#include "common.h"

/* localdecomp:start func_L07_003AECA8 */
void func_L07_00334740();
void func_L07_003AEAA0(s32, s32);

void func_L07_003AECA8(s32 arg0) {
    func_L07_00334740();
    func_L07_003AEAA0(arg0, 1);
}
/* localdecomp:end func_L07_003AECA8 */

/* localdecomp:start func_L07_003AECD8 */
extern void func_L07_00334800(int *);
void func_L07_003AEAA0(int, int);
void func_L07_003AECD8(int *obj)
{
    int *state;
    *(float *)((char *)obj + 0x2C) = *(float *)(*(char **)((char *)obj + 0x24) + 0x24);
    state = (int *)obj[0x68/4];
    state[0x108/4] = -1;
    func_L07_00334800(obj);
    func_L07_003AEAA0((int)obj, 2);
}
/* localdecomp:end func_L07_003AECD8 */

/* localdecomp:start func_L07_003AED20 */
s32 func_L07_00331008(s32, s32);
void func_L07_003310E8(s32, s32);
void func_L07_003AEAA0(s32, s32);

s32 func_L07_003AED20(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);

    if (func_L07_00331008(*(s32 *)(p + 0x240), (s32)arg0) != 0) {
        return 1;
    }
    func_L07_003310E8(*(s32 *)(p + 0x240), (s32)arg0);
    func_L07_003AEAA0((s32)arg0, 6);
    return 0;
}
/* localdecomp:end func_L07_003AED20 */

/* localdecomp:start func_L07_003AED80 */
#include "vu0.h"
extern vu0_v4 D_L07_001D9AE0 __attribute__((section(".sdata")));
extern void func_L01_003B2DC8();
void func_L07_003AED80(u8 *obj) {
    extern float func_0038D160(float, float);
    extern float func_0038CEA8(void *);
    extern float func_0038DB00(float, float);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, float);
    extern float func_L01_0040E4C0(void *);
    extern void func_L07_003AF240(u8 *);
    extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
    extern void func_L07_003AF010(u8 *, vu0_q *, void (*)(void *, void *));
    vu0_v4 diff, step;
    vu0_v4 *step_ptr;
    u8 *state = *(u8 **)(obj + 0x68);
    u8 *target = *(u8 **)(state + 0x240);
    float angle, length, turn, squared, height;
    vec_sub_ba(&diff, target + 0x10, obj + 0x10);
    angle = func_0038D160(diff.x, diff.y);
    length = func_0038CEA8(&diff);
    turn = func_0038DB00(angle, *(float *)(state + 0x260));
    if (turn > 0.0f) {
        func_0038CE90((step_ptr = &step), &diff, &D_L07_001D9AE0);
    } else {
        func_0038CE90((step_ptr = &step), &D_L07_001D9AE0, &diff);
    }
    step.z = 0.0f;
    func_0038CF68(step_ptr, step_ptr, fabs_asm(length * turn));
    func_0038CF68(&diff, &diff, length - *(float *)(state + 0x264));
    height = *(float *)(obj + 0x18);
    vec_add_ab(&step, &step, &diff);
    step.z = *(float *)(state + 0x268) - (height - *(float *)(*(u8 **)(state + 0x240)+0x18));
    squared = func_L01_0040E4C0(step_ptr);
    if (squared > 25.0f) {
        func_0038CF68(step_ptr, step_ptr, 5.0f);
    } else if (squared < 0.25f) {
        func_L07_003AF240(obj);
    }
    vec_add_ba(&step, obj + 0x10, &step);
    func_L01_00448890(obj + 0xF8, state + 0xE4, 0, angle, *(f32 *)(state + 0x44),
                      *(f32 *)(state + 0x48), *(f32 *)(state + 0x4C));
    func_L07_003AF010(obj, (vu0_q *)step_ptr, func_L01_003B2DC8);
}
/* localdecomp:end func_L07_003AED80 */
