/*
 * PAL near miss, P02 wave 2, 2026-11-16.
 * Owner: src/levels/07_annihilation_nation/L07_003B7408.c.
 * Exact flags: -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as.
 * Stock checker: 145 differing instructions on the initial formulation.
 * Remaining differences: health-threshold store scheduling, global-structure
 * address reuse, and later control-flow/register allocation.
 * No flags or metadata changed. Uses the stock owning-file context.
 * Preserved as a bounded draft, not a match; further tuning remains possible.
 */
#include "common.h"
extern u8 *func_L01_00447490(void *, s32, s32);
extern f32 func_L01_004474E8(void *, void *);
extern void func_L01_00459BE8(void *, s32, f32);
extern void func_003C4A40(void *, void *);
extern void func_L01_0044ABD0(void *, void *);
extern void func_L01_0044E820(void *, s32);
extern void func_L07_003A7488(s32, s32, s32);
extern void func_L07_003B8690(void *, s32);
extern void func_L07_003A2380(s32, void *, s32, s32);
extern void func_L07_003315B0(void *);
extern void func_L01_0047C990(s32, s32, s32, f32);
extern void func_L01_00456BD0(void *, s32);
extern s32 func_L07_00333D20(s32);
extern void func_L01_00456C98(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L07_003B8870(u8 *);
extern s32 func_L01_00456250(void *);
extern s32 func_00382468(s32);
extern void func_L01_00456230(void *, s32);
extern void func_0038CB00(void *);
extern void func_L07_004522E8(void *, s32, void *, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern u8 *D_L07_001DF41C;
extern u8 D_L07_001E1EC0[];
void func_L07_003B7F80(u8 *obj)
{
    u8 *p = *(u8 **)(obj + 0x68);
    u8 *hit;
    u8 *other;
    f32 damage;
    if (obj[0x20] == 1) return;
    hit = func_L01_00447490(obj, -1, 0);
    damage = func_L01_004474E8(obj, hit);
    obj[0xA8] = 255;
    if ((*(u16 *)(obj + 0x34) & 0x4000) && damage > 0.0f) {
        if (hit && *(u8 **)(hit + 0x20) &&
            *(s16 *)(*(u8 **)(hit + 0x20) + 0xAA) == 0x1A1C) damage = 1.0f;
        *(f32 *)(p + 0x30) -= damage;
        func_L01_00459BE8(obj, p[0x47], damage);
        p[0x187] = 255;
        func_003C4A40(obj, p + 0x180);
        if (damage >= *(s16 *)(p + 0x34) * 0.1f) {
            other = D_L07_001DF41C + (*(s32 *)(p + 0x280) << 8);
            if (!other[0xBC]) other[0xBC] = 2;
        }
    }
    func_L01_0044ABD0(obj, p + 0x180);
    if (*(s16 *)(p + 0x180) == 0) func_L01_0044E820(obj, *(s32 *)(p + 0x2A4));
    if (p[0x296] == 0) {
        if (*(f32 *)(p + 0x30) < *(s16 *)(p + 0x34) * 0.65f) {
            func_L07_003A7488(*(s32 *)(p + 0x288), 0, 8);
            func_L07_003B8690(obj, 13);
            p[0x296] = 1;
            *(f32 *)(p + 0x30) = *(s16 *)(p + 0x34) * 0.65f;
            (D_L07_001DF41C + (*(s32 *)(p + 0x280) << 8))[0xBC] = 3;
        }
    } else if (p[0x296] == 1) {
        if (*(f32 *)(p + 0x30) < *(s16 *)(p + 0x34) * 0.3f) {
            func_L07_003A7488(*(s32 *)(p + 0x288), 0, 8);
            p[0x296] = 2;
            *(f32 *)(p + 0x30) = *(s16 *)(p + 0x34) * 0.3f;
            (D_L07_001DF41C + (*(s32 *)(p + 0x280) << 8))[0xBC] = 4;
            func_L07_003A2380(10, obj, 0, 100);
        }
    }
    if (*(f32 *)(p + 0x30) <= 0.0f) {
        p[0x299] = 0;
        func_L07_003A7488(*(s32 *)(p + 0x288), 0, 8);
        func_L07_003B8690(obj, 17);
        return;
    }
    if (p[0x5E]) {
        func_L07_003315B0(obj);
        p[0x5E] = 0;
        return;
    }
    if (p[0x60]) {
        func_L07_003315B0(obj);
        p[0x60] = 0;
        return;
    }
    if (p[0x299]) {
        if (*(void **)(D_L07_001E1EC0 + 0x144) != obj &&
            *(void **)(D_L07_001E1EC0 + 0x144) == 0) {
            *(s32 *)(D_L07_001E1EC0 + 0x148) = 0;
            *(void **)(D_L07_001E1EC0 + 0x144) = obj;
        }
    } else if (*(void **)(D_L07_001E1EC0 + 0x144) == obj) {
        *(void **)(D_L07_001E1EC0 + 0x144) = 0;
    }
    func_L01_0047C990(3, 2, *(void **)(D_L07_001E1EC0 + 0x144) != obj,
        *(f32 *)(p + 0x30) / *(s16 *)(p + 0x34));
    func_L01_00456BD0(obj, 3);
    func_L01_00456C98(obj, func_L07_00333D20(*(s32 *)(p + 0x190)),
        0, 0, 0, 0, 1, 0, 0, 0, 0.0f, 0.0f, 1.0f);
    func_L07_003B8870(obj);
    if (func_L01_00456250(obj)) {
        if (*(s16 *)(p + 0x29E) == 0) {
            other = D_L07_001DF41C + (*(s32 *)(p + 0x280) << 8);
            if (!other[0xBC]) other[0xBC] = 1;
            if (func_00382468(2)) func_L07_003A2380(0, obj, 0, 100);
            else func_L07_003A2380(1, obj, 0, 100);
            *(s16 *)(p + 0x29E) = 1000;
        }
        func_L01_00456230(obj, 0);
    }
    func_0038CB00(p + 0x29C);
    func_L07_004522E8(obj, 4, p + 0x230, 2.5f);
    if (func_L01_0040E548(D_L07_001E1EC0, obj + 0x10) < 5625.0f) {
        func_L01_004472C0(obj);
        obj[0x6F] = 70;
    }
}
