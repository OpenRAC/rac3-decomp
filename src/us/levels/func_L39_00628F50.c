#include "common.h"

/* localdecomp:start func_L39_00628F50 */
s32 func_L39_00628F50(void *object, s32 value) {
    s32 selected = value == -1 ? 5 : value;
    *(s32 *)((u8 *)object + 0x638) = selected;
    return selected;
}
/* localdecomp:end func_L39_00628F50 */
