/* PAL near miss (haiku-w1): 32 words differ with the file's flags; the prologue save order and the entry-test load placement differ, and the last VU0 copy of the position is a GPR lq/sq where retail uses lqc2/sqc2 (vec_copy there gave more differences). */
#include "common.h"
#include "vu0.h"

typedef struct {
    vu0_v4 position[4];
    u32 colour[4];
    f32 uv[4][2];
    u8 pad70[0x20];
} Quad_0038A0F8;
extern s32 D_L01_001DDEA0;
extern s32 D_L01_001DDEA4;
extern vu0_v4 D_L01_001E29C0;
__asm__(".extern D_L01_001DDEA0, 4");
__asm__(".extern D_L01_001DDEA4, 4");

void func_L01_0038A0F8(u8 *moby) {
    extern void func_003D93B0(Quad_0038A0F8 *, s32, s32, s32);
    extern void func_003D2DA0(Quad_0038A0F8 *, s32, s32);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    Quad_0038A0F8 quad;
    vu0_v4 eye, step, end, side, saved;
    u8 *vars;
    f32 intensity, *uv;
    s32 i;
    u32 colour;

    if (moby == 0) return;
    vars = *(u8 **)(moby + 0x68);
    if (moby[0x20] == 0xFE) return;
    if (moby[0x20] == 0xFD) return;
    if (vars == 0) return;
    intensity = (f32)*(s32 *)(vars + 0x38) * *(f32 *)(vars + 0x3C);
    func_003D93B0(&quad, D_L01_001DDEA0, 0, 0x80);
    colour = ((s32)(intensity * 96.0f) << 24) | 0x804020;
    quad.colour[1] = colour;
    quad.colour[2] = colour;
    quad.colour[3] = colour;
    quad.colour[0] = colour;
    quad.uv[0][0] = 0.0f;
    quad.uv[0][1] = 0.0f;
    quad.uv[1][0] = 0.0f;
    quad.uv[1][1] = 1.0f;
    quad.uv[2][0] = 1.0f;
    quad.uv[2][1] = 0.0f;
    quad.uv[3][0] = 1.0f;
    quad.uv[3][1] = 1.0f;
    uv = &quad.uv[0][0];
    for (i = 3; i >= 0; i--, uv += 2) {
        *uv += *(f32 *)(vars + 0x30);
        if (*uv >= 7.0f) *uv -= 7.0f;
    }
    *(f32 *)(vars + 0x30) += 0.1f;
    if (*(f32 *)(vars + 0x30) >= 4.0f) *(f32 *)(vars + 0x30) -= 4.0f;
    vec_sub_ab(&eye, moby + 0x10, &D_L01_001E29C0);
    vec_sub_ab(&step, vars + 0x50, moby + 0x10);
    func_0038CE20(&step, &step, 0.5f);
    vec_add_ba(&end, moby + 0x10, &step);
    func_0038CE90(&side, &eye, &step);
    func_0038CF68(&side, &side, 1.4f);
    vec_add_ba(&quad.position[0], moby + 0x10, &side);
    vec_sub_ab(&quad.position[1], moby + 0x10, &side);
    func_0038CF68(&side, &side, 0.6f);
    vec_add_ab(&quad.position[2], &end, &side);
    vec_sub_ab(&quad.position[3], &end, &side);
    func_003D2DA0(&quad, 0, 0);
    quad.colour[0] = quad.colour[2];
    quad.colour[1] = quad.colour[3];
    quad.colour[3] = 0x204080;
    quad.colour[2] = 0x204080;
    *(vu0_q *)&quad.position[0] = *(vu0_q *)&quad.position[2];
    *(vu0_q *)&quad.position[1] = *(vu0_q *)&quad.position[3];
    vec_add_ba(&quad.position[2], &quad.position[2], &step);
    vec_add_ba(&quad.position[3], &quad.position[3], &step);
    func_003D2DA0(&quad, 0, 0);
    func_003D93B0(&quad, D_L01_001DDEA4, 1, 0x80);
    colour = ((s32)(intensity * 96.0f) << 24) | 0xFF4000;
    quad.uv[0][0] = 0.0f;
    quad.uv[0][1] = 0.0f;
    quad.uv[1][0] = 0.0f;
    quad.uv[1][1] = 1.0f;
    quad.uv[2][0] = 1.0f;
    quad.uv[2][1] = 0.0f;
    quad.uv[3][0] = 1.0f;
    quad.uv[3][1] = 1.0f;
    quad.colour[0] = quad.colour[1] = colour;
    quad.colour[2] = quad.colour[3] = 0xFF4000;
    func_0038CF68(&side, &side, 0.6f);
    vec_add_ba(&quad.position[0], moby + 0x10, &side);
    vec_sub_ab(&quad.position[1], moby + 0x10, &side);
    saved = *(vu0_v4 *)(moby + 0x10);
    vec_add_ba(&end, &step, &saved);
    vec_add_ba(&end, &end, &step);
    vec_add_ba(&quad.position[2], &end, &side);
    vec_sub_ab(&quad.position[3], &end, &side);
    func_003D2DA0(&quad, 0, 0);
}
