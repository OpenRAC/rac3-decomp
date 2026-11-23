/* PAL near miss (sonnet-b3): 202 diff words with the file's flags (-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as); same size as retail, remaining: pvar in $s4 not $s3, left/right float regs ($f22/$f23) swapped, inner j+1 hoisting (addiu before the call, move copy) not reproduced */
#include "common.h"

/* localdecomp:start func_L07_00310558 */
#include "structs/moby.h"

typedef struct {
    f32 offsets[28];
    f32 speed;
    s32 fade_timer;
    f32 age;
} Wave_00310558;

typedef struct {
    Vec4f vertex[4];
    u32 color[4];
    f32 uv[4][2];
    unsigned long regs[4];
} __attribute__((aligned(16))) WaveQuad_00310558;

typedef int WaveVector_00310558 __attribute__((mode(TI)));

extern s32 D_L07_001DEF40[] __attribute__((section(".sdata")));
extern f32 func_L01_0040F518(f32, f32);
extern void func_0038D328(Vec4f *, Vec4f *);
extern unsigned long func_00389598(s32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_00382760(Vec4f *, f32, f32, f32);
extern void func_003D2DA0(WaveQuad_00310558 *, Vec4f *, s32);

void func_L07_00310558(struct Moby *moby)
{
    WaveQuad_00310558 q;
    Vec4f matrix[4] __attribute__((aligned(16)));
    Vec4f rotation __attribute__((aligned(16)));
    Wave_00310558 *state;
    s32 i, j, n;
    u32 tint;
    f32 phase, radius;

    if (moby == 0) return;
    if ((u8)moby->state == 0xFE) return;
    if ((u8)moby->state == 0xFD) return;
    if (moby->oclass != 0xABE) {
        return;
    }
    state = moby->pvar;
    tint = 0xA06060;
    radius = state->speed * state->age;
    phase = func_L01_0040F518((f32)D_L07_001DEF40[0], 25.333334f) / 25.333334f;
    *(WaveVector_00310558 *)&rotation = *(WaveVector_00310558 *)&moby->rotation;
    rotation.x = 0.0f;
    func_0038D328(matrix, &rotation);
    *(WaveVector_00310558 *)&matrix[3] = *(WaveVector_00310558 *)&moby->position;
    q.regs[1] = func_00389598(0x15);
    q.regs[2] = 0xFF9000000260UL;
    q.regs[3] = 0x8000000048UL;
    q.regs[0] = 0;

    for (i = 0; i < 5; i = n) {
        f32 near_elevation = (f32)i * 0.06981317f / 5.0f - 0.034906585f;
        f32 far_elevation;
        n = i + 1;
        far_elevation = (f32)n * 0.06981317f / 5.0f - 0.034906585f;
        for (j = 0; j < 10; j++) {
            f32 opacity;
            u32 a, b;
            f32 left = func_0038DB48((f32)j * 1.3962634f / 10.0f) - 0.6981317f;
            f32 right = func_0038DB48((f32)(j + 1) * 1.3962634f / 10.0f) - 0.6981317f;

            q.uv[0][0] = phase + (func_0038D098(left) + 1.0f) * 0.5f;
            q.uv[1][0] = phase + (func_0038D098(right) + 1.0f) * 0.5f;
            q.uv[2][0] = phase + (func_0038D098(left) + 1.0f) * 0.5f;
            q.uv[3][0] = phase + (func_0038D098(right) + 1.0f) * 0.5f;
            q.uv[0][1] = (func_0038D0B0(near_elevation) + 1.0f) * 0.5f;
            q.uv[1][1] = (func_0038D0B0(near_elevation) + 1.0f) * 0.5f;
            q.uv[2][1] = (func_0038D0B0(far_elevation) + 1.0f) * 0.5f;
            q.uv[3][1] = (func_0038D0B0(far_elevation) + 1.0f) * 0.5f;

            if (state->fade_timer != 0) {
                opacity = (f32)state->fade_timer / 15.0f * 64.0f;
            } else {
                opacity = 64.0f;
            }
            a = (u32)(s32)(opacity * func_0038D0B0((f32)i * 3.1415927f / 5.0f));
            b = (u32)(s32)(opacity * func_0038D0B0((f32)(i + 1) * 3.1415927f / 5.0f));
            q.color[0] = j == 0 ? tint : (a << 24) | tint;
            q.color[1] = j == 9 ? tint : (a << 24) | tint;
            q.color[2] = j == 0 ? tint : (b << 24) | tint;
            q.color[3] = j == 9 ? tint : (b << 24) | tint;

            func_00382760(&q.vertex[0], radius, left, near_elevation);
            func_00382760(&q.vertex[1], radius, right, near_elevation);
            func_00382760(&q.vertex[2], radius, left, far_elevation);
            func_00382760(&q.vertex[3], radius, right, far_elevation);
            q.vertex[0].w = 1.0f;
            q.vertex[1].w = 1.0f;
            q.vertex[2].w = 1.0f;
            q.vertex[3].w = 1.0f;
            func_003D2DA0(&q, matrix, 0);
        }
    }

    q.regs[1] = func_00389598(0xE);
    for (i = 0; i < 3; i = n) {
        f32 last_angle = 0.0f;
        f32 last_elevation = 0.0f;
        n = i + 1;
        for (j = 0; j < 28; j++) {
            f32 left = func_0038DB48((f32)j * 1.3962634f / 28.0f) - 0.6981317f;
            f32 right = func_0038DB48((f32)(j + 1) * 1.3962634f / 28.0f) - 0.6981317f;
            f32 angle = func_003824E0(left, right);
            f32 blend, elevation;
            u32 color;

            if (j == 0) {
                last_angle = left;
            }
            if (j == 27) {
                angle = right;
            }
            q.uv[0][0] = q.uv[2][0] = (f32)j / 28.0f;
            q.uv[1][0] = q.uv[3][0] = (f32)(j + 1) / 28.0f;
            q.uv[0][1] = q.uv[1][1] = 0.0f;
            q.uv[2][1] = q.uv[3][1] = 1.0f;
            blend = q.uv[0][1];
            if (state->fade_timer != 0) {
                blend = 1.0f - (f32)state->fade_timer / 15.0f;
            }
            if (blend < 0.0f) {
                blend = 0.0f;
            }
            color = func_0038DBD8(0x7FC04070, 0x00FF0000, blend);
            q.color[1] = q.color[2] = q.color[3] = q.color[0] = color;
            elevation = state->offsets[j] * 0.017453292f * func_003824E0(-1.0f, 1.0f) * state->age * 3.0f;
            if (elevation > 0.027925268f) {
                elevation = 0.027925268f;
            }
            if (elevation < -0.027925268f) {
                elevation = -0.027925268f;
            }
            if (j == 0) {
                last_elevation = 0.0f;
            }
            func_00382760(&q.vertex[0], radius, last_angle, last_elevation);
            func_00382760(&q.vertex[1], radius, angle, elevation);
            func_00382760(&q.vertex[2], radius, last_angle, last_elevation);
            last_elevation = elevation;
            func_00382760(&q.vertex[3], radius, angle, elevation);
            last_angle = angle;
            q.vertex[2].z -= 0.15f;
            q.vertex[3].z -= 0.15f;
            q.vertex[0].w = 1.0f;
            q.vertex[1].w = 1.0f;
            q.vertex[2].w = 1.0f;
            q.vertex[3].w = 1.0f;
            func_003D2DA0(&q, matrix, 0);
        }
    }
}
/* localdecomp:end func_L07_00310558 */
