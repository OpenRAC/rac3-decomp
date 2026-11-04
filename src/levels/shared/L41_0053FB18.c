#include "common.h"

/* localdecomp:start func_L41_0053FB18 */
extern void *func_L39_0066C2B8(void);
extern s32 func_L39_0066C280(s32, s32, s32, s32, void *);
extern s32 D_001A5DF8[];

s32 func_L41_0053FB18(s32 a0, s32 a1, s32 *a2) {
    u8 *n;
    s32 *dst;
    s32 cnt;
    s32 *src;
    s32 off;

    cnt = a1;
    src = a2;
    if (cnt < 0) {
        return -1;
    }
    n = func_L39_0066C2B8();
    if (n == 0) {
        return -1;
    }
    off = func_L39_0066C280(3, a0, D_001A5DF8[0], cnt, n);
    dst = (s32 *)(n + off);
    if (cnt > 0) {
        s32 *p = src;
        s32 k = cnt;
        do {
            *dst++ = *p++;
        } while (--k != 0);
    }
    *(s32 *)n = (s32)dst - (s32)n;
    return a0;
}
/* localdecomp:end func_L41_0053FB18 */
