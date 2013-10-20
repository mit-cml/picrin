#include "picrin.h"
#include "picrin/pair.h"

pic_value
pic_cons(pic_state *pic, pic_value car, pic_value cdr)
{
  struct pic_pair *pair;

  pair = (struct pic_pair *)pic_obj_alloc(pic, sizeof(struct pic_pair), PIC_TT_PAIR);
  pair->car = car;
  pair->cdr = cdr;

  return pic_obj_value(pair);
}

pic_value
pic_car(pic_state *pic, pic_value obj)
{
  struct pic_pair *pair;

  if (! pic_pair_p(obj)) {
    pic_error(pic, "pair required");
  }
  pair = (struct pic_pair *)obj.u.data;

  return pair->car;
}

pic_value
pic_cdr(pic_state *pic, pic_value obj)
{
  struct pic_pair *pair;

  if (! pic_pair_p(obj)) {
    pic_error(pic, "pair required");
  }
  pair = (struct pic_pair *)obj.u.data;

  return pair->cdr;
}

pic_value
pic_assq(pic_state *pic, pic_value key, pic_value assoc)
{
  pic_value cell;

 enter:

  if (pic_nil_p(assoc))
    return assoc;

  cell = pic_car(pic, assoc);
  if (pic_eq_p(pic, key, pic_car(pic, cell)))
    return cell;

  assoc = pic_cdr(pic, assoc);
  goto enter;
}

pic_value
pic_acons(pic_state *pic, pic_value key, pic_value val, pic_value assoc)
{
  return pic_cons(pic, pic_cons(pic, key, val), assoc);
}
