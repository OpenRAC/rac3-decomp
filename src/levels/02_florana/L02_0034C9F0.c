#include "common.h"

INCLUDE_ASM("asm/levels", func_L02_0034C9F0);

INCLUDE_ASM("asm/levels", func_L02_0034CB58);

INCLUDE_ASM("asm/levels", func_L02_0034F710);

INCLUDE_ASM("asm/levels", func_L02_0034F958);

/* localdecomp:start func_L02_0034FC40 */
void func_L01_004443E8(s32, s32, s32);
void func_L01_00315900(s32, s32, s32);

void func_L02_0034FC40(void *arg0) {
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    func_L01_004443E8((s32) arg0, 0, 3);
    func_L01_00315900((*(s32 *)((u8 *)temp_s0 + 0x2EC)), 0, 0);
    *(s32 *)((u8 *)temp_s0 + 0x2EC) = 0;
}
/* localdecomp:end func_L02_0034FC40 */

INCLUDE_ASM("asm/levels", func_L02_0034FC88);
