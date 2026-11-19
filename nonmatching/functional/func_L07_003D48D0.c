/* functional: high. PAL near-miss draft re-read against PAL asm (state tests, all five draw phases, colours, float constants and callees match); differs from retail only in scheduling and constant loading. */
#include "common.h"
typedef struct {
    f32 vertex[4][4];
    u32 color[4];
    f32 uv[4][2];
    unsigned long w70, texture, w80, w88;
} __attribute__((aligned(16))) Quad_003D48D0;
typedef struct { f32 m[4][4]; } __attribute__((aligned(16))) Matrix_003D48D0;
extern f32 D_L07_001DE7C8[];
extern f32 D_L07_001DE7CC[];
void func_L07_003D48D0(u8 *self) {
    extern void func_0038D2A0(void *);
    extern unsigned long func_00389598(s32);
    extern void func_L06_00359C38(void *, u32, u32, f32);
    extern void func_L06_00359B60(void *, void *, f32, f32);
    extern void func_003D2DA0(void *, void *, s32);
    extern void func_L06_00359CA8(void *, u32);
    Quad_003D48D0 q;
    Matrix_003D48D0 matrix;
    u8 *data;
    f32 t;
    s32 i;
    f32 *dx, *dy, *sx, *sy;
    if (!self || self[0x20] == 0xFE || self[0x20] == 0xFD) return;
    if (*(s16 *)(self + 0xAA) != 0x1C81) return;
    data = *(u8 **)(self + 0x68);
    if (self[0x20] < 3) return;
    if (self[0x20] == 3) t = 1.0f - (f32)*(s32 *)data / 60.0f;
    else t = 1.0f;
    func_0038D2A0(&matrix);
    q.texture = func_00389598(0x27);
    q.w70 = 0;
    q.w80 = 0xFF9000000260UL;
    q.w88 = 0x8000000044UL;
    dx = &q.uv[0][0];
    dy = &q.uv[0][1];
    sx = D_L07_001DE7C8;
    sy = D_L07_001DE7CC;
    for (i = 3; i >= 0; i--) {
        *dx = *sx;
        *dy = *sy;
        dx += 2; dy += 2; sx += 2; sy += 2;
    }
    switch (self[0x20]) {
    case 3:
        if (t >= 0.0f && t < .5f) {
            f32 phase = (t - 0.0f) * 2.0f;
            f32 remain, grow;
            func_L06_00359C38(&q, 0x20A0A0A0, 0x80A0A0A0, phase);
            remain = 1.0f - phase;
            grow = (remain * .8f) * .5f;
            func_L06_00359B60(data, &q, grow + .8f, *(f32 *)(self + 0xF0) + remain * .7853981853f);
            func_003D2DA0(&q, &matrix, 0);
            func_L06_00359B60(data, &q, .8f - grow, *(f32 *)(self + 0xF0) + remain * -.7853981853f);
            func_003D2DA0(&q, &matrix, 0);
        }
        if (t >= .5f && t < .9f) {
            f32 phase = (t - .5f) / .3999999762f;
            func_L06_00359C38(&q, 0x60A0A0A0, 0x00A0A0A0, phase);
            func_L06_00359B60(data, &q, (phase * .8f) * .05f + .8f, *(f32 *)(self + 0xF0));
            func_003D2DA0(&q, &matrix, 0);
        }
        if (t >= .5f && t < 1.0f) {
            f32 phase = (t - .5f) * 2.0f;
            f32 grow;
            func_L06_00359C38(&q, 0x80FFFFFF, 0x00808080, phase);
            grow = (phase * .8f) * .25f;
            func_L06_00359B60(data, &q, grow + .8f, *(f32 *)(self + 0xF0) + phase * .2617993951f);
            func_003D2DA0(&q, &matrix, 0);
            func_L06_00359B60(data, &q, .8f - grow, *(f32 *)(self + 0xF0) + phase * -.2617993951f);
            func_003D2DA0(&q, &matrix, 0);
        }
        if (t >= .5f && t < .7f) {
            func_L06_00359C38(&q, 0x10808080, 0x800000FF, (t - .5f) / .1999999881f);
            func_L06_00359B60(data, &q, .8f, *(f32 *)(self + 0xF0));
            func_003D2DA0(&q, &matrix, 0);
        }
        if (t < .7f) break;
    case 4:
    case 5:
        func_L06_00359CA8(&q, 0x800000FF);
        func_L06_00359B60(data, &q, .8f, *(f32 *)(self + 0xF0));
        func_003D2DA0(&q, &matrix, 0);
        break;
    }
}
