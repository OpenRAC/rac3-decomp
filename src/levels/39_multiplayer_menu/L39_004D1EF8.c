#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_004D1EF8);

/* localdecomp:start func_L39_004D1F30 */
extern s32 func_L39_004D1720(void *, void *, s32 *);
extern s32 func_L39_004D1B30(s32, void *, void *, void *);
extern s32 func_L39_004D1BB8(s32);

s32 func_L39_004D1F30(void *a, void *b, void *c, void *d, void *e)
{
    s32 t;

    if (func_L39_004D1720(b, d, &t) != 0 || func_L39_004D1B30(t, a, c, e) != 0) {
        return -1;
    }
    return func_L39_004D1BB8(t) != 0 ? -1 : 0;
}
/* localdecomp:end func_L39_004D1F30 */

INCLUDE_ASM("asm/levels", func_L39_004D1FB8);
