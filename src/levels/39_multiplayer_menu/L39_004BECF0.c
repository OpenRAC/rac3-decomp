#include "common.h"

/* localdecomp:start func_L39_004BECF0 */
extern s32 func_L39_004BECC0(void);
extern s32 (*D_L39_0046481C)(s32 *, s32, s32, char *, s32) __attribute__((section(".data")));

s32 func_L39_004BECF0(void *p, s32 delta, s32 a2, char *a3, s32 a4) {
    s32 *q = p;
    s32 ret;

    if (D_L39_0046481C != 0) {
        ret = D_L39_0046481C(q, delta, a2, a3, a4);
    } else {
        if (((s32 (*)(s32, s32, char *, s32))func_L39_004BECC0)(9, a2, a3, a4) == 0) {
            ret = -1;
        } else {
            ret = *q + delta;
            *q = ret;
            if (((s32 (*)(s32, s32, char *, s32))func_L39_004BECC0)(10, a2, a3, a4) == 0) {
                ret = -1;
            }
        }
    }
    return ret;
}
/* localdecomp:end func_L39_004BECF0 */

LINKER_REMNANT("asm/levels", func_L39_004BEDA8);

/* localdecomp:start func_L39_004BEDB0 */
extern s32 func_00126A28(void);
extern s64 (*D_L39_00464820)(void) __attribute__((section(".data")));

s64 func_L39_004BEDB0(void) {
    s64 ret;

    if (D_L39_00464820 == 0) {
        ret = func_00126A28();
    } else {
        ret = D_L39_00464820();
    }
    return ret;
}
/* localdecomp:end func_L39_004BEDB0 */

/* localdecomp:start func_L39_004BEDE8 */
extern s32 D_L39_00464898 __attribute__((section(".data")));

/* OpenSSL's CRYPTO_mem_ctrl */
s32 func_L39_004BEDE8(s32 mode) {
    s32 ret = D_L39_00464898;

    switch (mode) {
    case 1:
        D_L39_00464898 |= 1;
        break;
    case 0:
        D_L39_00464898 &= ~1;
        break;
    case 3:
        D_L39_00464898 &= ~2;
        break;
    case 2:
        if (D_L39_00464898 & 1) {
            D_L39_00464898 |= 2;
        }
        break;
    case 8:
        ret = D_L39_00464898;
        break;
    default:
        break;
    }
    return ret;
}
/* localdecomp:end func_L39_004BEDE8 */
