#include "common.h"

INCLUDE_ASM("asm/levels", func_L23_003A2068);

INCLUDE_ASM("asm/levels", func_L23_003A2A08);

INCLUDE_ASM("asm/levels", func_L23_003A2E78);

INCLUDE_ASM("asm/levels", func_L23_003A2EF0);

/* localdecomp:start func_L23_003A2F68 */
void func_L23_004E3428(s32, s32);
extern s32 D_001A71A4[];

void func_L23_003A2F68(void *arg0, s32 arg1) {
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    if (D_001A71A4[0] != 0x74) {
        func_L23_004E3428(0x74, 1);
    }
    *(s32 *)((u8 *)temp_s0 + 0x64) = arg1;
}
/* localdecomp:end func_L23_003A2F68 */

INCLUDE_ASM("asm/levels", func_L23_003A2FB8);

INCLUDE_ASM("asm/levels", func_L23_003A3020);

INCLUDE_ASM("asm/levels", func_L23_003A31D8);

INCLUDE_ASM("asm/levels", func_L23_003A3860);

INCLUDE_ASM("asm/levels", func_L23_003A38C8);

/* localdecomp:start func_L23_003A3FC8 */
s32 func_L01_00516AA0(s32, s32, s32);

void func_L23_003A3FC8(s32 arg0, s32 arg1) {
    if (arg1 != 0) {
        func_L01_00516AA0(0x730000, 1, 1);
        return;
    }
    func_L01_00516AA0(0x730000, 1, 0);
}
/* localdecomp:end func_L23_003A3FC8 */

INCLUDE_ASM("asm/levels", func_L23_003A4008);
