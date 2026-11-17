#include "common.h"

/* localdecomp:start func_L39_004C2470 */
typedef struct {
    u8 pad0[0x28];
} S_004C2470;

extern S_004C2470 D_L39_00464AD0[];

u32 func_L39_004C2470(u32 n) {
    if (n < 0x23) {
        return (u32)&D_L39_00464AD0[(s32)(0x22 - n)];
    }
    return 0;
}
/* localdecomp:end func_L39_004C2470 */
