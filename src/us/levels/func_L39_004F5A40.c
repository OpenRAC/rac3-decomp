#include "common.h"

/* localdecomp:start func_L39_004F5A40 */
extern u8 D_L39_004F5A58[];

/* Stores the address D_L39_004F5A58 in the pointer at offset 8 of p, and returns 0. */
s32 func_L39_004F5A40(u8 *p) {
    *(void **)(p + 8) = D_L39_004F5A58;
    return 0;
}
/* localdecomp:end func_L39_004F5A40 */
