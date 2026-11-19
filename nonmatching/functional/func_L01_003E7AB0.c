/* functional: high. Camera pull-away helper: moves *position toward target by gain, damps it against the follow base (state+0xB0), and writes the displacement from the origin to *out. Same vector math and calls as retail (gain/damping pass in f12/f13) */
#include "vu0.h"
void func_L01_003E7AB0(u8 *obj, vu0_v4 *out, vu0_v4 *position, vu0_v4 *target, vu0_v4 *origin, f32 gain, f32 damping) {
    extern void func_0038CF68(f32 *, f32 *, f32);
    vu0_v4 delta, scaled, follow_delta, sum, origin_copy;
    u8 *state = *(u8 **)(obj + 0x70);
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(delta) : "m"(*position), "m"(*target) : "vf1", "vf2");
    func_0038CF68((f32 *)&scaled, (f32 *)&delta, gain);
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*position) : "m"(*position), "m"(scaled) : "vf1", "vf2");
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(follow_delta) : "m"(*position), "m"(*(vu0_v4 *)(state + 0xB0)) : "vf1", "vf2");
    func_0038CF68((f32 *)&follow_delta, (f32 *)&follow_delta, damping);
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(sum) : "m"(follow_delta), "m"(*(vu0_v4 *)(state + 0xB0)) : "vf1", "vf2");
    __asm__("lqc2 $vf1, %1\n\tsqc2 $vf1, %0" : "=m"(origin_copy) : "m"(*origin) : "vf1");
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(*out) : "m"(sum), "m"(origin_copy) : "vf1", "vf2");
}
