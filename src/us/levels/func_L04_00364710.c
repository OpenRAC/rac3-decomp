#include "common.h"

/* NTSC-U counterpart of func_L04_00365818 (src/levels/shared/L04_00362CE0.c): 5 -> 6 */
#include "vu0.h"
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00458A08(void *, f32);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00458A08(void *, f32);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);

/* localdecomp:start func_L04_00364710 */
extern s32 func_L01_00452EC8();
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_L01_00458A08(void *, f32);
extern f32 func_00388730(void *, void *);

s32 func_L04_00364710(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    vu0_v4 d;
    s32 t;
    if (func_L01_00452EC8(a0) != 0 && a0[0x43] != 3) {
        func_003BE4F0(a0, 3, 0, 6);
    }
    func_L01_00458A08(a0, *(f32 *)(pv + 0x36C));
    if (*(f32 *)(a0 + 0xF8) == *(f32 *)(pv + 0x36C)) {
        t = *(s32 *)(pv + 0x308);
        if (t == 2) {
            vec_sub_ab(&d, pv + 0x220, pv + 0x320);
            t = 0.0f < func_00388730(&d, pv + 0x330) ? -1 : 1;
        }
        if (t == 1) {
            func_L01_00441FB8(a0, 0x13, -1);
        } else {
            func_L01_00441FB8(a0, 0x16, -1);
        }
        return 2;
    }
    return 0;
}
/* localdecomp:end func_L04_00364710 */
