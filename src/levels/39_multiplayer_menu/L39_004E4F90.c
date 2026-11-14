#include "common.h"

/* localdecomp:start func_L39_004E4F90 */
typedef struct S_004E4F90 {
    s32 f0;
    s32 (*f4)(struct S_004E4F90 *);
} S_004E4F90;

s32 func_L39_004E4F90(S_004E4F90 *arg0) {
    if (arg0 == 0 || arg0->f4 == 0) {
        return -1;
    }
    return arg0->f4(arg0);
}
/* localdecomp:end func_L39_004E4F90 */

/* localdecomp:start func_L39_004E4FC8 */
typedef struct S_004E4FC8 {
    s32 (*f0)(struct S_004E4FC8 *, u8 *, s32);
} S_004E4FC8;

s32 func_L39_004E4FC8(S_004E4FC8 *arg0, u8 *buf, s32 num) {
    if (arg0 == 0 || arg0->f0 == 0) {
        return -1;
    }
    return arg0->f0(arg0, buf, num);
}
/* localdecomp:end func_L39_004E4FC8 */

LINKER_REMNANT("asm/levels", func_L39_004E5000);
