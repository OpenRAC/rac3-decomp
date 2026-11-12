#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_003AFC08 */
/* func_L05_003AFC08: from the staged near miss. func_L01_003303B8 takes its float second and
   func_L01_00475C60 its int after the three floats (the order of the argument moves); the fabs
   is include/vu0.h's fabs_asm, which retail's abs.s after func_0038CE20 is scheduled as. */
extern void func_00382580(void *, f32, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_003D8E60(void *, void *, s32, s32, s32, s32, void *, s32, f32, f32, f32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_003303B8(void *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u8 D_L05_00220758[];
__asm__(".extern D_L05_00220758, 16");

void func_L05_003AFC08(f32 x, u8 *p, s32 n, u8 *a, s32 cnt) {
    u8 loc[0x10];
    u8 *r;
    s32 k;
    f32 f22, f21, f20, f23, t;
    s32 v;

    func_00382580(loc, 0.020000001f, 0.040000003f);
    func_L01_003D8E60(p, loc, 60, 7, 5, n, a, 0, -1e+05f, x * 3.5f, -5.0f);
    if (cnt > 0) {
        if (func_00382468(cnt) == 0) {
            func_L01_003303B8(p, x, 0, 2, 2, 2, 1, 2, 1, 0.0f, 0.0f, 0.0f,
                0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        }
    }
    if (n > 0) {
        u8 *tb = D_L05_00220758;
        cnt = n;
        v = 0xF2;
        do {
            func_00382580(loc, 0.020000001f, 0.040000003f);
            k = func_00382498(-2, 2);
            f22 = x * 3.0f;
            t = func_003824E0(-6.0f, -10.0f);
            f23 = f22 * 2.1e+05f;
            r = func_L01_00475C60(p, loc, 50, k, 0x7F407FFF, 0x407FFF, f23, f23, t, 0);
            if (r != 0) {
                r[9] = (u8)v;
                r[2] = ((u8 *)*(u8 **)(tb + 0x184))[3];
            }
            func_0038CE20(loc, loc, 2.0f);
            *(f32 *)(loc + 8) = fabs_asm(*(f32 *)(loc + 8));
            k = func_00382498(-2, 2);
            f21 = (f22 * 0.4f) * 2.1e+05f;
            f20 = (f22 * 0.04f) * 2.1e+05f;
            t = func_003824E0(24.0f, 4e+01f);
            r = func_L01_00475C60(p, loc, 50, k, 0x7F0048FF, 0x48FF, f21, f20, t, 0);
            if (r != 0) {
                r[9] = (u8)v;
                r[2] = ((u8 *)*(u8 **)(tb + 0x184))[3];
            }
            cnt--;
        } while (cnt != 0);
    }
}
/* localdecomp:end func_L05_003AFC08 */

INCLUDE_ASM("asm/levels", func_L05_003AFF38);

INCLUDE_ASM("asm/levels", func_L05_003B00A8);

/* localdecomp:start func_L05_003B1100 */
extern s32 func_L01_004AAC98_003B1100(s32, s32, u8 *, s32);
extern void func_003A4F28(s32);
extern void func_L01_00456BD0(void *, s32);
extern void func_L01_00456C98(void *, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L05_003B1E80(s32, s32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern void func_L01_003E8BD0(s32, s32, f32, f32);
extern void func_L02_003FB148(s32, s32, f32);
extern void func_L05_003B2348(u8 *);
extern void func_L05_003B1450(u8 *);
typedef struct { u8 pad[0x144]; s32 v; } S_003B1100;
extern S_003B1100 D_L05_001E2700;
__asm__(".extern D_L05_001E2700, 16");

void func_L05_003B1100(u8 *a0) {
    u8 *p = a0;
    u8 *q = *(u8 **)(p + 0x68);
    u8 *r;
    s32 i;

    if (*(s32 *)(q + 0x2B0) == -1) {
        if (((p[0x34] ^ 1) & 1)) {
            *(s32 *)(q + 0x2B0) = func_L01_004AAC98_003B1100(0, 4, p, 0x1A13);
        }
    } else {
        if (*(u16 *)(p + 0x34) & 1) {
            func_003A4F28(*(s32 *)(q + 0x2B0));
            *(s32 *)(q + 0x2B0) = -1;
        }
    }
    if (((p[0x34] ^ 1) & 1)) {
        if (p[0x20] < 0x11) {
            func_L05_003B1450(p);
        }
    }
    func_L01_00456BD0(p, 3);
    i = 0;
    { f32 c = 100.0f; func_L01_00456C98(p, c, c, 1.0f, -1, 0, 0, 0, 0, 1, 0, 0, 0); }
    r = q + 0x160;
    do {
        s32 v = func_L05_003B1E80(i, 2);
        i++;
        func_L01_0044E850(p, r, v, 0.000288f, 0.0014400001f);
        r += 0x80;
    } while (i < 2);
    if (D_L05_001E2700.v) {
        func_L01_003E8BD0(0, 0, 9.0f, 0.003f);
    }
    if ((u32)(p[0x20] - 6) < 11) {
        func_L02_003FB148(7, 0, *(f32 *)(q + 0x30) / (f32)*(s16 *)(q + 0x34));
    }
    if (((p[0x34] ^ 1) & 1)) {
        if (p[0x20] < 0x11) {
            func_L05_003B2348(p);
        }
    }
}
/* localdecomp:end func_L05_003B1100 */

/* localdecomp:start func_L05_003B12E8 */
extern u8 D_L05_001DAF30;
extern u8 *D_L05_001DFB9C;
__asm__(".extern D_L05_001DAF30, 16");
__asm__(".extern D_L05_001DFB9C, 16");

extern void func_L01_004AA7E8(void *, s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L05_003B12E8(u8 *a0) {
    u8 *p = a0;
    u8 *q;
    f32 f;

    if (p[0x20] == 0) {
        D_L05_001DAF30 = 0;
        f = *(f32 *)(*(u8 **)(p + 0x24) + 0x24) * 0.5f;
        *(s16 *)(p + 0x32) = 0x80;
        *(u16 *)(p + 0x34) &= 0xBFFF;
        *(f32 *)(p + 0x2C) = f;
        q = *(u8 **)(p + 0x68);
        *(s32 *)(q + 0x2B0) = -1;
        p[0xBC] = 0;
        q[0x2B8] = 1;
        *(f32 *)(q + 0x280) = 5.5f;
        *(f32 *)(q + 0x28C) = 22.0f;
        *(s16 *)(q + 0x2B6) = 120;
        q[0x58] = 50;
        q[0x5A] = 160;
        q[0x2C0] = 0;
        q[0x2BA] = 0;
        q[0x2BE] = 0;
        q[0x2BF] = 0;
        *(s32 *)(q + 0x270) = 0;
        q[0x2B9] = 0;
        *(s32 *)(q + 0x298) = 0;
        *(s32 *)(q + 0x29C) = 0;
        if (*(s16 *)(q + 0x34) == 0) {
            *(s16 *)(q + 0x34) = 0xF0;
            *(f32 *)(q + 0x30) = 240.0f;
        }
        q[0x64] = 0;
        q[0x3E] = 3;
        q[0x3F] = 0;
        {
            s32 off = *(s32 *)(q + 0x2A8) << 8;
            u8 *r;
            r = D_L05_001DFB9C + off;
            *(f32 *)(q + 0x40) = -2.0f;
            *(s32 *)(r + 0x98) = 0;
            *(u16 *)(r + 0x34) = (*(u16 *)(r + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(r, 1);
        }
        *(s32 *)(p + 0x98) = 0;
        *(u16 *)(p + 0x34) = (*(u16 *)(p + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(p, 1);
        func_L01_004450F0(p, 1, -1);
    }
}
/* localdecomp:end func_L05_003B12E8 */

/* localdecomp:start func_L05_003B1450 */
extern void *func_L01_00447490(void *a, s32 b, s32 c);
extern f32 func_L01_004474E8(void *a, void *b);
extern void func_003C4A40(void *a, void *b);
extern void func_L01_004AAC98(s32 a, s32 b, void *c, s32 d);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_0044ABD0(void *a, void *b);
extern s32 D_001DE7A0_sda;
__asm__(".extern D_001DE7A0_sda, 4");

void func_L05_003B1450(u8 *a0) {
    u8 *p;
    u8 *r;
    f32 f;
    f32 g;

    p = *(u8 **)(a0 + 0x68);
    r = func_L01_00447490(a0, -1, 0);
    f = func_L01_004474E8(a0, r);
    a0[0xA8] = 0xFF;
    if ((*(u16 *)(a0 + 0x34) & 0x4000) && 0.0f < f) {
        if (r[0x28] != 10) {
            g = *(f32 *)(p + 0x30) - f;
            *(f32 *)(p + 0x30) = g;
            D_001DE7A0_sda = 5 - (s32)(g * 10.0f / (f32)*(s16 *)(p + 0x34));
        }
        p[0x137] = 0xFF;
        func_003C4A40(a0, p + 0x130);
        if (*(f32 *)(p + 0x30) <= 0.0f) {
            func_L01_004AAC98(4, 0, a0, 0x1A13);
            func_L01_004450F0(a0, 0x11, -1);
        } else {
            s32 t = p[0x2B8];
            if (*(f32 *)(p + 0x30) < (f32)*(s16 *)(p + 0x34) * (1.0f - (f32)t * 0.25f)) {
                p[0x2B8] = t + 1;
            }
        }
    }
    func_L01_0044ABD0(a0, p + 0x130);
}
/* localdecomp:end func_L05_003B1450 */

INCLUDE_ASM("asm/levels", func_L05_003B15D0);

INCLUDE_ASM("asm/levels", func_L05_003B1778);

/* localdecomp:start func_L05_003B19E8 */
extern f32 func_0038DAB8(f32, f32);

void func_L05_003B19E8(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 x = *(f32 *)(p + 0x27C);

    *(f32 *)(p + 0x280) = *(f32 *)(p + 0x284);
    *(f32 *)(p + 0x28C) = *(f32 *)(p + 0x290);
    *(f32 *)(p + 0x278) = x;
    *(f32 *)(a0 + 0xF8) = func_0038DAB8(x, 3.14159274f);
}
/* localdecomp:end func_L05_003B19E8 */

INCLUDE_ASM("asm/levels", func_L05_003B1A40);
