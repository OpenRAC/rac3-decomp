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
/* localdecomp:start func_0038B120 */
/* PROVISIONAL, VU0 j-constraint form. */
/* Needs -mvu0-use-vf0-vf2. Saves $ra and $s0-$s6 with sq (config/frontbin/sq_ra_funcs.txt),
   so 38B120.c's flag line has no -fopt-stack. */
static __inline__ void vadd_3869E8(V_3869E8 *d, V_3869E8 *a, V_3869E8 *b) {
    Q_3869E8 x, y;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*d) : "j"(x));
}
static __inline__ void vsub_3869E8(V_3869E8 *d, V_3869E8 *a, V_3869E8 *b) {
    Q_3869E8 x, y;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*a));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*b));
    __asm__("vsub.xyz %0, %0, %1" : "+j"(x) : "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(*d) : "j"(x));
}
void func_0038B120(s32 x, s32 y, s32 w, s32 h, s32 u, s32 v, s32 du, s32 dv, f32 ang, long col, long tex) {
    V_3869E8 a, b, c, p[4];
    s32 hw, hh, u1, v1, u4, uw4, v20, vh20;
    long z;
    long *q;
    hh = h >> 1;
    hw = w >> 1;
    c.x = x + hw;
    c.y = y + hh;
    u4 = u << 4;
    u1 = (u + du) << 4;
    v1 = v + dv;
    a.x = (f32)hh * func_0038D0B0(ang);
    a.y = (f32)hh * func_0038D098(ang);
    b.x = (f32)-hw * func_0038D098(ang);
    b.y = (f32)hw * func_0038D0B0(ang);
    v20 = v << 20;
    vh20 = v1 << 20;
    z = 0xFFFFF000000000UL;
    vadd_3869E8(&p[3], &c, &a);
    vsub_3869E8(&p[3], &p[3], &b);
    vadd_3869E8(&p[2], &c, &a);
    vadd_3869E8(&p[2], &p[2], &b);
    vsub_3869E8(&p[1], &c, &a);
    vsub_3869E8(&p[1], &p[1], &b);
    vsub_3869E8(&p[0], &c, &a);
    vadd_3869E8(&p[0], &p[0], &b);
    *(s32 *)(D_001DA050 + 0) = 0x10000007;
    *(s32 *)(D_001DA050 + 4) = 0;
    *(s32 *)(D_001DA050 + 8) = 0;
    *(s32 *)(D_001DA050 + 0xC) = 0x50000007;
    D_001DA050 += 0x10;
    *(Q_3869E8 *)D_001DA050 = D_001D76C0_0038B120[0];
    D_001DA050 += 0x10;
    q = (long *)D_001DA050;
    q[0] = tex;
    q[1] = 0x154;
    q[2] = col;
    q[3] = v20 + u4;
    q[4] = (long)(((s32)p[0].x << 4) + D_001D4BD0 - 8) | (long)(((s32)p[0].y << 4) + D_001D4BD4 - 8) << 16 | z;
    q[5] = v20 + u1;
    q[6] = (long)(((s32)p[1].x << 4) + D_001D4BD0 - 8) | (long)(((s32)p[1].y << 4) + D_001D4BD4 - 8) << 16 | z;
    q[7] = vh20 + u4;
    q[8] = (long)(((s32)p[2].x << 4) + D_001D4BD0 - 8) | (long)(((s32)p[2].y << 4) + D_001D4BD4 - 8) << 16 | z;
    q[9] = vh20 + u1;
    q[10] = (long)(((s32)p[3].x << 4) + D_001D4BD0 - 8) | (long)(((s32)p[3].y << 4) + D_001D4BD4 - 8) << 16 | z;
    q[11] = 0;
    D_001DA050 += 0x60;
}
/* localdecomp:end func_0038B120 */

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
