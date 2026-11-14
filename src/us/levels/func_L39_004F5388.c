#include "common.h"

/* localdecomp:start func_L39_004F5388 */
extern u8 D_L39_004F53A0[];

/* Stores the address of D_L39_004F53A0 at offset 8 of the given block and returns 0. */
s32 func_L39_004F5388(u8 *p) {
    *(void **)(p + 8) = D_L39_004F53A0;
    return 0;
}
/* localdecomp:end func_L39_004F5388 */
