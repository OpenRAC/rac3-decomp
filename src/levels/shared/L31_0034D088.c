#include "common.h"

INCLUDE_ASM("asm/levels", func_L31_0034D088);

/* localdecomp:start func_L31_0034D390 */
typedef struct {
    u8 pad0[0xC];
    f32 fC;
    u8 pad10[0x10];
} S_34C720e;

typedef struct {
    u8 pad0[0x40];
    S_34C720e e[1];
} S_34C720a;

typedef struct {
    u8 pad0[0x68];
    S_34C720a *p68;
} S_34C720b;

typedef struct {
    u8 pad0[0xDC];
    S_34C720b *pDC;
    s32 iE0;
    s32 iE4;
} S_34C720c;

typedef struct {
    u8 pad0[0x68];
    S_34C720c *p68;
} S_34C720d;

extern s32 D_L31_001DEB2C;

void func_L31_0034D390(S_34C720d *a0, s32 a1) {
    S_34C720c *v = a0->p68;

    if (a1) {
        v->pDC->p68->e[v->iE0].fC = 1.0f;
        v->pDC->p68->e[v->iE4].fC = 0.0f;
        v->pDC->p68->e[8].fC = 0.0f;
        v->pDC->p68->e[14].fC = 0.0f;
        D_L31_001DEB2C = 0;
    } else {
        v->pDC->p68->e[v->iE0].fC = 0.0f;
        v->pDC->p68->e[v->iE4].fC = 1.0f;
        v->pDC->p68->e[8].fC = 1.0f;
        v->pDC->p68->e[14].fC = 1.0f;
        D_L31_001DEB2C = 1;
    }
}
/* localdecomp:end func_L31_0034D390 */
