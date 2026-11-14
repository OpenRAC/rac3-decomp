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
void func_0014B008(void *);
extern void func_0011D534(void *, s32, s32);
extern void *func_001206F4(void *, void *);
extern void func_0014B008(void *);
extern void *D_L39_0024D760;
void func_0011D534(void *, s32, s32);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_00183BDC(void);
extern void func_L39_005958A0(s32, s32, s32);
extern void func_00195410(void);
extern u8 D_001A5CD0[];
extern s32 func_L39_006D8AD8(u8 *);

/* localdecomp:start func_L39_006D3A30 */
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
    u8 pad1D[0x13];
    s32 *f30;
    u8 pad34[4];
    s32 *f38;
    u8 pad3C[0x14];
    void *f50;
} G_006D3A30;

typedef struct {
    u8 pad0;
    u8 f1;
    u8 f2;
    u8 f3;
    u8 pad4[0xD];
    u8 f11;
} A_006D3A30;

typedef struct {
    u8 name[0x20];
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2C;
    u8 pad30[0x104];
    u8 f134[0x40];
    s32 f174;
    s32 f178;
    s32 f17C;
    s32 f180;
} E_006D3A30;

typedef struct {
    u8 name[0x140];
    u8 f140[0x24];
    s32 f164;
    s32 f168;
    s32 f16C;
    s32 f170;
    s32 f174;
    s32 f178;
    s32 f17C;
    s32 f180;
    s32 f184;
    s32 f188;
} P_006D3A30;

typedef struct {
    u8 pad0[4];
    s32 f4;
    u8 pad8[4];
    s32 fC;
    u8 pad10[4];
    s32 f14;
    s32 f18;
    s32 f1C;
    u8 pad20[0x3E];
    u8 f5E[0xA0];
    u8 fFE[0x32];
    s32 f130;
    s32 f134;
    s32 f138;
    s32 f13C;
    s32 f140;
    s32 f144;
    u8 pad148[0x34];
    s32 f17C;
    u8 pad180[0x148];
    u8 f2C8;
} D_006D3A30;

typedef union {
    struct {
        u16 f0;
        u8 pad2[0x13];
        u8 f15[0x13];
        s32 f28;
        s32 f2C;
        s32 f30;
        s32 f34;
        u8 f38[0x40];
        u8 f78[0x40];
        s32 fB8;
        s32 fBC;
        s32 fC0;
        s32 fC4;
        s32 fC8;
        s32 fCC;
        u8 padD0[4];
    } a;
    struct {
        s32 f0;
        s32 f4;
        u8 pad8[0x20];
        u16 f28;
        u16 f2A;
        u16 f2C;
        u16 f2E;
        u8 f30[0x10];
        u8 f40[0x40];
    } b;
} B_006D3A30;

typedef struct {
    s32 f0;
    s32 f4;
    u8 pad8[4];
    s32 fC;
    u8 pad10[0x10];
    s32 f20;
} N_006D3A30;
extern N_006D3A30 D_L39_00240628 __attribute__((section(".sdata")));
__asm__(".extern D_L39_00241640, 16");
extern u8 *D_L39_00241640;
extern u8 D_L39_00249C80[];
extern u8 D_L39_00249C88[];
extern u8 D_001A5CD0[];
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern u16 D_L39_00249C78[];
s32 func_L39_006D4188(u8 *);
s32 func_L39_006D40B0(void);

s32 func_L39_006CC458(s32, P_006D3A30 *);
s32 func_L39_006D4D48();
s32 func_0019B5C8(void);
s32 func_00120048(u8 *, u8 *, ...);
s32 func_L39_006D34D8(A_006D3A30 *, s32, void *, s32, s32, s32);
s32 func_L39_006D8AD8(u8 *);
extern void func_0011D534(void *, s32, s32);
s32 func_00183BDC(void);
s32 func_00120884(void *);
s32 func_0017E698(void *, void *, s32);
void func_L39_006D4030();
void func_00195410(void);
void func_0019B5E8(s32);
void func_00196468(void);
s32 func_00195810(void);
void func_0014AD08(s32, s32, s32, s32, s32, void *);
void func_00196380(P_006D3A30 *, s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_00196478(s32);
s32 func_001205B0(void *, void *);
void func_0019BEB8(s32);
void func_0019CA28(s32);

s32 func_L39_006D3A30(A_006D3A30 *arg0, P_006D3A30 *arg1, s32 arg2, s32 arg3) {
    G_006D3A30 *g;
    G_006D3A30 *h;
    D_006D3A30 *p;
    E_006D3A30 *ent;
    void *name;
    u8 *q;
    s32 ok;
    s32 i;
    s32 handle;
    u16 x;
    u16 y;
    B_006D3A30 buf;

    ok = func_L39_006D4D48(arg0);
    if (ok == 0) {
        return 0;
    }
    arg0->f2 = 0;
    arg0->f11 = 0;
    h = (G_006D3A30 *)D_L39_0024D760;
    D_L39_00240628.f0 = func_L39_006CC458(0x11, arg1);
    D_L39_00240628.f4 = func_L39_006CC458(0xC, arg1);
    D_L39_00240628.fC = func_L39_006CC458(0x16, arg1);
    if (D_L39_00240628.f4 == 2) {
        arg3 = *h->f38 != func_L39_006CC458(0xD, arg1);
    }
    g = (G_006D3A30 *)D_L39_0024D760;
    name = g->f50;
    func_0011D534(&buf, 0, 0xD4);
    buf.a.f28 = func_00183BDC();
    buf.a.f34 = arg1->f16C;
    buf.a.fCC = ((D_006D3A30 *)D_001A5CD0)->f2C8 ? 4 : 0;
    func_L39_005958A0((s32)buf.a.f38, (s32)arg1, func_00120884(arg1));
    func_L39_005958A0((s32)buf.a.f78, (s32)arg1->f140, func_00120884(arg1->f140));
    buf.a.fC0 = arg1->f178;
    buf.a.fC4 = arg1->f17C;
    buf.a.fC8 = arg1->f180;
    buf.a.f30 = arg1->f164;
    buf.a.f2C = arg1->f168;
    buf.a.fB8 = arg1->f170;
    buf.a.fBC = arg1->f174;
    func_001206F4(buf.a.f15, name);
    buf.a.f0 = D_L39_00249C78[0];
    arg0->f1 = 1;
    g->f1 = 1;
    g->f8 = (s32)func_00130760(func_0012DCB0(), 0x24000);
    if (func_0017E698(&buf, func_L39_006D4030, 0) != 0) {
        arg0->f1 = 0;
        g->f10 = 0x29;
        if (g->f14 == 0) {
            g->f14 = 0x29;
        }
        return 0;
    }
    while (arg0->f1 != 0) {
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if (func_L39_006D8AD8((u8 *)g) == 0) {
            ok = 0;
            break;
        }
    }
    g->f1 = 0;
    arg0->f1 = 0;
    if (g->f10 != 0) {
        ok = 0;
    }
    g->f10 = 0;
    if (ok == 0) {
        goto fail;
    }
    ok = func_L39_006D34D8(arg0, func_0019B5C8(), arg1->f140, arg2, arg3, buf.a.fCC);
    if (ok == 0) {
        goto fail;
    }
    p = (D_006D3A30 *)D_001A5CD0;
    func_0019B5E8(1);
    func_00196468();
    p->fC = arg2;
    p->f130 = arg2;
    p->f134 = arg1->f164;
    p->f18 = arg3;
    p->f138 = arg1->f184;
    p->f13C = arg1->f188;
    p->f140 = arg1->f184;
    p->f144 = arg1->f188;
    p->f14 = func_L39_006CC458(0x10, arg1) + 0x27;
    func_001206F4(p->fFE, arg1->f140);
    if (D_L39_00241640 != 0) {
        *(u16 *)(D_L39_00241640 + 0x17C) = p->f14;
    }
    if (p->f17C != 0) {
        if (func_00195810() != 0) {
            ok = 0;
        }
    }
    if (ok == 0) {
        goto fail;
    }
    q = p->f5E;
    buf.b.f4 = *h->f30;
    buf.b.f0 = p->fC;
    y = p->f1C;
    x = p->f18;
    buf.b.f28 = x;
    buf.b.f2A = x;
    buf.b.f2C = y;
    buf.b.f2E = y;
    func_001206F4(buf.b.f30, q);
    if ((u32)func_00120884(q) < 0xA) {
        func_00120048(buf.b.f40, D_L39_00249C80, q, 2);
    } else {
        func_00120048(buf.b.f40, D_L39_00249C88, q, 2);
    }
    func_0014AD08(0x50, ((D_006D3A30 *)D_001A5CD0)->f4, -1, D_L39_00240628.f20, 0x58, &buf);
    func_00196380(arg1, arg1->f168, arg1->f164, arg1->f16C, arg1->f170, arg1->f174, arg1->f178, arg1->f17C, arg1->f180);
    func_0014B008(&handle);
    ok = func_00196478(handle);
    if (ok == 0) {
        goto fail;
    }
    ent = arg0->f2 ? (E_006D3A30 *)((u8 *)arg0 + 0xE4) : 0;
    i = 0;
    func_L39_005958A0((s32)&buf, (s32)arg1, func_00120884(arg1));
    while (ent == 0 || func_001205B0(ent->f134, &buf) != 0) {
        i++;
        if (arg0->f3 == 0) {
            ok = func_L39_006D4188((u8 *)arg0);
        } else {
            h->f1 = 1;
            h->f8 = (s32)func_00130760(func_0012DCB0(), 0x24000);
        }
        while (arg0->f3 != 0) {
            h->f1C = 1;
            func_00195410();
            h->f1C = 0;
            if (func_L39_006D8AD8((u8 *)h) == 0) {
                ok = 0;
                break;
            }
        }
        h->f1 = 0;
        ent = arg0->f2 ? (E_006D3A30 *)((u8 *)arg0 + 0xE4) : 0;
        if (ent != 0 && (ent->f180 != arg1->f180 || ent->f17C != arg1->f17C
                || ent->f178 != arg1->f178 || ent->f2C != arg1->f170
                || ent->f174 != arg1->f174 || ent->f28 != arg1->f16C
                || ent->f20 != arg1->f168 || ent->f24 != arg1->f164)) {
            ent = 0;
        }
        if (i >= 0x15) {
            h->f10 = 2;
            if (h->f14 == 0) {
                h->f14 = 2;
            }
            ok = 0;
            break;
        }
    }
    if (ok == 0) {
fail:
        ((s32 (*)(A_006D3A30 *))func_L39_006D40B0)(arg0);
        return ok;
    }
    func_0019BEB8(6);
    func_0019CA28(1);
    return ok;
}
/* localdecomp:end func_L39_006D3A30 */
