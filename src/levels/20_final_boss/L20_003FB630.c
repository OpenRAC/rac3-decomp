#include "common.h"

typedef struct { u8 pad0[0x394]; s32 x394; u8 pad1[0x5C]; s16 x3F4; } T_003FB630;
typedef struct { u8 pad0[0x68]; T_003FB630 *x68; } O_003FB630;

/* localdecomp:start func_L20_003FB630 */
extern s32 func_L20_003FB3B0(void *);
extern void func_L05_0035AA68(void *, s32, s32, s32);

void func_L20_003FB630(O_003FB630 *p) {
    T_003FB630 *q;

    q = p->x68;
    if (func_L20_003FB3B0(p) != 0) {
        return;
    }
    if (q->x3F4 != 0) {
        if (q->x394 != 0) {
            func_L05_0035AA68(p, 5, 0, 8);
        } else {
            func_L05_0035AA68(p, 4, 0, 8);
        }
    } else {
        func_L05_0035AA68(p, 6, 0, 8);
    }
}
/* localdecomp:end func_L20_003FB630 */

INCLUDE_ASM("asm/levels", func_L20_003FB6A8);

INCLUDE_ASM("asm/levels", func_L20_003FDFE8);

INCLUDE_ASM("asm/levels", func_L20_003FE3D0);

LINKER_REMNANT("asm/levels", func_L20_003FE9B0);

INCLUDE_ASM("asm/levels", func_L20_003FE9C0);

INCLUDE_ASM("asm/levels", func_L20_003FEBA8);

INCLUDE_ASM("asm/levels", func_L20_003FEDF0);
