#include "common.h"

/* localdecomp:start func_L39_005115B8 */
typedef struct { s32 cap; s32 n; unsigned long *d; } S_005115B8;
extern s32 func_L39_00512A40(s32, void *);

s32 func_L39_005115B8(u8 *buf, s32 len, void *rv) {
    S_005115B8 *r = rv;
    s32 words;
    s32 full;
    s32 j;
    s32 e;
    s32 i;
    s32 m;
    u8 *p;
    unsigned long *d;

    if (len == 0) {
        return 0x102;
    }
    i = (len + 7) / sizeof(unsigned long);
    words = i ? i : 1;
    full = len / sizeof(unsigned long);
    if (r->cap < words) {
        e = func_L39_00512A40(words + 1, r);
        if (e != 0) {
            return e;
        }
    }
    r->n = words;
    p = buf + len - 1;
    d = r->d;
    for (i = 0; i < full; i++) {
        *d = *p;
        for (j = 1; j < 8; j++) {
            *d |= (unsigned long) p[-j] << (j * 8);
        }
        p -= 8;
        d++;
    }
    m = full * 8;
    if (m < len) {
        m = len - m;
        *d = *p;
        for (j = 1; j < m; j++) {
            *d |= (unsigned long) p[-j] << (j * 8);
        }
    }
    while (r->d[r->n - 1] == 0 && r->n > 1) {
        r->n--;
    }
    return 0;
}
/* localdecomp:end func_L39_005115B8 */
