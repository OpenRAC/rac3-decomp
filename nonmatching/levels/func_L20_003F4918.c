/*
 * PAL reconstruction from the owner's retail ELF, 2026-11-16.
 * Owning file: src/levels/20_final_boss/L20_003F45B8.c.
 * Flags: -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack
 *        -mno-check-zero-division @ps2as.
 * Stock check.py: 27 differing instructions (candidate 06).
 * Ten candidate compiles total; no exact candidate.
 * Remaining: f20/f21 allocation, abs.s scheduling, early color constant,
 * prologue and final float-argument move order. fabs_asm variants were worse.
 * This is the best diagnostic result, not a full-program match.
 * No full build verification; keep INCLUDE_ASM.
 */
#include "common.h"
#include "vu0.h"
extern void func_L01_00443B88(void *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32,s32);
extern u8 *func_L01_004713C8(void *, void *, s32, u32, s32, s32, s32, s32, f32, f32, f32);
extern u8 *D_L20_002203DC[];
void func_L20_003F4918(void *pos) {
    vu0_v4 v;
    f32 speed;
    f32 z;
    f32 size;
    s32 color;
    u8 *p;
    func_L01_00443B88(&v, 0.020000001f, 0.0500000045f);
    z = v.z;
    z = __builtin_fabsf(z);
    z += func_003824E0(7.0f, 10.5f) * 0.020000001f;
    v.z = z;
    speed = func_003824E0(0.06f, 0.22f);
    func_00382468(3);
    color = func_00382468(3) ? 0x263438 : 0x273538;
    { s32 life = (func_00382498(90,150) * 5 + 2) / 6;
    size = 210000.0f;
    size *= speed;
    p = ((u8 *(*)(void *, void *, s32, u32, f32, f32, f32, s32, s32, s32, s32))func_L01_004713C8)(
        pos, &v, life, color, size, size, 0.00624000048f, -2, 127, 127, 0);
    }
    if (p != 0) {
        p[2] = D_L20_002203DC[0][func_00382468(3) + 10];
        p[3] = 0x44;
    }
}
