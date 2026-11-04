#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0051F740);

INCLUDE_ASM("asm/levels", func_L39_0051FC18);

INCLUDE_ASM("asm/levels", func_L39_0051FD90);

INCLUDE_ASM("asm/levels", func_L39_00520350);

INCLUDE_ASM("asm/levels", func_L39_005203E0);

INCLUDE_ASM("asm/levels", func_L39_00520630);

INCLUDE_ASM("asm/levels", func_L39_00520870);

INCLUDE_ASM("asm/levels", func_L39_005210A0);

INCLUDE_ASM("asm/levels", func_L39_00521BC0);

INCLUDE_ASM("asm/levels", func_L39_00521DE8);

INCLUDE_ASM("asm/levels", func_L39_00521FE0);

INCLUDE_ASM("asm/levels", func_L39_00522248);

INCLUDE_ASM("asm/levels", func_L39_00522328);

/* localdecomp:start func_L39_00522EE8 */
extern s32 func_0019D510();
extern void func_L39_005237D0(char *object, char *entry);
extern void func_L01_00466F50(char *a, char *b, s32 c, f32 d, f32 e);

void func_L39_00522EE8(char *object)
{
    char *state = *(char **)(object + 0x68);
    int first = *(int *)(state + 0x38);
    int last = *(int *)(state + 0x34);
    int end;
    int index;
    int random;

    end = first + 2;
    index = end - last;
    if (index <= -1)
        index += 0x23;

    random = func_0019D510();
    if (random % 7 == 0)
        func_L39_005237D0(object, *(char **)(state + 0x5C) + (index << 6));

    random = func_0019D510();
    if (random % 0x16 == 0) {
        char *entry = *(char **)(state + 0x5C) + (index << 6);
        func_L01_00466F50(entry, entry + 0x10, 0, -1.0f, 0.0f);
    }
}
/* localdecomp:end func_L39_00522EE8 */

INCLUDE_ASM("asm/levels", func_L39_00522FA8);

INCLUDE_ASM("asm/levels", func_L39_005236F0);

INCLUDE_ASM("asm/levels", func_L39_005237D0);

INCLUDE_ASM("asm/levels", func_L39_00523860);

INCLUDE_ASM("asm/levels", func_L39_00523948);
