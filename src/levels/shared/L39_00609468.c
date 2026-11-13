#include "common.h"

/* localdecomp:start func_L39_00609468 */
void func_00194A38(s32);
void func_00194AF8();

s32 func_L39_00609468(void) {
    func_00194AF8();
    func_00194A38(0);
    return 1;
}
/* localdecomp:end func_L39_00609468 */

/* localdecomp:start func_L39_00609490 */
extern s32 D_001DA058_sda __attribute__((section(".sdata")));
extern u8 D_L39_00245770[];
extern u8 D_L39_00245788[];
extern void func_001264E0(s32);
extern s32 func_00139048(void);
extern void func_0011E718(void *);
extern s32 func_00194970(s32, s32, s32, u8 *);

s32 func_L39_00609490(void *arg0, s32 arg1, s32 arg2) {
    s32 ret = 0;
    u8 buf[3];
    if (D_001DA058_sda != 0) {
        func_001264E0(2);
        if (((s32 (*)(s32))func_00194A38)(1) == 0) {
            D_001DA058_sda = 0;
            if (func_00139048() == 0) {
                *(s32 *)((u8 *)arg0 + 8) += arg2 >> 11;
                ret = (arg2 >> 11) << 11;
            } else {
                func_0011E718(D_L39_00245770);
            }
        }
    } else {
        buf[0] = 100;
        buf[1] = 0;
        buf[2] = 0;
        func_00194A38(0);
        if (func_00194970(*(s32 *)((u8 *)arg0 + 8), arg2 >> 11, arg1, buf) != 0) {
            D_001DA058_sda = 1;
        } else {
            func_0011E718(D_L39_00245788);
        }
        ret = 0;
    }
    return ret;
}
/* localdecomp:end func_L39_00609490 */
