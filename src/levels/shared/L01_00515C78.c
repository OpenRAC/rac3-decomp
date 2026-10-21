#include "common.h"

/* localdecomp:start func_L01_00515C78 */
typedef struct {
    u8 pad[80];
    s32 items[4];
    s32 count;
} Unk00511CA0;

s32 func_L01_00515C78(Unk00511CA0 **a0, s32 a1) {
    Unk00511CA0 *p = a0[1];
    if (p->count >= 4) {
        return 0;
    }
    p->items[p->count] = a1;
    a0[1]->count++;
    return 1;
}
/* localdecomp:end func_L01_00515C78 */

LINKER_REMNANT("asm/levels", func_L01_00515CB8);
