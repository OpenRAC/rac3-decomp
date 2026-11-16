#include "common.h"

/* localdecomp:start func_L40_0053CA28 */
extern s32 D_001A5E58[];

/* Returns 1 when the word at offset 4 of the object equals the first entry of D_001A5E58, else 0. */
s32 func_L40_0053CA28(void *object) {
    return *(s32 *)((u8 *)object + 4) == D_001A5E58[0];
}
/* localdecomp:end func_L40_0053CA28 */
