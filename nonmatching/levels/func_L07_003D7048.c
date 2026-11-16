/*
 * PAL near miss, P02 wave 2, 2026-11-16.
 * Owner: src/levels/07_annihilation_nation/L07_003D7048.c.
 * Exact flags: -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as.
 * Stock checker: 62 differing instructions after three formulations.
 * A local typed hero pointer improves address reuse, but retail forms its
 * position address first, then subtracts 0x80 to retain the hero base.
 * Other differences include damage-table allocation and final block scheduling.
 * No flags or metadata changed. Uses the stock owning-file context.
 * Preserved as a bounded draft, not a match; further tuning remains possible.
 */
#include "common.h"
#include "vu0.h"
#include "structs/hero.h"
extern void func_L07_003D7350(u8 *);
extern s32 func_L01_004561B8(void *);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00404808(void *, void *);
extern void func_L07_003D7628(void);
extern s32 func_00382468(s32);
extern void func_L07_003D7520(void *, void *, s32);
extern void func_L03_003A1EB0(void *);
extern f32 func_L01_0040E570(void *, void *);
extern s32 func_L01_0041A4F0(void);
extern void func_L01_00446A70(void *, void *, s32, void *, void *, f32);
extern void func_L01_004AA760(s32, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern f32 func_003C3BE8(f32, f32, f32);
extern void func_003C7C38(void *);
extern struct Hero D_001A4BE0;
extern u8 D_0014275B;
extern s32 D_001D545C;
extern f32 D_L07_002F3630[];
extern f32 D_001DA978;
extern u8 D_001D66B0[];
void func_L07_003D7048(u8 *obj)
{
    u8 *p;
    f32 position[4] __attribute__((aligned(16)));
    f32 damage, angle;
    struct Hero *hero = &D_001A4BE0;
    func_L07_003D7350(obj);
    p = *(u8 **)(obj + 0x68);
    switch (obj[0x20]) {
    case 0: case 3: break;
    case 1:
        if (p[8] == 2) func_L01_004450F0(obj, 4, -1);
        break;
    case 2:
        if (func_L01_004561B8(obj)) func_003A52A0(1, 4, obj);
        if (obj[0x31]) {
            func_L01_00404808(func_L07_003D7628, obj);
            if (func_00382468(10) == 0) {
                func_L07_003D7520(obj, position, func_00382468(12));
                func_L03_003A1EB0(position);
            }
        }
        if (func_L01_0040E570(obj + 0x10, &hero->pos) < 9.0f &&
            fabs_asm(*(f32 *)(obj + 0x18) - hero->pos.z) < 0.75f) {
            if (func_L01_0041A4F0()) {
                if (D_001D545C == 7 && D_0014275B) damage = D_001DA978;
                else damage = D_L07_002F3630[D_001D545C];
            } else damage = 1.0f;
            func_L01_00446A70(hero->hero_moby, obj, 1, D_001D66B0, D_001D66B0, damage);
        }
        if (p[8] == 1) {
            func_L01_004AA760(1, obj);
            func_L01_004450F0(obj, 5, -1);
        }
        break;
    case 4:
        if (func_L01_004561B8(obj)) func_003A52A0(0, 4, obj);
        *(f32 *)(p + 0x14) += 0.012f;
        if (*(f32 *)(p + 0x14) >= 1.0f) {
            *(f32 *)(p + 0x14) = 1.0f;
            func_L01_004AA760(0, obj);
            func_L01_004450F0(obj, 2, -1);
        }
        angle = func_003C3BE8(3.1415927f, 0.0f, *(f32 *)(p + 0x14));
        *(f32 *)(obj + 0xF0) = angle;
        *(f32 *)(*(u8 **)(p + 0x10) + 0xF0) = angle;
        func_003C7C38(*(void **)(p + 0x10));
        break;
    case 5:
        if (func_L01_004561B8(obj)) func_003A52A0(0, 4, obj);
        *(f32 *)(p + 0x14) -= 0.012f;
        if (*(f32 *)(p + 0x14) <= 0.0f) {
            *(f32 *)(p + 0x14) = 0.0f;
            func_L01_004AA760(0, obj);
            func_L01_004450F0(obj, 1, -1);
        }
        angle = func_003C3BE8(3.1415927f, 0.0f, *(f32 *)(p + 0x14));
        *(f32 *)(obj + 0xF0) = angle;
        *(f32 *)(*(u8 **)(p + 0x10) + 0xF0) = angle;
        func_003C7C38(*(void **)(p + 0x10));
        break;
    }
}
