#include "common.h"

/* localdecomp:start func_L39_004F55A0 */
typedef struct S_004F55A0 { void *a; void *b; void *c; s32 n; } S_004F55A0;
extern void func_L39_004F74E8(void *, s32, s32);
extern void func_L39_004F7620(void *);

s32 func_L39_004F55A0(S_004F55A0 *p) {
    if (p == 0) {
        return 0;
    }
    if (p->c != 0) {
        func_L39_004F74E8(p->c, 0, p->n);
        func_L39_004F7620(p->c);
    }
    if (p->a != 0) {
        func_L39_004F74E8(p->a, 0, p->n);
        func_L39_004F7620(p->a);
    }
    if (p->b == 0) {
        return 0;
    }
    func_L39_004F74E8(p->b, 0, p->n);
    func_L39_004F7620(p->b);
    return 0;
}
/* localdecomp:end func_L39_004F55A0 */

/* localdecomp:start func_L39_004F5630 */
typedef struct S_004F5630 { void *buf; s32 pad[2]; u32 n; } S_004F5630;
typedef struct S2_004F5630 { void *buf; u32 n; } S2_004F5630;
extern void func_L39_004F7510(void *dst, const void *src, u32 n);

s32 func_L39_004F5630(S_004F5630 *a, S2_004F5630 *b) {
    if (a->n != b->n) {
        return 6;
    }
    func_L39_004F7510(a->buf, b->buf, a->n);
    return 0;
}
/* localdecomp:end func_L39_004F5630 */
