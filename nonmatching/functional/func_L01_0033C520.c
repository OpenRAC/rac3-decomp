/* functional: medium. The two vsubs and the vadd are retail's VU0 ops (lqc2/v*.xyz/sqc2 on vf1/vf2) so the VU0 state later retail callees see is retail's. 400 diff words at the file's flags (0x1E0 vs 0x100 frame because one local buffer replaces retail's overlapping out-args/locals, plus scheduling); frame-stamp and gp slots (gp+0x3290 = D_001DFB40, gp+0x4FE8 = D_001E1898, +0x6FC/+0x700 counters), the level-count ladder k from D_001DFF40 and gp+0x700 (4/3/2/1/0), the per-type spark counts n (type 0x1F5/0x200: min((1<<(k-1))-1,15); 0x1F4/0x1FF: 1/5/37), the 18-word stack argument block of func_L01_003303B8 and the five-iteration func_L01_004653B8 loop checked against retail. The asm tag 'Handwritten function' only marks the abs() macro pairs; this is compiled C. */
typedef struct { f32 x, y, z, w; } V4;
typedef int Q16 __attribute__((mode(TI)));
extern u8 D_001A4BE0[];
extern u8 D_L01_001E29C0[];
extern u8 D_L01_001E2A40[];
extern u8 D_142660[];
extern u8 *D_001A71A0[];
extern u16 D_001A8A6C[];
extern s32 D_L01_001DAFEC[];
extern s32 D_L01_001DFB40[];
extern s32 D_L01_001DFF40[];
extern s32 D_L01_001E1894[];
extern s32 D_L01_001E1898[];
extern s32 D_L01_001DCFAC;
extern s32 D_L01_001DCFB0;
extern void func_L01_0033C4B8(u8 *);
extern void func_L01_004AAC98(s32, s32, u8 *, s32);
extern void func_003A52A0(s32, s32, u8 *);
extern s32 func_003C4B50(void *);
extern void func_L01_004653B8(void *, s32, u32, f32, f32, f32, f32, f32);
extern void func_L01_00448248(void *, s32, s32);
extern void func_L01_0044C870(u8 *, u8 *, void *, void *);
extern void func_L01_00451FE0(u8 *, s32, void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32);
extern void func_L01_00349998(u8 *, void *, void *, s32, f32);
extern void func_L01_00425A08(s32);
extern void func_L01_00451F60(s32, s32, s32);
extern void func_L01_0041A5B0(s32, s32);

void func_L01_0033C520(u8 *m, s32 a1, u8 *a2) {
    Q16 buf[16];
    u8 *sp = (u8 *)buf;
    u8 *p;
    u8 *q;
    u8 *hero;
    s32 stamp;
    s32 d;
    s32 t;
    s32 v;
    s32 k;
    s32 n;
    s32 i;
    u16 fl;

    func_L01_0033C4B8(m);
    p = *(u8 **)(m + 0x68);
    d = D_L01_001DFB40[0] - D_L01_001E1894[0];
    if (d <= 0) {
        d = -d;
    }
    if (d >= 2) {
        t = *(s16 *)(m + 0xAA);
        if (t == 0x1FA) {
            func_L01_004AAC98(0, 0, m, 0x1F4);
            stamp = D_L01_001DFB40[0];
        } else if (t == 0x1FF) {
            func_L01_004AAC98(1, 0, m, 0x1FF);
            stamp = D_L01_001DFB40[0];
        } else {
            func_003A52A0(0, 0, m);
            stamp = D_L01_001DFB40[0];
        }
        D_L01_001E1894[0] = stamp;
    }
    stamp = D_L01_001DFB40[0];
    d = stamp - D_L01_001E1898[0];
    if (d <= 0) {
        d = -d;
    }
    if (d >= 2) {
        D_L01_001E1898[0] = stamp;
    }
    if (*(s32 *)(p + 0xD0) != 0) {
        q = *(u8 **)(*(u8 **)(p + 0xD0) + 0x68);
        *(s32 *)(q + 0xD4) = *(s32 *)(p + 0xD4);
        q = *(u8 **)(*(u8 **)(p + 0xD0) + 0x68);
        *(s32 *)(q + 0xDC) = *(s32 *)(q + 0xDC) | 0x24;
    }
    if (*(s32 *)(p + 0xD4) != 0) {
        func_003C4B50((void *)*(s32 *)(*(u8 **)(*(u8 **)(p + 0xD4) + 0x68) + 0xD0));
        q = *(u8 **)(*(u8 **)(p + 0xD4) + 0x68);
        *(s32 *)(q + 0xD0) = *(s32 *)(p + 0xD0);
        q = *(u8 **)(*(u8 **)(p + 0xD4) + 0x68);
        *(s32 *)(q + 0xDC) = *(s32 *)(q + 0xDC) | 0x24;
    }
    q = m;
    do {
        u8 *qq = *(u8 **)(q + 0x68);
        *(s32 *)(qq + 0xDC) = *(s32 *)(qq + 0xDC) | 0x20;
        q = *(u8 **)(qq + 0xD0);
    } while (q != 0);
    *(Q16 *)(sp + 0x90) = *(Q16 *)(m + 0x10);
    *(f32 *)(sp + 0x98) = *(f32 *)(sp + 0x98) + 0.3f;
    func_L01_004653B8(sp + 0x90, 1, 0x40808080, 0.3f, 1.01f, 1.075f, 0.05f, 50000.0f);
    i = 4;
    do {
        i = i - 1;
        func_L01_004653B8(sp + 0x90, 1, 0x40808080, 0.3f, 1.01f, 1.07f, 0.05f, 50000.0f);
    } while (i >= 0);
    if (a2 != 0) {
        *(Q16 *)(sp + 0xA0) = *(Q16 *)(a2 + 0x10);
    } else {
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(*(Q16 *)(sp + 0xA0)) : "m"(*(Q16 *)(m + 0x10)), "m"(*(Q16 *)(D_001A71A0[0] + 0x10)) : "vf1", "vf2");
    }
    stamp = D_L01_001DFB40[0];
    d = stamp - D_L01_001DCFAC;
    if (d <= 0) {
        d = -d;
    }
    if (d >= 0xC9) {
        D_L01_001DCFAC = stamp;
        D_L01_001DCFB0 = 0;
    } else if (stamp != D_L01_001DCFAC) {
        func_L01_00448248(&D_L01_001DCFB0, 0, d >> 2);
        D_L01_001DCFAC = D_L01_001DFB40[0];
    }
    v = D_L01_001DFF40[0];
    if (v >= 0xFB && D_L01_001DCFB0 < 5) {
        k = 4;
    } else if (v >= 0xC9 && D_L01_001DCFB0 < 10) {
        k = 3;
    } else if (v >= 0x97 && D_L01_001DCFB0 < 15) {
        k = 2;
    } else if (v >= 0x65) {
        k = D_L01_001DCFB0 < 20;
    } else {
        k = 0;
    }
    if (k != 0) {
        D_L01_001DCFB0 = D_L01_001DCFB0 + k;
        t = *(s16 *)(m + 0xAA);
        n = 0;
        if (t == 0x1F5 || t == 0x200) {
            n = (1 << (k - 1)) - 1;
            if (n >= 0x10) {
                n = 15;
            }
        } else if (t == 0x1F4 || t == 0x1FF) {
            if (k == 2) {
                n = 5;
            } else if (k < 3) {
                n = 1;
            } else {
                n = 0x25;
            }
        }
        if (n != 0) {
            *(unsigned long *)(sp + 0xB0) = 0;
            *(unsigned long *)(sp + 0xB8) = 0;
            if (*(s32 *)(p + 0x120) != 0 && D_L01_001DAFEC[0] == 0) {
                func_L01_0044C870(m, *(u8 **)(p + 0x120), m + 0x10, sp + 0xB0);
            }
            func_L01_00451FE0(m, n, sp + 0xB0, 0xFF, 0xB4, 0, 0, 0x23, 0, 3, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f,
                              1.0f, 1.0f);
        }
    }
    fl = *(u16 *)(m + 0x34);
    m[0x20] = 3;
    m[0xBC] = 0xC;
    *(u16 *)(m + 0x34) = fl | 1;
    *(s32 *)(m + 0x98) = 0;
    if (a1 != 0) {
        p[0xFA] = 1;
        func_0038CF68(sp + 0xB0, m + 0xE0, 0.5f);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(*(Q16 *)(sp + 0xB0)) : "m"(*(Q16 *)(sp + 0xB0)), "m"(*(Q16 *)(m + 0x10)) : "vf1", "vf2");
        func_L01_003303B8(sp + 0xB0, 0, 0xA, 0xA, 0xA, 0xA, 0xF, 0, 0, 0, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7,
                          0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0, 1.0f, 0.0f, 0.0f,
                          2.0f);
    }
    if (*(s16 *)(m + 0xAA) != 0x1F8) {
        return;
    }
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(*(Q16 *)(sp + 0xC0)) : "m"(*(Q16 *)D_L01_001E29C0), "m"(*(Q16 *)(sp + 0xB0)) : "vf1", "vf2");
    func_0038CF68(sp + 0xC0, sp + 0xC0, 1.0f);
    hero = D_001A4BE0;
    if (*(s32 *)(hero + 0x234) == 0) {
        q = D_142660;
        t = *(s16 *)(q + 0x40);
        *(s16 *)(q + 0x40) = 4;
        *(s32 *)(q + 0x78) = t;
    }
    func_L01_00349998(m, m + 0x10, sp + 0xC0, 1, 5.0f);
    q = D_L01_001E2A40;
    *(f32 *)(q + 0x40) = 0.2f;
    *(s32 *)(hero + 0x234) = 0x3E8;
    *(s32 *)(q + 0x48) = 0x4B;
    *(s32 *)(q + 0x28) = 0x32;
    *(f32 *)(q + 0x20) = 0.3f;
    *(s32 *)(q + 0x2C) = 0;
    func_L01_00425A08(1);
    func_L01_00451F60(0x121A, -1, 0);
    if (D_001A8A6C[0] == 0) {
        func_L01_0041A5B0(0x1405, 0x107);
    }
}
