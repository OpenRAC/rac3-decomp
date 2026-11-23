#include "common.h"

/* NTSC-U counterpart of func_L01_003EBF40 (src/levels/shared/L01_003EB9C8.c): 100 -> 120; 50 -> 60 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad0[512];
    u8 b200[48];
    u128_t v230;
    u8 pad240[675 - 576];
    u8 b2A3;
    u8 pad2A4[696 - 676];
    f32 f2B8;
    u8 pad2BC[712 - 700];
    f32 f2C8;
    u8 pad2CC[1120 - 716];
} Ent003EC730;

/* localdecomp:start func_L01_003EA090 */
typedef int q_3EBF40 __attribute__((mode(TI)));
typedef struct {
    s32 x0;
    f32 x4;
    f32 x8;
    s32 xC;
} S30_3EBF40_003EBF40;
typedef struct {
    q_3EBF40 x0;
    f32 x10;
    f32 x14;
    s32 x18;
    s16 h1C;
    s16 h1E;
    u8 pad20[0x10];
    S30_3EBF40_003EBF40 s;
} P0_3EBF40_003EBF40;
typedef struct {
    u8 pad0[0x30];
    f32 x30;
    f32 x34;
    s32 x38;
    s32 x3C;
    s32 x40;
    s32 x44;
    f32 x48;
    f32 x4C;
    u8 pad50[8];
    f32 x58;
    f32 x5C;
} Q_3EBF40_003EBF40;
typedef struct {
    f32 x0;
    f32 x4;
    u8 pad8[8];
    f32 x10;
    f32 x14;
} A_3EBF40_003EBF40;
typedef struct {
    f32 x0;
    s32 x4;
    void *x8;
} T_3EBF40_003EBF40;
typedef struct {
    P0_3EBF40_003EBF40 p0;
    Q_3EBF40_003EBF40 q;
    A_3EBF40_003EBF40 a;
    T_3EBF40_003EBF40 t;
} P_3EBF40_003EBF40;
typedef struct {
    q_3EBF40 x0;
    q_3EBF40 x10;
    q_3EBF40 x20;
    q_3EBF40 x30;
} S_3EBF40_003EBF40;
typedef struct {
    u8 pad0[0xF0];
    s32 xF0;
    u8 padF4[0x100 - 0xF4];
    s32 x100;
    u8 pad104[0x138 - 0x104];
    u8 *x138;
    f32 x13C;
} B_3EBF40_003EBF40;
typedef struct {
    u8 pad0[0x54];
    S_3EBF40_003EBF40 *x54;
    u8 pad58[0x150 - 0x58];
    B_3EBF40_003EBF40 b;
    u8 pad290[0x2A0 - 0x290];
    s16 h2A0;
    u8 pad2A2;
    u8 b2A3;
    u8 pad2A4[0x324 - 0x2A4];
    s32 x324;
} E_3EBF40_003EBF40;
typedef struct {
    q_3EBF40 x0;
    q_3EBF40 x10;
    q_3EBF40 x20;
    q_3EBF40 x30;
    q_3EBF40 x40;
    u8 pad50[0x20];
    P_3EBF40_003EBF40 *pv;
    u8 pad74[0x7E - 0x74];
    s16 h7E;
    u8 pad80[0x94 - 0x80];
    s32 w94;
} M_3EBF40_003EBF40;
extern Ent003EC730 D_L01_001E2AC0_003EA090[];
extern f32 func_00388960_003EA090(f32);
extern f32 func_00388978_003EA090(f32);
extern void func_00388830_003EA090(void *, void *, f32);
extern f32 func_00388A28_003EA090(f32, f32);

void func_L01_003EA090(u8 *mp) {
    M_3EBF40_003EBF40 *m = (M_3EBF40_003EBF40 *)mp;
    E_3EBF40_003EBF40 *e = (E_3EBF40_003EBF40 *)&D_L01_001E2AC0_003EA090[m->w94];
    P_3EBF40_003EBF40 *pv = m->pv;
    Q_3EBF40_003EBF40 *q = &pv->q;
    B_3EBF40_003EBF40 *b = &e->b;
    P_3EBF40_003EBF40 *pv2;
    T_3EBF40_003EBF40 *t;
    A_3EBF40_003EBF40 *a;
    P0_3EBF40_003EBF40 *p0;
    S30_3EBF40_003EBF40 *s;
    P_3EBF40_003EBF40 *pb;

    q->x4C = 1.5f;
    q->x48 = 0.20943952f;
    q->x58 = 0.0017453292f;
    q->x5C = -0.004363323f;
    q->x40 = 0;
    q->x44 = b->xF0;
    a = &m->pv->a;
    a->x0 = 4.64f;
    a->x4 = 0.5f;
    a->x10 = 2.0f;
    a->x14 = 0.05f;
    p0 = &m->pv->p0;
    qzero(&p0->x0);
    p0->x10 = 0.01f;
    p0->x14 = 0.3f;
    p0->h1E = 120;
    p0->h1C = 0;
    p0->x18 = 0;
    pb = m->pv;
    s = &pb->p0.s;
    s->x4 = 0.02f;
    s->x8 = 0.2f;
    s->xC = 0;
    pb->p0.s.x0 = 0;
    pv2 = m->pv;
    t = &pv2->t;
    t->x4 = 0;
    m->x30 = e->x54->x30;
    m->x0 = e->x54->x0;
    m->x10 = e->x54->x10;
    m->x20 = e->x54->x20;
    m->x40 = m->x0;
    m->h7E = 0;
    if ((u32)(b->x100 - 0x2B) < 2) {
        pv2->t.x0 = b->x13C;
        t->x8 = b->x138;
        q->x30 = func_00388960_003EA090(pv2->t.x0);
        q->x34 = func_00388978_003EA090(pv2->t.x0);
        q->x38 = 0;
    } else {
        vec_sub_ba(&q->x30, b->x138 + 0x10, &m->x30);
        q->x38 = 0;
        q->x3C = 0;
        func_00388830_003EA090(&q->x30, &q->x30, 1.0f);
        pv2->t.x0 = func_00388A28_003EA090(q->x30, q->x34);
        t->x8 = b->x138;
    }
    e->b2A3 = 2;
    e->h2A0 = 1;
    ((E_3EBF40_003EBF40 *)&D_L01_001E2AC0_003EA090[m->w94])->x324 = 60;
}
/* localdecomp:end func_L01_003EA090 */
