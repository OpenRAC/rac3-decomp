#include "common.h"

/* localdecomp:start func_L39_00546F30 */
typedef struct {
    char pad0[0x3];
    u8 flags;
} Ent;

extern Ent *func_L39_0061D7B0(s32);

void func_L39_00546F30(s32 id, f32 *a, f32 *b) {
    Ent *e = func_L39_0061D7B0(id);
    Ent *r;

    r = 0;
    if (e != 0) {
        if (e->flags & 0xF) {
            r = 0;
        } else {
            r = e;
        }
    }

    if (r != 0) {
        if (a != 0) {
            *a = 4.0f;
        }
        if (b != 0) {
            *b = 7.0f;
        }
    } else {
        if (a != 0) {
            *a = 7.0f;
        }
        if (b != 0) {
            *b = 15.0f;
        }
    }
}
/* localdecomp:end func_L39_00546F30 */

INCLUDE_ASM("asm/levels", func_L39_00546FE0);

/* localdecomp:start func_L39_00547E10 */
#include "vu0.h"

typedef struct {
    u8 pad0[0x2524];
    void *f2524;
    u8 pad2528[0x2544 - 0x2528];
    s32 f2544;
    s32 f2548;
} P_00547E10;

typedef struct {
    u8 pad0[0x50];
    P_00547E10 *f50;
} Q_00547E10;

typedef struct {
    u8 pad0[0x68];
    Q_00547E10 *f68;
} O_00547E10;

typedef struct {
    vu0_v4 v;
    f32 f10;
    f32 f14;
    f32 f18;
    f32 f1C;
} R_00547E10;

typedef struct {
    u8 pad0[0x21];
    s8 b21;
    u8 pad22[0x30 - 0x22];
    f32 f30;
    u8 pad34[0x80 - 0x34];
} E_00547E10;

typedef struct {
    u8 pad0[0x98];
    s32 f98;
} M_00547E10;

typedef struct {
    u8 pad0[0x18];
    M_00547E10 *x18;
    s32 x1C;
    vu0_v4 x20;
} G_00547E10;

extern P_00547E10 *D_L39_0024CE20_00547E10[];
extern G_00547E10 D_L39_0025F740_00547E10;
extern E_00547E10 D_L39_0049C890_00547E10[];
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CF00(void *, void *);
extern void func_L01_00446978_00547E10(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_L39_005FFDF8_00547E10(s32);
extern void func_L39_005FFE78_00547E10(void);
extern s32 func_L39_00648AE0_00547E10(u8 *, s32);
extern void *func_L39_0054D5F8_00547E10(vu0_v4 *, vu0_v4 *, vu0_v4 *, s32, s32, u8 *);

M_00547E10 *func_L39_00547E10(O_00547E10 *a0, vu0_v4 *a1, vu0_v4 *a2, R_00547E10 *a3, f32 ang) {
    vu0_v4 d;
    f32 s10;
    f32 s14;
    P_00547E10 *p;
    P_00547E10 *q;
    void *t;
    s32 id;
    s32 hit;
    E_00547E10 *e;
    f32 speed;
    f32 dist;
    f32 k;
    f32 a;
    M_00547E10 *r;
    f32 lim;

    p = a0->f68->f50;
    if (p == 0) {
        return 0;
    }
    vec_sub_ab(a3, a2, a1);
    func_0038CF68(a3, a3, 1.5f);
    a3->v.w = 5627.9248f;
    id = p->f2544;
    t = p->f2524;
    q = D_L39_0024CE20_00547E10[id];
    id = -1;
    if (q != 0) {
        id = q->f2548;
    }
    func_L39_005FFDF8_00547E10(id);
    hit = func_003D3CB0(a1, a2, 0x10, t, 0);
    func_L39_005FFE78_00547E10();
    if (hit != 0) {
        vec_sub_ab(&d, a2, a1);
        func_0038CF68(&d, &d, 1.0f);
        vec_sub_ab(&d, &D_L39_0025F740_00547E10.x20, a1);
        func_L39_0054D5F8_00547E10(a1, &d, &D_L39_0025F740_00547E10.x20, 1, (s32)a0, (u8 *)p);
        if (D_L39_0025F740_00547E10.x18 != 0 && D_L39_0025F740_00547E10.x18->f98 != 0) {
            {
                s32 i = 2;

                if (func_L39_00648AE0_00547E10((u8 *)p, i)) {
                    e = &D_L39_0049C890_00547E10[D_L39_0049C890_00547E10[i].b21];
                } else {
                    e = &D_L39_0049C890_00547E10[i];
                }
            }
            speed = e->f30;
            dist = func_0038CF00(&D_L39_0025F740_00547E10.x20, a1);
            a = ang - 0.0872664601f;
            if (a < 0.0f) {
                a = 0.0f;
            }
            k = a / 0.239982769f * 0.5f;
            k = 1.0f - k;
            lim = 33.0f;
            func_L39_00546F30_00547E10((s32)D_L39_0025F740_00547E10.x18, &s10, &s14);
            if (s14 < 10.0f) {
                lim = 11.5f;
            }
            if (dist < s10) {
                a3->f1C = (speed + speed) * k;
            } else if (dist < s14) {
                a3->f1C = speed * k;
            } else if (dist < lim) {
                a3->f1C = speed * 0.6f;
            } else {
                a3->f1C = speed * 0.3f;
            }
            func_L01_00446978_00547E10(D_L39_0025F740_00547E10.x18, a3);
        }
        r = D_L39_0025F740_00547E10.x18;
    } else {
        vec_sub_ab(&d, a2, a1);
        func_L39_0054D5F8_00547E10(a1, &d, a2, 0, (s32)a0, (u8 *)p);
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L39_00547E10 */
