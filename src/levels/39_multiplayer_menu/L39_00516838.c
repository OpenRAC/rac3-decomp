#include "common.h"

/* localdecomp:start func_L39_00516838 */
typedef struct {
    long count;
    s32 depth;
} C_00516838;

typedef struct {
    u8 _p0[0x10];
    u8 *f10;
    u8 _p14[0x48 - 0x14];
    long regs[16];
    s32 fC8;
    s32 fCC;
    s32 fD0;
    s32 fD4;
    C_00516838 *fD8;
} T_00516838;

typedef s32 (*F_00516838)(void *, s32, long *, long, long, long);

s32 func_L39_00516838(T_00516838 *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    C_00516838 *c = 0;
    long x, y, z;
    s32 sync;
    s32 r;

    if (a0->fC8 == 0) {
        return 2;
    }
    x = (a2 & 0x80) ? *(a0->regs + (a2 & 0xF)) : a2;
    y = (a3 & 0x80) ? *(a0->regs + (a3 & 0xF)) : a3;
    z = (a4 & 0x80) ? *(a0->regs + (a4 & 0xF)) : a4;
    if (a0->fD0 < 0) {
        a0->fD8 = 0;
    } else {
        a0->fD8 = (C_00516838 *)(a0->f10 + a0->fD0 * 0x28);
    }
    sync = a1 == 1;
    if (sync) {
        c = a0->fD8;
        if (c->count == 0) {
            return 3;
        }
        c->count--;
        c->depth++;
    }
    r = ((F_00516838)a0->fC8)(a0, a0->fCC, a0->regs, x, y, z);
    if (sync) {
        c->count++;
        c->depth--;
    }
    return r;
}
/* localdecomp:end func_L39_00516838 */

INCLUDE_ASM("asm/levels", func_L39_0051695C);

INCLUDE_ASM("asm/levels", func_L39_00516A84);

INCLUDE_ASM("asm/levels", func_L39_00516BB4);

INCLUDE_ASM("asm/levels", func_L39_00516CB8);

INCLUDE_ASM("asm/levels", func_L39_00516DC4);

INCLUDE_ASM("asm/levels", func_L39_00516E6C);

INCLUDE_ASM("asm/levels", func_L39_00516E78);

INCLUDE_ASM("asm/levels", func_L39_00516FC4);

INCLUDE_ASM("asm/levels", func_L39_00516FD8);
