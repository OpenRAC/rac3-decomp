#include "common.h"

/* localdecomp:start func_L39_005794E0 */
__asm__(".extern D_L39_0024B850, 16");
typedef struct { u8 p0[0x7C]; u8 b7C; u8 p7D; s16 h7E; } P_005794E0;
typedef struct { u32 state; u8 p4[4]; u8 b8; u8 b9; } G_005794E0;
typedef struct {
    u8 p0[0x74];
    G_005794E0 g;
    u8 p80[0x84 - 0x80];
    s16 h84;
    s16 h86;
    u8 p88[4];
    s16 h8C;
} S_005794E0;
typedef struct { u8 p0[4]; s32 (*f4)(void *, void *); u8 p8[0x14 - 8]; } T_005794E0;
typedef struct { u8 p0[0x1C]; u8 *f1C; } R_005794E0;
typedef struct { u8 p0[0x40]; u8 f40[0x10]; } V_005794E0;
typedef struct { u8 p0[0x150]; V_005794E0 v150; u8 p1A0[0x24C - 0x1A0]; s32 f24C; u8 p250[0x460 - 0x250]; } E_005794E0;
extern T_005794E0 D_L39_004B2F80[];
extern R_005794E0 *D_L39_0024B850;
extern E_005794E0 D_L39_0024DE80[];
extern s32 func_L39_005B42B0(void *, void *, s32);

s32 func_L39_005794E0(s32 a0, S_005794E0 *s, P_005794E0 *a2) {
    G_005794E0 *g = &s->g;
    s32 r;
    s32 h;
    u8 *p;
    E_005794E0 *e;

    if (s->g.b8 == 0) {
        return 0;
    }
    if (D_L39_004B2F80[s->h8C].f4 != 0) {
        r = D_L39_004B2F80[s->h8C].f4(s, a2);
        if (r == -1) return 0;
        if (r == 1) return 1;
    }
    switch (g->state) {
    case 1:
    case 2:
        if (g->b9 == 0) break;
    case 0:
        if (a2 == 0) return 1;
        if (a2->h7E != 0) return 1;
        if (g->b8 > a2->b7C) return 1;
        break;
    case 4:
        p = D_L39_0024B850[s->h84].f1C;
        if (a2 != 0 && a2->h7E == 0 && !(g->b8 > a2->b7C)) break;
        if (func_L39_005B42B0(D_L39_0024DE80[a0].v150.f40, *(void **)(p + 0xC), 0)) return 1;
        break;
    case 7:
        e = &D_L39_0024DE80[a0];
        h = s->h86;
        if (h != e->f24C) break;
        if (a2->h7E == 0 && !(g->b8 > a2->b7C)) break;
        return h != 3;
    }
    return 0;
}
/* localdecomp:end func_L39_005794E0 */
