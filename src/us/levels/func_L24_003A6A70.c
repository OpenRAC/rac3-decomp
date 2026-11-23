#include "common.h"

/* NTSC-U counterpart of func_L24_003A8668 (src/levels/24_insomniac_museum/L24_003A8668.c): 33 -> 40; 0.02 -> 0.0166667 */
/* localdecomp:start func_L24_003A6A70 */
#include "vu0.h"
typedef struct S_003A8668 {
    u8 pad0[0x20];
    f32 f20;
    u8 pad24[4];
    s32 f28;
    s32 f2C;
} S_003A8668;
extern S_003A8668 D_L24_001E2200_003A6A70;
extern void func_003BF6A8(void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern u8 *func_L01_00460318(void *, void *, u32, s32, s32, s32, s32, s32);
extern void func_L01_00443648(void *, void *, s32, s32, s32, s32, f32, f32, f32);

void func_L24_003A6A70(u8 *a0) {
    vu0_v4 pos;
    vu0_v4 vel;
    s32 i;
    f32 h;
    u8 r, g, b, a;
    s32 life, size, size2;
    u32 col;

    D_L24_001E2200_003A6A70.f20 = 0.075f;
    D_L24_001E2200_003A6A70.f28 = 0x28;
    D_L24_001E2200_003A6A70.f2C = 0;
    r = 10;
    for (i = 0; i < 90; i++) {
        qzero(&pos);
        func_003BF6A8(&pos, 1.5f);
        h = 1.5f - (fabs_asm(pos.x) + fabs_asm(pos.y)) * 0.5f;
        vec_add_ab(&pos, &pos, a0 + 0x10);
        vel.x = func_0037E250(-1.0f, 1.0f) * 0.0166666675f;
        vel.y = func_0037E250(-1.0f, 1.0f) * 0.0166666675f;
        vel.z = func_0037E250(4.0f, h * 6.5f + 5.0f) * 0.0166666675f;
        g = func_0037E1D8(200);
        b = 0xC8;
        if (func_0037E1D8(2) == 0) {
            b = 0xFF;
        }
        a = func_0037E1D8(0x80) + 0x64;
        col = (a << 24) | (r << 16) | (g << 8) | b;
        life = func_0037E1D8(10) + 30;
        size = func_0037E1D8(50) + 50;
        size2 = func_0037E1D8(50);
        func_L01_00460318(&pos, &vel, col, 0, life, size, size2 + 250, i & 1);
    }
    func_L01_00443648(a0, a0 + 0x10, 0x10000, 0, 1, 0, 2.0f, 10.0f, 1.0f);
}
/* localdecomp:end func_L24_003A6A70 */
