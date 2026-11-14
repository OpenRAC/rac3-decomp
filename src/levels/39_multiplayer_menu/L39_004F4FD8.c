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
