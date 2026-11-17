#include "common.h"

/* declared by functions of L39_00510BA8.c, which this file was cut from */
extern void func_L39_004F74E8(void *, s32, s32);
typedef struct { s32 cap; s32 n; long *d; } S_00510EF0;

/* declared by functions of L39_00511A50.c, which this file was cut from */
extern s32 func_L39_00512620(void *, s32 *, s32 **, s32 *, s32 *);
extern void func_L39_004F74E8(void *, s32, s32);
extern void *func_L39_004F7590(s32);

/* localdecomp:start func_L39_00512620 */
extern s32 func_L39_00511540(void *);
extern s32 func_L39_00512778(s32);
extern void *func_L39_004F7590(s32);
extern void func_L39_004F74E8(void *, s32, s32);
extern s32 func_L39_005127B8(void *, s32, s32, s32 *, s32 *);

s32 func_L39_00512620(void *m, s32 *bits, s32 **tab, s32 *n, s32 *w) {
    s32 maxv = 0;
    s32 ret;
    s32 len;
    s32 k;
    s32 i;
    s32 val;
    s32 sz;

    do {
        if (*tab != 0) {
            ret = 0x104;
            break;
        }
        len = func_L39_00511540(m);
        k = func_L39_00512778(len);
        *bits = k;
        *n = ((len + k - 2) / k) * 2 + 2;
        *tab = func_L39_004F7590(*n * 4);
        if (*tab == 0) {
            *n = 0;
            ret = 0x100;
            break;
        }
        func_L39_004F74E8(*tab, 0, *n * 4);
        len -= 2;
        i = 0;
        do {
            ret = func_L39_005127B8(m, len, *bits, &val, &sz);
            if (ret != 0) {
                break;
            }
            len -= val;
            (*tab)[i] = val;
            (*tab)[i + 1] = sz;
            if (maxv < sz) {
                maxv = sz;
            }
            i += 2;
        } while (len >= 0);
    } while (0);
    *w = maxv;
    return ret;
}
/* localdecomp:end func_L39_00512620 */
