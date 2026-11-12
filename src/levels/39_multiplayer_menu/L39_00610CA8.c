#include "common.h"

/* localdecomp:start func_L39_00610CA8 */
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_00610CA8;
extern S_00610CA8 D_L39_0024CD50;
extern u8 D_L39_0024CD60; __asm__(".extern D_L39_0024CD60, 16");
extern s32 D_001DA4F8_sda;
extern void *func_003E6C08();
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_L01_00519700(void *, s32);

s32 func_L39_00610CA8(s32 arg0, f32 fa, f32 fb)
{
  s32 *base;
  unsigned char new_var;
  s32 (*cb)(void *, f32, f32);
  s32 r;
  s32 t;
  void *p;
  S_00610CA8 *q;
  r = 0;
  q = &D_L39_0024CD50;
  if (q->f4 != 0)
  {
    base = (s32 *) q;
  }
  else
  {
    base = (s32 *) func_003E6C08(q);
  }
  p = (void *) func_003E6378(func_003E6DE8(base), arg0);
  new_var = p == 0;
  if (new_var || ((*((s32 (**)(void *, s32)) (((u8 *) (*((void **) (((u8 *) p) + 8)))) + 0x10)))(p, D_001DA4F8_sda) == 0))
  {
    p = 0;
  }
  if (p != 0)
  {
    t = (*((s32 (**)(void *)) (((u8 *) (*((void **) (((u8 *) p) + 8)))) + 0xC)))(p);
    cb = (void *) func_L01_00519700(&D_L39_0024CD60, t);
    if (cb != 0)
    {
      r = cb(p, fa, fb);
    }
  }
  return r;
}
/* localdecomp:end func_L39_00610CA8 */
