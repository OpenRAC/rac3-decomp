#include "common.h"

/* localdecomp:start func_L31_00346998 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x10];
    vu0_q pos;
} Src_00346998;

typedef struct {
    vu0_q pos;
    vu0_q vel;
    u8 pad20[0x8];
    s32 f28;
} Dst_00346998;

void func_L31_00346998(Src_00346998 *a, Dst_00346998 *b) {
    vu0_q pos = a->pos;

    b->f28 = 0;
    qzero(&b->vel);
    b->pos = pos;
}
/* localdecomp:end func_L31_00346998 */
