#include "common.h"

/* localdecomp:start func_L39_004E2D20 */
extern void *func_L39_004BEED8(s32);
extern u8 D_0046D2B0[];

void *func_L39_004E2D20(void) {
    u8 *object = func_L39_004BEED8(0x10);
    if (object != 0) {
        *(s32 *)(object + 0xC) = 1;
        *(s32 *)object = (s32)D_0046D2B0;
        *(s32 *)(object + 4) = 0;
        *(s32 *)(object + 8) = 0;
        return object;
    }
    return 0;
}
/* localdecomp:end func_L39_004E2D20 */

INCLUDE_ASM("asm/levels", func_L39_004E2D68);

/* localdecomp:start func_L39_004E2DD0 */
typedef struct Type1 Type1;
typedef struct Type2 {
    s32 (*f0)(Type1 *arg0, s32 arg1, s32 arg2, s32 arg3);
} Type2;
struct Type1 {
    Type2 *f0;
};

/* from rac4-decomp's func_L00_0051EBD0, renamed */
s32 func_L39_004E2DD0(Type1 *arg0, Type2 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    arg0->f0 = arg1;
    return arg1->f0(arg0, arg2, arg3, arg4);
}
/* localdecomp:end func_L39_004E2DD0 */

INCLUDE_ASM("asm/levels", func_L39_004E2E00);

INCLUDE_ASM("asm/levels", func_L39_004E2E50);

INCLUDE_ASM("asm/levels", func_L39_004E2EA0);

INCLUDE_ASM("asm/levels", func_L39_004E2EF0);

INCLUDE_ASM("asm/levels", func_L39_004E2F40);

INCLUDE_ASM("asm/levels", func_L39_004E2F70);

INCLUDE_ASM("asm/levels", func_L39_004E2FC0);

/* localdecomp:start func_L39_004E3000 */
void func_L39_004E3000(void *arg0, s32 arg1, s32 arg2) {
    ((void (*)(void *, s32, s32, s32))(*(s32 *)(*(s32 *)arg0 + 0x18)))(arg0, 0x101, arg2, arg1);
}
/* localdecomp:end func_L39_004E3000 */

INCLUDE_ASM("asm/levels", func_L39_004E3028);

INCLUDE_ASM("asm/levels", func_L39_004E3050);

INCLUDE_ASM("asm/levels", func_L39_004E3060);

INCLUDE_ASM("asm/levels", func_L39_004E3748);

INCLUDE_ASM("asm/levels", func_L39_004E38F0);
