#include "common.h"

INCLUDE_ASM("asm/levels", func_L05_003AFC08);

INCLUDE_ASM("asm/levels", func_L05_003AFF38);

INCLUDE_ASM("asm/levels", func_L05_003B00A8);

INCLUDE_ASM("asm/levels", func_L05_003B1100);

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
