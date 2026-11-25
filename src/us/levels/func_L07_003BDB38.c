#include "vu0.h"

/* NTSC-U counterpart of PAL func_L07_003BF480. */
/* localdecomp:start func_L07_003BDB38 */
extern f32 D_U_001DE560[] __attribute__((section(".sdata")));
__asm__(".extern D_U_001DE560, 4");
extern s32 D_U_001DE550[] __attribute__((section(".sdata")));
__asm__(".extern D_U_001DE550, 4");
extern u8 D_L07_0021EC98[];
void func_L07_003BDB38(u8 *m) {
    extern s32 func_0037E1D8(s32);
    extern s32 func_0037E208(s32, s32);
    extern f32 func_0037E250(f32, f32);
    extern void func_L07_003B8338(void *, s32, s32, s32, s32, f32, f32, f32, f32);
    extern void func_00389018(void *, s32, f32);
    extern void func_003890D8(void *, void *);
    extern void func_003886E8(void *, void *, f32);
    extern void func_003888C8(void *, void *, void *);
    extern void func_003BF6A8(void *, f32);
    extern u8 *func_L01_00472438(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
    extern u8 *func_L01_0046DCB8(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    f32 q[4];
    f32 matrix[3][4];
    vu0_v4 pos, at, velocity, scratch;
    s32 index;
    s32 tint;
    s32 i;
    f32 scale;
    u8 *base;

    index = (u8)func_0037E1D8(3);
    scale = D_U_001DE560[index];
    tint = D_U_001DE550[index];
    func_L07_003B8338(m + 0x10, 10, 3, tint, tint, scale * 3.0f, scale * 15.0f, scale * 3.0f, scale * 8.0f);
    func_00389018(q, 2, *(f32 *)(m + 0xF8));
    func_003890D8(q, matrix);
    func_003886E8(&pos, matrix, 1.25f);
    vec_add_ab(&pos, m + 0x10, &pos);
    base = D_L07_0021EC98;
    for (i = 1; i >= 0; i--) {
        s32 life;
        s32 rotation;
        f32 size;
        u8 *particle;

        *(vu0_q *)&at = *(vu0_q *)&pos;
        func_003BF6A8(&at, 1.5f);
        *(vu0_q *)&scratch = 0;
        scratch.y = func_0037E1D8(2) ? -0.050000004f : 0.050000004f;
        scratch.z = 0.050000004f;
        *(vu0_q *)&velocity = *(vu0_q *)&scratch;
        func_003888C8(&velocity, &velocity, matrix);
        func_003BF6A8(&velocity, 0.016666668f);
        life = func_0037E208(20, 40);
        rotation = 254;
        if (func_0037E1D8(2) != 0) {
            rotation = 2;
        }
        size = func_0037E250(126000.0078125f, 189000.0f);
        particle = func_L01_00472438(&at, &velocity, life, rotation, 0x7F5786AE, 0x2E475C, size, size * 1.5f, 0.013888889f, 0);
        if (particle != 0) {
            particle[2] = **(u8 **)(base + 0x10);
            particle[3] = 0x44;
        }
    }
    if (func_0037E1D8(6) == 0) {
        s32 life;
        s32 color;
        s32 rotation;
        f32 size;
        u8 *particle;

        *(vu0_q *)&at = *(vu0_q *)&pos;
        func_003BF6A8(&at, 0.15f);
        *(vu0_q *)&scratch = 0;
        scratch.y = func_0037E1D8(2) ? -0.25f : 0.25f;
        scratch.z = 0.16666667f;
        *(vu0_q *)&velocity = *(vu0_q *)&scratch;
        func_003888C8(&velocity, &velocity, matrix);
        func_003BF6A8(&velocity, 0.083333336f);
        life = func_0037E208(60, 80);
        color = 0x2E475C;
        if (func_0037E1D8(2) != 0) {
            color = 0x5786AE;
        }
        rotation = 254;
        if (func_0037E1D8(2) != 0) {
            rotation = 2;
        }
        size = func_0037E250(42000.0f, 63000.00390625f);
        particle = func_L01_0046DCB8(&at, &velocity, life, color, rotation, 127, 127, func_0037E1D8(3) + 10, size, size, 0.0069444445f);
        if (particle != 0) {
            particle[3] = 0x44;
        }
    }
}
/* localdecomp:end func_L07_003BDB38 */
