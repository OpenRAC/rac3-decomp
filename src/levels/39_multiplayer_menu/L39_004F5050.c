#include "common.h"

/* localdecomp:start func_L39_004F5050 */
typedef struct S_004F5050 { void *a; void *b; void *c; s32 n; } S_004F5050;
typedef struct S2_004F5050 { void *key; s32 n; } S2_004F5050;
extern void *func_L39_004F7590(void *n);
extern void func_L39_004F7510(void *dst, const void *src, u32 n);

s32 func_L39_004F5050(S_004F5050 *p, s32 unused, S2_004F5050 *q) {
    s32 n = q->n;
    p->n = n;
    if ((p->a = func_L39_004F7590((void *)n)) == 0) {
        return 0x10;
    }
    if ((p->b = func_L39_004F7590((void *)n)) == 0) {
        return 0x10;
    }
    if ((p->c = func_L39_004F7590((void *)n)) == 0) {
        return 0x10;
    }
    func_L39_004F7510(p->a, q->key, n);
    func_L39_004F7510(p->b, q->key, n);
    return 0;
}
/* localdecomp:end func_L39_004F5050 */
