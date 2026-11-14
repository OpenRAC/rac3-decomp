#include "common.h"

typedef struct {
    u8 pad0[8];
    s32 current;
    u8 padC[0x12C - 0xC];
    s32 total;
} Global_L40_0053CF40;

/* localdecomp:start func_L40_0053CF40 */
extern Global_L40_0053CF40 D_001A5E50;
extern s32 func_L40_004EC750(s32);
extern s32 func_L40_0053D4F8(s32);

/* Wraps value into an index modulo total; returns 1 if it is the current index, 0 if
 * func_L40_004EC750 rejects it, otherwise the result of func_L40_0053D4F8. */
s32 func_L40_0053CF40(s32 value) {
    s32 index = value % D_001A5E50.total;
    if (index == D_001A5E50.current) {
        return 1;
    }
    if (func_L40_004EC750(index) != 0) {
        return 0;
    }
    return func_L40_0053D4F8(index);
}
/* localdecomp:end func_L40_0053CF40 */
