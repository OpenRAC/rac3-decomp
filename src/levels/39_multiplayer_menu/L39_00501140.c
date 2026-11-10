#include "common.h"

/* localdecomp:start func_L39_00501140 */
extern s32 func_L39_00501200(s32, s32, s32);
extern s32 func_L39_005061A8(void);
extern s32 func_L39_005061C8(void);
extern s32 func_11C090(s32);
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);

s32 func_L39_00501140(s32 arg0, s32 arg1, s32 arg2, s64 arg3) {
    s32 r = 0;

    if (arg1 == 1) {
        if (arg3 == 3) {
            r = func_L39_00501200(arg0, func_L39_005061A8(), 1);
            if (r == 0) {
                func_L39_004BC6C8(0xB, 0xD6, 0x9D, 0, 0);
            } else {
                r = func_L39_00501200(arg0, func_11C090(func_L39_005061C8()), 1);
            }
        } else {
            r = func_L39_00501200(arg0, arg2, arg3);
        }
    }
    return r != 0;
}
/* localdecomp:end func_L39_00501140 */

INCLUDE_ASM("asm/levels", func_L39_00501200);
