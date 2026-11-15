#include "common.h"

typedef struct S_006CD768 {
    u8 f0;
    u8 pad1[7];
    u8 f8;
    u8 pad9[3];
    s32 fC;
} S_006CD768;

/* declared by functions of L39_006CCE90.c, which this file was cut from */
extern void *D_L39_0024D760;
extern u8 D_001A5CD0[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);
void func_00120D28(s32, s32, s32);
void *func_001206F4(void *, void *);
long func_0012DCB0(void);
long func_00130760(long, long);
void func_001961E8(s32);
s32 func_001961F8(void);
void func_00195410(void);
s32 func_L39_006D8AD8(u8 *);
void func_L39_006D2EF0(void *, s32, s32);
extern u16 D_L39_00249C18[];
extern void *func_001206F4(void *, void *);

/* declared by functions of L39_006D08E8.c, which this file was cut from */
void func_001961E8(s32);
s32 func_001961F8(void);
extern void *func_001206F4(void *, void *);
extern void *D_L39_0024D760;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);
extern void func_L39_005958A0(s32, s32, s32);
extern void func_00195410(void);
extern u8 D_001A5CD0[];
extern s32 func_L39_006D8AD8(u8 *);

/* localdecomp:start func_L39_006D4018 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct {
    char _p0[0x3C];
    s8 *f3C;
} S_6D4018;

/* from rac4-decomp's func_L00_0076F1E0 */
void func_L39_006D4018(void) {
    ((S_6D4018 *)D_L39_0024D760)->f3C[1] = 0;
}
/* localdecomp:end func_L39_006D4018 */

/* localdecomp:start func_L39_006D4030 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct {
    char _p0[0x10];
    s32 f10;
    s32 f14;
    char _p18[0x24];
    s8 *f3C;
} S_006D4030;
typedef struct {
    char _p0[0x18];
    s32 f18;
    s32 f1C;
} A_006D4030;
void func_0019B5B8(s32);
void func_0019B798(s32);

void func_L39_006D4030(A_006D4030 *arg) {
    S_006D4030 *g = (S_006D4030 *)D_L39_0024D760;
    s8 *p = g->f3C;
    s32 k = arg->f18;

    if (k != 0) {
        switch (k) {
        case -0x3CF:
            g->f10 = 0x2B;
            if (g->f14 == 0) {
                g->f14 = 0x2B;
            }
            break;
        case -0x3C7:
            g->f10 = 3;
            if (g->f14 == 0) {
                g->f14 = 3;
            }
            break;
        default:
            g->f10 = 0x2A;
            if (g->f14 == 0) {
                g->f14 = 0x2A;
            }
            break;
        }
    } else {
        func_0019B5B8(arg->f1C);
        func_0019B798(1);
    }
    p[1] = 0;
}
/* localdecomp:end func_L39_006D4030 */

/* localdecomp:start func_L39_006D40B0 */
typedef struct S_6D40B0_G {
    u8 pad0[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0x38];
    void *f50;
} S_6D40B0_G;
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern void *func_001206F4(void *, void *);
extern void func_00196038(void);
extern void func_0019B798(s32);
extern void func_0019B5B8(s32);
extern s32 func_0017E310(void *);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);

s32 func_L39_006D40B0(void) {
    S_6D40B0_G *g = (S_6D40B0_G *)D_L39_0024D760;
    void *name = g->f50;
    s32 r = 1;
    struct { u8 pad[0x14]; s32 mode; } l;

    func_00196038();
    func_0019B798(0);
    func_0019B5B8(-1);
    func_001206F4(&l, name);
    l.mode = 2;
    func_001961E8(func_0017E310(&l));
    if (func_001961F8() != 0) {
        g->f10 = 4;
        if (g->f14 == 0) {
            g->f14 = 4;
        }
        r = 0;
    }
    l.mode = 1;
    func_001961E8(func_0017E310(&l));
    if (func_001961F8() != 0) {
        g->f10 = 4;
        if (g->f14 == 0) {
            g->f14 = 4;
        }
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L39_006D40B0 */

/* localdecomp:start func_L39_006D4188 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x13];
    s32 f28;
    u8 pad2C[4];
} S_006D4188;
typedef struct {
    u8 pad0;
    u8 f1;
    u8 pad2[6];
    s32 f8;
    u8 padC[4];
    s32 f10;
    s32 f14;
    u8 pad18[0x38];
    void *f50;
} G_006D4188;
extern u16 D_L39_00249C78[];
extern u8 D_00197BF0[];
extern void *func_001206F4(void *, void *);
s32 func_0019B5C8(void);
extern s32 func_0017EAB8(void *, u8 *, s32);

s32 func_L39_006D4188(u8 *arg0) {
    G_006D4188 *g;
    s32 r = 1;
    S_006D4188 x;

    x.f0 = D_L39_00249C78[0];
    g = (G_006D4188 *)D_L39_0024D760;
    func_001206F4(x.f15, g->f50);
    x.f28 = func_0019B5C8();
    arg0[3] = 1;
    *(s32 *)(arg0 + 0xC) = (s32) func_00130760(func_0012DCB0(), 0x24000);
    g->f1 = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017EAB8(&x, D_00197BF0, 0));
    if (func_001961F8() != 0) {
        g->f10 = 0x2E;
        if (g->f14 == 0) {
            g->f14 = 0x2E;
        }
        r = 0;
    }
    g->f1 = 0;
    return r;
}
/* localdecomp:end func_L39_006D4188 */

/* localdecomp:start func_L39_006D4278 */
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
typedef struct { s32 w[0x18C / 4]; } S_006D4278_blk;
typedef struct {
    u8 pad0[2];
    u8 b2;
    u8 b3;
    u8 pad4[8];
    s32 wC;
    u8 pad10[0xE4 - 0x10];
    S_006D4278_blk blk;
} S_006D4278_t;
typedef struct { u8 pad[0x3C]; S_006D4278_t *f3C; } S_006D4278_g;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);

void func_L39_006D4278(S_006D4278_blk *arg)
{
    S_006D4278_t *t = ((S_006D4278_g *)D_L39_0024D760)->f3C;
    t->b3 = 0;
    t->blk = *arg;
    t->wC = (s32)func_00130760(func_0012DCB0(), 0x24000);
    t->b2 = 1;
}
/* localdecomp:end func_L39_006D4278 */

/* localdecomp:start func_L39_006D4380 */
typedef struct {
    u8 pad0[2];
    u8 f2;
    u8 pad3[0xD];
    u8 f10;
    u8 pad11[0x25F];
    u8 f270[0x18];
    s32 f288;
} S_006D4380;
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
} S_006D4380_G;
extern u16 D_L39_00249C78[];
extern u8 D_00197B00[];
typedef struct { u8 pad[0x2DC]; s32 f2DC; } S_006D4380_D;
extern u8 D_001A5CD0[];
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern s32 func_0017EAB8(void *, u8 *, s32);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);
extern void func_00195410(void);

u8 *func_L39_006D4380(S_006D4380 *arg0, s32 arg1) {
    S_006D4380_G *g = (S_006D4380_G *)D_L39_0024D760;
    s32 r;
    struct { u16 x[1]; u8 pad2[0x13]; u8 buf[0x13]; s32 a; u8 pad3[0x4]; } l;

    arg0->f2 = 0;
    l.x[0] = D_L39_00249C78[0];
    func_001206F4(l.buf, g->f50);
    l.a = arg1;
    g->f1 = arg0->f10 = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017EAB8(&l, D_00197B00, 0));
    r = 1;
    while (arg0->f10 != 0) {
        if (func_001961F8() != 0 || ((S_006D4380_D *)D_001A5CD0)->f2DC != 0) {
            g->f10 = 0x2E;
            if (g->f14 == 0) {
                g->f14 = 0x2E;
            }
            r = 0;
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
    arg0->f10 = 0;
    if (r != 0) {
        s32 e = arg0->f288;
        s32 c;

        if (e == -0x3DF || e == -0x3D1) {
            c = 0x35;
            goto set;
        }
        if (e != 0) {
            c = 0x2E;
        set:
            g->f10 = c;
            if (g->f14 == 0) {
                g->f14 = c;
            }
            r = 0;
        }
    }
    return r ? arg0->f270 : 0;
}
/* localdecomp:end func_L39_006D4380 */

/* localdecomp:start func_L39_006D44F0 */
typedef struct { u8 bytes[0x188]; } __attribute__((packed)) Part_6D44F0;
typedef struct { Part_6D44F0 a; s32 b; } Block_6D44F0;
typedef struct { u8 pad[2]; u8 f2; u8 pad3[0xD]; u8 f10; u8 pad11[0x25F]; Block_6D44F0 f270; } Target_6D44F0;
typedef struct { u8 pad[0x3C]; Target_6D44F0 *f3C; } Global_6D44F0;
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;

void func_L39_006D44F0(Block_6D44F0 *arg) {
    Target_6D44F0 *t = ((Global_6D44F0 *)D_L39_0024D760)->f3C;
    t->f270 = *arg;
    t->f2 = 1;
    t->f10 = 0;
}
/* localdecomp:end func_L39_006D44F0 */

/* localdecomp:start func_L39_006D45B8 */
typedef struct S_6D45B8 {
    u8 pad0[0x12];
    u8 f12;
    u8 pad13[5];
    s32 f18;
} S_6D45B8;
typedef struct S_6D45B8_G {
    u8 pad0[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0x38];
    s32 f50;
} S_6D45B8_G;
extern u16 D_L39_00249C78[];
extern u8 D_00197C18[];
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_0019B5C8(void);
extern s32 func_0017E9B8(u16 *, u8 *, s32);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);

s32 func_L39_006D45B8(u8 *arg0) {
    S_6D45B8 *p = (S_6D45B8 *)arg0;
    S_6D45B8_G *g = (S_6D45B8_G *)D_L39_0024D760;
    s32 r = 1;
    struct { u16 x[1]; u8 pad2[0x13]; u8 buf[0x13]; s32 v; } l;

    *(s32 *)(arg0 + 0xD20) = 0;
    l.x[0] = D_L39_00249C78[0];
    func_001206F4(l.buf, (void *)g->f50);
    l.v = func_0019B5C8();
    p->f12 = 1;
    p->f18 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017E9B8(l.x, D_00197C18, 0));
    if (func_001961F8() != 0) {
        g->f10 = 0x2F;
        if (g->f14 == 0) {
            g->f14 = 0x2F;
        }
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L39_006D45B8 */

/* localdecomp:start func_L39_006D4688 */
typedef struct { u8 b[0x100]; } Blk_006D4688;
typedef struct {
    char name[0x20];
    s32 f20;
    Blk_006D4688 data;
} Rec_006D4688;
typedef struct { Rec_006D4688 r[8]; } Recs_006D4688;
typedef struct {
    u8 _p0[0x11];
    u8 f11;
    u8 f12;
    u8 _p13[0x18 - 0x13];
    s32 f18;
    s32 f1C;
    u8 _p20[0x3FC - 0x20];
    s32 f3FC;
    Recs_006D4688 saved;
    u8 _pD20[0xD20 - 0xD20];
    s32 fD20;
    Recs_006D4688 recs;
} T_006D4688;
typedef struct {
    u8 _p0[0x10];
    s32 f10;
    s32 f14;
    u8 _p18[0x3C - 0x18];
    T_006D4688 *f3C;
} G_006D4688;
typedef struct {
    u8 _p0[0x18];
    s32 f18;
    s32 f1C;
    char name[0x20];
    Blk_006D4688 data;
    u8 _p140[0x144 - 0x140];
    u8 f144;
} A_006D4688;

__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern void func_L39_005958A0(s32, s32, s32);

void func_L39_006D4688(A_006D4688 *a) {
    G_006D4688 *g = (G_006D4688 *)D_L39_0024D760;
    T_006D4688 *t = g->f3C;
    s32 c;

    if (a->f18 == 0) {
        Rec_006D4688 *rec = &t->recs.r[t->fD20++];
        rec->f20 = a->f1C;
        func_L39_005958A0((s32)rec->name, (s32)a->name, 0x20);
        rec->data = a->data;
        if (a->f144 == 1) {
            t->saved = t->recs;
            t->f11 = 1;
            t->f3FC = t->fD20;
            t->f18 = t->f1C;
            t->f12 = 0;
        }
    } else if (a->f18 == 1) {
        t->f11 = 1;
        t->f18 = t->f1C;
        t->f12 = 0;
        t->f3FC = 0;
    } else {
        if (a->f18 == -0x3DF || a->f18 == -0x3D1) {
            t->f11 = 0;
            c = 0x35;
        } else if (a->f18 < 0) {
            t->f11 = 0;
            c = 0x2F;
        } else {
            return;
        }
        t->f12 = 0;
        t->f3FC = 0;
        g->f10 = c;
        if (g->f14 == 0) {
            g->f14 = c;
        }
    }
}
/* localdecomp:end func_L39_006D4688 */

/* localdecomp:start func_L39_006D48C8 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x13];
    s32 f28;
} Loc_006D48C8;
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
} G_006D48C8;
typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad21[3];
    s32 f24;
    u8 pad28[0x1644 - 0x28];
    s32 f1644;
    u8 f1648[1];
} S_006D48C8;
typedef struct {
    u8 pad0[0x2DC];
    s32 f2DC;
} D_006D48C8;
extern u16 D_L39_00249C78[];
extern u8 D_00197B28[];
extern void *func_001206F4(void *, void *);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);
extern void func_00195410(void);

u8 *func_L39_006D48C8(S_006D48C8 *p, s32 a, s32 *out) {
    G_006D48C8 *g;
    Loc_006D48C8 x;
    D_006D48C8 *d;
    s32 r;
    s32 code;
    u8 *ret;

    g = D_L39_0024D760;
    p->f1644 = 0;
    x.f0 = D_L39_00249C78[0];
    func_001206F4(x.f15, g->f50);
    x.f28 = a;
    p->f20 = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017E9B8((u16 *)&x, D_00197B28, 0));
    d = (D_006D48C8 *)D_001A5CD0;
    while (p->f20) {
        if (func_001961F8() != 0 || d->f2DC != 0) {
            g->f10 = 0x2F;
            if (g->f14 == 0) {
                g->f14 = 0x2F;
            }
            r = 0;
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
    p->f20 = 0;
    code = p->f24;
    if (code == 1) {
        p->f1644 = 0;
    } else if (code == -0x3DF || code == -0x3D1) {
        g->f10 = 0x35;
        if (g->f14 == 0) {
            g->f14 = 0x35;
        }
        r = 0;
    } else if (code < 0) {
        g->f10 = 0x2F;
        if (g->f14 == 0) {
            g->f14 = 0x2F;
        }
        r = 0;
    }
    ret = 0;
    *out = 0;
    if (r) {
        *out = p->f1644;
        ret = p->f1648;
    }
    return ret;
}
/* localdecomp:end func_L39_006D48C8 */

/* localdecomp:start func_L39_006D4A68 */
typedef struct {
    u8 data[0x100];
} Blk_006D4A68;
typedef struct {
    u8 name[0x20];
    s32 f20;
    Blk_006D4A68 blk;
} Ent_006D4A68;
typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad21[3];
    s32 f24;
    u8 pad28[0x161C];
    s32 count;
    Ent_006D4A68 ents[1];
} Tab_006D4A68;
typedef struct {
    u8 pad0[0x3C];
    Tab_006D4A68 *f3C;
} G_006D4A68;
typedef struct {
    u8 pad0[0x18];
    s32 f18;
    s32 f1C;
    u8 name[0x20];
    Blk_006D4A68 blk;
    u8 pad140[4];
    u8 f144;
} Arg_006D4A68;
extern void func_L39_005958A0(s32, s32, s32);
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;

void func_L39_006D4A68(Arg_006D4A68 *a) {
    Tab_006D4A68 *t = ((G_006D4A68 *)D_L39_0024D760)->f3C;

    if (a->f18 == 0) {
        Ent_006D4A68 *e = &t->ents[t->count++];
        e->f20 = a->f1C;
        func_L39_005958A0((s32)e, (s32)a->name, 0x20);
        e->blk = a->blk;
        if (a->f144 != 1) {
            return;
        }
    }
    t->f20 = 0;
    t->f24 = a->f18;
}
/* localdecomp:end func_L39_006D4A68 */

/* localdecomp:start func_L39_006D4B98 */
typedef struct S_006D4B98 {
    u8 pad0[3];
    u8 f3;
    u8 f4;
    u8 pad5[3];
    s32 f8;
    s32 fC;
    u8 pad10[2];
    u8 f12;
    u8 f13;
    s32 f14;
    s32 f18;
} S_006D4B98;
typedef struct { u8 pad[0x10]; s32 f10; s32 f14; } G_006D4B98;
extern G_006D4B98 *D_001E2050_sda;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_L39_006D45B8(u8 *);
extern s32 func_L39_006D4188(u8 *);

s32 func_L39_006D4B98(S_006D4B98 *arg0) {
    G_006D4B98 *g = D_001E2050_sda;
    s32 r = 1;

    if (arg0->f12 != 0) {
        if (((s32) func_00130760(func_0012DCB0(), 0x24000) - arg0->f18) >= 0x3A99) {
            g->f10 = 2;
            if (g->f14 == 0) {
                g->f14 = 2;
            }
            arg0->f12 = 0;
            func_L39_006D45B8((u8 *)arg0);
            r = 0;
        }
    } else if (arg0->f13 != 0) {
        if (arg0->f14 < ((s32) func_00130760(func_0012DCB0(), 0x24000) - arg0->f18)) {
            r = func_L39_006D45B8((u8 *)arg0);
        }
    }
    if (arg0->f3 != 0) {
        if (((s32) func_00130760(func_0012DCB0(), 0x24000) - arg0->fC) >= 0x3A99) {
            g->f10 = 2;
            if (g->f14 == 0) {
                g->f14 = 2;
            }
            arg0->f3 = 0;
            func_L39_006D4188((u8 *)arg0);
            r = 0;
        }
    } else if (arg0->f4 != 0) {
        if (arg0->f8 < ((s32) func_00130760(func_0012DCB0(), 0x24000) - arg0->fC)) {
            r = func_L39_006D4188((u8 *)arg0);
        }
    }
    return r;
}
/* localdecomp:end func_L39_006D4B98 */

/* localdecomp:start func_L39_006D4D48 */
typedef struct {
    u8 pad0[3];
    u8 f3;
    u8 pad4[8];
    s32 fC;
    u8 pad10[2];
    u8 f12;
    u8 pad13[5];
    s32 f18;
} T_006D4D48;
typedef struct {
    u8 pad0[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
} G_006D4D48;
typedef struct {
    u8 pad0[0x2DC];
    s32 f2DC;
} P_006D4D48;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_001961F8(void);
extern void func_00195410(void);

s32 func_L39_006D4D48(T_006D4D48 *a0) {
    s32 r1 = 1;
    s32 r2;
    G_006D4D48 *g = (G_006D4D48 *)D_001E2050_sda;

    if (a0->f3) {
        P_006D4D48 *p = (P_006D4D48 *)D_001A5CD0;

        do {
        if (func_001961F8() != 0 || p->f2DC != 0) {
            g->f10 = 0x2E;
            if (g->f14 == 0) {
                g->f14 = 0x2E;
            }
            r1 = 0;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if ((s32) func_00130760(func_0012DCB0(), 0x24000) - a0->fC >= 0x3A99) {
            r1 = 0;
            break;
        }
        } while (a0->f3);
    }
    a0->f3 = 0;
    r2 = 1;
    if (a0->f12) {
        P_006D4D48 *p = (P_006D4D48 *)D_001A5CD0;

        do {
        if (func_001961F8() != 0 || p->f2DC != 0) {
            g->f10 = 0x2E;
            if (g->f14 == 0) {
                g->f14 = 0x2E;
            }
            r2 = 0;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if ((s32) func_00130760(func_0012DCB0(), 0x24000) - a0->f18 >= 0x3A99) {
            r2 = 0;
            break;
        }
        } while (a0->f12);
    }
    a0->f12 = 0;
    return r1 || r2;
}
/* localdecomp:end func_L39_006D4D48 */
