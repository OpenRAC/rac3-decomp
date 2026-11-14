#include "common.h"

typedef struct { u8 pad0[0x394]; s32 x394; u8 pad1[0x5C]; s16 x3F4; } T_003FB630;
typedef struct { u8 pad0[0x68]; T_003FB630 *x68; } O_003FB630;

/* declared by functions of L20_003FB630.c, which this file was cut from */
extern void func_L20_003FEDF0(u8 *);

/* localdecomp:start func_L20_003FEDF0 */
void func_L20_003FEDF0(Mo *m) {
    u16 *q;

    if (m->b[0x21] == 0xFF) {
        return;
    }
    q = (u16 *)D_L20_0021CFE0[m->b[0x21]];
    while (m->b[0x21] != 0xFF && m->b[0x21] <= D_L20_001E02D8 && q != 0 &&
           ((s16)q[-1] >= 0 || q == (u16 *)D_L20_0021CFE0[m->b[0x21]])) {
        Mo *e = &D_L20_001E029C[*q & 0x7FFF];
        if (e == 0) {
            break;
        }
        q++;
        if (e->h[0xAA / 2] == m->h[0xAA / 2]) {
            e->pv[0x68 / 4]->uh[0x3D8 / 2] = 1;
        }
    }
}
/* localdecomp:end func_L20_003FEDF0 */
