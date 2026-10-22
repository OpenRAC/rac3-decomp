#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003CC2B0);

INCLUDE_ASM("asm/levels", func_L07_003CCAF0);

INCLUDE_ASM("asm/levels", func_L07_003CCD40);

/* localdecomp:start func_L07_003CCDF8 */
void func_L07_003BB1F0();
void func_L07_003CD2E8(void *, s32);

void func_L07_003CCDF8(void *arg0) {
    void *temp_s1;

    temp_s1 = *(void **)((u8 *)arg0 + 0x68);
    func_L07_003BB1F0();
    *(s32 *)((u8 *)temp_s1 + 0x414) = 0;
    *(s8 *)((u8 *)temp_s1 + 0x406) = 0;
    *(s8 *)((u8 *)temp_s1 + 0x404) = 0;
    *(s8 *)((u8 *)temp_s1 + 0x405) = 0;
    *(s8 *)((u8 *)temp_s1 + 0x407) = 0;
    *(s32 *)((u8 *)temp_s1 + 0x410) = 0;
    *(s32 *)((u8 *)temp_s1 + 0x418) = -1;
    func_L07_003CD2E8(arg0, 0x19);
}
/* localdecomp:end func_L07_003CCDF8 */

/* localdecomp:start func_L07_003CCE58 */
s32 func_L07_003CCE58(void *arg0) {
    return (*(u8 *)((u8 *)arg0 + 0x20)) == 0x19;
}
/* localdecomp:end func_L07_003CCE58 */

INCLUDE_ASM("asm/levels", func_L07_003CCE68);

INCLUDE_ASM("asm/levels", func_L07_003CD2E8);

INCLUDE_ASM("asm/levels", func_L07_003CD610);

INCLUDE_ASM("asm/levels", func_L07_003CD6A8);

INCLUDE_ASM("asm/levels", func_L07_003CD7E0);

INCLUDE_ASM("asm/levels", func_L07_003CD938);

INCLUDE_ASM("asm/levels", func_L07_003CD9F8);

INCLUDE_ASM("asm/levels", func_L07_003CDB30);

INCLUDE_ASM("asm/levels", func_L07_003CDC48);

INCLUDE_ASM("asm/levels", func_L07_003CDC80);

INCLUDE_ASM("asm/levels", func_L07_003CDDC0);

INCLUDE_ASM("asm/levels", func_L07_003CDE10);
