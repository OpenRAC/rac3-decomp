#include "common.h"

/* declared by functions of L39_004D7740.c, which this file was cut from */
extern void func_L39_004BC6C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void *func_L39_004DBA08(void);

/* localdecomp:start func_L39_004DD858 */
void func_L39_004BC6C8(s32, s32, s32, s32, s32);
void *func_L39_004DBA08(void);
s32 func_L39_004DD858(s32 arg0) {
    s32 (*fn)(s32) = *(s32 (**)(s32))((u8 *)func_L39_004DBA08() + 0x28);
    if (fn == 0) {
        func_L39_004BC6C8(0xA, 0x6B, 0xE, 0, 0);
        return -1;
    }
    return fn(arg0);
}
/* localdecomp:end func_L39_004DD858 */

INCLUDE_ASM("asm/levels", func_L39_004DD8B0);

INCLUDE_ASM("asm/levels", func_L39_004DD938);

INCLUDE_ASM("asm/levels", func_L39_004DDA88);

INCLUDE_ASM("asm/levels", func_L39_004DDAE8);

INCLUDE_ASM("asm/levels", func_L39_004DDBF0);

INCLUDE_ASM("asm/levels", func_L39_004DDD68);

INCLUDE_ASM("asm/levels", func_L39_004DDDD8);

INCLUDE_ASM("asm/levels", func_L39_004DDEE0);

INCLUDE_ASM("asm/levels", func_L39_004DDFB0);

INCLUDE_ASM("asm/levels", func_L39_004DDFC8);

INCLUDE_ASM("asm/levels", func_L39_004DE050);

INCLUDE_ASM("asm/levels", func_L39_004DE0C8);

INCLUDE_ASM("asm/levels", func_L39_004DE0F0);

INCLUDE_ASM("asm/levels", func_L39_004DE120);

INCLUDE_ASM("asm/levels", func_L39_004DE150);

INCLUDE_ASM("asm/levels", func_L39_004DE280);

INCLUDE_ASM("asm/levels", func_L39_004DE348);

INCLUDE_ASM("asm/levels", func_L39_004DE458);

INCLUDE_ASM("asm/levels", func_L39_004DE550);

INCLUDE_ASM("asm/levels", func_L39_004DE5D0);

INCLUDE_ASM("asm/levels", func_L39_004DE650);

INCLUDE_ASM("asm/levels", func_L39_004DE6D0);

INCLUDE_ASM("asm/levels", func_L39_004DE828);

INCLUDE_ASM("asm/levels", func_L39_004DE868);
