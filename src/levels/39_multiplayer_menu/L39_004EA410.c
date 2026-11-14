#include "common.h"

/* localdecomp:start func_L39_004EA410 */
typedef struct S_004EA410 {
    char _p0[0x4];
    void *f4;
    char _p8[0x4];
    void *fC;
    char f10[0x8];
    void *f18;
} S_004EA410;
extern char D_L39_00477538[];
extern s32 func_L39_004BECF0(void *, s32, s32, char *, s32);
extern void func_L39_004BEF28(void *);
extern void func_L39_004E2D68(void *);
extern void func_L39_004E47F8(void *);

void func_L39_004EA410(S_004EA410 *p) {
    if (p == 0) {
        return;
    }
    if (func_L39_004BECF0(p->f10, -1, 9, D_L39_00477538, 0xDB) > 0) {
        return;
    }
    if (p->fC != 0) {
        func_L39_004E2D68(p->fC);
    }
    if (p->f4 != 0) {
        func_L39_004E47F8(p->f4);
    }
    if (p->f18 != 0) {
        func_L39_004BEF28(p->f18);
    }
    func_L39_004BEF28(p);
}
/* localdecomp:end func_L39_004EA410 */

INCLUDE_ASM("asm/levels", func_L39_004EA4A8);

LINKER_REMNANT("asm/levels", func_L39_004EA4D8);

INCLUDE_ASM("asm/levels", func_L39_004EA4E0);
