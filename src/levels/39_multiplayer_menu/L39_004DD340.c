#include "common.h"

/* localdecomp:start func_L39_004DD340 */
typedef struct S_004DD340 {
    char _p0[0x4];
    s32 f4;
} S_004DD340;
extern s32 func_L39_004E48A8(s32, s32, s32, s32, s32, s32, s32);

s32 func_L39_004DD340(void *arg0, s32 arg1, void *arg2, s32 arg3) {
    return func_L39_004E48A8(((S_004DD340 *)arg0)->f4, 0x12, arg1, 2, (s32)arg2, arg3, 0x12);
}
/* localdecomp:end func_L39_004DD340 */
