#include "common.h"

/* localdecomp:start func_L03_003A2A10 */
typedef struct { u8 pad[0x23]; s8 v; } P_003A2A10;
typedef struct { u8 pad0[0x1200]; P_003A2A10 *p[3]; u8 pad1[0x50 - 12]; } E_003A2A10;
typedef struct { u8 pad0[0x25C0]; P_003A2A10 *q; } H_003A2A10;
extern E_003A2A10 D_001A4BE0_003A2A10;
extern H_003A2A10 D_001A4BE0_003A2A10h;
__asm__(".extern D_001A4BE0_003A2A10, 16");
__asm__(".extern D_001A4BE0_003A2A10h, 16");

void func_L03_003A2A10(s32 d) {
    s32 i;
    E_003A2A10 *e;
    int j;
    H_003A2A10 *h = &D_001A4BE0_003A2A10h;
    h->q->v += d;
    if (h->q->v < 0) h->q->v = 0x7F;
    else if ((u8)h->q->v < 12) h->q->v = 12;
    e = &D_001A4BE0_003A2A10;
    for (i = 0; i < 7; i++, e = (E_003A2A10 *)((u8 *)e + 0x50)) {
        P_003A2A10 *p;
        p = e->p[0];
        if (p != 0) {
            p->v += d;
            p = e->p[0];
            if (p->v < 0) p->v = 0x7F;
            else if ((u8)p->v < 12) p->v = 12;
        }
        p = e->p[1];
        if (p != 0) {
            p->v += d;
            p = e->p[1];
            if (p->v < 0) p->v = 0x7F;
            else if ((u8)p->v < 12) p->v = 12;
        }
        p = e->p[2];
        if (p != 0) {
            p->v += d;
            p = e->p[2];
            if (p->v < 0) p->v = 0x7F;
            else if ((u8)p->v < 12) p->v = 12;
        }
    }
}
/* localdecomp:end func_L03_003A2A10 */

/* localdecomp:start func_L03_003A2B48 */
typedef struct S_003A2B48 {
    u8 pad0[0x23];
    u8 b23;
    u8 pad24[0x10];
    u16 h34;
} S_003A2B48;
typedef struct G_003A2B48 {
    u8 pad0[0x25C0];
    S_003A2B48 *q;
} G_003A2B48;
extern G_003A2B48 D_001A4BE0;

void func_L03_003A2B48(void) {
    s32 i;

    D_001A4BE0.q->b23 = 0x7F;
    D_001A4BE0.q->h34 &= 0xDFFF;
    for (i = 0; i < 7; i++) {
        u8 *c = (u8 *)&D_001A4BE0 + i * 0x50;

        if (*(S_003A2B48 **)(c + 0x1200) != 0) {
            (*(S_003A2B48 **)(c + 0x1200))->b23 = 0x7F;
        }
        if (*(S_003A2B48 **)(c + 0x1204) != 0) {
            (*(S_003A2B48 **)(c + 0x1204))->b23 = 0x7F;
        }
        if (*(S_003A2B48 **)(c + 0x1208) != 0) {
            (*(S_003A2B48 **)(c + 0x1208))->b23 = 0x7F;
        }
    }
}
/* localdecomp:end func_L03_003A2B48 */

/* localdecomp:start func_L03_003A2BB8 */
#include "vu0.h"

typedef struct { u8 p0[0xC]; f32 fC; u8 p10[4]; f32 f14; f32 f18; f32 f1C; f32 f20; } S_3A2BB8;
typedef struct { u8 p0[0x10]; vu0_v4 pos; u8 p20[0x14]; u16 f34; u8 p36[0x32]; S_3A2BB8 *s; u8 p6C[0x74]; vu0_q vE0; } M_3A2BB8;


extern u8 D_L03_0021F298[];
extern s32 D_L03_001DE3F0[] __attribute__((section(".sdata")));
__asm__(".extern D_L03_001DE3F0, 8");
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_004713C8(void *, void *, s32, f32, s32, s32, s32, s32, f32, f32, s32);

#define BB8_FLD(base, T, off) (((struct { u8 pad[off]; T v; } *)(base))->v)
/* one burst at angle `ang` on the ring of radius s->r; NEWV recomputes the velocity */
#define BB8_BURST(ang, r, lo, hi, NEWV) \
    { \
        pos.x = func_0038D098(ang) * s->r; \
        pos.y = func_0038D0B0(ang) * s->r; \
        pos.z = 0.0f; \
        vec_add_ba(&pos, &pos, &m->pos); \
        pos.z = pos.z + 0.15f; \
        a = (s32)func_L01_00443A18(2.0f, 5.0f); \
        f = func_003824E0(0.1f, 0.2f); \
        NEWV \
        func_L01_004713C8(&pos, &v, (func_00382498(lo, hi) * 5 + 2) / 6, f * 210000.0f, D_L03_001DE3F0[0], a, 0x7F, 0x7F, 2100.0f, -0.0012f, 1); \
        a = -(a * 2); \
        p = func_L01_004713C8(&pos, &v, (func_00382498(lo, hi) * 5 + 2) / 6, f * 2.0f * 210000.0f, D_L03_001DE3F0[1], a, 0x30, 0x30, 4200.0f, -0.0012f, 0); \
        if (p != 0) { \
            p[2] = **(u8 **)(D_L03_0021F298 + 0xD4); \
        } \
    }
#define BB8_NEWV v = m->vE0; func_0038CF68(&v, &v, 0.040000003f);
#define BB8_SAMEV

void func_L03_003A2BB8(M_3A2BB8 *m) {
    vu0_v4 pos;
    vu0_q v;
    S_3A2BB8 *s;
    f32 b;
    s32 a;
    f32 f;
    u8 *p;

    s = m->s;
    b = func_0038DAB8(s->f18, 0.7853982f);
    BB8_BURST(s->f18, f1C, 40, 45, BB8_NEWV)
    BB8_BURST(func_0038DAB8(s->f18, 3.1415927f), f1C, 40, 45, BB8_SAMEV)
    BB8_BURST(func_0038DAB8(s->f18, 4.712389f), f1C, 40, 45, BB8_SAMEV)
    BB8_BURST(func_0038DAB8(s->f18, 1.5707964f), f1C, 40, 45, BB8_SAMEV)
    BB8_BURST(b, f20, 20, 25, BB8_NEWV)
    BB8_BURST(func_0038DAB8(b, 3.1415927f), f20, 20, 25, BB8_SAMEV)
    BB8_BURST(func_0038DAB8(b, 4.712389f), f20, 20, 25, BB8_SAMEV)
    BB8_BURST(func_0038DAB8(b, 1.5707964f), f20, 20, 25, BB8_SAMEV)

    s->f18 = func_0038DAB8(s->f18, s->f14);
    s->f1C = s->f1C - 0.008f;
    s->f14 = s->f14 + 0.0017453294f;
    if (s->f1C < 0.1f) s->f1C = 0.1f;
    s->f20 = s->f20 - 0.002f;
    if (s->f20 < 0.2f) s->f20 = 0.2f;
    if (s->f1C < 0.3f) {
        BB8_FLD(&D_001A4BE0, s16, 0x2888) = 1;
        BB8_FLD(&D_001A4BE0, f32, 0x22D0) = BB8_FLD(&D_001A4BE0, f32, 0x22D4) = s->fC;
        BB8_FLD(&D_001A4BE0, f32, 0x22D8) = 1.0f;
        s->fC = s->fC - 0.030000001f;
    }
}
/* localdecomp:end func_L03_003A2BB8 */
