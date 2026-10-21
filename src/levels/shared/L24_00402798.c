#include "common.h"

/* localdecomp:start func_L24_00402798 */
extern u8 D_L24_001D67CC;
extern f32 D_L24_001D67D0;
extern f32 D_L24_001E6DF0[];

s32 func_L24_00402798(void) {
    if (D_L24_001D67CC != 0) {
        return 0;
    }
    D_L24_001D67CC = 1;
    D_L24_001D67D0 = D_L24_001E6DF0[0];
    return 1;
}
/* localdecomp:end func_L24_00402798 */

/* localdecomp:start func_L24_004027C8 */
extern unsigned char D_L24_001D67CC;
extern float D_L24_001D67D0;
extern float D_L24_001E6DF0[];
extern void func_003873C0(void);
int func_L24_004027C8(void)
{
    int r;
    if (D_L24_001D67CC != 0) {
        D_L24_001E6DF0[0] = D_L24_001D67D0;
        func_003873C0();
        D_L24_001D67CC = 0;
        r = 1;
    } else {
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L24_004027C8 */

INCLUDE_ASM("asm/levels", func_L24_00402808);

LINKER_REMNANT("asm/levels", func_L24_00402838);
