#include "common.h"

/* declared by functions of L39_004F5050.c, which this file was cut from */
extern void func_L39_004F7510(void *dst, const void *src, u32 n);

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
