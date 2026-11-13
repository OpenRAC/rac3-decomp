#include "common.h"

/* NTSC-U counterpart of func_L39_00609490 (src/levels/shared/L39_00609468.c) */
void func_00194B28(s32);

/* localdecomp:start func_L39_00606D90 */
extern s32 D_001DA058_sda_00606D90 __attribute__((section(".sdata")));
extern u8 D_L39_002458F0[];
extern u8 D_L39_00245908[];
extern void func_001264E0(s32);
extern s32 func_00139048(void);
extern void func_0011E718(void *);
extern s32 func_00194A60(s32, s32, s32, u8 *);

s32 func_L39_00606D90(void *arg0, s32 arg1, s32 arg2) {
    s32 ret = 0;
    u8 buf[3];
    if (D_001DA058_sda_00606D90 != 0) {
        func_001264E0(2);
        if (((s32 (*)(s32))func_00194B28)(1) == 0) {
            D_001DA058_sda_00606D90 = 0;
            if (func_00139048() == 0) {
                *(s32 *)((u8 *)arg0 + 8) += arg2 >> 11;
                ret = (arg2 >> 11) << 11;
            } else {
                func_0011E718(D_L39_002458F0);
            }
        }
    } else {
        buf[0] = 100;
        buf[1] = 0;
        buf[2] = 0;
        func_00194B28(0);
        if (func_00194A60(*(s32 *)((u8 *)arg0 + 8), arg2 >> 11, arg1, buf) != 0) {
            D_001DA058_sda_00606D90 = 1;
        } else {
            func_0011E718(D_L39_00245908);
        }
        ret = 0;
    }
    return ret;
}
/* localdecomp:end func_L39_00606D90 */
