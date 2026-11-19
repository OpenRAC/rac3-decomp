#include "common.h"

/* localdecomp:start func_L39_00694418 */
typedef struct { s32 f0; u8 pad[0x30]; u8 f34; } S_00694418b;
typedef struct { u8 pad[0x38]; S_00694418b *f38; } S_00694418a;
typedef struct { u8 pad[0x288]; s32 state; } S_00694418c;
extern S_00694418a *D_L39_0024D760_00694418;
extern S_00694418c *D_L39_00247914;
extern S_00694418c *D_001DC204_sda;
extern char D_L39_00247EE0[];
extern void *func_00381FF0(s32);
extern s32 func_L39_006872E8(S_00694418c *, void *, char *, s32, s32, f32);
s32 func_L39_00694418(void)
{
    S_00694418b *p = D_L39_0024D760_00694418->f38;
    if (p->f34 != 0) {
        D_001DC204_sda->state = 9;
        return 1;
    }
    if (p->f0 < 0) {
        S_00694418c *o = D_L39_00247914;
        func_L39_006872E8(o, func_00381FF0(0x1732), D_L39_00247EE0, 4, 0, 0.6f);
        D_L39_00247914->state = 0x19;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_00694418 */

/* localdecomp:start func_L39_006944B0 */
typedef struct W_006944B0 W_006944B0;
typedef struct {
    u8 pad0[0x8C];
    s32 (*get)(W_006944B0 *);
    u8 pad1[0xB4 - 0x90];
    void (*clear)(W_006944B0 *);
    void (*text)(W_006944B0 *, char *);
} WV_006944B0;
struct W_006944B0 {
    u8 pad[0x60];
    WV_006944B0 *vt;
};
typedef struct {
    u8 pad0[0x114];
    W_006944B0 *f114;
    u8 pad1[4];
    W_006944B0 *f11c;
    W_006944B0 *f120;
    u8 pad2[0x290 - 0x124];
    s32 f290;
    u8 pad3[0x2C8 - 0x294];
    s32 f2c8[(0x3D0 - 0x2C8) / 4];
    s32 f3d0;
    s32 f3d4;
} S_006944B0;
typedef struct {
    u8 pad[0x3BC];
    u8 f3bc;
} M_006944B0;
typedef struct {
    u8 pad[0x40];
    s32 f40;
    s32 f44;
} A_006944B0;
typedef struct {
    u8 pad[0x1C];
    s32 f1c;
} R_006944B0;
typedef struct {
    u8 pad0[0x30];
    s32 *f30;
    u8 pad1[4];
    M_006944B0 *f38;
    void *f3c;
    u8 pad2[4];
    void *f44;
    void *f48;
} G_006944B0;
typedef struct {
    u8 pad[0x1E0];
} B_006944B0;
extern G_006944B0 *D_L39_0024D760;
extern char D_L39_00247EF0[];
extern A_006944B0 *func_L39_006D98C8(void *, s32);
extern A_006944B0 *func_L39_006D9328(void *, s32);
extern R_006944B0 *func_L39_006D6CF8(void *, s32, s32, s32);
extern void *func_L39_006D4380(void *, s32);
extern void func_L39_006CC120(B_006944B0 *);
extern void func_L39_006CC4F8(B_006944B0 *, void *);
extern s32 func_L39_006CC350(B_006944B0 *, s32);
extern void func_L39_006CC158(B_006944B0 *, s32);
extern void *func_00381FF0(s32);
extern int func_00120048(char *, char *, ...);

void func_L39_006944B0(S_006944B0 *p)
{
    G_006944B0 *g = D_L39_0024D760;
    void *h = g->f48;
    A_006944B0 *a;
    A_006944B0 *b;
    s32 state;
    s32 id;
    s32 lv;
    char buf[16];
    B_006944B0 tmp;

    if (p->f290 == 1 && p->f114->vt->get(p->f114) >= 0) {
        p->f3d4 = p->f2c8[p->f114->vt->get(p->f114)];
    }
    if (g->f38->f3bc) {
        return;
    }
    if (p->f3d4 < 0) {
        p->f11c->vt->clear(p->f11c);
        p->f120->vt->clear(p->f120);
        return;
    }
    if (p->f3d4 == p->f3d0) {
        return;
    }
    state = 0;
    a = func_L39_006D98C8(h, p->f3d4);
    id = -1;
    b = func_L39_006D9328(h, p->f3d4);
    p->f3d0 = p->f3d4;
    if (a) {
        id = a->f44;
        if (a->f40 == 0) {
            state = 3;
        } else {
            state = a->f40 == 1 ? 2 : 0;
        }
    } else if (b) {
        state = b->f40;
    }
    if (b) {
        R_006944B0 *r = func_L39_006D6CF8(g->f44, p->f3d4, 1, 0);
        if (r) {
            func_00120048(buf, D_L39_00247EF0, r->f1c);
            p->f120->vt->text(p->f120, buf);
        } else {
            p->f120->vt->clear(p->f120);
        }
    }
    if (*D_L39_0024D760->f30 == p->f3d4) {
        p->f11c->vt->text(p->f11c, func_00381FF0(0xFAE));
    } else if (state == 0) {
        p->f11c->vt->text(p->f11c, func_00381FF0(0xFAD));
    } else if (state == 1) {
        p->f11c->vt->text(p->f11c, func_00381FF0(0xF76));
    } else if (state == 2) {
        p->f11c->vt->text(p->f11c, func_00381FF0(0xFAF));
    } else if (state == 3) {
        s32 ok = 1;
        if (id >= 0) {
            void *q = func_L39_006D4380(g->f3c, id);
            if (q) {
                func_L39_006CC120(&tmp);
                func_L39_006CC4F8(&tmp, q);
                lv = func_L39_006CC350(&tmp, 3);
                ok = ok && lv <= 7;
                func_L39_006CC158(&tmp, 2);
            }
        }
        if (ok) {
            p->f11c->vt->text(p->f11c, func_00381FF0(0xFB0));
        } else {
            p->f11c->vt->text(p->f11c, func_00381FF0(0xFB1));
        }
    }
}
/* localdecomp:end func_L39_006944B0 */
