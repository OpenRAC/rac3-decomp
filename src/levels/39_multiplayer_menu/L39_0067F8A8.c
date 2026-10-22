#include "common.h"

LINKER_REMNANT("asm/levels", func_L39_0067F8A8);

/* localdecomp:start func_L39_0067F8B0 */
void func_00120D28(s32, s32, s32);
void func_L39_0067F8B0(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        func_00120D28(arg0 + 0x14, arg1, 0x33);
        *(s8 *)((u8 *)arg0 + 0x47) = 0;
    }
}
/* localdecomp:end func_L39_0067F8B0 */

INCLUDE_ASM("asm/levels", func_L39_0067F8E8);

/* localdecomp:start func_L39_0067F968 */
void func_L39_0067F968(void *arg0, f32 *arg1, f32 *arg2) {
    *arg1 = *(f32 *)((u8 *)arg0 + 0x58);
    *arg2 = *(f32 *)((u8 *)arg0 + 0x5C);
}
/* localdecomp:end func_L39_0067F968 */

INCLUDE_ASM("asm/levels", func_L39_0067F980);
