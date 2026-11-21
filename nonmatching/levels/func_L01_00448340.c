/* PAL near miss (sonnet-w1): 23 words differ with the file's flags; float arg regs swapped (retail gain=$f20, damping=$f21, cap=$f22; ours cap=$f20, gain=$f21, damping=$f22) and the VU0 asm/mtc1 scheduling follows from it */
#include "common.h"
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_00448340;
extern f32 func_0040E468(void *);
extern void func_0040E620(void *, void *, f32);
extern void func_L01_00448148(f32 *, f32);
f32 func_L01_00448340(Vec_00448340 *position, Vec_00448340 *target, f32 *rate, f32 gain, f32 damping, f32 cap) {
    Vec_00448340 delta;
    f32 distance, left;
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(delta) : "m"(*position), "m"(*target) : "vf1", "vf2");
    distance = func_0040E468(&delta);
    ((void (*)(f32 *, f32, f32, f32, f32))func_L01_00448148)(rate, distance, gain, damping, cap);
    func_0040E620(&delta, &delta, *rate);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*position) : "m"(*position), "m"(delta) : "vf1", "vf2");
    left = distance - *rate;
    if (fabs_asm(left) < cap * 0.01f) {
        *(vu0_q *)position = *(vu0_q *)target;
        *rate = 0.0f;
        return *rate;
    }
    return left;
}
