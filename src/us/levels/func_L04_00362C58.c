#include "common.h"

/* NTSC-U counterpart of func_L04_00363D00 (src/levels/shared/L04_00362CE0.c): 8 -> 10; 0.0024 -> 0.00166667; 0.04 -> 0.0333333; 0.0100531 -> 0.00698132; 0.251327 -> 0.20944; 0.00181514 -> 0.00126052; 0.0349066 -> 0.0290888 */
#include "vu0.h"
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_00388800(void *, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_00388800(void *, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern f32 func_00388800(void *, void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0037E208(s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_0037E208(s32, s32);
extern f32 func_00388800(void *, void *);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388800(void *, void *);

/* localdecomp:start func_L04_00362C58 */
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E2A8(void);
extern f32 func_0037E250(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_L01_00453210(void *, s32);
extern void func_L01_00457590(void *, void *, f32);
extern f32 func_00388A28(f32, f32);
extern f32 func_L01_00445758(void *, f32, void *, f32, f32, f32, s32);
extern f32 func_00388800(void *, void *);
extern s32 func_00388398(void *);

s32 func_L04_00362C58(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    f32 a;
    f32 r;
    u8 *p;
    u8 *t;
    if (func_L01_00452EC8(a0) != 0) {
        if (a0[0x43] != 2) {
            func_003BE4F0(a0, 2, 0, 10);
        }
        p = pv + 0x340;
        a = func_0037E2A8();
        r = func_0037E250(2.0f, 6.0f);
        qzero(pv + 0x340);
        *(f32 *)(pv + 0x340) = func_00388960(a) * r;
        *(f32 *)(pv + 0x344) = func_00388978(a) * r;
        vec_add_ab(pv + 0x340, pv + 0x340, pv + 0x320);
        if (*(s32 *)(pv + 0x31C) != -1 && func_L01_00453210(p, *(s32 *)(pv + 0x31C)) == 0) {
            *(vu0_q *)(pv + 0x340) = *(vu0_q *)(pv + 0x320);
        }
        *(s32 *)(pv + 0x360) = func_0037E208(0x12C, 0x212);
        func_L01_00458A70(a0, 0.00166666671f, 0.0333333351f, 0.00698131742f, 0.209439531f);
    }
    if (*(s32 *)(pv + 0x4E4) == 0) {
        t = pv + 0x340;
        func_L01_00457590(a0, t, *(f32 *)(a0 + 0xF8));
        func_L01_00445758(a0 + 0xF8, func_00388A28(*(f32 *)(pv + 0x340) - *(f32 *)(a0 + 0x10), *(f32 *)(pv + 0x344) - *(f32 *)(a0 + 0x14)), pv + 0x370, 0.00126051565f, 0.00126051565f, 0.0290888231f, 0);
        if (func_00388800(a0 + 0x10, t) < 0.75f) {
            a = func_0037E2A8();
            r = func_0037E250(2.0f, 6.0f);
            qzero(pv + 0x340);
            *(f32 *)(pv + 0x340) = func_00388960(a) * r;
            *(f32 *)(pv + 0x344) = func_00388978(a) * r;
            vec_add_ab(pv + 0x340, pv + 0x340, pv + 0x320);
            if (*(s32 *)(pv + 0x31C) != -1 && func_L01_00453210(t, *(s32 *)(pv + 0x31C)) == 0) {
                *(vu0_q *)(pv + 0x340) = *(vu0_q *)(pv + 0x320);
            }
        }
        if (func_00388398(pv + 0x360) == 0) {
            return 0;
        }
    }
    func_L01_00441FB8(a0, 3, -1);
    return 1;
}
/* localdecomp:end func_L04_00362C58 */
