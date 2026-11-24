#include "common.h"
/* localdecomp:start func_L39_00512CB0 */
typedef struct Big_00512CB0 {
    s32 cap;
    s32 count;
    unsigned long *words;
} Big_00512CB0;

extern s32 func_L39_00512A40(s32, Big_00512CB0 *);
extern s32 func_L39_00510EF0(Big_00512CB0 *, Big_00512CB0 *);
extern s32 func_L39_00514CF8(s32, Big_00512CB0 *);
extern void func_L39_005128F8(Big_00512CB0 *);

s32 func_L39_00512CB0(Big_00512CB0 *a, Big_00512CB0 *b, Big_00512CB0 *out) {
    Big_00512CB0 tmp;
    Big_00512CB0 *t;
    s32 n = b->count;
    s32 i;
    s32 ret;
    s32 m;

    if (n < a->count) {
        return 0x108;
    }
    if (n == a->count) {
        for (i = n - 1; i >= 0; i--) {
            if (b->words[i] != a->words[i]) {
                break;
            }
        }
        if (i < 0) {
            return 0x108;
        }
        if (b->words[i] < a->words[i]) {
            return 0x108;
        }
    }
    do { m = n * 2; } while (0);
    t = &tmp;
    m += 1;
    func_L39_005128E8((s32 *)t);
    ret = func_L39_00512A40(m, t);
    if (ret == 0) {
        ret = func_L39_00510EF0(a, t);
        if (ret == 0) {
            ret = func_L39_00514CF8(n, t);
            if (ret == 0) {
                ret = func_L39_00513808(t, b, out);
            }
        }
    }
    func_L39_005128F8(t);
    return ret;
}
/* localdecomp:end func_L39_00512CB0 */
