/* functional: high. EXACT: tools/check.py <file> func_00383C48 (frontbin, src/frontbin/382380.c flags) reports MATCH; ported from the matched boot_elf twin func_00384028 (src/boot_elf/text/383E48.c), callees renamed to their frontbin addresses through _bf3C48 aliases. */
typedef struct { u8 pad0[0x50]; void *f50; u8 pad54[0x460 - 0x54]; } S_00222500_bf3C48;
extern S_00222500_bf3C48 D_00222480_bf3C48[];
extern f32 func_003C3BE8_bf3C48(f32, f32, f32);
extern void func_0038DAB8_bf3C48(f32, f32);
extern f32 func_0038DB00_bf3C48(f32, f32);
extern f32 func_0038CE68_bf3C48(void *, void *);
extern f32 func_0038CEA8_bf3C48(void *);
extern f32 func_0038D0C8_bf3C48(f32);
extern void func_0038D890_bf3C48(void *, void *, void *, f32);
extern void func_0038CF68_bf3C48(s32 a, s32 b, f32 x);
extern void func_003834D0_bf3C48();
#include "vu0.h"
extern void func_0038CE90_bf3C48(void *, void *, void *);
extern void func_0038D810_bf3C48(void *, void *);
extern void func_0038CE20_bf3C48(f32 *, void *, f32);
extern void func_003C4840_bf3C48(f32 *, void *, f32);
extern void func_0038D850_bf3C48(void *, void *, void *);
extern s32 func_0038CAD0_bf3C48(void *);
s32 func_00383C48(u8 *obj, u8 *state) {
    vu0_v4 angles, a, cross, b, base, offset, diff, projected;
    vu0_v4 basis[3], turnedA, turnedB, full, rotation;
    f32 fraction, delta, angle, sign, step, dot, height;
    u8 *entry, *model;
    if (*(s32 *)(state + 0xC) <= 0) return 1;
    entry = (u8 *)&D_00222480_bf3C48[*(s32 *)(obj + 0x94)];
    fraction = 1.0f / func_003C3BE8_bf3C48(1.0f, (f32)*(s32 *)(state + 0x14), (f32)*(s32 *)(state + 0xC) * *(f32 *)(state + 0x10));
    model = entry + 0x150;
    if (entry[0x2A2] == 2) {
        base = *(vu0_v4 *)(entry + 0x190);
        a = *(vu0_v4 *)(state + 0x20);
        b = *(vu0_v4 *)(state + 0x30);
        func_0038CE90_bf3C48(&cross, &a, &b);
        func_003834D0_bf3C48(&angles, obj + 0x30, &base, &a, &cross, &b);
    } else {
        base = *(vu0_v4 *)(obj + 0x30);
        func_0038CF68_bf3C48((s32)&a, *(s32 *)(model + 0xF0) + 0xC0, 1.0f);
        func_0038CF68_bf3C48((s32)&b, *(s32 *)(model + 0xF0) + 0xE0, 1.0f);
        angles.z = 0.0f; angles.x = 3.1415927f; angles.y = 0.0f;
    }
    delta = func_0038DB00_bf3C48(angles.x, *(f32 *)state);
    *(f32 *)state = ((f32 (*)(f32, f32))func_0038DAB8_bf3C48)(*(f32 *)state, delta * fraction);
    *(f32 *)(state + 4) = ((f32 (*)(f32, f32))func_0038DAB8_bf3C48)(*(f32 *)(state + 4), func_0038DB00_bf3C48(angles.y, *(f32 *)(state + 4)) * fraction);
    *(f32 *)(state + 8) += (angles.z - *(f32 *)(state + 8)) * fraction;
    func_0038CF68_bf3C48((s32)&offset, (s32)&a, *(f32 *)(state + 8));
    func_0038D890_bf3C48(&offset, &offset, &b, *(f32 *)state);
    func_0038CE90_bf3C48(&cross, &offset, &b);
    func_0038CF68_bf3C48((s32)&cross, (s32)&cross, 1.0f);
    func_0038D890_bf3C48(&offset, &offset, &cross, *(f32 *)(state + 4));
    vec_add_ba(state + 0x50, &base, &offset);
    *(vu0_v4 *)entry = *(vu0_v4 *)(state + 0x50);
    func_0038D810_bf3C48(state + 0x40, basis);
    height = func_0038CE68_bf3C48(&basis[2], obj);
    func_0038CE20_bf3C48((f32 *)&projected, &basis[2], height);
    vec_sub_ba(&diff, obj, &projected);
    dot = func_0038CE68_bf3C48(&basis[0], &diff);
    angle = 1.5707964f - func_0038D0C8_bf3C48(dot / func_0038CEA8_bf3C48(&diff));
    sign = func_0038CE68_bf3C48(&diff, &basis[1]) >= 0.0f ? 1.0f : -1.0f;
    angle *= sign;
    if (fabs_asm(delta) > 1.5707964f && ((delta >= 0.0f && sign < 0.0f) || (delta < 0.0f && sign >= 0.0f))) {
        if (angle < 0.0f) angle += 6.2831855f;
        else angle -= 6.2831855f;
    }
    step = angle * fraction;
    if (fabs_asm(step) < 0.00001f) {
        turnedA = basis[0]; turnedB = basis[1];
    } else {
        func_003C4840_bf3C48((f32 *)&full, &basis[2], step);
        func_0038D850_bf3C48(&turnedA, &basis[0], &full);
        func_0038D850_bf3C48(&turnedB, &basis[1], &full);
    }
    if (fabs_asm(angle) < 0.00001f) full = basis[0];
    else {
        func_003C4840_bf3C48((f32 *)&rotation, &basis[2], angle);
        func_0038D850_bf3C48(&full, &basis[0], &rotation);
    }
    angle = 1.5707964f - func_0038D0C8_bf3C48(func_0038CE68_bf3C48(&full, obj));
    sign = func_0038CE68_bf3C48(&full, obj + 0x20) >= 0.0f ? 1.0f : -1.0f;
    angle *= sign;
    func_0038D890_bf3C48(&turnedA, &turnedA, &turnedB, angle * fraction);
    func_0038CF68_bf3C48((s32)(entry + 0x380), (s32)&turnedA, 1.0f);
    func_0038CE90_bf3C48(entry + 0x390, entry + 0x380, model + 0x80);
    func_0038CF68_bf3C48((s32)(entry + 0x390), (s32)(entry + 0x390), -1.0f);
    func_0038CE90_bf3C48(entry + 0x3A0, entry + 0x390, entry + 0x380);
    func_003C47E8_bf3C48(state + 0x60, entry + 0x380);
    func_003C47E8_bf3C48(state + 0x40, entry + 0x380);
    func_0038CAD0_bf3C48(state + 0xC);
    return 0;
}
