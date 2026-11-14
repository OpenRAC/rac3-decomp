#include "common.h"

/* localdecomp:start func_L39_004EA3C8 */
void func_L39_004EACC8(void *);
void func_L39_004EACD8(void *);
void func_L39_004EACE8(void *);
void func_L39_004EACF8(void *);
extern u8 D_L39_004ED578[];
extern u8 D_L39_004ED6A8[];
extern u8 D_L39_004EEBC0[];
extern u8 D_L39_004EED58[];

s32 func_L39_004EA3C8(void) {
    func_L39_004EACC8(D_L39_004EEBC0);
    func_L39_004EACE8(D_L39_004EED58);
    func_L39_004EACD8(D_L39_004ED578);
    func_L39_004EACF8(D_L39_004ED6A8);
    return 1;
}
/* localdecomp:end func_L39_004EA3C8 */

INCLUDE_ASM("asm/levels", func_L39_004EA410);

INCLUDE_ASM("asm/levels", func_L39_004EA4A8);

INCLUDE_ASM("asm/levels", func_L39_004EA4E0);

/* localdecomp:start func_L39_004EA570 */
/* m2c3 */
s32 func_L39_004E48A8(s32, s32, s32, s32, s32, s32, s32); /* extern */

s32 func_L39_004EA570(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_L39_004E48A8((*(s32 *)((u8 *)(arg0) + 4)), 0x10, arg1, 0, arg2, arg3, 0x12) == 0;
}
/* localdecomp:end func_L39_004EA570 */

INCLUDE_ASM("asm/levels", func_L39_004EA5A8);

INCLUDE_ASM("asm/levels", func_L39_004EA8A0);

INCLUDE_ASM("asm/levels", func_L39_004EA938);

INCLUDE_ASM("asm/levels", func_L39_004EA968);

INCLUDE_ASM("asm/levels", func_L39_004EA9D0);

INCLUDE_ASM("asm/levels", func_L39_004EAA68);
