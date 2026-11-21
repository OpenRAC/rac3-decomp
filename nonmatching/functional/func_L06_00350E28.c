/* functional: high. check.py at level_06: 80 instruction diffs, all stack-frame offsets/scheduling from local layout; call sequence, arguments, constants (+-0.75, -0.22, 0.0432, 0.432) and stores re-read against the assembly. Declares D_L06_001DD2D8 as s32[2] (the file's later declaration is a scalar) and calls func_L06_00350D60 with its later s32,s32,s32,f32* prototype. */
#include "vu0.h"
#include "common.h"
extern void func_L01_0040EE50(void *, void *);
extern void func_L06_00350C50(u8 *, u8 *, s32, void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D308(void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_003C48A8(void *, void *);
extern void func_L06_00350D60(s32, s32, s32, f32 *);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern s32 D_L06_001DD2D8[2];
__asm__(".extern D_L06_001DD2D8, 8");

void func_L06_00350E28(u8 *a0, u8 *a1, vu0_v4 *a2, s32 side) {
    vu0_v4 ang;
    vu0_v4 pos;
    vu0_v4 d;
    vu0_v4 m[4];
    vu0_v4 off;
    vu0_v4 rot[3];
    vu0_v4 rm[3];
    vu0_v4 base[3];
    u8 *e;

    func_L01_0040EE50(base, *(u8 **)(a1 + 0x260) + 0xC0);
    qzero(&ang);
    func_L06_00350C50(a0, a1, side, m, &pos, &d);
    vec_sub_ab(&d, a2, &pos);
    if (side == 0) {
        func_0038CE20(&off, *(u8 **)(a1 + 0x260) + 0xD0, -0.75f);
    } else {
        func_0038CE20(&off, *(u8 **)(a1 + 0x260) + 0xD0, 0.75f);
    }
    vec_add_ab(&d, &off, &d);
    ang.y = -func_0038D160(func_0038CED8(&d), d.z);
    ang.y = func_0038DAB8(ang.y, -0.22f);
    ang.z = func_0038D160(d.x, d.y);
    func_0038D308(rm, &ang);
    func_0038D5F0(rot, base, rm);
    e = a1 + 0x3A0 + side * 0x80;
    func_003C48A8(rot, e + 0x60);
    func_L06_00350D60((s32)a0, (s32)a1, side, (f32 *)(e + 0x60));
    func_L01_0044E850(*(u8 **)(a1 + 0x260), e, D_L06_001DD2D8[side], 0.0432f, 0.432f);
}
