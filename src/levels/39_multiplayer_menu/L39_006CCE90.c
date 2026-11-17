#include "common.h"

typedef struct S_006CD768 {
    u8 f0;
    u8 pad1[7];
    u8 f8;
    u8 pad9[3];
    s32 fC;
} S_006CD768;

/* localdecomp:start func_L39_006CCE90 */
typedef struct {
    u16 f00;
    char _p02[0x66 - 0x02];
} Loc_006CCE90;
typedef struct {
    char _p0[0x1];
    u8 f1;
    char _p2[0x8 - 0x2];
    s32 f8;
    char _pC[0x10 - 0xC];
    s32 f10;
    s32 f14;
    char _p18[0x1C - 0x18];
    u8 f1C;
    char _p1D[0x50 - 0x1D];
    s32 f50;
} G_006CCE90;
typedef struct {
    char _p0[0x4];
    char name[0x20];
    u8 f24;
    char _p25[0x30 - 0x25];
    u8 f30;
    char _p31[0x6C - 0x31];
    s32 f6C;
} S_006CCE90;
typedef struct {
    char _p0[0x2DC];
    s32 f2DC;
} P_006CCE90;

void func_00120D28(s32, s32, s32);
void *func_001206F4(void *, void *);
s32 func_00120884(void *);
extern void func_L39_005958A0(s32, s32, s32);
long func_0012DCB0(void);
long func_00130760(long, long);
s32 func_0017E4E0(void *, void *, s32);
void func_001961E8(s32);
s32 func_001961F8(void);
void func_00195410(void);
s32 func_L39_006D8AD8(u8 *);
extern u8 D_00197678[];
extern void *D_001E2050_sda;
extern u16 D_L39_00249B58[];
extern u8 D_001A5CD0[];

/* same shape as func_L39_006DCAD0 */
s32 func_L39_006CCE90(S_006CCE90 *arg0, void *arg1, void *arg2) {
    Loc_006CCE90 loc;
    G_006CCE90 *g;
    P_006CCE90 *p;
    s32 r;

    g = (G_006CCE90 *)D_001E2050_sda;
    func_00120D28((s32)arg0->name, (s32)arg1, 0x20);
    arg0->f24 = 0;
    loc.f00 = D_L39_00249B58[0];
    func_001206F4((u8 *)&loc + 0x15, (void *)g->f50);
    func_L39_005958A0((s32)((u8 *)&loc + 0x26), (s32)arg0->name, func_00120884(arg0->name));
    func_L39_005958A0((s32)((u8 *)&loc + 0x46), (s32)arg2, 0x20);
    arg0->f30 = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017E4E0(&loc, D_00197678, 0));
    p = (P_006CCE90 *)D_001A5CD0;
    while (arg0->f30 != 0) {
        if (func_001961F8() != 0 || p->f2DC != 0) {
            g->f10 = 9;
            if (g->f14 == 0) {
                g->f14 = 9;
            }
            r = 0;
            break;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if (func_L39_006D8AD8((u8 *)g) == 0) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    arg0->f30 = 0;
    if (r != 0) {
        if (arg0->f6C != 0) {
            g->f10 = 9;
            if (g->f14 == 0) {
                g->f14 = 9;
            }
            r = 0;
        }
    }
    if (r != 0) {
        g->f10 = 0;
        g->f14 = 0;
    }
    return r;
}
/* localdecomp:end func_L39_006CCE90 */

/* localdecomp:start func_L39_006CD038 */
typedef struct {
    u8 pad0[0x31];
    u8 f31;
    u8 pad32[0xFE];
    s32 f130;
} T_006CD038;
typedef struct {
    u8 pad0;
    u8 f1;
    u8 pad2[6];
    s32 f8;
    u8 padC[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
    u8 pad1D[0x33];
    void *f50;
} G_006CD038;
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x1B];
} B_006CD038;
typedef struct {
    u8 pad0[0x2DC];
    s32 f2DC;
} P_006CD038;
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern u16 D_L39_00249B58[];
extern u8 D_001976A0[];
extern u8 D_001A5CD0[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern s32 func_0017E568(void *, u8 *, s32);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);
extern void func_00195410(void);
extern s32 func_L39_006D8AD8(u8 *);

s32 func_L39_006CD038(T_006CD038 *a0, s32 a1) {
    s32 r;
    G_006CD038 *g;
    B_006CD038 buf;
    P_006CD038 *p;

    buf.f0 = D_L39_00249B58[0];
    g = (G_006CD038 *)D_L39_0024D760;
    func_001206F4(buf.f15, g->f50);
    a0->f31 = 1;
    g->f1 = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017E568(&buf, D_001976A0, 0));
    p = (P_006CD038 *)D_001A5CD0;
    r = 1;
    while (a0->f31) {
        if (func_001961F8() != 0 || p->f2DC != 0) {
            g->f10 = 0xB;
            if (g->f14 == 0) {
                g->f14 = 0xB;
            }
            r = 0;
            break;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if (!func_L39_006D8AD8((u8 *)g)) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    a0->f31 = 0;
    if (r) {
        if (a0->f130 != 0 && a1 == 0) {
            g->f10 = 0xB;
            if (g->f14 == 0) {
                g->f14 = 0xB;
            }
            r = 0;
        }
        if (a1) {
            func_001961E8(0);
        }
        if (r) {
            g->f10 = 0;
            g->f14 = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006CD038 */

/* localdecomp:start func_L39_006CD1B8 */
typedef struct { u8 bytes[32]; } __attribute__((packed)) Block_6CD1B8;
typedef struct { u8 pad[0x2d]; u8 f2D; u8 pad2[6]; Block_6CD1B8 f34; } Target_6CD1B8;
typedef struct { u8 pad[0x1d]; u8 f1D; u8 pad2[0x12]; Target_6CD1B8 *f30; } Global_6CD1B8;
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;

/* from rac4-decomp's func_L00_00765F58 */
void func_L39_006CD1B8(Block_6CD1B8 *arg) {
    Global_6CD1B8 *g = ((Global_6CD1B8 *)D_L39_0024D760);
    Target_6CD1B8 *t = g->f30;
    if (g->f1D == 0) {
        t->f34 = *arg;
        t->f2D = 0;
    }
}
/* localdecomp:end func_L39_006CD1B8 */

/* localdecomp:start func_L39_006CD218 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { int words[7]; } Data_006CD218;
typedef struct { char pad[0x2E]; unsigned char flag; char pad2[0xE9]; Data_006CD218 data; } Target_006CD218;
typedef struct { char pad[0x1D]; unsigned char flag; char pad2[0x12]; Target_006CD218 *target; } Global_006CD218;

/* from rac4-decomp's func_L00_00765FB8 */
void func_L39_006CD218(Data_006CD218 *arg) {
    Global_006CD218 *g = ((Global_006CD218 *)D_L39_0024D760);
    Target_006CD218 *t = g->target;
    if (!g->flag) {
        t->data = *arg;
        t->flag = 0;
    }
}
/* localdecomp:end func_L39_006CD218 */

/* localdecomp:start func_L39_006CD270 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { int words[7]; } Data_6CD270;
typedef struct { char pad[0x2F]; unsigned char flag; char pad2[0xE8]; Data_6CD270 data; } Target_6CD270;
typedef struct { char pad[0x1D]; unsigned char flag; char pad2[0x12]; Target_6CD270 *target; } Global_6CD270;

/* from rac4-decomp's func_L00_00765FB8 */
void func_L39_006CD270(Data_6CD270 *arg) {
    Global_6CD270 *g = ((Global_6CD270 *)D_L39_0024D760);
    Target_6CD270 *t = g->target;
    if (!g->flag) {
        t->data = *arg;
        t->flag = 0;
    }
}
/* localdecomp:end func_L39_006CD270 */

/* localdecomp:start func_L39_006CD2C8 */
extern u8 D_001A5CD0[];
typedef struct { s32 w[0x31]; } B_006CD2C8;
typedef struct {
    s32 f0;
    u8 pad4[0x24];
    s32 f28;
    u8 f2C;
    u8 pad2D[3];
    u8 f30;
    u8 pad31[0x23];
    B_006CD2C8 f54;
} T_006CD2C8;
typedef struct {
    u8 pad0[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[5];
    u8 f1D;
    u8 pad1E[0x12];
    T_006CD2C8 *f30;
} G_006CD2C8;
typedef struct {
    u8 pad0[0x34];
    s32 f34;
    u8 pad38[0x38];
    s32 f70;
    u8 f74;
} D_006CD2C8;
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;

void func_L39_006CD2C8(B_006CD2C8 *arg0) {
    G_006CD2C8 *g = (G_006CD2C8 *)D_L39_0024D760;
    T_006CD2C8 *t = g->f30;
    s32 v;
    s32 i;

    if (g->f1D == 0) {
        switch (arg0->w[6]) {
        case 0:
            i = 1;
            while (--i >= 0) {
            }
            break;
        case -0x3D2:
            g->f10 = 0xA;
            if (g->f14 == 0) {
                g->f14 = 0xA;
            }
            break;
        case -0x3E6:
            g->f10 = 0xF;
            if (g->f14 == 0) {
                g->f14 = 0xF;
            }
            break;
        case -0x3E5:
            g->f10 = 0x10;
            if (g->f14 == 0) {
                g->f14 = 0x10;
            }
            break;
        case -0x3DF:
            g->f10 = 1;
            if (g->f14 == 0) {
                g->f14 = 1;
            }
            break;
        case -0x3DD:
            g->f10 = 1;
            if (g->f14 == 0) {
                g->f14 = 1;
            }
            break;
        case -0x3DC:
            g->f10 = 1;
            if (g->f14 == 0) {
                g->f14 = 1;
            }
            break;
        case -0x3DB:
            g->f10 = 1;
            if (g->f14 == 0) {
                g->f14 = 1;
            }
            break;
        }
        v = arg0->w[7];
        t->f0 = v;
        ((D_006CD2C8 *)D_001A5CD0)->f34 = v;
        t->f28 = 0;
        ((D_006CD2C8 *)D_001A5CD0)->f70 = 0;
        t->f2C = 0;
        ((D_006CD2C8 *)D_001A5CD0)->f74 = 0;
        t->f54 = *arg0;
        t->f30 = 0;
    }
}
/* localdecomp:end func_L39_006CD2C8 */

/* localdecomp:start func_L39_006CD488 */
typedef struct { u8 bytes[0x18]; s32 f18; } Block_006CD488;
typedef struct { u8 pad[0x31]; u8 f31; u8 pad2[0xE6]; Block_006CD488 f118; } Target_006CD488;
typedef struct { u8 pad[0x10]; s32 f10; s32 f14; u8 pad18[5]; u8 f1D; u8 pad1E[0x12]; Target_006CD488 *f30; } Global_006CD488;
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;

void func_L39_006CD488(Block_006CD488 *arg) {
    Global_006CD488 *g = ((Global_006CD488 *)D_L39_0024D760);
    Target_006CD488 *t = g->f30;
    s32 v;

    if (g->f1D == 0) {
        v = arg->f18;
        switch (v) {
        case -0x3DF:
            v = 1;
            g->f10 = v;
            if (g->f14 == 0) {
                g->f14 = v;
            }
            break;
        case -0x3DD:
            v = 1;
            g->f10 = v;
            if (g->f14 == 0) {
                g->f14 = v;
            }
            break;
        case -0x3DC:
            v = 1;
            g->f10 = v;
            if (g->f14 == 0) {
                g->f14 = v;
            }
            break;
        case -0x3DB:
            v = 1;
            g->f10 = v;
            if (g->f14 == 0) {
                g->f14 = v;
            }
            break;
        case 0:
            break;
        default:
            if (v < 0) {
                v = 1;
                g->f10 = v;
                if (g->f14 == 0) {
                    g->f14 = v;
                }
            }
            break;
        }
    }
    t->f118 = *arg;
    t->f31 = 0;
}
/* localdecomp:end func_L39_006CD488 */

/* localdecomp:start func_L39_006CD540 */
typedef struct { u8 a; u8 p[3]; s32 b; } E_006CD540;
typedef struct { E_006CD540 e[2]; s32 c; u8 d; u8 q[7]; u8 f; } S_006CD540;
S_006CD540 *func_L39_006CD540(S_006CD540 *s) {
    s->e[0].a = 0; s->e[0].b = -1;
    s->e[1].a = 0; s->e[1].b = -1;
    s->c = -1;
    s->d = 0;
    s->f = 0;
    return s;
}
/* localdecomp:end func_L39_006CD540 */

/* localdecomp:start func_L39_006CD568 */
typedef struct S_006CD568 {
    s32 pad0;
    s32 a4;
    u8 b8;
    u8 p9[3];
    s32 aC;
    s32 a10;
    u8 b14;
    u8 p15[7];
    u8 b1C;
} S_006CD568;
void func_L39_006CD568(S_006CD568 *arg0) {
    arg0->a4 = -1;
    arg0->b8 = 0;
    arg0->aC = -1;
    arg0->a10 = -1;
    arg0->b14 = 0;
    arg0->b1C = 0;
}
/* localdecomp:end func_L39_006CD568 */

/* localdecomp:start func_L39_006CD588 */
s32 func_L39_006E16A0(s32, s32, s32, s32);

s32 func_L39_006CD588(u32 arg0, s32 arg1) {
    u32 r = arg0;
    u32 m;
    u32 rem;
    u32 a;
    r += func_L39_006E16A0(r, arg1 * 2, 0xD0, 4);
    m = 4;
    rem = r % m;
    a = r;
    if (rem != 0) {
        a = r + (m - rem);
    }
    r = a;
    r += arg1 * 8;
    return r - arg0;
}
/* localdecomp:end func_L39_006CD588 */

/* localdecomp:start func_L39_006CD5F0 */
typedef struct {
    s32 f0;
    s32 f4;
    u32 f8;
} L_006CD5F0;
typedef struct {
    u8 f0;
    u8 pad1[7];
    u8 f8;
    u8 pad9[0x1B];
    s32 f24;
    L_006CD5F0 f28;
    L_006CD5F0 f34;
    s32 f40;
    u32 f44;
} S_006CD5F0;
extern s32 func_L39_006E16A0(s32, s32, s32, s32);
extern s32 func_L39_006E1648(s32, s32, s32, s32);
extern void func_11D534(void *, s32, s32);

void func_L39_006CD5F0(S_006CD5F0 *s, u32 base, s32 unused, s32 n) {
    u32 buf;
    u32 r;
    u32 align;
    L_006CD5F0 *a;
    L_006CD5F0 *b;

    if (s->f0 == 0) {
        s->f8 = 0;
        s->f24 = n;
        s->f0 = 1;
        buf = base;
        r = func_L39_006E16A0(base, n * 2, 0xD0, 4);
        s->f40 = func_L39_006E1648(buf, r, 0xD0, 4);
        buf += r;
        align = 4;
        buf = (buf % align) ? buf + (align - buf % align) : buf;
        s->f44 = buf;
        func_11D534((void *)buf, 0, s->f24 * 8);
        a = &s->f28;
        b = &s->f34;
        a->f0 = 0;
        a->f8 = s->f44;
        a->f4 = 0;
        b->f0 = 0;
        b->f8 = s->f24 * 4 + s->f44;
        b->f4 = 0;
    }
}
/* localdecomp:end func_L39_006CD5F0 */

/* localdecomp:start func_L39_006CD6E0 */
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
s32 func_L39_006CD768(u8 *);

s32 func_L39_006CD6E0(u8 *arg0) {
    s32 result = 1;

    if (arg0[0] != 0) {
        if (arg0[8] != 0) {
            if (((s32) func_00130760(func_0012DCB0(), 0x24000) - *(s32 *) (arg0 + 0xC)) >= 0x3A99) {
                arg0[8] = 0;
                result = 0;
                func_L39_006CD768(arg0);
            }
        }
    }
    return result;
}
/* localdecomp:end func_L39_006CD6E0 */

/* localdecomp:start func_L39_006CD768 */
extern u16 D_L39_00249BC0[];
extern u8 D_001976F0[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_0017F7D8(u16 *, u8 *, s32);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);

s32 func_L39_006CD768(u8 *arg0) {
    S_006CD768 *p = (S_006CD768 *)arg0;
    s32 r = 1;
    u16 x[16];

    if (p->f0 != 0) {
        x[0] = D_L39_00249BC0[0];
        p->f8 = 1;
        p->fC = (s32) func_00130760(func_0012DCB0(), 0x24000);
        func_001961E8(func_0017F7D8(x, D_001976F0, 0));
        if (func_001961F8() != 0) {
            p->f8 = 0;
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006CD768 */

/* localdecomp:start func_L39_006CD808 */
typedef struct E_006CD808 {
    s32 pad0[6];
    s32 f18;
    u8 pad1C[0xCC - 0x1C];
    u8 fCC;
    u8 padCD[3];
} E_006CD808;

typedef s32 (*Cmp_006CD808)(E_006CD808 *, E_006CD808 *);

typedef struct Q_006CD808 {
    Cmp_006CD808 cmp;
    s32 count;
    E_006CD808 **arr;
} Q_006CD808;

typedef struct P_006CD808 {
    u8 pad0[0xC];
    s32 fC;
    u8 pad10[8];
    s32 f18;
    u8 *f1C;
} P_006CD808;

typedef struct M_006CD808 {
    u8 f0;
    u8 pad1[3];
    s32 f4;
    u8 f8;
    u8 pad9[3];
    s32 fC;
    s32 f10;
    u8 pad14[0x10];
    s32 f24;
    Q_006CD808 q[2];
    P_006CD808 *f40;
} M_006CD808;

typedef struct G_006CD808 {
    u8 pad0[0x1D];
    u8 f1D;
    u8 pad1E[0x16];
    M_006CD808 *f34;
} G_006CD808;

__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
void func_0011D534(void *, s32, s32);

void func_L39_006CD808(E_006CD808 *arg0) {
    G_006CD808 *g = (G_006CD808 *)D_L39_0024D760;
    M_006CD808 *m = g->f34;
    Q_006CD808 *q;
    Q_006CD808 *p;
    P_006CD808 *pool;
    E_006CD808 *node;
    E_006CD808 *n;
    P_006CD808 *pool2;
    E_006CD808 *node2;
    E_006CD808 *e;
    E_006CD808 *t;
    s32 which;
    s32 i;
    s32 k;
    s32 j;
    s32 child;

    if (m->f0 == 0 || g->f1D != 0) {
        return;
    }
    if (m->f4 == 0) {
        which = 1;
    } else {
        which = 0;
    }
    q = &m->q[which];
    if (arg0->f18 == 0) {
        if (q->count < m->f24) {
            pool = m->f40;
            n = (E_006CD808 *)pool->f1C;
            if (n != 0) {
                pool->f1C = *(u8 **)((u8 *)n + pool->fC);
                pool->f18--;
            }
            node = n;
            if (node != 0) {
                *node = *arg0;
                j = q->count++;
                q->arr[j] = node;
                if (q->cmp != 0) {
                    i = j / 2;
                    while (j > 0 && (u8)q->cmp(q->arr[i], q->arr[j])) {
                        t = q->arr[i];
                        q->arr[i] = q->arr[j];
                        q->arr[j] = t;
                        j = i;
                    }
                }
            }
        }
    } else if (arg0->f18 != 1) {
        if (arg0->fCC != 0) {
            func_0011D534(arg0, 0, 0xD0);
            arg0->fCC = 1;
        } else {
            func_0011D534(arg0, 0, 0xD0);
        }
    } else {
        arg0->fCC = 1;
    }
    if (arg0->fCC == 0) {
        return;
    }
    if (q->cmp != 0 && q->count >= 2) {
        for (k = q->count - 1; k > 0; k--) {
            t = q->arr[k];
            q->arr[k] = q->arr[0];
            q->arr[0] = t;
            if (q->cmp != 0) {
                i = k;
                e = q->arr[i];
                child = i * 2 + 1;
                while (child < 0) {
                    s32 r = child + 1;
                    if (r < 0) {
                        if ((u8)q->cmp(q->arr[child], q->arr[r])) {
                            child = r;
                        }
                        if (q->cmp(e, q->arr[child])) {
                            q->arr[i] = q->arr[child];
                            i = child;
                            child = i * 2 + 1;
                        } else {
                            break;
                        }
                    }
                }
                q->arr[i] = e;
            }
        }
    }
    p = 0;
    if (m->f0 != 0 && m->f4 >= 0) {
        p = &m->q[m->f4];
    }
    if (p != 0) {
        for (k = 0; k < p->count; k++) {
            pool2 = m->f40;
            node2 = p->arr[k];
            *(u8 **)((u8 *)node2 + pool2->fC) = pool2->f1C;
            pool2->f1C = (u8 *)node2;
            pool2->f18++;
        }
        p->count = 0;
    }
    m->f4 = which;
    m->f10 = m->fC;
    m->f8 = 0;
}
/* localdecomp:end func_L39_006CD808 */

/* localdecomp:start func_L39_006CDC30 */
typedef struct {
    u8 pad0[0x14];
    u8 f14;
    u8 pad15[3];
    s32 f18;
} S_006CDC30;
typedef struct {
    u8 f0;
    u8 f1;
    u8 pad2[6];
    s32 f8;
    u8 padC[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
    u8 pad1D[0x33];
    void *f50;
} S_006CDC30_G;
extern u16 D_L39_00249BC0[];
extern u8 D_001976C8[];
typedef struct { u8 pad[0x2DC]; s32 f2DC; } S_006CDC30_D;
extern u8 D_001A5CD0[];
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern s32 func_0017ECA8(void *, u8 *, s32);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);
extern void func_00195410(void);
extern s32 func_L39_006D8AD8(u8 *);

s32 func_L39_006CDC30(S_006CDC30 *arg0, s32 arg1) {
    S_006CDC30_G *g = (S_006CDC30_G *)D_L39_0024D760;
    s32 r;
    struct { u16 x[1]; u8 pad2[0x13]; u8 buf[0x13]; s32 a; u8 pad3[0x4]; } l;

    void *name = g->f50;
    l.x[0] = D_L39_00249BC0[0];
    func_001206F4(l.buf, name);
    l.a = arg1;
    g->f1 = arg0->f14 = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017ECA8(&l, D_001976C8, 0));
    r = 1;
    while (arg0->f14 != 0) {
        if (func_001961F8() != 0 || ((S_006CDC30_D *)D_001A5CD0)->f2DC != 0) {
            g->f10 = 0x12;
            if (g->f14 == 0) {
                g->f14 = 0x12;
            }
            r = 0;
            break;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if (func_L39_006D8AD8((u8 *)g) == 0) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    arg0->f14 = 0;
    if (r != 0) {
        if (arg0->f18 == -0x3DD) {
            r = 0;
        } else if (arg0->f18 == -0x3DC) {
            g->f10 = 0x12;
            if (g->f14 == 0) {
                g->f14 = 0x12;
            }
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006CDC30 */

/* localdecomp:start func_L39_006CDD90 */
typedef struct {
    u8 pad0[0x14];
    s8 f14;
    s32 f18;
} S_6CDD90_B;
typedef struct {
    u8 pad0[0x34];
    S_6CDD90_B *f34;
} S_6CDD90_A;
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006CDD90(S_6CDD90_B *arg0) {
    S_6CDD90_B *p = ((S_6CDD90_A *)D_L39_0024D760)->f34;
    p->f14 = 0;
    p->f18 = arg0->f18;
}
/* localdecomp:end func_L39_006CDD90 */

/* localdecomp:start func_L39_006CDDB0 */
typedef struct {
    u8 pad0[0x1C];
    u8 f1C;
    u8 pad1D[3];
    s32 f20;
} S_006CDDB0;
typedef struct {
    u8 f0;
    u8 f1;
    u8 pad2[6];
    s32 f8;
    u8 padC[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
    u8 pad1D[0x33];
    void *f50;
} S_006CDDB0_G;
extern u16 D_L39_00249BC0[];
extern u8 D_00197718[];
typedef struct { u8 pad[0x2DC]; s32 f2DC; } S_006CDDB0_D;
extern u8 D_001A5CD0[];
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern s32 func_0017ED28(void *, u8 *, s32);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);
extern void func_00195410(void);
extern s32 func_L39_006D8AD8(u8 *);

s32 func_L39_006CDDB0(S_006CDDB0 *arg0, s32 arg1) {
    S_006CDDB0_G *g = (S_006CDDB0_G *)D_L39_0024D760;
    s32 r;
    struct { u16 x[1]; u8 pad2[0x13]; u8 buf[0x13]; s32 a; u8 pad3[0x4]; } l;

    void *name = g->f50;
    l.x[0] = D_L39_00249BC0[0];
    func_001206F4(l.buf, name);
    l.a = arg1;
    g->f1 = arg0->f1C = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017ED28(&l, D_00197718, 0));
    r = 1;
    while (arg0->f1C != 0) {
        if (func_001961F8() != 0 || ((S_006CDDB0_D *)D_001A5CD0)->f2DC != 0) {
            g->f10 = 0x13;
            if (g->f14 == 0) {
                g->f14 = 0x13;
            }
            r = 0;
            break;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if (func_L39_006D8AD8((u8 *)g) == 0) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    arg0->f1C = 0;
    if (r != 0) {
        if (arg0->f20 == -0x3DD) {
            r = 0;
        } else if (arg0->f20 == -0x3DC) {
            g->f10 = 0x13;
            if (g->f14 == 0) {
                g->f14 = 0x13;
            }
        }
    }
    return r;
}
/* localdecomp:end func_L39_006CDDB0 */

/* localdecomp:start func_L39_006CDF18 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { u8 pad0[0x1C]; s8 f1C; u8 pad1[3]; s32 f20; } Sub_6CDF18;
typedef struct { u8 pad0[0x34]; Sub_6CDF18 *f34; } Obj_6CDF18;

/* from rac4-decomp's func_L00_00766DB0 */
void func_L39_006CDF18(s32 *arg0) {
    Sub_6CDF18 *s = ((Obj_6CDF18 *)D_L39_0024D760)->f34;
    s->f1C = 0;
    s->f20 = arg0[6];
}
/* localdecomp:end func_L39_006CDF18 */

/* localdecomp:start func_L39_006CDF38 */
void func_L39_006CDF38(void *arg0) {
    *(s8 *)((u8 *)arg0 + 0x34) = 0;
    *(s8 *)((u8 *)arg0 + 0x5C) = 0;
    *(s8 *)((u8 *)arg0 + 0x64) = 0;
    *(s8 *)((u8 *)arg0 + 0x6C) = 0;
    *(s8 *)((u8 *)arg0 + 0x7C) = 0;
    *(s8 *)((u8 *)arg0 + 0x84) = 0;
    *(s8 *)((u8 *)arg0 + 0x8C) = 0;
    *(s8 *)((u8 *)arg0 + 0x94) = 0;
    *(s8 *)((u8 *)arg0 + 0x9C) = 0;
    *(s8 *)((u8 *)arg0 + 0xA4) = 0;
    *(s8 *)((u8 *)arg0 + 0xAC) = 0;
    *(s8 *)((u8 *)arg0 + 0xB4) = 0;
    *(s8 *)((u8 *)arg0 + 0xBC) = 0;
    *(s8 *)((u8 *)arg0 + 0xC4) = 0;
    *(s8 *)((u8 *)arg0 + 0xCC) = 0;
    *(s8 *)((u8 *)arg0 + 0xD4) = 0;
    *(s8 *)((u8 *)arg0 + 0x220) = 0;
    *(s8 *)((u8 *)arg0 + 0x38C) = 0;
    *(s32 *)((u8 *)arg0 + 0x3B8) = -1;
    *(s8 *)((u8 *)arg0 + 0x3BC) = 0;
    *(s32 *)((u8 *)arg0 + 0x3C0) = -1;
    *(s32 *)((u8 *)arg0 + 0x3C4) = -1;
    *(s32 *)((u8 *)arg0 + 0x3F0) = -1;
    *(s8 *)((u8 *)arg0 + 0x3F4) = 0;
    *(s32 *)((u8 *)arg0 + 0x3F8) = -1;
    *(s32 *)((u8 *)arg0 + 0x3FC) = -1;
    *(s32 *)((u8 *)arg0 + 0x428) = -1;
    *(s8 *)((u8 *)arg0 + 0x42C) = 0;
    *(s32 *)((u8 *)arg0 + 0x430) = -1;
    *(s32 *)((u8 *)arg0 + 0x434) = -1;
    *(s32 *)((u8 *)arg0 + 0x460) = -1;
    *(s8 *)((u8 *)arg0 + 0x464) = 0;
    *(s32 *)((u8 *)arg0 + 0x468) = -1;
    *(s32 *)((u8 *)arg0 + 0x46C) = -1;
    *(s32 *)((u8 *)arg0 + 0x4A0) = -1;
    *(s8 *)((u8 *)arg0 + 0x4A4) = 0;
    *(s32 *)((u8 *)arg0 + 0x4A8) = -1;
    *(s32 *)((u8 *)arg0 + 0x4AC) = -1;
    *(s32 *)((u8 *)arg0 + 0x4E0) = -1;
    *(s8 *)((u8 *)arg0 + 0x4E4) = 0;
    *(s32 *)((u8 *)arg0 + 0x4E8) = -1;
    *(s32 *)((u8 *)arg0 + 0x4EC) = -1;
    *(s32 *)((u8 *)arg0 + 0x518) = -1;
    *(s8 *)((u8 *)arg0 + 0x51C) = 0;
    *(s32 *)((u8 *)arg0 + 0x520) = -1;
    *(s32 *)((u8 *)arg0 + 0x524) = -1;
    *(s32 *)((u8 *)arg0 + 0x0) = -1;
}
/* localdecomp:end func_L39_006CDF38 */

/* localdecomp:start func_L39_006CE000 */
s32 func_L39_006E16A0(s32, s32, s32, s32);

s32 func_L39_006CE000(u32 arg0, s32 arg1) {
    u32 r = arg0;
    u32 m;
    u32 rem;
    u32 a;
    r += func_L39_006E16A0(r, arg1 * 2, 0x1DC, 4);
    m = 4;
    rem = r % m;
    a = r;
    if (rem != 0) {
        a = r + (m - rem);
    }
    r = a;
    r += arg1 * 8;
    return r - arg0;
}
/* localdecomp:end func_L39_006CE000 */

/* localdecomp:start func_L39_006CE068 */
typedef struct {
    s32 f0;
    s32 f4;
    u32 f8;
} L_006CE068;
typedef struct {
    u8 pad0[0x3B4];
    u8 f0;
    u8 pad1[7];
    u8 f8;
    u8 pad9[0xB];
    s32 f24;
    L_006CE068 f28;
    L_006CE068 f34;
    s32 f40;
    u32 f44;
} S_006CE068;
s32 func_L39_006E16A0(s32, s32, s32, s32);
extern s32 func_L39_006E1648(s32, s32, s32, s32);
extern void func_0011D534(void *, s32, s32);

void func_L39_006CE068(S_006CE068 *s, u32 base, s32 unused, s32 n) {
    u32 buf;
    u32 r;
    u32 align;
    L_006CE068 *a;
    L_006CE068 *b;

    if (s->f0 == 0) {
        s->f8 = 0;
        s->f24 = n;
        s->f0 = 1;
        buf = base;
        r = (u32)func_L39_006E16A0((s32)base, n * 2, 0x1DC, 4);
        s->f40 = func_L39_006E1648((s32)buf, (s32)r, 0x1DC, 4);
        buf += r;
        align = 4;
        buf = (buf % align) ? buf + (align - buf % align) : buf;
        s->f44 = buf;
        func_0011D534((void *)buf, 0, s->f24 * 8);
        a = &s->f28;
        b = &s->f34;
        a->f0 = 0;
        a->f8 = s->f44;
        a->f4 = 0;
        b->f0 = 0;
        b->f8 = s->f24 * 4 + s->f44;
        b->f4 = 0;
    }
}
/* localdecomp:end func_L39_006CE068 */

/* localdecomp:start func_L39_006CE150 */
s32 func_L39_006E16A0(s32, s32, s32, s32);

s32 func_L39_006CE150(u32 arg0, s32 arg1) {
    u32 r = arg0;
    u32 m;
    u32 rem;
    u32 a;
    r += func_L39_006E16A0(r, arg1 * 2, 0xD4, 4);
    m = 4;
    rem = r % m;
    a = r;
    if (rem != 0) {
        a = r + (m - rem);
    }
    r = a;
    r += arg1 * 8;
    return r - arg0;
}
/* localdecomp:end func_L39_006CE150 */

/* localdecomp:start func_L39_006CE1B8 */
typedef struct {
    s32 f0;
    s32 f4;
    u32 f8;
} L_006CE1B8;
typedef struct {
    u8 pad0[0x3EC];
    u8 f0;
    u8 pad1[7];
    u8 f8;
    u8 pad9[0xB];
    s32 f24;
    L_006CE1B8 f28;
    L_006CE1B8 f34;
    s32 f40;
    u32 f44;
} S_006CE1B8;
s32 func_L39_006E16A0(s32, s32, s32, s32);
extern s32 func_L39_006E1648(s32, s32, s32, s32);
extern void func_0011D534(void *, s32, s32);

void func_L39_006CE1B8(S_006CE1B8 *s, u32 base, s32 unused, s32 n) {
    u32 buf;
    u32 r;
    u32 align;
    L_006CE1B8 *a;
    L_006CE1B8 *b;

    if (s->f0 == 0) {
        s->f8 = 0;
        s->f24 = n;
        s->f0 = 1;
        buf = base;
        r = (u32)func_L39_006E16A0((s32)base, n * 2, 0xD4, 4);
        s->f40 = func_L39_006E1648((s32)buf, (s32)r, 0xD4, 4);
        buf += r;
        align = 4;
        buf = (buf % align) ? buf + (align - buf % align) : buf;
        s->f44 = buf;
        func_0011D534((void *)buf, 0, s->f24 * 8);
        a = &s->f28;
        b = &s->f34;
        a->f0 = 0;
        a->f8 = s->f44;
        a->f4 = 0;
        b->f0 = 0;
        b->f8 = s->f24 * 4 + s->f44;
        b->f4 = 0;
    }
}
/* localdecomp:end func_L39_006CE1B8 */

/* localdecomp:start func_L39_006CE2A0 */
s32 func_L39_006E16A0(s32, s32, s32, s32);

s32 func_L39_006CE2A0(u32 arg0, s32 arg1) {
    u32 r = arg0;
    u32 m;
    u32 rem;
    u32 a;
    r += func_L39_006E16A0(r, arg1 * 2, 0x114, 4);
    m = 4;
    rem = r % m;
    a = r;
    if (rem != 0) {
        a = r + (m - rem);
    }
    r = a;
    r += arg1 * 8;
    return r - arg0;
}
/* localdecomp:end func_L39_006CE2A0 */

/* localdecomp:start func_L39_006CE308 */
typedef struct {
    s32 f0;
    s32 f4;
    u32 f8;
} L_006CE308;
typedef struct {
    u8 pad0[0x424];
    u8 f0;
    u8 pad1[7];
    u8 f8;
    u8 pad9[0xB];
    s32 f24;
    L_006CE308 f28;
    L_006CE308 f34;
    s32 f40;
    u32 f44;
} S_006CE308;
s32 func_L39_006E16A0(s32, s32, s32, s32);
extern s32 func_L39_006E1648(s32, s32, s32, s32);
extern void func_0011D534(void *, s32, s32);

void func_L39_006CE308(S_006CE308 *s, u32 base, s32 unused, s32 n) {
    u32 buf;
    u32 r;
    u32 align;
    L_006CE308 *a;
    L_006CE308 *b;

    if (s->f0 == 0) {
        s->f8 = 0;
        s->f24 = n;
        s->f0 = 1;
        buf = base;
        r = (u32)func_L39_006E16A0((s32)base, n * 2, 0x114, 4);
        s->f40 = func_L39_006E1648((s32)buf, (s32)r, 0x114, 4);
        buf += r;
        align = 4;
        buf = (buf % align) ? buf + (align - buf % align) : buf;
        s->f44 = buf;
        func_0011D534((void *)buf, 0, s->f24 * 8);
        a = &s->f28;
        b = &s->f34;
        a->f0 = 0;
        a->f8 = s->f44;
        a->f4 = 0;
        b->f0 = 0;
        b->f8 = s->f24 * 4 + s->f44;
        b->f4 = 0;
    }
}
/* localdecomp:end func_L39_006CE308 */

/* localdecomp:start func_L39_006CE3F0 */
s32 func_L39_006E16A0(s32, s32, s32, s32);

s32 func_L39_006CE3F0(u32 arg0, s32 arg1) {
    u32 r = arg0;
    u32 m;
    u32 rem;
    u32 a;
    r += func_L39_006E16A0(r, arg1 * 2, 0x118, 4);
    m = 4;
    rem = r % m;
    a = r;
    if (rem != 0) {
        a = r + (m - rem);
    }
    r = a;
    r += arg1 * 8;
    return r - arg0;
}
/* localdecomp:end func_L39_006CE3F0 */

/* localdecomp:start func_L39_006CE458 */
typedef struct S_006CE458_Q { s32 f0; s32 f4; s32 f8; } S_006CE458_Q;
typedef struct S_006CE458 {
    u8 pad0[0x45C];
    u8 f45C;
    u8 pad45D[7];
    u8 f464;
    u8 pad465[0xB];
    s32 f470;
    S_006CE458_Q f474;
    S_006CE458_Q f480;
    s32 f48C;
    u32 f490;
} S_006CE458;
extern s32 func_L39_006E16A0(s32, s32, s32, s32);
extern s32 func_L39_006E1648(s32, s32, s32, s32);
extern void func_L39_006CE458(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    S_006CE458 *p = (S_006CE458 *)arg0;
    S_006CE458_Q *q;
    S_006CE458_Q *q2;
    u32 r;
    u32 m;
    u32 rem;
    u32 a;
    s32 size;

    if (p->f45C == 0) {
        r = arg1;
        p->f464 = 0;
        p->f470 = arg3;
        p->f45C = 1;
        size = func_L39_006E16A0(r, arg3 * 2, 0x118, 4);
        p->f48C = func_L39_006E1648(r, size, 0x118, 4);
        r += size;
        m = 4;
        rem = r % m;
        a = r;
        if (rem != 0) {
            a = r + (m - rem);
        }
        r = a;
        p->f490 = r;
        func_0011D534(r, 0, p->f470 * 8);
        q = &p->f474;
        q->f0 = 0;
        q->f8 = p->f490;
        q->f4 = 0;
        q2 = &p->f480;
        q2->f0 = 0;
        q2->f8 = p->f470 * 4 + p->f490;
        q2->f4 = 0;
    }
}
/* localdecomp:end func_L39_006CE458 */

/* localdecomp:start func_L39_006CE540 */
s32 func_L39_006E16A0(s32, s32, s32, s32);

s32 func_L39_006CE540(u32 arg0, s32 arg1) {
    u32 r = arg0;
    u32 m;
    u32 rem;
    u32 a;
    r += func_L39_006E16A0(r, arg1 * 2, 0x48, 4);
    m = 4;
    rem = r % m;
    a = r;
    if (rem != 0) {
        a = r + (m - rem);
    }
    r = a;
    r += arg1 * 8;
    return r - arg0;
}
/* localdecomp:end func_L39_006CE540 */

/* localdecomp:start func_L39_006CE5A8 */
typedef struct {
    s32 f0;
    s32 f4;
    u32 f8;
} L_006CE5A8;
typedef struct {
    u8 pad0[0x49C];
    u8 f0;
    u8 pad1[7];
    u8 f8;
    u8 pad9[0xB];
    s32 f24;
    L_006CE5A8 f28;
    L_006CE5A8 f34;
    s32 f40;
    u32 f44;
} S_006CE5A8;
s32 func_L39_006E16A0(s32, s32, s32, s32);
extern s32 func_L39_006E1648(s32, s32, s32, s32);
extern void func_0011D534(void *, s32, s32);

void func_L39_006CE5A8(S_006CE5A8 *s, u32 base, s32 unused, s32 n) {
    u32 buf;
    u32 r;
    u32 align;
    L_006CE5A8 *a;
    L_006CE5A8 *b;

    if (s->f0 == 0) {
        s->f8 = 0;
        s->f24 = n;
        s->f0 = 1;
        buf = base;
        r = (u32)func_L39_006E16A0((s32)base, n * 2, 0x48, 4);
        s->f40 = func_L39_006E1648((s32)buf, (s32)r, 0x48, 4);
        buf += r;
        align = 4;
        buf = (buf % align) ? buf + (align - buf % align) : buf;
        s->f44 = buf;
        func_0011D534((void *)buf, 0, s->f24 * 8);
        a = &s->f28;
        b = &s->f34;
        a->f0 = 0;
        a->f8 = s->f44;
        a->f4 = 0;
        b->f0 = 0;
        b->f8 = s->f24 * 4 + s->f44;
        b->f4 = 0;
    }
}
/* localdecomp:end func_L39_006CE5A8 */

/* localdecomp:start func_L39_006CE690 */
s32 func_L39_006E16A0(s32, s32, s32, s32);

s32 func_L39_006CE690(u32 arg0, s32 arg1) {
    u32 r = arg0;
    u32 m;
    u32 rem;
    u32 a;
    r += func_L39_006E16A0(r, arg1 * 2, 0x1C4, 4);
    m = 4;
    rem = r % m;
    a = r;
    if (rem != 0) {
        a = r + (m - rem);
    }
    r = a;
    r += arg1 * 8;
    return r - arg0;
}
/* localdecomp:end func_L39_006CE690 */

/* localdecomp:start func_L39_006CE6F8 */
typedef struct {
    s32 f0;
    s32 f4;
    u32 f8;
} L_006CE6F8;
typedef struct {
    u8 pad0[0x4DC];
    u8 f0;
    u8 pad1[7];
    u8 f8;
    u8 pad9[0xB];
    s32 f24;
    L_006CE6F8 f28;
    L_006CE6F8 f34;
    s32 f40;
    u32 f44;
} S_006CE6F8;
s32 func_L39_006E16A0(s32, s32, s32, s32);
extern s32 func_L39_006E1648(s32, s32, s32, s32);
extern void func_0011D534(void *, s32, s32);

void func_L39_006CE6F8(S_006CE6F8 *s, u32 base, s32 unused, s32 n) {
    u32 buf;
    u32 r;
    u32 align;
    L_006CE6F8 *a;
    L_006CE6F8 *b;

    if (s->f0 == 0) {
        s->f8 = 0;
        s->f24 = n;
        s->f0 = 1;
        buf = base;
        r = (u32)func_L39_006E16A0((s32)base, n * 2, 0x1C4, 4);
        s->f40 = func_L39_006E1648((s32)buf, (s32)r, 0x1C4, 4);
        buf += r;
        align = 4;
        buf = (buf % align) ? buf + (align - buf % align) : buf;
        s->f44 = buf;
        func_0011D534((void *)buf, 0, s->f24 * 8);
        a = &s->f28;
        b = &s->f34;
        a->f0 = 0;
        a->f8 = s->f44;
        a->f4 = 0;
        b->f0 = 0;
        b->f8 = s->f24 * 4 + s->f44;
        b->f4 = 0;
    }
}
/* localdecomp:end func_L39_006CE6F8 */

/* localdecomp:start func_L39_006CE7E0 */
s32 func_L39_006E16A0(s32, s32, s32, s32);

s32 func_L39_006CE7E0(u32 arg0, s32 arg1) {
    u32 r = arg0;
    u32 m;
    u32 rem;
    u32 a;
    r += func_L39_006E16A0(r, arg1 * 2, 0x28, 4);
    m = 4;
    rem = r % m;
    a = r;
    if (rem != 0) {
        a = r + (m - rem);
    }
    r = a;
    r += arg1 * 8;
    return r - arg0;
}
/* localdecomp:end func_L39_006CE7E0 */

/* localdecomp:start func_L39_006CE848 */
typedef struct {
    s32 f0;
    s32 f4;
    u32 f8;
} L_006CE848;
typedef struct {
    u8 pad0[0x515];
    u8 f0;
    u8 pad1[6];
    u8 f8;
    u8 pad9[0xB];
    s32 f24;
    L_006CE848 f28;
    L_006CE848 f34;
    s32 f40;
    u32 f44;
} S_006CE848;
s32 func_L39_006E16A0(s32, s32, s32, s32);
extern s32 func_L39_006E1648(s32, s32, s32, s32);
extern void func_0011D534(void *, s32, s32);

void func_L39_006CE848(S_006CE848 *s, u32 base, s32 unused, s32 n) {
    u32 buf;
    u32 r;
    u32 align;
    L_006CE848 *a;
    L_006CE848 *b;

    if (s->f0 == 0) {
        s->f8 = 0;
        s->f24 = n;
        s->f0 = 1;
        buf = base;
        r = (u32)func_L39_006E16A0((s32)base, n * 2, 0x28, 4);
        s->f40 = func_L39_006E1648((s32)buf, (s32)r, 0x28, 4);
        buf += r;
        align = 4;
        buf = (buf % align) ? buf + (align - buf % align) : buf;
        s->f44 = buf;
        func_0011D534((void *)buf, 0, s->f24 * 8);
        a = &s->f28;
        b = &s->f34;
        a->f0 = 0;
        a->f8 = s->f44;
        a->f4 = 0;
        b->f0 = 0;
        b->f8 = s->f24 * 4 + s->f44;
        b->f4 = 0;
    }
}
/* localdecomp:end func_L39_006CE848 */

/* localdecomp:start func_L39_006CE930 */
/* from rac4-decomp's func_L00_00767968 */
void *func_L39_006CE930(void *arg0) {
    u8 *p = (u8 *)arg0;
    *(s8 *)(p + 0x34) = 0;
    *(s32 *)(p + 0x0) = -1;
    *(s8 *)(p + 0x5C) = 0;
    *(s8 *)(p + 0x64) = 0;
    *(s8 *)(p + 0x6C) = 0;
    *(s8 *)(p + 0x7C) = 0;
    *(s8 *)(p + 0x84) = 0;
    *(s8 *)(p + 0x8C) = 0;
    *(s8 *)(p + 0x94) = 0;
    *(s8 *)(p + 0x9C) = 0;
    *(s8 *)(p + 0xA4) = 0;
    *(s8 *)(p + 0xAC) = 0;
    *(s8 *)(p + 0xB4) = 0;
    *(s8 *)(p + 0xBC) = 0;
    *(s8 *)(p + 0xC4) = 0;
    *(s8 *)(p + 0xCC) = 0;
    *(s8 *)(p + 0xD4) = 0;
    *(s8 *)(p + 0x220) = 0;
    *(s8 *)(p + 0x38C) = 0;
    *(s8 *)(p + 0x3B4) = 0;
    *(s32 *)(p + 0x3B8) = -1;
    *(s8 *)(p + 0x3BC) = 0;
    *(s32 *)(p + 0x3C0) = -1;
    *(s32 *)(p + 0x3C4) = -1;
    *(s8 *)(p + 0x3EC) = 0;
    *(s32 *)(p + 0x3F0) = -1;
    *(s8 *)(p + 0x3F4) = 0;
    *(s32 *)(p + 0x3F8) = -1;
    *(s32 *)(p + 0x3FC) = -1;
    *(s8 *)(p + 0x424) = 0;
    *(s32 *)(p + 0x428) = -1;
    *(s8 *)(p + 0x42C) = 0;
    *(s32 *)(p + 0x430) = -1;
    *(s32 *)(p + 0x434) = -1;
    *(s8 *)(p + 0x45C) = 0;
    *(s32 *)(p + 0x460) = -1;
    *(s8 *)(p + 0x464) = 0;
    *(s32 *)(p + 0x468) = -1;
    *(s32 *)(p + 0x46C) = -1;
    *(s8 *)(p + 0x49C) = 0;
    *(s32 *)(p + 0x4A0) = -1;
    *(s8 *)(p + 0x4A4) = 0;
    *(s32 *)(p + 0x4A8) = -1;
    *(s32 *)(p + 0x4AC) = -1;
    *(s8 *)(p + 0x4DC) = 0;
    *(s32 *)(p + 0x4E0) = -1;
    *(s8 *)(p + 0x4E4) = 0;
    *(s32 *)(p + 0x4E8) = -1;
    *(s32 *)(p + 0x4EC) = -1;
    *(s8 *)(p + 0x515) = 0;
    *(s32 *)(p + 0x518) = -1;
    *(s8 *)(p + 0x51C) = 0;
    *(s32 *)(p + 0x520) = -1;
    *(s32 *)(p + 0x524) = -1;
    return arg0;
}
/* localdecomp:end func_L39_006CE930 */

/* localdecomp:start func_L39_006CEA18 */
typedef struct {
    u16 f00;
    char _p02[0x28 - 0x02];
    s32 f28;
    s32 f2C;
} Loc_006CEA18;
typedef struct {
    char _p0[0x30];
    s32 f30;
    char _p34[0x104 - 0x34];
    s32 f104;
    char _p108[0x190 - 0x108];
} Loc2_006CEA18;
typedef struct {
    char _p0[0x1];
    u8 f1;
    char _p2[0x8 - 0x2];
    s32 f8;
    char _pC[0x10 - 0xC];
    s32 f10;
    s32 f14;
    char _p18[0x1C - 0x18];
    u8 f1C;
    char _p1D[0x30 - 0x1D];
    s32 *f30;
    char _p34[0x44 - 0x34];
    void *f44;
    void *f48;
    char _p4C[0x50 - 0x4C];
    s32 f50;
} G_006CEA18;
typedef struct {
    s32 f0;
    char _p4[0x30 - 0x4];
    u8 f30[4];
    u8 f34;
    u8 f35;
    char _p36[0x38 - 0x36];
    s32 f38;
    char _p3C[0x5C - 0x3C];
    u8 f5C;
    char _p5D[0x60 - 0x5D];
    u32 f60;
} A_006CEA18;
typedef struct {
    char _p0[0x80];
    u8 f80[4];
    u8 f84;
    char _p85[0xA9 - 0x85];
    u8 fA9;
    char _pAA[0xAC - 0xAA];
    s32 fAC;
    char _pB0[0x2DC - 0xB0];
    s32 f2DC;
} P_006CEA18;
typedef struct {
    char _p0[0x40];
    s32 f40;
} R_006CEA18;

__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
void func_00120D28(s32, s32, s32);
void *func_001206F4(void *, void *);
long func_0012DCB0(void);
long func_00130760(long, long);
s32 func_0017D6F8(void *, void *, s32);
void func_001961E8(s32);
s32 func_001961F8(void);
void func_00195410(void);
void func_00196208(void);
s32 func_L39_006D8AD8(u8 *);
s32 func_L39_006D6E50(void *, s32, s32, void *);
void func_L39_006D6E30(void *, s32, void *);
s32 func_L39_006D2F18(void *, void *, void *);
void func_L39_006D2EF0(void *, s32, s32);
R_006CEA18 *func_L39_006D9328(void *, s32);
extern u8 D_00197830[];
extern u16 D_L39_00249C18[];
extern u8 D_001A5CD0[];

s32 func_L39_006CEA18(A_006CEA18 *a, s32 arg1) {
    Loc_006CEA18 loc;
    Loc2_006CEA18 loc2;
    s32 o1;
    s32 o2;
    G_006CEA18 *g;
    s32 r;
    void *name;

    g = (G_006CEA18 *)D_L39_0024D760;
    name = (void *)g->f50;
    loc.f00 = D_L39_00249C18[0];
    func_001206F4((u8 *)&loc + 0x15, name);
    loc.f28 = 1;
    loc.f2C = 1;
    a->f5C = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017D6F8(&loc, D_00197830, 0));
    while (a->f5C != 0) {
        if (func_001961F8() != 0 || ((P_006CEA18 *)D_001A5CD0)->f2DC != 0) {
            g->f10 = 0x14;
            if (g->f14 == 0) {
                g->f14 = 0x14;
            }
            r = 0;
            break;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if (func_L39_006D8AD8((u8 *)g) == 0) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    a->f5C = 0;
    if (a->f60 >= 2) {
        g->f10 = 0x14;
        if (g->f14 == 0) {
            g->f14 = 0x14;
        }
        r = 0;
    }
    if (r != 0) {
        s32 id;
        s32 key;

        func_00120D28((s32)((P_006CEA18 *)D_001A5CD0)->f80, (s32)a->f30, 4);
        ((P_006CEA18 *)D_001A5CD0)->f84 = 0;
        id = a->f0;
        key = *((G_006CEA18 *)D_L39_0024D760)->f30;
        if (((P_006CEA18 *)D_001A5CD0)->fAC != id || ((P_006CEA18 *)D_001A5CD0)->fA9 != a->f34 || arg1 != 0) {
            ((P_006CEA18 *)D_001A5CD0)->fAC = id;
            ((P_006CEA18 *)D_001A5CD0)->fA9 = a->f34;
            func_00196208();
            if (func_L39_006D6E50(((G_006CEA18 *)D_L39_0024D760)->f44, key, 0, &loc2) != 0) {
                loc2.f30 = id;
                loc2.f104 = id;
                func_L39_006D6E30(((G_006CEA18 *)D_L39_0024D760)->f44, 0, &loc2);
            }
        }
        if (a->f34 != 0) {
            a->f35 = 1;
            if (func_L39_006D2F18(a, &o1, &o2) == 0 && o1 >= 0) {
                func_L39_006D2EF0(a, -1, -1);
            }
        } else {
            R_006CEA18 *e = func_L39_006D9328(((G_006CEA18 *)D_L39_0024D760)->f48, a->f38);
            a->f35 = e != 0 && e->f40 != 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006CEA18 */

/* localdecomp:start func_L39_006CECA0 */
extern s32 func_00120048(u8 *, u8 *, ...);
extern u8 D_L39_00249BC8[];

void func_L39_006CECA0(u8 *arg0, s32 *arg1) {
    u32 i = 0;
    u8 *p = arg0;
    s32 *q = arg1;

    do {
        func_00120048(p, D_L39_00249BC8, *q);
        i++;
        q++;
        p += 8;
    } while (i < 3);
    *(u8 *)((u8 *)arg0 + i * 8) = 0;
}
/* localdecomp:end func_L39_006CECA0 */

/* localdecomp:start func_L39_006CED20 */
extern u8 D_L39_00249BC8[];
extern void func_001200E0(void *, void *, void *);

void func_L39_006CED20(u8 *arg0, s32 *arg1)
{
    u32 i = 0;
    s32 *q = arg1;
    u8 *p = arg0;

    do {
        func_001200E0(p, D_L39_00249BC8, q);
        i++;
        q++;
        p += 8;
    } while (i < 3);
}
/* localdecomp:end func_L39_006CED20 */

/* localdecomp:start func_L39_006CED88 */
typedef struct {
    s32 f0;
    u8 f4[0x24];
    s32 f28[3];
    u8 f34;
    u8 f35;
    u8 pad36[2];
    s32 f38;
    u8 f3C[0x20];
    u8 f5C;
    u8 pad5D[3];
    s32 f60;
} T_006CED88;
typedef struct {
    u8 pad0[0x30];
    s32 *f30;
    u8 pad34[4];
    T_006CED88 *f38;
} G_006CED88;
typedef struct {
    u8 pad0[0x38];
    s32 f38;
    u8 f3C[0x20];
    u8 f5C;
    u8 f5D;
    u8 pad5E[0x22];
    u8 f80;
    u8 pad81[0x28];
    u8 fA9;
    u8 padAA[2];
    s32 fAC;
} S_006CED88;
typedef struct {
    u8 pad0[0x18];
    s32 f18;
    s32 f1C;
    u8 pad20[4];
    u8 f24[0x20];
    s32 f44;
    u8 f48[0x20];
    s32 f68[3];
} A_006CED88;
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern u8 D_001A5CD0[];
extern u8 D_L39_00249C20[];
extern void *func_001206F4(void *, void *);
extern void func_0011D534(void *, s32, s32);
extern void func_00196208(void);
extern void func_L39_005958F8(s32, s32, s32);
extern void func_L39_006CED20(u8 *, s32 *);

void func_L39_006CED88(A_006CED88 *a) {
    G_006CED88 *g = (G_006CED88 *)D_L39_0024D760;
    T_006CED88 *t = g->f38;
    s32 *cur = g->f30;
    u8 buf[0x20];
    s32 on = a->f18;

    t->f60 = on;
    if (on != 0) {
        S_006CED88 *s = (S_006CED88 *)D_001A5CD0;
        s->f38 = -1;
        t->f0 = -1;
        func_001206F4(t->f4, D_L39_00249C20);
        func_001206F4(s->f3C, D_L39_00249C20);
        t->f34 = 0;
        s->f5D = 0;
        t->f35 = 0;
        func_0011D534(t->f28, 0, 0xC);
        t->f38 = -1;
        t->f3C[0] = D_L39_00249C20[0];
        s->fAC = -1;
        s->f80 = 0;
        s->fA9 = 0;
        func_00196208();
    } else {
        S_006CED88 *s = (S_006CED88 *)D_001A5CD0;
        s32 id = a->f1C;
        s->f38 = id;
        t->f0 = id;
        func_L39_005958F8((s32)buf, (s32)a->f24, 0x20);
        func_001206F4(t->f4, buf);
        func_001206F4(s->f3C, buf);
        if (a->f44 == *cur) {
            t->f34 = 1;
            s->f5D = 1;
        } else {
            t->f34 = 0;
            s->f5D = 0;
        }
        func_L39_006CED20((u8 *)a->f68, t->f28);
        t->f38 = a->f44;
        func_001206F4(t->f3C, a->f48);
    }
    t->f5C = 0;
}
/* localdecomp:end func_L39_006CED88 */

/* localdecomp:start func_L39_006CEEE0 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x13];
    s32 f28;
    u8 f2C[0x20];
} Loc_006CEEE0;
typedef struct {
    u8 pad0;
    u8 f1;
    u8 pad2[6];
    s32 f8;
    u8 padC[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
    u8 pad1D[0x33];
    void *f50;
} G_006CEEE0;
typedef struct {
    u8 pad0[0x64];
    u8 f64;
    u8 pad65[3];
    s32 f68;
} S_006CEEE0;
typedef struct {
    u8 pad0[0x2DC];
    s32 f2DC;
} D_006CEEE0;
extern u16 D_L39_00249C18[];
extern u8 D_00197790[];
extern void *func_001206F4(void *, void *);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_0017CD78(void *, u8 *, s32);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);
extern void func_00195410(void);
extern void func_L39_005958A0(s32, s32, s32);
extern s32 func_00183BDC(void);

s32 func_L39_006CEEE0(S_006CEEE0 *p, void *a) {
    G_006CEEE0 *g;
    Loc_006CEEE0 x;
    void *n;
    D_006CEEE0 *d;
    s32 r;

    g = D_L39_0024D760;
    n = g->f50;
    x.f0 = D_L39_00249C18[0];
    func_001206F4(x.f15, n);
    x.f28 = func_00183BDC();
    ((void (*)(void *, void *, s32))func_L39_005958A0)(x.f2C, a, 0x20);
    p->f64 = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017CD78(&x, D_00197790, 0));
    d = (D_006CEEE0 *)D_001A5CD0;
    while (p->f64) {
        if (func_001961F8() != 0 || d->f2DC != 0) {
            g->f10 = 0x15;
            if (g->f14 == 0) {
                g->f14 = 0x15;
            }
            r = 0;
            break;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if (!func_L39_006D8AD8((u8 *)g)) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    p->f64 = 0;
    if (r) {
        if (p->f68 == -0x3CA) {
            g->f10 = 0x18;
            if (g->f14 == 0) {
                g->f14 = 0x18;
            }
            r = 0;
        } else if (p->f68 == -0x3E0) {
            g->f10 = 0x24;
            if (g->f14 == 0) {
                g->f14 = 0x24;
            }
            r = 0;
        } else if (p->f68 != 0) {
            g->f10 = 0x15;
            if (g->f14 == 0) {
                g->f14 = 0x15;
            }
            r = 0;
        }
        if (r) {
            r = func_L39_006CEA18((A_006CEA18 *)p, 0);
        }
    }
    return r;
}
/* localdecomp:end func_L39_006CEEE0 */

/* localdecomp:start func_L39_006CF080 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { char pad[0x64]; char flag; char pad2[3]; int val; } T_006CF080;
typedef struct { char pad[0x38]; T_006CF080 *p; } S_006CF080;

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006CF080(char *arg0) {
    T_006CF080 *t = ((S_006CF080 *)D_L39_0024D760)->p;
    t->flag = 0;
    t->val = *(int *)(arg0 + 0x18);
}
/* localdecomp:end func_L39_006CF080 */

/* localdecomp:start func_L39_006CF0A0 */
typedef struct {
    s32 f0;
    u8 pad4[0x68];
    u8 f6C;
    u8 pad6D[3];
    s32 f70;
} S_006CF0A0;
typedef struct {
    u8 f0;
    u8 f1;
    u8 pad2[6];
    s32 f8;
    u8 padC[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
    u8 pad1D[0x33];
    void *f50;
} S_006CF0A0_G;
extern u16 D_L39_00249C18[];
extern u8 D_001977B8[];
typedef struct { u8 pad[0x2DC]; s32 f2DC; } S_006CF0A0_D;
extern u8 D_001A5CD0[];
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern s32 func_0017CDF8(void *, u8 *, s32);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);
extern void func_00195410(void);
extern s32 func_L39_006D8AD8(u8 *);
extern s32 func_L39_006CEA18(A_006CEA18 *, s32);

s32 func_L39_006CF0A0(S_006CF0A0 *arg0) {
    S_006CF0A0_G *g = (S_006CF0A0_G *)D_L39_0024D760;
    s32 r;
    struct { u16 x[1]; u8 pad2[0x13]; u8 buf[0x13]; s32 a; u8 pad3[4]; } l;

    void *name = g->f50;
    l.x[0] = D_L39_00249C18[0];
    func_001206F4(l.buf, name);
    l.a = arg0->f0;
    g->f1 = arg0->f6C = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017CDF8(&l, D_001977B8, 0));
    r = 1;
    while (arg0->f6C != 0) {
        if (func_001961F8() != 0 || ((S_006CF0A0_D *)D_001A5CD0)->f2DC != 0) {
            g->f10 = 0x16;
            if (g->f14 == 0) {
                g->f14 = 0x16;
            }
            r = 0;
            break;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if (func_L39_006D8AD8((u8 *)g) == 0) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    arg0->f6C = 0;
    if (r != 0) {
        s32 e = arg0->f70;
        s32 c;

        if (e == -0x3DE) {
            c = 0x23;
        } else if (e != 0) {
            c = 0x16;
        } else {
            goto done;
        }
        g->f10 = c;
        if (g->f14 == 0) {
            g->f14 = c;
        }
        r = 0;
    }
done:
    if (r != 0) {
        r = func_L39_006CEA18((A_006CEA18 *)arg0, 0);
    }
    return r;
}
/* localdecomp:end func_L39_006CF0A0 */

/* localdecomp:start func_L39_006CF218 */
typedef struct {
    u8 pad0[0x6C];
    s8 f6C;
    u8 pad1[3];
    s32 f70;
} S_6CF218_B;
typedef struct {
    u8 pad0[0x18];
    s32 f18;
} S_6CF218_C;
typedef struct {
    u8 pad0[0x38];
    S_6CF218_B *f38;
} S_6CF218_A;
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006CF218(S_6CF218_C *arg0) {
    S_6CF218_B *p = ((S_6CF218_A *)D_L39_0024D760)->f38;
    p->f6C = 0;
    p->f70 = arg0->f18;
}
/* localdecomp:end func_L39_006CF218 */

/* localdecomp:start func_L39_006CF238 */
typedef struct {
    u8 pad0[0x74];
    u8 f74;
    u8 pad75[3];
    s32 f78;
} T_006CF238;
typedef struct {
    u8 pad0;
    u8 f1;
    u8 pad2[6];
    s32 f8;
    u8 padC[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
    u8 pad1D[0x33];
    void *f50;
} G_006CF238;
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x13];
    s32 f28;
    u8 f2C[0x24];
} B_006CF238;
typedef struct {
    u8 pad0[0x2DC];
    s32 f2DC;
} P_006CF238;
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern u16 D_L39_00249C18[];
extern u8 D_001977E0[];
extern u8 D_001A5CD0[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern void func_L39_005958A0(s32, s32, s32);
extern s32 func_0017CF78(void *, u8 *, s32);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);
extern void func_00195410(void);
extern s32 func_L39_006D8AD8(u8 *);
extern s32 func_L39_006CEA18(A_006CEA18 *, s32);

s32 func_L39_006CF238(T_006CF238 *a0, s32 a1, void *a2) {
    s32 r;
    G_006CF238 *g;
    B_006CF238 buf;
    P_006CF238 *p;

    void *n;

    g = (G_006CF238 *)D_L39_0024D760;
    n = g->f50;
    buf.f0 = D_L39_00249C18[0];
    func_001206F4(buf.f15, n);
    buf.f28 = a1;
    func_L39_005958A0((s32)buf.f2C, (s32)a2, 0x20);
    a0->f74 = 1;
    g->f1 = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017CF78(&buf, D_001977E0, 0));
    p = (P_006CF238 *)D_001A5CD0;
    r = 1;
    while (a0->f74) {
        if (func_001961F8() != 0 || p->f2DC != 0) {
            g->f10 = 0x16;
            if (g->f14 == 0) {
                g->f14 = 0x16;
            }
            r = 0;
            break;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if (!func_L39_006D8AD8((u8 *)g)) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    a0->f74 = 0;
    if (r) {
        if (a0->f78 == -0x3DE) {
            g->f10 = 0x23;
            if (g->f14 == 0) {
                g->f14 = 0x23;
            }
            r = 0;
        } else if (a0->f78 != 0) {
            g->f10 = 0x17;
            if (g->f14 == 0) {
                g->f14 = 0x17;
            }
            r = 0;
        }
        if (r) {
            r = func_L39_006CEA18((A_006CEA18 *)a0, 0);
        }
    }
    return r;
}
/* localdecomp:end func_L39_006CF238 */

/* localdecomp:start func_L39_006CF3C8 */
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006CF3C8(void *arg0) {
    void *temp_v1;
    temp_v1 = (*(void **)((u8 *)D_L39_0024D760 + 0x38));
    (*(s8 *)((u8 *)(temp_v1) + 0x74)) = 0;
    (*(s32 *)((u8 *)(temp_v1) + 0x78)) = (s32) (*(s32 *)((u8 *)(arg0) + 0x18));
}
/* localdecomp:end func_L39_006CF3C8 */

/* localdecomp:start func_L39_006CF3E8 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x11];
    u8 f26[0xC8];
} Loc_006CF3E8;
typedef struct {
    u8 pad0;
    u8 f1;
    u8 pad2[6];
    s32 f8;
    u8 padC[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
    u8 pad1D[0x33];
    void *f50;
} G_006CF3E8;
typedef struct {
    u8 pad0[0x7C];
    u8 f7C;
    u8 pad7D[3];
    s32 f80;
    u8 pad84[0x3EC - 0x84];
    u8 f3EC;
    u8 pad3ED[7];
    u8 f3F4;
} S_006CF3E8;
typedef struct {
    u8 pad0[0x2DC];
    s32 f2DC;
} D_006CF3E8;
extern u16 D_L39_00249C18[];
extern u8 D_00197A10[];
extern void *func_001206F4(void *, void *);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_0017D378(void *, u8 *, s32);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);
extern void func_00195410(void);
extern void func_L39_005958A0(s32, s32, s32);
s32 func_L39_006D0DD0(u8 *);

s32 func_L39_006CF3E8(S_006CF3E8 *p, void *a) {
    G_006CF3E8 *g;
    Loc_006CF3E8 x;
    void *n;
    D_006CF3E8 *d;
    s32 r;

    g = D_L39_0024D760;
    n = g->f50;
    x.f0 = D_L39_00249C18[0];
    func_001206F4(x.f15, n);
    ((void (*)(void *, void *, s32))func_L39_005958A0)(x.f26, a, 0xC8);
    p->f7C = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017D378(&x, D_00197A10, 0));
    d = (D_006CF3E8 *)D_001A5CD0;
    while (p->f7C) {
        if (func_001961F8() != 0 || d->f2DC != 0) {
            g->f10 = 0x1D;
            if (g->f14 == 0) {
                g->f14 = 0x1D;
            }
            r = 0;
            break;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if (!func_L39_006D8AD8((u8 *)g)) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    p->f7C = 0;
    if (r) {
        if (p->f80 == -0x3DE) {
            g->f10 = 0x23;
            if (g->f14 == 0) {
                g->f14 = 0x23;
            }
            r = 0;
        } else if (p->f80 != 0) {
            g->f10 = 0x1D;
            if (g->f14 == 0) {
                g->f14 = 0x1D;
            }
            r = 0;
        }
        if (r && p->f3EC && !p->f3F4) {
            r = func_L39_006D0DD0((u8 *)p);
        }
    }
    return r;
}
/* localdecomp:end func_L39_006CF3E8 */

/* localdecomp:start func_L39_006CF588 */
typedef struct {
    u8 pad0[0x7c];
    s8 f7C;
    u8 pad1[0x80 - 0x7c - 1];
    s32 f80;
} S_006CF588_B;
typedef struct {
    u8 pad0[0x18];
    s32 f18;
} S_006CF588_C;
typedef struct {
    u8 pad0[0x38];
    S_006CF588_B *f38;
} S_006CF588_A;
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006CF588(S_006CF588_C *arg0) {
    S_006CF588_B *p = ((S_006CF588_A *)D_L39_0024D760)->f38;
    p->f7C = 0;
    p->f80 = arg0->f18;
}
/* localdecomp:end func_L39_006CF588 */

/* localdecomp:start func_L39_006CF5A8 */
typedef struct {
    u16 f00;
    char _p02[0x28 - 0x02];
    s32 f28;
    char _p2C[0xF4 - 0x2C];
} Loc_006CF5A8;
typedef struct {
    char _p0[0x1];
    u8 f1;
    char _p2[0x8 - 0x2];
    s32 f8;
    char _pC[0x10 - 0xC];
    s32 f10;
    s32 f14;
    char _p18[0x1C - 0x18];
    u8 f1C;
    char _p1D[0x50 - 0x1D];
    s32 f50;
} G_006CF5A8;
typedef struct {
    char _p0[0x84];
    u8 f84;
    char _p85[0x88 - 0x85];
    s32 f88;
    char _p8C[0x3EC - 0x8C];
    u8 f3EC;
    char _p3ED[0x3F4 - 0x3ED];
    u8 f3F4;
} S_006CF5A8;
typedef struct {
    char _p0[0x2DC];
    s32 f2DC;
} P_006CF5A8;

extern void func_L39_005958A0(s32, s32, s32);
s32 func_0017D3F8(void *, void *, s32);
s32 func_L39_006D0DD0(u8 *);
__asm__(".extern D_L39_0024D760, 16");
extern u8 D_00197AB0[];

/* same shape as func_L39_006DCAD0 */
s32 func_L39_006CF5A8(S_006CF5A8 *arg0, s32 arg1, void *arg2) {
    Loc_006CF5A8 loc;
    G_006CF5A8 *g;
    P_006CF5A8 *p;
    s32 r;
    s32 code;
    void *name;

    g = (G_006CF5A8 *)D_L39_0024D760;
    name = (void *)g->f50;
    loc.f00 = D_L39_00249C18[0];
    func_001206F4((u8 *)&loc + 0x15, name);
    loc.f28 = arg1;
    func_L39_005958A0((s32)((u8 *)&loc + 0x2C), (s32)arg2, 0xC8);
    arg0->f84 = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017D3F8(&loc, D_00197AB0, 0));
    p = (P_006CF5A8 *)D_001A5CD0;
    while (arg0->f84 != 0) {
        if (func_001961F8() != 0 || p->f2DC != 0) {
            g->f10 = 0x1E;
            if (g->f14 == 0) {
                g->f14 = 0x1E;
            }
            r = 0;
            break;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if (func_L39_006D8AD8((u8 *)g) == 0) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    arg0->f84 = 0;
    if (r != 0) {
        if (arg0->f88 == -0x3DE) {
            g->f10 = 0x23;
            if (g->f14 == 0) {
                g->f14 = 0x23;
            }
            r = 0;
        } else if (arg0->f88 != 0) {
            g->f10 = 0x1E;
            if (g->f14 == 0) {
                g->f14 = 0x1E;
            }
            r = 0;
        }
    }
    if (r != 0 && arg0->f3EC != 0 && arg0->f3F4 == 0) {
        r = func_L39_006D0DD0((u8 *)arg0);
    }
    return r;
}
/* localdecomp:end func_L39_006CF5A8 */

/* localdecomp:start func_L39_006CF750 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { char pad[0x84]; char flag; char pad2[3]; int val; } T_006CF750;
typedef struct { char pad[0x38]; T_006CF750 *p; } S_006CF750;

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006CF750(char *arg0) {
    T_006CF750 *t = ((S_006CF750 *)D_L39_0024D760)->p;
    t->flag = 0;
    t->val = *(int *)(arg0 + 0x18);
}
/* localdecomp:end func_L39_006CF750 */

/* localdecomp:start func_L39_006CF770 */
typedef struct {
    u8 pad0[0x8C];
    u8 f8C;
    u8 pad8D[3];
    s32 f90;
    u8 pad94[0x358];
    u8 f3EC;
    u8 pad3ED[7];
    u8 f3F4;
} T_006CF770;
typedef struct {
    u8 pad0;
    u8 f1;
    u8 pad2[6];
    s32 f8;
    u8 padC[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
    u8 pad1D[0x33];
    void *f50;
} G_006CF770;
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x13];
    s32 f28;
    u8 pad2C[4];
} B_006CF770;
typedef struct {
    u8 pad0[0x2DC];
    s32 f2DC;
} P_006CF770;
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern u16 D_L39_00249C18[];
extern u8 D_00197AD8[];
extern u8 D_001A5CD0[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern s32 func_0017D478(void *, u8 *, s32);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);
extern void func_00195410(void);
extern s32 func_L39_006D8AD8(u8 *);
extern s32 func_L39_006D0DD0(u8 *);

s32 func_L39_006CF770(T_006CF770 *a0, s32 a1) {
    s32 r;
    G_006CF770 *g;
    B_006CF770 buf;
    P_006CF770 *p;
    void *n;

    g = (G_006CF770 *)D_L39_0024D760;
    n = g->f50;
    buf.f0 = D_L39_00249C18[0];
    func_001206F4(buf.f15, n);
    buf.f28 = a1;
    a0->f8C = 1;
    g->f1 = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017D478(&buf, D_00197AD8, 0));
    p = (P_006CF770 *)D_001A5CD0;
    r = 1;
    while (a0->f8C) {
        if (func_001961F8() != 0 || p->f2DC != 0) {
            g->f10 = 0x1F;
            if (g->f14 == 0) {
                g->f14 = 0x1F;
            }
            r = 0;
            break;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if (!func_L39_006D8AD8((u8 *)g)) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    a0->f8C = 0;
    if (r) {
        if (a0->f90 == -0x3DE) {
            g->f10 = 0x23;
            if (g->f14 == 0) {
                g->f14 = 0x23;
            }
            r = 0;
        } else if (a0->f90 != 0) {
            g->f10 = 0x1F;
            if (g->f14 == 0) {
                g->f14 = 0x1F;
            }
            r = 0;
        }
        if (r && a0->f3EC != 0 && a0->f3F4 == 0) {
            r = func_L39_006D0DD0((u8 *)a0);
        }
    }
    return r;
}
/* localdecomp:end func_L39_006CF770 */

/* localdecomp:start func_L39_006CF900 */
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006CF900(void *arg0) {
    void *temp_v1;
    temp_v1 = (*(void **)((u8 *)D_L39_0024D760 + 0x38));
    (*(s8 *)((u8 *)(temp_v1) + 0x8c)) = 0;
    (*(s32 *)((u8 *)(temp_v1) + 0x90)) = (s32) (*(s32 *)((u8 *)(arg0) + 0x18));
}
/* localdecomp:end func_L39_006CF900 */

/* localdecomp:start func_L39_006CF920 */
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x13];
    s32 f28;
    u8 f2C[0xD0];
} L_006CF920;
typedef struct {
    u8 pad0[0x94];
    u8 f94;
    u8 pad95[3];
    s32 f98;
    u8 pad9C[0x438];
    u8 f4D4;
    u8 pad4D5[3];
    s32 f4D8;
    u8 f4DC;
    u8 pad4DD[7];
    u8 f4E4;
} S_006CF920;
typedef struct {
    u8 pad0;
    u8 f1;
    u8 pad2[6];
    s32 f8;
    u8 padC[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
    u8 pad1D[0x33];
    void *f50;
} G_006CF920;
typedef struct { u8 pad[0x2DC]; s32 f2DC; } D_006CF920;
extern u16 D_L39_00249C18[];
extern u8 D_00197A38[];
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern void func_L39_005958A0(s32, s32, s32);
extern s32 func_0017D4F8(void *, u8 *, s32);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);
extern void func_00195410(void);
extern s32 func_L39_006D8AD8(u8 *);
extern s32 func_L39_006D2500(void *, s32, s32);

s32 func_L39_006CF920(S_006CF920 *arg0, s32 arg1, s32 arg2) {
    G_006CF920 *g = (G_006CF920 *)D_L39_0024D760;
    s32 r;
    L_006CF920 l;

    void *n = g->f50;

    l.f0 = D_L39_00249C18[0];
    func_001206F4(l.f15, n);
    l.f28 = arg1;
    func_L39_005958A0((s32)l.f2C, arg2, 200);
    g->f1 = arg0->f94 = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017D4F8(&l, D_00197A38, 0));
    r = 1;
    while (arg0->f94 != 0) {
        if (func_001961F8() != 0 || ((D_006CF920 *)D_001A5CD0)->f2DC != 0) {
            g->f10 = 0x20;
            if (g->f14 == 0) {
                g->f14 = 0x20;
            }
            r = 0;
            break;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if (func_L39_006D8AD8((u8 *)g) == 0) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    arg0->f94 = 0;
    if (r != 0) {
        if (arg0->f98 == -0x3DE) {
            g->f10 = 0x23;
            if (g->f14 == 0) {
                g->f14 = 0x23;
            }
            r = 0;
        } else if (arg0->f98 != 0) {
            g->f10 = 0x20;
            if (g->f14 == 0) {
                g->f14 = 0x20;
            }
            r = 0;
        }
    }
    if (r != 0 && arg0->f4DC != 0 && arg0->f4E4 == 0) {
        r = func_L39_006D2500(arg0, arg0->f4D4, arg0->f4D8);
    }
    return r;
}
/* localdecomp:end func_L39_006CF920 */

/* localdecomp:start func_L39_006CFAD0 */
typedef struct {
    u8 pad0[0x94];
    s8 f94;
    u8 pad1[3];
    s32 f98;
} S_6CFAD0_B;
typedef struct {
    u8 pad0[0x18];
    s32 f18;
} S_6CFAD0_C;
typedef struct {
    u8 pad0[0x38];
    S_6CFAD0_B *f38;
} S_6CFAD0_A;
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006CFAD0(S_6CFAD0_C *arg0) {
    S_6CFAD0_B *p = ((S_6CFAD0_A *)D_L39_0024D760)->f38;
    p->f94 = 0;
    p->f98 = arg0->f18;
}
/* localdecomp:end func_L39_006CFAD0 */

/* localdecomp:start func_L39_006CFAF0 */
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x13];
    s32 f28;
    s32 f2C;
    u8 f30[0xCC];
} L_006CFAF0;
typedef struct {
    u8 pad0[0x9C];
    u8 f9C;
    u8 pad9D[3];
    s32 fA0;
    u8 padA4[0x430];
    u8 f4D4;
    u8 pad4D5[3];
    s32 f4D8;
    u8 f4DC;
    u8 pad4DD[7];
    u8 f4E4;
} S_006CFAF0;
typedef struct {
    u8 pad0;
    u8 f1;
    u8 pad2[6];
    s32 f8;
    u8 padC[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
    u8 pad1D[0x33];
    void *f50;
} G_006CFAF0;
typedef struct { u8 pad[0x2DC]; s32 f2DC; } D_006CFAF0;
extern u16 D_L39_00249C18[];
extern u8 D_00197A88[];
extern u8 D_001A5CD0[];
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern void func_L39_005958A0(s32, s32, s32);
extern s32 func_0017D578(void *, u8 *, s32);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);
extern void func_00195410(void);
extern s32 func_L39_006D8AD8(u8 *);
/* defined in L39_006D08E8.c (S_006D2500 *); declared here as func_L39_006CFCD0 and L39_006D05A0.c do, with the return value */
extern s32 func_L39_006D2500(void *, s32, s32);

s32 func_L39_006CFAF0(S_006CFAF0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    G_006CFAF0 *g = (G_006CFAF0 *)D_L39_0024D760;
    s32 r;
    L_006CFAF0 l;

    void *n = g->f50;

    l.f0 = D_L39_00249C18[0];
    func_001206F4(l.f15, n);
    l.f28 = arg1;
    l.f2C = arg2;
    func_L39_005958A0((s32)l.f30, arg3, 200);
    g->f1 = arg0->f9C = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017D578(&l, D_00197A88, 0));
    r = 1;
    while (arg0->f9C != 0) {
        if (func_001961F8() != 0 || ((D_006CFAF0 *)D_001A5CD0)->f2DC != 0) {
            g->f10 = 0x21;
            if (g->f14 == 0) {
                g->f14 = 0x21;
            }
            r = 0;
            break;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if (func_L39_006D8AD8((u8 *)g) == 0) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    arg0->f9C = 0;
    if (r != 0) {
        if (arg0->fA0 == -0x3DE) {
            r = 0;
        } else if (arg0->fA0 != 0) {
            g->f10 = 0x19;
            if (g->f14 == 0) {
                g->f14 = 0x19;
            }
            r = 0;
        }
    }
    if (r != 0 && arg0->f4DC != 0 && arg0->f4E4 == 0) {
        r = func_L39_006D2500(arg0, arg0->f4D4, arg0->f4D8);
    }
    return r;
}
/* localdecomp:end func_L39_006CFAF0 */

/* localdecomp:start func_L39_006CFCB0 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { char pad[0x9c]; char flag; char pad2[3]; int val; } T_006CFCB0;
typedef struct { char pad[0x38]; T_006CFCB0 *p; } S_006CFCB0;

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006CFCB0(char *arg0) {
    T_006CFCB0 *t = ((S_006CFCB0 *)D_L39_0024D760)->p;
    t->flag = 0;
    t->val = *(int *)(arg0 + 0x18);
}
/* localdecomp:end func_L39_006CFCB0 */

/* localdecomp:start func_L39_006CFCD0 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x13];
    s32 f28;
} Loc_006CFCD0;
typedef struct {
    u8 pad0;
    u8 f1;
    u8 pad2[6];
    s32 f8;
    u8 padC[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
    u8 pad1D[0x33];
    void *f50;
} G_006CFCD0;
typedef struct {
    u8 pad0[0xA4];
    u8 fA4;
    u8 padA5[3];
    s32 fA8;
    u8 padAC[0x4D4 - 0xAC];
    u8 f4D4;
    u8 pad4D5[3];
    s32 f4D8;
    u8 f4DC;
    u8 pad4DD[7];
    u8 f4E4;
} S_006CFCD0;
typedef struct {
    u8 pad0[0x2DC];
    s32 f2DC;
} D_006CFCD0;
extern u16 D_L39_00249C18[];
extern u8 D_00197A60[];
extern void *func_001206F4(void *, void *);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_0017D5F8(void *, u8 *, s32);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);
extern void func_00195410(void);
extern s32 func_L39_006D8AD8(u8 *);
extern s32 func_L39_006D2500(void *, s32, s32);

s32 func_L39_006CFCD0(S_006CFCD0 *p, s32 a) {
    G_006CFCD0 *g;
    Loc_006CFCD0 x;
    void *n;
    D_006CFCD0 *d;
    s32 r;

    g = D_L39_0024D760;
    n = g->f50;
    x.f0 = D_L39_00249C18[0];
    func_001206F4(x.f15, n);
    x.f28 = a;
    p->fA4 = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017D5F8(&x, D_00197A60, 0));
    d = (D_006CFCD0 *)D_001A5CD0;
    while (p->fA4) {
        if (func_001961F8() != 0 || d->f2DC != 0) {
            g->f10 = 0x22;
            if (g->f14 == 0) {
                g->f14 = 0x22;
            }
            r = 0;
            break;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if (!func_L39_006D8AD8((u8 *)g)) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    p->fA4 = 0;
    if (r) {
        if (p->fA8 == -0x3DE) {
            g->f10 = 0x23;
            if (g->f14 == 0) {
                g->f14 = 0x23;
            }
            r = 0;
        } else if (p->fA8 != 0) {
            g->f10 = 0x22;
            if (g->f14 == 0) {
                g->f14 = 0x22;
            }
            r = 0;
        }
        if (r && p->f4DC && !p->f4E4) {
            r = func_L39_006D2500(p, p->f4D4, p->f4D8);
        }
    }
    return r;
}
/* localdecomp:end func_L39_006CFCD0 */

/* localdecomp:start func_L39_006CFE68 */
typedef struct {
    u8 pad0[0xa4];
    s8 fA4;
    u8 pad1[0xa8 - 0xa4 - 1];
    s32 fA8;
} S_006CFE68_B;
typedef struct {
    u8 pad0[0x18];
    s32 f18;
} S_006CFE68_C;
typedef struct {
    u8 pad0[0x38];
    S_006CFE68_B *f38;
} S_006CFE68_A;
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006CFE68(S_006CFE68_C *arg0) {
    S_006CFE68_B *p = ((S_006CFE68_A *)D_L39_0024D760)->f38;
    p->fA4 = 0;
    p->fA8 = arg0->f18;
}
/* localdecomp:end func_L39_006CFE68 */

/* localdecomp:start func_L39_006CFE88 */
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006CFE88(void *arg0) {
    void *temp_v1;
    temp_v1 = (*(void **)((u8 *)D_L39_0024D760 + 0x38));
    (*(s8 *)((u8 *)(temp_v1) + 0xac)) = 0;
    (*(s32 *)((u8 *)(temp_v1) + 0xb0)) = (s32) (*(s32 *)((u8 *)(arg0) + 0x18));
}
/* localdecomp:end func_L39_006CFE88 */

/* localdecomp:start func_L39_006CFEA8 */
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x13];
    s32 f28;
    u8 f2C[0xD0];
} L_006CFEA8;
typedef struct {
    u8 pad0[0xB4];
    u8 fB4;
    u8 padB5[3];
    s32 fB8;
    u8 padBC[0x368];
    u8 f424;
    u8 pad425[7];
    u8 f42C;
} S_006CFEA8;
typedef struct {
    u8 pad0;
    u8 f1;
    u8 pad2[6];
    s32 f8;
    u8 padC[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
    u8 pad1D[0x33];
    void *f50;
} G_006CFEA8;
typedef struct { u8 pad[0x2DC]; s32 f2DC; } D_006CFEA8;
extern u16 D_L39_00249C18[];
extern u8 D_00197970[];
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern void func_L39_005958A0(s32, s32, s32);
extern s32 func_0017D078(void *, u8 *, s32);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);
extern void func_00195410(void);
extern s32 func_L39_006D8AD8(u8 *);

s32 func_L39_006CFEA8(S_006CFEA8 *arg0, s32 arg1, s32 arg2) {
    G_006CFEA8 *g = (G_006CFEA8 *)D_L39_0024D760;
    s32 r;
    L_006CFEA8 l;

    void *n = g->f50;

    l.f0 = D_L39_00249C18[0];
    func_001206F4(l.f15, n);
    l.f28 = arg1;
    func_L39_005958A0((s32)l.f2C, arg2, 200);
    g->f1 = arg0->fB4 = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017D078(&l, D_00197970, 0));
    r = 1;
    while (arg0->fB4 != 0) {
        if (func_001961F8() != 0 || ((D_006CFEA8 *)D_001A5CD0)->f2DC != 0) {
            g->f10 = 0x19;
            if (g->f14 == 0) {
                g->f14 = 0x19;
            }
            r = 0;
            break;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if (func_L39_006D8AD8((u8 *)g) == 0) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    arg0->fB4 = 0;
    if (r != 0) {
        if (arg0->fB8 == -0x3DE) {
            r = 0;
        } else if (arg0->fB8 == -0x3E6) {
            g->f10 = 0xF;
            if (g->f14 == 0) {
                g->f14 = 0xF;
            }
            r = 0;
        } else if (arg0->fB8 != 0) {
            g->f10 = 0x19;
            if (g->f14 == 0) {
                g->f14 = 0x19;
            }
            r = 0;
        }
    }
    if (r != 0 && arg0->f424 != 0 && arg0->f42C == 0) {
        r = func_L39_006D1658((u8 *)arg0);
    }
    return r;
}
/* localdecomp:end func_L39_006CFEA8 */

/* localdecomp:start func_L39_006D0058 */
typedef struct {
    u8 pad0[0xB4];
    s8 fB4;
    u8 pad1[3];
    s32 fB8;
} S_6D0058_B;
typedef struct {
    u8 pad0[0x18];
    s32 f18;
} S_6D0058_C;
typedef struct {
    u8 pad0[0x38];
    S_6D0058_B *f38;
} S_6D0058_A;
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006D0058(S_6D0058_C *arg0) {
    S_6D0058_B *p = ((S_6D0058_A *)D_L39_0024D760)->f38;
    p->fB4 = 0;
    p->fB8 = arg0->f18;
}
/* localdecomp:end func_L39_006D0058 */

/* localdecomp:start func_L39_006D0078 */
typedef struct {
    u8 pad0[0xC4];
    u8 fC4;
    u8 padC5[3];
    s32 fC8;
    u8 padCC[0x358];
    u8 f424;
    u8 pad425[7];
    u8 f42C;
} T_006D0078;
typedef struct {
    u8 pad0;
    u8 f1;
    u8 pad2[6];
    s32 f8;
    u8 padC[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
    u8 pad1D[0x33];
    void *f50;
} G_006D0078;
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x13];
    s32 f28;
    u8 pad2C[4];
} B_006D0078;
typedef struct {
    u8 pad0[0x2DC];
    s32 f2DC;
} P_006D0078;
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern u16 D_L39_00249C18[];
extern u8 D_001979C0[];
extern u8 D_001A5CD0[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern s32 func_0017D278(void *, u8 *, s32);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);
extern void func_00195410(void);
extern s32 func_L39_006D8AD8(u8 *);
extern s32 func_L39_006D1658(u8 *);


s32 func_L39_006D0078(T_006D0078 *a0, s32 a1) {
    s32 r;
    G_006D0078 *g;
    B_006D0078 buf;
    P_006D0078 *p;
    void *n;

    g = (G_006D0078 *)D_L39_0024D760;
    n = g->f50;
    buf.f0 = D_L39_00249C18[0];
    func_001206F4(buf.f15, n);
    buf.f28 = a1;
    a0->fC4 = 1;
    g->f1 = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017D278(&buf, D_001979C0, 0));
    p = (P_006D0078 *)D_001A5CD0;
    r = 1;
    while (a0->fC4) {
        if (func_001961F8() != 0 || p->f2DC != 0) {
            g->f10 = 0x1A;
            if (g->f14 == 0) {
                g->f14 = 0x1A;
            }
            r = 0;
            break;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if (!func_L39_006D8AD8((u8 *)g)) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    a0->fC4 = 0;
    if (r) {
        if (a0->fC8 == -0x3DE) {
            g->f10 = 0x23;
            if (g->f14 == 0) {
                g->f14 = 0x23;
            }
            r = 0;
        } else if (a0->fC8 != 0) {
            g->f10 = 0x1A;
            if (g->f14 == 0) {
                g->f14 = 0x1A;
            }
            r = 0;
        }
        if (r && a0->f424 != 0 && a0->f42C == 0) {
            r = func_L39_006D1658((u8 *)a0);
        }
    }
    return r;
}
/* localdecomp:end func_L39_006D0078 */

/* localdecomp:start func_L39_006D0208 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { char pad[0xc4]; char flag; char pad2[3]; int val; } T_006D0208;
typedef struct { char pad[0x38]; T_006D0208 *p; } S_006D0208;

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006D0208(char *arg0) {
    T_006D0208 *t = ((S_006D0208 *)D_L39_0024D760)->p;
    t->flag = 0;
    t->val = *(int *)(arg0 + 0x18);
}
/* localdecomp:end func_L39_006D0208 */

/* localdecomp:start func_L39_006D0228 */
typedef struct {
    s32 f0;
    u8 pad4[0xC8];
    u8 fCC;
    u8 padCD[3];
    s32 fD0;
} S_006D0228;
typedef struct {
    u8 f0;
    u8 f1;
    u8 pad2[6];
    s32 f8;
    u8 padC[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
    u8 pad1D[0x33];
    void *f50;
} S_006D0228_G;
extern u16 D_L39_00249C18[];
extern u8 D_001979E8[];
typedef struct { u8 pad[0x2DC]; s32 f2DC; } S_006D0228_D;
extern u8 D_001A5CD0[];
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern s32 func_0017CFF8(void *, u8 *, s32);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);
extern void func_00195410(void);
extern s32 func_L39_006D8AD8(u8 *);

s32 func_L39_006D0228(S_006D0228 *arg0, s32 arg1) {
    S_006D0228_G *g = (S_006D0228_G *)D_L39_0024D760;
    s32 r;
    struct { u16 x[1]; u8 pad2[0x13]; u8 buf[0x13]; s32 a; s32 b; } l;

    void *name = g->f50;
    l.x[0] = D_L39_00249C18[0];
    func_001206F4(l.buf, name);
    l.a = arg1;
    l.b = arg0->f0;
    g->f1 = arg0->fCC = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017CFF8(&l, D_001979E8, 0));
    r = 1;
    while (arg0->fCC != 0) {
        if (func_001961F8() != 0 || ((S_006D0228_D *)D_001A5CD0)->f2DC != 0) {
            g->f10 = 0x1C;
            if (g->f14 == 0) {
                g->f14 = 0x1C;
            }
            r = 0;
            break;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if (func_L39_006D8AD8((u8 *)g) == 0) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    arg0->fCC = 0;
    if (r != 0) {
        s32 e = arg0->fD0;
        s32 c;

        if (e == -0x3DE) {
            c = 0x23;
        } else if (e != 0) {
            c = 0x1C;
        } else {
            return r;
        }
        g->f10 = c;
        if (g->f14 == 0) {
            g->f14 = c;
        }
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L39_006D0228 */

/* localdecomp:start func_L39_006D0398 */
typedef struct {
    u8 pad0[0xcc];
    s8 fCC;
    u8 pad1[0xd0 - 0xcc - 1];
    s32 fD0;
} S_006D0398_B;
typedef struct {
    u8 pad0[0x18];
    s32 f18;
} S_006D0398_C;
typedef struct {
    u8 pad0[0x38];
    S_006D0398_B *f38;
} S_006D0398_A;
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006D0398(S_006D0398_C *arg0) {
    S_006D0398_B *p = ((S_006D0398_A *)D_L39_0024D760)->f38;
    p->fCC = 0;
    p->fD0 = arg0->f18;
}
/* localdecomp:end func_L39_006D0398 */

/* localdecomp:start func_L39_006D03B8 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x13];
    s32 f28;
    s32 f2C;
    u8 f30[0xC8];
} Loc_006D03B8;
typedef struct {
    u8 pad0;
    u8 f1;
    u8 pad2[6];
    s32 f8;
    u8 padC[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
    u8 pad1D[0x33];
    void *f50;
} G_006D03B8;
typedef struct {
    u8 pad0[0xBC];
    u8 fBC;
    u8 padBD[3];
    s32 fC0;
} S_006D03B8;
typedef struct {
    u8 pad0[0x2DC];
    s32 f2DC;
} D_006D03B8;
extern u16 D_L39_00249C18[];
extern u8 D_00197998[];
extern void *func_001206F4(void *, void *);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_0017D1F8(void *, u8 *, s32);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);
extern void func_00195410(void);
extern s32 func_L39_006D8AD8(u8 *);
extern s32 func_L39_006CEA18(A_006CEA18 *, s32);
extern void func_L39_005958A0(s32, s32, s32);

s32 func_L39_006D03B8(S_006D03B8 *p, s32 a, s32 b, void *c) {
    G_006D03B8 *g;
    Loc_006D03B8 x;
    void *n;
    D_006D03B8 *d;
    s32 r;

    g = D_L39_0024D760;
    n = g->f50;

    x.f0 = D_L39_00249C18[0];
    func_001206F4(x.f15, n);
    x.f28 = a;
    x.f2C = b;
    ((void (*)(void *, void *, s32))func_L39_005958A0)(x.f30, c, 0xC8);
    p->fBC = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017D1F8(&x, D_00197998, 0));
    d = (D_006D03B8 *)D_001A5CD0;
    while (p->fBC) {
        if (func_001961F8() != 0 || d->f2DC != 0) {
            g->f10 = 0x1B;
            if (g->f14 == 0) {
                g->f14 = 0x1B;
            }
            r = 0;
            break;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if (!func_L39_006D8AD8((u8 *)g)) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    p->fBC = 0;
    if (r) {
        if (p->fC0) {
            g->f10 = 0x19;
            if (g->f14 == 0) {
                g->f14 = 0x19;
            }
            r = 0;
        }
        if (r) {
            r = func_L39_006CEA18((A_006CEA18 *)p, 0);
        }
    }
    return r;
}
/* localdecomp:end func_L39_006D03B8 */

/* localdecomp:start func_L39_006D0550 */
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006D0550(void *arg0) {
    void *temp_v1;
    temp_v1 = (*(void **)((u8 *)D_L39_0024D760 + 0x38));
    (*(s8 *)((u8 *)(temp_v1) + 0xbc)) = 0;
    (*(s32 *)((u8 *)(temp_v1) + 0xc0)) = (s32) (*(s32 *)((u8 *)(arg0) + 0x18));
}
/* localdecomp:end func_L39_006D0550 */
