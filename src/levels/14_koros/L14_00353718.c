#include "common.h"

/* localdecomp:start func_L14_00353718 */
extern s32 D_L14_001DD570;
extern s32 D_L14_001DD578;
extern s32 D_L14_001DD550;
extern s32 D_L14_001DD588;
extern s32 D_L14_001DD580;
extern s32 D_L14_001DD584;
extern void func_L14_003AD768(void *);
void func_L14_00353718(u8 *a0) {
    s32 *s = *(s32 **)(a0 + 0x68);
    s32 x, y;
    if (a0[0x20] == 0) {
        a0[0x20] = 1;
        x = D_L14_001DD580;
        y = D_L14_001DD584;
        s[5] = (s32)&D_L14_001DD570;
        s[4] = (s32)&D_L14_001DD578;
        s[3] = 2;
        s[1] = (s32)&D_L14_001DD550;
        s[7] = y;
        s[2] = (s32)&D_L14_001DD588;
        s[6] = x;
        s[0] = 0;
        s[8] = x;
    }
    func_L14_003AD768(a0);
}
/* localdecomp:end func_L14_00353718 */

INCLUDE_ASM("asm/levels", func_L14_00353790);

INCLUDE_ASM("asm/levels", func_L14_00353910);

INCLUDE_ASM("asm/levels", func_L14_003539E0);

INCLUDE_ASM("asm/levels", func_L14_00353BC8);

INCLUDE_ASM("asm/levels", func_L14_00353CD0);

INCLUDE_ASM("asm/levels", func_L14_00353DD8);
