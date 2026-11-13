#include "common.h"

/* localdecomp:start func_L39_0053DA40 */
typedef struct {
    u8 pad[136];
    s32 f88[1];
} S_352C4C_0053DA40;
typedef struct { u32 w0; s32 w4; } M_0053DA40;
typedef struct {
    u8 p0[0x1C]; s32 f1C; u8 p20[0x20]; s32 f40; u8 p44[0x24]; s32 f68; u8 p6C[0x40]; s32 fAC; u8 pB0[8]; s32 fB8; s32 fBC;
} O_0053DA40;
extern S_352C4C_0053DA40 *D_L39_00352B4C[];
extern s32 D_L39_00352950[];
extern void func_L39_00662B18(M_0053DA40 *, void *, s32);
extern void func_L39_0055D948(s32, s32);

void func_L39_0053DA40(u8 *a0, M_0053DA40 *m) {
    O_0053DA40 *o = *(O_0053DA40 **)(a0 + 0x68);
    s32 buf;
    switch (m->w0 & 0xF) {
    case 0:
        o->f40 = 1;
        break;
    case 1:
        func_L39_00662B18(m, &buf, 4);
        if (o->f68 == -1 || m->w4 + (s32)(m->w0 >> 13) < o->f68) {
            D_L39_00352950[0] = buf;
            o->f68 = m->w4 + (s32)(m->w0 >> 13);
        }
        break;
    case 2:
        func_L39_0055D948(o->fAC, D_L39_00352B4C[0]->f88[o->f1C]);
        o->fBC = 0;
        o->fB8++;
        break;
    }
}
/* localdecomp:end func_L39_0053DA40 */

INCLUDE_ASM("asm/levels", func_L39_0053DB28);

INCLUDE_ASM("asm/levels", func_L39_0053DC78);

INCLUDE_ASM("asm/levels", func_L39_0053E300);

INCLUDE_ASM("asm/levels", func_L39_0053E740);
