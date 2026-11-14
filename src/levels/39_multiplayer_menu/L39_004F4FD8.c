#include "common.h"

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

INCLUDE_ASM("asm/levels", func_L39_004F5040);

INCLUDE_ASM("asm/levels", func_L39_004F5050);

INCLUDE_ASM("asm/levels", func_L39_004F5100);

INCLUDE_ASM("asm/levels", func_L39_004F5320);

INCLUDE_ASM("asm/levels", func_L39_004F5540);

INCLUDE_ASM("asm/levels", func_L39_004F5570);

INCLUDE_ASM("asm/levels", func_L39_004F5588);

INCLUDE_ASM("asm/levels", func_L39_004F55A0);

INCLUDE_ASM("asm/levels", func_L39_004F5630);

INCLUDE_ASM("asm/levels", func_L39_004F5670);

INCLUDE_ASM("asm/levels", func_L39_004F5680);

INCLUDE_ASM("asm/levels", func_L39_004F56A0);

INCLUDE_ASM("asm/levels", func_L39_004F56C0);

INCLUDE_ASM("asm/levels", func_L39_004F56C8);

INCLUDE_ASM("asm/levels", func_L39_004F56D8);

INCLUDE_ASM("asm/levels", func_L39_004F56E8);

INCLUDE_ASM("asm/levels", func_L39_004F5708);

INCLUDE_ASM("asm/levels", func_L39_004F5728);

INCLUDE_ASM("asm/levels", func_L39_004F5730);

INCLUDE_ASM("asm/levels", func_L39_004F5740);

INCLUDE_ASM("asm/levels", func_L39_004F5750);

INCLUDE_ASM("asm/levels", func_L39_004F57A0);

INCLUDE_ASM("asm/levels", func_L39_004F57C0);

INCLUDE_ASM("asm/levels", func_L39_004F57C8);

INCLUDE_ASM("asm/levels", func_L39_004F57D8);

INCLUDE_ASM("asm/levels", func_L39_004F57E8);

INCLUDE_ASM("asm/levels", func_L39_004F5838);

INCLUDE_ASM("asm/levels", func_L39_004F5858);

INCLUDE_ASM("asm/levels", func_L39_004F5860);

INCLUDE_ASM("asm/levels", func_L39_004F5870);

INCLUDE_ASM("asm/levels", func_L39_004F5880);

INCLUDE_ASM("asm/levels", func_L39_004F58D0);

INCLUDE_ASM("asm/levels", func_L39_004F5A78);

INCLUDE_ASM("asm/levels", func_L39_004F5C20);

INCLUDE_ASM("asm/levels", func_L39_004F5C28);

INCLUDE_ASM("asm/levels", func_L39_004F5C40);

INCLUDE_ASM("asm/levels", func_L39_004F5C58);

INCLUDE_ASM("asm/levels", func_L39_004F5CA8);
