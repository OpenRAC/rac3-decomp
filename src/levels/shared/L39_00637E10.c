#include "common.h"

/* declared by functions of L39_00637D38.c, which this file was cut from */
extern void func_L39_00637E10(void *);

INCLUDE_ASM("asm/levels", func_L39_00637E10);

INCLUDE_ASM("asm/levels", func_L39_00637EC8);

/* localdecomp:start func_L39_00638458 */
#include "vu0.h"

extern void func_L39_006384B0(void *);

void func_L39_00638458(u8 *a0) {
    qzero(a0 + 0x140);
    func_L39_006384B0(a0);
    *(s32 *)(a0 + 0x1A0) = 0;
    *(s32 *)(a0 + 0xFD4) = 0;
    *(s32 *)(a0 + 0x1A8) = 0;
    qzero(a0 + 0x120);
    qzero(a0 + 0x140);
    qzero(a0 + 0x150);
    qzero(a0 + 0x160);
    qzero(a0 + 0x190);
    qzero(a0 + 0xC0);
    qzero(a0 + 0x130);
}
/* localdecomp:end func_L39_00638458 */
