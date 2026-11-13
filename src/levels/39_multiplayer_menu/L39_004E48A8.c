#include "common.h"

/* localdecomp:start func_L39_004E48A8 */
extern s32 func_L39_004E4970(s32, s32 *, s32);

s32 func_L39_004E48A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 args[6];

    args[0] = arg1;
    args[1] = arg2;
    args[4] = arg5;
    args[3] = arg4;
    args[2] = arg3;
    args[5] = arg6 & ~8;
    return func_L39_004E4970(arg0, args, arg6 & ~8);
}
/* localdecomp:end func_L39_004E48A8 */
