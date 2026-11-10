#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_004F4E58);

INCLUDE_ASM("asm/levels", func_L39_004F4EB8);

INCLUDE_ASM("asm/levels", func_L39_004F4EE8);

INCLUDE_ASM("asm/levels", func_L39_004F4F18);

INCLUDE_ASM("asm/levels", func_L39_004F4F68);

/* localdecomp:start func_L39_004F4FD8 */
extern s32 D_L39_0046D814[];
typedef struct S_004F4FD8 { u8 pad[0x30]; s32 *a; struct S_004F4FD8 *b; } S_004F4FD8;

s32 func_L39_004F4FD8(S_004F4FD8 *p) {
    s32 r;

    if (p == 0) goto fail;
    if (p->b != p) goto fail;
    r = 0;
    if (p->b->a == D_L39_0046D814) goto done;
fail:
    r = 0x204;
done:
    return r;
}
/* localdecomp:end func_L39_004F4FD8 */

INCLUDE_ASM("asm/levels", func_L39_004F5010);

INCLUDE_ASM("asm/levels", func_L39_004F5CB0);

INCLUDE_ASM("asm/levels", func_L39_004F5CE8);

INCLUDE_ASM("asm/levels", func_L39_004F5D38);

/* localdecomp:start func_L39_004F5D60 */
s32 func_L39_004F5D38(void);

/* from rac4-decomp's func_003FE5B0, renamed */
s32 func_L39_004F5D60(void *arg0) {
    s32 var_v0;
    var_v0 = func_L39_004F5D38();
    if (var_v0 != 0) {
        return var_v0;
    }
    var_v0 = (*(s32 *)((u8 *)arg0 + 0x2C) & 1) ? 0 : 0x202;
    return var_v0;
}
/* localdecomp:end func_L39_004F5D60 */

INCLUDE_ASM("asm/levels", func_L39_004F5DA0);

INCLUDE_ASM("asm/levels", func_L39_004F5E70);

INCLUDE_ASM("asm/levels", func_L39_004F5EA0);

INCLUDE_ASM("asm/levels", func_L39_004F5F38);

INCLUDE_ASM("asm/levels", func_L39_004F5F80);

INCLUDE_ASM("asm/levels", func_L39_004F5FA0);

INCLUDE_ASM("asm/levels", func_L39_004F5FC8);

INCLUDE_ASM("asm/levels", func_L39_004F6060);

INCLUDE_ASM("asm/levels", func_L39_004F60D8);

INCLUDE_ASM("asm/levels", func_L39_004F6130);

INCLUDE_ASM("asm/levels", func_L39_004F6198);

INCLUDE_ASM("asm/levels", func_L39_004F62B0);

INCLUDE_ASM("asm/levels", func_L39_004F6368);

INCLUDE_ASM("asm/levels", func_L39_004F63B8);

INCLUDE_ASM("asm/levels", func_L39_004F6420);

INCLUDE_ASM("asm/levels", func_L39_004F66E8);

INCLUDE_ASM("asm/levels", func_L39_004F6A30);

INCLUDE_ASM("asm/levels", func_L39_004F6A80);

INCLUDE_ASM("asm/levels", func_L39_004F6B10);

INCLUDE_ASM("asm/levels", func_L39_004F6BF0);

INCLUDE_ASM("asm/levels", func_L39_004F6CA8);

INCLUDE_ASM("asm/levels", func_L39_004F6D38);

INCLUDE_ASM("asm/levels", func_L39_004F6E18);

INCLUDE_ASM("asm/levels", func_L39_004F6ED0);

INCLUDE_ASM("asm/levels", func_L39_004F6F38);

INCLUDE_ASM("asm/levels", func_L39_004F6FA0);

INCLUDE_ASM("asm/levels", func_L39_004F7018);

INCLUDE_ASM("asm/levels", func_L39_004F7320);

INCLUDE_ASM("asm/levels", func_L39_004F73F0);

INCLUDE_ASM("asm/levels", func_L39_004F7460);

INCLUDE_ASM("asm/levels", func_L39_004F74E8);

INCLUDE_ASM("asm/levels", func_L39_004F7510);

INCLUDE_ASM("asm/levels", func_L39_004F7538);

INCLUDE_ASM("asm/levels", func_L39_004F7560);

INCLUDE_ASM("asm/levels", func_L39_004F7590);

INCLUDE_ASM("asm/levels", func_L39_004F75B0);

INCLUDE_ASM("asm/levels", func_L39_004F7620);

INCLUDE_ASM("asm/levels", func_L39_004F7648);

INCLUDE_ASM("asm/levels", func_L39_004F7660);

INCLUDE_ASM("asm/levels", func_L39_004F7678);

INCLUDE_ASM("asm/levels", func_L39_004F7890);

INCLUDE_ASM("asm/levels", func_L39_004F7968);

INCLUDE_ASM("asm/levels", func_L39_004F7A20);

INCLUDE_ASM("asm/levels", func_L39_004F8148);

INCLUDE_ASM("asm/levels", func_L39_004F8220);

INCLUDE_ASM("asm/levels", func_L39_004F82C0);

INCLUDE_ASM("asm/levels", func_L39_004F8360);

INCLUDE_ASM("asm/levels", func_L39_004F841C);

INCLUDE_ASM("asm/levels", func_L39_004F84DC);

INCLUDE_ASM("asm/levels", func_L39_004F85B4);

INCLUDE_ASM("asm/levels", func_L39_004F868C);

INCLUDE_ASM("asm/levels", func_L39_004F879C);

INCLUDE_ASM("asm/levels", func_L39_004F88C8);
