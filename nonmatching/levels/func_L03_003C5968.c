/* NTSC-U draft (Claude wave K): C of func_L03_003C3B00, the NTSC-U twin of func_L03_003C5968, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 285 words differ on NTSC-U (the worker's best count) (NTSC-U twin "func_L03_003C3B00", whose code is not the PAL one).
 * Worker's note: 285 diff but structurally complete NPC (self=a0, s3=self->0x68 state block): D_001D545C==3 cutscene branch last, else state0 (spawn/hit-test via func_003CE740 on sp vec +-1.0, 4 random floats func_0037E2A8 into 0xF0..0xFC, func_L01_00441FB8(self,1,-1)), ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L03_003C5968 (src/levels/shared/L03_003C5460.c) */
/* localdecomp:start func_L03_003C3B00 */
typedef int u128_t __attribute__((mode(TI)));
extern s32 D_001D545C_sda;
extern f32 D_001DEDF0_sda;
extern s32 D_001DF35C_sda;
extern s32 D_L03_001DF738[];
extern f32 D_L03_001E92A8[];
extern u8 D_00142796[];
extern u8 D_001A4C60[];
extern u8 D_001A4BE0[];
extern u8 D_001CCFD0[];
extern u16 D_001A7E18[];
extern s32 func_003CE740(void *, void *, s32, void *, s32);
extern f32 func_0037E2A8(void);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_003887C8(void *, void *);
extern void func_L03_003C35F8(void *);
extern f32 func_00389380(f32, f32);
extern void func_L03_003C3340(void *);
extern void func_L01_0044B860(void *, void *, void *, f32, f32, f32);
extern void func_0039C710(void);
extern void func_L03_003C38F8(void *);
extern s32 func_0037E1D8(s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_0050BB98(s32, s32, f32);
extern s32 func_00388398(void *);
extern void func_L01_004F12C0(void *, void *, s32, s32);
extern void func_L01_003E9730(s32, s32);
extern s32 func_0039FE80(s32, s32, void *);
extern void func_L03_003C3FA8(void *, s32);
extern void func_L01_0044ECE0(s32, s32, s32);
extern void func_00399F90(void);
extern void func_00399C90(s32, s32);
extern void func_L01_00417F60(s32, s32);
extern void func_L01_004A6DF8(void *, s32);
extern void func_003BD360(void *);

void func_L03_003C3B00(u8 *self) {
    u8 *s3 = *(u8 **)(self + 0x68);
    u128_t t0;
    u128_t t1;
    u8 *hero;
    s32 one;
    s32 i;
    u16 fl;

    if (s3 == 0) {
        return;
    }
    if (D_001D545C_sda != 3) {
        if (self[0x20] == 0) {
            if (D_00142796[0] != 0) {
                func_003BD360(self);
                return;
            }
            *(u128_t *)(s3 + 0x20) = *(u128_t *)(self + 0x10);
            *(f32 *)(s3 + 0x2C) = *(f32 *)(self + 0xF8);
            t1 = *(u128_t *)(self + 0x10);
            t0 = t1;
            ((f32 *)&t1)[2] = ((f32 *)&t1)[2] + 1.0f;
            ((f32 *)&t0)[2] = ((f32 *)&t0)[2] - 1.0f;
            if (func_003CE740(&t1, &t0, 2, self, 0) != 0) {
                *(f32 *)(self + 0x18) = D_L03_001E92A8[0] + 0.5f;
            }
            *(f32 *)(self + 0xF0) = func_0037E2A8();
            *(f32 *)(self + 0xF4) = func_0037E2A8();
            *(f32 *)(self + 0xF8) = func_0037E2A8();
            *(f32 *)(self + 0xFC) = func_0037E2A8();
            *(f32 *)(s3 + 8) = *(f32 *)(self + 0x18);
            func_L01_00441FB8(self, 1, -1);
        } else if (self[0x20] == 1) {
            if (func_003887C8(D_001A4C60, self + 0x10) <= D_001DEDF0_sda) {
                func_L03_003C35F8(self);
            }
        }
        if (self[0x20] == 1) {
            *(f32 *)(self + 0xF0) = func_00389380(*(f32 *)(self + 0xF0), 0.03450f);
            *(f32 *)(self + 0xF4) = func_00389380(*(f32 *)(self + 0xF4), 0.0029999f);
            *(f32 *)(self + 0xF8) = func_00389380(*(f32 *)(self + 0xF8), 0.0058f);
            *(f32 *)(self + 0xFC) = func_00389380(*(f32 *)(self + 0xFC), 0.0261f);
            func_L03_003C3340(self);
            func_L01_0044B860(self, s3, s3 + 4, 0.25f, 0.023f, *(f32 *)(s3 + 8));
            *(s16 *)(self + 0x96) = 0;
        } else if (self[0x20] == 2) {
            u8 *a = D_001CCFD0;
            u8 *h = D_001A4BE0;
            if (*(s16 *)(a + 0x76) == 0) {
                if (*(s16 *)(a + 0x9E) == 3 && *(s16 *)(a + 0x98) < 0x1B58) {
                    func_0039C710();
                }
            }
            one = 1;
            hero = h;
            D_L03_001DF738[0] = one;
            *(s16 *)(hero + 0x1DC) = 3;
            func_L03_003C38F8(self);
            *(u128_t *)(self + 0x10) = *(u128_t *)(hero + 0x80);
            *(u128_t *)(self + 0xF0) = *(u128_t *)(hero + 0x90);
            if (self[0x42] == one) {
                if (func_0037E1D8(10) == 0) {
                    func_L03_003C3340(self);
                }
                if (self[0x60] & 2) {
                    if (self[0x43] != 0) {
                        func_003BE4F0(self, 0, 0, 0);
                    }
                    self[0x31] = 0;
                    *(u16 *)(self + 0x34) |= 1;
                    for (i = 3; i >= 0; i--) {
                        func_L03_003C3340(self);
                    }
                }
            }
            if (*(s32 *)(hero + 0xC08) & 2) {
                func_L01_0050BB98(0, 0, 30.0f);
            }
            if (self[0x42] == 0) {
                if (func_00388398(s3 + 0x7C) != 0) {
                    D_001DF35C_sda = 0;
                    func_L01_004F12C0(hero + 0x80, hero + 0x90, 0, 0);
                    func_L01_003E9730(0, 0);
                    func_0039FE80(0, 0, self);
                    func_L03_003C3FA8(self + 0x10, 10);
                    func_L01_0044ECE0(0x12AD, 0x1F4, 0);
                    D_00142796[0] = 1;
                    func_00399F90();
                    func_00399C90(0, -1);
                    if (D_001A7E18[(0x8000 + 0x4540) / 2] == 0) {
                        func_L01_00417F60(0x1070, 0xDF);
                    }
                    *(s32 *)(self + 0x98) = 0;
                    *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
                    func_L01_004A6DF8(self, 1);
                }
            }
        }
    } else {
        if (self[0x20] == 0) {
        self[0x20] = 1;
        if (D_00142796[0] == 0) {
            *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) | 0x41) & 0xEFFF;
            *(s32 *)(self + 0x98) = 0;
            func_L01_004A6DF8(self, 1);
        } else {
            u8 *o;
            *(f32 *)(self + 0xF4) = func_00389380(*(f32 *)(self + 0xF4), 1.5707964f);
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
/* localdecomp:end func_L03_003C3B00 */
