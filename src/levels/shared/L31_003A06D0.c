#include "common.h"

INCLUDE_ASM("asm/levels", func_L31_003A06D0);

/* localdecomp:start func_L31_003A0C88 */
extern s32 D_L31_001DE734;
__asm__(".extern D_L31_001DE734, 4");
extern s32 D_L31_001DF340 __attribute__((section(".data")));
extern f32 D_L31_001DE738;
__asm__(".extern D_L31_001DE738, 4");
extern f32 D_L31_001DE73C;
__asm__(".extern D_L31_001DE73C, 4");
extern f32 func_0038D098(f32);
extern s32 func_0038DBD8(f32, s32, s32);
extern void func_L30_0034CF28(void *, void *, s32, f32, f32);

void func_L31_003A0C88(char *a0) {
    char *s0 = *(char **)(a0 + 0x68);
    f32 t = func_0038D098((f32)(D_L31_001DF340 % D_L31_001DE734) * 6.2831855f / (f32)D_L31_001DE734);
    s32 c = func_0038DBD8(t * 0.5f + 0.5f, *(s32 *)(s0 + 0x44), *(s32 *)(s0 + 0x4C));
    func_L30_0034CF28(a0 + 0x10, s0 + 0x54, c, D_L31_001DE738, D_L31_001DE73C);
}
/* localdecomp:end func_L31_003A0C88 */
