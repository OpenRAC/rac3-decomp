#include "common.h"

/* localdecomp:start func_L39_006B5288 */
void func_L39_006B5288(void *arg0, s32 arg1, s8 arg2) {
    *(s8 *)((u8 *)arg0 + 0x2B4) = arg2;
    *(s8 *)((u8 *)arg0 + 0x2B6) = 1;
    *(s32 *)((u8 *)arg0 + 0x2A8) = arg1;
    *(s32 *)((u8 *)arg0 + 0x2AC) = 0;
}
/* localdecomp:end func_L39_006B5288 */

/* localdecomp:start func_L39_006B52A0 */
typedef struct G_006B52A0 {
    u8 pad0[0x38];
    s32 *f38;
    void *f3C;
    u8 pad40[0xC];
    s32 *f4C;
} G_006B52A0;

typedef struct T_006B52A0 {
    u8 pad0[0x2AC];
    s32 f2AC;
    s32 f2B0;
    u8 f2B4;
} T_006B52A0;

extern G_006B52A0 *D_001E2050_sda;
extern char D_00248F10[];
extern char D_00248F18[];
extern void *func_L39_006D4380(void *);
extern void func_L39_006CC120(void *);
extern void func_L39_006CC4F8(void *, void *);
extern s32 func_L39_006CC350(void *, s32);
extern void func_L39_006CC158(void *, s32);
extern u8 *func_L39_006DB750(s32 *, s32);
extern void func_001200E0(s32 type, s32 n, void *s);

s32 func_L39_006B52A0(T_006B52A0 *this) {
    G_006B52A0 *g = D_001E2050_sda;
    u8 result = 0;
    s32 id = this->f2B0;
    u8 buf[0x1E0];
    s32 a, b;
    s32 idx;
    s32 *pa;
    s32 *pb;
    s32 mode;
    s32 *t;
    u8 *e;
    u8 *s;
    void *p;

    if (id >= 0 && id != *g->f4C && this->f2B4 != 0) {
        idx = id;
        if (this->f2AC == 3) {
            p = func_L39_006D4380(g->f3C);
            if (p != 0) {
                func_L39_006CC120(buf);
                func_L39_006CC4F8(buf, p);
                idx = func_L39_006CC350(buf, 2);
                func_L39_006CC158(buf, 2);
            }
        }
        e = func_L39_006DB750(g->f4C, idx);
        if (e != 0) {
            s = e + 0x1C;
            pa = &a;
            pb = &b;
            mode = 8;
            if (s[0] == 'C') {
                if (s[1] == 'Y') {
                    mode = 1;
                    ((void (*)(u8 *, char *, s32 *, s32 *))func_001200E0)(s + 2, D_00248F10, pa, pb);

                } else if (s[1] == 'R') {
                    mode = 4;
                    ((void (*)(u8 *, char *, s32 *, s32 *))func_001200E0)(s + 2, D_00248F10, pa, pb);

                } else if (s[1] == 'C') {
                    mode = 2;
                    ((void (*)(u8 *, char *, s32 *, s32 *))func_001200E0)(s + 2, D_00248F18, pa, pb);

                }
            } else if (s[0] == 'H') {
                mode = 6;
                ((void (*)(u8 *, char *, s32 *, s32 *))func_001200E0)(s + 2, D_00248F10, pa, pb);

            }
            t = g->f38;
            switch (mode) {
            case 1:
                result = 1;
                break;
            case 2:
                result = (*t == a || *t == b);
                break;
            case 4:
                result = (*t == a);
                break;
            }
        }
    }
    return result;
}
/* localdecomp:end func_L39_006B52A0 */

/* localdecomp:start func_L39_006B5498 */
typedef struct O_006B5498 O_006B5498;

typedef struct V_006B5498 {
    u8 pad0[0x1C];
    void (*f1C)(O_006B5498 *, s32, s32);
    void (*f20)(O_006B5498 *, s32, s32);
    u8 pad24[0xB4 - 0x24];
    void (*fB4)(O_006B5498 *);
    void (*fB8)(O_006B5498 *, char *);
} V_006B5498;

struct O_006B5498 {
    u8 pad0[0x60];
    V_006B5498 *vt;
};

typedef struct F_006B5498 {
    u8 pad0[8];
    u8 f8;
} F_006B5498;

typedef struct P_006B5498 {
    s32 f0;
    u8 pad4[0x3BC - 4];
    u8 f3BC;
    u8 pad3BD[0x42C - 0x3BD];
    u8 f42C;
} P_006B5498;

typedef struct G_006B5498 {
    u8 pad0[0x30];
    s32 *f30;
    F_006B5498 *f34;
    P_006B5498 *f38;
    void *f3C;
    F_006B5498 *f40;
    void *f44;
    void *f48;
} G_006B5498;

typedef struct R_006B5498 {
    f32 a[4];
    f32 b[4];
    u8 pad20[4];
    s32 f24;
    u8 pad28[0xC];
} R_006B5498;

typedef struct E_006B5498 {
    u8 pad0[0x1C];
    char name[0x24];
    s32 f40;
    s32 f44;
    R_006B5498 r;
} E_006B5498;

typedef struct Q_006B5498 {
    u8 pad0[0x24];
    s32 f24;
    u8 pad28[8];
    s32 f30;
} Q_006B5498;

typedef struct T_006B5498 {
    u8 pad0[0x114];
    O_006B5498 *f114;
    O_006B5498 *f118;
    O_006B5498 *f11C;
    u8 pad120[0x13C - 0x120];
    O_006B5498 *f13C;
    O_006B5498 *f140;
    O_006B5498 *f144;
    O_006B5498 *f148;
    O_006B5498 *f14C;
    O_006B5498 *f150;
    O_006B5498 *f154;
    O_006B5498 *f158;
    O_006B5498 *f15C;
    O_006B5498 *f160;
    u8 pad164[4];
    O_006B5498 *f168;
    O_006B5498 *f16C;
    O_006B5498 *f170;
    O_006B5498 *f174;
    u8 pad178[0x2A8 - 0x178];
    s32 f2A8;
    s32 f2AC;
    s32 f2B0;
    u8 pad2B4;
    u8 f2B5;
    u8 f2B6;
    char name[0x20];
    char f2D7;
    u8 pad2D8[0x2E1 - 0x2D8];
    u8 f2E1;
    u8 pad2E2[7];
    u8 f2E9;
} T_006B5498;

struct G_006B5F20;
__asm__(".extern D_L39_0024D760, 16");
extern struct G_006B5F20 *D_L39_0024D760;
extern char D_L39_00249038[];
extern char D_001E1B28_sda[] __attribute__((section(".sdata")));
extern char D_001DD930_sda[] __attribute__((section(".sdata")));
__asm__(".extern D_001E1B28_sda, 8");
__asm__(".extern D_001DD930_sda, 8");
extern E_006B5498 *func_L39_006D98C8(void *, s32);
extern E_006B5498 *func_L39_006D9328(void *, s32);
extern s32 func_L39_006DF598(f32, f32);
extern s32 func_L39_006D6E50(void *, s32, s32, s32 *);
extern E_006B5498 *func_L39_006D6CF8(void *, s32, s32, s32);
extern u8 *func_L39_006D31B8(void *, s32, s32);
extern void func_L39_005958F8(char *, char *, s32);
extern char *func_00381FF0(s32);
extern void func_00120D28(char *, char *, s32);
extern s32 func_00120048(char *, char *, ...);
extern s32 func_00120884(char *);
extern s32 func_L39_006B52A0(T_006B52A0 *);

static __inline__ s32 id_006B5498(P_006B5498 *p) {
    return p->f0;
}

void func_L39_006B5498(T_006B5498 *this) {
    G_006B5498 *g = (G_006B5498 *)D_L39_0024D760;
    void *list;
    E_006B5498 *a;
    E_006B5498 *b;
    char *name;
    s32 id;
    u8 ok;

    if (g->f34->f8 != 0) return;
    if (g->f40->f8 != 0) return;
    if (g->f38->f42C != 0) return;
    if (g->f38->f3BC != 0) return;
    if (this->f2B6 == 0) {
        if (this->f2B5 == 0) return;
    }

    list = g->f48;
    a = func_L39_006D98C8(list, this->f2A8);
    b = func_L39_006D9328(list, this->f2A8);
    this->f2B6 = 0;
    if (b != 0) {
        func_00120D28(this->name, b->name, 0x20);
        this->f2D7 = 0;
        this->f2AC = b->f40;
    } else {
        this->f2AC = 0;
    }
    name = this->name;
    if (a != 0) {
        func_00120D28(name, b->name, 0x20);
        this->f2D7 = 0;
        this->f2B0 = a->f44;
        if (a->f40 == 0) {
            this->f2AC = 3;
        } else if (a->f40 == 1) {
            this->f2AC = 2;
        }
    } else {
        this->f2B0 = -1;
    }

    if (b != 0) {
        R_006B5498 r;
        s32 n = 1;
        s32 i;

        r = b->r;
        id = r.f24;
        for (i = 0; i < 4; i++) {
            if (r.a[i] > 0.0f) {
                n = (func_L39_006DF598(r.a[i], r.b[i]) < n) ? n : func_L39_006DF598(r.a[i], r.b[i]);
            }
        }
        this->f168->vt->f1C(this->f168, n > 0, 0);
        this->f16C->vt->f1C(this->f16C, n >= 2, 0);
        this->f170->vt->f1C(this->f170, n >= 3, 0);
        this->f174->vt->f1C(this->f174, n >= 4, 0);
    }

    if (b != 0 && this->f2B5 != 0) {
        s32 st[0x64];
        char buf[0x100];
        void *db = g->f44;
        E_006B5498 *e;
        u8 *s;

        if (func_L39_006D6E50(db, this->f2A8, 0, st) != 0) {
            this->f2B5 = 0;
            func_00120048(buf, D_L39_00249038, st[2]);
            this->f144->vt->fB8(this->f144, buf);
            func_00120048(buf, D_L39_00249038, st[3]);
            this->f148->vt->fB8(this->f148, buf);
            func_00120048(buf, D_L39_00249038, st[5]);
            this->f14C->vt->fB8(this->f14C, buf);
            func_00120048(buf, D_L39_00249038, st[6]);
            this->f150->vt->fB8(this->f150, buf);
            func_00120048(buf, D_L39_00249038, st[10]);
            this->f154->vt->fB8(this->f154, buf);
            func_00120048(buf, D_L39_00249038, st[11]);
            this->f158->vt->fB8(this->f158, buf);
            e = func_L39_006D6CF8(db, this->f2A8, 1, 0);
            if (e != 0) {
                func_00120048(buf, D_L39_00249038, *(s32 *)e->name);
            } else {
                buf[0] = 0;
            }
            this->f15C->vt->fB8(this->f15C, buf);
            s = 0;
            if (id != -1) {
                s = func_L39_006D31B8(g->f38, this->f2A8, id);
            }
            if (s != 0) {
                char *str = (char *)s + 0x20;

                this->f2E9 = 1;
                func_L39_005958F8(D_001E1B28_sda, str, func_00120884(str));
                this->f160->vt->fB8(this->f160, D_001E1B28_sda);
            } else {
                this->f2E9 = 0;
                this->f160->vt->fB4(this->f160);
            }
        }
    }

    func_L39_005958F8(D_001DD930_sda, name, func_00120884(name));
    this->f114->vt->fB8(this->f114, D_001DD930_sda);

    if (*((G_006B5498 *)D_L39_0024D760)->f30 == this->f2A8) {
        this->f13C->vt->fB8(this->f13C, func_00381FF0(0xFAE));
        this->f140->vt->fB8(this->f140, func_00381FF0(0xFAC));
        this->f118->vt->f20(this->f118, 2, 0);
    } else if (this->f2AC == 0) {
        this->f13C->vt->fB8(this->f13C, func_00381FF0(0xFAD));
        this->f140->vt->fB8(this->f140, func_00381FF0(0xFAD));
        this->f118->vt->f20(this->f118, 2, 0);
        this->f11C->vt->f20(this->f11C, 2, 0);
    } else if (this->f2AC == 1) {
        this->f13C->vt->fB8(this->f13C, func_00381FF0(0xFAE));
        this->f140->vt->fB8(this->f140, func_00381FF0(0xF76));
        this->f118->vt->f20(this->f118, 2, 0);
        this->f11C->vt->f20(this->f11C, 2, 0);
    } else if (this->f2AC == 2) {
        s32 avail = func_L39_006B52A0((T_006B52A0 *)this);
        this->f13C->vt->fB8(this->f13C, func_00381FF0(0xFAE));
        this->f140->vt->fB8(this->f140, func_00381FF0(0xFAF));
        this->f118->vt->f20(this->f118, avail ? 3 : 2, 0);
        ok = this->f2E1;
        this->f11C->vt->f20(this->f11C, ok ? 2 : 3, 0);
    } else if (this->f2AC == 3) {
        s32 avail = 0;
        u8 ready = 0;

        if (this->f2B0 >= 0) {
            Q_006B5498 *q = ((void *(*)(void *, s32))func_L39_006D4380)(g->f3C, this->f2B0);
            if (q != 0) {
                u8 buf[0x1E0];
                P_006B5498 *t = g->f38;
                s32 n;
                s32 room;

                func_L39_006CC120(buf);
                func_L39_006CC4F8(buf, q);
                switch (func_L39_006CC350(buf, 0xC)) {
                case 0:
                    ready = 1;
                    break;
                case 2:
                    ready = (id_006B5498(t) == func_L39_006CC350(buf, 0xD) || id_006B5498(t) == func_L39_006CC350(buf, 0xE));
                    break;
                case 1:
                    ready = (id_006B5498(t) == func_L39_006CC350(buf, 0xD));
                    break;
                }
                n = func_L39_006CC350(buf, 3);
                room = q->f30 < q->f24;
                ok = (n > 7) ? 0 : (ready != 0);
                ready = room ? ok : 0;
                if (!ready) {
                    avail = func_L39_006B52A0((T_006B52A0 *)this);
                }
                func_L39_006CC158(buf, 2);
            }
        }
        if (ready) {
            this->f13C->vt->fB8(this->f13C, func_00381FF0(0xFAE));
            this->f140->vt->fB8(this->f140, func_00381FF0(0xFB0));
            this->f118->vt->f20(this->f118, 3, 0);
            this->f11C->vt->f20(this->f11C, 2, 0);
        } else {
            this->f13C->vt->fB8(this->f13C, func_00381FF0(0xFAE));
            this->f140->vt->fB8(this->f140, func_00381FF0(0xFB1));
            this->f118->vt->f20(this->f118, avail ? 3 : 2, 0);
            this->f11C->vt->f20(this->f11C, 2, 0);
        }
    }
}
/* localdecomp:end func_L39_006B5498 */

/* localdecomp:start func_L39_006B5D00 */
typedef struct E_006B5D00 {
    u8 pad0[0x1C];
    s32 f1C;
} E_006B5D00;

typedef struct I_006B5D00 {
    s32 f0;
    s32 count;
    E_006B5D00 **arr;
} I_006B5D00;

typedef struct L_006B5D00 {
    u8 f0;
    u8 pad1[3];
    s32 f4;
    u8 f8;
    u8 pad9[7];
    s32 f10;
    u8 pad14[0x14];
    I_006B5D00 items[1];
} L_006B5D00;

typedef struct B_006B5D00 {
    u8 v;
} B_006B5D00;

typedef struct O_006B5D00 O_006B5D00;

typedef struct V_006B5D00 {
    u8 pad0[0x20];
    void (*f20)(O_006B5D00 *, s32, s32);
} V_006B5D00;

struct O_006B5D00 {
    u8 pad0[0x60];
    V_006B5D00 *vt;
};

typedef struct T_006B5D00 {
    u8 pad0[0x120];
    O_006B5D00 *f120;
    O_006B5D00 *f124;
    O_006B5D00 *f128;
    u8 pad12C[0x2A8 - 0x12C];
    s32 f2A8;
    u8 pad2AC[0x2D9 - 0x2AC];
    u8 f2D9;
    u8 f2DA;
    u8 pad2DB;
    s32 f2DC;
    u8 pad2E0;
    u8 f2E1;
} T_006B5D00;

typedef struct G_006B5D00 {
    u8 pad0[0x30];
    s32 *f30;
    L_006B5D00 *f34;
} G_006B5D00;

__asm__(".extern D_L39_0024D760, 16");
extern struct G_006B5F20 *D_L39_0024D760;
extern s32 func_L39_006CD768(void *);

void func_L39_006B5D00(T_006B5D00 *this) {
    G_006B5D00 *g = (G_006B5D00 *)D_L39_0024D760;
    L_006B5D00 *l = g->f34;
    I_006B5D00 *p;
    B_006B5D00 b;
    u8 found;
    s32 i;

    if (this->f2D9 != 0) {
        if (l->f8 == 0) {
            func_L39_006CD768(l);
            this->f2D9 = 0;
        }
    }
    if (l->f10 != this->f2DC) {
        this->f2DC = l->f10;
        b.v = 0;
        p = 0;
        if (l->f0 != 0 && l->f4 >= 0) {
            p = &l->items[l->f4];
        }
        if (p != 0) {
            if (l->f8 == 0) {
                b.v = 1;
            }
        }
        if (!b.v || *g->f30 == this->f2A8) {
            this->f120->vt->f20(this->f120, 2, 0);
            this->f124->vt->f20(this->f124, 0, 0);
            return;
        }
        found = 0;
        p = 0;
        if (l->f0 != 0 && l->f4 >= 0) {
            p = &l->items[l->f4];
        }
        if (p != 0) {
            for (i = 0; i < p->count; i++) {
                if (p->arr[i]->f1C == this->f2A8) {
                    found = 1;
                    break;
                }
            }
        }
        this->f2DA = found;
        if (this->f2DA) {
            this->f120->vt->f20(this->f120, 0, 0);
            this->f124->vt->f20(this->f124, 3, 0);
        } else {
            this->f120->vt->f20(this->f120, this->f2E1 ? 2 : 3, 0);
            this->f124->vt->f20(this->f124, 0, 0);
        }
        if (this->f2E1 == 0) {
            this->f128->vt->f20(this->f128, this->f2DA ? 2 : 3, 0);
        }
    }
}
/* localdecomp:end func_L39_006B5D00 */

/* localdecomp:start func_L39_006B5F20 */
typedef struct E_006B5F20 {
    u8 pad0[0x1C];
    s32 f1C;
} E_006B5F20;

typedef struct I_006B5F20 {
    s32 f0;
    s32 count;
    E_006B5F20 **arr;
} I_006B5F20;

typedef struct L_006B5F20 {
    u8 f0;
    u8 pad1[3];
    s32 f4;
    u8 f8;
    u8 pad9[7];
    s32 f10;
    u8 pad14[0x14];
    I_006B5F20 items[1];
} L_006B5F20;

typedef struct G_006B5F20 {
    u8 pad0[0x30];
    s32 *f30;
    u8 pad34[0xC];
    L_006B5F20 *f40;
} G_006B5F20;

/* The flag below lives in a byte-wide register in retail (it is zero-extended before its test and
 * set by a branch, not by sltiu); a plain u8 or s32 local is widened and folds to sltiu. */
typedef struct B_006B5F20 {
    u8 v;
} B_006B5F20;

typedef struct O_006B5F20 O_006B5F20;

typedef struct V_006B5F20 {
    u8 pad0[0x20];
    void (*f20)(O_006B5F20 *, s32, s32);
} V_006B5F20;

struct O_006B5F20 {
    u8 pad0[0x60];
    V_006B5F20 *vt;
};

typedef struct T_006B5F20 {
    u8 pad0[0x11C];
    O_006B5F20 *f11C;
    O_006B5F20 *f120;
    u8 pad124[4];
    O_006B5F20 *f128;
    O_006B5F20 *f12C;
    u8 pad130[0x2A8 - 0x130];
    s32 f2A8;
    u8 pad2AC[0x2DA - 0x2AC];
    u8 f2DA;
    u8 pad2DB[5];
    u8 f2E0;
    u8 f2E1;
    u8 pad2E2[2];
    s32 f2E4;
} T_006B5F20;

__asm__(".extern D_L39_0024D760, 16");
extern G_006B5F20 *D_L39_0024D760;
extern void func_L39_006D5D68(L_006B5F20 *);

void func_L39_006B5F20(T_006B5F20 *this) {
    G_006B5F20 *g = D_L39_0024D760;
    L_006B5F20 *l = g->f40;
    I_006B5F20 *p;
    B_006B5F20 b;
    u8 found;
    s32 i;

    if (this->f2E0 != 0) {
        if (l->f8 == 0) {
            func_L39_006D5D68(l);
            this->f2E0 = 0;
        }
    }
    if (l->f10 != this->f2E4) {
        this->f2E4 = l->f10;
        b.v = 0;
        p = 0;
        if (l->f0 != 0 && l->f4 >= 0) {
            p = &l->items[l->f4];
        }
        if (p != 0) {
            if (l->f8 == 0) {
                b.v = 1;
            }
        }
        if (!b.v || *g->f30 == this->f2A8) {
            this->f128->vt->f20(this->f128, 2, 0);
            this->f12C->vt->f20(this->f12C, 0, 0);
            return;
        }
        found = 0;
        p = 0;
        if (l->f0 != 0 && l->f4 >= 0) {
            p = &l->items[l->f4];
        }
        if (p != 0) {
            for (i = 0; i < p->count; i++) {
                if (p->arr[i]->f1C == this->f2A8) {
                    found = 1;
                    break;
                }
            }
        }
        this->f2E1 = found;
        if (this->f2E1) {
            this->f128->vt->f20(this->f128, 0, 0);
            this->f12C->vt->f20(this->f12C, 3, 0);
            this->f11C->vt->f20(this->f11C, 2, 0);
        } else {
            this->f128->vt->f20(this->f128, this->f2DA ? 2 : 3, 0);
            this->f12C->vt->f20(this->f12C, 0, 0);
        }
        if (this->f2DA == 0) {
            this->f120->vt->f20(this->f120, this->f2E1 ? 2 : 3, 0);
        }
    }
}
/* localdecomp:end func_L39_006B5F20 */

/* localdecomp:start func_L39_006B6158 */
typedef struct E_006B6158 {
    u8 pad0[0x1C];
    s32 f1C;
} E_006B6158;

typedef struct I_006B6158 {
    s32 f0;
    s32 count;
    E_006B6158 **arr;
} I_006B6158;

typedef struct M_006B6158 {
    u8 f0;
    u8 pad1[3];
    s32 f4;
    u8 f8;
    u8 pad9[7];
    s32 f10;
    u8 pad14[4];
    I_006B6158 items[1];
} M_006B6158;

typedef struct L_006B6158 {
    s32 f0;
    u8 pad4[0x3B4 - 4];
    M_006B6158 a;
    u8 pad3D8[0x424 - 0x3D8];
    M_006B6158 b;
} L_006B6158;

typedef struct G_006B6158 {
    u8 pad0[0x38];
    L_006B6158 *f38;
} G_006B6158;

typedef struct B_006B6158 {
    u8 v;
} B_006B6158;

typedef struct T_006B6158 {
    u8 pad0[0x2A8];
    s32 f2A8;
    u8 pad2AC[0x2D8 - 0x2AC];
    u8 f2D8;
    u8 pad2D9[0x2E8 - 0x2D9];
    u8 f2E8;
    u8 pad2E9;
    u8 f2EA;
    u8 f2EB;
    s32 f2EC;
    s32 f2F0;
} T_006B6158;

struct G_006B5F20;
__asm__(".extern D_L39_0024D760, 16");
extern struct G_006B5F20 *D_L39_0024D760;
extern void func_L39_006D1658(L_006B6158 *);
extern void func_L39_006D08E8(L_006B6158 *);

void func_L39_006B6158(T_006B6158 *this) {
    L_006B6158 *l = ((G_006B6158 *)D_L39_0024D760)->f38;
    I_006B6158 *p;
    I_006B6158 *p2;
    B_006B6158 b;
    u8 found;
    u8 found2;
    s32 i;
    s32 id;

    if (this->f2E8 != 0) {
        if (l->f0 >= 0 && l->b.f8 == 0 && l->a.f8 == 0) {
            func_L39_006D1658(l);
            func_L39_006D08E8(l);
            this->f2E8 = 0;
        }
    }
    if (l->b.f10 != this->f2EC || l->a.f10 != this->f2F0) {
        b.v = 0;
        p = 0;
        if (l->a.f0 != 0 && l->a.f4 >= 0) {
            p = &l->a.items[l->a.f4];
        }
        if (p != 0) {
            if (l->a.f8 == 0) {
                b.v = 1;
            }
        }
        if (!b.v) {
            return;
        }
        b.v = 0;
        p = 0;
        if (l->b.f0 != 0 && l->b.f4 >= 0) {
            p = &l->b.items[l->b.f4];
        }
        if (p != 0) {
            if (l->b.f8 == 0) {
                b.v = 1;
            }
        }
        if (b.v) {
            found = 0;
            this->f2EC = l->b.f10;
            id = this->f2A8;
            this->f2F0 = l->a.f10;
            p = 0;
            if (l->b.f0 != 0 && l->b.f4 >= 0) {
                p = &l->b.items[l->b.f4];
            }
            if (p != 0) {
                for (i = 0; i < p->count; i++) {
                    if (p->arr[i]->f1C == id) {
                        found = 1;
                        break;
                    }
                }
            }
            this->f2EB = found;
            found2 = 0;
            id = this->f2A8;
            p2 = 0;
            if (l->a.f0 != 0 && l->a.f4 >= 0) {
                p2 = &l->a.items[l->a.f4];
            }
            if (p2 != 0) {
                for (i = 0; i < p2->count; i++) {
                    if (p2->arr[i]->f1C == id) {
                        found2 = 1;
                        break;
                    }
                }
            }
            this->f2EA = found2;
            this->f2D8 = 0;
        }
    }
}
/* localdecomp:end func_L39_006B6158 */

LINKER_REMNANT("asm/levels", func_L39_006B6388);
