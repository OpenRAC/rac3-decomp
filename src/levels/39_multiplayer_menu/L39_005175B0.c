#include "common.h"

/* localdecomp:start func_L39_005175B0 */
typedef struct {
    long f0;
    u8 *f8;
    u8 _pC[0xA];
    u8 f16;
    u8 f17;
} S_005175B0;

extern s32 func_L39_00517780(void *, s32);

s32 func_L39_005175B0(S_005175B0 *p, long *out) {
    u32 n;
    u8 *src;
    u32 c;
    u32 i;
    long v;
    s32 r;

    r = func_L39_00517780(p, 2);
    if (r != 0) {
        return r;
    }
    i = (p->f16 >> 2) & 1;
    n = (s32)p->f0;
    if (n == 0) {
        *out = 0;
        return 0;
    }
    if (n > 8) {
        return 9;
    }
    src = p->f8;
    if (i) {
        c = p->f17;
    } else {
        c = *src++;
    }
    v = (c & 0x80) ? -0x100 : 0;
    v |= c;
    for (i = 1; i < n; i++) {
        v = *src++ | (v << 8);
    }
    *out = v;
    return 0;
}
/* localdecomp:end func_L39_005175B0 */
