#include "common.h"

/* localdecomp:start func_L39_004E1200 */
extern s32 func_L39_004BECF0(void *, s32, s32, char *, s32);
extern void func_L39_004E1268(void *);
extern void func_L39_004BEF28(void *);
extern char D_L39_00477278[];

void func_L39_004E1200(void *arg0) {
    if (arg0 == 0) {
        return;
    }
    if (func_L39_004BECF0((u8 *)arg0 + 8, -1, 0xA, D_L39_00477278, 0xF2) > 0) {
        return;
    }
    func_L39_004E1268(arg0);
    func_L39_004BEF28(arg0);
}
/* localdecomp:end func_L39_004E1200 */

INCLUDE_ASM("asm/levels", func_L39_004E1268);
