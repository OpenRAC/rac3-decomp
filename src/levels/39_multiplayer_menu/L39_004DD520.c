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

INCLUDE_ASM("asm/levels", func_L39_004DD690);
