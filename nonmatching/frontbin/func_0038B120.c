/* US draft of func_0038B120 (rac3-uya-decomp func_003869E8, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-fopt-stack` (a single-function override). */


/* localdecomp:start func_0038B120 */
/* VU0 j-form (needs -mvu0-use-vf0-vf2, on every line of tools/text_parts.txt).
   Saves $ra and $s0-$s6 with sq (tools/sq_ra_funcs.txt), so the override also drops -fopt-stack. */
typedef int Q_3869E8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3869E8;
extern s32 D_001DA050;
extern Q_3869E8 D_001D76C0_0038B120[];
extern s32 D_001D4BD0_0038B120, D_001D4BD4_0038B120;
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
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
    q[4] = (long)(((s32)p[0].x << 4) + D_001D4BD0_0038B120 - 8) | (long)(((s32)p[0].y << 4) + D_001D4BD4_0038B120 - 8) << 16 | z;
    q[5] = v20 + u1;
    q[6] = (long)(((s32)p[1].x << 4) + D_001D4BD0_0038B120 - 8) | (long)(((s32)p[1].y << 4) + D_001D4BD4_0038B120 - 8) << 16 | z;
    q[7] = vh20 + u4;
    q[8] = (long)(((s32)p[2].x << 4) + D_001D4BD0_0038B120 - 8) | (long)(((s32)p[2].y << 4) + D_001D4BD4_0038B120 - 8) << 16 | z;
    q[9] = vh20 + u1;
    q[10] = (long)(((s32)p[3].x << 4) + D_001D4BD0_0038B120 - 8) | (long)(((s32)p[3].y << 4) + D_001D4BD4_0038B120 - 8) << 16 | z;
    q[11] = 0;
    D_001DA050 += 0x60;
}
/* localdecomp:end func_0038B120 */
