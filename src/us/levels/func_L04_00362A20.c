#include "common.h"

/* NTSC-U counterpart of func_L04_00363AA0 (src/levels/shared/L04_00362CE0.c): 0.0024 -> 0.00166667; 0.04 -> 0.0333333; 0.0100531 -> 0.00698132; 0.251327 -> 0.20944; 8 -> 10 */
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

/* localdecomp:start func_L04_00362A20 */
extern s32 func_L01_00452EC8();
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern s32 func_L01_00458AE0(void *, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);

s32 func_L04_00362A20(u8 *a0) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    if (func_L01_00452EC8(a0) != 0) {
        func_L01_00458A70(a0, 0.00166666671f, 0.0333333351f, 0.00698131742f, 0.209439531f);
        if (a0[0x43] != 2) {
            func_003BE4F0(a0, 2, 0, 10);
        }
    }
    if (func_L01_00458AE0(a0, *(s32 *)(pv + 0x300)) != 0) {
        func_L01_00441FB8(a0, 3, -1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L04_00362A20 */
