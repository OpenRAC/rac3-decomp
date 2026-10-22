#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003BEAC0);

INCLUDE_ASM("asm/levels", func_L07_003BEB50);

INCLUDE_ASM("asm/levels", func_L07_003BEE80);

INCLUDE_ASM("asm/levels", func_L07_003BF158);

/* localdecomp:start func_L07_003BF2D0 */
void func_L07_003BF2D0(void *arg0) {
    void *temp_a0;

    temp_a0 = *(*(void ***)((u8 *)arg0 + 0x68));
    if (temp_a0 != 0) {
        func_L07_003BF2D0(temp_a0);
    }
    *(u16 *)((u8 *)arg0 + 0x34) = (u16) ((*(u16 *)((u8 *)arg0 + 0x34)) & 0xFFFE);
}
/* localdecomp:end func_L07_003BF2D0 */

INCLUDE_ASM("asm/levels", func_L07_003BF318);

/* localdecomp:start func_L07_003BF368 */
void func_003C2880(void *);

void func_L07_003BF368(void *arg0) {
    void *temp_a0;

    temp_a0 = *(*(void ***)((u8 *)arg0 + 0x68));
    if (temp_a0 != 0) {
        func_L07_003BF368(temp_a0);
    }
    func_003C2880(arg0);
}
/* localdecomp:end func_L07_003BF368 */

INCLUDE_ASM("asm/levels", func_L07_003BF3A8);

INCLUDE_ASM("asm/levels", func_L07_003BF480);

INCLUDE_ASM("asm/levels", func_L07_003BF838);

INCLUDE_ASM("asm/levels", func_L07_003BF8A8);

INCLUDE_ASM("asm/levels", func_L07_003BFAE8);
