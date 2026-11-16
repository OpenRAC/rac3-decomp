/* PAL near miss (Codex wave 8): near miss: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details).
 * Worker's note: Context correction required: owner declares func_0038DE98 void(f32,f32), retail consumes f0 at 003841DC and 003841FC. Draft uses inferred f32 return and ordinary checker rejects incompatible file prototype; w441/func_00384028.01.log. No cast/alias workaround; ...
 */
#include "common.h"
/* localdecomp:start func_00384028 */
#include "vu0.h"
s32 func_00384028(u8 *obj, u8 *state) {
    extern f32 func_003C3FA0(f32, f32, f32);
    extern void func_0038D270(void *, void *, void *);
    extern void func_003838B0();
    extern void func_0038D348(s32, s32, f32);
    extern f32 func_0038DEE0(f32, f32);
    extern f32 func_0038DE98(f32, f32);
    extern void func_0038DC70(void *, void *, void *, f32);
    extern void func_0038DBF0(void *, void *);
    extern f32 func_0038D248(void *, void *);
    extern void func_0038D200(void *, void *, f32);
    extern f32 func_0038D288(void *);
    extern f32 func_0038D4A8(f32);
    extern void func_003C4BF8(void *, void *, f32);
    extern void func_0038DC30(void *, void *, void *);
    extern void func_003C4BA0(void *, void *);
    extern void func_0038CEB0(s32 *);
    vu0_v4 angles, a, cross, b, base, offset, diff, projected;
    vu0_v4 basis[3], turnedA, turnedB, full, rotation;
    f32 fraction, delta, angle, sign, step;
    u8 *entry, *model;
    void *saved;
    if (*(s32 *)(state + 0xC) <= 0) return 1;
    entry = (u8 *)&D_00222480[*(s32 *)(obj + 0x94)];
    fraction = 1.0f / func_003C3FA0(1.0f, (f32)*(s32 *)(state + 0x14), (f32)*(s32 *)(state + 0xC) * *(f32 *)(state + 0x10));
    model = entry + 0x150;
    if (entry[0x2A2] == 2) {
        b = *(vu0_v4 *)(state + 0x30);
        base = *(vu0_v4 *)(entry + 0x190);
        a = *(vu0_v4 *)(state + 0x20);
        func_0038D270(&cross, &a, &b);
        func_003838B0(&angles, obj + 0x30, &base, &a, &cross, &b);
    } else {
        base = *(vu0_v4 *)(obj + 0x30);
        func_0038D348((s32)&a, *(s32 *)(model + 0xF0) + 0xC0, 1.0f);
        func_0038D348((s32)&b, *(s32 *)(model + 0xF0) + 0xE0, 1.0f);
        angles.z = 0.0f; angles.x = 3.1415927f; angles.y = 0.0f;
    }
    saved = state + 0x40;
    delta = func_0038DEE0(angles.x, *(f32 *)state);
    *(f32 *)state = func_0038DE98(*(f32 *)state, delta * fraction);
    *(f32 *)(state + 4) = func_0038DE98(*(f32 *)(state + 4), func_0038DEE0(angles.y, *(f32 *)(state + 4)) * fraction);
    *(f32 *)(state + 8) += (angles.z - *(f32 *)(state + 8)) * fraction;
    func_0038D348((s32)&offset, (s32)&a, *(f32 *)(state + 8));
    func_0038DC70(&offset, &offset, &b, *(f32 *)state);
    func_0038D270(&cross, &offset, &b);
    func_0038D348((s32)&cross, (s32)&cross, 1.0f);
    func_0038DC70(&offset, &offset, &cross, *(f32 *)(state + 4));
    vec_add_ba(state + 0x50, &base, &offset);
    *(vu0_v4 *)entry = *(vu0_v4 *)(state + 0x50);
    func_0038DBF0(saved, basis);
    func_0038D200(&projected, &basis[2], func_0038D248(&basis[2], obj));
    vec_sub_ba(&diff, obj, &projected);
    step = func_0038D248(&basis[0], &diff);
    angle = 1.5707964f - func_0038D4A8(step / func_0038D288(&diff));
    sign = -1.0f;
    if (func_0038D248(&diff, &basis[1]) >= 0.0f) sign = 1.0f;
    angle *= sign;
    if (fabs_asm(delta) > 1.5707964f && ((delta >= 0.0f && sign < 0.0f) || (delta < 0.0f && sign >= 0.0f))) {
        if (angle < 0.0f) angle += 6.2831855f;
        else angle -= 6.2831855f;
    }
    step = angle * fraction;
    if (fabs_asm(step) < 0.00001f) {
        turnedA = basis[0]; turnedB = basis[1];
    } else {
        func_003C4BF8(&full, &basis[2], step);
        func_0038DC30(&turnedA, &basis[0], &full);
        func_0038DC30(&turnedB, &basis[1], &full);
    }
    if (fabs_asm(angle) < 0.00001f) full = basis[0];
    else {
        func_003C4BF8(&rotation, &basis[2], angle);
        func_0038DC30(&full, &basis[0], &rotation);
    }
    angle = 1.5707964f - func_0038D4A8(func_0038D248(&full, obj));
    sign = -1.0f;
    if (func_0038D248(&full, obj + 0x20) >= 0.0f) sign = 1.0f;
    angle *= sign;
    func_0038DC70(&turnedA, &turnedA, &turnedB, angle * fraction);
    func_0038D348((s32)(entry + 0x380), (s32)&turnedA, 1.0f);
    func_0038D270(entry + 0x390, entry + 0x380, model + 0x80);
    func_0038D348((s32)(entry + 0x390), (s32)(entry + 0x390), -1.0f);
    func_0038D270(entry + 0x3A0, entry + 0x390, entry + 0x380);
    func_003C4BA0(state + 0x60, entry + 0x380);
    func_003C4BA0(saved, entry + 0x380);
    func_0038CEB0((s32 *)(state + 0xC));
    return 0;
}
/* localdecomp:end func_00384028 */
