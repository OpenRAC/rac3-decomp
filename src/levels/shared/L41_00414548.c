#include "common.h"

INCLUDE_ASM("asm/levels", func_L41_00414548);

/* localdecomp:start func_L41_00414900 */
typedef struct {
    s32 x0;
    u8 pad[0x2D];
    u8 x31;
} S_414050;

extern S_414050 *func_L39_0066C1F0(s32);

void func_L41_00414900(S_414050 **p, s32 *id) {
    if (*p != 0) {
        if ((*p)->x0 != *id) {
            *p = 0;
        }
        if (*p != 0 && (*p)->x31 == 0) {
            *p = 0;
            *id = 0;
        }
    }
    if (*p == 0 && *id != 0) {
        *p = func_L39_0066C1F0(*id);
    }
}
/* localdecomp:end func_L41_00414900 */

/* localdecomp:start func_L41_00414980 */
typedef struct {
    u8 pad0[0x2C];
    s32 x2C;
    u8 pad30[0xA0 - 0x30];
    s32 xA0;
    u8 padA4[0xB8 - 0xA4];
    s32 xB8;
} S_00414980_I;

typedef struct {
    u8 pad0[0x68];
    S_00414980_I *x68;
    u8 pad6C[0x100 - 0x6C];
} S_00414980_O;

typedef struct {
    u8 pad0[0xA8];
    s32 xA8[1];
} S_00414980_T;

extern S_00414980_O *D_L41_0024865C;
extern S_00414980_T *D_L41_003575AC __attribute__((section(".data")));

s32 func_L41_00414980(S_00414980_O *a) {
    S_00414980_I *p = a->x68;
    s32 v = p->xB8;
    s32 w;
    S_00414980_O *e;

    if (v == -1) {
        return 1;
    }
    w = p->xA0;
    if (w == -1) {
        return 1;
    }
    e = &D_L41_0024865C[v];
    return D_L41_003575AC->xA8[e->x68->x2C] == w;
}
/* localdecomp:end func_L41_00414980 */

/* localdecomp:start func_L41_004149E0 */
int func_L41_004149E0(char *a) {
    int i;
    for (i = 0; i < 5; i++) {
        if (((int *)(a + 112))[i] != 0) {
            return 0;
        }
    }
    return 1;
}
/* localdecomp:end func_L41_004149E0 */

INCLUDE_ASM("asm/levels", func_L41_00414A10);
