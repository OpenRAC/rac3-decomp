#include "common.h"

/* localdecomp:start func_L04_00365638 */
extern s32 func_L04_00462650(void);
extern void func_L04_00451098(void *, s32, s32, s32);

/* Calls func_L04_00451098 on the object when func_L04_00462650 returns nonzero and the object's
 * byte 0x43 is set; always returns 0. */
s32 func_L04_00365638(u8 *object) {
    if (func_L04_00462650() != 0 && object[0x43] != 0) {
        func_L04_00451098(object, 0, 0, 10);
    }
    return 0;
}
/* localdecomp:end func_L04_00365638 */
