/* PAL near miss (Codex wave 6): near miss: 55 words differ with the file's flags.
 * Worker's note: 55 diff in build/codex/w323/448340-01.log; blocked by existing func_L01_00448148(f32*,f32) declaration: retail needs (f32*,f32,f32,f32,f32); retained declared two-argument call, missing gain/damping/cap forwarding; VU0 scheduling also differs; context ...
 */
#include "common.h"
/* localdecomp:start func_L01_00448340 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_00448340;
f32 func_L01_00448340(Vec_00448340 *position, Vec_00448340 *target, f32 *rate, f32 gain, f32 damping, f32 cap) {
    extern f32 func_0038CEA8(void *);
    extern void func_L01_00448148(f32 *, f32);
    extern void func_0038CF68(void *, void *, f32);
    Vec_00448340 delta;
    f32 distance, left;
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(delta) : "m"(*position), "m"(*target) : "vf1", "vf2");
    distance = func_0038CEA8(&delta);
    /* The owning file's callee declaration accepts only these two arguments.
       Retail additionally passes gain, damping and cap in f13-f15. */
    func_L01_00448148(rate, distance);
    func_0038CF68(&delta, &delta, *rate);
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
/* localdecomp:end func_L01_00448340 */
