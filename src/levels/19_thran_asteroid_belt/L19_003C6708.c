#include "common.h"

INCLUDE_ASM("asm/levels", func_L19_003C6708);

INCLUDE_ASM("asm/levels", func_L19_003C6F18);

INCLUDE_ASM("asm/levels", func_L19_003C6F30);

/* localdecomp:start func_L19_003C7058 */
/* m2c3 */
s32 func_L01_0042B068(s32, s32);            /* extern */
s32 func_L01_004ED658(s32);                     /* extern */
s32 func_L01_004F50C8(s32, s32, s32, s32);  /* extern */
s32 func_L01_00504E38(s32);                     /* extern */
extern s32 D_001DF800;

void func_L19_003C7058(void *arg0) {
    s32 temp_4;
    void *temp_16;

    temp_16 = (*(void **)((u8 *)(arg0) + 0x68));
    func_L01_004ED658(0);
    func_L01_0042B068(0, 0);
    temp_4 = D_001DF800 + ((*(s32 *)((u8 *)(temp_16) + 0x1C)) << 7);
    func_L01_004F50C8(temp_4 + 0x30, temp_4 + 0x70, -1, 1);
    func_L01_00504E38(0);
}
/* localdecomp:end func_L19_003C7058 */

INCLUDE_ASM("asm/levels", func_L19_003C70C0);
