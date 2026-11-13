#include "common.h"

/* NTSC-U counterpart of func_L34_003515A0 (src/levels/34_vidcomic_3/L34_003515A0.c): 333 -> 400 */
/* localdecomp:start func_L34_00350880 */
s32 func_003C24B0(s32, s32);
void func_L01_00452E70(s32, s32);
void func_003C7C38(s32);
void func_L01_00441FB8(s32, s32, s32);

s32 func_L34_00350880(s32 arg0, s32 arg1) {
    u8 *p = (u8 *)func_003C24B0(0x16F4, 0x80);
    u8 *st;

    if (p != 0) {
        func_L01_00452E70((s32)p, arg0);
        *(s32 *)(p + 0xF4) = 0;
        func_003C7C38((s32)p);
        st = *(u8 **)(p + 0x68);
        *(s32 *)(st + 0x0) = 0x190;
        *(s32 *)(st + 0x10) = -1;
        *(s32 *)(st + 0x14) = 0;
        if (arg1 != 0) {
            *(f32 *)(p + 0x2C) = *(f32 *)(p + 0x2C) * 0.4f;
            func_L01_00441FB8((s32)p, 2, -1);
        }
    }
    return (s32)p;
}
/* localdecomp:end func_L34_00350880 */
