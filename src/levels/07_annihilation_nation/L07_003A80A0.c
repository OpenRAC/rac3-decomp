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

INCLUDE_ASM("asm/levels", func_L07_003A8D70);
