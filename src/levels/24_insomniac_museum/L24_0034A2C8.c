#include "common.h"

INCLUDE_ASM("asm/levels", func_L24_0034A2C8);

INCLUDE_ASM("asm/levels", func_L24_0034AA48);

INCLUDE_ASM("asm/levels", func_L24_0034AE40);

INCLUDE_ASM("asm/levels", func_L24_0034AF10);

INCLUDE_ASM("asm/levels", func_L24_0034AFF0);

INCLUDE_ASM("asm/levels", func_L24_0034B930);

INCLUDE_ASM("asm/levels", func_L24_0034BA30);

INCLUDE_ASM("asm/levels", func_L24_0034BBD8);

INCLUDE_ASM("asm/levels", func_L24_0034BC48);

INCLUDE_ASM("asm/levels", func_L24_0034BF38);

INCLUDE_ASM("asm/levels", func_L24_0034C088);

INCLUDE_ASM("asm/levels", func_L24_0034C208);

INCLUDE_ASM("asm/levels", func_L24_0034C348);

INCLUDE_ASM("asm/levels", func_L24_0034C618);

INCLUDE_ASM("asm/levels", func_L24_0034C7A8);

INCLUDE_ASM("asm/levels", func_L24_0034C8D0);

/* localdecomp:start func_L24_0034CCA0 */
void func_0038CAD0(s32);
void func_0038CB00(s32);

void func_L24_0034CCA0(void *arg0) {
    s32 temp_s0;
    u16 temp_v1;

    temp_s0 = *(s32 *)((u8 *)arg0 + 0x68);
    func_0038CAD0(temp_s0 + 0x4B0);
    func_0038CB00(temp_s0 + 0x4B4);
    temp_v1 = *(u16 *)((u8 *)arg0 + 0x96);
    if (temp_v1 <= 0xFFFEU) {
        *(u16 *)((u8 *)arg0 + 0x96) = (u16) (temp_v1 + 1);
    }
}
/* localdecomp:end func_L24_0034CCA0 */
