#include "common.h"

/* localdecomp:start func_L39_00517F48 */
typedef struct {
    char _p0[0x30];
    s32 count;
    s32 f34;
    unsigned long *stack;
    s32 f3C;
    s32 f40;
    s32 f44;
    unsigned long regs[16];
} S_00517F48;

s32 func_L39_00517F48(s32 a0, s32 *buf, s32 n) {
    S_00517F48 *p = (S_00517F48 *)a0;
    s32 i;
    if (p->count == 0) {
        return 4;
    }
    for (i = 0; i < n; i++) {
        s32 v = buf[i];
        if (v & 0x80) {
            p->count--;
            *(unsigned long *)((u8 *)p + (v & 0xF) * 8 + 0x48) = p->stack[p->count];
        }
    }
    return 0;
}
/* localdecomp:end func_L39_00517F48 */

/* localdecomp:start func_L39_00517FB8 */
extern s32 func_L39_00517E58(s32, s32 *, s32);
extern s32 func_L39_00517F48(s32, s32 *, s32);
s32 func_L39_00517FB8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 buf[3];
    s32 r;
    buf[0] = a2; buf[1] = a3; buf[2] = a4;
    if (a1 == 0) {
        r = func_L39_00517E58(a0, buf, 3);
        if (r != 0) return r;
    } else if (a1 == 1) {
        r = func_L39_00517F48(a0, buf, 3);
        if (r != 0) return r;
    } else {
        return 2;
    }
    return 0;
}
/* localdecomp:end func_L39_00517FB8 */

INCLUDE_ASM("asm/levels", func_L39_0051801C);
