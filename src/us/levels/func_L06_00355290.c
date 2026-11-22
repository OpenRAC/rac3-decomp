#include "common.h"

/* NTSC-U counterpart of func_L06_00355F90. */
/* localdecomp:start func_L06_00355290 */
extern s32 func_L01_00452EC8(u8 *);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern void func_L06_00350C38(u8 *, u8 *, s32, s32, s32);
extern s32 func_L06_00350528(s32, u8 *);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern f32 func_L06_00352460(u8 *, s32);
s32 func_L06_00355290(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    if (func_L01_00452EC8(a0)) {
        *(s32 *)(v + 0x350) = 1;
        *(f32 *)(v + 0x354) = func_L06_00352460(v, *(s32 *)(v + 0x344));
        *(f32 *)(v + 0xA4) = 0.15f;
        func_L01_00458A70(a0, 0.00277777785f, 0.166666672f, 0.00698131742f, 0.209439531f);
        func_L06_00350C38(a0, v, 6, 0, 10);
    }
    func_L06_00350528((s32)a0, v);
    if (a0[0x60] & 2) {
        func_L01_00441FB8(a0, 6, -1);
        func_L06_00350C38(a0, v, 7, 0, 5);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_00355290 */
