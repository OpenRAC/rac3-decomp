#include "common.h"

LINKER_REMNANT("asm/levels", func_L39_005A0008);

/* localdecomp:start func_L39_005A0010 */
typedef int u128_t __attribute__((mode(TI)));

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
} Rec_005A0010;

typedef struct {
    u8 pad0[0xA];
    s16 fA;
    u8 padC[4];
} Tab_005A0010;

typedef struct {
    u8 b0;
    u8 pad1[0xB];
    s32 fC;
} Ent_005A0010;

typedef struct {
    u8 pad0[0x10];
    u8 b10;
    u8 pad11[3];
    s32 f14;
    u8 pad18[4];
    s32 f1C[1];
} Obj_005A0010;

typedef struct {
    s32 f0;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 pad7;
    u8 b8;
    u8 pad9[2];
    u8 bB;
    u8 bC;
    u8 padD[3];
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
    u8 pad24[4];
    s32 f28;
    u8 b2C;
    u8 pad2D[0x1A];
    u8 b47;
    s32 tbl[1];
} S_005A0010;

extern s32 D_001FC450[];
extern u8 D_L39_00268A40[];
extern u8 D_L39_00272590[];
extern u8 D_L39_002757B0[];
extern void func_00399810(s32, void *, void *, s32);

void func_L39_005A0010(S_005A0010 *p, Tab_005A0010 *a1, u8 *a2, s32 a3)
{
    s32 n;
    Rec_005A0010 *r;
    s32 k;
    s32 q;

    n = p->b4 + p->b5 + p->b6;
    if (p->b2C != 0) {
        n += *((u8 *)p + (p->b2C << 4) + 1);
    }
    if (p->f0 != 0) {
        p->f0 = (s32)p + p->f0;
        r = (Rec_005A0010 *)p->f0;
        for (k = 0; k < n; k++) {
            r->f0 = r->f0 + (s32)p;
            r->f8 = r->f8 + (s32)p;
            r++;
        }
    }
    if (p->f10 != 0) {
        p->f10 = (s32)p + p->f10;
    }
    if (p->f14 != 0) {
        p->f14 = (s32)p + p->f14;
    }
    if (p->f18 != 0) {
        p->f18 = (s32)p + p->f18;
    }
    if (p->f1C != 0) {
        s32 cnt;
        s32 i;

        p->f1C = (s32)p + p->f1C;
        cnt = *(s32 *)p->f1C;
        for (i = 0; i < cnt; i++) {
            ((s32 *)p->f1C)[i + 1] = ((s32 *)p->f1C)[i + 1] + (s32)p;
        }
    }
    if (p->f20 != 0) {
        Ent_005A0010 *e;

        p->f20 = (s32)p + p->f20;
        e = (Ent_005A0010 *)p->f20;
        for (;;) {
            u8 *d;

            e->fC = e->fC + (s32)p;
            d = (u8 *)e;
            if (e->b0 != 0xFF) {
                do {
                    *d = a2[*d];
                    d++;
                } while (*d != 0xFF);
            }
            if (e->fC < 0) {
                break;
            }
            e++;
        }
    }
    if (p->bB != 0) {
        u8 hi = p->bB >> 4;
        s32 lo = p->bB & 0xF;
        s16 *dst = (s16 *)(p->f20 - ((lo * hi) << 10) - 0x10);
        s32 m;
        s16 v;

        for (m = 0; m < hi; m++) {
            if (a1 != 0) {
                v = a1[a2[m]].fA;
                dst[m] = v + (D_001FC450[8] >> 8);
            } else {
                dst[m] = (u16)((*(unsigned long *)(D_L39_00268A40 + a2[m] * 0x18) >> 37) & 0x3FFF);
            }
        }
    }
    if (p->f28 != 0) {
        p->f28 = (s32)p + p->f28;
    }
    for (q = 0; q < p->bC; q++) {
        Obj_005A0010 *o;
        s32 t;

        if (p->tbl[q] != 0) {
            o = (Obj_005A0010 *)((s32)p + p->tbl[q]);
            p->tbl[q] = (s32)o;
            if (p->b8 == 0) {
                if (o->b10 >= 2) {
                    o->b10 = 1;
                }
            }
            if (o->f14 != 0) {
                o->f14 = (s32)o + o->f14;
            }
            for (t = 0; t < o->b10; t++) {
                o->f1C[t] = (s32)p + o->f1C[t];
            }
        }
    }
    if (a3 >= 0) {
        *(u128_t *)(D_L39_002757B0 + (D_L39_00272590[a3] << 4)) = *(u128_t *)a2;
    }
    if (p->f0 != 0) {
        func_00399810(p->f0, a1, a2, n);
    }
    if (p->b47 == 0xFF) {
        p->b47 = 0;
    }
}
/* localdecomp:end func_L39_005A0010 */
