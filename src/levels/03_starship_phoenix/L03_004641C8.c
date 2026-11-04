#include "common.h"

/* localdecomp:start func_L03_004641C8 */
extern f32 func_0038CF00(void *, void *);

f32 func_L03_004641C8(unsigned char *a0) {
    unsigned char *s2;
    unsigned char *q;
    s32 s0, s1, n;
    f32 f20;
    f32 f0;

    s2 = a0;
    f20 = 0.0f;
    if (s2 == 0) {
        return -1.0f;
    }
    n = *(s32 *)s2;
    if (n <= 0) {
        return f20;
    }
    s0 = 0;
    do {
        s1 = s0 + 1;
        f0 = func_0038CF00(s2 + 0x10 + (s0 << 4), s2 + 0x10 + ((s1 % n) << 4));
        q = s2 + (s0 << 4);
        *(f32 *)(q + 0x1C) = f0;
        f20 += f0;
        s0 = s1;
        n = *(s32 *)s2;
    } while (s0 < n);
    return f20;
}
/* localdecomp:end func_L03_004641C8 */

LINKER_REMNANT("asm/levels", func_L03_00464270);
