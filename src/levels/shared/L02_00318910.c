#include "common.h"

typedef struct { u8 p0[0x23]; u8 f23; u8 p24[0x10]; u16 f34; } E_00318E78;

typedef struct { char pad[0x10]; unsigned int kind; } B;
typedef struct { char pad[0x68]; B *b; } A;

typedef struct { u8 p0[0x23]; s8 f23; } E_00318CA8;
typedef struct { u8 p0[0x1200]; E_00318CA8 *e[3]; u8 pad[0x50 - 0xC]; } S_00318CA8;
typedef struct { u8 p0[0x25C0]; E_00318CA8 *g; } T_00318CA8;

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

/* localdecomp:start func_L02_00318A28 */
typedef int u128_t_00318A28 __attribute__((mode(TI)));
extern u8 D_001A4BE0[];
extern u8 D_L02_0021E0D8[];
extern u8 D_L02_0026F7A0[];
extern void func_L02_003BAFA0(void *, void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_004713C8(void *, void *, s32, f32, s32, s32, s32, s32, f32, f32, s32);

void func_L02_00318A28(u8 *self, s32 *col) {
    u128_t_00318A28 v[2];
    u8 *st;
    s32 i;
    s32 a;
    f32 f;
    u8 *p;
    u8 *h;
    u8 *g;

    st = *(u8 **)(self + 0x68);
    for (i = 0; i < 24; i++) {
        h = D_001A4BE0;
        func_L02_003BAFA0(*(void **)(h + 0x25C0), D_L02_0026F7A0, &v[0], 0, 0.0f);
        v[1] = *(u128_t_00318A28 *)(self + 0xE0);
        func_0038CF68(&v[1], &v[1], *(f32 *)(st + 0x14) * 0.040000003f);
        a = (s32)func_L01_00443A18(2.0f, 5.0f);
        f = func_003824E0(0.05f, 0.1f);
        func_L01_004713C8(&v[0], &v[1], (s32)((f32)((func_00382498(20, 25) * 5 + 2) / 6) * *(f32 *)(st + 0x14)), f * 210000.0f, col[0], a, 0x7F, 0x7F, 2100.0f, -0.0012f, 1);
        a = -(a * 2);
        p = func_L01_004713C8(&v[0], &v[1], (s32)((f32)((func_00382498(20, 25) * 5 + 2) / 6) * *(f32 *)(st + 0x14)), f * 4.0f * 210000.0f, col[1], a, 0x30, 0x30, 4200.0f, -0.0012f, 0);
        if (p != 0) {
            g = D_L02_0021E0D8;
            p[2] = **(u8 **)(g + 0xD4);
        }
    }
    *(f32 *)(st + 0x14) = *(f32 *)(st + 0x14) + 0.035000004f;
    if (*(f32 *)(st + 0x14) > 1.0f) {
        *(f32 *)(st + 0x14) = 1.0f;
    }
}
/* localdecomp:end func_L02_00318A28 */

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
