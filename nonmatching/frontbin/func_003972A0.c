/* US draft of func_003972A0 (rac3-uya-decomp func_00392A40, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003972A0 */
typedef struct { u32 w0; u16 h4; u8 b6; u8 b7; } E_392A40;
extern P_392108 *D_001D9EA8_003972A0;
extern E_392A40 *D_001D9EAC_003972A0;
typedef int Q_392A40 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } V4_392A40;
extern u32 *D_001DA050;
extern s32 func_00396A38_003972A0();
extern s32 D_001D4BD0;
extern s32 D_001D4BD4;
extern Q_392A40 D_001D76F0_003972A0[];
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
void func_003972A0(s32 tex, s32 *col, f32 x, f32 y, f32 w, f32 h, f32 ang) {
    V4_392A40 a, b, c, p0, p1, p2, p3;
    unsigned long *q;
    P_392108 *k = (P_392108 *)((tex << 2) + (s32)D_001D9EA8_003972A0);
    E_392A40 *e = D_001D9EAC_003972A0 + k->b;
    s32 tw = 1 << e->b6;
    s32 th = 1 << e->b7;
    c.x = x;
    c.y = y;
    a.x = h * func_0038D0B0(ang);
    a.y = h * func_0038D098(ang);
    b.x = -w * func_0038D098(ang);
    b.y = w * func_0038D0B0(ang);
    {
        Q_392A40 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(a));
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(c));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p3) : "j"(va));
    }
    {
        Q_392A40 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(b));
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(p3));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p3) : "j"(va));
    }
    {
        Q_392A40 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(c));
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(a));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p2) : "j"(va));
    }
    {
        Q_392A40 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(b));
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(p2));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p2) : "j"(va));
    }
    {
        Q_392A40 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(c));
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(a));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p1) : "j"(va));
    }
    {
        Q_392A40 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(b));
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(p1));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p1) : "j"(va));
    }
    {
        Q_392A40 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(c));
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(a));
        __asm__("vsub.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p0) : "j"(va));
    }
    {
        Q_392A40 va, vb;
        __asm__("lqc2 %0, %1" : "=j"(va) : "m"(p0));
        __asm__("lqc2 %0, %1" : "=j"(vb) : "m"(b));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(va) : "j"(va), "j"(vb));
        __asm__("sqc2 %1, %0" : "=m"(p0) : "j"(va));
    }
    D_001DA050[0] = 0x10000008;
    D_001DA050[1] = 0;
    D_001DA050[2] = 0;
    D_001DA050[3] = 0x50000008;
    {
        u32 *p = D_001DA050;
        Q_392A40 *g = D_001D76F0_003972A0;
        D_001DA050 = p + 4;
        *(Q_392A40 *)(p + 4) = *g;
    }
    q = (unsigned long *)(D_001DA050 + 4);
    D_001DA050 = (u32 *)q;
    q[0] = func_00396A38_003972A0(tex);
    q[1] = 0x15C;
    q[2] = col[0];
    q[3] = 0;
    q[4] = (unsigned long)(((s32)(p0.x) * 16 + D_001D4BD0 - 8) | ((long)((s32)(p0.y) * 16 + D_001D4BD4 - 8) << 16)) | (0xFFFFF0UL << 32);
    q[5] = col[1];
    q[6] = tw << 4;
    q[7] = (unsigned long)(((s32)(p1.x) * 16 + D_001D4BD0 - 8) | ((long)((s32)(p1.y) * 16 + D_001D4BD4 - 8) << 16)) | (0xFFFFF0UL << 32);
    q[8] = col[2];
    q[9] = th << 20;
    q[10] = (unsigned long)(((s32)(p2.x) * 16 + D_001D4BD0 - 8) | ((long)((s32)(p2.y) * 16 + D_001D4BD4 - 8) << 16)) | (0xFFFFF0UL << 32);
    q[11] = col[3];
    q[12] = (th << 20) + (tw << 4);
    q[13] = (unsigned long)(((s32)(p3.x) * 16 + D_001D4BD0 - 8) | ((long)((s32)(p3.y) * 16 + D_001D4BD4 - 8) << 16)) | (0xFFFFF0UL << 32);
    D_001DA050 += 0x1C;
}
/* localdecomp:end func_003972A0 */
