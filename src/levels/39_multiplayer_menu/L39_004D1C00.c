#include "common.h"

/* localdecomp:start func_L39_004D1C00 */
s32 func_L39_004D1C00(s32 a0) {
    return func_L39_004D1BB8(a0);
}
/* localdecomp:end func_L39_004D1C00 */

/* localdecomp:start func_L39_004D1C18 */
extern s32 func_L39_004D0EF8(s32, s32 *);
extern s32 func_L39_004D13F8(s32, s32, s32, s32);
s32 func_L39_004D1C18(s32 a0, s32 a1, s32 a2, s32 a3)
{
    s32 t;

    if (func_L39_004D0EF8(a1, &t) != 0 || func_L39_004D13F8(t, a0, a2, a3) != 0) {
        return -1;
    }
    return func_L39_004D1480(t) ? -1 : 0;
}
/* localdecomp:end func_L39_004D1C18 */

/* localdecomp:start func_L39_004D1CA0 */
extern s32 func_L39_004D1630(s32, s32 *);
extern s32 func_L39_004D1B30(s32, s32, s32, s32);
s32 func_L39_004D1CA0(s32 a0, s32 a1, s32 a2, s32 a3)
{
    s32 t;

    if (func_L39_004D1630(a1, &t) != 0 || func_L39_004D1B30(t, a0, a2, a3) != 0) {
        return -1;
    }
    return func_L39_004D1BB8(t) ? -1 : 0;
}
/* localdecomp:end func_L39_004D1CA0 */

INCLUDE_ASM("asm/levels", func_L39_004D1D28);

/* localdecomp:start func_L39_004D1DC8 */
extern s32 func_L39_004D1268(s32, s32, s32, s32, s32 *);
extern s32 func_L39_004D1460(s32, s32, s32, s32);
extern s32 func_L39_004D14C8(s32);
s32 func_L39_004D1DC8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6)
{
    s32 t;

    if (func_L39_004D1268(a1, a2, a3, a5, &t) != 0 || func_L39_004D1460(t, a0, a4, a6) != 0) {
        return -1;
    }
    return func_L39_004D14C8(t) ? -1 : 0;
}
/* localdecomp:end func_L39_004D1DC8 */

/* localdecomp:start func_L39_004D1E58 */
extern s32 func_L39_004D19A0(s32, s32, s32, s32, s32 *);
extern s32 func_L39_004D1B98(s32, s32, s32, s32);
extern s32 func_L39_004D1C00(s32);
s32 func_L39_004D1E58(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6)
{
    s32 t;

    if (func_L39_004D19A0(a1, a2, a3, a5, &t) != 0 || func_L39_004D1B98(t, a0, a4, a6) != 0) {
        return -1;
    }
    return func_L39_004D1C00(t) ? -1 : 0;
}
/* localdecomp:end func_L39_004D1E58 */
