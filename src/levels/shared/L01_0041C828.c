#include "common.h"

/* localdecomp:start func_L01_0041C828 */
typedef struct {
    u8 pad[16];
    void (*fn)(void *);
    u8 pad2[124];
} Entry_41A120;
extern Entry_41A120 D_L01_002E60D0[];
s32 func_L01_0041C828(s32 a0) {
    Entry_41A120 *p = &D_L01_002E60D0[a0 & 0xF];
    s32 r = 0;
    if (p != 0 && p->fn != 0) {
        p->fn(p);
        r = 1;
    }
    return r;
}
/* localdecomp:end func_L01_0041C828 */
