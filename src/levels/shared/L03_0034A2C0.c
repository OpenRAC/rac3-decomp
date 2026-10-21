#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_0034A2C0);

INCLUDE_ASM("asm/levels", func_L03_0034A4B8);

/* localdecomp:start func_L03_0034A760 */
extern u8 *func_L01_00447490(u8 *, s32, s32);
void func_L03_0034A760(u8 *a0) {
    u8 *p = func_L01_00447490(a0, 0x10000, 0);
    if (p != 0) {
        u8 *q = *(u8 **)(p + 32);
        if (q != 0) {
            s16 t = *(s16 *)(q + 170);
            if (t == 208 || t == 2085) {
                a0[188] = 1;
            }
        }
    }
    a0[168] = 255;
}
/* localdecomp:end func_L03_0034A760 */

LINKER_REMNANT("asm/levels", func_L03_0034A7C8);

INCLUDE_ASM("asm/levels", func_L03_0034A7D8);

INCLUDE_ASM("asm/levels", func_L03_0034AB60);

INCLUDE_ASM("asm/levels", func_L03_0034AC40);

/* localdecomp:start func_L03_0034AE68 */
typedef struct {
    u8 pad[32];
    u8 type;
    u8 pad2[223];
} E_0034A2A8;
extern E_0034A2A8 *D_L03_001DF99C;
s32 func_L03_0034AE68(u8 *a0, s32 a1) {
    s32 *q = (s32 *)(*(u8 **)(a0 + 104) + 16);
    s32 count = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (q[i] != -1) {
            u8 t = D_L03_001DF99C[q[i]].type;
            if (t != 3 && (a1 == 0 || t != 2)) {
                count++;
            }
        }
    }
    return count;
}
/* localdecomp:end func_L03_0034AE68 */

/* localdecomp:start func_L03_0034AED8 */
typedef int q128 __attribute__((mode(TI)));

typedef struct {
    char pad0[0x150];
    q128 unk150;
    char pad160[0x190 - 0x160];
    q128 unk190;
    char pad1A0[0x300 - 0x1A0];
    q128 unk300;
    char pad310[0x940 - 0x310];
    q128 unk940;
} Vars;

typedef struct {
    char pad0[0x10];
    q128 pos;
    char pad20[0x34 - 0x20];
    u16 flags;
    char pad36[0x68 - 0x36];
    Vars *vars;
    char pad6C[0xA8 - 0x6C];
    u8 unkA8;
    char padA9[0xAA - 0xA9];
    s16 oClass;
} Moby;

extern void func_L01_004450F0(Moby *, s32, s32);

void func_L03_0034AED8(void *arg0, Moby *m) {
    if (arg0 == 0 || m == 0) {
        return;
    }
    if (m->oClass == 7003) {
        m->pos = m->vars->unk940;
    }
    if (m->oClass == 7062) {
        m->pos = m->vars->unk150;
    }
    if (m->oClass == 7063) {
        m->pos = m->vars->unk300;
    }
    if (m->oClass == 7066) {
        m->pos = m->vars->unk190;
    }
    m->unkA8 = 255;
    m->flags &= ~2;
    func_L01_004450F0(m, 0, -1);
}
/* localdecomp:end func_L03_0034AED8 */
