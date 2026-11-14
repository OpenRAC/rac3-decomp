#include "common.h"

typedef struct { u8 pad[4]; s16 f4; u8 pad6[0x76 - 6]; s16 f76; u8 pad78[0x98 - 0x78]; s16 f98; u8 pad9A[4]; s16 f9E; } S_001CCFD0_003AFF18;

/* localdecomp:start func_L03_003AF410 */
s32 func_L03_003AF410(void *arg0) {
    s32 temp_a0;

    temp_a0 = *(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x13C);
    switch (temp_a0) {                              /* irregular */
    case 4:
        return 4;
    case 6:
        return 3;
    default:
        return -1;
    }
}
/* localdecomp:end func_L03_003AF410 */

INCLUDE_ASM("asm/levels", func_L03_003AF450);
