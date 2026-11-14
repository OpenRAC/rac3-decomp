#include "common.h"

/* localdecomp:start func_L39_00515030 */
extern s32 func_L39_004F7538(void *, void *, s32);
typedef struct { s32 cap; s32 n; long *d; } S_00515030;

s32 func_L39_00515030(s32 arg0, S_00515030 *s) {
    long *d;
    s32 i = arg0 * 8;
    s32 n = s->n - arg0;
    s32 bytes = n * 8;

    s->n = n;
    if (n <= 0) {
        d = s->d;
        do {
            i = 1;
            s->n = i;
            *d = 0;
        } while (0);
        return 0;
    }
    d = s->d;
    func_L39_004F7538(d, (u8 *) d + i, bytes);
    return 0;
}
/* localdecomp:end func_L39_00515030 */

INCLUDE_ASM("asm/levels", func_L39_00515088);
