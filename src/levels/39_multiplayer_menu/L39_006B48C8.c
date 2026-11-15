#include "common.h"

/* localdecomp:start func_L39_006B48C8 */
typedef struct V_006B48C8 {
    u8 pad0[0x20];
    void (*f20)(void *, s32, s32);
    u8 pad24[0xC];
    void (*f30)(void *, f32 *, f32 *);
} V_006B48C8;

typedef struct O_006B48C8 {
    u8 pad0[4];
    s32 state;
    u8 pad8[0x58];
    V_006B48C8 *vt;
} O_006B48C8;

typedef struct E_006B48C8 {
    s32 f0;
    s32 f4;
    s32 f8;
} E_006B48C8;

typedef struct X_006B48C8 {
    u8 f0;
    s32 f4;
    u8 pad8[0x20];
    E_006B48C8 entries[1];
} X_006B48C8;

typedef struct P_006B48C8 {
    s32 f0;
    u8 f4[0x30];
    u8 f34;
} P_006B48C8;

typedef struct G_006B48C8 {
    u8 pad0[0x30];
    s32 *f30;
    X_006B48C8 *f34;
    P_006B48C8 *f38;
    void *f3C;
    X_006B48C8 *f40;
    u8 pad44[4];
    void *f48;
    void *f4C;
    u8 pad50[4];
    void *f54;
} G_006B48C8;

typedef struct T_006B48C8 {
    u8 pad0[0x2A8];
    s32 f2A8;
    s32 f2AC;
    s32 f2B0;
    s32 f2B4;
} T_006B48C8;

typedef struct Q_006B48C8 {
    u8 pad0[0xA4];
    T_006B48C8 *fA4;
    u8 padA8[0x284 - 0xA8];
    s32 f284;
} Q_006B48C8;

typedef struct R_006B48C8 {
    u8 pad0[0x184];
    s32 f184;
    s32 f188;
} R_006B48C8;

typedef struct N_006B48C8 {
    u8 b[64];
} N_006B48C8;

typedef struct Self_006B48C8 {
    u8 pad0[0x110];
    O_006B48C8 *items[11];
    u8 pad13C[0x290 - 0x13C];
    s32 cur;
    u8 pad294[0x2A8 - 0x294];
    s32 f2A8;
    s32 f2AC;
    s32 f2B0;
    u8 pad2B4;
    u8 f2B5;
    u8 f2B6;
    u8 f2B7[0x2D8 - 0x2B7];
    u8 f2D8;
    u8 f2D9;
    u8 pad2DA[6];
    u8 f2E0;
    u8 pad2E1[7];
    u8 f2E8;
    u8 f2E9;
    u8 f2EA;
    u8 f2EB;
} Self_006B48C8;

__asm__(".extern D_L39_0024D760, 16");
__asm__(".extern D_001DD8C4_sda, 4");
__asm__(".extern D_001DC204_sda, 4");
__asm__(".extern D_001E2050_sda, 4");
extern G_006B48C8 *D_L39_0024D760;
extern Q_006B48C8 *D_L39_00247914;
extern s32 D_001DD8C4_sda;
extern u8 *D_001DC204_sda;
extern G_006B48C8 *D_001E2050_sda;
extern N_006B48C8 D_L39_00248FD8;
extern u8 D_L39_00248FD0[];
extern u8 D_L39_00249018[];
extern char D_L39_00249020[];
extern char D_L39_00249028[];
extern char D_L39_00249030[];

extern s32 func_L39_0068AEF8(void *, s32);
extern void func_L39_006B5D00(void *);
extern void func_L39_006B5F20(void *);
extern void func_L39_006B6158(void *);
extern void func_L39_006B5498(void *);
extern void func_L39_006CEA18(void *, s32);
extern s32 func_L39_00688340(s32, s32, s32);
extern R_006B48C8 *func_L39_006D4380(void *);
extern u8 *func_L39_006DE380(void *, s32, s32);
extern void func_L39_006CC120(void *);
extern void func_L39_006CC4F8(void *, void *);
extern s32 func_L39_006CC350(void *, s32);
extern s32 func_L39_006DA680(void *, s32, u8 *);
extern void func_L39_006BD408(void *, s32);
extern void func_L39_006CC158(void *, s32);
extern s32 func_L39_00687450(void *, u8 *, u8 *, s32, s32, s32, s32);
extern s32 func_L39_006D9E68(void *, s32, void *, s32);
extern void *func_00381FF0(s32);
extern s32 func_L39_006872E8(void *, void *, void *, s32, f32, s32);
extern void func_L39_006CDC30(void *, s32);
extern void func_L39_006CDDB0(void *, s32);
extern void func_L39_006D6210(void *, s32);
extern void func_L39_006D6398(void *, s32);
extern void func_L39_006CFEA8(void *, s32, void *);
extern void func_L39_006D0078(void *, s32);
extern void func_L39_006D0228(void *, s32);
extern s32 func_00120048(void *, char *, ...);
extern void func_L39_0068A2D0(void *, s32, s32, s32, f32, f32);

s32 func_L39_006B48C8(Self_006B48C8 *self, s32 cmd)
{
    G_006B48C8 *g = D_L39_0024D760;
    P_006B48C8 *pl = g->f38;
    O_006B48C8 *o;
    X_006B48C8 *x;
    P_006B48C8 *p;
    E_006B48C8 *e;
    void *list;
    X_006B48C8 *xs;
    s32 i;
    s32 first;
    s32 last;
    s32 flags;
    s32 k;
    u8 buf[0x50];
    u8 msg[0x190];
    f32 fx;
    f32 fy;

    if (func_L39_0068AEF8(self, cmd)) {
        return 1;
    }

    if ((D_001DD8C4_sda++ & 0x3F) == 0) {
        func_L39_006B5D00(self);
        func_L39_006B5F20(self);
        func_L39_006B6158(self);
        func_L39_006B5498(self);
    }

    if (self->f2D8 == 0) {
        if (pl->f0 < 0 || pl->f34 == 0 || *g->f30 == self->f2A8) {
            self->items[8]->vt->f20(self->items[8], 2, 0);
            self->items[9]->vt->f20(self->items[9], 0, 0);
            self->items[10]->vt->f20(self->items[10], 0, 0);
        } else {
            if (self->f2EA) {
                self->items[8]->vt->f20(self->items[8], 0, 0);
                self->items[9]->vt->f20(self->items[9], 0, 0);
                self->items[10]->vt->f20(self->items[10], 3, 0);
            } else if (self->f2E9) {
                self->items[8]->vt->f20(self->items[8], 2, 0);
                self->items[9]->vt->f20(self->items[9], 0, 0);
                self->items[10]->vt->f20(self->items[10], 0, 0);
            } else if (self->f2EB) {
                self->items[8]->vt->f20(self->items[8], 0, 0);
                self->items[9]->vt->f20(self->items[9], 3, 0);
                self->items[10]->vt->f20(self->items[10], 0, 0);
            } else {
                self->items[8]->vt->f20(self->items[8], 3, 0);
                self->items[9]->vt->f20(self->items[9], 0, 0);
                self->items[10]->vt->f20(self->items[10], 0, 0);
            }
        }
    }

    if ((D_001DD8C4_sda & 0x1FF) == 0) {
        self->f2B6 = 1;
        self->f2E8 = 1;
    }

    if (cmd == 6) {
        func_L39_006CEA18(D_L39_0024D760->f38, 0);
        func_L39_00688340(4, 0, 0);
        self->f2D9 = 1;
        self->f2E0 = 1;
        self->f2E8 = 1;
        self->f2B6 = 1;
        self->f2B5 = 1;
    } else if (cmd == 7) {
        func_L39_00688340(4, 0, 0);
        x = D_L39_0024D760->f34;
        xs = D_L39_0024D760->f40;
        p = D_L39_0024D760->f38;
        list = D_L39_0024D760->f54;
        switch (self->cur) {
        case 2:
            if (self->f2B0 < 0) {
                return 1;
            }
            if (self->f2AC == 3) {
                R_006B48C8 *r;
                u8 *t;
                s32 team;
                s32 id;

                r = func_L39_006D4380(D_L39_0024D760->f3C);
                if (r == 0) {
                    return 1;
                }
                team = 0;
                t = func_L39_006DE380(list, 0, self->f2B0);
                if (t) {
                    team = *(s32 *)(t + 0x24);
                }
                func_L39_006CC120(buf);
                func_L39_006CC4F8(buf, r);
                id = func_L39_006CC350(buf, 2);
                if (func_L39_006DA680(D_L39_0024D760->f4C, id, 0)) {
                    if (r->f184 == 1) {
                        Q_006B48C8 *q = D_L39_00247914;
                        s32 sel = self->f2B0;
                        s32 v = r->f188;
                        T_006B48C8 *d = q->fA4;
                        d->f2A8 = sel;
                        d->f2AC = team;
                        d->f2B0 = id;
                        d->f2B4 = v;
                        q->f284 = 0x10;
                    } else {
                        func_L39_006BD408(*(void **)(D_001DC204_sda + 0xE0), id);
                        D_L39_00247914->f284 = 0x1F;
                    }
                }
                func_L39_006CC158(buf, 2);
            } else if (self->f2AC == 2) {
                if (func_L39_006DA680(D_L39_0024D760->f4C, self->f2B0, D_L39_00248FD0)) {
                    func_L39_006BD408(*(void **)(D_001DC204_sda + 0xE0), self->f2B0);
                    D_L39_00247914->f284 = 0x1F;
                }
            }
            return 1;
        case 3: {
            *(N_006B48C8 *)buf = D_L39_00248FD8;
            func_L39_00687450(D_L39_00247914, D_L39_00248FD0, &buf[1], 0, 0x3E, 0, 0);
            if (buf[1] != 0) {
                if (func_L39_006D9E68(D_001E2050_sda->f48, self->f2A8, buf, 0) != 0) {
                    u8 *ui = D_001DC204_sda;
                    func_L39_006872E8(ui, func_00381FF0(0x184E), D_L39_00249018, 4, 0.6f, 0);
                }
            }
            return 1;
        }
        case 4: {
            Q_006B48C8 *q;

            e = 0;
            if (x->f0 && x->f4 >= 0) {
                e = &x->entries[x->f4];
            }
            if (e->f4 < 0x40) {
                self->items[4]->vt->f20(self->items[4], 2, 0);
                self->items[6]->vt->f20(self->items[6], 2, 0);
                func_L39_006CDC30(x, self->f2A8);
                self->f2E0 = 1;
                self->f2D9 = 1;
                return 1;
            }
            func_00120048(buf, D_L39_00249020);
            q = D_L39_00247914;
            func_L39_006872E8(q, func_00381FF0(0x184D), buf, 4, 0.6f, 0);
            return 0;
        }
        case 5:
            self->items[5]->vt->f20(self->items[5], 2, 0);
            func_L39_006CDDB0(x, self->f2A8);
            self->f2E0 = 1;
            self->f2D9 = 1;
            return 1;
        case 6:
            e = 0;
            if (xs->f0 && xs->f4 >= 0) {
                e = &xs->entries[xs->f4];
            }
            if (e->f4 < 0x1A) {
                self->items[6]->vt->f20(self->items[6], 2, 0);
                self->items[4]->vt->f20(self->items[4], 2, 0);
                func_L39_006D6210(xs, self->f2A8);
            } else {
                Q_006B48C8 *q = D_L39_00247914;
                func_L39_006872E8(q, func_00381FF0(0x18D3), D_L39_00248FD0, 4, 0.6f, 0);
            }
            self->f2E0 = 1;
            self->f2D9 = 1;
            return 1;
        case 7:
            self->items[7]->vt->f20(self->items[7], 2, 0);
            func_L39_006D6398(xs, self->f2A8);
            self->f2E0 = 1;
            self->f2D9 = 1;
            return 1;
        case 8: {
            if (p->f0 < 0 || p->f34 == 0) {
                return 1;
            }
            self->items[8]->vt->f20(self->items[8], 0, 0);
            self->items[9]->vt->f20(self->items[9], 2, 0);
            func_00120048(buf, D_L39_00249028, p->f4);
            func_L39_006CFEA8(p, self->f2A8, buf);
            self->f2D8 = 1;
            self->f2E8 = 1;
            return 1;
        }
        case 9:
            if (p->f0 < 0 || p->f34 == 0) {
                return 1;
            }
            self->items[8]->vt->f20(self->items[8], 2, 0);
            self->items[9]->vt->f20(self->items[9], 0, 0);
            func_L39_006D0078(p, self->f2A8);
            self->f2D8 = 1;
            self->f2E8 = 1;
            return 1;
        case 10: {
            Q_006B48C8 *q;
            s32 r;

            if (p->f0 < 0 || p->f34 == 0) {
                return 1;
            }
            func_00120048(buf, func_00381FF0(0x1038), self->f2B7);
            q = D_L39_00247914;
            r = func_L39_006872E8(q, buf, func_00381FF0(0x1031), 3, 0.6f, 0);
            if (r == 1) {
                func_00120048(msg, D_L39_00249030, 0x4D, func_00381FF0(0x1732));
                func_L39_006D9E68(D_L39_0024D760->f48, self->f2A8, msg, 1);
                self->items[10]->vt->f20(self->items[10], 0, 0);
                self->items[8]->vt->f20(self->items[8], 2, 0);
                func_L39_006D0228(p, self->f2A8);
                self->f2D8 = r;
                self->f2E8 = r;
            }
            return 1;
        }
        }
    }
    if (cmd == 5) {
        func_L39_00688340(0x17, 0, 0);
    }
    if (self->cur != -1) {
        o = self->items[self->cur];
        o->vt->f30(o, &fx, &fy);
        first = -1;
        last = -1;
        for (i = 2; i < 11; i++) {
            if ((k = self->items[i]->state) == 3 || k == 4 || k == 5) {
                if (first == -1) {
                    first = i;
                }
                last = i;
            }
        }
        flags = self->cur != first;
        if (self->cur != last) {
            flags |= 2;
        }
        func_L39_0068A2D0(self, flags, 3, 3, fx, fy);
    }
    return 0;
}
/* localdecomp:end func_L39_006B48C8 */
