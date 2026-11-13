#include "common.h"

/* localdecomp:start func_L39_004E48E8 */
extern void *func_L39_004BEED8(s32);
extern void *func_L39_004BEF00(void *, s32, s32);
typedef struct { s32 pad0; s32 pad4; s32 cap; void *data; } S_004E48E8;
s32 func_L39_004E48E8(S_004E48E8 *a, s32 n) {
    void *p;
    if (n <= a->cap || n <= 0) {
        return 0;
    }
    if (a->data == 0) {
        p = func_L39_004BEED8(n * 4);
    } else {
        p = func_L39_004BEF00(a->data, n * 4, a->cap * 4);
    }
    if (p == 0) return 1;
    a->data = p;
    a->cap = n;
    return 0;
}
/* localdecomp:end func_L39_004E48E8 */
