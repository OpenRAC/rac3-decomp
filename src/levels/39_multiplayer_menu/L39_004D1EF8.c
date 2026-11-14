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

/* localdecomp:start func_L39_004D1FB8 */
extern s32 func_L39_004D19A0(s32, s32, s32, s32, s32 *);
extern s32 func_L39_004D1B98(s32, s32, s32, s32);
extern s32 func_L39_004D1C00(s32);

s32 func_L39_004D1FB8(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g)
{
    s32 t;

    if (func_L39_004D19A0(b, c, d, f, &t) != 0 || func_L39_004D1B98(t, a, e, g) != 0) {
        return -1;
    }
    return func_L39_004D1C00(t) != 0 ? -1 : 0;
}
/* localdecomp:end func_L39_004D1FB8 */

LINKER_REMNANT("asm/levels", func_L39_004D2048);
