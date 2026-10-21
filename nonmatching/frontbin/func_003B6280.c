/* US draft of func_003B6280 (rac3-uya-decomp func_003B0DA0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003B6280 */
typedef struct { u8 p0[0x18]; u8 *f18; } O_3B0DA0;
typedef struct { u8 p0[0x2C]; s32 f2C; } Z_3B0DA0;
extern O_3B0DA0 D_00227580;
extern u8 D_00143A07[];
extern Z_3B0DA0 D_0031CC80;
extern s32 *D_001D99A0;
extern void func_003A0760();
extern s32 func_00381FF0();
extern void func_003E7C90_003B6280();
extern void func_003BAF50();
extern void func_003E81F0_003B6280(s32, f32, f32);
extern void func_003E7760_003B6280(s32, f32);
void func_003B6280(void)
{
  u8 *base;
  s32 off;
  s32 *q;
  s32 *p;
  s32 i;
  f32 v[2];
  int new_var2;
  f32 z;
  f32 new_var;
  f32 new_var3;
  f32 w;
  off = 0;
  base = D_00227580.f18 + 0x400000;
  switch (D_00143A07[0])
  {
    case 0:

    case 1:
      off = ((s32) base) + (*((s32 *) (base + 0)));
      break;

    case 2:
      off = ((s32) base) + (*((s32 *) (base + 8)));
      break;

    case 3:
      off = ((s32) base) + (*((s32 *) (base + 0x10)));
      break;

    case 4:
      off = ((s32) base) + (*((s32 *) (base + 0x18)));
      break;

    case 5:
      off = ((s32) base) + (*((s32 *) (base + 0x20)));
      break;

  }

  func_003A0760(off, D_00227580.f18);
  q = (s32 *) D_00227580.f18;
  D_0031CC80.f2C = ((u32) q[0]) >> 4;
  D_001D99A0 = q;
  p = q;
  new_var2 = 0;
  for (i = 0; i < D_0031CC80.f2C; i++)
  {
    p[new_var2] = p[new_var2] + ((s32) q);
    p += 4;
  }

  w = 1.2f;
  z = 0.0f;
  v[0] = w;
  v[1] = z;
  func_003E7C90_003B6280(0xD0005, func_00381FF0(0x107));
  func_003E7C90_003B6280(0xD0006, func_00381FF0(0xFF));
  func_003E7C90_003B6280(0xD0007, func_00381FF0(0xCD5));
  func_003BAF50(0x107, v, &v[1]);
  func_003E81F0_003B6280(0xD0005, v[0], v[0]);
  func_003E7760_003B6280(0xD0002, v[1]);
  new_var3 = v[1];
  func_003E7760_003B6280(0xD0003, new_var3);
  func_003E7760_003B6280(0xD0000, v[1]);
  func_003E7760_003B6280(0xD0001, new_var = v[1]);
}
/* localdecomp:end func_003B6280 */
