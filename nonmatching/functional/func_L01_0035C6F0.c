/* functional: high. VU0 vector sub/add written as plain float ops (same results, w forced as retail); retail passes the four consecutive vectors as one matrix, kept as m[4]. */
#include "vu0.h"
typedef struct {
    vu0_v4 vertices[4];
    u32 colors[4];
    f32 uv[8];
    u8 pad70[0x20];
} Draw_0035C6F0;
extern vu0_v4 D_L01_001E29C0;
void func_L01_0035C6F0(u8 *bullet) {
    extern f32 func_003824E0(f32 low, f32 high);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_003D93B0(void *, s32, s32, s32);
    extern void func_003D2DA0(void *, void *, s32);
    vu0_v4 m[4]; /* velocity, delta, side, start: one matrix */
    Draw_0035C6F0 draw;
    vu0_v4 offset;
    s32 i;
    u8 *vars = *(u8 **)(bullet + 0x68);
    f32 width = func_003824E0(0.45f, 0.7f);
    f32 length = func_003824E0(4.0f, 4.5f);
    func_0038CF68(&m[0], vars, 1.0f);
    m[1].x = D_L01_001E29C0.x - *(f32 *)(bullet + 0x10);
    m[1].y = D_L01_001E29C0.y - *(f32 *)(bullet + 0x14);
    m[1].z = D_L01_001E29C0.z - *(f32 *)(bullet + 0x18);
    func_0038CE90(&m[2], &m[1], &m[0]);
    func_0038CF68(&m[2], &m[2], width);
    func_0038CF68(&m[0], &m[0], length);
    m[0].w = 0.0f; m[1].w = 0.0f; m[2].w = 0.0f;
    func_003D93B0(&draw, 0x3F, 0, 0x80);
    draw.uv[0] = 0.0f; draw.uv[1] = 0.0f; draw.uv[2] = 0.0f; draw.uv[3] = 1.0f;
    draw.uv[4] = 1.0f; draw.uv[5] = 0.0f; draw.uv[6] = 1.0f; draw.uv[7] = 1.0f;
    for (i = 0; i < 4; i++) {
        qzero(&draw.vertices[i]);
        draw.vertices[i].x = i < 2 ? 0.0f : 1.0f;
        draw.vertices[i].y = 0.0f;
        draw.vertices[i].z = i & 1 ? 1.0f : -1.0f;
        draw.vertices[i].w = 1.0f;
        draw.colors[i] = 0x7FFFFFFF;
    }
    func_0038CF68(&offset, vars, -3.7f);
    m[3].x = offset.x + *(f32 *)(bullet + 0x10);
    m[3].y = offset.y + *(f32 *)(bullet + 0x14);
    m[3].z = offset.z + *(f32 *)(bullet + 0x18);
    m[3].w = 1.0f;
    func_003D2DA0(&draw, &m[0], 0);
}
