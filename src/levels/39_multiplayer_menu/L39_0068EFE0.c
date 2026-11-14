#include "common.h"

/* localdecomp:start func_L39_0068EFE0 */
typedef struct O_0068EFE0 O_0068EFE0;
typedef struct {
    u8 pad0[0x20];
    void (*f20)(O_0068EFE0 *, s32, s32);
    u8 pad24[0x30 - 0x24];
    void (*f30)(O_0068EFE0 *, f32 *, f32 *);
    u8 pad34[0x78 - 0x34];
    s32 (*f78)(O_0068EFE0 *);
    u8 pad7C[0x8C - 0x7C];
    s32 (*f8C)(O_0068EFE0 *);
    u8 pad90[0x98 - 0x90];
    s32 (*f98)(O_0068EFE0 *);
    s32 (*f9C)(O_0068EFE0 *, f32 *, f32 *);
} V_0068EFE0;
struct O_0068EFE0 {
    u8 pad0[0x60];
    V_0068EFE0 *vt;
};
typedef struct {
    u8 pad0[0x1C];
    s32 f1C;
} I_0068EFE0;
typedef struct {
    u8 pad0[4];
    s32 n;
    I_0068EFE0 **items;
} E_0068EFE0;
typedef struct {
    u8 valid;
    u8 pad1[3];
    s32 cur;
    u8 pad8[0x28 - 8];
    E_0068EFE0 e[1];
} L_0068EFE0;
typedef struct {
    u8 pad0[0x18];
    s32 f18;
} R_0068EFE0;
typedef struct {
    u8 pad0[0x34];
    L_0068EFE0 *f34;
    u8 pad38[0x40 - 0x38];
    L_0068EFE0 *f40;
    u8 pad44[0x48 - 0x44];
    void *f48;
} G_0068EFE0;
typedef struct {
    u8 pad0[0x110];
    O_0068EFE0 *f110[(0x290 - 0x110) / 4];
    s32 f290;
    u8 pad294[0x2A8 - 0x294];
    u8 f2A8;
    u8 pad2A9[0x2B4 - 0x2A9];
    s32 f2B4[1];
} S_0068EFE0;
typedef struct {
    u8 pad0[0xD0];
    void *fD0;
    u8 padD4[0x284 - 0xD4];
    s32 f284;
} D_0068EFE0;

extern G_0068EFE0 *D_L39_0024D760;
extern D_0068EFE0 *D_L39_00247914;
extern u8 D_L39_00247CA0[];
__asm__(".extern D_L39_00247CA0, 4");
extern u8 D_L39_00247CC8[];
extern u8 D_L39_00247CD0[];

void func_L39_0068F810(void *);
void func_L39_0068FA80(void *);
s32 func_L39_0068AEF8(void *, s32);
extern u8 *func_00381FF0(s32);
extern s32 func_00120048(u8 *, u8 *, ...);
extern s32 func_001205B0(u8 *, u8 *);
void func_L39_00689E58(void *, u8 *, f32, f32, u32);
s32 func_L39_00688340(s32, s32, s32);
void func_L39_0068B2F8(void *, s32, s32);
s32 func_L39_006872E8(void *, u8 *, u8 *, s32, s32, f32);
s32 func_L39_00687450(void *, u8 *, u8 *, s32, s32, s32, s32);
R_0068EFE0 *func_L39_006D9C90(void *, u8 *);
s32 func_L39_006CDDB0(void *, s32);
s32 func_L39_006D6210(void *, s32);
void func_L39_006B5288(void *, s32, s8);
s32 func_L39_006D6398(void *, s32);
void func_L39_00689F00(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);

static __inline__ E_0068EFE0 *cur_0068EFE0(L_0068EFE0 *l) {
    E_0068EFE0 *e = 0;
    if (l->valid && l->cur >= 0) {
        e = &l->e[l->cur];
    }
    return e;
}

static __inline__ s8 contains_0068EFE0(L_0068EFE0 *l, s32 id) {
    s32 found = 0;
    E_0068EFE0 *e = cur_0068EFE0(l);
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

s32 func_L39_0068EFE0(S_0068EFE0 *this, s32 arg1) {
    u8 buf[0x20];
    u8 msg[0x70];
    f32 x, y;
    G_0068EFE0 *g = D_L39_0024D760;
    void *db = g->f48;
    L_0068EFE0 *list = g->f40;

    func_L39_0068F810(this);
    if (this->f110[0]->vt->f78(this->f110[0]) > 0) {
        this->f110[0]->vt->f20(this->f110[0], 3, 0);
        func_L39_0068FA80(this);
    } else {
        this->f110[0]->vt->f20(this->f110[0], 2, 0);
    }
    if (func_L39_0068AEF8(this, arg1) == 1) {
        return 1;
    }
    if (this->f290 == 0) {
        func_00120048(buf, D_L39_00247CC8, func_00381FF0(0xF91));
        func_L39_00689E58(this, buf, 1.0f, 1.0f, 0x706EC8FF);
    } else {
        func_L39_00689E58(this, D_L39_00247CA0, 1.0f, 1.0f, 0x706EC8FF);
    }
    if (this->f290 != 0 && this->f110[0]->vt->f78(this->f110[0]) > 0 && (u32)(arg1 - 3) < 2) {
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
            E_0068EFE0 *e;
            R_0068EFE0 *r;

            if (this->f2A8) {
                return 0;
            }
            e = cur_0068EFE0(list);
            if (e->n >= 26) {
                D_0068EFE0 *m = D_L39_00247914;
                func_L39_006872E8(m, func_00381FF0(0x18D3), D_L39_00247CA0, 4, 0, 0.6f);
                return 1;
            }
            buf[0] = 0;
            func_L39_00687450(D_L39_00247914, D_L39_00247CA0, buf, 0, 0xF, 1, 0);
            if (func_001205B0(buf, D_L39_00247CA0) == 0) {
                break;
            }
            r = func_L39_006D9C90(db, buf);
            if (r != 0) {
                if (r->f18 >= 0) {
                    if (contains_0068EFE0(list, r->f18)) {
                        return 1;
                    }
                    {
                        L_0068EFE0 *l2 = D_L39_0024D760->f34;
                        s32 id = r->f18;
                        if (contains_0068EFE0(l2, id)) {
                            func_L39_006CDDB0(l2, id);
                        }
                    }
                    if (func_L39_006D6210(list, r->f18)) {
                        this->f2A8 = 1;
                        func_00120048(msg, D_L39_00247CD0, func_00381FF0(0xF9E));
                    } else {
                        func_00120048(msg, D_L39_00247CD0, func_00381FF0(0xF9F));
                    }
                    func_L39_006872E8(D_L39_00247914, msg, D_L39_00247CA0, 4, 0, 0.6f);
                } else {
                    D_0068EFE0 *m = D_L39_00247914;
                    func_L39_006872E8(m, func_00381FF0(0x128F), D_L39_00247CA0, 4, 0, 0.6f);
                }
            } else {
                func_00120048(msg, func_00381FF0(0x1175), buf);
                func_L39_006872E8(D_L39_00247914, msg, D_L39_00247CA0, 4, 0, 0.6f);
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
            D_L39_00247914->f284 = 0x2C;
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
        fmt = func_00381FF0(0x1035);
        func_00120048(buf, fmt, this->f110[0]->vt->f98(this->f110[0]));
        {
            D_0068EFE0 *m = D_L39_00247914;
            r = func_L39_006872E8(m, buf, func_00381FF0(0x1031), 3, 0, 0.6f);
        }
        if (r == 1) {
            func_L39_006D6398(D_L39_0024D760->f40, v);
            this->f2A8 = r;
        }
        return 1;
    }
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
/* localdecomp:end func_L39_0068EFE0 */
