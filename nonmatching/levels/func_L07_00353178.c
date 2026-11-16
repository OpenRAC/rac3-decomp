/* PAL near miss (Codex wave 6): near miss: 53 words differ with "-O2 -G8 -fopt-stack -mno-check-zero-division" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 * Worker's note: 32 diff: build/codex/w326/func_L07_00353178.03.log with injected divs 2,0,0 (still not MATCH); VU sequence grouping differs around FP compare and final store; existing vu0.h j helpers fail under fixed flags, see .02.log
 */
#include "common.h"
/* localdecomp:start func_L07_00353178 */
#include "vu0.h"
void func_L07_00353178(u8 *self, s32 sequence, s32 joint, s32 amount,
                       f32 time, f32 speed, f32 height, f32 start, f32 end, f32 peak) {
    extern void func_0038CF68(void *, void *, f32);
    extern f32 func_003C3D30(void *, s32, s32, f32);
    extern f32 func_003C3BE8(f32, f32, f32);
    extern void func_L01_0045AA30(void *, void *);
    vu0_v4 position, scaled, delta;
    f32 factor;
    f32 angle;
    if (self[0x42] != sequence) return;
    if (!(start <= time && time < end)) return;
    *(vu0_q *)&position = *(vu0_q *)(self + 0x10);
    func_0038CF68(&scaled, self + 0xC0 + joint * 16, (amount * speed) / (end - start));
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(position) : "m"(position), "m"(scaled) : "vf1", "vf2");
    if (time < 16.0f) factor = (time - start) / (peak - start);
    else factor = 1.0f - (time - peak) / (end - peak);
    angle = func_003C3D30(&position, 0, 0, 0.5f);
    position.z = func_003C3BE8(angle, angle + height, factor);
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
            : "=m"(delta) : "m"(position), "m"(*(vu0_v4 *)(self + 0x10)) : "vf1", "vf2");
    func_L01_0045AA30(self, &delta);
}
/* localdecomp:end func_L07_00353178 */
