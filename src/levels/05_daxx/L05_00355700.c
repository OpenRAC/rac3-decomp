#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L05_00355700 */
extern s32 D_L05_001DD590;
extern s32 D_L05_001DD5A0;
extern s32 D_L05_001DD5B0;
extern s32 D_L05_001DD5C0;
extern s32 D_L05_001DD5D0;
extern s32 D_L05_001DD5E0;
extern s32 D_L05_001DD5F0;
extern f32 D_L05_001DD580;
extern f32 D_L05_001DD584;
__asm__(".extern D_L05_001DD590, 4");
__asm__(".extern D_L05_001DD5A0, 4");
__asm__(".extern D_L05_001DD5B0, 4");
__asm__(".extern D_L05_001DD5C0, 4");
__asm__(".extern D_L05_001DD5D0, 4");
__asm__(".extern D_L05_001DD5E0, 4");
__asm__(".extern D_L05_001DD5F0, 4");
__asm__(".extern D_L05_001DD580, 4");
__asm__(".extern D_L05_001DD584, 4");
extern void func_003C6680(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
extern void func_L01_0043A430(void *, s32, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_0044ED88(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_003C6990(void *, void *, s32);
extern void func_003C48A8(void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_0038D750(void *, s32, f32);
extern void func_L01_0044F450(void *, void *);
extern void func_003C4DA8(void *, void *, void *, void *);

void func_L05_00355700(u8 *o) {
    vu0_v4 pos;
    vu0_v4 rot;
    vu0_v4 d;
    u8 *v;
    f32 dv;
    f32 lim;

    *(vu0_q *)&pos = *(vu0_q *)(o + 0x10);
    *(vu0_q *)&rot = *(vu0_q *)(o + 0xF0);
    v = *(u8 **)(o + 0x68);
    if (o[0x20] == 0) {
        *(s32 *)(v + 0x6C) |= 1;
        *(vu0_q *)(v + 0x70) = *(vu0_q *)(o + 0x10);
        func_003C6680(o, v + 0x70, 0, 0, &D_L05_001DD5E0, &D_L05_001DD5F0, &D_L05_001DD590, &D_L05_001DD5A0,
                      &D_L05_001DD5B0, &D_L05_001DD5D0, &D_L05_001DD5C0);
        func_L01_0043A430(o, 0, v + 0x130);
        func_L01_004450F0(o, 1, -1);
        if (*(s32 *)(v + 0x188) == -1 && *(long *)(v + 0x180) == -1) {
            return;
        }
        o[0x30] = 0xFF;
        func_L01_0044ED88(o, v + 0x190, 0x40, *(s32 *)(v + 0x188), *(s32 *)(v + 0x180), *(s32 *)(v + 0x184), 7, 0);
        v[0x158A] = 1;
    }
    func_003C6990(o, v + 0x70, 0);
    func_003C48A8(o + 0xC0, o + 0xF0);
    dv = D_L05_001DD584 * 0.017453292f * 0.020000001f - *(f32 *)(v + 0x174);
    lim = D_L05_001DD580 * 0.017453292f * 0.00040000002f;
    if (dv > lim) {
        dv = lim;
    } else if (dv < -lim) {
        dv = -lim;
    }
    *(f32 *)(v + 0x174) += dv;
    *(f32 *)(v + 0x170) = func_0038DAB8(*(f32 *)(v + 0x170), *(f32 *)(v + 0x174));
    func_0038D750(v + 0x140, 1, *(f32 *)(v + 0x170));
    if (*(s32 *)(v + 0x188) != -1 || *(long *)(v + 0x180) != -1) {
        func_L01_0044F450(o, v + 0x190);
    }
    vec_sub_ab(&d, o + 0x10, &pos);
    func_003C4DA8(v + 0x30, &d, &rot, o + 0xF0);
}
/* localdecomp:end func_L05_00355700 */
