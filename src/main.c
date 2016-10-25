/**
 * See Copyright Notice in picrin.h
 */

#include "picrin.h"
#include "picrin/extra.h"

void pic_init_yail(pic_state *);

void
pic_init_picrin(pic_state *pic)
{
  void pic_init_contrib(pic_state *);
  void pic_load_piclib(pic_state *);

  pic_init_contrib(pic);
  pic_load_piclib(pic);
  pic_init_yail(pic);
}

int picrin_argc;
char **picrin_argv;
char **picrin_envp;

extern char *picrin_native_stack_start; /* for call/cc */

int
main(int argc, char *argv[], char **envp)
{
  char t;
  pic_state *pic;
  pic_value e;
  int status;

  pic = pic_open(pic_default_allocf, NULL);

  picrin_argc = argc;
  picrin_argv = argv;
  picrin_envp = envp;

  picrin_native_stack_start = &t;

  pic_try {
    pic_init_picrin(pic);

    //enable_debug = 1;
    pic_funcall(pic, "picrin.main", "main", 0);

    status = 0;
  }
  pic_catch(e) {
    pic_print_error(pic, pic_stderr(pic), e);
    status = 1;
  }

  pic_close(pic);

  return status;
}
