#include "common.h"

/* localdecomp:start func_L39_004E36B0 */
extern s32 func_L39_004E3748(void *, s32, u8 *, u32 *, u32, s32, s32, s32);
extern s32 func_L39_004E3B68(void *, s32, s32, u32 *, u32, s32, u32, s32);
extern s32 func_L39_004E3CB8(void *, s32, s32, u32 *, u32, s32, u32, s32);
extern s32 func_L39_004E3EB8(void *, s32, s32, u32 *, u32, s32, u32, s32);
extern s32 func_L39_004E3FC0(void *, s32, s32, u32 *, u32, s32, u32, s32);

s32 func_L39_004E36B0(void *arg0, s32 arg1, s32 arg2, u32 *arg3, u32 arg4, s32 arg5, u32 arg6, s32 arg7) {
    switch (arg1) {
    case 1:
    case 10:
        return func_L39_004E3748(arg0, arg1, (u8 *)arg2, arg3, arg4, arg5, arg6, arg7);
    case 4:
        return func_L39_004E3FC0(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    case 2:
        return func_L39_004E3B68(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    case 3:
        return func_L39_004E3CB8(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    case 9:
        return func_L39_004E3EB8(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    }
    return 2;
}
/* localdecomp:end func_L39_004E36B0 */
