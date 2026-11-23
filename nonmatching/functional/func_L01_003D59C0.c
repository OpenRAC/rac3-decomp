/* functional: medium. Near miss (80 word diffs, allocation and scheduling; branch bodies reproduce PAL per the worker). */
#include "common.h"
/* localdecomp:start func_L01_003D59C0 */
#include "vu0.h"
void func_L01_003D59C0(M_3D41E8 *obj, s32 index, void *position, void *matrix,
                       f32 speed, f32 radius, f32 duration, f32 size, f32 acceleration) {
    extern f32 func_003824E0(f32, f32);
    extern s32 func_00382468(s32);
    extern void func_L01_00443B18(void *, f32);
    extern void func_0038D000(void *, void *, void *);
    extern void func_0038CF68(vu0_v4 *, vu0_v4 *, f32);
    vu0_v4 velocity, point;
    V_3D41E8 *vars = obj->x68;
    u8 *record;
    switch (vars->x3D0) {
    case 1:
        velocity.x = func_003824E0(2.0f, 4.0f) * speed * 0.0200000014f;
        velocity.y = func_003824E0(3.0f, vars->x3D2 + 4.0f) * speed * 0.0200000014f * 0.5f;
        if (func_00382468(2)) velocity.y = -velocity.y;
        velocity.z = func_003824E0(0, 1.0f) * 0.0200000014f;
        *(vu0_q *)&point = *(vu0_q *)position;
        break;
    case 2: case 3: case 4:
        func_L01_00443B18(&velocity, speed * 4.0f * 0.0200000014f);
        velocity.z = func_003824E0(0, 4.0f) * 0.0200000014f;
        func_L01_00443B18(&point, radius);
        point.z = func_003824E0(0, radius * 0.25f);
        vec_add_ba(&point, &point, position);
        break;
    }
    record = (u8 *)vars + index * 0x60;
    func_0038D000(&velocity, &velocity, matrix);
    *(vu0_v4 *)(record + 0) = point;
    *(vu0_v4 *)(record + 0x20) = point;
    *(vu0_v4 *)(record + 0x30) = velocity;
    *(vu0_v4 *)(record + 0x10) = velocity;
    *(vu0_v4 *)(record + 0x40) = *(vu0_v4 *)((u8 *)obj + 0xF0);
    *(f32 *)(record + 0xC) = func_003824E0(duration * 0.75f, duration * 1.25f) * 2.0f * 3.14159274f / 50.3333321f;
    *(f32 *)(record + 0x1C) = func_003824E0(acceleration * 0.75f, acceleration * 2.0f);
    *(f32 *)(record + 0x4C) = func_003824E0(size * 0.5f, size * 1.5f);
    *(s32 *)(record + 0x50) = 0;
    record[0x54] = 0;
    *(s32 *)(record + 0x5C) = 0;
    *(s32 *)(record + 0x58) = 0;
    *(s32 *)(record + 0x38) = 0;
    record[0x55] = 0x7F;
    func_0038CF68((vu0_v4 *)(record + 0x30), (vu0_v4 *)(record + 0x30), 1.0f);
}
/* localdecomp:end func_L01_003D59C0 */
