#include "common.h"

/* declared by functions of L39_004DB038.c, which this file was cut from */
extern void func_L39_005042F8(void *);

/* localdecomp:start func_L39_004DD520 */
void func_L39_004E2DD0(s32, s32, s32, s32, s32);
s32 func_L39_004E2F70(s32, s32, s32 *, s32, s32, s32, s32);

s32 func_L39_004DD520(s32 arg0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 *arg5) {
    s32 out;
    s32 ret;

    if (!(arg5[5] & 0x100)) {
        arg5[5] |= 0x100;
        func_L39_004E2DD0(arg5[3], arg5[2], arg5[1], 0, 0);
    }
    ret = func_L39_004E2F70(arg5[3], arg0, &out, arg2, arg3, arg4, 0);
    if (arg1 != 0) {
        *arg1 = out;
    }
    return ret ? 0 : out;
}
/* localdecomp:end func_L39_004DD520 */

/* localdecomp:start func_L39_004DD5E0 */
s32 func_L39_004E4688(s32, s32, s32);
void func_L39_004E4A50(s32, s32, s32, s32);
void func_L39_004DD250(void *);

void *func_L39_004DD5E0(s32 *arg0) {
    s32 *p = ((s32 *(*)(s32))func_L39_005042F8)(arg0[2]);

    if (p != 0) {
        if (func_L39_004E4688(p[1], arg0[1], 0x12) != 0) {
            func_L39_004E4A50(p[1], 0x12, 3, 0);
            func_L39_004E4A50(p[1], 0x12, 4, 0);
            return p;
        }
        func_L39_004DD250(p);
    }
    return 0;
}
/* localdecomp:end func_L39_004DD5E0 */

INCLUDE_ASM("asm/levels", func_L39_004DD668);

/* localdecomp:start func_L39_004DD690 */
extern void func_L39_004BC6C8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_L39_004BEF28(void *);
extern void *func_L39_004BEED8(s32);
extern void func_0011D534(void *, s32, s32);

typedef struct {
    char _p0[0xC];
    void (*fC)(void *);
    char _p10[0x38 - 0x10];
    s32 f38;
    void (*f3C)(void *, s32);
    s32 f40;
} S2_004DD690;
typedef struct {
    S2_004DD690 *f0;
    char _p4[4];
    s32 f8;
    void *fC;
} S1_004DD690;

s32 func_L39_004DD690(S1_004DD690 *arg0, S2_004DD690 *arg1) {
    if (arg1 == 0) {
        arg1 = arg0->f0;
    } else {
        arg0->f0 = arg1;
    }
    if (arg1 == 0) {
        func_L39_004BC6C8(6, 0x71, 0x75, 0, 0);
        return 0;
    }
    if (arg0->fC == 0 || arg0->f8 < arg1->f38) {
        if (arg0->fC != 0) {
            func_L39_004BEF28(arg0->fC);
        }
        arg0->fC = func_L39_004BEED8(arg1->f38);
        if (arg0->fC == 0) {
            func_L39_004BC6C8(6, 0x71, 0x21, 0, 0);
            return 0;
        }
        func_0011D534(arg0->fC, 0, arg1->f38);
    }
    arg0->f8 = arg1->f38;
    if (arg1->f3C != 0) {
        arg1->f3C(arg0->fC, arg1->f40);
    }
    arg1->fC(arg0->fC);
    return 1;
}
/* localdecomp:end func_L39_004DD690 */
