/* near miss (level 7, Annihilation Nation): 2 differences: retail sets the call's 0 argument (move $a1,$zero) before lw $a3,0x68($t0); store order found, tried casts of the callee and locals for the arguments (8 wordings) */
#include "common.h"

/* localdecomp:start func_L07_003A8D70 */
extern u8 D_L07_001D66B0[];
extern void func_L01_004450F0(void *, s32, s32);
void func_L07_003A8D70(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    *(u128_t *)(arg0 + 0x10) = *(u128_t *)(p + 0xD0);
    *(u128_t *)(p + 0xD0) = *(u128_t *)D_L07_001D66B0;
    *(s32 *)(p + 0xC0) = 0;
    *(s16 *)(p + 0xC4) = 0;
    *(s16 *)(p + 0xC6) = 0;
    *(s32 *)(p + 0xC8) = 0;
    func_L01_004450F0(arg0, 0, -1);
}
/* localdecomp:end func_L07_003A8D70 */
