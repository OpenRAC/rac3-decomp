#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0066E378);

INCLUDE_ASM("asm/levels", func_L39_0066EAA8);

INCLUDE_ASM("asm/levels", func_L39_0066EC58);

INCLUDE_ASM("asm/levels", func_L39_0066ED88);

/* localdecomp:start func_L39_0066EE90 */
typedef struct {
    char pad0[0x8];
    char head[0x19 - 0x8];
    char bits[0x1DC - 0x19];
    s32 count;
} Obj;

extern void func_0038CC88(char *, char *, s32);
extern f32 func_001369D0(f32);

s32 func_L39_0066EE90(Obj *o, char *dst) {
    s32 ret;

    if (o->count == -1) {
        ret = 0;
    } else {
        func_0038CC88(dst, o->head, 8);
        dst += 8;
        func_0038CC88(dst, o->bits, (s32)func_001369D0(o->count * 0.125f));
        ret = (s32)func_001369D0(o->count * 0.125f) + 8;
    }
    return ret;
}
/* localdecomp:end func_L39_0066EE90 */

LINKER_REMNANT("asm/levels", func_L39_0066EF40);

INCLUDE_ASM("asm/levels", func_L39_0066EF48);

INCLUDE_ASM("asm/levels", func_L39_0066F260);

INCLUDE_ASM("asm/levels", func_L39_0066F558);

INCLUDE_ASM("asm/levels", func_L39_0066F5C0);

INCLUDE_ASM("asm/levels", func_L39_0066F628);
