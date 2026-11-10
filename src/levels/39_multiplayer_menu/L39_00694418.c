#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00694418);

INCLUDE_ASM("asm/levels", func_L39_006944B0);

/* localdecomp:start func_L39_00694770 */
typedef struct V_00694770 V_00694770;
typedef struct { V_00694770 *vt; } O_00694770;
struct V_00694770 {
    u8 pad[0x88];
    void (*set)(O_00694770 *, s32);
    s32 (*get)(O_00694770 *);
};
typedef struct {
    u8 pad[0x60];
    V_00694770 *vt;
} OB_00694770;
typedef struct {
    u8 pad0[0x114];
    OB_00694770 *f114;
    u8 pad1[0x290 - 0x118];
    s32 f290;
    u8 pad2[0x2C4 - 0x294];
    s32 f2c4;
    u8 pad3[0x3C8 - 0x2C8];
    s32 f3c8;
} S_00694770;
void func_L39_0068B2F8(s32, s32, s32);

s32 func_L39_00694770(S_00694770 *p, s32 arg1)
{
    if (arg1 == 3 || arg1 == 4) {
        if (p->f290 == 1) {
            func_L39_0068B2F8((s32)p, p->f3c8, 0);
            return 1;
        }
        p->f3c8 = p->f290;
        func_L39_0068B2F8((s32)p, 1, 0);
        return 1;
    }
    if (arg1 == 2) {
        if (p->f290 == 1 && p->f114->vt->get((O_00694770 *)p->f114) == p->f2c4 - 1) {
            p->f114->vt->set((O_00694770 *)p->f114, 0);
            return 1;
        }
        if (p->f290 == 10) {
            func_L39_0068B2F8((s32)p, 8, 0);
            return 1;
        }
    } else if (arg1 == 1) {
        if (p->f290 == 1 && p->f114->vt->get((O_00694770 *)p->f114) == 0) {
            p->f114->vt->set((O_00694770 *)p->f114, p->f2c4 - 1);
            return 1;
        }
        if (p->f290 == 8) {
            func_L39_0068B2F8((s32)p, 10, 0);
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_00694770 */

INCLUDE_ASM("asm/levels", func_L39_006948A0);

INCLUDE_ASM("asm/levels", func_L39_006949F0);

INCLUDE_ASM("asm/levels", func_L39_00694C70);

LINKER_REMNANT("asm/levels", func_L39_00694E60);

INCLUDE_ASM("asm/levels", func_L39_00694E78);

LINKER_REMNANT("asm/levels", func_L39_00694FF8);
