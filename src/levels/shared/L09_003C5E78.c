#include "common.h"

typedef void (*fn_3C5D58)(u8 *);

INCLUDE_ASM("asm/levels", func_L09_003C5E78);

INCLUDE_ASM("asm/levels", func_L09_003C6388);

INCLUDE_ASM("asm/levels", func_L09_003C6890);

INCLUDE_ASM("asm/levels", func_L09_003C6900);

INCLUDE_ASM("asm/levels", func_L09_003C6C38);

INCLUDE_ASM("asm/levels", func_L09_003C6D50);

INCLUDE_ASM("asm/levels", func_L09_003C70C0);

INCLUDE_ASM("asm/levels", func_L09_003C7338);

INCLUDE_ASM("asm/levels", func_L09_003C7568);

/* localdecomp:start func_L09_003C7748 */

extern fn_3C5D58 *func_L01_0043B548(s32, s32);
extern void func_L09_003C6C38(u8 *);
extern void func_003C2880(u8 *);
extern u8 *D_001A65C0[];

void func_L09_003C7748(u8 *a0, s32 a1) {
    u8 *pv = *(u8 **)(a0 + 104);
    fn_3C5D58 *tbl;
    if (*(s32 *)(pv + 464) != 0) {
        tbl = func_L01_0043B548(6625, 108);
        if (a1 == 0 && D_001A65C0[0] == a0) {
            func_L09_003C6C38(a0);
        }
        tbl[0](a0);
        if (a1 != 0) {
            tbl[1](a0);
        }
    } else {
        func_003C2880(a0);
    }
}
/* localdecomp:end func_L09_003C7748 */

INCLUDE_ASM("asm/levels", func_L09_003C77E8);

INCLUDE_ASM("asm/levels", func_L09_003C7928);

INCLUDE_ASM("asm/levels", func_L09_003C7B78);

INCLUDE_ASM("asm/levels", func_L09_003C7DF8);

INCLUDE_ASM("asm/levels", func_L09_003C8158);

INCLUDE_ASM("asm/levels", func_L09_003C8740);

INCLUDE_ASM("asm/levels", func_L09_003C92E0);

INCLUDE_ASM("asm/levels", func_L09_003CA6A8);

INCLUDE_ASM("asm/levels", func_L09_003CA7E8);

INCLUDE_ASM("asm/levels", func_L09_003CA998);
