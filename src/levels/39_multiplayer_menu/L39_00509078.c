#include "common.h"

/* localdecomp:start func_L39_00509078 */
typedef struct S_00509078 { void *data; s32 len; } S_00509078;
extern s32 func_L39_004F7560(void *, void *, long);
s32 func_L39_00509078(S_00509078 *a, S_00509078 *b) {
    s32 r = 0;
    s32 n = a->len;
    long len = n;
    if (n == b->len) {
        r = func_L39_004F7560(a->data, b->data, len) == 0;
    }
    return r;
}
/* localdecomp:end func_L39_00509078 */
