#include "common.h"

/* localdecomp:start func_L39_005515E8 */
void func_L39_00551660(void *);
extern s32 func_L39_00551918(u8 *);
extern s32 func_L39_00552070(u8 *);
extern void func_003C2880(u8 *);
extern void func_L01_00404A10(void *, u8 *);

void func_L39_005515E8(u8 *a0) {
    s32 a = func_L39_00551918(a0);
    s32 b = func_L39_00552070(a0);
    if (a == 0 && b == 0) {
        if (a0[32] == 2) {
            func_003C2880(a0);
        }
    } else {
        func_L01_00404A10(func_L39_00551660, a0);
    }
}
/* localdecomp:end func_L39_005515E8 */

/* localdecomp:start func_L39_00551660 */
void func_L39_00551A38(void);
void func_L39_005521F8(void *);

void func_L39_00551660(void *arg0) {
    if (arg0 != 0) {
        u8 t = *(u8 *)((char *)arg0 + 0x20);
        if (t != 0xFE) {
            if (t == 0xFD) {
                return;
            }
            func_L39_00551A38();
            func_L39_005521F8(arg0);
        }
    }
}
/* localdecomp:end func_L39_00551660 */

INCLUDE_ASM("asm/levels", func_L39_005516B0);
