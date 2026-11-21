#include "vu0.h"
#include "common.h"

/* localdecomp:start func_L06_00350E28 */
extern s32 D_L06_001DD2D8;
__asm__(".extern D_L06_001DD2D8, 4");
extern f32 func_0038CED8(void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038D160(f32, f32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);

void func_L06_00350E28(u8 *a0, u8 *a1, void *a2, s32 a3) {
    extern void func_L01_0040EE50(void *, void *);
    extern void func_L06_00350C50(u8 *, u8 *, s32, void *, void *, void *);
    extern void func_L06_00350D60(s32, s32, s32, f32 *);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_0038D308(void *, void *);
    extern void func_0038D5F0(void *, void *, void *);
    extern void func_003C48A8(void *, void *);
    vu0_v4 rot;
    vu0_v4 pos;
    vu0_v4 d;
    vu0_v4 m30[3];
    vu0_v4 m60[3];
    vu0_v4 m90[3];
    vu0_v4 xC0[4];
    vu0_v4 off;
    u8 *p;

    func_L01_0040EE50(m90, *(u8 **)(a1 + 0x260) + 0xC0);
    qzero(&rot);
    func_L06_00350C50(a0, a1, a3, xC0, &pos, &d);
    vec_sub_ab(&d, a2, &pos);
    if (a3 == 0) {
        func_0038CE20(&off, *(u8 **)(a1 + 0x260) + 0xD0, -0.75f);
        vec_add_ab(&d, &off, &d);
    } else {
        func_0038CE20(&off, *(u8 **)(a1 + 0x260) + 0xD0, 0.75f);
        vec_add_ab(&d, &off, &d);
    }
    rot.y = -func_0038D160(func_0038CED8(&d), d.z);
    rot.y = func_0038DAB8(rot.y, -0.22f);
    rot.z = func_0038D160(d.x, d.y);
    func_0038D308(m30, &rot);
    func_0038D5F0(m60, m90, m30);
    p = a1 + (a3 * 0x80 + 0x3A0);
    func_003C48A8(m60, p + 0x60);
    func_L06_00350D60((s32)a0, (s32)a1, a3, (f32 *)(p + 0x60));
    func_L01_0044E850(*(void **)(a1 + 0x260), p, (&D_L06_001DD2D8)[a3], 0.0432f, 0.43200004f);
}
/* localdecomp:end func_L06_00350E28 */
