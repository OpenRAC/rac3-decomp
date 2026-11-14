#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_004BB4C0);

/* localdecomp:start func_L39_004BB528 */
typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    u8 pad10[0x4];
    s32 unk14;
    u8 pad18[0x4];
    s32 unk1C;
    s32 unk20;
} S_004BB528;

s32 func_L39_004BB528(S_004BB528 *arg0) {
    arg0->unkC = 0;
    arg0->unk1C = 0;
    arg0->unk20 = 0;
    arg0->unk14 = 0;
    return 1;
}
/* localdecomp:end func_L39_004BB528 */

INCLUDE_ASM("asm/levels", func_L39_004BB540);

INCLUDE_ASM("asm/levels", func_L39_004BB5A8);

INCLUDE_ASM("asm/levels", func_L39_004BB648);

INCLUDE_ASM("asm/levels", func_L39_004BB6D0);

INCLUDE_ASM("asm/levels", func_L39_004BB838);

/* localdecomp:start func_L39_004BB880 */
extern s32 D_L39_004433B8[];
extern void func_0011D534(void *, s32, s32);

void func_L39_004BB880(void) {
    func_0011D534(D_L39_004433B8, 0, 0xE8);
}
/* localdecomp:end func_L39_004BB880 */
