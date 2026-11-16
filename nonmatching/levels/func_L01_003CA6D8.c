/* NTSC-U draft (Claude wave K): C of func_L01_003C8E40, the NTSC-U twin of func_L01_003CA6D8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 200 words differ on NTSC-U (the worker's best count) (NTSC-U twin "func_L01_003C8E40", whose code is not the PAL one).
 * Worker's note: 200 diff, flat store schedule (retail interleaves ~30 hoisted float constants f0-f9 with the field stores; mine different order): fully decoded effect/NPC init s32 f(u8 *self, u8 *other): return 0 if self==0 or state>=2; h34 = (h34&0xFFBC)/(owner->h44&0x1000) ...
 */
#include "common.h"

/* NTSC-U counterpart of func_L01_003C8DE8 (src/levels/shared/L01_003C8DE8.c) */
/* localdecomp:start func_L01_003C8E40 */
typedef int u128_t __attribute__((mode(TI)));
__asm__(".extern D_001D545C_sda, 4");
__asm__(".extern D_001DAA70_sda, 4");
extern s32 D_001D545C_sda;
extern f32 D_001DAA70_sda;
extern u8 D_0014275B[];
extern f32 D_L01_002F1550[];
extern s32 func_L01_00417EA0(void);
extern void func_00388440(void *, s32, s32);
extern void func_L01_00452E70(void *, void *);
extern u8 *func_003BCFB0(s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003C26C8(void *);

s32 func_L01_003C8E40(u8 *self, u8 *other) {
    u8 *s0;
    u8 *o;
    u8 *t4;
    u8 *p;
    s32 a1;
    s32 a;
    f32 f20;
    f32 m;
    u16 fl;

    if (self[0x20] >= 2 || self == 0) {
        return 0;
    }
    t4 = *(u8 **)(other + 0x68);
    fl = *(u16 *)(self + 0x34) & 0xFFBC;
    o = *(u8 **)(self + 0x24);
    *(u16 *)(self + 0x34) = fl;
    s0 = *(u8 **)(self + 0x68);
    *(u16 *)(self + 0x34) = fl | (*(u16 *)(o + 0x44) & 0x1000);
    *(s32 *)(self + 0x98) = *(s32 *)(o + 0x10);
    *(f32 *)(s0 + 0xF4) = 0.0069444445f;
    *(f32 *)(s0 + 0xF8) = 0.009722222f;
    *(f32 *)(s0 + 0xFC) = 0.00055555557f;
    s0[0xE0] = 0x1B;
    s0[0xE6] = 8;
    *(f32 *)(s0 + 0x104) = 0.5f;
    *(f32 *)(s0 + 0x10C) = 0.15f;
    *(f32 *)(s0 + 0xF0) = 0.016666668f;
    s0[0x14B] = 0xFF;
    s0[0x142] = 6;
    s0[0x143] = 0x10;
    s0[0x119] = 1;
    *(f32 *)(s0 + 0x190) = 0.4f;
    *(f32 *)(s0 + 0x194) = 0.3f;
    *(f32 *)(s0 + 0x198) = 2.2f;
    *(s16 *)(s0 + 0x108) = 0;
    s0[0x118] = 0xFF;
    s0[0xE1] = 8;
    s0[0xE2] = 8;
    *(f32 *)(s0 + 0x100) = 0.5f;
    s0[0x147] = 1;
    s0[0x148] = 0;
    s0[0x149] = 0;
    s0[0x14A] = 0;
    *(f32 *)(s0 + 0x19C) = 2.0f;
    *(f32 *)(s0 + 0x1A0) = 1.5707964f;
    *(f32 *)(s0 + 0x1C0) = 3.1415927f;
    *(f32 *)(s0 + 0x1BC) = 0.0021f;
    *(f32 *)(s0 + 0x1C4) = 2.0f;
    if (D_001D545C_sda == 4) {
        a = *(s16 *)(self + 0xB2);
        if (a == 0x20 || (u16)(*(u16 *)(self + 0xB2) - 0x22B) < 7 || a == 0x4ED) {
            *(f32 *)(s0 + 0x190) = 0.78f;
        }
    }
    s0[0x38] = 1;
    *(f32 *)(s0 + 0x40) = 0.5f;
    s0[0x39] = 0;
    s0[0x3F] = 0;
    a1 = *(s16 *)(t4 + 0x7A);
    if (a1 == -1) {
        if (*(s16 *)(s0 + 0x34) == 0 || *(f32 *)(s0 + 0x30) <= 0.0f) {
            if (func_L01_00417EA0() != 0) {
                if (D_001D545C_sda == 7 && D_0014275B[0] == 0) {
                    m = D_001DAA70_sda;
                } else {
                    m = D_L01_002F1550[D_001D545C_sda];
                }
                *(s16 *)(s0 + 0x34) = (s32)(m * 30.0f);
            } else {
                *(s16 *)(s0 + 0x34) = 0x1E;
            }
        }
    } else {
        f20 = (f32)a1;
        if (func_L01_00417EA0() != 0) {
            if (D_001D545C_sda == 7 && D_0014275B[0] == 0) {
                m = D_001DAA70_sda;
            } else {
                m = D_L01_002F1550[D_001D545C_sda];
            }
            *(s16 *)(s0 + 0x34) = (s32)(f20 * m);
        } else {
            *(s16 *)(s0 + 0x34) = (s32)f20;
        }
    }
    s0[0x58] = 0x14;
    s0[0x5A] = 0xE;
    *(f32 *)(s0 + 0x30) = (f32) * (s16 *)(s0 + 0x34);
    *(u128_t *)(s0 + 0x4B0) = *(u128_t *)(self + 0x10);
    *(u128_t *)(s0 + 0x4C0) = *(u128_t *)(self + 0xF0);
    func_00388440(s0 + 0x4D0, 0, 0x80);
    if (*(s32 *)(s0 + 0x550) == 0) {
        p = func_003BCFB0(0x19C1, 0x80);
        *(u8 **)(s0 + 0x550) = p;
        func_L01_00452E70(p, self);
    }
    func_L01_00441FB8(self, 2, -1);
    func_003C26C8(self);
    return 1;
}
/* localdecomp:end func_L01_003C8E40 */
