/*
 * P03 PAL retail reconstruction, wave 2, base 1118a8b8 (2026-11-16).
 * Owner: src/levels/07_annihilation_nation/L07_003AF398.c.
 * Flags: -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
 *        -mno-check-zero-division @ps2as.
 * Stock checker: 165 positional differences; preserves checked iteration 04.
 * Attempts: 303, 165, 165, 165 differences. Moving pointer lifetimes,
 * correcting the event prototype and reusing the hit/pool pointer leave
 * iterations 02/03/04 with identical checker output. Remaining: saved
 * pointer allocation, stage joins, call scheduling and absolute/GP addressing.
 * No full build or US carry; marker retained.
 */
#include "common.h"
typedef struct { u8 bytes[16]; } Hit_003B5E08;
typedef struct { u8 pad[0x144]; u8 *owner; s32 ticks; } Pool_003B5E08;
extern u8 D_L07_001E1EC0[];
extern u8 *D_L07_001DF41C;
extern u8 D_L07_001D66B0[];
extern s32 func_L01_00447490(void *, s32, s32);
extern f32 func_L01_004474E8(void *, s32);
extern void func_L01_004AAC98(s32, s32, void *, s32);
extern void func_L01_00459BE8(void *, s32, f32);
extern void func_003C4A40(void *, void *);
extern void func_L01_0044ABD0(void *, void *);
extern void func_L01_0044E820(void *, s32);
extern s32 func_0038CB00(void *);
extern s32 func_L07_003A2380(u8, s32, u8, s16);
extern void func_L07_003B64D0(u8 *, s32);
extern void func_L01_0043B9E8(void *, s32, s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, s32, s32, s32, s32, s32, s32, s32,
                             f32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L07_003315B0(void *);
extern void func_L01_0047C990(s32, s32, s32, f32);
extern void func_L01_00456BD0(void *, s32);
extern s32 func_L07_00333D20(void *);
extern void func_L01_00456C98(void *, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L07_003B6870(void *);
extern void func_L07_004522E8(void *, s32, void *, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
void func_L07_003B5E08(u8 *self) {
    u8 *p = *(u8 **)(self + 0x68);
    u8 *hit;
    u8 *other;
    Hit_003B5E08 copy;
    s32 anim;
    f32 damage, limit;
    if (self[0x20] == 1) return;
    anim = func_L01_00447490(self, -1, 0);
    hit = p + 0x70;
    damage = func_L01_004474E8(self, anim);
    self[0xA8] = 255;
    if ((*(u16 *)(self + 0x34) & 0x4000) && damage > 0.0f) {
        if (!*(s16 *)(p + 0x330)) {
            func_L01_004AAC98(0, 0, self, 0x1A1C);
            *(s16 *)(p + 0x330) = 50;
        }
        *(f32 *)(p + 0x30) -= damage;
        func_L01_00459BE8(self, p[0x47], damage);
        p[0x77] = 255;
        func_003C4A40(self, hit);
        if (damage >= (f32)*(s16 *)(p + 0x34) * 0.1f) {
            other = D_L07_001DF41C + *(s32 *)(p + 0x300) * 256;
            if (!other[0xBC]) other[0xBC] = 2;
        }
    }
    func_L01_0044ABD0(self, hit);
    if (!*(s16 *)(p + 0x70)) func_L01_0044E820(self, *(s32 *)(p + 0x33C));
    func_0038CB00(p + 0x330);
    if (p[0x321] == 0) {
        limit = 0.66f;
        if (*(f32 *)(p + 0x30) < (f32)*(s16 *)(p + 0x34) * limit) {
            func_L07_003A2380(6, (s32)self, 0, 100);
            func_L07_003B64D0(self, 18);
            p[0x321] = 1;
            p[0x326] = 3;
            *(f32 *)(p + 0x30) = (f32)*(s16 *)(p + 0x34) * limit;
        }
    } else if (p[0x321] == 1) {
        limit = 0.33f;
        if (*(f32 *)(p + 0x30) < (f32)*(s16 *)(p + 0x34) * limit) {
            func_L07_003B64D0(self, 18);
            p[0x321] = 2;
            p[0x326] = 3;
            *(f32 *)(p + 0x30) = (f32)*(s16 *)(p + 0x34) * limit;
        }
    }
    if (p[0x326]) {
        other = *(u8 **)(p + 0x308);
        if (other) {
            if (*(s16 *)(other + 0xAA) != 0x1C81 || other[0x20] == 254 || other[0x20] == 253)
                *(s32 *)(p + 0x308) = 0;
        } else {
            (D_L07_001DF41C + *(s32 *)(p + 0x300) * 256)[0xBC] = p[0x326];
            p[0x326] = 0;
        }
    }
    if (*(f32 *)(p + 0x30) <= 0.0f) {
        copy = *(Hit_003B5E08 *)(p + 0x70);
        func_L01_0043B9E8(self, copy.bytes[4], copy.bytes[5], copy.bytes[6]);
        func_L01_00451FE0(self, 0x3FFF, D_L07_001D66B0, 255, 180, 0, 0, 35, 0, 3,
                         8.0f, 12.0f, 8.0f, 12.0f, -1.0f, -1.0f, 1.0f, 1.0f);
        func_L07_003315B0(self);
        return;
    }
    if (p[0x5E]) { func_L07_003315B0(self); p[0x5E] = 0; return; }
    if (p[0x60]) { func_L07_003315B0(self); p[0x60] = 0; return; }
    hit = D_L07_001E1EC0;
    if (p[0x324]) {
        if (((Pool_003B5E08 *)hit)->owner != self && ((Pool_003B5E08 *)hit)->owner == 0) {
            ((Pool_003B5E08 *)hit)->ticks = 0;
            ((Pool_003B5E08 *)hit)->owner = self;
        }
    } else if (((Pool_003B5E08 *)hit)->owner == self) ((Pool_003B5E08 *)hit)->owner = 0;
    func_L01_0047C990(2, 0, ((Pool_003B5E08 *)hit)->owner != self,
                     *(f32 *)(p + 0x30) / (f32)*(s16 *)(p + 0x34));
    func_L01_00456BD0(self, 3);
    anim = func_L07_00333D20(*(void **)(p + 0x190));
    func_L01_00456C98(self, 0.0f, 0.0f, 1.0f, anim, 0, 0, 0, 0, 1, 0, 0, 0);
    func_L07_003B6870(self);
    func_0038CB00(p + 0x328);
    func_L07_004522E8(self, 17, p + 0x2B0, 2.5f);
    if (func_L01_0040E548(hit, self + 0x10) < 5625.0f) {
        func_L01_004472C0(self);
        self[0x6F] = 70;
    }
}
