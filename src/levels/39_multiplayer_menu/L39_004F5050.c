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

INCLUDE_ASM("asm/levels", func_L39_004F5100);

INCLUDE_ASM("asm/levels", func_L39_004F5320);

/* localdecomp:start func_L39_004F5540 */
typedef struct S_004F5540 { void *src; void *dst; s32 pad; u32 n; } S_004F5540;
extern void func_L39_004F7510(void *dst, const void *src, u32 n);

s32 func_L39_004F5540(S_004F5540 *p) {
    func_L39_004F7510(p->dst, p->src, p->n);
    return 0;
}
/* localdecomp:end func_L39_004F5540 */

/* localdecomp:start func_L39_004F5570 */
typedef struct S_004F5570 { u8 pad[0xC]; s32 v; } S_004F5570;
s32 func_L39_004F5570(S_004F5570 *a, s32 *out) {
    s32 v = a->v;
    *out = v;
    return v == 0 ? 0xB : 0;
}
/* localdecomp:end func_L39_004F5570 */
