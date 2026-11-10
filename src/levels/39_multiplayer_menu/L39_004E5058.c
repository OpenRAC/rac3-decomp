#include "common.h"

/* localdecomp:start func_L39_004E5058 */
typedef struct S_004E5058 {
    char _p0[8];
    s32 (*f8)(struct S_004E5058 *, s32, s32 *);
} S_004E5058;

s32 func_L39_004E5058(S_004E5058 *arg0, s32 arg1) {
    if (arg0 == 0 || arg0->f8 == 0) {
        return 0;
    }
    return arg0->f8(arg0, 0x10, &arg1);
}
/* localdecomp:end func_L39_004E5058 */
