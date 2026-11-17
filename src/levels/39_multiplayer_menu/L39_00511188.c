#include "common.h"

/* localdecomp:start func_L39_00511188 */
typedef struct {
    s32 cap;
    s32 count;
    unsigned long *words;
} S_00511188_Big;

extern s32 func_L39_00512948(s32, S_00511188_Big *);

s32 func_L39_00511188(unsigned long w, S_00511188_Big *b) {
    unsigned long *words = b->words;
    s32 i;
    s32 n;
    s32 ret;

    words[0] += w;
    if (words[0] >= w) {
        return 0;
    }
    n = b->count;
    for (i = 1; i < n; i++) {
        if (++words[i] != 0) {
            return 0;
        }
    }
    n++;
    if (b->cap < n) {
        ret = func_L39_00512948(n + 1, b);
        if (ret != 0) {
            return ret;
        }
    }
    b->words[i] = 1;
    b->count = n;
    return 0;
}
/* localdecomp:end func_L39_00511188 */

INCLUDE_ASM("asm/levels", func_L39_00511268);

/* localdecomp:start func_L39_00511480 */
typedef struct {
    s32 unk0;
    s32 count;
    unsigned long *words;
} S_00511480_Big;

s32 func_L39_00511480(unsigned long arg0, S_00511480_Big *arg1) {
    unsigned long *words = arg1->words;
    s32 i;
    s32 n;

    if (words[0] >= arg0) {
        words[0] -= arg0;
        return 0;
    }
    words[0] -= arg0;
    n = arg1->count - 1;
    i = 1;
    if (i <= n) {
        if (--words[i] == (unsigned long)-1) {
            while (++i <= n) {
                if (--words[i] != (unsigned long)-1) {
                    break;
                }
            }
        }
    }
    if (i < n) {
        return 0;
    }
    if (i > n) {
        return 0x109;
    }
    if (words[i] == 0) {
        arg1->count--;
    }
    return 0;
}
/* localdecomp:end func_L39_00511480 */
