#include "common.h"

/* NTSC-U counterpart of func_L06_003564A0. */
/* localdecomp:start func_L06_003557A0 */
extern s32 func_L01_00452EC8(u8 *);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern void func_L06_00350C38(u8 *, u8 *, s32, s32, s32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern s32 func_L01_004576E8(u8 *);
s32 func_L06_003557A0(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);

    if (func_L01_00452EC8(a0)) {
        *(s32 *)(v + 0x350) = 0;
        *(f32 *)(v + 0xA4) = 0.5f;
        func_L01_00458A70(a0, 0.00388888898f, 0.0833333358f, 0.00698131742f, 0.209439531f);
    }
    if (a0[0x43] == 8 && (a0[0x60] & 2)) {
        func_L01_00441FB8(a0, 3, -1);
        func_L06_00350C38(a0, v, 2, 0, 10);
        return 1;
    }
    if (*(f32 *)(v + 0x100) < *(f32 *)(a0 + 0x18)) {
        func_L01_004576E8(a0);
        return 0;
    }
    if (a0[0x43] != 8) {
        func_L06_00350C38(a0, v, 8, 0, 5);
    }
    return 0;
}
/* localdecomp:end func_L06_003557A0 */
