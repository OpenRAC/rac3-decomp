#include "common.h"

/* localdecomp:start func_L39_004C4198 */
typedef struct {
    char _p0[0x14];
    s32 f14;
} T_004C4198;
typedef struct {
    char _p0[0x64];
    s32 f64;
    char _p68[0xDC - 0x68];
    T_004C4198 *fDC;
} S_004C4198;

s32 func_L39_004C4198(S_004C4198 *arg0) {
    T_004C4198 *p;
    s32 w;

    if (arg0 != 0) {
        if (arg0->f64 != 0) {
            return arg0->f64;
        }
        p = arg0->fDC;
        if (p != 0) {
            w = p->f14;
            if (w != 0) {
                return w;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L39_004C4198 */

INCLUDE_ASM("asm/levels", func_L39_004C41D0);
