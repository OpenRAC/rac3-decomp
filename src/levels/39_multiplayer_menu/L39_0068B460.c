#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0068B460);

INCLUDE_ASM("asm/levels", func_L39_0068B478);

INCLUDE_ASM("asm/levels", func_L39_0068B4D0);

LINKER_REMNANT("asm/levels", func_L39_0068B688);

INCLUDE_ASM("asm/levels", func_L39_0068B690);

/* localdecomp:start func_L39_0068B6B8 */
s32 func_00381FF0(s32);
void func_L39_0067F100(s32);
void func_L39_00689BD8(void *, s32);
void func_L39_00689D28(void *, s32);
void func_L39_00689DB8(void *, s32);
void func_L39_0068A9B8(s32);
void func_L39_0068AAB8(void *);
void func_L39_0068C718(void *);

void func_L39_0068B6B8(void *arg0) {
    func_L39_0067F100(0x210000);
    func_L39_0068A9B8(0);
    func_L39_00689BD8(arg0, func_00381FF0(0x10C7));
    func_L39_00689D28(arg0, func_00381FF0(0x124));
    func_L39_00689DB8(arg0, func_00381FF0(0xCD5));
    func_L39_0068AAB8(arg0);
    *(s32 *)((u8 *)arg0 + 0x338) = 0;
    func_L39_0068C718(arg0);
}
/* localdecomp:end func_L39_0068B6B8 */
