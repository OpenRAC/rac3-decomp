#include "common.h"
#include "vu0.h"


/* localdecomp:start func_L32_003A0BB8 */
extern f32 D_L32_001DE6D4;
extern f32 D_L32_001DE6C8;
void func_L32_003A25B0(void *, f32, f32);
void func_L32_003A2508(void *, s32, f32);
void func_L32_003A14C8(void *, s32);

void func_L32_003A0BB8(void *arg0) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);

    func_L32_003A25B0(arg0, D_L32_001DE6D4, D_L32_001DE6C8);
    func_L32_003A2508(arg0, 0, 0.0f);
    if (p[0x228] != 0) {
        func_L32_003A14C8(arg0, 1);
    }
}
/* localdecomp:end func_L32_003A0BB8 */

INCLUDE_ASM("asm/levels", func_L32_003A0C18);
