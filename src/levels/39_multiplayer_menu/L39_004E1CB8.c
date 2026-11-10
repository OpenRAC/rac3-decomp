#include "common.h"

/* localdecomp:start func_L39_004E1CB8 */
extern void func_L39_004BC6C8(s32, s32, s32, s32, s32);

s32 func_L39_004E1CB8(u8 **arg0, u8 *arg1, s32 arg2) {
    u8 *p;
    s32 i;
    s32 v;
    u8 *q;
    s32 len;
    u8 t;

    p = *arg0;
    for (i = 0; i < arg2; i++) {
        arg1[i] = 0;
    }
    len = arg2 * 2;
    for (i = 0; i < len; i++) {
        if ((u8)(*p - '0') < 10) {
            v = *p - '0';
        } else if ((u8)(*p - 'A') < 6) {
            v = *p - 'A' + 10;
        } else if ((u8)(*p - 'a') < 6) {
            v = *p - 'a' + 10;
        } else {
            func_L39_004BC6C8(9, 0x65, 0x67, 0, 0);
            return 0;
        }
        p++;
        q = &arg1[i / 2];
        t = *q;
        if (i % 2 == 0) {
            *q = t | (v << 4);
        } else {
            *q = t | v;
        }
    }
    *arg0 = p;
    return 1;
}
/* localdecomp:end func_L39_004E1CB8 */

INCLUDE_ASM("asm/levels", func_L39_004E1DC8);

INCLUDE_ASM("asm/levels", func_L39_004E2398);

INCLUDE_ASM("asm/levels", func_L39_004E23D8);

INCLUDE_ASM("asm/levels", func_L39_004E2440);

INCLUDE_ASM("asm/levels", func_L39_004E2450);
