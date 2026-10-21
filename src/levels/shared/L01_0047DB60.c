#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_0047DB60);

/* localdecomp:start func_L01_0047DB70 */
typedef struct {
    u8 pad0[0x50];
    s32 x50[1];
} D_002E9FD8_t;
extern D_002E9FD8_t D_L01_002E9F98;

s32 func_L01_0047DB70(s32 i) {
    return D_L01_002E9F98.x50[i];
}
/* localdecomp:end func_L01_0047DB70 */
