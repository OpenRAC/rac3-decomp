#include "common.h"

/* localdecomp:start func_L24_0043C3B0 */
typedef int q_0043C3B0 __attribute__((mode(TI)));

typedef struct M_0043C3B0 {
    u8 pad0[0x10];
    q_0043C3B0 q10;
    u8 b20;
    u8 pad21[0x34 - 0x21];
    u16 h34;
    u8 pad36[0x68 - 0x36];
    u8 *p68;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} M_0043C3B0;

typedef struct T_0043C3B0 {
    q_0043C3B0 q0;
    M_0043C3B0 *p10;
    s16 h14;
    u8 pad16[0x1C - 0x16];
    s16 h1C;
} T_0043C3B0;

typedef struct H_0043C3B0 {
    u8 pad0[0xD0];
    q_0043C3B0 qD0;
    u8 padE0[0x25C0 - 0xE0];
    M_0043C3B0 *x25C0;
    s32 x25C4;
} H_0043C3B0;

typedef struct D_0043C3B0 {
    u8 pad0[0x10];
    f32 f10;
} D_0043C3B0;

extern H_0043C3B0 D_001A4BE0;
extern s32 D_L24_001D6694;
extern s32 D_L24_001D673C;
extern s32 D_L24_001D6774;
extern u8 *D_L24_001DF51C;
extern s16 D_L24_001DF680[2];
extern s16 D_L24_001DF6C0[2];
extern M_0043C3B0 *D_L24_001EE528[];

extern M_0043C3B0 *func_L01_00456910(M_0043C3B0 *m, s32 a1, s32 *out, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, f32 scale);
extern int func_L01_00456B40(u8 *p, u8 *q, f32 f12, f32 f13);
extern f32 func_L01_004566F8(M_0043C3B0 *a, M_0043C3B0 *b, s32 c, s32 d, s32 e, s32 g, f32 scale);
extern D_0043C3B0 *func_00382348(M_0043C3B0 *m);
extern void func_L01_00450E48(void *, void *, f32, f32, f32);

/* from rac2-decomp's func_002B3BA8 */
s32 func_L24_0043C3B0(M_0043C3B0 *m, f32 range, f32 height, s32 mode, q_0043C3B0 *pos, s32 force) {
    f32 at[4] __attribute__((aligned(16)));
    s32 kind;
    T_0043C3B0 *t;
    M_0043C3B0 *e;
    M_0043C3B0 *best;
    s32 bestKind;
    f32 bestDist;
    f32 d;
    s32 i;
    D_0043C3B0 *dmg;

    if (!(m->h34 & 0x20)) {
        return 0;
    }
    t = *(T_0043C3B0 **)(m->p68 + 0xC);
    if (pos != 0) {
        *(q_0043C3B0 *)at = *pos;
    } else {
        *(q_0043C3B0 *)at = m->q10;
    }
    t->p10 = D_001A4BE0.x25C0;
    t->q0 = D_001A4BE0.qD0;
    t->h1C = 0;
    t->h14 = 0;
    if (force == 0) {
        if (D_L24_001D6694 != 0) {
            return 0;
        }
        if (D_001A4BE0.x25C4 == 0x74) {
            return 0;
        }
    }
    if (mode != -1) {
        e = func_L01_00456910(m, mode, &kind, 0, 0, 0, 0, 0, 1.0f);
        if (e == 0) {
            return t->h14;
        }
        t->p10 = e;
        t->h14 = 1;
        t->h1C = kind;
        if (e != D_001A4BE0.x25C0) {
            t->q0 = e->q10;
            dmg = func_00382348(e);
            if (dmg != 0) {
                if (D_L24_001D673C == 0) {
                    *(f32 *)((u8 *)t + 8) += dmg->f10;
                } else {
                    func_L01_00450E48(e, t, 0.0f, 0.0f, dmg->f10);
                }
            }
        }
        return t->h14;
    }

    bestDist = 9999999.0f;
    best = 0;
    bestKind = 0;
    e = D_001A4BE0.x25C0;
    if (func_L01_00456B40((u8 *)e, (u8 *)at, range, height)) {
        d = func_L01_004566F8(m, e, 0, 0, 0, 0, 1.0f);
        if (d < bestDist) {
            best = e;
            bestDist = d;
            bestKind = 1;
        }
    }
    for (i = 1; i <= D_L24_001DF680[0]; i++) {
        e = (M_0043C3B0 *)(D_L24_001DF51C + (D_L24_001DF680[i] << 8));
        if (e != 0 && e->hAA == 0xCB && e->b20 != 0xFE && e->b20 != 0xFD && e->b20 == 3) {
            if (func_L01_00456B40((u8 *)e, (u8 *)at, range, height)) {
                d = func_L01_004566F8(m, e, 0, 0, 0, 0, 1.0f);
                if (d < bestDist) {
                    best = e;
                    bestDist = d;
                    bestKind = 2;
                }
            }
        }
    }
    for (i = 0; i < D_L24_001D6774; i++) {
        e = D_L24_001EE528[i];
        if (func_L01_00456B40((u8 *)e, (u8 *)at, range, height)) {
            if (e != 0 && e->b20 != 0xFE && e->b20 != 0xFD && e != m) {
                d = func_L01_004566F8(m, e, 0, 0, 0, 0, 1.0f);
                if (d < bestDist) {
                    best = e;
                    bestDist = d;
                    bestKind = 3;
                }
            }
        }
    }
    for (i = 1; i <= D_L24_001DF6C0[0]; i++) {
        e = (M_0043C3B0 *)(D_L24_001DF51C + (D_L24_001DF6C0[i] << 8));
        if (e != 0 && e->hAA == 0x1BC3 && e->b20 != 0xFE && e->b20 != 0xFD) {
            if (func_L01_00456B40((u8 *)e, (u8 *)at, range, height)) {
                d = func_L01_004566F8(m, e, 0, 0, 0, 0, 1.0f);
                if (d < bestDist) {
                    best = e;
                    bestDist = d;
                    bestKind = 4;
                }
            }
        }
    }
    if (best != 0) {
        t->h1C = bestKind;
        t->h14 = 1;
        t->p10 = best;
        if (best == D_001A4BE0.x25C0) {
            t->q0 = D_001A4BE0.qD0;
        } else {
            t->q0 = best->q10;
            dmg = func_00382348(best);
            if (dmg != 0) {
                if (D_L24_001D673C != 0) {
                    func_L01_00450E48(best, t, 0.0f, 0.0f, dmg->f10);
                } else {
                    *(f32 *)((u8 *)t + 8) += dmg->f10;
                }
            }
        }
    }
    return t->h14;
}
/* localdecomp:end func_L24_0043C3B0 */
