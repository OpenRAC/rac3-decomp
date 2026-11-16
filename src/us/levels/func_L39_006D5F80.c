#include "common.h"

/* localdecomp:start func_L39_006D5F80 */
extern s32 func_001962E8(void);
extern s32 func_0012DCB0(void);
extern long func_00130760(s32, long);

/* Checks the pending request on an object: sets its error code at +0x10 (8 on an error from
 * func_001962E8, 2 when it has been pending too long) and returns 0, else returns 1 while it is
 * still fine. */
s32 func_L39_006D5F80(u8 *object) {
    s32 result = 1;
    s32 value;
    s32 difference;
    if (func_001962E8() != 0) {
        value = 8;
    } else {
        if (object[1] == 0) {
            goto done;
        }
        if (*(s32 *)(object + 8) == 0) {
            goto done;
        }
        if (*(s32 *)(object + 0xC) <= 0) {
            goto done;
        }
        difference = (s32)func_00130760(func_0012DCB0(), 0x24000) - *(s32 *)(object + 8);
        if (*(s32 *)(object + 0xC) < difference) {
            value = 2;
        } else {
            goto done;
        }
    }
    *(s32 *)(object + 0x10) = value;
    if (*(s32 *)(object + 0x14) == 0) {
        *(s32 *)(object + 0x14) = value;
    }
    result = 0;
done:
    return result;
}
/* localdecomp:end func_L39_006D5F80 */
