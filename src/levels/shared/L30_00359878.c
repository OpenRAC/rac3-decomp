#include "common.h"

INCLUDE_ASM("asm/levels", func_L30_00359878);

/* localdecomp:start func_L30_00359980 */
extern u8 *D_L30_001DF71C;
extern u32 D_00142BC8[];
extern u8 D_L30_001E8DC0[];
extern void func_L01_00456230(void *, s32);
extern void func_00392B20(void *, s32);
extern s32 func_00392C78(void *);

s32 func_L30_00359980(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    s32 i = *(s32 *)v;

    if (i != -1) {
        func_L01_00456230(D_L30_001DF71C + (i << 8), 1);
    }
    if (!(D_00142BC8[0] & 0x200)) {
        func_00392B20(D_L30_001E8DC0, 41);
        i = func_00392C78(D_L30_001E8DC0);
        *(s32 *)(v + 0xD4) = 1;
        return i;
    }
}
/* localdecomp:end func_L30_00359980 */
