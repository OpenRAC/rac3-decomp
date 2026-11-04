#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003ADF68);

INCLUDE_ASM("asm/levels", func_L07_003AE410);

INCLUDE_ASM("asm/levels", func_L07_003AE618);

INCLUDE_ASM("asm/levels", func_L07_003AEAA0);

/* localdecomp:start func_L07_003AECA8 */
void func_L07_00334740();
void func_L07_003AEAA0(s32, s32);

void func_L07_003AECA8(s32 arg0) {
    func_L07_00334740();
    func_L07_003AEAA0(arg0, 1);
}
/* localdecomp:end func_L07_003AECA8 */

INCLUDE_ASM("asm/levels", func_L07_003AECD8);

/* localdecomp:start func_L07_003AED20 */
s32 func_L07_00331008(s32, s32);
void func_L07_003310E8(s32, s32);
void func_L07_003AEAA0(s32, s32);

s32 func_L07_003AED20(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);

    if (func_L07_00331008(*(s32 *)(p + 0x240), (s32)arg0) != 0) {
        return 1;
    }
    func_L07_003310E8(*(s32 *)(p + 0x240), (s32)arg0);
    func_L07_003AEAA0((s32)arg0, 6);
    return 0;
}
/* localdecomp:end func_L07_003AED20 */

INCLUDE_ASM("asm/levels", func_L07_003AED80);
