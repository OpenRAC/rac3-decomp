#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L06_00350E28. */
/* localdecomp:start func_L06_00350130 */
extern s32 D_L06_001DD318;
__asm__(".extern D_L06_001DD318, 4");
extern f32 func_003887A0(void *);
extern void func_003886E8(void *, void *, f32);
extern f32 func_00388A28(f32, f32);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);

void func_L06_00350130(u8 *a0, u8 *a1, void *a2, s32 a3) {
    extern void func_L01_0040C920(void *, void *);
    extern void func_L06_0034FF58(u8 *, u8 *, s32, void *, void *, void *);
    extern void func_L06_00350068(s32, s32, s32, f32 *);
    extern f32 func_00389380(f32, f32);
    extern void func_00388BD0(void *, void *);
    extern void func_00388EB8(void *, void *, void *);
    extern void func_003BF360(void *, void *);
    vu0_v4 rot;
    vu0_v4 pos;
    vu0_v4 d;
    vu0_v4 m30[3];
    vu0_v4 m60[3];
    vu0_v4 m90[3];
    vu0_v4 xC0[4];
    vu0_v4 off;
    u8 *p;

    func_L01_0040C920(m90, *(u8 **)(a1 + 0x260) + 0xC0);
    qzero(&rot);
    func_L06_0034FF58(a0, a1, a3, xC0, &pos, &d);
    vec_sub_ab(&d, a2, &pos);
    if (a3 == 0) {
        func_003886E8(&off, *(u8 **)(a1 + 0x260) + 0xD0, -0.75f);
        vec_add_ab(&d, &off, &d);
    } else {
        func_003886E8(&off, *(u8 **)(a1 + 0x260) + 0xD0, 0.75f);
        vec_add_ab(&d, &off, &d);
    }
    rot.y = -func_00388A28(func_003887A0(&d), d.z);
    rot.y = func_00389380(rot.y, -0.22f);
    rot.z = func_00388A28(d.x, d.y);
    func_00388BD0(m30, &rot);
    func_00388EB8(m60, m90, m30);
    p = a1 + (a3 * 0x80 + 0x3A0);
    func_003BF360(m60, p + 0x60);
    func_L06_00350068((s32)a0, (s32)a1, a3, (f32 *)(p + 0x60));
    func_L01_0044B5C8(*(void **)(a1 + 0x260), p, (&D_L06_001DD318)[a3], 0.03f, 0.3f);
}
/* localdecomp:end func_L06_00350130 */
