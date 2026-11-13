#include "common.h"

typedef struct Loc_006DA090 {
    s16 f00;
    u8 pad02[0x26];
    s32 f28;
    s32 f2C;
    u8 f30[0x40];
} Loc_006DA090;
typedef struct Obj_006DA090 {
    u8 pad00[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0x38];
    s32 f50;
    s32 f54;
} Obj_006DA090;

/* declared by functions of L39_006D8E90.c, which this file was cut from */
extern Obj_006DA090 *D_L39_0024D760;
s32 func_001206F4(void *, s32);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
void func_001961E8(void *);
s32 func_001961F8(void);
void func_00195410(void);
extern s32 func_L39_006D8AD8(void *);
void func_L39_005958A0(void *, void *, s32);
extern Obj_006DA090 *D_L39_0024D760 __attribute__((section(".data")));

/* localdecomp:start func_L39_006D9FD8 */
typedef struct {
 int f0; char f4; char pad5[0xBB]; char fC0; char padC1[0x23];
 char fE4; char padE5[7]; char fEC; char padED[7]; char fF4;
 char padF5[0x67]; char f15C, f15D; char pad15E[2]; int f160, f164;
 char f168; char pad169[3]; int f16C, f170; char pad174[0x24];
 char f198, f199; char pad19A[2]; int f19C, f1A0; char f1A4;
 char pad1A5[3]; int f1A8, f1AC;
} Type1;

/* from rac4-decomp's func_L00_007770F0, renamed */
Type1 *func_L39_006D9FD8(Type1 *p) {
 p->f0 = -1;
 p->f4 = 0; p->fC0 = 0; p->fE4 = 0; p->fEC = 0; p->fF4 = 0;
 p->f15C = 0; p->f15D = 0; p->f160 = -1; p->f164 = -1;
 p->f168 = 0; p->f16C = 10000; p->f170 = -1;
 p->f198 = 0; p->f199 = 0; p->f19C = -1; p->f1A0 = -1; p->f1A4 = 0; p->f1AC = -1; p->f1A8 = 10000;
 return p;
}
/* localdecomp:end func_L39_006D9FD8 */

/* localdecomp:start func_L39_006DA038 */
void func_L39_006DA038(Type1 *p) {
    p->f0 = -1;
    p->f4 = 0;
    p->fC0 = 0;
    p->fE4 = 0;
    p->fEC = 0;
    p->fF4 = 0;
    p->f15D = 0;
    p->f160 = -1;
    p->f164 = -1;
    p->f168 = 0;
    p->f16C = 10000;
    p->f170 = -1;
    p->f199 = 0;
    p->f19C = -1;
    p->f1A0 = -1;
    p->f1A4 = 0;
    p->f1AC = -1;
    p->f1A8 = 10000;
}
/* localdecomp:end func_L39_006DA038 */

/* localdecomp:start func_L39_006DA090 */
s32 func_L39_006DD608(s32, void *, s32);
s32 func_001206F4(void *, s32);
void func_L39_005958A0(void *, void *, s32);
void *func_0017EC38(void *);
void func_001961E8(void *);
s32 func_001961F8(void);
__asm__(".extern D_L39_0024D760, 16");
extern u16 D_L39_00249F40[];

s32 func_L39_006DA090(s32 a0, void *a1) {
    Loc_006DA090 loc;
    Obj_006DA090 *p;
    s32 r;
    s32 x;

    p = D_L39_0024D760;
    x = p->f50;
    r = func_L39_006DD608(p->f54, a1, 0);
    if (r != 0) {
        loc.f00 = D_L39_00249F40[0];
        func_001206F4((u8 *)&loc + 0x15, x);
        loc.f28 = 0;
        loc.f2C = -1;
        func_L39_005958A0(loc.f30, a1, 0x40);
        func_001961E8(func_0017EC38(&loc));
        if (func_001961F8() != 0) {
            p->f10 = 0x49;
            if (p->f14 == 0) {
                p->f14 = 0x49;
            }
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006DA090 */

/* localdecomp:start func_L39_006DA158 */
s32 func_L39_006E16A0(void *, s32, s32, s32);
s32 func_L39_006DA158(u32 arg0, s32 arg1) {
    u32 p = arg0 + func_L39_006E16A0((void *)arg0, arg1 * 2, 0xD0, 4);
    {
        u32 a = 4;
        p = (p % a) ? p + (a - p % a) : p;
    }
    p += arg1 * 8;
    return p - arg0;
}
/* localdecomp:end func_L39_006DA158 */

/* localdecomp:start func_L39_006DA1C0 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
} Q_006DA1C0;
typedef struct {
    u8 pad0[0x15C];
    u8 f15C;
    u8 f15D;
    u8 pad15E[0x16];
    s32 f174;
    Q_006DA1C0 f178;
    Q_006DA1C0 f184;
    s32 f190;
    s32 f194;
} S_006DA1C0;
s32 func_L39_006E16A0(void *, s32, s32, s32);
s32 func_L39_006E1648(s32, s32, s32, s32);
void func_0011D534(s32, s32, s32);

void func_L39_006DA1C0(S_006DA1C0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u32 r;
    s32 n;
    Q_006DA1C0 *q;
    Q_006DA1C0 *q2;

    if (arg0->f15C == 0) {
        arg0->f15D = 0;
        arg0->f174 = arg3;
        arg0->f15C = 1;
        r = arg1;
        n = func_L39_006E16A0((void *)arg1, arg3 * 2, 0xD0, 4);
        arg0->f190 = func_L39_006E1648(r, n, 0xD0, 4);
        r += n;
        {
            u32 align = 4;
            u32 t = r;
            u32 rem = r % align;
            if (rem != 0) {
                t = r + (align - rem);
            }
            r = t;
        }
        arg0->f194 = r;
        func_0011D534(r, 0, arg0->f174 * 8);
        q = &arg0->f178;
        q->f0 = 0;
        q->f8 = arg0->f194;
        q->f4 = 0;
        q2 = &arg0->f184;
        q2->f0 = 0;
        q2->f8 = arg0->f174 * 4 + arg0->f194;
        q2->f4 = 0;
    }
}
/* localdecomp:end func_L39_006DA1C0 */

/* localdecomp:start func_L39_006DA2A8 */
s32 func_L39_006E16A0(void *, s32, s32, s32);
s32 func_L39_006DA2A8(u32 arg0, s32 arg1) {
    u32 p = arg0 + func_L39_006E16A0((void *)arg0, arg1 * 2, 0x80, 4);
    {
        u32 a = 4;
        p = (p % a) ? p + (a - p % a) : p;
    }
    p += arg1 * 8;
    return p - arg0;
}
/* localdecomp:end func_L39_006DA2A8 */

/* localdecomp:start func_L39_006DA310 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
} Q_006DA310;
typedef struct {
    u8 pad0[0x198];
    u8 f198;
    u8 f199;
    u8 pad19A[0x16];
    s32 f1B0;
    Q_006DA310 f1B4;
    Q_006DA310 f1C0;
    s32 f1CC;
    s32 f1D0;
} S_006DA310;
s32 func_L39_006E16A0(void *, s32, s32, s32);
s32 func_L39_006E1648(s32, s32, s32, s32);
void func_0011D534(s32, s32, s32);

void func_L39_006DA310(S_006DA310 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u32 r;
    s32 n;
    Q_006DA310 *q;
    Q_006DA310 *q2;

    if (arg0->f198 == 0) {
        arg0->f199 = 0;
        arg0->f1B0 = arg3;
        arg0->f198 = 1;
        r = arg1;
        n = func_L39_006E16A0((void *)arg1, arg3 * 2, 0x80, 4);
        arg0->f1CC = func_L39_006E1648(r, n, 0x80, 4);
        r += n;
        {
            u32 align = 4;
            u32 t = r;
            u32 rem = r % align;
            if (rem != 0) {
                t = r + (align - rem);
            }
            r = t;
        }
        arg0->f1D0 = r;
        func_0011D534(r, 0, arg0->f1B0 * 8);
        q = &arg0->f1B4;
        q->f0 = 0;
        q->f8 = arg0->f1D0;
        q->f4 = 0;
        q2 = &arg0->f1C0;
        q2->f0 = 0;
        q2->f8 = arg0->f1B0 * 4 + arg0->f1D0;
        q2->f4 = 0;
    }
}
/* localdecomp:end func_L39_006DA310 */

/* localdecomp:start func_L39_006DA3F8 */
typedef struct {
    u16 f00;
    u8 pad02[0x26];
    s32 f28;
    s32 f2C;
    char f30[0x40];
    char f70[0x20];
    s32 f90;
    s32 f94;
    s32 f98;
    s32 f9C;
    s32 fA0;
} Loc_006DA3F8;
typedef struct {
    char f00[0x40];
    char f40[0x20];
    s32 f60;
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
    s32 f74;
} Src_006DA3F8;
typedef struct {
    u8 pad0[0xC0];
    u8 fC0;
    u8 padC1[0x1B];
    s32 fDC;
    s32 fE0;
} S_006DA3F8;
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
    s32 f50;
} G_006DA3F8;
typedef struct {
    u8 pad0[0x2DC];
    s32 f2DC;
} P_006DA3F8;

extern long func_0012DCB0(void);
extern long func_00130760(long, long);
s32 func_00183BDC_006DA3F8(void);
void *func_0017E7A0_006DA3F8(void *, void (*)(void), s32);
void func_00197D80_006DA3F8(void);
void func_00195410(void);
extern P_006DA3F8 D_001A5CD0_006DA3F8;

s32 func_L39_006DA3F8(S_006DA3F8 *a0, Src_006DA3F8 *a1, s32 *a2) {
    Loc_006DA3F8 loc;
    G_006DA3F8 *g = (G_006DA3F8 *)D_L39_0024D760;
    s32 x = g->f50;
    s32 r;
    P_006DA3F8 *p;
    s32 v;

    func_0011D534((s32)&loc, 0, sizeof(loc));
    loc.f00 = D_L39_00249F40[0];
    func_001206F4((u8 *)&loc + 0x15, x);
    loc.f28 = func_00183BDC_006DA3F8();
    loc.f2C = a1->f60;
    loc.f90 = a1->f64;
    loc.f94 = a1->f68;
    loc.f98 = a1->f6C;
    loc.f9C = a1->f70;
    loc.fA0 = a1->f74;
    func_L39_005958A0(loc.f30, a1->f00, 0x40);
    func_L39_005958A0(loc.f70, a1->f40, 0x20);
    a0->fC0 = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017E7A0_006DA3F8(&loc, func_00197D80_006DA3F8, 0));
    p = &D_001A5CD0_006DA3F8;
    while (a0->fC0 != 0) {
        if (func_001961F8() != 0 || p->f2DC != 0) {
            g->f10 = 0x40;
            if (g->f14 == 0) {
                g->f14 = 0x40;
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
    a0->fC0 = 0;
    if (r != 0) {
        v = a0->fDC;
        if (v == -0x3DD) {
            g->f10 = 0x41;
            if (g->f14 == 0) {
                g->f14 = 0x41;
            }
            r = 0;
        } else if (v != 3 && v != 0 && !(a1->f64 == 6 && v == -0x3CE)) {
            g->f10 = 0x40;
            if (g->f14 == 0) {
                g->f14 = 0x40;
            }
            r = 0;
        }
    }
    if (a2 != 0) {
        if (r != 0 || a0->fDC == -0x3CE) {
            *a2 = a0->fE0;
        } else {
            *a2 = -1;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006DA3F8 */

/* localdecomp:start func_L39_006DA628 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { char bytes[32]; } Block_6DA628;
typedef struct { char pad[0xc0]; unsigned char fC0; char pad2[3]; Block_6DA628 fC4; } Type1_6DA628;
typedef struct { char pad[0x4c]; Type1_6DA628 *f4C; } Type2_6DA628;

/* from rac4-decomp's func_L00_00777750 */
void func_L39_006DA628(Block_6DA628 *arg0) {
    Type1_6DA628 *p = ((Type2_6DA628 *)D_L39_0024D760)->f4C;
    p->fC0 = 0;
    p->fC4 = *arg0;
}
/* localdecomp:end func_L39_006DA628 */

/* localdecomp:start func_L39_006DA680 */
typedef struct {
    u16 f00;
    u8 pad02[0x26];
    s32 f28;
    char f2C[0x20];
} Loc_006DA680;
typedef struct {
    s32 f0;
    u8 f4;
    u8 pad5[0x1B];
    s32 f20;
    u8 f24[1];
} S_006DA680;
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
    s32 f50;
} G_006DA680;
typedef struct {
    u8 pad0[0x78];
    s32 f78;
    u8 pad7C[0x260];
    s32 f2DC;
} P_006DA680;

extern long func_0012DCB0(void);
extern long func_00130760(long, long);
void *func_0017E920_006DA680(void *, void (*)(void), s32);
void func_00197DD0_006DA680(void);
void func_00195410(void);
extern s32 func_L39_006D8AD8(void *);
s32 func_L39_006DD340(void *);
s32 func_L39_006DD060(void *, void *);
extern P_006DA680 D_001A5CD0_006DA680;

s32 func_L39_006DA680(S_006DA680 *a0, s32 a1, void *a2) {
    Loc_006DA680 loc;
    G_006DA680 *g = (G_006DA680 *)D_L39_0024D760;
    s32 x = g->f50;
    s32 r;

    loc.f00 = D_L39_00249F40[0];
    func_001206F4((u8 *)&loc + 0x15, x);
    loc.f28 = a1;
    if (a2) {
        func_L39_005958A0(loc.f2C, a2, 0x20);
    } else {
        loc.f2C[0] = 0;
    }
    a0->f4 = 1;
    g->f1 = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017E920_006DA680(&loc, func_00197DD0_006DA680, 0));
    r = 1;
    while (a0->f4 != 0) {
        if (func_001961F8() != 0 || D_001A5CD0_006DA680.f2DC != 0) {
            g->f10 = 0x42;
            if (g->f14 == 0) {
                g->f14 = 0x42;
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
    a0->f4 = 0;
    if (r != 0) {
        if (a0->f20 == -0x3DD || a0->f20 == -0x3D9) {
            g->f10 = 0x43;
            if (g->f14 == 0) {
                g->f14 = 0x43;
            }
            r = 0;
        } else if (a0->f20 != 0) {
            g->f10 = 0x42;
            if (g->f14 == 0) {
                g->f14 = 0x42;
            }
            r = 0;
        }
    }
    if (r != 0 && (r = func_L39_006DD340((void *)x)) != 0
        && (r = func_L39_006DD060((void *)x, a0->f24)) != 0) {
        a0->f0 = a1;
    } else {
        a0->f0 = -1;
    }
    D_001A5CD0_006DA680.f78 = a0->f0;
    return r;
}
/* localdecomp:end func_L39_006DA680 */

/* localdecomp:start func_L39_006DA878 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { char bytes[0xB8]; } Block_006DA878;
typedef struct { char pad[4]; unsigned char f4; char pad2[3]; Block_006DA878 f8; } Type1_006DA878;
typedef struct { char pad[0x4c]; Type1_006DA878 *f4C; } Type2_006DA878;

void func_L39_006DA878(Block_006DA878 *arg0) {
    Type1_006DA878 *p = ((Type2_006DA878 *)D_L39_0024D760)->f4C;
    p->f4 = 0;
    p->f8 = *arg0;
}
/* localdecomp:end func_L39_006DA878 */

/* localdecomp:start func_L39_006DA958 */
typedef struct {
    s32 f0;
    u8 pad4[0x158];
    u8 f15C, f15D;
    u8 pad15E[2];
    s32 f160;
    u8 pad164[4];
    u8 f168;
    u8 pad169[3];
    s32 f16C;
    u8 pad170[0x28];
    u8 f198, f199;
    u8 pad19A[2];
    s32 f19C;
    u8 pad1A0[4];
    u8 f1A4;
    u8 pad1A5[3];
    s32 f1A8;
} S_006DA958;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
s32 func_L39_006DAB18(S_006DA958 *);
s32 func_L39_006DAFC8();

s32 func_L39_006DA958(S_006DA958 *p) {
    s32 r = 1;

    if (p->f15C) {
        if (p->f15D == 0) {
            if (p->f168 && p->f0 >= 0) {
                s32 t = func_00130760(func_0012DCB0(), 0x24000);
                s32 ok = 1;
                if (p->f160 >= 0 && t - p->f160 < p->f16C) {
                    ok = 0;
                }
                if (ok) {
                    r = func_L39_006DAB18(p);
                }
            }
        } else if (p->f0 >= 0) {
            if ((s32)func_00130760(func_0012DCB0(), 0x24000) - p->f160 > 15000) {
                p->f15D = 0;
                func_L39_006DAB18(p);
                r = 0;
            }
        }
    }
    if (p->f198) {
        if (p->f199 == 0) {
            if (p->f1A4) {
                s32 t = func_00130760(func_0012DCB0(), 0x24000);
                s32 ok = 1;
                if (p->f19C >= 0) {
                    if (t - p->f19C < p->f1A8) {
                        ok = 0;
                    }
                }
                if (ok) {
                    r = func_L39_006DAFC8(p);
                }
            }
        } else {
            if ((s32)func_00130760(func_0012DCB0(), 0x24000) - p->f19C > 15000) {
                p->f199 = 0;
                func_L39_006DAFC8(p);
                r = 0;
            }
        }
    }
    return r;
}
/* localdecomp:end func_L39_006DA958 */

/* localdecomp:start func_L39_006DAB18 */
typedef struct {
    u16 f00;
    u8 pad02[0x16];
    s32 f18;
    u8 pad1C[4];
    u8 f20[0x10];
} Loc_006DAB18;
typedef struct {
    s32 f00;
    u8 pad04[0x159];
    u8 f15D;
    u8 pad15E[2];
    s32 f160;
} Obj_006DAB18;
typedef struct {
    u8 pad00[0x10];
    s32 f10;
    s32 f14;
} Dst_006DAB18;

extern void func_0014B008(void *);
extern void *func_0017F858(void *, void *, s32);
extern void func_001961E8(void *);
extern s32 func_001961F8(void);
extern u16 D_L39_00249F40[];
extern u8 D_00197DF8[];

/* follows func_L39_006DAFC8 in this file */
s32 func_L39_006DAB18(S_006DA958 *arg) {
    extern Dst_006DAB18 *D_001E2050_sda;
    Obj_006DAB18 *arg0 = (Obj_006DAB18 *)arg;
    Loc_006DAB18 loc;
    s32 ret = 1;
    Dst_006DAB18 *d = D_001E2050_sda;

    if (arg0->f00 >= 0) {
        if (arg0->f15D == 0) {
            loc.f18 = arg0->f00;
            loc.f00 = D_L39_00249F40[0];
            arg0->f15D = 1;
            arg0->f160 = func_00130760(func_0012DCB0(), 0x24000);
            func_0014B008(loc.f20);
            func_001961E8(func_0017F858(&loc, D_00197DF8, 0));
            if (func_001961F8() != 0) {
                d->f10 = 0x44;
                if (d->f14 == 0) {
                    d->f14 = 0x44;
                }
                ret = 0;
            }
        }
    } else {
        d->f10 = 0x45;
        if (d->f14 == 0) {
            d->f14 = 0x45;
        }
        ret = 0;
    }
    return ret;
}
/* localdecomp:end func_L39_006DAB18 */

/* localdecomp:start func_L39_006DABF0 */
typedef struct Msg_006DABF0 {
    u8 pad00[0x18];
    s32 f18;
    u8 pad1C[0xCC - 0x1C];
    u8 fCC;
    u8 padCD[3];
} Msg_006DABF0;
typedef struct Pool_006DABF0 {
    u8 pad00[0xC];
    s32 fC;
    u8 pad10[8];
    s32 f18;
    u8 *f1C;
} Pool_006DABF0;
typedef struct Q_006DABF0 {
    s32 (*cmp)(Msg_006DABF0 *, Msg_006DABF0 *);
    s32 count;
    Msg_006DABF0 **arr;
} Q_006DABF0;
typedef struct Mgr_006DABF0 {
    u8 pad00[0x15C];
    u8 f15C;
    u8 f15D;
    u8 pad15E[2];
    s32 f160;
    s32 f164;
    u8 pad168[8];
    s32 f170;
    s32 f174;
    Q_006DABF0 q[2];
    Pool_006DABF0 *pool;
} Mgr_006DABF0;
typedef struct G_006DABF0 {
    u8 pad00[0x1D];
    u8 f1D;
    u8 pad1E[0x4C - 0x1E];
    Mgr_006DABF0 *mgr;
} G_006DABF0;

void func_L39_006DABF0(Msg_006DABF0 *msg)
{
    G_006DABF0 *g = (G_006DABF0 *)D_L39_0024D760;
    Mgr_006DABF0 *m = g->mgr;
    Q_006DABF0 *q;
    Q_006DABF0 *old;
    Pool_006DABF0 *pool;
    Pool_006DABF0 *pool2;
    Msg_006DABF0 *item;
    Msg_006DABF0 *item2;
    Msg_006DABF0 *tmp;
    Msg_006DABF0 *got;
    Msg_006DABF0 *top;
    s32 k;
    s32 i;
    s32 n;
    s32 parent;
    s32 j;
    s32 child;
    s32 c2;

    if (m->f15C == 0 || g->f1D != 0) {
        return;
    }
    k = m->f170 == 0;
    q = &m->q[k];
    if (msg->f18 == 0 && q->count < m->f174) {
        pool = m->pool;
        item = (Msg_006DABF0 *)pool->f1C;
        if (item != 0) {
            pool->f1C = *(u8 **)((u8 *)item + pool->fC);
            pool->f18--;
        }
        got = item;
        if (got != 0) {
            *got = *msg;
            n = q->count;
            q->count = n + 1;
            q->arr[n] = got;
            if (q->cmp != 0) {
                parent = n / 2;
                while (n > 0 && (u8)q->cmp(q->arr[parent], q->arr[n])) {
                    tmp = q->arr[parent];
                    q->arr[parent] = q->arr[n];
                    q->arr[n] = tmp;
                    n = parent;
                }
            }
        }
    }
    if (msg->fCC != 0) {
        if (q->cmp != 0 && q->count >= 2) {
            for (i = q->count - 1; i > 0; i--) {
                tmp = q->arr[i];
                q->arr[i] = q->arr[0];
                q->arr[0] = tmp;
                if (q->cmp != 0) {
                    j = i;
                    top = q->arr[j];
                    child = j * 2 + 1;
                    if (child < 0) {
                        do {
                            c2 = child + 1;
                            if (c2 < 0) {
                                if ((u8)q->cmp(q->arr[child], q->arr[c2])) {
                                    child = c2;
                                }
                                if (!q->cmp(top, q->arr[child])) {
                                    break;
                                }
                                q->arr[j] = q->arr[child];
                                j = child;
                                child = j * 2 + 1;
                            }
                        } while (child < 0);
                    }
                    q->arr[j] = top;
                }
            }
        }
        old = 0;
        if (m->f170 >= 0) {
            old = &m->q[m->f170];
        }
        if (old != 0) {
            for (i = 0; i < old->count; i++) {
                pool2 = m->pool;
                item2 = old->arr[i];
                *(u8 **)((u8 *)item2 + pool2->fC) = pool2->f1C;
                pool2->f1C = (u8 *)item2;
                pool2->f18++;
            }
            old->count = 0;
        }
        m->f170 = k;
        m->f164 = m->f160;
        m->f15D = 0;
    }
}
/* localdecomp:end func_L39_006DABF0 */

/* localdecomp:start func_L39_006DAFC8 */
typedef struct {
    u16 f00;
    u8 pad02[0x14];
    u16 f16;
    u16 f18;
    u8 pad1A[6];
    u8 f20[0x10];
} Loc_006DAFC8;
typedef struct {
    u8 pad00[0x199];
    u8 f199;
    s32 f19C;
    u8 pad1A0[0x10];
    u16 f1B0;
} Obj_006DAFC8;
typedef struct {
    u8 pad00[0x10];
    s32 f10;
    s32 f14;
} Dst_006DAFC8;

extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_0014B008(void *);
extern void *func_0017F948(void *, void *, s32);
extern void func_001961E8(void *);
extern s32 func_001961F8(void);
extern u16 D_L39_00249F40[];
extern u8 D_00197E20[];
extern Dst_006DAFC8 *D_001E2050_sda;

s32 func_L39_006DAFC8(Obj_006DAFC8 *arg0) {
    Loc_006DAFC8 loc;
    s32 ret = 1;
    Dst_006DAFC8 *d = D_001E2050_sda;

    if (arg0->f199 == 0) {
        loc.f00 = D_L39_00249F40[0];
        loc.f18 = arg0->f1B0;
        loc.f16 = 1;
        arg0->f199 = 1;
        arg0->f19C = func_00130760(func_0012DCB0(), 0x24000);
        func_0014B008(loc.f20);
        func_001961E8(func_0017F948(&loc, D_00197E20, 0));
        if (func_001961F8() != 0) {
            d->f10 = 0x48;
            if (d->f14 == 0) {
                d->f14 = 0x48;
            }
            ret = 0;
        }
    }
    return ret;
}
/* localdecomp:end func_L39_006DAFC8 */

/* localdecomp:start func_L39_006DB098 */
typedef struct Msg_006DB098 {
    u8 pad00[0x18];
    s32 f18;
    u8 pad1C[0x7C - 0x1C];
    u8 f7C;
    u8 pad7D[3];
} Msg_006DB098;
typedef struct Pool_006DB098 {
    u8 pad00[0xC];
    s32 fC;
    u8 pad10[8];
    s32 f18;
    u8 *f1C;
} Pool_006DB098;
typedef struct Q_006DB098 {
    s32 (*cmp)(Msg_006DB098 *, Msg_006DB098 *);
    s32 count;
    Msg_006DB098 **arr;
} Q_006DB098;
typedef struct Mgr_006DB098 {
    u8 pad00[0x198];
    u8 f198;
    u8 f199;
    u8 pad19A[2];
    s32 f19C;
    s32 f1A0;
    u8 pad1A4[8];
    s32 f1AC;
    s32 f1B0;
    Q_006DB098 q[2];
    Pool_006DB098 *pool;
} Mgr_006DB098;
typedef struct G_006DB098 {
    u8 pad00[0x1D];
    u8 f1D;
    u8 pad1E[0x4C - 0x1E];
    Mgr_006DB098 *mgr;
} G_006DB098;

void func_L39_006DB098(Msg_006DB098 *msg)
{
    G_006DB098 *g = (G_006DB098 *)D_L39_0024D760;
    Mgr_006DB098 *m = g->mgr;
    Q_006DB098 *q;
    Q_006DB098 *old;
    Pool_006DB098 *pool;
    Pool_006DB098 *pool2;
    Msg_006DB098 *item;
    Msg_006DB098 *item2;
    Msg_006DB098 *tmp;
    Msg_006DB098 *got;
    Msg_006DB098 *top;
    s32 k;
    s32 i;
    s32 n;
    s32 parent;
    s32 j;
    s32 child;
    s32 c2;

    if (m->f198 == 0 || g->f1D != 0) {
        return;
    }
    k = m->f1AC == 0;
    q = &m->q[k];
    if (msg->f18 == 0 && q->count < m->f1B0) {
        pool = m->pool;
        item = (Msg_006DB098 *)pool->f1C;
        if (item != 0) {
            pool->f1C = *(u8 **)((u8 *)item + pool->fC);
            pool->f18--;
        }
        got = item;
        if (got != 0) {
            *got = *msg;
            n = q->count;
            q->count = n + 1;
            q->arr[n] = got;
            if (q->cmp != 0) {
                parent = n / 2;
                while (n > 0 && (u8)q->cmp(q->arr[parent], q->arr[n])) {
                    tmp = q->arr[parent];
                    q->arr[parent] = q->arr[n];
                    q->arr[n] = tmp;
                    n = parent;
                }
            }
        }
    }
    if (msg->f7C != 0) {
        if (q->cmp != 0 && q->count >= 2) {
            for (i = q->count - 1; i > 0; i--) {
                tmp = q->arr[i];
                q->arr[i] = q->arr[0];
                q->arr[0] = tmp;
                if (q->cmp != 0) {
                    j = i;
                    top = q->arr[j];
                    child = j * 2 + 1;
                    if (child < 0) {
                        do {
                            c2 = child + 1;
                            if (c2 < 0) {
                                if ((u8)q->cmp(q->arr[child], q->arr[c2])) {
                                    child = c2;
                                }
                                if (!q->cmp(top, q->arr[child])) {
                                    break;
                                }
                                q->arr[j] = q->arr[child];
                                j = child;
                                child = j * 2 + 1;
                            }
                        } while (child < 0);
                    }
                    q->arr[j] = top;
                }
            }
        }
        old = 0;
        if (m->f1AC >= 0) {
            old = &m->q[m->f1AC];
        }
        if (old != 0) {
            for (i = 0; i < old->count; i++) {
                pool2 = m->pool;
                item2 = old->arr[i];
                *(u8 **)((u8 *)item2 + pool2->fC) = pool2->f1C;
                pool2->f1C = (u8 *)item2;
                pool2->f18++;
            }
            old->count = 0;
        }
        m->f1AC = k;
        m->f1A0 = m->f19C;
        m->f199 = 0;
    }
}
/* localdecomp:end func_L39_006DB098 */

INCLUDE_ASM("asm/levels", func_L39_006DB450);

/* localdecomp:start func_L39_006DB5B0 */
typedef struct {
    u8 pad0[0xE4];
    s8 fE4;
    u8 pad1[3];
    s32 fE8;
} S_6DB5B0_B;
typedef struct {
    u8 pad0[0x18];
    s32 f18;
} S_6DB5B0_C;

__asm__(".extern D_L39_0024D760, 16");
/* D_L39_0024D760 is already declared (with .extern size 16) as Obj_006DA090 * in this file.
   Landing: give Obj_006DA090 a field `S_6DB5B0_B *f4C` (split pad18 into pad18[0x34] + f4C) and use p = D_L39_0024D760->f4C. */
/* from rac4-decomp's func_L00_00778848 */
void func_L39_006DB5B0(S_6DB5B0_C *arg0) {
    S_6DB5B0_B *p = *(S_6DB5B0_B **)((u8 *)D_L39_0024D760 + 0x4C);
    p->fE4 = 0;
    p->fE8 = arg0->f18;
}
/* localdecomp:end func_L39_006DB5B0 */

/* localdecomp:start func_L39_006DB5D0 */
typedef struct {
    u16 f00;
    u8 pad02[0x16];
    u32 f18;
    u32 f1C;
    u32 f20;
    u32 f24;
    s32 f28;
    s32 f2C;
} Loc_006DB5D0;
typedef struct {
    u8 pad00[0xEC];
    u8 fEC;
    u8 padED[3];
    s32 fF0;
} Obj_006DB5D0;
typedef struct {
    u8 f00;
    u8 f01;
    u8 pad02[6];
    s32 f08;
    u8 pad0C[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
} P_006DB5D0;
typedef struct {
    u8 pad[0x2DC];
    s32 f2DC;
} G_006DB5D0;

extern void *func_0017FBC8(void *, void *, s32);
extern void func_00195410(void);
extern s32 func_L39_006D8AD8(void *);
extern u8 D_00197D58[];
extern G_006DB5D0 D_001A5CD0_006DB5D0;

s32 func_L39_006DB5D0(Obj_006DB5D0 *o) {
    Loc_006DB5D0 loc;
    P_006DB5D0 *p = (P_006DB5D0 *)D_L39_0024D760;
    s32 ok;

    loc.f00 = D_L39_00249F40[0];
    loc.f18 = 0xFFFFFFFF;
    loc.f1C = 0xFFFFFFFF;
    loc.f20 = 0xFFFFFFFF;
    loc.f24 = 0xFFFFFFFF;
    loc.f28 = 0;
    loc.f2C = 0x20;
    o->fEC = 1;
    p->f01 = 1;
    p->f08 = func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017FBC8(&loc, D_00197D58, 0));
    ok = 1;
    while (o->fEC != 0) {
        if (func_001961F8() != 0 || D_001A5CD0_006DB5D0.f2DC != 0) {
            p->f10 = 0x47;
            if (p->f14 == 0) {
                p->f14 = 0x47;
            }
            ok = 0;
            break;
        }
        p->f1C = 1;
        func_00195410();
        p->f1C = 0;
        if (func_L39_006D8AD8(p) == 0) {
            ok = 0;
            break;
        }
    }
    p->f01 = 0;
    o->fEC = 0;
    if (ok != 0 && o->fF0 != 0) {
        p->f10 = 0x47;
        if (p->f14 == 0) {
            p->f14 = 0x47;
        }
        ok = 0;
    }
    return ok;
}
/* localdecomp:end func_L39_006DB5D0 */

/* localdecomp:start func_L39_006DB730 */
extern Obj_006DA090 *D_L39_0024D760 __attribute__((section(".data")));

void func_L39_006DB730(void *arg0) {
    u8 *temp_v1 = *(u8 **)((u8 *)D_L39_0024D760 + 0x4C);
    *(s8 *)(temp_v1 + 0xEC) = 0;
    *(s32 *)(temp_v1 + 0xF0) = *(s32 *)((u8 *)arg0 + 0x18);
}
/* localdecomp:end func_L39_006DB730 */

/* localdecomp:start func_L39_006DB750 */
typedef struct {
    u16 f00;
    u8 pad02[0x26];
    s32 f28;
    u8 pad2C[4];
} Loc_006DB750;
typedef struct {
    u8 pad00[0xF4];
    u8 fF4;
    u8 padF5[3];
    u8 fF8[0x18];
    s32 f110;
} Obj_006DB750;
typedef struct {
    u8 f00;
    u8 f01;
    u8 pad02[6];
    s32 f08;
    u8 pad0C[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
    u8 pad1D[0x33];
    s32 f50;
} P_006DB750;
typedef struct {
    u8 pad[0x2DC];
    s32 f2DC;
} G_006DB750;

extern s32 func_001206F4(void *, s32);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_0017EB38(void *, void *, s32);
extern void func_001961E8(void *);
extern s32 func_001961F8(void);
extern void func_00195410(void);
extern s32 func_L39_006D8AD8(void *);
extern u16 D_L39_00249F40[];
extern u8 D_00197DA8[];
extern G_006DB750 D_001A5CD0;

void *func_L39_006DB750(Obj_006DB750 *arg0, s32 arg1) {
    Loc_006DB750 loc;
    P_006DB750 *p = (P_006DB750 *)D_L39_0024D760;
    s32 ok;
    s32 x;
    void *r;

    x = p->f50;
    loc.f00 = D_L39_00249F40[0];
    func_001206F4((u8 *)&loc + 0x15, x);
    loc.f28 = arg1;
    arg0->fF4 = 1;
    p->f01 = 1;
    ok = 1;
    p->f08 = func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017EB38(&loc, D_00197DA8, 0));
    while (arg0->fF4 != 0) {
        if (func_001961F8() != 0 || D_001A5CD0.f2DC != 0) {
            p->f10 = 0x4A;
            if (p->f14 == 0) {
                p->f14 = 0x4A;
            }
            ok = 0;
            break;
        }
        p->f1C = 1;
        func_00195410();
        p->f1C = 0;
        if (func_L39_006D8AD8(p) == 0) {
            ok = 0;
            break;
        }
    }
    p->f01 = 0;
    arg0->fF4 = 0;
    r = 0;
    if (ok != 0) {
        r = arg0->f110 != 0 ? 0 : arg0->fF8;
    }
    return r;
}
/* localdecomp:end func_L39_006DB750 */

/* localdecomp:start func_L39_006DB890 */
typedef struct { s32 w[0x19]; } S_006DB890;

void func_L39_006DB890(S_006DB890 *arg0) {
    u8 *obj = *(u8 **)((u8 *)D_L39_0024D760 + 0x4C);
    obj[0xF4] = 0;
    *(S_006DB890 *)(obj + 0xF8) = *arg0;
}
/* localdecomp:end func_L39_006DB890 */

INCLUDE_ASM("asm/levels", func_L39_006DB948);

/* localdecomp:start func_L39_006DBD58 */
typedef struct {
    u8 pad00[0x1C];
    s32 f1C;
    u16 f20;
    u8 pad22[6];
    s32 f28;
    u8 pad2C[0x10];
    u8 f3C[0xB];
    u8 f47[1];
} E_006DBD58;
typedef struct {
    s32 f0;
    s32 f4;
    E_006DBD58 **f8;
} L_006DBD58;
typedef struct {
    u8 pad00[0x1AC];
    s32 f1AC;
    u8 pad1B0[4];
    L_006DBD58 f1B4[1];
} S_006DBD58;

s32 func_00120884(void *);
s32 func_001200E0(void *, void *, s32 *);
extern u8 D_L39_00249F38[];

s32 func_L39_006DBD58(S_006DBD58 *arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    s32 lo = 999999;
    s32 hi = 0;
    s32 mine = 0;
    L_006DBD58 *l;
    s32 i;
    s32 v;
    s32 t;

    *arg2 = 0;
    *arg3 = 0;
    l = 0;
    if (arg0->f1AC >= 0) {
        l = &arg0->f1B4[arg0->f1AC];
    }
    if (l != 0 && l->f4 > 0) {
        for (i = 0; i < l->f4; i++) {
            E_006DBD58 *e = l->f8[i];
            v = -1;
            if (e->f28 == 1) {
                if ((u32)func_00120884(e->f3C) < 13) {
                    t = 0;
                    goto have;
                }
                func_001200E0(e->f47, D_L39_00249F38, &v);
            }
            t = v;
have:
            if (arg1 == e->f1C) {
                mine = t;
            }
            if (t < lo && e->f20 <= 0xDA) {
                lo = t;
            }
            if (hi < t && e->f20 <= 0xDA) {
                hi = t;
            }
        }
    }
    if (lo < mine) {
        *arg2 = 1;
    }
    if (mine < hi) {
        *arg3 = 1;
    }
    return mine;
}
/* localdecomp:end func_L39_006DBD58 */

/* localdecomp:start func_L39_006DBEE0 */
typedef struct {
    u8 pad0[0x1C];
    s32 f1C;
    u16 f20;
    u8 pad22[6];
    s32 f28;
    u8 pad2C[0x10];
    char f3C[0xB];
    char f47[1];
} Item_006DBEE0;
typedef struct {
    s32 f0;
    s32 n;
    Item_006DBEE0 **items;
} Grp_006DBEE0;
typedef struct {
    u8 pad0[0x199];
    u8 f199;
    u8 pad19A[0x12];
    s32 f1AC;
    u8 pad1B0[4];
    Grp_006DBEE0 grp[1];
} S_006DBEE0;
typedef struct {
    char f00[0x40];
    char f40[0x20];
    s32 f60;
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
    s32 f74;
} Src_006DBEE0;

extern s32 func_0011FFA8(char *, s32, const char *, ...);
extern char D_L39_00249F08[];
extern u8 D_L39_00249F38[];
s32 func_L39_006DA3F8();

s32 func_L39_006DBEE0(S_006DBEE0 *a0, s32 a1, s32 *a2) {
    Src_006DBEE0 src;
    s32 r = 0;
    s32 max;
    s32 i;
    s32 x;
    Grp_006DBEE0 *grp;
    Src_006DBEE0 *p;
    s32 n;

    if (a0->f199 == 0) {
        max = -1;
        grp = 0;
        if (a0->f1AC >= 0) {
            grp = &a0->grp[a0->f1AC];
        }
        if (grp != 0 && grp->n > 0) {
            for (i = 0; i < grp->n; i++) {
                Item_006DBEE0 *it = grp->items[i];
                s32 v;
                s32 t;
                if (it->f20 == 0) {
                    *a2 = it->f1C;
                    return 1;
                }
                v = -1;
                if (it->f28 == 1) {
                    if ((u32)func_00120884(it->f3C) < 13) {
                        t = 0;
                        goto have;
                    }
                    func_001200E0(it->f47, D_L39_00249F38, &v);
                }
                t = v;
have:
                if (max < t) {
                    max = t;
                }
            }
            if (max >= 0 && max < 0xFF) {
                x = a1 - 0x28;
                n = max + 1;
                src.f60 = 0xE0;
                p = &src;
                src.f64 = 1;
                src.f40[0] = 0;
                if (x < 32) {
                    src.f68 = (s32)(1L << x);
                    src.f6C = 0;
                    src.f70 = 0;
                } else if (x < 64) {
                    src.f68 = 0;
                    src.f6C = (s32)(1L << (x - 32));
                    src.f70 = 0;
                }
                func_0011FFA8(p->f00, 0x40, D_L39_00249F08, x, n);
                p->f74 = 0x20;
                r = func_L39_006DA3F8(a0, &src, a2);
            }
        } else {
            x = a1;
            x = x - 0x28;
            n = 0;
            src.f60 = 0xE0;
            p = &src;
            src.f64 = 1;
            src.f40[0] = 0;
            if (x < 32) {
                src.f68 = (s32)(1L << x);
                src.f6C = 0;
                src.f70 = 0;
            } else if (x < 64) {
                src.f68 = 0;
                src.f6C = (s32)(1L << (x - 32));
                src.f70 = 0;
            }
            func_0011FFA8(p->f00, 0x40, D_L39_00249F08, x, n);
            p->f74 = 0x20;
            r = func_L39_006DA3F8(a0, &src, a2);
        }
    }
    return r;
}
/* localdecomp:end func_L39_006DBEE0 */

/* localdecomp:start func_L39_006DC148 */
void func_L39_006DB450(s32, s32, s32, s32, s32, s32);

void func_L39_006DC148(s32 arg0, s32 arg1) {
    s32 lo = 0;
    s32 hi = 0;
    arg1 -= 0x28;
    if (arg1 < 32) {
        lo = (s32)(1L << arg1);
    } else if (arg1 < 64) {
        hi = (s32)(1L << (arg1 - 32));
    }
    func_L39_006DB450(arg0, 1, 1, lo, hi, 0);
}
/* localdecomp:end func_L39_006DC148 */
