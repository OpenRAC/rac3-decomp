#include "common.h"

/* localdecomp:start func_L39_004C2468 */
s32 func_L39_004C2468(void) {
    return 0x23;
}
/* localdecomp:end func_L39_004C2468 */

INCLUDE_ASM("asm/levels", func_L39_004C2470);

/* localdecomp:start func_L39_004C24A8 */
typedef struct {
    u8 pad0[0xB8];
    s32 fB8;
} S_004C24A8_inner;

typedef struct {
    u8 pad0[0x38];
    s32 f38;
    u8 pad3C[0x18];
    S_004C24A8_inner *f54;
} S_004C24A8;

s32 func_L39_004C24A8(S_004C24A8 *arg0) {
    if (arg0->f38 != 0xF1) {
        return arg0->f54->fB8;
    }
    return 0;
}
/* localdecomp:end func_L39_004C24A8 */
