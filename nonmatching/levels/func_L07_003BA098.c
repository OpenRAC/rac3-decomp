/* near miss (level 7, Annihilation Nation): 7 differences, the same as func_L07_003A6EA8 (one source with another offset) */
#include "common.h"

/* localdecomp:start func_L07_003BA098 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_L07_001D66B0[];
extern void func_L01_004450F0(void *, s32, s32);
void func_L07_003BA098(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    if (*(s32 *)(p + 0x70) != -1) {
        *(u128_t *)(arg0 + 0x10) = *(u128_t *)(p + 0x80);
        *(u128_t *)(p + 0x80) = *(u128_t *)D_L07_001D66B0;
        *(s32 *)(p + 0x70) = -1;
        func_L01_004450F0(arg0, 0, -1);
    }
}
/* localdecomp:end func_L07_003BA098 */
