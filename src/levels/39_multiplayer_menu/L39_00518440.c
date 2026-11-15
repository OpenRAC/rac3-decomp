#include "common.h"

/* localdecomp:start func_L39_00518440 */
typedef struct Type1_518440 {
    unsigned long f0;
    char _p8[0x16 - 0x8];
    u8 f16;
    u8 f17;
} Type1_518440;

/* from rac4-decomp's func_L00_00554250 */
void func_L39_00518440(Type1_518440 *arg0, s32 arg1) {
    if ((arg0->f16 & 4) == 0) {
        arg0->f16 |= 4;
        arg0->f0++;
    }
    arg0->f17 = arg1;
}
/* localdecomp:end func_L39_00518440 */
