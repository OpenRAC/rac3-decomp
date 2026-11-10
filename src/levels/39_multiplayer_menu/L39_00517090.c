#include "common.h"

/* localdecomp:start func_L39_00517090 */
typedef struct { char _p0[0xC]; void *fC; char _p10[0x20]; u8 f30[8]; } S_00517090;
extern u8 D_L39_0046F4B0[];
extern void func_L39_0050C4B0(void *, s32, s32, s32);
extern void func_L39_004F74E8(void *, s32, s32);
void func_L39_00517090(S_00517090 *a0, s32 a1, s32 a2) {
    func_L39_0050C4B0(a0, a1, a2, 0);
    func_L39_004F74E8(a0->f30, 0, sizeof(a0->f30));
    a0->fC = D_L39_0046F4B0;
}
/* localdecomp:end func_L39_00517090 */

INCLUDE_ASM("asm/levels", func_L39_005170D8);
