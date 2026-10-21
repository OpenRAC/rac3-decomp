#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_005C34A8);

/* localdecomp:start func_L39_005C3E30 */
extern void func_L39_005C34A8(u8 *, u8 *, s32);
void func_L39_005C3E30(u8 *a0) {
    s32 n;
    *(s32 *)(a0 + 416) = 0;
    *(s32 *)(a0 + 428) = *(s32 *)(a0 + 840);
    *(s32 *)(a0 + 444) = *(s32 *)(a0 + 432);
    *(s32 *)(a0 + 432) = 0;
    if (*(s32 *)(a0 + 408) != 0 && a0[1396] == 0) {
        n = (a0[1397] & 0xF) * 2 + 2;
        if (n > 20) {
            n = 20;
        }
        func_L39_005C34A8(a0, a0 + 1396, n);
    }
}
/* localdecomp:end func_L39_005C3E30 */

INCLUDE_ASM("asm/levels", func_L39_005C3EA0);
