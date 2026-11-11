/* near miss (level 7, Annihilation Nation): 10 differences: register choice (retail p in $a2, table base in $a3, 2 and 0x16 swapped between $t0/$t1); the callee reads only two arguments (6 wordings) */
#include "common.h"

/* localdecomp:start func_L07_003B6AE8 */
typedef int u128_t __attribute__((mode(TI)));
extern void func_L07_003B64D0(u8 *, s32);
extern u8 *D_L07_001DF500_003B6AE8;
__asm__(".extern D_L07_001DF500_003B6AE8, 16");
void func_L07_003B6AE8(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    p[0x324] = 0;
    *(u128_t *)(p + 0x2F0) = *(u128_t *)((*(s32 *)(p + 0x30C) << 7) + D_L07_001DF500_003B6AE8 + 0x30);
    p[0x323] = 2;
    p[0x322] = 0x16;
    func_L07_003B64D0(arg0, 0x13);
}
/* localdecomp:end func_L07_003B6AE8 */
