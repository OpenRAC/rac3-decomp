#include "common.h"

/* localdecomp:start func_L40_003D6FD8 */
#include "vu0.h"

typedef struct {
    f32 vertices[4][4];
    u32 colors[4];
    f32 uv[4][2];
    unsigned long registers[4];
} __attribute__((aligned(16))) Quad_003D6FD8;

typedef union {
    vu0_q bits;
    f32 f[4];
} __attribute__((aligned(16))) QV_003D6FD8;

typedef f32 Vec_003D6FD8[4] __attribute__((aligned(16)));

typedef struct {
    u8 pad0[0x23A0];
    Vec_003D6FD8 pos;
} Cam_003D6FD8;

typedef struct {
    u8 pad0[0x24];
    Cam_003D6FD8 *cam;
} Vars_003D6FD8;

typedef struct {
    u8 pad0[0x68];
    Vars_003D6FD8 *vars;
} Moby_003D6FD8;

extern unsigned long func_L39_00589890(int index);
extern void func_L01_002FDBD8(f32 (*)[4], s32);
extern void func_L01_002FD988(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_003D2DA0(void *, void *, s32);

/* from rac2-decomp's func_0032BE30 */
void func_L40_003D6FD8(Moby_003D6FD8 *m, u32 opacity, f32 points[][4], s32 count) {
    Quad_003D6FD8 outer;
    Quad_003D6FD8 inner;
    Vec_003D6FD8 frame[4];
    QV_003D6FD8 outerWidth;
    QV_003D6FD8 innerWidth;
    Cam_003D6FD8 *cam;
    s32 index;
    u32 innerColor;

    if (m == 0 || m->vars == 0) {
        return;
    }
    cam = m->vars->cam;
    innerColor = 0x8000FF00;
    outer.registers[1] = func_L39_00589890(0x2B);
    outer.registers[3] = ((long)opacity << 32) | 0x68;
    outer.registers[2] = 0xFF9000000260UL;
    outer.registers[0] = 0;
    outer.colors[1] = 0x7FFFFFFF;
    outer.colors[0] = 0x7FFFFFFF;
    inner.registers[1] = func_L39_00589890(0x2B);
    inner.registers[2] = 0xFF9000000260UL;
    inner.registers[0] = 0;
    inner.registers[3] = ((long)((s32)opacity / 3) << 32) | 0x68;
    outerWidth.bits = 0;
    innerWidth.bits = 0;
    outer.colors[1] = innerColor;
    inner.colors[0] = innerColor;
    outerWidth.f[2] = 0.05f;
    outerWidth.f[3] = 1.0f;
    innerWidth.f[2] = 0.2f;
    innerWidth.f[3] = 1.0f;
    func_L01_002FDBD8(points, count);
    func_L01_002FD988(&outer);
    func_L01_002FD988(&inner);
    outer.uv[0][0] = 0.0f; outer.uv[0][1] = 0.0f;
    outer.uv[1][0] = 0.0f; outer.uv[1][1] = 1.0f;
    outer.uv[2][0] = 1.0f; outer.uv[2][1] = 0.0f;
    outer.uv[3][0] = 1.0f; outer.uv[3][1] = 1.0f;
    inner.uv[0][0] = 0.0f; inner.uv[0][1] = 0.0f;
    inner.uv[1][0] = 0.0f; inner.uv[1][1] = 1.0f;
    inner.uv[2][0] = 0.33f; inner.uv[2][1] = 0.0f;
    inner.uv[3][0] = 0.33f; inner.uv[3][1] = 1.0f;
    vec_sub_ab(frame[0], points[1], points[0]);
    func_0038CF68(frame[0], frame[0], 1.0f);
    vec_sub_ab(frame[1], cam->pos, points[0]);
    func_0038CE90(frame[2], frame[1], frame[0]);
    func_0038CF68(frame[2], frame[2], 1.0f);
    func_0038CE90(frame[1], frame[0], frame[2]);
    *(vu0_q *)frame[3] = *(vu0_q *)points[0];
    *(vu0_q *)outer.vertices[0] = outerWidth.bits;
    func_0038CE20(outer.vertices[1], outer.vertices[0], -1.0f);
    func_0038D028(outer.vertices[0], outer.vertices[0], frame);
    func_0038D028(outer.vertices[1], outer.vertices[1], frame);
    *(vu0_q *)inner.vertices[0] = innerWidth.bits;
    func_0038CE20(inner.vertices[1], inner.vertices[0], -1.0f);
    func_0038D028(inner.vertices[0], inner.vertices[0], frame);
    func_0038D028(inner.vertices[1], inner.vertices[1], frame);
    for (index = 1; index < count - 1; index++) {
        *(vu0_q *)outer.vertices[2] = outerWidth.bits;
        func_0038CE20(outer.vertices[3], outer.vertices[2], -1.0f);
        *(vu0_q *)inner.vertices[2] = innerWidth.bits;
        func_0038CE20(inner.vertices[3], inner.vertices[2], -1.0f);
        vec_sub_ab(frame[0], points[index + 1], points[index]);
        func_0038CF68(frame[0], frame[0], 1.0f);
        vec_sub_ab(frame[1], cam->pos, points[index]);
        func_0038CE90(frame[2], frame[1], frame[0]);
        func_0038CF68(frame[2], frame[2], 1.0f);
        func_0038CE90(frame[1], frame[0], frame[2]);
        *(vu0_q *)frame[3] = *(vu0_q *)points[index];
        func_0038D028(outer.vertices[2], outer.vertices[2], frame);
        func_0038D028(outer.vertices[3], outer.vertices[3], frame);
        func_0038D028(inner.vertices[2], inner.vertices[2], frame);
        func_0038D028(inner.vertices[3], inner.vertices[3], frame);
        outer.colors[2] = outer.colors[3] = 0x7F7F7F7F;
        inner.colors[2] = inner.colors[3] = innerColor;
        func_003D2DA0(&outer, 0, 0);
        func_003D2DA0(&inner, 0, 0);
        {
            f32 startU = index * 0.33f;
            f32 endU = startU + 0.33f;
            if (startU >= 1.0f) {
                startU -= 1.0f;
                endU -= 1.0f;
            }
            inner.uv[0][0] = startU;
            inner.uv[2][0] = endU;
            inner.uv[1][0] = startU;
            inner.uv[3][0] = endU;
        }
        *(vu0_q *)outer.vertices[0] = *(vu0_q *)outer.vertices[2];
        *(vu0_q *)outer.vertices[1] = *(vu0_q *)outer.vertices[3];
        *(vu0_q *)inner.vertices[0] = *(vu0_q *)inner.vertices[2];
        *(vu0_q *)inner.vertices[1] = *(vu0_q *)inner.vertices[3];
    }
}
/* localdecomp:end func_L40_003D6FD8 */
