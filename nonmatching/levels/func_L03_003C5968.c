/* func_L03_003C5968 (Claude wave 14 r74, 2026-11-28). Replaces the earlier draft of this function (PAL port of the NTSC-U draft of `func_L03_003C3B00` (Claude wave K)). */
/* r74 wave 14 (2026-11-28): the b39-w10 draft made file-ready again: it declared func_L03_003C5460 and
 * func_L03_003C5760 as void (void *), which conflicts with L03_003C5460.c's definitions (u8 * and O_003C5760 *);
 * now it uses the file's prototypes (the call passes (O_003C5760 *)self). Under the file's own line it is 7 diff at
 * level 03 (wave10/p10/check.py), all register choices: retail keeps the first zero-extension of self[0x20] in
 * a0 and the raw copy in a1, here v1/a0. greg dump: x (zext, pseudo 124) gets v1 because it does not conflict with
 * the join's zext x2 (pseudo 174, allocated first, v1); retail behaves as if x2 were already live in the
 * `== 1` test block (PRE-inserted there), which makes x conflict with v1 and pushes x to a0 and the copy to a1.
 * A 160 s permuter run (1450 candidates) found nothing below its base. */
#include "common.h"

/* localdecomp:start func_L03_003C5968 */
extern s32 D_001D545C_sda;
extern f32 D_001DEDB0_sda;
__asm__(".extern D_001DEDB0_sda, 4");
extern s32 D_L03_001DF2DC;
extern s32 D_L03_001DF6B8;
__asm__(".extern D_L03_001DF6B8, 16");
extern f32 D_L03_001E9228[];
extern u8 D_00142796[];
extern u8 D_001A4C60[];
extern u8 D_001A4BE0[];
extern u16 D_001A7E18[];
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_00382538(void);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_L03_003C5190(void *);
extern void func_L01_0044EAE0(void *, void *, void *, f32, f32, f32);
extern void func_003A1798(void);
extern s32 func_00382468(s32);
extern void func_003C3A10(void *, s32, s32, s32);
extern void func_L01_0050FB40(s32, s32, f32);
extern s32 func_0038CAD0(void *);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_003EB5E0(s32, s32);
extern void func_L03_003C5E10(void *, s32);
extern void func_L01_00451F60(s32, s32, s32);
extern void func_0039EF28(void);
extern s32 func_0039EC28(s32, s32);
extern void func_L01_0041A5B0(s32, s32);
extern void func_L01_004AA7E8(void *, s32);
extern void func_003C2880(void *);

void func_L03_003C5968(u8 *self) {
    u8 *s3 = *(u8 **)(self + 0x68);
    u128_t tt[2];
    s32 one;
    s32 i;
    u16 fl;

    if (s3 == 0) {
        return;
    }
    if (D_001D545C_sda != 3) {
        if (self[0x20] == 0) {
            if (D_00142796[0] != 0) {
                func_003C2880(self);
                return;
            }
            *(u128_t *)(s3 + 0x20) = *(u128_t *)(self + 0x10);
            *(f32 *)(s3 + 0x2C) = *(f32 *)(self + 0xF8);
            tt[0] = *(u128_t *)(self + 0x10);
            tt[1] = tt[0];
            ((f32 *)&tt[1])[2] = ((f32 *)&tt[1])[2] + 1.0f;
            ((f32 *)&tt[0])[2] = ((f32 *)&tt[0])[2] - 1.0f;
            if (func_003D3CB0(&tt[1], &tt[0], 2, self, 0) != 0) {
                *(f32 *)(self + 0x18) = D_L03_001E9228[0] + 0.5f;
            }
            *(f32 *)(self + 0xF0) = func_00382538();
            *(f32 *)(self + 0xF4) = func_00382538();
            *(f32 *)(self + 0xF8) = func_00382538();
            *(f32 *)(self + 0xFC) = func_00382538();
            *(f32 *)(s3 + 8) = *(f32 *)(self + 0x18);
            func_L01_004450F0(self, 1, -1);
        } else if (self[0x20] == 1) {
            if (func_0038CF00(D_001A4C60, self + 0x10) <= D_001DEDB0_sda) {
                func_L03_003C5460(self);
            }
        }
        if (self[0x20] == 1) {
            *(f32 *)(self + 0xF0) = func_0038DAB8(*(f32 *)(self + 0xF0), 0.041887905f);
            *(f32 *)(self + 0xF4) = func_0038DAB8(*(f32 *)(self + 0xF4), 0.013962635f);
            *(f32 *)(self + 0xF8) = func_0038DAB8(*(f32 *)(self + 0xF8), 0.0069813174f);
            *(f32 *)(self + 0xFC) = func_0038DAB8(*(f32 *)(self + 0xFC), 0.03141593f);
            func_L03_003C5190(self);
            func_L01_0044EAE0(self, s3, s3 + 4, 0.25f, 0.02792527f, *(f32 *)(s3 + 8));
            *(s16 *)(self + 0x96) = 0;
        } else if (self[0x20] == 2) {
            u8 *a = (u8 *)&D_001CCFD0;
            u8 *h1;
            u8 *h2;
            if (*(s16 *)(a + 0x76) == 0) {
                if (*(s16 *)(a + 0x9E) == 3 && *(s16 *)(a + 0x98) < 0x1B58) {
                    func_003A1798();
                }
            }
            one = 1;
            D_L03_001DF6B8 = one;
            h1 = D_001A4BE0;
            *(s16 *)(h1 + 0x1DC) = 3;
            func_L03_003C5760((O_003C5760 *)self);
            *(u128_t *)(self + 0x10) = *(u128_t *)(h1 + 0x80);
            *(u128_t *)(self + 0xF0) = *(u128_t *)(h1 + 0x90);
            if (self[0x42] == one) {
                if (func_00382468(10) == 0) {
                    func_L03_003C5190(self);
                }
                if (self[0x60] & 2) {
                    if (self[0x43] != 0) {
                        func_003C3A10(self, 0, 0, 0);
                    }
                    self[0x31] = 0;
                    *(u16 *)(self + 0x34) |= 1;
                    for (i = 3; i >= 0; i--) {
                        func_L03_003C5190(self);
                    }
                }
            }
            h2 = D_001A4BE0;
            if (*(s32 *)(h2 + 0xC08) & 2) {
                func_L01_0050FB40(0, 0, 25.0f);
            }
            if (self[0x42] == 0) {
                if (func_0038CAD0(s3 + 0x7C) != 0) {
                    D_L03_001DF2DC = 0;
                    func_L01_004F50C8(h2 + 0x80, h2 + 0x90, 0, 0);
                    func_L01_003EB5E0(0, 0);
                    func_003A52A0(0, 0, self);
                    func_L03_003C5E10(self + 0x10, 10);
                    func_L01_00451F60(0x12AD, 0x1A1, 0);
                    D_00142796[0] = 1;
                    func_0039EF28();
                    func_0039EC28(0, -1);
                    if (D_001A7E18[(0x8000 + 0x4540) / 2] == 0) {
                        func_L01_0041A5B0(0x1070, 0xDF);
                    }
                    *(s32 *)(self + 0x98) = 0;
                    *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
                    func_L01_004AA7E8(self, 1);
                    func_003C2880(self);
                }
            }
        } else if (self[0x20] == 0 && self[0x42] == 3 && self[0x43] < 5) {
            return;
        } else {
            return;
        }
    } else {
        if (self[0x20] == 0) {
        self[0x20] = 1;
        if (D_00142796[0] == 0) {
            *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
            *(s32 *)(self + 0x98) = 0;
            func_L01_004AA7E8(self, 1);
        } else {
            u8 *o;
            *(f32 *)(self + 0xF4) = func_0038DAB8(*(f32 *)(self + 0xF4), 1.5707964f);
            *(f32 *)(self + 0x18) = *(f32 *)(self + 0x18) + 0.35f;
            fl = *(u16 *)(self + 0x34) & 0xFFBE;
            o = *(u8 **)(self + 0x24);
            *(u16 *)(self + 0x34) = fl;
            *(u16 *)(self + 0x34) = fl | (*(u16 *)(o + 0x44) & 0x1000);
            *(s32 *)(self + 0x98) = *(s32 *)(o + 0x10);
        }
        }
    }
}
/* localdecomp:end func_L03_003C5968 */
