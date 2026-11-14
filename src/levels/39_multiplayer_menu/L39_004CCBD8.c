#include "common.h"
#include "dnas.h"

/* the second library's driver: driver(block, k1, k2, k3) (include/dnas.h) */
extern void func_L39_004F7890(s32, s32, s32, u32);

/* localdecomp:start func_L39_004CCBD8 */
extern s32 func_L39_004B7418(void);
extern s32 func_L39_004D3E90(s32);
extern s32 func_L39_004CFBA8(void);
extern void func_L39_004D0CE0(void);
extern s32 D_L39_00465848;

s32 func_L39_004CCBD8(s32 a0) {
    s32 ret = -1;

    DNAS_BEGIN(func_L39_004CCBD8, 0, func_L39_004F7890);
    if (D_L39_00465848 != 0) {
        ret = 0;
    } else if (func_L39_004B7418() >= 0) {
        s32 r;

        ret = -0x193;
        r = func_L39_004D3E90(a0);
        if (r == 1) {
            if (func_L39_004CFBA8() >= 0) {
                func_L39_004D0CE0();
                ret = 0;
                D_L39_00465848 = r;
            }
        }
    }
    DNAS_END(func_L39_004CCBD8, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CCBD8 */

/* localdecomp:start func_L39_004CCD18 */
#include "dnas.h"

extern void func_L39_004F7890(s32, s32, s32, u32);
extern s32 func_L39_004B7418(void);
extern s32 func_L39_004D3E90(s32);
extern s32 func_L39_004CFBA8(void);
extern void func_L39_004D0CE0(void);
extern s32 D_L39_00465848;

s32 func_L39_004CCD18(s32 a0) {
    s32 ret = -1;

    DNAS_BEGIN(func_L39_004CCD18, 0, func_L39_004F7890);
    if (D_L39_00465848 != 0) {
        ret = 0;
    } else if (func_L39_004B7418() >= 0) {
        s32 r;

        ret = -0x193;
        r = func_L39_004D3E90(a0);
        if (r == 1) {
            if (func_L39_004CFBA8() >= 0) {
                func_L39_004D0CE0();
                ret = 0;
                D_L39_00465848 = r;
            }
        }
    }
    DNAS_END(func_L39_004CCD18, 0, func_L39_004F7890);
    return ret;
}
/* localdecomp:end func_L39_004CCD18 */
