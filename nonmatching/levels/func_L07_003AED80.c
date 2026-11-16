/* PAL near miss (Codex wave 6): near miss: 21 words differ with the file's flags.
 * Worker's note: 21 diff, w319/func_L07_003AED80.07.log; VU0 atomic sequence scheduling, global address/call argument order. j helpers cannot compile with fixed flags (03.log). No metadata changes.
 */
#include "common.h"
/* localdecomp:start func_L07_003AED80 */
#include "vu0.h"
extern vu0_v4 D_L07_001D9AE0[];
__asm__(".extern D_L07_001D9AE0, 16");
extern u8 D_L07_003AEF58[];
void func_L07_003AED80(u8 *obj) {
    extern float func_0038D160(float, float);
    extern float func_0038CEA8(void *);
    extern float func_0038DB00(float, float);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, float);
    extern float func_L01_0040E4C0(void *);
    extern void func_L07_003AF240(u8 *);
    extern void func_L01_00448890(void *, void *, float, float, float, float, long);
    extern void func_L07_003AF010(u8 *, void *, void *);
    vu0_v4 diff, step;
    vu0_v4 *step_ptr;
    u8 *state = *(u8 **)(obj + 0x68);
    u8 *target = *(u8 **)(state + 0x240);
    float angle, length, turn, squared, height;
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(diff) : "m"(*(vu0_v4 *)(obj+0x10)), "m"(*(vu0_v4 *)(target+0x10)) : "vf1","vf2");
    angle = func_0038D160(diff.x, diff.y);
    length = func_0038CEA8(&diff);
    turn = func_0038DB00(angle, *(float *)(state+0x260));
    if (turn > 0.0f) func_0038CE90((step_ptr = &step), &diff, D_L07_001D9AE0);
    else func_0038CE90((step_ptr = &step), D_L07_001D9AE0, &diff);
    step.z = 0.0f;
    func_0038CF68(step_ptr, step_ptr, fabs_asm(length * turn));
    func_0038CF68(&diff, &diff, length - *(float *)(state+0x264));
    height = *(float *)(obj+0x18);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(step) : "m"(step), "m"(diff) : "vf1","vf2");
    step.z = *(float *)(state+0x268) - (height - *(float *)(*(u8 **)(state+0x240)+0x18));
    squared = func_L01_0040E4C0(step_ptr);
    if (squared > 25.0f) func_0038CF68(step_ptr, step_ptr, 5.0f);
    else if (squared < 0.25f) func_L07_003AF240(obj);
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
        : "=m"(step) : "m"(step), "m"(*(vu0_v4 *)(obj+0x10)) : "vf1","vf2");
    func_L01_00448890(obj+0xF8, state+0xE4, angle, *(float *)(state+0x44), *(float *)(state+0x48), *(float *)(state+0x4C), 0);
    func_L07_003AF010(obj, step_ptr, D_L07_003AEF58);
}
/* localdecomp:end func_L07_003AED80 */
