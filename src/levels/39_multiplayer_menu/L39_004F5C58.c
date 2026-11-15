#include "common.h"

/* localdecomp:start func_L39_004F5C58 */
typedef struct S_004F5C58 { void *buf; u32 n; } S_004F5C58;
extern void func_L39_004F74E8(void *, s32, u32);
extern void func_L39_004F7620(void *);

s32 func_L39_004F5C58(S_004F5C58 *p) {
    if (p == 0) {
        return 0;
    }
    if (p->buf != 0) {
        func_L39_004F74E8(p->buf, 0, p->n);
        func_L39_004F7620(p->buf);
    }
    return 0;
}
/* localdecomp:end func_L39_004F5C58 */
