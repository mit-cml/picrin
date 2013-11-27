#ifndef MACRO_H__
#define MACRO_H__

struct pic_senv {
  PIC_OBJECT_HEADER
  struct pic_senv *up;
  struct xhash *tbl;
  struct pic_syntax **stx;
  size_t xlen, xcapa;
};

struct pic_syntax {
  PIC_OBJECT_HEADER
  enum {
    PIC_STX_DEFINE,
    PIC_STX_SET,
    PIC_STX_QUOTE,
    PIC_STX_LAMBDA,
    PIC_STX_IF,
    PIC_STX_BEGIN,
    PIC_STX_MACRO,
    PIC_STX_DEFMACRO,
    PIC_STX_DEFSYNTAX
  } kind;
  pic_sym sym;
  struct pic_proc *macro;
  struct pic_senv *senv;
};

struct pic_sc {
  PIC_OBJECT_HEADER
  pic_value expr;
  struct pic_senv *senv;
};

#define pic_sc(v) ((struct pic_sc *)pic_ptr(v))
#define pic_sc_p(v) (pic_type(v) == PIC_TT_SC)

#define pic_syntax(v) ((struct pic_syntax *)pic_ptr(v))
#define pic_syntax_p(v) (pic_type(v) == PIC_TT_SYNTAX)

#define pic_senv(v) ((struct pic_senv *)pic_ptr(v))
#define pic_senv_p(v) (pic_type(v) == PIC_TT_SENV)

struct pic_syntax *pic_syntax_new(pic_state *, int kind, pic_sym sym);
struct pic_syntax *pic_syntax_new_macro(pic_state *, pic_sym, struct pic_proc *, struct pic_senv *senv);

#endif