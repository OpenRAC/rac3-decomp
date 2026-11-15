#include "common.h"

/* declared by functions of L39_00510BA8.c, which this file was cut from */
typedef struct { s32 cap; s32 n; unsigned long *d; } S_00511540;
extern s32 func_L39_00511848(void *, u32, u32 *, u8 *);

/* localdecomp:start func_L39_00511848 */
s32 func_L39_00511848(void *arg0, u32 size, u32 *outLen, u8 *buf) {
    S_00511540 *a = arg0;
    s32 n = a->n;
    unsigned long *p;
    unsigned long v;
    s32 i;
    s32 k;
    u8 c;

    *outLen = n * 8;
    p = &a->d[n - 1];
    v = *p--;
    i = 7;
    c = (v >> 56) & 0xFF;
    if (c == 0) {
        do {
            i--;
            (*outLen)--;
            c = (v >> (i * 8)) & 0xFF;
        } while (i > 0 && c == 0);
        if (c == 0) {
            if (*outLen != 1) {
                return 0x104;
            }
            if (size < *outLen) {
                return 0x105;
            }
            *buf = 0;
            return 0;
        }
    }
    if (size < *outLen) {
        return 0x105;
    }
    *buf++ = c;
    for (k = i - 1; k >= 0; k--) {
        *buf++ = (v >> (k * 8)) & 0xFF;
    }
    for (i = 1; i < n; i++) {
        v = *p--;
        *buf++ = (v >> 56) & 0xFF;
        *buf++ = (v >> 48) & 0xFF;
        *buf++ = (v >> 40) & 0xFF;
        *buf++ = (v >> 32) & 0xFF;
        *buf++ = (v >> 24) & 0xFF;
        *buf++ = (v >> 16) & 0xFF;
        *buf++ = (v >> 8) & 0xFF;
        *buf++ = v & 0xFF;
    }
    return 0;
}
/* localdecomp:end func_L39_00511848 */

INCLUDE_ASM("asm/levels", func_L39_005119F0);
