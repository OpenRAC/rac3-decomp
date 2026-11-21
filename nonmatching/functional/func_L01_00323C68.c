/* functional: medium. 50 words differ from retail (VU sequence scheduling); same operations. */
#include "vu0.h"
typedef union { vu0_q q; f32 f[4]; } V_00323C68;
typedef struct {
    V_00323C68 vertices[4];
    u32 color[4];
    s32 x50, x54, x58;
    f32 x5C, x60;
    s32 x64;
    f32 x68, x6C;
    u8 tail[0x20];
} Render_00323C68;
extern s32 D_L01_001DC9E0;
__asm__(".extern D_L01_001DC9E0, 4");
extern s32 D_L01_001DCA00;
__asm__(".extern D_L01_001DCA00, 4");
extern vu0_v4 D_L01_001E29C0;
void func_L01_00323C68(u8 *object) {
    extern f32 func_003824E0(f32, f32);
    extern void func_0038CF68(f32 *, s32, f32);
    extern void func_0038CE90(f32 *, f32 *, f32 *);
    extern void func_0038D000(f32 *, f32 *, f32 *);
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_003D2DA0(void *, f32 *, s32);
    V_00323C68 basis[4];
    Render_00323C68 render;
    V_00323C68 offset;
    u8 *state = *(u8 **)(object + 0x68);
    f32 a, b;
    s32 i;
    if (D_L01_001DC9E0) {
        a = func_003824E0(0.75f, 0.95f);
        b = func_003824E0(2.0f, 2.5f);
    } else {
        a = func_003824E0(0.275f, 0.475f);
        b = func_003824E0(1.0f, 1.3f);
    }
    func_0038CF68(basis[0].f, (s32)(state + 0x40), -1.0f);
    __asm__("lqc2 $vf2, %1
	lqc2 $vf1, %2
	vsub.xyz $vf1, $vf1, $vf2
	sqc2 $vf1, %0"
        : "=m"(basis[1]) : "m"(*(vu0_v4 *)(object + 0x10)), "m"(D_L01_001E29C0) : "vf1", "vf2");
    func_0038CE90(basis[2].f, basis[1].f, basis[0].f);
    func_0038CF68(basis[2].f, (s32)&basis[2], a);
    func_0038CF68(basis[0].f, (s32)&basis[0], b);
    basis[0].f[3] = 0.0f;
    basis[1].f[3] = 0.0f;
    basis[2].f[3] = 0.0f;
    if (D_L01_001DC9E0) func_003D93B0(&render, 63, 1, 128);
    else func_003D93B0(&render, 62, 1, 128);
    render.x50 = 0;
    render.x5C = 1.0f;
    render.x60 = 1.0f;
    render.x68 = 1.0f;
    render.x6C = 1.0f;
    render.x54 = 0;
    render.x58 = 0;
    render.x64 = 0;
    for (i = 0; i < 4; i++) {
        qzero(&render.vertices[i]);
        render.vertices[i].f[0] = i < 2 ? 0.0f : 1.0f;
        render.vertices[i].f[1] = 0.0f;
        render.vertices[i].f[2] = (i & 1) ? 1.0f : -1.0f;
        render.vertices[i].f[3] = 1.0f;
        render.color[i] = 0x7FFFFFFF;
    }
    {
        f32 y = -1.0f;
        if (D_L01_001DC9E0) y = -2.0f;
        offset.q = 0;
        offset.f[1] = y;
    }
    func_0038D000(basis[3].f, offset.f, (f32 *)(object + 0xC0));
    if (D_L01_001DCA00) {
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %0\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "+m"(basis[3]) : "m"(*(vu0_v4 *)(state + 0x10)) : "vf1", "vf2");
    } else {
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %0\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "+m"(basis[3]) : "m"(*(vu0_v4 *)(state + 0x20)) : "vf1", "vf2");
    }
    basis[3].f[3] = 1.0f;
    func_003D2DA0(&render, basis[0].f, 0);
    func_003D2DA0(&render, basis[0].f, 0);
    func_003D2DA0(&render, basis[0].f, 0);
    func_003D2DA0(&render, basis[0].f, 0);
    func_003D2DA0(&render, basis[0].f, 0);
    func_003D2DA0(&render, basis[0].f, 0);
}
