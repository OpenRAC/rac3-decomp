#include "common.h"

/* localdecomp:start func_L11_003E5058 */
#include "vu0.h"

typedef struct {
    vu0_v4 v[4]; u32 color[4]; f32 uv[4][2];
    u8 pad70[0x20];
} Draw_003E5058;
typedef struct {
    Draw_003E5058 draw;
    vu0_v4 basis[3]; vu0_v4 pos; vu0_v4 delta;
} Work_003E5058;
typedef struct {
    u8 pad0[0x80];
    vu0_v4 v80;
    u8 pad90[0x3D0];
} Cam_003E5058;

extern vu0_v4 D_L11_001E1700;
extern Cam_003E5058 D_L11_001E18D0[];
extern vu0_v4 D_L11_001D7AD0[];
extern s32 D_001D52F0;
__asm__(".extern D_001D52F0, 16");
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_003D2DA0(void *, s32, s32);
extern void func_00389478(void *, f32 *, f32 *);

/* from rac2-decomp's func_002820D0 */
void func_L11_003E5058(vu0_v4 *position, s32 alpha, s32 uvs, f32 size, f32 jitter, f32 offset) {
    Work_003E5058 w;
    s32 i;
    u32 color;

    *(vu0_q *)&w.pos = *(vu0_q *)position;
    vec_sub_ab(&w.basis[0], &D_L11_001E1700, &w.pos);
    func_0038CF68(&w.basis[0], &w.basis[0], 1.0f);
    {
        Cam_003E5058 *c = &D_L11_001E18D0[D_001D52F0];
        func_0038CE90(&w.basis[1], &w.basis[0], &c->v80);
    }
    func_0038CF68(&w.basis[1], &w.basis[1], 1.0f);
    func_0038CE90(&w.basis[2], &w.basis[1], &w.basis[0]);
    func_0038CE20(&w.delta, w.basis, offset);
    vec_add_ab(&w.pos, &w.pos, &w.delta);
    for (i = 0; i < 4; i++) {
        func_0038CE20(&w.draw.v[i], &D_L11_001D7AD0[i], size);
        func_0038D028(&w.draw.v[i], &w.draw.v[i], w.basis);
    }
    func_003D93B0(&w.draw, 0x3B, 5, 0x80);
    color = (alpha << 24) | 0x808080;
    w.draw.color[3] = color;
    w.draw.color[2] = color;
    w.draw.color[1] = color;
    w.draw.color[0] = color;
    w.draw.uv[0][0] = 0; w.draw.uv[0][1] = 0;
    w.draw.uv[1][0] = 0; w.draw.uv[1][1] = 1;
    w.draw.uv[2][0] = 1; w.draw.uv[2][1] = 0;
    w.draw.uv[3][0] = 1; w.draw.uv[3][1] = 1;
    func_003D2DA0(&w.draw, 0, 0);
    func_003D93B0(&w.draw, -1, 6, 0x80);
    func_0038CE20(&w.delta, w.basis, offset + 0.01f);
    if (uvs) {
        f32 **p = (f32 **)uvs;
        for (i = 0; i < 4; i++) {
            w.draw.uv[i][0] = p[i][0];
            w.draw.uv[i][1] = p[i][1];
            if (w.draw.uv[i][0] > 1.0f) w.draw.uv[i][0] = 1.0f;
            else if (w.draw.uv[i][0] < 0.0f) w.draw.uv[i][0] = 0.0f;
            if (w.draw.uv[i][1] > 1.0f) w.draw.uv[i][1] = 1.0f;
            else if (w.draw.uv[i][1] < 0.0f) w.draw.uv[i][1] = 0.0f;
        }
    } else {
        for (i = 0; i < 4; i++) {
            func_00389478(&w.draw.v[i], &w.draw.uv[i][0], &w.draw.uv[i][1]);
            if (i >> 1)
                w.draw.uv[i][0] -= jitter;
            else
                w.draw.uv[i][0] += jitter;
            {
                f32 value = w.draw.uv[i][1];
                w.draw.uv[i][1] = value = (i & 1) ? value - jitter : value + jitter;
            }
            if (w.draw.uv[i][0] > 1.0f) w.draw.uv[i][0] = 1.0f;
            else if (w.draw.uv[i][0] < 0.0f) w.draw.uv[i][0] = 0.0f;
            if (w.draw.uv[i][1] > 1.0f) w.draw.uv[i][1] = 1.0f;
            else if (w.draw.uv[i][1] < 0.0f) w.draw.uv[i][1] = 0.0f;
        }
    }
    func_003D2DA0(&w.draw, 0, 0);
}
/* localdecomp:end func_L11_003E5058 */

LINKER_REMNANT("asm/levels", func_L11_003E5438);
