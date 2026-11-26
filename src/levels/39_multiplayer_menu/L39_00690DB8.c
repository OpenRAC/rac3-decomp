#include "common.h"

/* localdecomp:start func_L39_00690DB8 */
extern void func_L39_0068ADC8(void *);
extern void func_L39_00690DB8(void *);

extern void func_L39_0067F168();
void func_L39_00690DB8(void *p) {
    func_L39_0067F168(p);
    func_L39_0068ADC8(p);
}
/* localdecomp:end func_L39_00690DB8 */

/* localdecomp:start func_L39_00690DE8 */
typedef struct O_00690DE8 O_00690DE8;
typedef struct {
    u8 pad0[0x20];
    void (*f20)(O_00690DE8 *, s32, s32);
    u8 pad24[0x30 - 0x24];
    void (*f30)(O_00690DE8 *, f32 *, f32 *);
    u8 pad34[0x78 - 0x34];
    s32 (*f78)(O_00690DE8 *);
    u8 pad7C[0x8C - 0x7C];
    s32 (*f8C)(O_00690DE8 *);
    u8 pad90[0x98 - 0x90];
    s32 (*f98)(O_00690DE8 *);
    s32 (*f9C)(O_00690DE8 *, f32 *, f32 *);
} V_00690DE8;
struct O_00690DE8 {
    u8 pad0[0x60];
    V_00690DE8 *vt;
};
typedef struct {
    u8 pad0[0x1C];
    s32 f1C;
} I_00690DE8;
typedef struct {
    u8 pad0[4];
    s32 n;
    I_00690DE8 **items;
} E_00690DE8;
typedef struct {
    u8 valid;
    u8 pad1[3];
    s32 cur;
    u8 pad8[0x28 - 8];
    E_00690DE8 e[1];
} L_00690DE8;
typedef struct {
    u8 pad0[0x18];
    s32 f18;
} R_00690DE8;
typedef struct {
    u8 pad0[0x34];
    L_00690DE8 *f34;
    u8 pad38[0x40 - 0x38];
    L_00690DE8 *f40;
    u8 pad44[0x48 - 0x44];
    void *f48;
} G_00690DE8;
typedef struct {
    u8 pad0[0x110];
    O_00690DE8 *f110[(0x290 - 0x110) / 4];
    s32 f290;
    u8 pad294[0x2A8 - 0x294];
    u8 f2A8;
    u8 pad2A9[0x2B4 - 0x2A9];
    s32 f2B4[1];
} S_00690DE8;
typedef struct {
    u8 pad0[0xD0];
    void *fD0;
    u8 padD4[0x284 - 0xD4];
    s32 f284;
} D_00690DE8;

extern G_00690DE8 *D_L39_0024D760;
extern D_00690DE8 *D_L39_00247914;
extern u8 D_L39_00247D38[];
__asm__(".extern D_L39_00247D38, 4");
extern u8 D_L39_00247D60[];
extern u8 D_L39_00247D68[];

void func_L39_006915C8(void *);
void func_L39_00691900(void *);
s32 func_L39_0068AEF8(void *, s32);
extern u8 *func_00381FF0(s32);
extern s32 func_00120048(u8 *, u8 *, ...);
extern s32 func_001205B0(u8 *, u8 *);
void func_L39_00689E58(void *, u8 *, f32, f32, u32);
s32 func_L39_00688340(s32, s32, s32);
void func_L39_0068B2F8(void *, s32, s32);
s32 func_L39_006872E8(void *, u8 *, u8 *, s32, s32, f32);
s32 func_L39_00687450(void *, u8 *, u8 *, s32, s32, s32, s32);
R_00690DE8 *func_L39_006D9C90(void *, u8 *);
s32 func_L39_006CDDB0(void *, s32);
s32 func_L39_006CDC30(void *, s32);
void func_L39_0068A2D0(void *, s32, s32, s32, f32, f32);
void func_L39_006B5288(void *, s32, s8);
s32 func_L39_006D6398(void *, s32);
void func_L39_00689F00(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);

static __inline__ E_00690DE8 *cur_00690DE8(L_00690DE8 *l) {
    E_00690DE8 *e = 0;
    if (l->valid && l->cur >= 0) {
        e = &l->e[l->cur];
    }
    return e;
}

static __inline__ s8 contains_00690DE8(L_00690DE8 *l, s32 id) {
    s32 found = 0;
    E_00690DE8 *e = cur_00690DE8(l);
    s32 i;
    if (e != 0) {
        for (i = 0; i < e->n; i++) {
            if (e->items[i]->f1C == id) {
                found = 1;
                break;
            }
        }
    }
    return found;
}

s32 func_L39_00690DE8(S_00690DE8 *this, s32 arg1) {
    u8 buf[0x20];
    u8 msg[0x70];
    f32 x, y;

    func_L39_006915C8(this);
    if (this->f110[0]->vt->f78(this->f110[0]) > 0) {
        this->f110[0]->vt->f20(this->f110[0], 3, 0);
        func_L39_00691900(this);
    } else {
        this->f110[0]->vt->f20(this->f110[0], 2, 0);
    }
    if (func_L39_0068AEF8(this, arg1) == 1) {
        return 1;
    }
    if (this->f290 == 0) {
        func_00120048(buf, D_L39_00247D60, func_00381FF0(0xF8F));
        func_L39_00689E58(this, buf, 1.0f, 1.0f, 0x706EC8FF);
    } else {
        func_L39_00689E58(this, D_L39_00247D38, 1.0f, 1.0f, 0x706EC8FF);
    }
    if (this->f290 != 0 && this->f110[0]->vt->f78(this->f110[0]) > 0 && (u32)(arg1 - 3) < 2) {
        func_L39_00688340(3, 0, 0);
        func_L39_0068B2F8(this, 0, 0);
        return 1;
    }
    if (arg1 == 1 && this->f290 == 1) {
        func_L39_00688340(3, 0, 0);
        func_L39_0068B2F8(this, 3, 0);
        return 1;
    }
    if ((arg1 == 2 && this->f290 == 3) || (this->f290 == 0 && (u32)(arg1 - 3) < 2)) {
        func_L39_00688340(3, 0, 0);
        func_L39_0068B2F8(this, 1, 0);
        return 1;
    }
    if (this->f290 == 0) {
        if (arg1 == 1) {
            if (this->f110[0]->vt->f8C(this->f110[0]) == 0) {
                return 1;
            }
        }
        if (arg1 == 2) {
            s32 sel = this->f110[this->f290]->vt->f8C(this->f110[this->f290]);
            if (sel == this->f110[this->f290]->vt->f78(this->f110[this->f290]) - 1) {
                return 1;
            }
        }
    }
    if (arg1 == 7) {
        func_L39_00688340(4, 0, 0);
        switch (this->f290) {
        case 2:
            D_L39_00247914->f284 = 0x1E;
            return 1;
        case 1: {
            G_00690DE8 *g;
            L_00690DE8 *list;
            R_00690DE8 *r;

            buf[0] = 0;
            func_L39_00687450(D_L39_00247914, D_L39_00247D38, buf, 0, 0xF, 1, 0);
            if (func_001205B0(buf, D_L39_00247D38) == 0) {
                break;
            }
            g = D_L39_0024D760;
            list = g->f34;
            r = func_L39_006D9C90(g->f48, buf);
            if (r != 0) {
                if (r->f18 >= 0) {
                    if (contains_00690DE8(list, r->f18)) {
                        return 1;
                    }
                    {
                        L_00690DE8 *l2 = D_L39_0024D760->f40;
                        s32 id = r->f18;
                        if (contains_00690DE8(l2, id)) {
                            func_L39_006D6398(l2, id);
                        }
                    }
                    if (func_L39_006CDC30(list, r->f18)) {
                        this->f2A8 = 1;
                        func_00120048(msg, D_L39_00247D68, func_00381FF0(0xF98));
                    } else {
                        func_00120048(msg, D_L39_00247D68, func_00381FF0(0xF99));
                    }
                    func_L39_006872E8(D_L39_00247914, msg, D_L39_00247D38, 4, 0, 0.6f);
                } else {
                    D_00690DE8 *m = D_L39_00247914;
                    func_L39_006872E8(m, func_00381FF0(0x128F), D_L39_00247D38, 4, 0, 0.6f);
                }
            } else {
                func_00120048(msg, func_00381FF0(0x1175), buf);
                func_L39_006872E8(D_L39_00247914, msg, D_L39_00247D38, 4, 0, 0.6f);
            }
            return 1;
        }
        case 0: {
            s32 sel = this->f110[0]->vt->f8C(this->f110[0]);
            if (sel != -1) {
                func_L39_006B5288(D_L39_00247914->fD0, this->f2B4[sel], 1);
                D_L39_00247914->f284 = 0x1B;
                return 1;
            }
            break;
        }
        case 3:
            D_L39_00247914->f284 = 3;
            return 1;
        }
    }
    if (arg1 == 8 && this->f290 == 0) {
        s32 sel = this->f110[0]->vt->f8C(this->f110[0]);
        s32 v;
        u8 *fmt;
        s32 r;

        if (sel == -1) {
            return 1;
        }
        v = this->f2B4[sel];
        if (v < 0) {
            return 1;
        }
        fmt = func_00381FF0(0x1034);
        func_00120048(buf, fmt, this->f110[0]->vt->f98(this->f110[0]));
        {
            D_00690DE8 *m = D_L39_00247914;
            r = func_L39_006872E8(m, buf, func_00381FF0(0x1031), 3, 0, 0.6f);
        }
        if (r == 1) {
            func_L39_006CDDB0(D_L39_0024D760->f34, v);
            this->f2A8 = r;
        }
        return 1;
    }
    func_L39_0068A2D0(this, 0, 3, 3, 2.0f, 2.0f);
    if (this->f290 == 0) {
        if (this->f110[0]->vt->f9C(this->f110[0], &x, &y)) {
            func_L39_00689F00(this, 0, 3, 3, x + 0.175f, y, 0.35f, 0.035f, 0.027f, 0.25f);
        }
        return 0;
    }
    this->f110[this->f290]->vt->f30(this->f110[this->f290], &x, &y);
    func_L39_00689F00(this, 0, 3, 3, x, y, 0.43f, 0.032f, 0.027f, 0.25f);
    return 0;
}
/* localdecomp:end func_L39_00690DE8 */
