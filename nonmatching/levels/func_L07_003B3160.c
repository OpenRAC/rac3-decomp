/*
 * P03 PAL retail reconstruction, wave 2, base 1118a8b8 (2026-11-16).
 * Owner: src/levels/07_annihilation_nation/L07_003AF398.c.
 * Flags: -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
 *        -mno-check-zero-division @ps2as.
 * Stock checker: 166 positional differences; preserves checked iteration 05.
 * Attempts: 166, 197, 182, 197, 166 differences. Bounded reconstruction:
 * remaining hit-pointer lifetime/CSE, saved-register and call/store scheduling
 * differ. Whole-file source/ABI review still needed before integration.
 * No full build or US carry; marker retained.
 */
#include "common.h"
typedef struct { u8 bytes[16]; } Hit_003B3160;
extern s32 func_L01_00447490(void *, s32, s32);
extern f32 func_L01_004474E8(void *, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_L01_00459BE8(void *, s32, f32);
extern void func_003C4A40(void *, void *);
extern s32 func_L07_003A2380(u8, s32, u8, s16);
extern s32 func_00382468(s32);
extern void func_L01_0044ABD0(void *, void *);
extern void func_L01_0044E820(void *, s32);
extern void func_L01_00459C50(s32);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                             f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L07_003A2450(void);
extern void func_L07_003315B0(void *);
extern void func_L01_00456BD0(void *, s32);
extern s32 func_L07_00333D20(void *);
extern void func_L01_00456C98(void *, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L07_003B4DF8(u8 *);
extern void func_L02_003FB148(s32, s32, f32);
extern void func_L07_003B46E8(u8 *);
extern s32 func_0038CB00(void *);
extern u8 D_L07_001D66B0[];
void func_L07_003B3160(u8 *self) {
    u8 *p = *(u8 **)(self + 0x68);
    u8 *hit = p + 0x70;
    f32 damage, old;
    Hit_003B3160 copy;
    s32 anim;
    if (self[0x20] == 1) return;
    damage = func_L01_004474E8(self, func_L01_00447490(self, -1, 0));
    self[0xA8] = 0xFF;
    if ((*(u16 *)(self + 0x34) & 0x4000) && damage > 0.0f) {
        func_003A52A0(7, 0, self);
        old = *(f32 *)(p + 0x30);
        *(f32 *)(p + 0x30) = old - damage;
        func_L01_00459BE8(self, p[0x47], damage);
        p[0x77] = 0xFF;
        if (p[0x47] != 9 && p[0x47] != 25) p[0x676] = 0;
        hit = p + 0x70;
        func_003C4A40(self, hit);
        if (*(f32 *)(p + 0x30) < old - (f32)*(s16 *)(p + 0x34) * 0.1f &&
            !*(s16 *)(p + 0x670)) {
            func_L07_003A2380(20, (s32)self, 0, 100);
            *(s16 *)(p + 0x670) = func_00382468(125) + 250;
        }
    }
    func_L01_0044ABD0(self, hit);
    if (!*(s16 *)(p + 0x70)) func_L01_0044E820(self, *(s32 *)(p + 0x67C));
    if (*(f32 *)(p + 0x30) <= 0.0f) {
        if (p[0x676]) func_L01_00459C50(8);
        copy = *(Hit_003B3160 *)(p + 0x70);
        func_L01_0043B9E8(self, copy.bytes[4], copy.bytes[5], copy.bytes[6]);
        func_L01_00451FE0(self, 0x3FFF, D_L07_001D66B0, 255, 180, 0, 0, 35, 0, 3,
                         3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_L07_003A2450();
        func_L07_003A2380(81, (s32)self, 0, 100);
        func_L07_003315B0(self);
        return;
    }
    if (p[0x5E]) {
        func_L07_003315B0(self);
        p[0x5E] = 0;
        return;
    }
    if (p[0x60]) {
        func_L07_003315B0(self);
        p[0x60] = 0;
        return;
    }
    func_L01_00456BD0(self, 3);
    anim = func_L07_00333D20(*(void **)(p + 0x190));
    func_L01_00456C98(self, 0.0f, 0.0f, 1.0f, anim, 0, 0, 0, 0, 1, 0, 0, 0);
    func_L07_003B4DF8(self);
    func_L02_003FB148(6, 0, *(f32 *)(p + 0x30) / (f32)*(s16 *)(p + 0x34));
    func_L07_003B46E8(self);
    func_0038CB00(p + 0x66C);
    func_0038CB00(p + 0x66E);
    func_0038CB00(p + 0x670);
}
