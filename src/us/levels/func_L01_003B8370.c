#include "common.h"

/* NTSC-U counterpart of func_L01_003B9BB8 (src/levels/shared/L01_003B84E8.c) */
/* localdecomp:start func_L01_003B8370 */
typedef int u128_t __attribute__((mode(TI)));
extern u16 *D_L01_0021DEA0[];
extern u8 *D_L01_001E009C;
__asm__(".extern D_L01_001E009C, 16");
extern u8 D_001D5476;
__asm__(".extern D_001D5476, 16");
typedef struct { u8 p0[0x20]; f32 f20; u8 p24[4]; s32 f28; s32 f2C; } S_2AC0;
extern S_2AC0 D_L01_001E2AC0;
extern f32 D_001DE920_sda;
__asm__(".extern D_001DE920_sda, 4");
extern s32 D_001D545C_sda_003B8370;
__asm__(".extern D_001D545C_sda_003B8370, 4");
extern s32 D_001E00D8_sda;
__asm__(".extern D_001E00D8_sda, 4");

extern s32 func_L01_00442E08(u8 *, s32);
extern void func_003BE4F0(u8 *, s32, s32, s32);
extern void func_003C26C8(u8 *);
extern f32 func_00388978(f32);
extern void func_L01_00474140(s32 *, s32, u8 *, u8 *, s32, f32);
extern f32 func_00389380(f32, f32);
extern s32 func_L01_00444358(void *, s32, s32);
extern void func_L01_00456960(s32);
extern void func_L01_0044DB68(u8 *, void *, f32, f32, f32);
/* Int and float parameters are interleaved on purpose: the order they are listed in decides how the
   argument moves are scheduled (func_L01_00447D00, func_L01_0044F090, func_L01_003B7058). */
extern void func_L01_00447D00(u8 *, void *, void *, f32, f32, s32, s32, f32, s32, f32, f32, f32, s32, f32, s32, s32, s32, s32, s32);
extern void func_0039FE80(s32, s32, u8 *);
extern void func_00388830(void *, void *, f32);
extern void func_L01_0044F090(u8 *, s32, void *, f32, f32, s32, f32, s32, f32, f32, f32, s32, f32, s32, s32);
extern void func_003BDA38(u8 *, s32, void *);
extern s32 func_L01_004562A0(void *, s32, f32);
extern void func_L01_003B6CF0(void *, s32, s32, s32, s32, f32);
extern s32 func_003883C8(void *);
extern s32 func_L01_0032FE90(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_003B7058(u8 *, f32, f32, f32, f32, s32, s32, s32);
extern f32 func_003893C8(f32, f32);
extern f32 func_003BEBF8(f32 *, f32, f32);
extern void func_L01_003B8B10(u8 *);
extern void func_L01_003B9A10(u8 *);

void func_L01_003B8370(u8 *obj) {
    u8 *st;
    u16 *cur;
    u16 *next;
    u8 *o2;
    u8 *c2;
    s32 *pp;
    s32 hh;
    s32 i;
    f32 *pv;
    f32 f20, f21, f22, f23, f24, f12, f0;
    f32 vA[4] __attribute__((aligned(16)));
    f32 vB[4] __attribute__((aligned(16)));
    f32 vC[4] __attribute__((aligned(16)));

    st = *(u8 **)(obj + 0x68);
    pp = *(s32 **)(st + 0x70);
    f21 = (f32)*pp;
    f24 = *(f32 *)(st + 0x14);
    hh = *(s16 *)(st + 0x80);
    cur = D_L01_0021DEA0[obj[0x21]];
    f23 = D_001DE920_sda * 0.017453292f * 0.016666668f;
    while (obj[0x21] != 0xFF && D_001E00D8_sda >= obj[0x21] && cur != 0 &&
           (((s16 *)cur)[-1] >= 0 || cur == D_L01_0021DEA0[obj[0x21]])) {
        o2 = D_L01_001E009C + ((*cur & 0x7FFF) << 8);
        if (o2 == 0) {
            return;
        }
        c2 = *(u8 **)(o2 + 0x68);
        f22 = *(f32 *)(o2 + 0xF8);
        if (*(s16 *)(o2 + 0xAA) != 0x1D3E && D_001D5476 != 0) {
            func_L01_00442E08(o2, 0x1D3E);
            *(f32 *)(o2 + 0x2C) = *(f32 *)(*(u8 **)(o2 + 0x24) + 0x24) * 1.5f;
            func_003BE4F0(o2, 5, 0, 0);
            func_003C26C8(o2);
        }
        f12 = *(f32 *)(c2 + 0x10) + *(f32 *)(c2 + 0x8C) * func_00388978(*(f32 *)(c2 + 0x90));
        if (f12 >= f21) {
            f12 = f12 - f21;
        } else if (f12 < 0.0f) {
            f12 = f12 + f21;
        }
        func_L01_00474140(pp, hh, o2 + 0x10, o2 + 0xF0, 0, f12);
        *(f32 *)(c2 + 0x78) = func_00389380(*(f32 *)(c2 + 0x78), *(f32 *)(c2 + 0x7C));
        *(f32 *)(o2 + 0x18) = *(f32 *)(o2 + 0x18) + func_00388978(*(f32 *)(c2 + 0x78));
        f0 = *(f32 *)(c2 + 0x10) + f24;
        *(f32 *)(c2 + 0x10) = f0;
        if (f0 >= f21) {
            *(f32 *)(c2 + 0x10) = f0 - f21;
        }
        *(f32 *)(c2 + 0x90) = func_00389380(*(f32 *)(c2 + 0x90), *(f32 *)(c2 + 0x94));
        if (func_L01_00444358(o2, 0x8010000, 0) != 0) {
            if (o2[0x31] != 0) {
                if (D_001D545C_sda_003B8370 == 0x10 && *(s16 *)(o2 + 0xAA) == 0x1C4E) {
                    func_L01_00456960(0x12);
                    *(s16 *)(c2 + 0xAE) = 5;
                    if (*(s16 *)(c2 + 0xAC) == 0) {
                        *(s16 *)(c2 + 0xAC) = 0x12C;
                    }
                } else {
                    o2[0x31] = 0;
                    *(u16 *)(o2 + 0x34) = *(u16 *)(o2 + 0x34) | 1;
                    *(s32 *)(o2 + 0x98) = 0;
                    *(u128_t *)vA = 0;
                    vA[2] = 0.050000004f;
                    func_L01_0044DB68(o2, vB, 0.0f, 0.0f, 0.0f);
                    func_L01_00447D00(o2, vA, vB, 0.0f, 0.0f, 0x23, 8, 5.0f, 0x10, 2.5f, 0.0f, 3.0f, -1, 15.0f, 1, 10, -1, 0, 0x1010001);
                    if (*(s16 *)(o2 + 0xAA) == 0x1C46 || *(s16 *)(o2 + 0xAA) == 0x1C87) {
                        func_0039FE80(0, 0, o2);
                    }
                    if (*(s16 *)(o2 + 0xAA) == 0xB13) {
                        func_0039FE80(1, 0, o2);
                    }
                    func_00388830(vC, o2 + 0xC0, *(f32 *)(c2 + 8) * 0.016666668f * 0.6f);
                    func_L01_0044F090(o2, 0xFF, vC, 1.3f, 3.0f, 1, 6.0f, 0x23, 3.0f, 6.0f, -1.0f, 0xFF, -1.0f, 0xB4, 0);
                }
            }
        }
        o2[0xA8] = 0xFF;
        next = cur + 1;
        if (*(s16 *)(c2 + 0xAC) != 0) {
            if (*(s16 *)(o2 + 0xAA) == 0x1C4E) {
                for (i = 0; i < *(s16 *)(c2 + 0xAE); i++) {
                    func_003BDA38(o2, i, vA);
                    pv = vA;
                    *(u128_t *)vB = *(u128_t *)vA;
                    vB[3] = 5.0f;
                    if (func_L01_004562A0(vB, 0, 255.0f) >= 0) {
                        func_L01_003B6CF0(pv, 2, 0xFF, 0x5A, 0x32, 0.75f);
                    }
                }
                if (func_003883C8(c2 + 0xAC) != 0) {
                    o2[0x31] = 0;
                    *(s32 *)(o2 + 0x98) = 0;
                    *(u16 *)(o2 + 0x34) = *(u16 *)(o2 + 0x34) | 1;
                    f20 = *(f32 *)(o2 + 0x2C) / *(f32 *)(*(u8 **)(o2 + 0x24) + 0x24);
                    func_L01_0032FE90(o2 + 0x10, 0, 0x19, 0, 0x14, 3, 0xA, 2, f20 * 0.15f, 0.0f, 0.0f, 2.0f, 0, 1, 1, 1, 0, 0,
                                      0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF,
                                      0x3064FF, 0);
                    D_L01_001E2AC0.f20 = 1.0f;
                    D_L01_001E2AC0.f28 = 0x2D;
                    D_L01_001E2AC0.f2C = 0;
                    for (i = 0; i < 15; i++) {
                        func_L01_003B7058(o2, 0.0f, 0.35f, 0.05f, f20, 3, 0xFF, 0);
                    }
                    func_00388830(vC, o2 + 0xC0, *(f32 *)(c2 + 8) * 0.016666668f * 0.6f);
                    func_L01_0044F090(o2, 0x3FF, vC, 1.3f, 6.0f, 1, 12.0f, 0x23, 3.0f, 6.0f, -1.0f, 0xFF, -1.0f, 0xB4, 0);
                }
            }
        }
        if (o2[0x31] != 0 && ((o2[0x34] ^ 1) & 1) != 0) {
            f12 = -func_003893C8(*(f32 *)(o2 + 0xF8), f22) * 50.0f;
            if (f12 > 0.7853982f) {
                f12 = 0.7853982f;
            }
            if (f12 < -0.7853982f) {
                f12 = -0.7853982f;
            }
            func_003BEBF8((f32 *)(o2 + 0xF0), f12, f23);
            if (*(s16 *)(c2 + 0x82) != 0) {
                func_L01_003B8B10(o2);
            }
            func_L01_003B9A10(o2);
        }
        func_003C26C8(o2);
        cur = next;
    }
}
/* localdecomp:end func_L01_003B8370 */
