/* functional: high. 152 diff but instruction multiset identical to retail except branch offsets and 3 nops, 10 jals identical; the long VU0 sequences are the draft's merged inline blocks (equivalent to retail's lqc2/vadd/vsub/sqc2 order, scheduling differs) */
#include "common.h"
typedef struct {
    S_38C110v position[4];
    u32 colour[4];
    f32 uv[4][2];
    u8 pad70[0x20];
} Quad_0038A0F8;
extern s32 D_L01_001DDEA0;
extern s32 D_L01_001DDEA4;
extern S_38C110v D_L01_001E29C0;
__asm__(".extern D_L01_001DDEA0, 4");
__asm__(".extern D_L01_001DDEA4, 4");

void func_L01_0038A0F8(u8 *moby) {
    extern void func_003D93B0(Quad_0038A0F8 *, s32, s32, s32);
    extern void func_003D2DA0(Quad_0038A0F8 *, s32, s32);
    extern void func_0038CE20(s128 *, s128 *, f32);
    extern void func_0038CE90(S_38C110v *, S_38C110v *, S_38C110v *);
    extern void func_0038CF68(S_38C110v *, S_38C110v *, f32);
    Quad_0038A0F8 quad;
    S_38C110v eye_delta, step, end, side, saved;
    u8 *vars = *(u8 **)(moby + 0x68);
    f32 intensity;
    s32 i;
    f32 *uv;
    u32 colour;
    if (moby == 0 || moby[0x20] == 0xFE || moby[0x20] == 0xFD || vars == 0) return;
    intensity = (f32)*(s32 *)(vars + 0x38) * *(f32 *)(vars + 0x3C);
    func_003D93B0(&quad, D_L01_001DDEA0, 0, 0x80);
    colour = ((s32)(intensity * 96.0f) << 24) | 0x804020;
    quad.colour[2] = quad.colour[3] = quad.colour[0] = quad.colour[1] = colour;
    quad.uv[0][0] = 0.0f;
    quad.uv[0][1] = 0.0f;
    quad.uv[1][0] = 0.0f;
    quad.uv[1][1] = 1.0f;
    quad.uv[2][0] = 1.0f;
    quad.uv[2][1] = 0.0f;
    quad.uv[3][0] = 1.0f;
    quad.uv[3][1] = 1.0f;
    for (i = 3, uv = &quad.uv[0][0]; i >= 0; i--, uv += 2) {
        *uv += *(f32 *)(vars + 0x30);
        if (*uv >= 7.0f) *uv -= 7.0f;
    }
    *(f32 *)(vars + 0x30) += 0.1f;
    if (*(f32 *)(vars + 0x30) >= 4.0f) *(f32 *)(vars + 0x30) -= 4.0f;
    __asm__(
        "lqc2 $vf1, %1\n\t"
        "lqc2 $vf2, %2\n\t"
        "vsub.xyz $vf1, $vf1, $vf2\n\t"
        "sqc2 $vf1, %0"
        : "=m"(eye_delta) : "m"(*(S_38C110v *)(moby + 0x10)), "m"(D_L01_001E29C0) : "vf1", "vf2");
    __asm__(
        "lqc2 $vf2, %2\n\t"
        "lqc2 $vf1, %1\n\t"
        "vsub.xyz $vf1, $vf1, $vf2\n\t"
        "sqc2 $vf1, %0"
        : "=m"(step) : "m"(*(S_38C110v *)(vars + 0x50)), "m"(*(S_38C110v *)(moby + 0x10)) : "vf1", "vf2");
    func_0038CE20((s128 *)&step, (s128 *)&step, 0.5f);
    __asm__(
        "lqc2 $vf2, %2\n\t"
        "lqc2 $vf1, %1\n\t"
        "vadd.xyz $vf1, $vf1, $vf2\n\t"
        "sqc2 $vf1, %0"
        : "=m"(end) : "m"(*(S_38C110v *)(moby + 0x10)), "m"(step) : "vf1", "vf2");
    func_0038CE90(&side, &eye_delta, &step);
    func_0038CF68(&side, &side, 1.4f);
    __asm__(
        "lqc2 $vf2, %3\n\t"
        "lqc2 $vf1, %2\n\t"
        "vadd.xyz $vf1, $vf1, $vf2\n\t"
        "lqc2 $vf2, %2\n\t"
        "sqc2 $vf1, %0\n\t"
        "lqc2 $vf1, %3\n\t"
        "vsub.xyz $vf2, $vf2, $vf1\n\t"
        "sqc2 $vf2, %1"
        : "=m"(quad.position[0]), "=m"(quad.position[1])
        : "m"(*(S_38C110v *)(moby + 0x10)), "m"(side) : "vf1", "vf2");
    func_0038CF68(&side, &side, 0.6f);
    __asm__(
        "lqc2 $vf2, %3\n\t"
        "lqc2 $vf1, %2\n\t"
        "vadd.xyz $vf1, $vf1, $vf2\n\t"
        "sqc2 $vf1, %0\n\t"
        "lqc2 $vf2, %3\n\t"
        "lqc2 $vf1, %2\n\t"
        "vsub.xyz $vf1, $vf1, $vf2\n\t"
        "sqc2 $vf1, %1"
        : "=m"(quad.position[2]), "=m"(quad.position[3]) : "m"(end), "m"(side) : "vf1", "vf2");
    func_003D2DA0(&quad, 0, 0);
    quad.colour[0] = quad.colour[2];
    quad.colour[1] = quad.colour[3];
    quad.colour[3] = 0x204080;
    quad.colour[2] = 0x204080;
    *(s128 *)&quad.position[0] = *(s128 *)&quad.position[2];
    *(s128 *)&quad.position[1] = *(s128 *)&quad.position[3];
    __asm__(
        "lqc2 $vf2, %2\n\t"
        "lqc2 $vf1, %0\n\t"
        "vadd.xyz $vf1, $vf1, $vf2\n\t"
        "sqc2 $vf1, %0\n\t"
        "lqc2 $vf1, %2\n\t"
        "lqc2 $vf2, %1\n\t"
        "vadd.xyz $vf2, $vf2, $vf1\n\t"
        "sqc2 $vf2, %1"
        : "+m"(quad.position[2]), "+m"(quad.position[3]) : "m"(step) : "vf1", "vf2");
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
    quad.colour[1] = colour;
    quad.colour[0] = colour;
    quad.colour[3] = 0xFF4000;
    quad.colour[2] = 0xFF4000;
    func_0038CF68(&side, &side, 0.6f);
    __asm__(
        "lqc2 $vf2, %7\n\t"
        "lqc2 $vf1, %6\n\t"
        "vadd.xyz $vf1, $vf1, $vf2\n\t"
        "lqc2 $vf2, %6\n\t"
        "sqc2 $vf1, %0\n\t"
        "lqc2 $vf1, %6\n\t"
        "sqc2 $vf1, %4\n\t"
        "lqc2 $vf1, %7\n\t"
        "vsub.xyz $vf2, $vf2, $vf1\n\t"
        "sqc2 $vf2, %1\n\t"
        "lqc2 $vf2, %4\n\t"
        "lqc2 $vf1, %8\n\t"
        "vadd.xyz $vf1, $vf2, $vf1\n\t"
        "sqc2 $vf1, %3\n\t"
        "lqc2 $vf2, %8\n\t"
        "lqc2 $vf1, %3\n\t"
        "vadd.xyz $vf1, $vf1, $vf2\n\t"
        "sqc2 $vf1, %3\n\t"
        "lqc2 $vf1, %7\n\t"
        "lqc2 $vf2, %3\n\t"
        "vadd.xyz $vf2, $vf2, $vf1\n\t"
        "sqc2 $vf2, %2\n\t"
        "lqc2 $vf1, %3\n\t"
        "lqc2 $vf2, %7\n\t"
        "vsub.xyz $vf1, $vf1, $vf2\n\t"
        "sqc2 $vf1, %5"
        : "=m"(quad.position[0]), "=m"(quad.position[1]), "=m"(quad.position[2]), "=m"(end), "=m"(saved), "=m"(quad.position[3])
        : "m"(*(S_38C110v *)(moby + 0x10)), "m"(side), "m"(step) : "vf1", "vf2");
    func_003D2DA0(&quad, 0, 0);
}
