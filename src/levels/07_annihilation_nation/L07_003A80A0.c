#include "common.h"

INCLUDE_ASM("asm/levels", func_L07_003A80A0);

INCLUDE_ASM("asm/levels", func_L07_003A8538);

INCLUDE_ASM("asm/levels", func_L07_003A8908);

/* localdecomp:start func_L07_003A8D58 */
typedef int u128_t __attribute__((mode(TI)));
void func_L07_003A8D58(void *arg0, s16 arg1, s32 arg2) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    *(u128_t *)(p + 0xD0) = *(u128_t *)((u8 *)arg0 + 0x10);
    *(s16 *)(p + 0xC6) = arg1;
    *(s32 *)(p + 0xC8) = arg2;
}
/* localdecomp:end func_L07_003A8D58 */

/* localdecomp:start func_L07_003A8D70 */
extern u8 D_L07_001D66B0[] __attribute__((section(".sdata")));
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
