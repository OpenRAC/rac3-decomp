/* US draft of func_0038B4D0 (rac3-uya-decomp func_00386D98, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-fopt-stack` (a single-function override). */


/* localdecomp:start func_0038B4D0 */
extern s32 D_001D4BD0_0038B4D0;
extern s32 D_001D4BD4_0038B4D0;
extern u8 D_001D76C0[];
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
  ox = D_001D4BD0_0038B4D0;
  oy = D_001D4BD4_0038B4D0;
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
