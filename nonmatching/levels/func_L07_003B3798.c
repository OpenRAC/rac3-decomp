/* near miss (level 7, Annihilation Nation): 11 differences: retail copies arg0 to $v0, keeps 5 in $t0 and builds the selector as move $a1,$a3 + movn; tried a shared constant variable, a ternary and an if (4 wordings) */
#include "common.h"

/* localdecomp:start func_L07_003B3798 */
extern void func_L07_003B37D0(u8 *, s32, u8 *, s32);
void func_L07_003B3798(u8 *arg0, u8 arg1) {
    u8 *p = *(u8 **)(arg0 + 0x68);
    s32 k = 4;
    s32 s;
    arg0[0x95] = arg1;
    s = k;
    if (p[0x1AE]) s = 5;
    func_L07_003B37D0(arg0, s, p, k);
}
/* localdecomp:end func_L07_003B3798 */
