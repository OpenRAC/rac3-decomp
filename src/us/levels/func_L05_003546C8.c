#include "common.h"

/* NTSC-U counterpart of func_L05_00355700 (src/levels/05_daxx/L05_00355700.c) */
#include "vu0.h"

/* localdecomp:start func_L05_003546C8 */
extern s32 D_L05_001DD5D0_003546C8;
extern s32 D_L05_001DD5E0_003546C8;
extern s32 D_L05_001DD5F0_003546C8;
extern s32 D_L05_001DD600_003546C8;
extern s32 D_L05_001DD610;
extern s32 D_L05_001DD620;
extern s32 D_L05_001DD630;
extern f32 D_L05_001DD5C0_003546C8;
extern f32 D_L05_001DD5C4;
__asm__(".extern D_L05_001DD5D0_003546C8, 4");
__asm__(".extern D_L05_001DD5E0_003546C8, 4");
__asm__(".extern D_L05_001DD5F0_003546C8, 4");
__asm__(".extern D_L05_001DD600_003546C8, 4");
__asm__(".extern D_L05_001DD610, 4");
__asm__(".extern D_L05_001DD620, 4");
__asm__(".extern D_L05_001DD630, 4");
__asm__(".extern D_L05_001DD5C0_003546C8, 4");
__asm__(".extern D_L05_001DD5C4, 4");
extern void func_003C1130(void *, void *, void *, void *, void *, void *, void *, void *, void *, void *, void *);
extern void func_L01_00437350(void *, s32, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_0044BB08(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_003C1440(void *, void *, s32);
extern void func_003BF360(void *, void *);
extern f32 func_00389380(f32, f32);
extern void func_00389018(void *, s32, f32);
extern void func_L01_0044C1D0(void *, void *);
extern void func_003BF838(void *, void *, void *, void *);

void func_L05_003546C8(u8 *o) {
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
        func_003C1130(o, v + 0x70, 0, 0, &D_L05_001DD620, &D_L05_001DD630, &D_L05_001DD5D0_003546C8, &D_L05_001DD5E0_003546C8,
                      &D_L05_001DD5F0_003546C8, &D_L05_001DD610, &D_L05_001DD600_003546C8);
        func_L01_00437350(o, 0, v + 0x130);
        func_L01_00441FB8(o, 1, -1);
        if (*(s32 *)(v + 0x188) == -1 && *(long *)(v + 0x180) == -1) {
            return;
        }
        o[0x30] = 0xFF;
        func_L01_0044BB08(o, v + 0x190, 0x40, *(s32 *)(v + 0x188), *(s32 *)(v + 0x180), *(s32 *)(v + 0x184), 7, 0);
        v[0x158A] = 1;
    }
    func_003C1440(o, v + 0x70, 0);
    func_003BF360(o + 0xC0, o + 0xF0);
    dv = D_L05_001DD5C4 * 0.017453292f * 0.016666668f - *(f32 *)(v + 0x174);
    lim = D_L05_001DD5C0_003546C8 * 0.017453292f * 0.00027777778f;
    if (dv > lim) {
        dv = lim;
    } else if (dv < -lim) {
        dv = -lim;
    }
    *(f32 *)(v + 0x174) += dv;
    *(f32 *)(v + 0x170) = func_00389380(*(f32 *)(v + 0x170), *(f32 *)(v + 0x174));
    func_00389018(v + 0x140, 1, *(f32 *)(v + 0x170));
    if (*(s32 *)(v + 0x188) != -1 || *(long *)(v + 0x180) != -1) {
        func_L01_0044C1D0(o, v + 0x190);
    }
    vec_sub_ab(&d, o + 0x10, &pos);
    func_003BF838(v + 0x30, &d, &rot, o + 0xF0);
}
/* localdecomp:end func_L05_003546C8 */
