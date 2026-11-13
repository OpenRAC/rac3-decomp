/* near miss (level 10, Zeldrin Starport): 1 difference: the jr $ra delay slot (sw $a2,0xC($v1)) at 0x004B0000 is catalogued as a function of its own, func_L10_004B0000 (4 bytes), so the catalogue size (0x10) cuts it and the C is one instruction longer; every other word is retail's. The inventory takes the delay slot for a start because a data word points at it (tools/inventory.py, the 'after finished code' rule accepts w[k] == jr $ra). With the catalogue fixed, this C covers both entries */
#include "common.h"

/* localdecomp:start func_L10_004AFFF0 */
void func_L10_004AFFF0(u8 *a0, s32 a1, s32 a2) {
    *(s32 *)(*(u8 **)(a0 + 0xC) + 8) = a1;
    *(s32 *)(*(u8 **)(a0 + 0xC) + 0xC) = a2;
}
/* localdecomp:end func_L10_004AFFF0 */
