#include "common.h"

/* localdecomp:start func_L39_00511540 */
typedef struct { s32 cap; s32 n; unsigned long *d; } S_00511540;
s32 func_L39_00511540(S_00511540 *s) {
    unsigned long *d = s->d;
    if (d != 0) {
        s32 i = s->n - 1;
        s32 c = 1;
        unsigned long v = d[i] >> 1;
        while (v != 0) { v >>= 1; c++; }
        return i * 64 + c;
    }
    return 0;
}
/* localdecomp:end func_L39_00511540 */

LINKER_REMNANT("asm/levels", func_L39_005115A0);
