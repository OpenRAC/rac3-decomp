#include "common.h"

/* localdecomp:start func_L03_0032F600 */
extern s32 func_L01_004AA710(s32, s32);
extern void func_003A4F28(s32);

void func_L03_0032F600(s32 a0) {
    s32 i;

    for (i = 0; i < 52; i++) {
        if (func_L01_004AA710(a0, i)) func_003A4F28(i);
    }
}
/* localdecomp:end func_L03_0032F600 */
