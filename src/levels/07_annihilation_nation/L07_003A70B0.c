#include "common.h"

/* localdecomp:start func_L07_003A70B0 */
s32 func_L07_003BAC00(s32, s32);
void func_L01_004450F0(void *, s32, s32);

void func_L07_003A70B0(void *arg0) {
    u8 *p = arg0;
    u8 *s = *(u8 **)(p + 0x68);
    s32 f;

    if (p[0x20] != 0) {
        if (*(s32 *)(s + 0x74) != 0) {
            if (func_L07_003BAC00(*(s32 *)(s + 0x74), *(s32 *)(s + 0x70)) == 0) {
                return;
            }
        }
    }
    f = p[0x20];
    if (f != 1) {
        if (f >= 2) {
            return;
        }
        if (f != 0) {
            return;
        }
        p[0x30] = 0xFF;
        *(s16 *)(p + 0x32) = 0x40;
        p[0x31] = 0;
        *(s32 *)(s + 0x74) = 0;
        *(s32 *)(s + 0x70) = -1;
        func_L01_004450F0(p, 1, -1);
    } else {
        if (*(s32 *)(s + 0x70) != -1) {
            func_L01_004450F0(p, 2, -1);
        }
    }
}
/* localdecomp:end func_L07_003A70B0 */

INCLUDE_ASM("asm/levels", func_L07_003A7178);

INCLUDE_ASM("asm/levels", func_L07_003A71E8);

INCLUDE_ASM("asm/levels", func_L07_003A7238);

INCLUDE_ASM("asm/levels", func_L07_003A7378);

INCLUDE_ASM("asm/levels", func_L07_003A7488);

/* localdecomp:start func_L07_003A7540 */
void func_L07_003A7540(void *arg0) {
    if (arg0 != 0) {
        *(s8 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x2BC) = 1;
    }
}
/* localdecomp:end func_L07_003A7540 */

INCLUDE_ASM("asm/levels", func_L07_003A7558);

INCLUDE_ASM("asm/levels", func_L07_003A75E0);

INCLUDE_ASM("asm/levels", func_L07_003A79F0);
