#include "common.h"

/* localdecomp:start func_L39_0066C748 */
typedef struct {
    u8 pad0[0x18];
    s32 index;
    s32 f1C;
    s32 f20;
    u8 pad24[0x20];
    s32 f44;
} S_0066C748;

extern S_0066C748 D_L39_00343318[];

void func_L39_0066C748(S_0066C748 *entry) {
    s32 index = entry - D_L39_00343318;
    entry->f44 = -1;
    entry->f1C = 0;
    entry->f20 = 0;
    entry->index = index;
}
/* localdecomp:end func_L39_0066C748 */
