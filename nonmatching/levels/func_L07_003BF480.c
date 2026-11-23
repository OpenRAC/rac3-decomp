/* PAL near miss, reserved50 P01 (2026-11-23): 28 differing words with
 * -mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as.
 * The flag-only whole level-07 build matches. Shared vec_add_ab removes the
 * original eight-word opaque-VU interleaving residue (historical draft: 36).
 * The remaining alpha/conditional-move allocation is unresolved: retail keeps
 * 0x44 in fp; this C hoists 2 instead. Narrow alpha/rotation and a conditional
 * expression produced the same wrong bytes; stopped after three formulations.
 * Earlier alpha-placement searches are not reset. Requires owner V_003BF3A8
 * and u128_t declarations. Not promoted. */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L07_003BF480 */
extern f32 D_001DE520_sda[] __attribute__((section(".sdata"))); __asm__(".extern D_001DE520_sda, 4");
extern s32 D_001DE510_sda[] __attribute__((section(".sdata"))); __asm__(".extern D_001DE510_sda, 4");
extern u8 D_L07_0021EC98[];
void func_L07_003BF480(u8 *m) {
    extern s32 func_00382468(s32);
    extern s32 func_00382498(s32, s32);
    extern f32 func_003824E0(f32, f32);
    extern void func_L07_003B9C28(void *, s32, s32, s32, s32, f32, f32, f32, f32);
    extern void func_0038D750(void *, s32, f32);
    extern void func_0038D810(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038D000(void *, void *, void *);
    extern void func_003C4C18(void *, f32);
    extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32);
    extern u8 *func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    f32 q[4];
    f32 matrix[3][4];
    V_003BF3A8 pos, at, velocity, scratch;
    s32 index;
    s32 tint;
    s32 i;
    f32 scale;
    u8 *base;
    s32 alpha;

    index = (u8)func_00382468(3);
    scale = D_001DE520_sda[index];
    tint = D_001DE510_sda[index];
    func_L07_003B9C28(m + 0x10, 8, 2, tint, tint, scale * 3.0f, scale * 15.0f, scale * 3.0f, scale * 8.0f);
    func_0038D750(q, 2, *(f32 *)(m + 0xF8));
    func_0038D810(q, matrix);
    func_0038CE20(&pos, matrix, 1.25f);
    vec_add_ab(&pos, m + 0x10, &pos);
    base = D_L07_0021EC98;
    alpha = 0x44;
    for (i = 1; i >= 0; i--) {
        s32 life;
        s32 rotation;
        f32 size;
        u8 *particle;

        *(u128_t *)&at = *(u128_t *)&pos;
        func_003C4C18(&at, 1.5f);
        *(u128_t *)&scratch = 0;
        scratch.y = func_00382468(2) ? -0.060000002f : 0.060000002f;
        scratch.z = 0.060000002f;
        *(u128_t *)&velocity = *(u128_t *)&scratch;
        func_0038D000(&velocity, &velocity, matrix);
        func_003C4C18(&velocity, 0.0200000014f);
        life = func_00382498(17, 33);
        rotation = 254;
        if (func_00382468(2) != 0) {
            rotation = 2;
        }
        size = func_003824E0(126000.0078125f, 189000.0f);
        particle = func_L01_00475C60(&at, &velocity, life, rotation, 0x7F5786AE, 0x2E475C, 0, size, size * 1.5f, 0.0200000014f);
        if (particle != 0) {
            particle[3] = alpha;
            particle[2] = **(u8 **)(base + 0x10);
        }
    }
    if (func_00382468(6) == 0) {
        s32 life;
        s32 color;
        s32 rotation;
        f32 size;
        u8 *particle;

        *(u128_t *)&at = *(u128_t *)&pos;
        func_003C4C18(&at, 0.15f);
        *(u128_t *)&scratch = 0;
        scratch.y = func_00382468(2) ? -0.3f : 0.3f;
        scratch.z = 0.2000000179f;
        *(u128_t *)&velocity = *(u128_t *)&scratch;
        func_0038D000(&velocity, &velocity, matrix);
        func_003C4C18(&velocity, 0.100000009f);
        life = func_00382498(50, 67);
        color = 0x2E475C;
        if (func_00382468(2) != 0) {
            color = 0x5786AE;
        }
        rotation = 254;
        if (func_00382468(2) != 0) {
            rotation = 2;
        }
        size = func_003824E0(42000.0f, 63000.00390625f);
        particle = func_L01_004713C8(&at, &velocity, life, color, rotation, 127, 127, func_00382468(3) + 10, size, size, 0.0100000007f);
        if (particle != 0) {
            particle[3] = 0x44;
        }
    }
}
/* localdecomp:end func_L07_003BF480 */
