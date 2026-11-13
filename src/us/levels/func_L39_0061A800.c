#include "common.h"

/* localdecomp:start func_L39_0061A800 */
typedef struct {
    u8 pad_0[0x12C];
    s32 count;                  /* 0x12C */
    u8 pad_130[0x148 - 0x130];
    s32 list[1];                /* 0x148 */
} S_61A800;

extern S_61A800 D_001A5E50;

s32 func_L39_0061A800(s32 value) {
    s32 i;
    for (i = 0; i < D_001A5E50.count; i++) {
        if (D_001A5E50.list[i] == value) return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_0061A800 */
