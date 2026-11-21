/* functional: high. Read block by block against the PAL asm; differs only in VU0 scheduling and float constant allocation. */
#include "common.h"
#include "vu0.h"
extern int D_L01_0021F6C0[];
s32 func_L01_00477668(s32 index, Vec4 *start, Vec4 *end, Vec4 *out) {
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038D000(void *, void *, void *);
    extern void func_0038CDF8(void *, void *, void *, f32);
    Vec4 matrix[3], previous, next;
    s32 i = 1;
    s32 hit = 0;
    f32 one = 1.0f;
    f32 closest;
    f32 length;
    f32 cross;
    u8 *table;
    __asm__("lqc2 $vf2, %1
	lqc2 $vf1, %2
	vsub.xyz $vf1, $vf1, $vf2
	sqc2 $vf1, %0"
        : "=m"(matrix[0]) : "m"(*start), "m"(*end) : "vf1", "vf2");
    matrix[0].f[2] = 0;
    length = func_0038CEA8(&matrix[0]);
    closest = one;
    func_0038CF68(&matrix[0], &matrix[0], one / length);
    qzero(&matrix[1]);
    qzero(&matrix[2]);
    matrix[1].f[0] = matrix[0].f[1];
    matrix[1].f[1] = -matrix[0].f[0];
    matrix[2].f[2] = one;
    table = (u8 *)D_L01_0021F6C0[index];
    __asm__("lqc2 $vf2, %1
	lqc2 $vf1, %2
	vsub.xyz $vf1, $vf1, $vf2
	sqc2 $vf1, %0"
        : "=m"(previous) : "m"(*start), "m"(*(Vec4 *)(table + 16)) : "vf1", "vf2");
    func_0038D000(&previous, &previous, &matrix[0]);
    if (i < *(s32 *)(u8 *)D_L01_0021F6C0[index]) do {
        table = (u8 *)D_L01_0021F6C0[index];
    __asm__("lqc2 $vf2, %1
	lqc2 $vf1, %2
	vsub.xyz $vf1, $vf1, $vf2
	sqc2 $vf1, %0"
            : "=m"(next) : "m"(*start), "m"(*(Vec4 *)((i << 4) + (s32)table + 16)) : "vf1", "vf2");
        func_0038D000(&next, &next, &matrix[0]);
        if (previous.f[3] != 0.0f || next.f[3] != 0.0f) {
            if (next.f[1] * previous.f[1] < 0.0) {
                cross = (previous.f[0] - next.f[0]) / (previous.f[1] - next.f[1]) * -next.f[1] + next.f[0];
                if (cross > 0.0 && cross < closest) {
                    closest = cross;
                    hit = 1;
                }
            }
        }
        { s32 following = i + 1;
        previous = next;
        i = following; }
    } while (i < *(s32 *)(u8 *)D_L01_0021F6C0[index]);
    func_0038CDF8(out, start, end, closest);
    return hit;
}
