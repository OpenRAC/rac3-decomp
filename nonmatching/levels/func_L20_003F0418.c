/* PAL near miss (Codex wave 8): near miss: 245 words differ with the file's flags.
 * Worker's note: 247 raw positional diff: sixth-best.log; full quad/UV behavior reconstructed; fixed flags require monolithic VU sequences, retail interleaves GPR setup; dli expansion and allocation/scheduling remain; contract compiles sixth-contract.log
 */
#include "common.h"
/* localdecomp:start func_L20_003F0418 */
#include "vu0.h"
typedef struct {
    vu0_q vertex[4];
    u32 colour[4];
    f32 uv[8];
    long flags, texture, primitive, blend;
} Draw_003F0418;
typedef struct {
    vu0_q pos;
    u8 pad[0x1D0-0x10];
    vu0_q up;
    u8 tail[0x460-0x1E0];
} Hero_003F0418;
extern s32 D_001D52F0[] __attribute__((section(".sdata")));
extern Hero_003F0418 D_L20_001E2E80[] __attribute__((section(".sdata")));
extern vu0_q D_L20_001D7C50[];
void func_L20_003F0418(vu0_q *position, s32 texture, s32 mode,
                        f32 scale, f32 offset, f32 angle, f32 unused, f32 jitter) {
    extern void func_003D93B0(Draw_003F0418 *, s32, s32, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038D308(void *, void *);
    extern void func_0038D5F0(void *, void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038D028(void *, void *, void *);
    extern void func_003A9440(s32, long);
    extern void func_003D2DA0(Draw_003F0418 *, s32, s32);
    extern void func_00389478(void *, f32 *, f32 *);
    extern s32 func_00382468(s32);
    extern f32 func_003824E0(f32, f32);
    Draw_003F0418 draw;
    vu0_v4 matrix[4];
    vu0_v4 temp;
    vu0_v4 scratch[3];
    s32 i;
    vu0_q *src, *dst;
    f32 *u, *v;
    func_003D93B0(&draw, texture, 1, 0x80);
    *(vu0_q *)&matrix[3] = *position;
    draw.blend = 0x800000004AL;
    draw.colour[1] = draw.colour[2] = draw.colour[3] = draw.colour[0] = 0x80808080;
    draw.uv[0] = 0; draw.uv[1] = 0; draw.uv[2] = 0; draw.uv[3] = 1;
    draw.uv[4] = 1; draw.uv[5] = 0; draw.uv[6] = 1; draw.uv[7] = 1;
    __asm__("lqc2 vf2, %2\n\tlqc2 vf1, %1\n\tvsub.xyz vf1, vf1, vf2\n\tsqc2 vf1, %0" : "=m"(matrix[0]) : "m"(D_L20_001E2E80[D_001D52F0[0]].pos), "m"(matrix[3]) : "vf1", "vf2");
    func_0038CF68(&matrix[0], &matrix[0], 1.0f);
    func_0038CE90(&matrix[1], &matrix[0], &D_L20_001E2E80[D_001D52F0[0]].up);
    func_0038CF68(&matrix[1], &matrix[1], 1.0f);
    func_0038CE90(&matrix[2], &matrix[1], &matrix[0]);
    if (angle != 0.0f) {
        *(vu0_q *)&temp = 0;
        temp.x = angle;
        func_0038D308(scratch, &temp);
        func_0038D5F0(matrix, matrix, scratch);
    }
    func_0038CE20(&temp, matrix, offset);
    __asm__("lqc2 vf1, %1\n\tlqc2 vf2, %2\n\tvadd.xyz vf1, vf1, vf2\n\tsqc2 vf1, %0" : "=m"(matrix[3]) : "m"(matrix[3]), "m"(temp) : "vf1", "vf2");
    src = D_L20_001D7C50;
    dst = draw.vertex;
    for (i=3; i>=0; i--) {
        func_0038CE20(dst, src++, scale);
        func_0038D028(dst, dst, matrix);
        dst++;
    }
    func_003A9440(0x47, 0x31001);
    func_003D2DA0(&draw, 0, 0);
    if (mode) {
        *(vu0_q *)&scratch[0] = draw.vertex[0];
        src = &draw.vertex[1];
        for (i=2; i>=0; i--) {
            __asm__("lqc2 vf2, %2\n\tlqc2 vf1, %1\n\tvadd.xyz vf1, vf1, vf2\n\tsqc2 vf1, %0" : "=m"(scratch[0]) : "m"(scratch[0]), "m"(*src) : "vf1", "vf2");
            src++;
        }
        func_0038CE20(scratch, scratch, 0.25f);
        dst = draw.vertex;
        u = &draw.uv[0]; v = &draw.uv[1];
        for (i=3; i>=0; i--) {
            __asm__("lqc2 vf2, %2\n\tlqc2 vf1, %1\n\tvsub.xyz vf1, vf1, vf2\n\tsqc2 vf1, %0" : "=m"(scratch[1]) : "m"(*dst), "m"(scratch[0]) : "vf1", "vf2");
            func_0038CE20(&scratch[1], &scratch[1], 0.8f);
            __asm__("lqc2 vf2, %1\n\tlqc2 vf1, %2\n\tvadd.xyz vf2, vf2, vf1\n\tsqc2 vf2, %0" : "=m"(scratch[1]) : "m"(scratch[0]), "m"(scratch[1]) : "vf1", "vf2");
            func_00389478(&scratch[1], u, v);
            if (0.0f < jitter && func_00382468(1) == 0) {
                *u += func_003824E0(-jitter, jitter);
                *v += func_003824E0(-jitter, jitter);
            }
            if (*u > 1.0f) *u = 1.0f;
            else if (*u < 0.0f) *u = 0.0f;
            if (*v > 1.0f) *v = 1.0f;
            else if (*v < 0.0f) *v = 0.0f;
            u += 2; v += 2; dst++;
        }
    } else {
        dst = draw.vertex;
        u = &draw.uv[0]; v = &draw.uv[1];
        for (i=3; i>=0; i--) {
            func_00389478(dst, u, v);
            if (func_00382468(1) == 0) {
                *u += func_003824E0(-jitter, jitter);
                *v += func_003824E0(-jitter, jitter);
            }
            if (*u > 1.0f) *u = 1.0f;
            else if (*u < 0.0f) *u = 0.0f;
            if (*v > 1.0f) *v = 1.0f;
            else if (*v < 0.0f) *v = 0.0f;
            u += 2; v += 2; dst++;
        }
    }
    func_003D93B0(&draw, -1, 1, 0x80);
    draw.blend = 0x8000000054L;
    func_003A9440(0x47, 0x53001);
    func_003D2DA0(&draw, 0, 0);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L20_003F0418 */
