#include "common.h"

typedef struct {
    u8 pad0[16];
    s32 unk10;
} C39E3B8;
typedef struct {
    u8 pad0[220];
    s32 unkDC;
} V39E3B8;
typedef struct {
    u8 pad0[36];
    C39E3B8 *unk24;
    u8 pad28[52 - 40];
    u16 unk34;
    u8 pad36[104 - 54];
    V39E3B8 *pVars;
    u8 pad6C[152 - 108];
    s32 unk98;
    u8 pad9C[256 - 156];
} M39E3B8;

INCLUDE_ASM("asm/levels", func_L02_0039FAF0);

/* localdecomp:start func_L02_003A0030 */
extern void func_L02_003A0200_003A0030(u8 *);

void func_L02_003A0030(u8 *obj) {
    if (obj[32] == 0) {
        func_L02_003A0200_003A0030(obj);
    }
}
/* localdecomp:end func_L02_003A0030 */

INCLUDE_ASM("asm/levels", func_L02_003A0058);

/* localdecomp:start func_L02_003A0158 */



extern M39E3B8 *D_L02_001DE99C[];
extern void func_L01_0033D0E8(M39E3B8 *);

void func_L02_003A0158(s32 idx, s32 mode) {
    M39E3B8 *m = &D_L02_001DE99C[0][idx];

    switch (mode) {
    case 0:
        m->unk34 &= ~0x100;
        m->unk98 = m->unk24->unk10;
        m->pVars->unkDC = 8;
        break;
    case 1:
        func_L01_0033D0E8(m);
    case 2:
        m->unk34 |= 0x100;
        m->unk98 = 0;
        m->pVars->unkDC = 2;
        break;
    }
}
/* localdecomp:end func_L02_003A0158 */

INCLUDE_ASM("asm/levels", func_L02_003A0200);

INCLUDE_ASM("asm/levels", func_L02_003A02D8);

/* localdecomp:start func_L02_003A0498 */
extern void func_L02_003A04D0(u8 *o, s32 a);

void func_L02_003A0498(u8 *a) {
    func_L02_003A04D0(a, 0);
    func_L02_003A04D0(a, 1);
}
/* localdecomp:end func_L02_003A0498 */

INCLUDE_ASM("asm/levels", func_L02_003A04D0);

INCLUDE_ASM("asm/levels", func_L02_003A0978);

INCLUDE_ASM("asm/levels", func_L02_003A0C18);
