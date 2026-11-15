#include "common.h"

/* localdecomp:start func_L39_004C41D0 */
typedef struct {
    char _p0[0x3C];
    s32 (*f3C)(void *, u8 *);
} V_004C41D0;
typedef struct {
    char _p0[0x8];
    V_004C41D0 *f8;
} S_004C41D0;
typedef struct {
    s32 count;
    void **items;
} L_004C41D0;

s32 func_L39_004C41D0(S_004C41D0 *arg0, L_004C41D0 *list, u8 *buf) {
    u8 *start;
    s32 i;

    if (list == 0) {
        return 0;
    }
    start = buf;
    for (i = 0; i < list->count; i++) {
        s32 n = arg0->f8->f3C(list->items[i], buf);
        if (buf != 0) {
            buf += n;
        }
    }
    return buf - start;
}
/* localdecomp:end func_L39_004C41D0 */
