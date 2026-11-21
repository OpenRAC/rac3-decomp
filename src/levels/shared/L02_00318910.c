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

/* localdecomp:start func_L02_00318F28 */
#include "vu0.h"

typedef struct { u8 p0[0x18]; f32 f18; f32 f1C; u8 p20[0x24]; f32 f44; f32 f48; f32 f4C; } S_318F28;
typedef struct { u8 p0[0x10]; vu0_v4 pos; u8 p20[0x14]; u16 f34; u8 p36[0x32]; S_318F28 *s; u8 p6C[0x74]; vu0_q vE0; } M_318F28;

extern u8 D_001A4BE0[];
extern u8 D_L02_0021E0D8[];
extern s32 D_L02_001DC6B0[] __attribute__((section(".sdata")));
__asm__(".extern D_L02_001DC6B0, 8");
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_004713C8(void *, void *, s32, f32, s32, s32, s32, s32, f32, f32, s32);

#define F28_FLD(base, T, off) (((struct { u8 pad[off]; T v; } *)(base))->v)
/* one burst at angle `ang` on the ring of radius s->r; NEWV recomputes the velocity */
#define F28_BURST(ang, r, lo, hi, NEWV) \
    { \
        pos.x = func_0038D098(ang) * s->r; \
        pos.y = func_0038D0B0(ang) * s->r; \
        pos.z = 0.0f; \
        vec_add_ba(&pos, &pos, &m->pos); \
        pos.z = pos.z + 0.15f; \
        a = (s32)func_L01_00443A18(2.0f, 5.0f); \
        f = func_003824E0(0.1f, 0.2f); \
        NEWV \
        func_L01_004713C8(&pos, &v, (func_00382498(lo, hi) * 5 + 2) / 6, f * 210000.0f, D_L02_001DC6B0[0], a, 0x7F, 0x7F, 2100.0f, -0.0012f, 1); \
        a = -(a * 2); \
        p = func_L01_004713C8(&pos, &v, (func_00382498(lo, hi) * 5 + 2) / 6, f * 2.0f * 210000.0f, D_L02_001DC6B0[1], a, 0x30, 0x30, 4200.0f, -0.0012f, 0); \
        if (p != 0) { \
            p[2] = **(u8 **)(D_L02_0021E0D8 + 0xD4); \
        } \
    }
#define F28_NEWV v = m->vE0; func_0038CF68(&v, &v, 0.040000003f);
#define F28_SAMEV

void func_L02_00318F28(M_318F28 *m) {
    vu0_v4 pos;
    vu0_q v;
    S_318F28 *s;
    f32 b;
    s32 a;
    f32 f;
    u8 *p;

    s = m->s;
    if (m->f34 & 1) return;
    b = func_0038DAB8(s->f44, 0.7853982f);
    F28_BURST(s->f44, f4C, 40, 45, F28_NEWV)
    F28_BURST(func_0038DAB8(s->f44, 3.1415927f), f4C, 40, 45, F28_SAMEV)
    F28_BURST(func_0038DAB8(s->f44, 4.712389f), f4C, 40, 45, F28_SAMEV)
    F28_BURST(func_0038DAB8(s->f44, 1.5707964f), f4C, 40, 45, F28_SAMEV)
    F28_BURST(b, f18, 20, 25, F28_NEWV)
    F28_BURST(func_0038DAB8(b, 3.1415927f), f18, 20, 25, F28_SAMEV)
    F28_BURST(func_0038DAB8(b, 4.712389f), f18, 20, 25, F28_SAMEV)
    F28_BURST(func_0038DAB8(b, 1.5707964f), f18, 20, 25, F28_SAMEV)

    s->f44 = func_0038DAB8(s->f44, s->f48);
    s->f4C = s->f4C - 0.008f;
    s->f48 = s->f48 + 0.0017453294f;
    if (s->f4C < 0.1f) s->f4C = 0.1f;
    s->f18 = s->f18 - 0.002f;
    if (s->f18 < 0.2f) s->f18 = 0.2f;
    if (s->f4C < 0.3f) {
        F28_FLD(D_001A4BE0, s16, 0x2888) = 1;
        F28_FLD(D_001A4BE0, f32, 0x22D0) = F28_FLD(D_001A4BE0, f32, 0x22D4) = s->f1C;
        F28_FLD(D_001A4BE0, f32, 0x22D8) = 1.0f;
        s->f1C = s->f1C - 0.030000001f;
    }
}
/* localdecomp:end func_L02_00318F28 */

/* localdecomp:start func_L02_00319BB0 */
#include "vu0.h"

typedef struct { u8 p0[0x14]; f32 f14; f32 f18; f32 f1C; u8 p20[0x24]; f32 f44; f32 f48; f32 f4C; } S_319BB0;
typedef struct { u8 p0[0x10]; vu0_v4 pos; u8 p20[0x14]; u16 f34; u8 p36[0x32]; S_319BB0 *s; u8 p6C[0x74]; vu0_v4 vE0; } M_319BB0;

extern u8 D_001A4BE0[];
extern u8 D_L02_0021E0D8[];
extern s32 D_L02_001DC6B0[] __attribute__((section(".sdata")));
__asm__(".extern D_L02_001DC6B0, 8");
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_004713C8(void *, void *, s32, f32, s32, s32, s32, s32, f32, f32, s32);

#define BB0_FLD(base, T, off) (((struct { u8 pad[off]; T v; } *)(base))->v)
/* one burst at angle `ang` on the ring of radius s->r; NEWV recomputes the velocity */
#define BB0_BURST(ang, r, lo, hi, NEWV) \
    { \
        pos.x = func_0038D098(ang) * s->r; \
        pos.y = func_0038D0B0(ang) * s->r; \
        pos.z = 0.0f; \
        vec_add_ba(&pos, &pos, &m->pos); \
        pos.z = pos.z + 0.15f; \
        a = (s32)func_L01_00443A18(2.0f, 5.0f); \
        f = func_003824E0(0.1f, 0.2f); \
        NEWV \
        func_L01_004713C8(&pos, &v, (s32)((f32)((func_00382498(lo, hi) * 5 + 2) / 6) * s->f14), f * 210000.0f, D_L02_001DC6B0[0], a, 0x7F, 0x7F, 2100.0f, -0.0012f, 1); \
        a = -(a * 2); \
        p = func_L01_004713C8(&pos, &v, (s32)((f32)((func_00382498(lo, hi) * 5 + 2) / 6) * s->f14), f * 2.0f * 210000.0f, D_L02_001DC6B0[1], a, 0x30, 0x30, 4200.0f, -0.0012f, 0); \
        if (p != 0) { \
            p[2] = **(u8 **)(D_L02_0021E0D8 + 0xD4); \
        } \
    }
#define BB0_NEWV v = m->vE0; func_0038CF68(&v, &v, s->f14 * 0.040000003f);
#define BB0_SAMEV

void func_L02_00319BB0(M_319BB0 *m) {
    vu0_v4 pos;
    vu0_v4 v;
    S_319BB0 *s;
    f32 b;
    s32 a;
    f32 f;
    u8 *p;

    s = m->s;
    if (m->f34 & 1) return;
    b = func_0038DAB8(s->f44, 0.7853982f);
    BB0_BURST(s->f44, f4C, 40, 45, BB0_NEWV)
    BB0_BURST(func_0038DAB8(s->f44, 3.1415927f), f4C, 40, 45, BB0_SAMEV)
    BB0_BURST(func_0038DAB8(s->f44, 4.712389f), f4C, 40, 45, BB0_SAMEV)
    BB0_BURST(func_0038DAB8(s->f44, 1.5707964f), f4C, 40, 45, BB0_SAMEV)
    BB0_BURST(b, f18, 20, 25, BB0_NEWV)
    BB0_BURST(func_0038DAB8(b, 3.1415927f), f18, 20, 25, BB0_SAMEV)
    BB0_BURST(func_0038DAB8(b, 4.712389f), f18, 20, 25, BB0_SAMEV)
    BB0_BURST(func_0038DAB8(b, 1.5707964f), f18, 20, 25, BB0_SAMEV)

    s->f44 = func_0038DB00(s->f44, s->f48);
    s->f48 = s->f48 - 0.002443461f;
    if (s->f48 < 0.0f) s->f48 = 0.0f;
    s->f4C = s->f4C + 0.010000001f;
    s->f18 = s->f18 + 0.0030000003f;
    if (0.8f < s->f4C) s->f4C = 0.8f;
    if (0.8f < s->f18) s->f18 = 0.8f;
    BB0_FLD(D_001A4BE0, s16, 0x2888) = 1;
    BB0_FLD(D_001A4BE0, f32, 0x22D0) = BB0_FLD(D_001A4BE0, f32, 0x22D4) = s->f1C;
    BB0_FLD(D_001A4BE0, f32, 0x22D8) = 1.0f;
    s->f1C = s->f1C + 0.32000002f;
    if (1.0f < s->f1C) s->f1C = 1.0f;
    s->f14 = s->f14 - 0.046000004f;
    if (s->f14 < 0.0f) s->f14 = 0.0f;
}
/* localdecomp:end func_L02_00319BB0 */
