/* PAL near miss (Codex wave 8): near miss: 45 words differ with the file's flags.
 * Worker's note: 45 diff (003E7AB0-03.log): correct VU sequences with vf1/vf2 clobbers compile; opaque sequences prevent retail EE interleaving and leave 196 vs 204 bytes. Existing vu0.h j helpers cannot compile under fixed flags (003E7AB0-04.log). No alternate flags tested.
 */
#include "common.h"
/* localdecomp:start func_L01_003E7AB0 */
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
/* localdecomp:end func_L01_003E7AB0 */
