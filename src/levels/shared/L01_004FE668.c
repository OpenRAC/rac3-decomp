#include "common.h"

typedef struct {
    u8 pad0[152];
    float f98;
    u8 pad1[400 - 156];
    u8 sub190[16];
    float f1A0;
    u8 pad2[5172 - 420];
    s16 h1434;
    u8 pad3;
    u8 b1437;
    u8 pad4[5808 - 5176];
    s32 mode;
    u8 pad5[9716 - 5812];
    u8 b25F4;
} Veldin1A4BE0;
typedef int s128 __attribute__((mode(TI)));
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec_4FB8C8;
typedef union {
    s128 q;
    Vec_4FB8C8 v;
} Q_4FB8C8;
typedef struct {
    u8 pad0[28];
    s32 x28;
    f32 f32;
} Pvar_4FB8C8;
typedef struct {
    u8 pad0[16];
    s128 pos;
    u8 pad32[17];
    u8 b49;
    u8 pad50[2];
    u16 h52;
    u8 pad54[50];
    Pvar_4FB8C8 *pv;
} Moby_4FB8C8;
typedef struct {
    u8 pad0[128];
    s128 v128;
    u8 pad144[8];
    f32 f152;
    u8 pad156[374];
    s16 h530;
    u8 pad532[2108];
    Moby_4FB8C8 *target;
    u8 pad2644[4];
    f32 f2648;
    u8 pad2652[2];
    s16 h2654;
    u8 pad2656[7012];
    s32 x9668;
} Player_4FB8C8;
typedef struct {
    u8 p0[16];
    s128 pos;
    u8 p20[17];
    u8 b49;
    u8 p50;
    u16 h52;
    u8 p54[116];
    s16 h170;
} M_4FBE48;
typedef struct {
    u8 p0[128];
    s128 v128;
    u8 p90[8];
    float f152;
    u8 p9C[1360];
    float f1516;
    u8 p5F0[1184];
    M_4FBE48 *f2704;
    s32 f2708;
    u8 pA98[6964];
    s32 f9676;
} G_4FBE48;
typedef struct {
    u8 p0[9540];
    s32 f9540;
} H_4FBE48;
typedef struct {
    u8 pad0[0x1B8];
    s32 x1B8;
    u8 pad1BC[0x23D4 - 0x1BC];
    s32 x23D4[16];
    s32 x2414[16];
    s32 x2454[16];
    s32 x2494;
    u8 pad2498[0x25C4 - 0x2498];
    s32 x25C4;
    s32 x25C8;
    s32 x25CC;
    s32 x25D0;
    s32 x25D4;
    s32 x25D8;
    s32 x25DC;
    s32 x25E0;
} G_4FC2D0;
typedef struct {
    u8 pad0[440];
    s32 start;
    u8 pad1[9172 - 444];
    s32 ids[32];
    s32 lens[16];
    s32 count;
} S_4FC388;
typedef struct {
    u8 p0[0x1A0];
    s32 w1A0;
} S_00502368;
typedef struct {
    u8 p0[0x1434];
    s16 h1434;
    u8 p1436[0x16B0 - 0x1436];
    s32 w16B0;
    u8 p16B4[0x2838 - 0x16B4];
    f32 f2838;
} G_00502368;

INCLUDE_ASM("asm/levels", func_L01_004FE668);

INCLUDE_ASM("asm/levels", func_L01_004FE920);

INCLUDE_ASM("asm/levels", func_L01_004FF3D0);

INCLUDE_ASM("asm/levels", func_L01_004FF5D8);

/* localdecomp:start func_L01_004FF610 */

extern Veldin1A4BE0 D_001A4BE0;
extern s32 func_L01_004606E8(s32, s32, s32, s32);
extern void func_L01_004EE850(s32, float);
extern float func_L01_004F4E20(void *, s32);
extern float func_0038DB00(float, float);
extern float func_0038DBA0(float, float);
s32 func_L01_004FF610(void) {
    s32 r = 2;
    s32 c;
    float a;
    float k;

    if (D_001A4BE0.h1434 != 0 || (D_001A4BE0.mode == 1 && func_L01_004606E8(40, 2, 0, 0) != 0)) {
        c = D_001A4BE0.b1437;
        if (c == 0) {
            r = 0;
        } else if (c == 3) {
            r = 3;
        } else if (c == 2) {
            r = 2;
        } else {
            r = 1;
        }
    } else {
        func_L01_004EE850(0, 1.0f);
        if (D_001A4BE0.b25F4 != 0) {
            a = func_L01_004F4E20(D_001A4BE0.sub190, 0);
        } else {
            a = func_0038DB00(D_001A4BE0.f1A0, D_001A4BE0.f98);
        }
        k = 0.7853982f;
        if (func_0038DBA0(a, 3.1415927f) < k) {
            r = 3;
        } else if (func_0038DBA0(a, -1.5707964f) < k) {
            r = 1;
        } else if (func_0038DBA0(a, 1.5707964f) < k) {
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L01_004FF610 */

/* localdecomp:start func_L01_004FF780 */
extern Veldin1A4BE0 D_001A4BE0;






extern Moby_4FB8C8 *D_L01_001F02E8[];
extern f32 func_0038CF00(void *a, void *b);
extern f32 func_L01_004E9470(f32 a, f32 b, f32 c, f32 d, Moby_4FB8C8 *m, s32 *out);
extern s32 func_00382380(void *v, s32 a, s32 b);
extern s32 func_003D3CB0(void *a, void *b, s32 c, s32 d, s32 e);

void func_L01_004FF780(void) {
    Player_4FB8C8 *pl;
    Player_4FB8C8 *pe;
    Player_4FB8C8 *pk;
    Moby_4FB8C8 *m;
    Moby_4FB8C8 *best_m;
    Pvar_4FB8C8 *pv;
    f32 best;
    f32 d;
    f32 lim;
    f32 a2;
    f32 c;
    f32 a;
    f32 b;
    f32 score;
    s32 i;
    Q_4FB8C8 v0;
    Q_4FB8C8 v1;

    ((Player_4FB8C8 *)&D_001A4BE0)[0].h2654 = 0;
    if (((Player_4FB8C8 *)&D_001A4BE0)[0].h530 != 0) {
        return;
    }
    best = 100000000.0f;
    best_m = 0;
    for (i = 0; i < 32; i++) {
        s32 flag;

        m = D_L01_001F02E8[i];
        if (m == 0) {
            break;
        }
        pv = m->pv;
        if (m->h52 & 1) {
            continue;
        }
        if (!(m->h52 & 0x1000)) {
            continue;
        }
        pl = ((Player_4FB8C8 *)&D_001A4BE0);
        if (3.0f < ((Vec_4FB8C8 *)&pl->v128)->z - ((Vec_4FB8C8 *)&m->pos)->z) {
            continue;
        }
        d = func_0038CF00(&pl->v128, &m->pos);
        if (pv->f32 != 0.0f && pv->f32 < d) {
            continue;
        }
        if (16.0f < d) {
            continue;
        }
        a = 1.2217305f;
        if (pl->x9668 == 44) {
            a = 1.5707964f;
        }
        b = 1.3962634f;
        if (pl->x9668 == 1 || pl->x9668 == 29) {
            b = 0.08726646f;
            a = b;
        }
        a2 = pv->f32;
        pk = ((Player_4FB8C8 *)&D_001A4BE0);
        c = pk->f152;
        lim = 16.0f;
        if (a2 != 0.0f) {
            lim = a2;
        }
        score = func_L01_004E9470(c, lim, a, b, m, &flag);
        if (flag != 0) {
            continue;
        }
        if (m->b49 == 0) {
            score += 10.0f;
        }
        if (pv->x28 >= 0 && func_00382380(&pk->v128, pv->x28, 0)) {
            continue;
        }
        if (score < best) {
            best = score;
            best_m = m;
        }
    }
    pe = ((Player_4FB8C8 *)&D_001A4BE0);
    pe->target = best_m;
    if (best_m != 0) {
        v0.q = pe->v128;
        v0.v.z += 0.5f;
        v1.q = best_m->pos;
        if (func_003D3CB0(&v0, &v1, 2, 0, 0) == 0) {
            pe->f2648 = best;
            pe->h2654 = 1;
        }
    }
}
/* localdecomp:end func_L01_004FF780 */

INCLUDE_ASM("asm/levels", func_L01_004FFA10);

/* localdecomp:start func_L01_004FFD00 */
extern f32 func_L01_004E9470(f32 a, f32 b, f32 c, f32 d, Moby_4FB8C8 *m, s32 *out);
extern Veldin1A4BE0 D_001A4BE0;




extern H_4FBE48 D_001A4C60;
extern M_4FBE48 *D_L01_001F03E8[];
extern s32 func_L01_00456250(M_4FBE48 *);
extern float func_0038CF00(void *, void *);
extern float func_0038CF38(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);

s32 func_L01_004FFD00(void) {
    M_4FBE48 *best;
    M_4FBE48 *m;
    s32 i;
    float bestDist, d, a, c, e;
    s32 out;
    s128 v[2];

    if ((*(G_4FBE48 *)&D_001A4BE0).f9676 == 33) return (*(G_4FBE48 *)&D_001A4BE0).f2708;
    (*(G_4FBE48 *)&D_001A4BE0).f2708 = 0;
    best = 0;
    bestDist = 100000000.0f;
    for (i = 0; i < 32; i++) {
        m = D_L01_001F03E8[i];
        if (m == 0) break;
        if (m->h170 != 2461) continue;
        if (m->h52 & 1) continue;
        if (func_L01_00456250(m)) continue;
        if (func_0038CF00(&D_001A4C60, &m->pos) > 30.0f) continue;
        c = 0.52359879f;
        e = -1.0f;
        if (D_001A4C60.f9540 == 1 || D_001A4C60.f9540 == 29) {
            c = e = 0.08726646f;
        }
        a = (*(G_4FBE48 *)&D_001A4BE0).f152;
        if ((*(G_4FBE48 *)&D_001A4BE0).f9676 == 15) a = (*(G_4FBE48 *)&D_001A4BE0).f1516;
        d = ((float (*)(float, float, float, float, M_4FBE48 *, s32 *))func_L01_004E9470)(a, 30.0f, c, e, m, &out);
        if (out != 0) continue;
        if (func_0038CF38(&(*(G_4FBE48 *)&D_001A4BE0).v128, &m->pos) < 4.0f) continue;
        if (m->b49 == 0) d += 10.0f;
        if (d < bestDist) {
            bestDist = d;
            best = m;
        }
    }
    if (best) {
        v[0] = (*(G_4FBE48 *)&D_001A4BE0).v128;
        (*(G_4FBE48 *)&D_001A4BE0).f2704 = best;
        ((float *)&v[0])[2] += 0.5f;
        v[1] = best->pos;
        if (func_003D3CB0(&v[0], &v[1], 2, 0, 0) == 0) (*(G_4FBE48 *)&D_001A4BE0).f2708 = 1;
    }
    return (*(G_4FBE48 *)&D_001A4BE0).f2708;
}
/* localdecomp:end func_L01_004FFD00 */

INCLUDE_ASM("asm/levels", func_L01_004FFF58);

/* localdecomp:start func_L01_00500188 */
extern Veldin1A4BE0 D_001A4BE0;
void func_L01_00500188(void) {
    s32 n = (*(G_4FC2D0 *)&D_001A4BE0).x2494;
    s32 i;
    if (n >= 16) {
        n = 15;
    }
    for (i = n - 1; i >= 0; i--) {
        (*(G_4FC2D0 *)&D_001A4BE0).x23D4[i + 1] = (*(G_4FC2D0 *)&D_001A4BE0).x23D4[i];
        (*(G_4FC2D0 *)&D_001A4BE0).x2414[i + 1] = (*(G_4FC2D0 *)&D_001A4BE0).x2414[i];
        (*(G_4FC2D0 *)&D_001A4BE0).x2454[i + 1] = (*(G_4FC2D0 *)&D_001A4BE0).x2454[i];
    }
    (*(G_4FC2D0 *)&D_001A4BE0).x23D4[0] = (*(G_4FC2D0 *)&D_001A4BE0).x25C4;
    (*(G_4FC2D0 *)&D_001A4BE0).x2414[0] = (*(G_4FC2D0 *)&D_001A4BE0).x25CC;
    (*(G_4FC2D0 *)&D_001A4BE0).x2454[0] = (*(G_4FC2D0 *)&D_001A4BE0).x1B8;
    (*(G_4FC2D0 *)&D_001A4BE0).x2494++;
    if ((*(G_4FC2D0 *)&D_001A4BE0).x2494 > 16) {
        (*(G_4FC2D0 *)&D_001A4BE0).x2494 = 16;
    }
    (*(G_4FC2D0 *)&D_001A4BE0).x25DC = (*(G_4FC2D0 *)&D_001A4BE0).x25D0;
    (*(G_4FC2D0 *)&D_001A4BE0).x25E0 = (*(G_4FC2D0 *)&D_001A4BE0).x25D4;
    (*(G_4FC2D0 *)&D_001A4BE0).x25D8 = (*(G_4FC2D0 *)&D_001A4BE0).x1B8;
    (*(G_4FC2D0 *)&D_001A4BE0).x25D0 = (*(G_4FC2D0 *)&D_001A4BE0).x25C4;
    (*(G_4FC2D0 *)&D_001A4BE0).x25D4 = (*(G_4FC2D0 *)&D_001A4BE0).x25CC;
}
/* localdecomp:end func_L01_00500188 */

/* localdecomp:start func_L01_00500240 */
extern Veldin1A4BE0 D_001A4BE0;
s32 func_L01_00500240(s32 a0, s32 a1) {
    s32 i;
    s32 acc = (*(S_4FC388 *)&D_001A4BE0).start;
    for (i = 0; i < (*(S_4FC388 *)&D_001A4BE0).count; i++) {
        if (a1 < acc) return 0;
        if ((*(S_4FC388 *)&D_001A4BE0).ids[i] == a0) return 1;
        acc += (*(S_4FC388 *)&D_001A4BE0).lens[i];
    }
    return 0;
}
/* localdecomp:end func_L01_00500240 */

INCLUDE_ASM("asm/levels", func_L01_005002B8);

INCLUDE_ASM("asm/levels", func_L01_005003D0);

/* localdecomp:start func_L01_00504E38 */
extern u8 D_001A71C4[];
extern void func_L01_005003D0(s32, s32);

void func_L01_00504E38(s32 arg0)
{
    s32 mode;

    mode = 1;
    if (arg0 != 0) {
        mode = 2;
    }
    switch (D_001A71C4[0]) {
    case 0:
        func_L01_005003D0(0, mode);
        break;
    case 3:
        func_L01_005003D0(81, mode);
        break;
    case 1:
        func_L01_005003D0(63, mode);
        break;
    }
}
/* localdecomp:end func_L01_00504E38 */

INCLUDE_ASM("asm/levels", func_L01_00504EC0);

/* localdecomp:start func_L01_00504F70 */
extern Veldin1A4BE0 D_001A4BE0;
extern s32 D_L01_001E2E90[];
extern void func_L01_005003D0(s32 a0, s32 a1);

s32 func_L01_00504F70(void) {
    u8 *p = ((u8 *)&D_001A4BE0);
    if (*(s32 *)(p + 9676) != 17) {
        return 0;
    }
    if (!(*(f32 *)(p + 848) + 0.4f < *(f32 *)(p + 136))) {
        return 0;
    }
    D_L01_001E2E90[0] = 0;
    func_L01_005003D0(6, 1);
    return 1;
}
/* localdecomp:end func_L01_00504F70 */

INCLUDE_ASM("asm/levels", func_L01_00504FE0);

INCLUDE_ASM("asm/levels", func_L01_00505380);

INCLUDE_ASM("asm/levels", func_L01_005055A0);

/* localdecomp:start func_L01_00506298 */
extern Veldin1A4BE0 D_001A4BE0;
extern s32 func_L01_004606E8(s32, s32, s32, s32);


extern s32 func_003A3BB8(s32, s32);
extern s32 func_L01_004FF5D8(void);
extern s32 func_L01_00460778(s32, s32, s32, s32, s32);
extern s32 func_L01_004FF610(void);
extern void func_L01_005003D0(s32, s32);
extern S_00502368 *D_001D52FC;

s32 func_L01_00506298(s32 a, s32 b) {
    u8 buf[16];
    s32 n;
    if (((s32 (*)(s32, s32, void *, s32))func_L01_004606E8)(func_003A3BB8(64, 0), a, buf, 0) == 0) {
        return 0;
    }
    n = func_L01_004FF5D8();
    if ((D_001D52FC->w1A0 & func_003A3BB8(8, 0)) && n > 0
        && func_L01_00460778(func_003A3BB8(64, 0), 0x1F000, a + n, n, 0) != 0) {
        func_L01_005003D0(11, 1);
        return 1;
    }
    if (((*(G_00502368 *)&D_001A4BE0).h1434 != 0 || ((*(G_00502368 *)&D_001A4BE0).w16B0 == 1 && ((s32 (*)(s32, s32, void *, s32))func_L01_004606E8)(40, 2, 0, 0) != 0))
        && (*(G_00502368 *)&D_001A4BE0).f2838 > 0.9f && func_L01_004FF610() != 2) {
        func_L01_005003D0(11, 1);
        return 1;
    }
    if (b != 0) {
        return 0;
    }
    func_L01_005003D0(7, 1);
    return 1;
}
/* localdecomp:end func_L01_00506298 */
