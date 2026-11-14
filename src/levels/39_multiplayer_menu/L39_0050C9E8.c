#include "common.h"

/* localdecomp:start func_L39_0050C9E8 */
typedef struct {
    char _p0[0x30];
    u8 *f30;
} S_0050C9E8;
typedef struct {
    u8 *f0;
    u32 f4;
} O_0050C9E8;

s32 func_L39_0050C9E8(S_0050C9E8 *s, O_0050C9E8 *out, u32 n) {
    u8 *p = s->f30;
    u32 i;

    if (p[0] != 0 || p[1] != 1) {
        return 0x20C;
    }
    for (i = 2; i < n; i++) {
        if (p[i] != 0xFF) {
            break;
        }
    }
    i++;
    if (i > n || p[i - 1] != 0) {
        return 0x20C;
    }
    out->f4 = n - i;
    out->f0 = s->f30 + i;
    return 0;
}
/* localdecomp:end func_L39_0050C9E8 */

LINKER_REMNANT("asm/levels", func_L39_0050CA78);

INCLUDE_ASM("asm/levels", func_L39_0050CA80);
