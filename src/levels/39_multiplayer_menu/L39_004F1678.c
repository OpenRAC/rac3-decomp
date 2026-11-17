#include "common.h"

/* localdecomp:start func_L39_004F1678 */
void func_L39_004F16C0(s32, s32);

void func_L39_004F1678(void *arg0, void *arg1) {
    func_L39_004F16C0((*(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 4))) + 0x14)), (*(s32 *)((u8 *)((*(void **)((u8 *)arg1 + 4))) + 0x14)));
}
/* localdecomp:end func_L39_004F1678 */

/* localdecomp:start func_L39_004F16A0 */
u8 *func_L39_004F16A0(void *arg0) {
    return *(u8 **)((u8 *)(*(void **)((u8 *)arg0 + 4)) + 0xC);
}
/* localdecomp:end func_L39_004F16A0 */

/* localdecomp:start func_L39_004F16B0 */
s32 func_L39_004F16B0(void *arg0) {
    return *(s32 *)((u8 *)(*(void **)((u8 *)arg0 + 4)) + 4);
}
/* localdecomp:end func_L39_004F16B0 */

INCLUDE_ASM("asm/levels", func_L39_004F16C0);
