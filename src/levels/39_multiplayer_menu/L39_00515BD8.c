#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00515BD8);

INCLUDE_ASM("asm/levels", func_L39_00515C28);

INCLUDE_ASM("asm/levels", func_L39_00515C70);

INCLUDE_ASM("asm/levels", func_L39_00515D28);

INCLUDE_ASM("asm/levels", func_L39_00515DA8);

INCLUDE_ASM("asm/levels", func_L39_00515E00);

INCLUDE_ASM("asm/levels", func_L39_00515E18);

LINKER_REMNANT("asm/levels", func_L39_00515F30);

/* localdecomp:start func_L39_00515F38 */
typedef struct {
    s32 key;
    s32 unk4;
    s32 unk8;
} E_00515F38;

typedef struct {
    u32 count;
    s32 unk4;
    E_00515F38 *items;
} S_00515F38;

E_00515F38 *func_L39_00515F38(S_00515F38 *arg0, s32 arg1) {
    u32 n;
    E_00515F38 *p;
    if (arg1 == 0) return 0;
    n = arg0->count;
    p = arg0->items;
    while (n-- > 0) {
        if (p->key == arg1) return p;
        p++;
    }
    return 0;
}
/* localdecomp:end func_L39_00515F38 */
