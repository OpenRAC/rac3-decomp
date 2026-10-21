#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00563370);

INCLUDE_ASM("asm/levels", func_L39_005635D0);

/* localdecomp:start func_L39_00563DB8 */
extern s32 D_L39_00241128[];
extern s32 D_L39_001DFE04;
extern f32 func_L01_004C93D8(void);
extern s32 func_L39_00565008(u8 *, f32);
extern void func_003C2F58(s32, s32, u8 *);
extern void func_L39_00563E40(u8 *);
extern void func_L39_005640A0(u8 *);
extern void func_L39_00564498(u8 *);

void func_L39_00563DB8(u8 *arg0)
{
    u8 *v;

    if (D_L39_00241128[0] == 0) {
        v = *(u8 **)(arg0 + 104);
        if (func_L39_00565008(arg0, func_L01_004C93D8()) && D_L39_001DFE04 != 40) {
            func_003C2F58(*(s32 *)(*(u8 **)(v + 64) + 9508), 10, v + 48);
            func_L39_00563E40(arg0);
            func_L39_005640A0(arg0);
            func_L39_00564498(arg0);
        }
    }
}
/* localdecomp:end func_L39_00563DB8 */

INCLUDE_ASM("asm/levels", func_L39_00563E40);

INCLUDE_ASM("asm/levels", func_L39_005640A0);

INCLUDE_ASM("asm/levels", func_L39_00564498);

INCLUDE_ASM("asm/levels", func_L39_00564800);
