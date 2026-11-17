#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
/* --- end of declarations from other files --- */

/* declarations carried from the file this was cut from */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6F30 - 0x4958];
    u8 f6F30[1];
} S_3B0580;
extern void func_003B6280(void);


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
/* localdecomp:start func_003B6280 */
extern S_3B0580 D_00160C40_003B6280[];
extern void *D_001D89D0_003B6280;
extern void *D_001D89D4_003B6280;
extern void *func_003B5400(s32);
extern void *func_003B46B0(s32);
extern s32 func_003B48E0(void *, s32, s32, s32, s32);
extern void *func_003B46B0(s32);
extern u8 D_0037F830_003B5F78[];
extern u8 D_0037F690_003B5F78[];
extern s32 D_001D89B8_003B5F78;
extern s32 D_001D89E4_003B5F78;
extern void func_003A5748();
extern s32 func_00381FF0_003B6280();
extern void func_0011B2E8_003B6280();
extern s32 func_003B9AB8();
extern void func_003B9A90();
extern s32 func_003E8780();
extern void *func_003B5388();
extern s32 func_003B5580(void);
extern void func_003E73B0_003B6280(void *p);
typedef struct { s32 a, b, c, d; } E_37B870_003B6280;
extern E_37B870_003B6280 D_0037F830_003B6280[];
extern s32 D_001D89B8_003B6280;
extern s32 D_001D89BC_003B6280;
extern s32 D_001D8A00_003B6280;
extern s32 *func_003B9F88(s32);
extern s32 func_003BA010(s32 *);
extern s32 func_003E8200(s32, s32);
extern s32 func_003E7DD0(s32 arg0, s32 arg1);
typedef struct { s32 f0; s32 f4; s32 f8; s32 fC; s32 f10; s32 f14; f32 f18; f32 f1C; f32 f20; f32 a24[4]; f32 a34[4]; f32 a44[4]; } S_3B07B8_003B6280;
extern s32 D_001D89C0_003B6280;
extern s32 D_001D89C4_003B6280;
extern s32 D_001D89C8_003B6280;
extern s32 D_001D89CC_003B6280;
extern f32 D_001D89D8_003B6280;
extern f32 D_001D89DC_003B6280;
extern f32 D_001D89E0_003B6280;
extern char D_001D8A08_003B6280[];
extern void *func_003B5400(s32);
extern s32 *func_003B9F88(s32);
extern s32 func_003BA020();
extern void func_003BAF68(s32 *arg0, float float1, float float2, float float3, float float4, float float5);
extern void func_003BAF88(void *, f32, f32, f32, f32);
extern void func_003BA898(void *, s32, f32, f32, f32);
extern void func_003BA710();
extern s32 func_003BA1E8_003B6128(void *, s32, s32);
extern s32 func_00381FF0_003B6280();
extern void func_11B2E8_003B6280();
extern s32 D_00143950_b_003B6280[];
extern void func_003877A0();
extern u8 D_00143950_003B6280[];
extern s32 D_00143950_b_003B6280[];

typedef struct { u8 p0[0x18]; u8 *f18; } O_3B0DA0_003B6280;
typedef struct { u8 p0[0x2C]; s32 f2C; } Z_3B0DA0_003B6280;
extern O_3B0DA0_003B6280 D_00227580_003B6280;
extern u8 D_00143A07_003B6280[];
extern Z_3B0DA0_003B6280 D_0031CC80_003B6280;
extern s32 *D_001D99A0_003B6280;
extern void func_003A0760_003B6280();
extern s32 func_00381FF0_003B6280();
extern void func_003E7C90_003B6280_003B6280();
extern void func_003BAF50_003B6280();
extern void func_003E81F0_003B6280_003B6280(s32, f32, f32);
extern void func_003E7760_003B6280_003B6280(s32, f32);
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
  base = D_00227580_003B6280.f18 + 0x400000;
  switch (D_00143A07_003B6280[0])
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

  func_003A0760_003B6280(off, D_00227580_003B6280.f18);
  q = (s32 *) D_00227580_003B6280.f18;
  D_0031CC80_003B6280.f2C = ((u32) q[0]) >> 4;
  D_001D99A0_003B6280 = q;
  p = q;
  new_var2 = 0;
  for (i = 0; i < D_0031CC80_003B6280.f2C; i++)
  {
    p[new_var2] = p[new_var2] + ((s32) q);
    p += 4;
  }

  w = 1.2f;
  z = 0.0f;
  v[0] = w;
  v[1] = z;
  func_003E7C90_003B6280_003B6280(0xD0005, func_00381FF0_003B6280(0x107));
  func_003E7C90_003B6280_003B6280(0xD0006, func_00381FF0_003B6280(0xFF));
  func_003E7C90_003B6280_003B6280(0xD0007, func_00381FF0_003B6280(0xCD5));
  func_003BAF50_003B6280(0x107, v, &v[1]);
  func_003E81F0_003B6280_003B6280(0xD0005, v[0], v[0]);
  func_003E7760_003B6280_003B6280(0xD0002, v[1]);
  new_var3 = v[1];
  func_003E7760_003B6280_003B6280(0xD0003, new_var3);
  func_003E7760_003B6280_003B6280(0xD0000, v[1]);
  func_003E7760_003B6280_003B6280(0xD0001, new_var = v[1]);
}
/* localdecomp:end func_003B6280 */
