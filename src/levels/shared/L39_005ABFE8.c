#include "common.h"

/* localdecomp:start func_L39_005ABFE8 */
/* from rac2-decomp's func_002A0300 */
__asm__(".extern D_L39_0024BF58, 16");
extern void func_003A9440(s32, unsigned long);
extern void func_001264E0(s32);
extern void func_003C3690(void);
extern void func_003C3660(void);
extern s32 func_L39_005B25C8(void *, void *, s32, s32);
extern char *D_L39_0024BF58;
extern s32 D_L39_0024BF58_gp_005ABFE8 __attribute__((section(".sdata")));

void func_L39_005ABFE8(void *object, s32 mode)
{
    func_003A9440(0x47, 0x5360B);
    func_001264E0(0);
    func_003C3690();
    D_L39_0024BF58_gp_005ABFE8 = func_L39_005B25C8(object, D_L39_0024BF58, mode, 0);
    func_003C3660();
    D_L39_0024BF58 -= 0x10;
}
/* localdecomp:end func_L39_005ABFE8 */
