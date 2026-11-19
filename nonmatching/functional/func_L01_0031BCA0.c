/* functional: medium. Near-miss draft from the PAL assembly (Codex waves), re-checked at level 01: compiles in the file context with relocations resolved (callees/globals as retail); 71 words differ only in VU0 scheduling and quad UV loop allocation; not byte-identical, behaviour as retail. */
#include "vu0.h"
typedef struct {
    vu0_v4 vertices[4];
    u32 colours[4];
    f32 uv[4][2];
    unsigned long zero;
    unsigned long texture;
    unsigned long clamp;
    unsigned long primitive;
} Quad_0031BCA0;
extern vu0_v4 D_L01_001E29C0;
extern s32 D_L01_001DC828;
extern u32 D_L01_001DC830;
extern f32 D_L01_001DC838[];
extern f32 D_L01_001DC83C[];
__asm__(".extern D_L01_001DC828, 4");
__asm__(".extern D_L01_001DC830, 4");
void func_L01_0031BCA0(u8 *moby, u128_t *position) {
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern f32 func_L01_00443A18(f32, f32);
    extern unsigned long func_00389598(s32);
    extern void func_003D2DA0(void *, s32, s32);
    vu0_v4 input;
    Quad_0031BCA0 quad;
    vu0_v4 left, right, direction, p, q;
    vu0_v4 tmp, sum;
    vu0_v4 camera1, camera2, camera3;
    u8 *vars;
    s32 i;
    *(u128_t *)&input = *position;
    vars = *(u8 **)(moby + 0x68);
    p = *(vu0_v4 *)(vars + 0x10);
    func_0038CF68(&q, vars + 0x20, -8.0f);
    vec_add_ba(&q, &q, &p);
    vec_copy(&camera1, &D_L01_001E29C0);
    vec_copy(&camera2, &D_L01_001E29C0);
    vec_sub_ba(&direction, &q, &p);
    vec_sub_ba(&left, &q, &camera1);
    vec_sub_ab(&right, &p, &camera2);
    func_0038CE90(&left, &left, &direction);
    func_0038CF68(&left, &left, func_L01_00443A18(0.1f, 0.2f) + 0.5f);
    func_0038CE90(&right, &right, &direction);
    func_0038CF68(&right, &right, func_L01_00443A18(0.1f, 0.2f) + 0.5f);
    quad.texture = func_00389598(62);
    quad.clamp = 0xFF9000000260;
    quad.primitive = ((unsigned long)D_L01_001DC828 << 32) | 0x48;
    quad.zero = 0;
    quad.colours[0] = quad.colours[1] = quad.colours[2] = quad.colours[3] = D_L01_001DC830;
    for (i = 0; i < 4; i++) {
        quad.uv[i][0] = D_L01_001DC838[i*2];
        quad.uv[i][1] = D_L01_001DC83C[i*2];
    }
    vec_sub_ba(&sum, &q, &left);
    tmp = sum;
    quad.vertices[0] = tmp;
    vec_add_ba(&sum, &q, &left);
    tmp = sum;
    quad.vertices[1] = tmp;
    vec_sub_ba(&sum, &p, &right);
    tmp = sum;
    quad.vertices[2] = tmp;
    vec_add_ba(&sum, &p, &right);
    tmp = sum;
    quad.vertices[3] = tmp;
    func_003D2DA0(&quad, 0, 0);
    vec_sub_ba(&direction, &q, &p);
    vec_copy(&camera3, &D_L01_001E29C0);
    vec_sub_ba(&left, &q, &D_L01_001E29C0);
    vec_sub_ab(&right, &p, &camera3);
    func_0038CE90(&left, &left, &direction);
    func_0038CF68(&left, &left, func_L01_00443A18(0.05f, 0.15f) + 0.25f);
    func_0038CE90(&right, &right, &direction);
    func_0038CF68(&right, &right, func_L01_00443A18(0.05f, 0.15f) + 0.25f);
    quad.texture = func_00389598(63);
    quad.clamp = 0xFF9000000260;
    quad.primitive = ((unsigned long)D_L01_001DC828 << 32) | 0x48;
    quad.zero = 0;
    quad.colours[0] = quad.colours[1] = quad.colours[2] = quad.colours[3] = 0x60DDDDDD;
    for (i = 0; i < 4; i++) {
        quad.uv[i][0] = D_L01_001DC838[i*2];
        quad.uv[i][1] = D_L01_001DC83C[i*2];
    }
    vec_sub_ba(&sum, &q, &left);
    tmp = sum;
    quad.vertices[0] = tmp;
    vec_add_ba(&sum, &q, &left);
    tmp = sum;
    quad.vertices[1] = tmp;
    vec_sub_ba(&sum, &p, &right);
    tmp = sum;
    quad.vertices[2] = tmp;
    vec_add_ab(&sum, &p, &right);
    tmp = sum;
    quad.vertices[3] = tmp;
    func_003D2DA0(&quad, 0, 0);
}
