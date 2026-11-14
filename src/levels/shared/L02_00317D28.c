#include "common.h"

typedef struct { u8 p0[0x23]; u8 f23; u8 p24[0x10]; u16 f34; } E_00318E78;

typedef struct { char pad[0x10]; unsigned int kind; } B;
typedef struct { char pad[0x68]; B *b; } A;

typedef struct { u8 p0[0x23]; s8 f23; } E_00318CA8;
typedef struct { u8 p0[0x1200]; E_00318CA8 *e[3]; u8 pad[0x50 - 0xC]; } S_00318CA8;
typedef struct { u8 p0[0x25C0]; E_00318CA8 *g; } T_00318CA8;

INCLUDE_ASM("asm/levels", func_L02_00317D28);

/* localdecomp:start func_L02_00318910 */
extern void func_L01_00452560(int, int, int, int, int, int, int);
void func_L02_00318910(A *a0)
{
    int msg;
    switch (a0->b->kind) {
    case 10: msg = 0x8C9; break;
    case 13: msg = 0x1871; break;
    case 14: msg = 0xEFC; break;
    case 19: msg = 0x1872; break;
    case 40: msg = 0xC88; break;
    case 41: msg = 0xC87; break;
    case 50: msg = 0x1266; break;
    case 51: msg = 0x1264; break;
    case 69: msg = 0x141E; break;
    case 101: msg = 0x11E4; break;
    case 102: msg = 0x11D8; break;
    case 11: msg = 0x15E2; break;
    case 28: msg = 0x16FE; break;
    case 0:
    default: msg = 0x850; break;
    }
    func_L01_00452560(0, 12, msg, 1, 0, 0, 0);
}
/* localdecomp:end func_L02_00318910 */

/* localdecomp:start func_L02_003189D8 */
typedef struct { u8 p0[0x2C]; f32 f2C; } V_318528;
typedef struct { u8 p0[0x68]; V_318528 *v; } M_318528;
extern f32 D_L02_001DE2D0;
void func_L02_003189D8(M_318528 *m) {
    f32 f = m->v->f2C;
    if (f > 1.0f) {
        f = 1.0f;
    } else if (f < 0.0f) {
        f = 0.0f;
    }
    D_L02_001DE2D0 = 1.0f - f;
}
/* localdecomp:end func_L02_003189D8 */

INCLUDE_ASM("asm/levels", func_L02_00318A28);

/* localdecomp:start func_L02_00318CA8 */
extern u8 D_001A4BE0[];

void func_L02_00318CA8(f32 *a0, f32 f12) {
    T_00318CA8 *t;
    S_00318CA8 *p;
    s32 i;

    *a0 += f12;
    if (*a0 > 1.0f) {
        *a0 = 1.0f;
    } else if (*a0 < 0.0f) {
        *a0 = 0.0f;
    }
    t = (T_00318CA8 *)D_001A4BE0;
    t->g->f23 = (s32)(*a0 * 115.0f) + 12;
    if (t->g->f23 < 0) {
        t->g->f23 = 0x7F;
    } else if ((u8)t->g->f23 < 12) {
        t->g->f23 = 12;
    }
    for (i = 0; i < 7; i++) {
        p = (S_00318CA8 *)(D_001A4BE0 + i * 0x50);
        if (i == 3) continue;
        if (p->e[0] != 0) {
            p->e[0]->f23 = (u8)p->e[0]->f23 + f12;
            if (p->e[0]->f23 < 0) {
                p->e[0]->f23 = 0x7F;
            } else if ((u8)p->e[0]->f23 < 12) {
                p->e[0]->f23 = 12;
            }
        }
        if (p->e[1] != 0) {
            p->e[1]->f23 = (u8)p->e[1]->f23 + f12;
            if (p->e[1]->f23 < 0) {
                p->e[1]->f23 = 0x7F;
            } else if ((u8)p->e[1]->f23 < 12) {
                p->e[1]->f23 = 12;
            }
        }
        if (p->e[2] != 0) {
            p->e[2]->f23 = (u8)p->e[2]->f23 + f12;
            if (p->e[2]->f23 < 0) {
                p->e[2]->f23 = 0x7F;
            } else if ((u8)p->e[2]->f23 < 12) {
                p->e[2]->f23 = 12;
            }
        }
    }
}
/* localdecomp:end func_L02_00318CA8 */

/* localdecomp:start func_L02_00318E78 */
extern u8 D_001A4BE0[];

void func_L02_00318E78(void) {
    u8 *base = D_001A4BE0;
    s32 p;
    s32 end;
    s32 c;

    (*(E_00318E78 **)(base + 0x25C0))->f23 = 0x7F;
    (*(E_00318E78 **)(base + 0x25C0))->f34 &= 0xDFFF;
    c = 0x7F;
    p = (s32)base;
    end = (s32)base + 0x230;
    do {
        if (*(E_00318E78 **)(p + 0x1200) != 0) {
            (*(E_00318E78 **)(p + 0x1200))->f23 = c;
            (*(E_00318E78 **)(p + 0x1200))->f34 &= 0xDFFF;
        }
        if (*(E_00318E78 **)(p + 0x1204) != 0) {
            (*(E_00318E78 **)(p + 0x1204))->f23 = c;
            (*(E_00318E78 **)(p + 0x1204))->f34 &= 0xDFFF;
        }
        if (*(E_00318E78 **)(p + 0x1208) != 0) {
            (*(E_00318E78 **)(p + 0x1208))->f23 = c;
            (*(E_00318E78 **)(p + 0x1208))->f34 &= 0xDFFF;
        }
        p += 0x50;
    } while (p < end);
}
/* localdecomp:end func_L02_00318E78 */

INCLUDE_ASM("asm/levels", func_L02_00318F28);

INCLUDE_ASM("asm/levels", func_L02_00319BB0);
