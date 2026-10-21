#include "common.h"

/* NTSC-U version of func_003BE3B8 (frontbin): 5 -> 6; 250 -> 300 */
/* localdecomp:start func_U_003B8EC0 */
extern void func_U_003B6528(s32, s32);
extern void func_U_00385B60(s32);
extern s32 D_U_001DA340;
__asm__(".extern D_U_001DA340, 16");
s32 func_U_003B8EC0(void) {
    func_U_003B6528(0, 0);
    func_U_00385B60(6);
    D_U_001DA340 = 300;
    return 1;
}
/* localdecomp:end func_U_003B8EC0 */
