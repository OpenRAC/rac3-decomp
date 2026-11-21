#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
typedef int u128_t __attribute__((mode(TI)));
extern void func_0038B4D0(s32, s32, s32, s32, s32, s32, s32, s32, long, long);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

typedef int Q_3869E8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3869E8;
extern s32 D_001DA050;
extern Q_3869E8 D_001D76C0_0038B120[];
extern s32 D_001D4BD0, D_001D4BD4;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
INCLUDE_ASM("asm/nonmatchings/text", func_0038B120);

extern u8 D_001D76C0[];
/* localdecomp:start func_0038B4D0 */
void func_0038B4D0(s32 x, s32 y, s32 w, s32 h, s32 u, s32 v, s32 uw, s32 vh, long a8, long a9)
{
  u8 *r;
  u8 *p;
  u8 *q;
  s32 ox;
  s32 oy;
  long x0;
  long y0;
  long x1;
  long y1;
  long k;
  s32 u0;
  s32 u1;
  s32 v0;
  s32 v1;
  ox = D_001D4BD0;
  oy = D_001D4BD4;
  *((s32 *) (D_001DA050 + 0)) = 0x10000007;
  u1 = (u + uw) << 4;
  x1 = (((x + w) << 4) + ox) - 8;
  y0 = ((long) (((y << 4) + oy) - 8)) << 16;
  *((s32 *) (D_001DA050 + 4)) = 0;
  *((s32 *) (D_001DA050 + 8)) = 0;
  *((s32 *) (D_001DA050 + 0xC)) = 0x50000007;
  r = (u8 *) D_001DA050;
  k = 0xFFFFF000000000UL;
  D_001DA050 = ((s32) r) + 0x10;
  x0 = ((x << 4) + ox) - 8;
  v1 = (v + vh) << 20;
  u0 = u << 4;
  v0 = v << 20;
  *((u128_t *) (r + 0x10)) = *((u128_t *) D_001D76C0);
  y1 = ((long) ((((y + h) << 4) + oy) - 8)) << 16;
  p = (u8 *) D_001DA050;
  q = p + 0x10;
  D_001DA050 = (s32) q;
  *((long *) (p + 0x10)) = a9;
  *((long *) (q + 8)) = 0x154;
  *((long *) (q + 0x18)) = v0 + u0;
  *((long *) (q + 0x20)) = (x0 | y0) | k;
  *((long *) (q + 0x28)) = v0 + u1;
  *((long *) (q + 0x30)) = (x1 | y0) | k;
  *((long *) (q + 0x38)) = v1 + u0;
  *((long *) (q + 0x40)) = (x0 | y1) | k;
  *((long *) (q + 0x48)) = v1 + u1;
  *((long *) (q + 0x10)) = a8;
  *((long *) (q + 0x50)) = (x1 | y1) | k;
  *((long *) (q + 0x58)) = 0;
  D_001DA050 = D_001DA050 + 0x60;
}
/* localdecomp:end func_0038B4D0 */
