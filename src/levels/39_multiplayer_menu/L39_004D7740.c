#include "common.h"

/* localdecomp:start func_L39_004D7740 */
u32 func_L39_004B5910(u32);

typedef struct S_004D7740 { char pad[0x24]; u32 val; } S_004D7740;

void func_L39_004D7740(S_004D7740 *arg0, u32 arg1) {
    arg0->val = func_L39_004B5910(arg1);
}
/* localdecomp:end func_L39_004D7740 */

INCLUDE_ASM("asm/levels", func_L39_004D7770);

INCLUDE_ASM("asm/levels", func_L39_004D7B38);

/* localdecomp:start func_L39_004D8110 */
s32 func_L39_004D8110(u8 *arg0, u8 *arg1, u32 arg2) {
    u32 i;

    for (i = 0; i < arg2; i++) {
        if (arg0[i] < arg1[i]) {
            return -1;
        }
        if (arg1[i] < arg0[i]) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_004D8110 */

INCLUDE_ASM("asm/levels", func_L39_004D8168);

INCLUDE_ASM("asm/levels", func_L39_004D83E0);

INCLUDE_ASM("asm/levels", func_L39_004D8660);

INCLUDE_ASM("asm/levels", func_L39_004D8BC0);

INCLUDE_ASM("asm/levels", func_L39_004D8CB0);

INCLUDE_ASM("asm/levels", func_L39_004D8E10);

INCLUDE_ASM("asm/levels", func_L39_004D8F00);

/* localdecomp:start func_L39_004D8FD0 */
extern s32 D_L39_00464668[];
s32 func_L39_004CDC00(void);
s32 func_L39_004B4620(u8 *);
s32 func_L39_004B4700(u8 *);
s32 func_L39_004D8FD0(u8 *arg0, s32 arg1) {
    s32 ret = func_L39_004CDC00();
    u8 *p = arg0;
    s32 n;
    if (ret < 0) return ret;
    if (ret != 0 && !(D_L39_00464668[0] & 1)) p = arg0 + func_L39_004B4620(arg0);
    p += func_L39_004B4700(p);
    n = p - arg0;
    if (arg1 != n) return -0x6A;
    return n;
}
/* localdecomp:end func_L39_004D8FD0 */

INCLUDE_ASM("asm/levels", func_L39_004D9058);

INCLUDE_ASM("asm/levels", func_L39_004D9168);

INCLUDE_ASM("asm/levels", func_L39_004D9330);

INCLUDE_ASM("asm/levels", func_L39_004D9508);
