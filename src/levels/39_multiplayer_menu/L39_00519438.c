#include "common.h"

/* localdecomp:start func_L39_00519438 */
extern s32 func_L39_00518A60(u32);

/* from rac4-decomp's func_L00_00566D30, renamed */
s32 func_L39_00519438(u32 arg0) {
    if (arg0 != 0) {
        return func_L39_00518A60(arg0 & 0xFFFF);
    }
    return -1;
}
/* localdecomp:end func_L39_00519438 */
