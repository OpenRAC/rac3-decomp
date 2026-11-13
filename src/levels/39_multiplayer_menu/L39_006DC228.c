#include "common.h"

/* localdecomp:start func_L39_006DC228 */
typedef struct {
    char text[0x40];
    char name[0x20];
    s32 type;
    s32 size;
    s32 min;
    s32 max;
    s32 a;
    s32 c;
    char pad[0x80 - 0x78];
} S_006DC228;
extern char D_L39_00249F18[];
s32 func_0011FFA8(char *, s32, const char *, ...);
s32 func_L39_006DA3F8(s32, S_006DC228 *, s32 *);
s32 func_L39_006DA680(s32, s32, s32);

s32 func_L39_006DC228(s32 arg0, s32 arg1, s32 arg2, s32 *arg3) {
    S_006DC228 req;
    s32 tmp;
    s32 *out;
    s32 ret;
    s32 lo;
    s32 hi;
    lo = arg1 < arg2 ? arg1 : arg2;
    hi = arg1 < arg2 ? arg2 : arg1;
    req.type = 0xE0;
    req.name[0] = 0;
    req.size = 2;
    req.min = lo;
    req.max = hi;
    req.a = 0;
    func_0011FFA8(req.text, 0x40, D_L39_00249F18, lo, hi);
    out = &tmp;
    if (arg3 != 0) {
        out = arg3;
    }
    req.c = 0x20;
    req.type = 0x8A;
    ret = func_L39_006DA3F8(arg0, &req, out);
    if (ret != 0 || *(s32 *)(arg0 + 0xDC) == -0x3CE) {
        ret = func_L39_006DA680(arg0, *out, 0);
    }
    return ret;
}
/* localdecomp:end func_L39_006DC228 */

/* localdecomp:start func_L39_006DC308 */
typedef struct {
    char text[0x40];
    char name[0x20];
    s32 type;
    s32 size;
    s32 value;
    s32 a;
    s32 b;
    s32 c;
    char pad[0x80 - 0x78];
} S_006DC308;
extern char D_L39_00249F28[];
s32 func_0011FFA8(char *, s32, const char *, ...);
s32 func_L39_006DA680(s32, s32, s32);

s32 func_L39_006DC308(s32 arg0, s32 arg1, s32 *arg2) {
    S_006DC308 req;
    s32 tmp;
    s32 *out;
    s32 ret;

    req.type = 0xE0;
    req.size = 4;
    req.value = arg1;
    req.name[0] = 0;
    req.a = 0;
    req.b = 0;
    func_0011FFA8(req.text, 0x40, D_L39_00249F28, arg1);
    out = &tmp;
    if (arg2 != 0) {
        out = arg2;
    }
    req.c = 0x20;
    req.type = 0x4A;
    ret = func_L39_006DA3F8(arg0, (S_006DC228 *)&req, out);
    if (ret != 0 || *(s32 *)(arg0 + 0xDC) == -0x3CE) {
        ret = func_L39_006DA680(arg0, *out, 0);
    }
    return ret;
}
/* localdecomp:end func_L39_006DC308 */

INCLUDE_ASM("asm/levels", func_L39_006DC3D0);

/* localdecomp:start func_L39_006DC788 */
void *func_L39_006DC788(void *arg0) {
    *(s8 *)((u8 *)arg0 + 0x98) = 0;
    *(s8 *)((u8 *)arg0 + 0x99) = 0;
    *(s8 *)((u8 *)arg0 + 0x9A) = 0;
    *(s8 *)((u8 *)arg0 + 0x9B) = 0;
    *(s8 *)((u8 *)arg0 + 0x9C) = 0;
    *(s8 *)((u8 *)arg0 + 0x9D) = 0;
    return arg0;
}
/* localdecomp:end func_L39_006DC788 */

/* localdecomp:start func_L39_006DC7A8 */
void func_L39_006DC7A8(void *arg0) {
    *(s8 *)((u8 *)arg0 + 0x98) = 0;
    *(s8 *)((u8 *)arg0 + 0x99) = 0;
    *(s8 *)((u8 *)arg0 + 0x9A) = 0;
    *(s8 *)((u8 *)arg0 + 0x9B) = 0;
    *(s8 *)((u8 *)arg0 + 0x9C) = 0;
    *(s8 *)((u8 *)arg0 + 0x9D) = 0;
}
/* localdecomp:end func_L39_006DC7A8 */

/* localdecomp:start func_L39_006DC7C8 */
typedef struct {
    u16 f00;
    char _p02[0x18 - 0x02];
    s32 f18;
    char _p1C[0x20 - 0x1C];
} Loc_006DC7C8;
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
} G_006DC7C8;
typedef struct {
    char _p0[0x11];
    u8 f11[0x94 - 0x11];
    s32 f94;
    u8 f98;
    u8 f99;
    char _p9A[0x9C - 0x9A];
    u8 f9C;
    char _p9D[0xB8 - 0x9D];
    s32 fB8;
} S_006DC7C8;
typedef struct {
    char _p0[0x2DC];
    s32 f2DC;
} P_006DC7C8;

__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern u16 D_L39_00249FA0[];
extern u8 D_L39_00249FA8[];
extern u8 D_001A5CD0[];
extern u8 D_001A58C7[];
extern u8 D_00197E70[];
extern u8 D_001980B0[];
s32 func_001206F4(void *, s32);
s32 func_L39_006DCDB8_006DC7C8(S_006DC7C8 *);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
s32 func_0017E370(void *, void *, s32);
s32 func_0017F748(void *, void *, s32);
void func_001961E8(s32);
s32 func_001961F8();
void func_00195410(void);
s32 func_L39_006D8AD8(u8 *);
s32 func_L39_006DCC80(void);
s32 func_00120048(u8 *, u8 *, ...);
s32 func_00183BDC(void);
s32 func_0019B760(void *, void *, s32);
void func_0011D534(void *, s32, s32);

s32 func_L39_006DC7C8(u8 *a0, s32 arg1, char *a2, s32 arg3) {
    S_006DC7C8 *arg0 = (S_006DC7C8 *)a0;
    s32 arg2 = (s32)a2;
    Loc_006DC7C8 loc;
    u8 buf[0x800];
    G_006DC7C8 *g;
    P_006DC7C8 *p;
    s32 r;

    arg0->f98 = arg1;
    if (arg2 != 0) {
        func_001206F4(arg0->f11, arg2);
    }
    if (arg3 != -1) {
        arg0->f94 = arg3;
    }
    g = D_L39_0024D760;
    if (func_L39_006DCDB8_006DC7C8(arg0) == 0) {
        return 0;
    }
    loc.f00 = D_L39_00249FA0[0];
    loc.f18 = 1;
    arg0->f99 = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017E370(&loc, D_00197E70, 0));
    p = (P_006DC7C8 *)D_001A5CD0;
    while (arg0->f99 != 0) {
        if (func_001961F8() != 0 || p->f2DC != 0) {
            g->f10 = 0x4B;
            if (g->f14 == 0) {
                g->f14 = 0x4B;
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
    if (r != 0) {
        if (arg0->fB8 != 0) {
            g->f10 = 0x4B;
            if (g->f14 == 0) {
                g->f14 = 0x4B;
            }
            r = 0;
        }
    }
    if (r != 0) {
        r = ((s32 (*)(S_006DC7C8 *))func_L39_006DCC80)(arg0);
        if (r != 0) {
            func_00120048(buf, D_L39_00249FA8, arg0->f94);
            if (func_0019B760(arg0->f11, buf, func_00183BDC()) != 0) {
                g->f10 = 6;
                if (g->f14 == 0) {
                    g->f14 = 6;
                }
                r = 0;
            }
            if (r != 0) {
                ((void *(*)(void *, s32, s32))func_0011D534)(buf, 0, 0x30);
                *(s32 *)(buf + 0x28) = 2;
                switch (D_001A58C7[0]) {
                case 0:
                    *(s32 *)(buf + 0x2C) = 2;
                    break;
                case 2:
                    *(s32 *)(buf + 0x2C) = 8;
                    break;
                case 3:
                    *(s32 *)(buf + 0x2C) = 7;
                    break;
                case 4:
                    *(s32 *)(buf + 0x2C) = 6;
                    break;
                case 5:
                    *(s32 *)(buf + 0x2C) = 5;
                    break;
                }
                arg0->f9C = 1;
                g->f1 = 1;
                g->f8 = func_00130760(func_0012DCB0(), 0x24000);
                func_001961E8(func_0017F748(buf, D_001980B0, 0));
                while (arg0->f9C != 0) {
                    if (func_001961F8() != 0 || ((P_006DC7C8 *)D_001A5CD0)->f2DC != 0) {
                        g->f10 = 0x51;
                        if (g->f14 == 0) {
                            g->f14 = 0x51;
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
            }
        }
    }
    return r;
}
/* localdecomp:end func_L39_006DC7C8 */

/* localdecomp:start func_L39_006DCAD0 */
typedef struct {
    u16 f00;
    char _p02[0x30 - 0x02];
} Loc_006DCAD0;
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
} G_006DCAD0;
typedef struct {
    char _p0[0x9A];
    u8 f9A;
    char _p9B[0x9D - 0x9B];
    u8 f9D;
    char _p9E[0xE8 - 0x9E];
    s32 fE8;
} S_006DCAD0;
typedef struct {
    char _p0[0x2DC];
    s32 f2DC;
} P_006DCAD0;

s32 func_0019B710(void);
s32 func_0019B778(s32);
s32 func_001206F4(void *, s32);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
s32 func_0017E3E8(void *, void *, s32);
void func_001961E8(s32);
s32 func_001961F8();
void func_00195410(void);
void func_00197E98(void);
s32 func_L39_006D8AD8(u8 *);
void func_L39_006D80F8(void *);
s32 func_L39_006DD340(void *);
extern void *D_001E2050_sda;
extern u16 D_L39_00249FA0[];
extern u8 D_001A5CD0[];

s32 func_L39_006DCAD0(S_006DCAD0 *arg0, s32 arg1) {
    Loc_006DCAD0 loc;
    G_006DCAD0 *g;
    P_006DCAD0 *p;
    s32 r;

    g = D_001E2050_sda;
    if (func_0019B710() != 0 && func_0019B778(1) != 0) {
        g->f10 = 7;
        if (g->f14 == 0) {
            g->f14 = 7;
        }
        return 0;
    }
    loc.f00 = D_L39_00249FA0[0];
    func_001206F4((u8 *)&loc + 0x15, g->f50);
    arg0->f9A = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017E3E8(&loc, func_00197E98, 0));
    p = (P_006DCAD0 *)D_001A5CD0;
    while (arg0->f9A != 0) {
        if (func_001961F8() != 0 || p->f2DC != 0) {
            g->f10 = 0x4C;
            if (g->f14 == 0) {
                g->f14 = 0x4C;
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
    arg0->f9A = 0;
    if (r != 0) {
        if (arg0->fE8 < 0) {
            g->f10 = 0x4C;
            if (g->f14 == 0) {
                g->f14 = 0x4C;
            }
            r = 0;
        }
    }
    if (arg0->f9D != 0) {
        if (func_L39_006DD340(arg0) == 0) {
            r = 0;
        }
    }
    if (arg1 != 0) {
        func_L39_006D80F8(g);
    }
    return r;
}
/* localdecomp:end func_L39_006DCAD0 */

/* localdecomp:start func_L39_006DCC80 */
s32 func_0017DF20();
void func_001961E8(s32);
extern void *D_001E2050_sda;

s32 func_L39_006DCC80(void) {
    s32 temp_v0;
    void *temp_s1;

    temp_s1 = D_001E2050_sda;
    temp_v0 = func_0017DF20();
    func_001961E8(temp_v0);
    if (temp_v0 != 0) {
        *(s32 *)((u8 *)temp_s1 + 0x10) = 0x4D;
        if ((*(s32 *)((u8 *)temp_s1 + 0x14)) == 0) {
            *(s32 *)((u8 *)temp_s1 + 0x14) = 0x4D;
        }
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L39_006DCC80 */

/* localdecomp:start func_L39_006DCCE0 */
typedef struct { u32 words[7]; } S_6DCCE0_Copy;
typedef struct { char pad[0x9a]; u8 flag; char pad2[0x35]; S_6DCCE0_Copy data; } S_6DCCE0_Target;
typedef struct { char pad[0x1d]; u8 flag; char pad2[0x2F]; S_6DCCE0_Target *target; } S_6DCCE0_Owner;
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;

/* from rac4-decomp's func_L00_007797B0 */
void func_L39_006DCCE0(S_6DCCE0_Copy *arg0) {
    S_6DCCE0_Owner *owner = ((S_6DCCE0_Owner *)D_L39_0024D760);
    S_6DCCE0_Target *target = owner->target;
    if (!owner->flag) {
        target->flag = 0;
        target->data = *arg0;
    }
}
/* localdecomp:end func_L39_006DCCE0 */

/* localdecomp:start func_L39_006DCD38 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { int words[12]; } Data_6DCD38;
typedef struct { char pad[0x99]; unsigned char flag; char pad2[6]; Data_6DCD38 data; } Target_6DCD38;
typedef struct { char pad[0x1D]; unsigned char flag; char pad2[0x32]; Target_6DCD38 *target; } Global_6DCD38;

/* from rac4-decomp's func_L00_00779808 */
void func_L39_006DCD38(Data_6DCD38 *arg) {
    Global_6DCD38 *g = ((Global_6DCD38 *)D_L39_0024D760);
    Target_6DCD38 *t = g->target;
    if (!g->flag) {
        t->flag = 0;
        t->data = *arg;
    }
}
/* localdecomp:end func_L39_006DCD38 */

/* localdecomp:start func_L39_006DCDB8 */
typedef struct {
    u8 b[0x40];
} B_006DCDB8;
typedef struct {
    char _p0[0x38];
    B_006DCDB8 f38;
    char _p78[0xF0 - 0x78];
    s32 fF0;
    void *fF4;
    s32 fF8;
    s32 fFC;
} L_006DCDB8;
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
} G_006DCDB8;
typedef struct {
    char _p0[0x94];
    s32 f94;
    u8 f98;
    char _p99[0x9B - 0x99];
    u8 f9B;
    char _p9C[0x9D - 0x9C];
    u8 f9D;
} S_006DCDB8;
typedef struct {
    char _p0[0x2DC];
    s32 f2DC;
} P_006DCDB8;

void func_0017F620(void *, s32, void *, s32, s32);
void func_00183B3C(void *);
void func_0011D534(void *, s32, s32);
s32 func_0017DFE0(void *, void *, s32);
void func_001961E8(s32);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
s32 func_001961F8();
void func_00195410(void);
s32 func_L39_006D8AD8(u8 *);
void func_L39_006D8E80(void *);
void func_L39_006DD028(s32 arg0);
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern u8 D_001A5CD0[];

s32 func_L39_006DCDB8(S_006DCDB8 *arg0) {
    L_006DCDB8 loc;
    B_006DCDB8 tmp;
    s32 res;
    G_006DCDB8 *g;
    s32 r;
    s32 i;

    g = D_L39_0024D760;
    func_0017F620(&loc, 0, (u8 *)arg0 + 0x11, arg0->f94, 1);
    loc.fF0 = 0xFF;
    loc.fF4 = func_L39_006DD028;
    loc.fF8 = 0;
    loc.fFC = 0;
    if (arg0->f98 != 0) {
        func_00183B3C(&tmp);
    } else {
        func_0011D534(&tmp, 0, 0x40);
    }
    loc.f38 = tmp;
    r = 1;
    i = 1;
    while (arg0->f9D == 0 && r != 0) {
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        arg0->f9B = 1;
        func_001961E8(func_0017DFE0(&loc, &res, 0));
        g->f1 = 1;
        g->f8 = func_00130760(func_0012DCB0(), 0x24000);
        while (arg0->f9B != 0) {
            if (func_001961F8() != 0 || ((P_006DCDB8 *)D_001A5CD0)->f2DC != 0) {
                g->f10 = 0x4E;
                if (g->f14 == 0) {
                    g->f14 = 0x4E;
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
        arg0->f9B = 0;
        if (i++ >= 4) {
            break;
        }
    }
    if (r != 0) {
        if (arg0->f9D == 0) {
            g->f10 = 0x4E;
            if (g->f14 == 0) {
                g->f14 = 0x4E;
            }
            r = 0;
        } else {
            g->f10 = 0;
            g->f14 = 0;
            r = 1;
            func_L39_006D8E80(g);
        }
    }
    return r;
}
/* localdecomp:end func_L39_006DCDB8 */

/* localdecomp:start func_L39_006DD028 */
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern u8 D_001A5FB5[];

typedef struct { char pad[0x1D]; u8 flag; char pad2[0x32]; u8 *target; } S_6DD028_Owner;

void func_L39_006DD028(s32 arg0) {
    S_6DD028_Owner *owner = (S_6DD028_Owner *)D_L39_0024D760;
    u8 *target = owner->target;
    if (!owner->flag && arg0) {
        D_001A5FB5[0] = 1;
        target[0x9D] = 1;
        target[0x9B] = 0;
    }
}
/* localdecomp:end func_L39_006DD028 */

/* localdecomp:start func_L39_006DD060 */
typedef struct { s32 words[39]; } Data_006DD060;
typedef struct {
    Data_006DD060 data;
    char _p9C[0xF0 - 0x9C];
    s32 fF0;
    void (*fF4)(s32);
    void (*fF8)(void);
    void (*fFC)(void);
} Loc_006DD060;
typedef struct {
    char _p0[0x14];
    s32 f14;
    char _p18[0x20 - 0x18];
} LocB_006DD060;
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
} G_006DD060;
typedef struct {
    char _p0[0x9B];
    u8 f9B;
    char _p9C[0x9D - 0x9C];
    u8 f9D;
} A_006DD060;
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
void func_0011D534(void *, s32, s32);
s32 func_0017DFE0(void *, void *, s32);
s32 func_0017E310(void *);
void func_L39_006D8E80(void *);
void func_L39_006DD028(s32);
void func_L39_006DD3C0(void);
void func_L39_006DD3C8(void);

s32 func_L39_006DD060(A_006DD060 *arg0, Data_006DD060 *arg1) {
    G_006DD060 *g = (G_006DD060 *)D_L39_0024D760;
    Loc_006DD060 loc;
    char locA[0x10];
    LocB_006DD060 locB;
    P_006DCAD0 *p;
    s32 r;
    s32 tries;

    g->f1C = 1;
    func_00195410();
    g->f1C = 0;
    func_0011D534(&loc, 0, 0x100);
    loc.data = *arg1;
    loc.fF0 = 0xFF;
    loc.fF4 = func_L39_006DD028;
    loc.fF8 = func_L39_006DD3C0;
    loc.fFC = func_L39_006DD3C8;
    r = 1;
    tries = 1;
    while (arg0->f9D == 0) {
        arg0->f9B = 1;
        p = (P_006DCAD0 *)D_001A5CD0;
        g->f1 = 1;
        g->f8 = func_00130760(func_0012DCB0(), 0x24000);
        func_001961E8(func_0017DFE0(&loc, locA, 0));
        while (arg0->f9B != 0) {
            if (func_001961F8() != 0 || p->f2DC != 0) {
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
        arg0->f9B = 0;
        if (tries++ >= 4) {
            break;
        }
    }
    if (r != 0) {
        if (arg0->f9D == 0) {
            g->f10 = 0x4F;
            if (g->f14 == 0) {
                g->f14 = 0x4F;
            }
            r = 0;
        } else {
            g->f10 = 0;
            g->f14 = 0;
            func_L39_006D8E80(g);
        }
        if (r != 0) {
            func_001206F4(&locB, (s32)arg0);
            locB.f14 = 1;
            func_001961E8(func_0017E310(&locB));
            if (func_001961F8() != 0) {
                g->f10 = 4;
                if (g->f14 == 0) {
                    g->f14 = 4;
                }
                r = 0;
            }
        }
    }
    return r;
}
/* localdecomp:end func_L39_006DD060 */

/* localdecomp:start func_L39_006DD340 */
s32 func_0017E140();
s32 func_001961F8();
void func_001961E8(s32);
extern void *D_001E2050_sda;
extern u8 D_001A5FB5[];

s32 func_L39_006DD340(void *arg0) {
    void *temp_s0;
    s32 temp_v0;

    temp_s0 = D_001E2050_sda;
    temp_v0 = func_0017E140();
    func_001961E8(temp_v0);
    temp_v0 = func_001961F8();
    if (temp_v0 != -0x10 && temp_v0 != 0) {
        *(s32 *)((u8 *)temp_s0 + 0x10) = 0x50;
        if (*(s32 *)((u8 *)temp_s0 + 0x14) == 0) {
            *(s32 *)((u8 *)temp_s0 + 0x14) = 0x50;
        }
        return 0;
    }
    D_001A5FB5[0] = 0;
    *(u8 *)((u8 *)arg0 + 0x9D) = 0;
    return 1;
}
/* localdecomp:end func_L39_006DD340 */

/* localdecomp:start func_L39_006DD3C0 */
void func_L39_006DD3C0(void) {

}
/* localdecomp:end func_L39_006DD3C0 */

/* localdecomp:start func_L39_006DD3C8 */
void func_L39_006DD3C8(void) {

}
/* localdecomp:end func_L39_006DD3C8 */

/* localdecomp:start func_L39_006DD3D0 */
typedef struct {
    char pad0[0x10];
    s32 f10;
    s32 f14;
    char pad18[0x38];
    u8 *f50;
} S_6DD3D0;

__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_0077A320 */
s32 func_L39_006DD3D0(void *arg0)
{
    S_6DD3D0 *base = ((S_6DD3D0 *)D_L39_0024D760);
    s32 result = *(s32 *)((u8 *)arg0 + 0x18);
    u8 *target = base->f50;
    if (*(s32 *)((u8 *)arg0 + 0x18)) {
        result = base->f14;
        base->f10 = 0x51;
        if (!result)
            base->f14 = 0x51;
    }
    target[0x9c] = 0;
    return result;
}
/* localdecomp:end func_L39_006DD3D0 */

/* localdecomp:start func_L39_006DD400 */
typedef struct { s8 b0; s8 pad1[0x5F]; s8 b60; s8 pad2[0x2EEB]; s8 b4C; s8 p3[7]; s8 b54; s8 p4[7]; s8 b5C; s8 p5[0x2B]; s8 b88; s8 b89; s8 p6[2]; s32 w8C; s32 w90; s32 w94; } S_006DD400;
void *func_L39_006DD400(S_006DD400 *a) {
    a->b0 = 0;
    a->b60 = 0;
    a->b4C = 0;
    a->b54 = 0;
    a->b5C = 0;
    a->b88 = 0;
    a->b89 = 0;
    a->w8C = -1;
    a->w90 = -1;
    a->w94 = -1;
    return a;
}
/* localdecomp:end func_L39_006DD400 */

/* localdecomp:start func_L39_006DD438 */
typedef struct { s8 b0; s8 pad1[0x5F]; s8 b60; s8 pad2[0x2EEB]; s8 b4C; s8 p3[7]; s8 b54; s8 p4[7]; s8 b5C; s8 p5[0x2B]; s8 b88; s8 b89; s8 p6[2]; s32 w8C; s32 w90; s32 w94; } S_006DD438;
void func_L39_006DD438(S_006DD438 *a) {
a->b0 = 0;
a->b60 = 0;
a->b4C = 0;
a->b54 = 0;
a->b5C = 0;
a->b89 = 0;
a->w8C = -1;
a->w90 = -1;
a->w94 = -1;
}
/* localdecomp:end func_L39_006DD438 */

/* localdecomp:start func_L39_006DD468 */
s32 func_L39_006E16A0(s32, s32, s32, s32);

s32 func_L39_006DD468(void *arg0, s32 arg1) {
    u32 end = (u32)arg0 + func_L39_006E16A0((s32)arg0, arg1 * 2, 0x40C, 4);
    u32 aligned;
    {
        u32 x = end;
        u32 a = 4;
        u32 r = x % a;
        if (r != 0) {
            x += a - r;
        }
        aligned = x;
    }
    end = aligned + arg1 * 8;
    return end - (u32)arg0;
}
/* localdecomp:end func_L39_006DD468 */

/* localdecomp:start func_L39_006DD4D0 */
typedef struct {
    u8 *f0;
    s32 f4;
    s32 f8;
} S_006DD4D0_Q;
typedef struct {
    char _p0[0x2F88];
    u8 b2F88;
    u8 b2F89;
    char _p2F8A[0x2F98 - 0x2F8A];
    s32 n;
    S_006DD4D0_Q q0;
    S_006DD4D0_Q q1;
    s32 f2FB4;
    s32 buf;
} S_006DD4D0;
s32 func_L39_006E16A0(s32, s32, s32, s32);
void func_L39_006E1648(s32, s32, s32, s32);
void func_0011D534(void *, s32, s32);

void func_L39_006DD4D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    S_006DD4D0 *s = (S_006DD4D0 *)arg0;
    u32 p;
    s32 size;
    S_006DD4D0_Q *q0;
    S_006DD4D0_Q *q1;

    if (s->b2F88 == 0) {
        p = arg1;
        s->b2F89 = 0;
        s->n = arg3;
        s->b2F88 = 1;
        size = func_L39_006E16A0(p, arg3 * 2, 0x40C, 4);
        s->f2FB4 = ((s32 (*)(s32, s32, s32, s32))func_L39_006E1648)(p, size, 0x40C, 4);
        p += size;
        {
            u32 x = p;
            u32 m = 4;
            u32 r = x % m;
            if (r != 0) {
                x += m - r;
            }
            p = x;
        }
        s->buf = p;
        func_0011D534((void *)p, 0, s->n * 8);
        q0 = &s->q0;
        q1 = &s->q1;
        q0->f0 = 0;
        q0->f8 = s->buf;
        q0->f4 = 0;
        q1->f0 = 0;
        q1->f8 = s->n * 4 + s->buf;
        q1->f4 = 0;
    }
}
/* localdecomp:end func_L39_006DD4D0 */

/* localdecomp:start func_L39_006DD5B8 */
extern u8 D_001B3331[];

void func_L39_006DD5B8(s32 arg0, u8 *arg1) {
    u8 *p = arg1;
    s32 c;
    s32 r;
    if (*p != 0) {
        do {
            c = *p;
            r = c;
            if (D_001B3331[c] & 2) {
                r = c - 0x20;
            }
            *p = r;
            p++;
        } while (*p != 0);
    }
}
/* localdecomp:end func_L39_006DD5B8 */

LINKER_REMNANT("asm/levels", func_L39_006DD600);

/* localdecomp:start func_L39_006DD608 */
typedef struct {
    u16 f00;
    char _p02[0x28 - 0x02];
    s32 f28;
    u8 f2C[0x70 - 0x2C];
} Loc_006DD608;
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
} G_006DD608;
typedef struct {
    u8 f0;
    char _p1[0x5C - 0x1];
    s32 f5C;
} S_006DD608;
typedef struct {
    char _p0[0x2DC];
    s32 f2DC;
} P_006DD608;

__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern u16 D_L39_0024A010[];
extern u8 D_001A5CD0[];
s32 func_001206F4(void *, s32);
s32 func_00120884(void *);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
s32 func_0017E720(void *, void *, s32);
void func_001961E8(s32);
s32 func_001961F8();
void func_00195410(void);
void func_00197F10(void);
void func_L39_005958A0(void *, void *, s32);
s32 func_L39_006D8AD8(u8 *);

s32 func_L39_006DD608(s32 arg0, void *arg1, s32 arg2) {
    Loc_006DD608 loc;
    S_006DD608 *s = (S_006DD608 *)arg0;
    G_006DD608 *g;
    u8 *dst;

    loc.f00 = D_L39_0024A010[0];
    g = (G_006DD608 *)D_L39_0024D760;
    func_001206F4((u8 *)&loc + 0x15, g->f50);
    dst = loc.f2C;
    loc.f28 = arg2;
    func_L39_005958A0(dst, arg1, func_00120884(arg1));
    s->f0 = 1;
    g->f1 = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017E720(&loc, func_00197F10, 0));
    while (s->f0 != 0) {
        if (func_001961F8() != 0 || ((P_006DD608 *)D_001A5CD0)->f2DC != 0) {
            g->f10 = 0x52;
            if (g->f14 == 0) {
                g->f14 = 0x52;
            }
            return 0;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if (func_L39_006D8AD8((u8 *)g) == 0) {
            return 0;
        }
    }
    g->f1 = 0;
    if (s->f5C == -0x3C6) {
        g->f10 = 3;
        if (g->f14 == 0) {
            g->f14 = 3;
        }
        return 0;
    }
    if (s->f5C == -0x3C7) {
        g->f10 = 0x52;
        if (g->f14 == 0) {
            g->f14 = 0x52;
        }
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L39_006DD608 */

/* localdecomp:start func_L39_006DD770 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct {
    s32 x[0x5C / 4];
} S_006DD770_Blk;
typedef struct {
    u8 b0;
    S_006DD770_Blk blk;
} S_006DD770_St;
typedef struct {
    char _p0[0x1D];
    u8 b1D;
    char _p1E[0x54 - 0x1E];
    S_006DD770_St *f54;
} S_006DD770_G;

void func_L39_006DD770(S_006DD770_Blk *arg0) {
    S_006DD770_G *g = (S_006DD770_G *)D_L39_0024D760;
    S_006DD770_St *st = g->f54;

    if (g->b1D == 0) {
        st->b0 = 0;
        st->blk = *arg0;
    }
}
/* localdecomp:end func_L39_006DD770 */

/* localdecomp:start func_L39_006DD860 */
typedef struct {
    u16 f00;
    char _p02[0x28 - 0x02];
    s32 f28;
    char _p2C[0x40 - 0x2C];
} Loc_006DD860;
typedef struct {
    char _p0[0x10];
    s32 f10;
    s32 f14;
    char _p18[0x50 - 0x18];
    s32 f50;
} G_006DD860;
typedef struct {
    char _p0[0x2F89];
    u8 f2F89;
    u8 f2F8A;
    char _p2F8B;
    s32 f2F8C;
} S_006DD860;

__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern u16 D_L39_0024A010[];
s32 func_0012DCB0(void);
long func_00130760(s32, long);
void func_001961E8(s32);
void func_0014B008(void *);
s32 func_0017F158(void *, void *, s32);
s32 func_0017F0D8(void *, void *, s32);
void func_00197F38(void);

s32 func_L39_006DD860(void *arg0, s32 arg1) {
    S_006DD860 *a = arg0;
    Loc_006DD860 loc;
    G_006DD860 *g;
    s32 r;
    s32 t;

    g = D_L39_0024D760;
    t = g->f50;
    a->f2F89 = 1;
    a->f2F8A = arg1;
    r = 1;
    if (arg1 != 0) {
        loc.f00 = D_L39_0024A010[0];
        func_001206F4((u8 *)&loc + 0x15, t);
        loc.f28 = func_00183BDC();
        a->f2F8C = func_00130760(func_0012DCB0(), 0x24000);
        func_0014B008((u8 *)&loc + 0x30);
        func_001961E8(func_0017F158(&loc, func_00197F38, 0));
    } else {
        loc.f00 = D_L39_0024A010[0];
        func_001206F4((u8 *)&loc + 0x15, t);
        loc.f28 = func_00183BDC();
        a->f2F8C = func_00130760(func_0012DCB0(), 0x24000);
        func_0014B008((u8 *)&loc + 0x34);
        func_001961E8(func_0017F0D8(&loc, func_00197F38, 0));
    }
    if (func_001961F8() != 0) {
        g->f10 = 0x53;
        if (g->f14 == 0) {
            g->f14 = 0x53;
        }
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L39_006DD860 */

/* localdecomp:start func_L39_006DD9B0 */
__asm__(".extern D_L39_0024D760, 16");
extern s32 func_00120B70(u8 *, u8 *, s32);
extern void func_L39_006DE688(u8 *);
extern void func_L39_005958F8(void *, void *, s32);
extern u8 D_L39_0024A018[];

typedef struct { s32 w[0x40C / 4]; } Blk_006DD9B0;
typedef struct {
    char _p0[0x18];
    s32 f18;
    char _p1C[4];
    u8 text[0x3E8];
    char _p408[0x408 - 0x3E8 - 0x20];
    u8 f408;
} A_006DD9B0;
typedef struct {
    s32 (*cmp)(void *, void *);
    s32 count;
    void **arr;
} Heap_006DD9B0;
typedef struct {
    char _p0[0xC];
    s32 off;
    char _p10[8];
    s32 nfree;
    void *head;
} Pool_006DD9B0;
typedef struct {
    char _p0[0x2F88];
    u8 active;
    u8 f2F89;
    char _p2F8A[2];
    s32 f2F8C;
    s32 f2F90;
    s32 cur;
    s32 max;
    Heap_006DD9B0 heaps[2];
    Pool_006DD9B0 *pool;
} St_006DD9B0;
typedef struct {
    char _p0[0x1D];
    u8 b1D;
    char _p1E[0x54 - 0x1E];
    St_006DD9B0 *st;
} G_006DD9B0;

void func_L39_006DD9B0(A_006DD9B0 *arg0) {
    G_006DD9B0 *g = (G_006DD9B0 *)D_L39_0024D760;
    St_006DD9B0 *st = g->st;
    Heap_006DD9B0 *heap;
    Heap_006DD9B0 *old;
    s32 idx;
    s32 i;
    s32 k;
    s32 m;
    s32 j;
    s32 c;
    s32 p;
    s32 d;
    s32 got;
    void *node;
    void *top;
    void *tmp;
    Pool_006DD9B0 *pool;

    if (st->active == 0) {
        return;
    }
    if (g->b1D != 0) {
        return;
    }
    idx = st->cur == 0;
    heap = &st->heaps[idx];
    if (arg0->f18 == 0) {
        if ((u32)func_00120884(arg0->text) >= 0x1A && func_00120B70(arg0->text, D_L39_0024A018, 0x19) == 0) {
            func_L39_006DE688(arg0->text);
        } else {
            if (heap->count < st->max) {
                pool = st->pool;
                node = pool->head;
                if (pool->head != 0) {
                    pool->head = *(void **)((u8 *)node + pool->off);
                    pool->nfree--;
                }
                got = node != 0;
                if (got) {
                    *(Blk_006DD9B0 *)node = *(Blk_006DD9B0 *)arg0;
                    i = func_00120884(arg0->text);
                    if (i >= 1000) {
                        i = 999;
                    }
                    func_L39_005958F8(((A_006DD9B0 *)node)->text, arg0->text, i);
                    i = heap->count++;
                    heap->arr[i] = node;
                    if (heap->cmp != 0) {
                        p = i / 2;
                        while (i > 0 && (u8)heap->cmp(heap->arr[p], heap->arr[i])) {
                            tmp = heap->arr[p];
                            heap->arr[p] = heap->arr[i];
                            heap->arr[i] = tmp;
                            i = p;
                        }
                    }
                }
            }
        }
    }
    if (arg0->f408 == 0) {
        return;
    }
    if (heap->cmp != 0 && heap->count >= 2) {
        for (k = heap->count - 1; k > 0; k--) {
            tmp = heap->arr[k];
            heap->arr[k] = heap->arr[0];
            heap->arr[0] = tmp;
            if (heap->cmp != 0) {
                j = k;
                top = heap->arr[j];
                c = j * 2 + 1;
                if (c < 0) do {
                    d = c + 1;
                    if (d < 0) {
                        if ((u8)heap->cmp(heap->arr[c], heap->arr[d])) {
                            c = d;
                        }
                        if (heap->cmp(top, heap->arr[c]) == 0) {
                            break;
                        }
                        heap->arr[j] = heap->arr[c];
                        j = c;
                        c = j * 2 + 1;
                    }
                } while (c < 0);
                heap->arr[j] = top;
            }
        }
    }
    old = 0;
    if (st->cur >= 0) {
        old = &st->heaps[st->cur];
    }
    if (old != 0) {
        for (m = 0; m < old->count; m++) {
            Pool_006DD9B0 *pl = st->pool;
            void *e = old->arr[m];
            *(void **)((u8 *)e + pl->off) = pl->head;
            pl->head = e;
            pl->nfree++;
        }
        old->count = 0;
    }
    st->cur = idx;
    st->f2F90 = st->f2F8C;
    st->f2F89 = 0;
}
/* localdecomp:end func_L39_006DD9B0 */

/* localdecomp:start func_L39_006DDDE8 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { char pad[0x60]; char a; char pad2[0xb]; char b; } T_6DDDE8;
typedef struct { char pad[0x54]; T_6DDDE8 *p; } S_6DDDE8;

/* from rac4-decomp's func_L00_0077C368 */
void func_L39_006DDDE8(void) {
    T_6DDDE8 *t = ((S_6DDDE8 *)D_L39_0024D760)->p;
    t->a = 0;
    t->b = 0;
}
/* localdecomp:end func_L39_006DDDE8 */

/* localdecomp:start func_L39_006DDE00 */
typedef struct {
    u16 f00;
    char _p02[0x28 - 0x02];
    s32 f28;
    char _p2C[0x30 - 0x2C];
} Loc_006DDE00;
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
} G_006DDE00;
typedef struct {
    char _p0[0x60];
    u8 f60;
    char _p61[0x64 - 0x61];
    s32 f64;
    s32 f68;
    u8 f6C[4];
} S_006DDE00;
typedef struct {
    char _p0[0x2DC];
    s32 f2DC;
} P_006DDE00;

__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern u16 D_L39_0024A010[];
extern u8 D_001A5CD0[];
s32 func_001206F4(void *, s32);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
s32 func_0017EF30(void *, void *, s32);
void func_001961E8(s32);
s32 func_001961F8();
void func_00195410(void);
void func_00197F60(void);
s32 func_L39_006D8AD8(u8 *);

void *func_L39_006DDE00(S_006DDE00 *arg0, s32 arg1) {
    Loc_006DDE00 loc;
    G_006DDE00 *g;
    P_006DDE00 *p;
    s32 r;
    s32 x;
    void *ret;

    g = (G_006DDE00 *)D_L39_0024D760;
    x = g->f50;
    loc.f00 = D_L39_0024A010[0];
    func_001206F4((u8 *)&loc + 0x15, x);
    loc.f28 = arg1;
    arg0->f60 = 1;
    arg0->f68 = 0;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017EF30(&loc, func_00197F60, 0));
    p = (P_006DDE00 *)D_001A5CD0;
    while (arg0->f60 != 0) {
        if (func_001961F8() != 0 || p->f2DC != 0) {
            g->f10 = 0x54;
            if (g->f14 == 0) {
                g->f14 = 0x54;
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
    arg0->f60 = 0;
    ret = 0;
    if (r != 0) {
        if (arg0->f64 == -0x3DD) {
            g->f10 = 0x55;
            if (g->f14 == 0) {
                g->f14 = 0x55;
            }
            r = 0;
        } else if (arg0->f64 != 0) {
            g->f10 = 0x54;
            if (g->f14 == 0) {
                g->f14 = 0x54;
            }
            r = 0;
        }
        ret = r != 0 ? arg0->f6C : 0;
    }
    return ret;
}
/* localdecomp:end func_L39_006DDE00 */

/* localdecomp:start func_L39_006DDF78 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { char pad[0x60]; char a; char pad2[3]; s32 v; s32 len; char text[1]; } T_006DDF78;
typedef struct { char pad[0x54]; T_006DDF78 *p; } S_006DDF78;
typedef struct { char pad[0x18]; s32 v; char text[0x100]; u8 end; } A_006DDF78;
extern void *D_L39_0024D760;
void func_L39_005958F8(void *, void *, s32);
s32 func_00120884(void *);

void func_L39_006DDF78(A_006DDF78 *arg0) {
    s32 v = arg0->v;
    T_006DDF78 *t = ((S_006DDF78 *)D_L39_0024D760)->p;
    t->v = v;
    if (v != 0) {
        t->text[0] = 0;
    } else {
        func_L39_005958F8(&t->text[t->len], arg0->text, 0x100);
        if (arg0->end == 0) {
            t->len += func_00120884(arg0->text);
            return;
        }
    }
    t->a = 0;
}
/* localdecomp:end func_L39_006DDF78 */

/* localdecomp:start func_L39_006DE010 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { char pad[0x2f4c]; char flag; char pad2[3]; int val; } T_006DE010;
typedef struct { char pad[0x54]; T_006DE010 *p; } S_006DE010;

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006DE010(char *arg0) {
    T_006DE010 *t = ((S_006DE010 *)D_L39_0024D760)->p;
    t->flag = 0;
    t->val = *(int *)(arg0 + 0x18);
}
/* localdecomp:end func_L39_006DE010 */

/* localdecomp:start func_L39_006DE030 */
typedef struct {
    u16 f00;
    char _p02[0x28 - 0x02];
    s32 f28;
    char _p2C[0x30 - 0x2C];
} Loc_006DE030;
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
} G_006DE030;
typedef struct {
    char _p0[0x2F54];
    u8 f2F54;
    char _p2F55[0x2F58 - 0x2F55];
    u32 f2F58;
} S_006DE030;

s32 func_0017F590(void *, void *, s32);
void func_00197EC0(void);
extern u16 D_L39_0024A010[];
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;

s32 func_L39_006DE030(S_006DE030 *arg0) {
    Loc_006DE030 loc;
    G_006DE030 *g;
    P_006DCAD0 *p;
    s32 r;
    s32 t;

    g = D_L39_0024D760;
    t = g->f50;
    loc.f00 = D_L39_0024A010[0];
    func_001206F4((u8 *)&loc + 0x15, t);
    loc.f28 = 0;
    arg0->f2F54 = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017F590(&loc, func_00197EC0, 0));
    p = (P_006DCAD0 *)D_001A5CD0;
    while (arg0->f2F54 != 0) {
        if (func_001961F8() != 0 || p->f2DC != 0) {
            g->f10 = 0x57;
            if (g->f14 == 0) {
                g->f14 = 0x57;
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
    arg0->f2F54 = 0;
    if (r != 0) {
        if (arg0->f2F58 >= 2) {
            g->f10 = 0x57;
            if (g->f14 == 0) {
                g->f14 = 0x57;
            }
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006DE030 */

/* localdecomp:start func_L39_006DE180 */
typedef struct {
    u16 f00;
    char _p02[0x28 - 0x02];
    s32 f28;
    char _p2C[0x30 - 0x2C];
} Loc_006DE180;
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
} G_006DE180;
typedef struct {
    char _p0[0x2F54];
    u8 f2F54;
    char _p2F55[0x2F58 - 0x2F55];
    u32 f2F58;
} S_006DE180;

s32 func_0017F590(void *, void *, s32);
void func_00197EC0(void);
extern u16 D_L39_0024A010[];
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;

s32 func_L39_006DE180(S_006DE180 *arg0) {
    Loc_006DE180 loc;
    G_006DE180 *g;
    P_006DCAD0 *p;
    s32 r;
    s32 t;

    g = D_L39_0024D760;
    t = g->f50;
    loc.f00 = D_L39_0024A010[0];
    func_001206F4((u8 *)&loc + 0x15, t);
    loc.f28 = 1;
    arg0->f2F54 = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017F590(&loc, func_00197EC0, 0));
    p = (P_006DCAD0 *)D_001A5CD0;
    while (arg0->f2F54 != 0) {
        if (func_001961F8() != 0 || p->f2DC != 0) {
            g->f10 = 0x58;
            if (g->f14 == 0) {
                g->f14 = 0x58;
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
    arg0->f2F54 = 0;
    if (r != 0) {
        if (arg0->f2F58 >= 2) {
            g->f10 = 0x58;
            if (g->f14 == 0) {
                g->f14 = 0x58;
            }
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006DE180 */

/* localdecomp:start func_L39_006DE2D0 */
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_0077C700 */
void func_L39_006DE2D0(void *arg0) {
    void *temp_v1;
    temp_v1 = (*(void **)((u8 *)D_L39_0024D760 + 0x54));
    (*(s8 *)((u8 *)(temp_v1) + 0x2f54)) = 0;
    (*(s32 *)((u8 *)(temp_v1) + 0x2f58)) = (s32) (*(s32 *)((u8 *)(arg0) + 0x18));
}
/* localdecomp:end func_L39_006DE2D0 */

/* localdecomp:start func_L39_006DE2F0 */
s32 func_12DCB0(void *);
long func_130760(void *, long);
s32 func_L39_006DD860(void *, s32);

s32 func_L39_006DE2F0(void *arg0) {
    s32 ret = 1;
    s32 t;

    if (*(u8 *)((u8 *)arg0 + 0x2F88) != 0) {
        if (*(u8 *)((u8 *)arg0 + 0x2F89) != 0) {
            s32 p = func_12DCB0(arg0);

            t = func_130760((void *)p, 0x24000);
            if ((t - *(s32 *)((u8 *)arg0 + 0x2F8C)) >= 0x3A99) {
                *(u8 *)((u8 *)arg0 + 0x2F89) = 0;
                ret = 0;
                func_L39_006DD860(arg0, *(u8 *)((u8 *)arg0 + 0x2F8A));
            }
        }
    }
    return ret;
}
/* localdecomp:end func_L39_006DE2F0 */

/* localdecomp:start func_L39_006DE380 */
typedef struct {
    u16 f00;
    char _p02[0x28 - 0x02];
    s32 f28;
    s32 f2C;
} Loc_006DE380;
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
} G_006DE380;
typedef struct {
    char _p0[0x2F5C];
    u8 f2F5C;
    char _p2F5D[0x2F60 - 0x2F5D];
    u8 f2F60[0x18];
    s32 f2F78;
} S_006DE380;
typedef struct {
    char _p0[0x2DC];
    s32 f2DC;
} P_006DE380;

__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern u16 D_L39_0024A010[];
extern u8 D_001A5CD0[];
s32 func_001206F4(void *, s32);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
s32 func_0017F3E0(void *, void *, s32);
void func_001961E8(s32);
s32 func_001961F8();
void func_00195410(void);
void func_00197EE8(void);
s32 func_L39_006D8AD8(u8 *);

void *func_L39_006DE380(S_006DE380 *arg0, s32 arg1, s32 arg2) {
    Loc_006DE380 loc;
    G_006DE380 *g;
    P_006DE380 *p;
    s32 r;
    s32 x;

    g = (G_006DE380 *)D_L39_0024D760;
    x = g->f50;
    loc.f00 = D_L39_0024A010[0];
    func_001206F4((u8 *)&loc + 0x15, x);
    loc.f28 = arg2;
    loc.f2C = arg1;
    arg0->f2F5C = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017F3E0(&loc, func_00197EE8, 0));
    p = (P_006DE380 *)D_001A5CD0;
    while (arg0->f2F5C != 0) {
        if (func_001961F8() != 0 || p->f2DC != 0) {
            g->f10 = 0x59;
            if (g->f14 == 0) {
                g->f14 = 0x59;
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
    arg0->f2F5C = 0;
    if (r != 0) {
        if (arg0->f2F78 != 0) {
            g->f10 = 0x59;
            if (g->f14 == 0) {
                g->f14 = 0x59;
            }
            r = 0;
        }
    }
    return r != 0 ? arg0->f2F60 : 0;
}
/* localdecomp:end func_L39_006DE380 */

/* localdecomp:start func_L39_006DE4E0 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { unsigned long x[5]; } __attribute__((packed)) Block_6DE4E0;

/* from rac4-decomp's func_L00_0077C7B0 */
void func_L39_006DE4E0(Block_6DE4E0 *arg0) {
    unsigned char *state = *(unsigned char **)((unsigned char *)D_L39_0024D760 + 0x54);
    state[0x2F5C] = 0;
    *(Block_6DE4E0 *)(state + 0x2F60) = *arg0;
}
/* localdecomp:end func_L39_006DE4E0 */

INCLUDE_ASM("asm/levels", func_L39_006DE548);

/* localdecomp:start func_L39_006DE688 */
void func_L39_006DE8D8(s32 arg0, s32 arg1);

void func_L39_006DE688(u8 *s) {
    u8 key[0x100];
    u8 val[0x100];
    u8 *p;
    u8 *q;
    s32 n;
    s32 m;

    p = s + 0x19;
    q = p;
    do {
        n = 0;
        while (p - s < 1000 && (*p == ' ' || *p == '\n' || *p == '\t')) {
            p++;
        }
        for (; q - s < 1000 && *q != 0; q++) {
            if (*q == '=' || *q == ' ' || *q == '\t') {
                n = q - p;
                if (n >= 0x100) {
                    n = 0xFF;
                }
                func_L39_005958F8(key, p, n);
                key[n] = 0;
                while (q - s < 1000 && (*q == ' ' || *q == '=' || *q == '\t')) {
                    q++;
                }
                p = q;
                break;
            }
        }
        if (n == 0) {
            return;
        }
        m = 0;
        for (; p - s < 1000 && *p != 0; p++) {
            if (*p == '\n' || p - s == 999) {
                m = p - q;
                if (m >= 0x100) {
                    m = 0xFF;
                }
                func_L39_005958F8(val, q, m);
                val[m] = 0;
                func_L39_006DE8D8((s32)key, (s32)val);
                while (p - s < 1000 && (*p == ' ' || *p == '\n')) {
                    p++;
                }
                q = p;
                break;
            }
        }
    } while (m != 0);
}
/* localdecomp:end func_L39_006DE688 */

/* localdecomp:start func_L39_006DE8D8 */
s32 func_001205B0(s32, s32);
s32 func_L39_0057D548(s32, s32);
void func_L39_00672470(s32, s32);
s32 func_L39_006E1478(s32, s32);
extern u8 D_L39_0024A038[];

void func_L39_006DE8D8(s32 arg0, s32 arg1) {
    if ((func_001205B0(arg0, (s32) D_L39_0024A038) != 0) && (func_L39_006E1478(arg0, arg1) == 0) && (func_L39_0057D548(arg0, arg1) == 0)) {
        func_L39_00672470(arg0, arg1);
    }
}
/* localdecomp:end func_L39_006DE8D8 */

/* localdecomp:start func_L39_006DE948 */
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;

typedef struct { s32 words[0xAC / 4]; } S_006DE948_Data;
typedef struct { char pad[0x54]; u8 *p; } S_006DE948_Owner;

void func_L39_006DE948(S_006DE948_Data *arg0) {
    u8 *target = ((S_006DE948_Owner *)D_L39_0024D760)->p;
    target[0x2FBC] = 0;
    *(s32 *)(target + 0x2FC0) = *(s32 *)((u8 *)arg0 + 0xAC);
    *(S_006DE948_Data *)(target + 0x2FF0) = *arg0;
}
/* localdecomp:end func_L39_006DE948 */

/* localdecomp:start func_L39_006DEA18 */
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;

typedef struct { char pad[0x54]; u8 *p; } S_6DEA18_Owner;

void func_L39_006DEA18(void *arg0) {
    u8 *owner = (u8 *)arg0;
    u8 *target = ((S_6DEA18_Owner *)D_L39_0024D760)->p;
    *(s32 *)(target + 0x2FD4) = *(s32 *)(owner + 0x1E0);
    if (*(s32 *)(owner + 0x1DC) == 3 || *(s32 *)(owner + 0x1E0) != 0) {
        target[0x2FD0] = 0;
    }
}
/* localdecomp:end func_L39_006DEA18 */

/* localdecomp:start func_L39_006DEA58 */
typedef struct {
    u8 pad0[0x2FD8];
    s8 f2FD8;
    u8 pad1[3];
    s32 f2FDC;
} S_6DEA58_B;
typedef struct {
    u8 pad0[0xAC];
    s32 fAC;
} S_6DEA58_C;
typedef struct {
    u8 pad0[0x54];
    S_6DEA58_B *f54;
} S_6DEA58_A;
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006DEA58(S_6DEA58_C *arg0) {
    S_6DEA58_B *p = ((S_6DEA58_A *)D_L39_0024D760)->f54;
    p->f2FD8 = 0;
    p->f2FDC = arg0->fAC;
}
/* localdecomp:end func_L39_006DEA58 */

/* localdecomp:start func_L39_006DEA78 */
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;

typedef struct { char pad[0x54]; void *target; } S_006DEA78_Owner;

void func_L39_006DEA78(void *arg0) {
    S_006DEA78_Owner *owner = (S_006DEA78_Owner *)D_L39_0024D760;
    u8 *target = owner->target;
    *(u8 *)(target + 0x2FC4) = 0;
    *(s32 *)(target + 0x2FC8) = *(s32 *)((u8 *)arg0 + 0x1C0);
    *(s32 *)(target + 0x2FCC) = *(s32 *)((u8 *)arg0 + 0x98);
}
/* localdecomp:end func_L39_006DEA78 */

/* localdecomp:start func_L39_006DEAA0 */
typedef struct {
    u8 pad0[0x2fe0];
    s8 f2FE0;
    u8 pad1[0x2fe4 - 0x2fe0 - 1];
    s32 f2FE4;
} S_006DEAA0_B;
typedef struct {
    s32 f0;
} S_006DEAA0_C;
typedef struct {
    u8 pad0[0x54];
    S_006DEAA0_B *f54;
} S_006DEAA0_A;
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006DEAA0(S_006DEAA0_C *arg0) {
    S_006DEAA0_B *p = ((S_006DEAA0_A *)D_L39_0024D760)->f54;
    p->f2FE0 = 0;
    p->f2FE4 = arg0->f0;
}
/* localdecomp:end func_L39_006DEAA0 */

/* localdecomp:start func_L39_006DEAC0 */
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
typedef struct { char pad[0x54]; u8 *p; } S_006DEAC0_Owner;

void func_L39_006DEAC0(u8 *arg0) {
    u8 *t = ((S_006DEAC0_Owner *)D_L39_0024D760)->p;
    s32 i;
    *(s32 *)(t + 0x2FEC) = *(s32 *)(arg0 + 0x1E0);
    for (i = 0; i < *(s32 *)(arg0 + 0x1D4); i++) {
        if (*(s32 *)(t + 0x30A0) < *(s32 *)(t + 0x30A4)) {
            (*(u8 **)(t + 0x309C))[*(s32 *)(t + 0x30A0)] = arg0[(*(s32 *)(arg0 + 0x1D0) + i) % 0x1D0];
        }
        *(s32 *)(t + 0x30A0) += 1;
    }
    if (*(s32 *)(arg0 + 0x1DC) == 3 || *(s32 *)(arg0 + 0x1E0) != 0) {
        t[0x2FE8] = 0;
    }
}
/* localdecomp:end func_L39_006DEAC0 */

INCLUDE_ASM("asm/levels", func_L39_006DEB68);

INCLUDE_ASM("asm/levels", func_L39_006DEDF8);

/* localdecomp:start func_L39_006DF018 */
typedef struct { s32 words[13]; } C_006DF018;
typedef struct { char pad[0x18]; s32 busy; char pad2[0x2C]; C_006DF018 data; } R_006DF018;
typedef struct { char pad[0x30]; s32 *id; char pad2[0x14]; void *list; } G_006DF018;
typedef struct { char pad[0x88]; f32 a[4]; f32 b[4]; } P_006DF018;
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern C_006DF018 D_001A5D58;
extern f32 D_001A6950[];
extern R_006DF018 *func_L39_006D9328(void *, s32);

void func_L39_006DF018(void) {
    G_006DF018 *g = (G_006DF018 *)D_L39_0024D760;
    R_006DF018 *r = func_L39_006D9328(g->list, *g->id);
    P_006DF018 *p;
    s32 i;

    if (r != 0 && r->busy == 0) {
        D_001A5D58 = r->data;
        p = (P_006DF018 *)D_001A5CD0;
        for (i = 0; i < 4; i++) {
            if (p->a[i] <= 0.0f) {
                p->a[i] = D_001A6950[0xE0 / 4];
                p->b[i] = D_001A6950[0xDC / 4];
            }
        }
    }
}
/* localdecomp:end func_L39_006DF018 */

/* localdecomp:start func_L39_006DF118 */
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern u8 D_001DE9D4_sda;
s32 func_L39_006CEA18(void *, s32);
s32 func_L39_006D08E8(void *);

typedef struct { char pad[0x34]; u8 flag; } S_6DF118_Target;
typedef struct { char pad[0x38]; S_6DF118_Target *target; } S_6DF118_Owner;

void func_L39_006DF118(void) {
    S_6DF118_Owner *owner = (S_6DF118_Owner *)D_L39_0024D760;
    S_6DF118_Target *target = owner->target;
    func_L39_006CEA18(target, 0);
    if (target->flag != 0) {
        func_L39_006D08E8(target);
        D_001DE9D4_sda = 1;
    }
}
/* localdecomp:end func_L39_006DF118 */

INCLUDE_ASM("asm/levels", func_L39_006DF168);

/* localdecomp:start func_L39_006DF450 */
extern u8 D_1A6950[];

void func_L39_006DF450(s32 *a0, s32 a1, s32 a2, s32 a3) {
    s32 v;
    f32 f0;
    f32 f1;
    f32 f2;
    u8 *p;

    p = D_1A6950;
    f2 = (f32)a0[a2];
    if (*(f32 *)(p + 0xD0) < f2) {
        v = a0[a3];
        if (v > 0) {
            f1 = (f32)a0[11];
            if (*(f32 *)(p + 0xEC) <= f1) {
                f0 = *(f32 *)(p + 0xD4);
                f1 = (f32)v;
                a0[a1] = (s32)(f0 * f2 / f1);
                return;
            }
        }
    }
    a0[a1] = 0;
}
/* localdecomp:end func_L39_006DF450 */

/* localdecomp:start func_L39_006DF4E8 */
extern f32 D_001A6950[];

void func_L39_006DF4E8(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 v6 = arg0[arg2];
    s32 v7 = arg0[arg3];

    if (D_001A6950[52] < (f32)(v6 + v7)) {
        if (v7 > 0 && D_001A6950[59] <= (f32)arg0[11]) {
            arg0[arg1] = (s32)(D_001A6950[53] * (f32)v6 / (f32)v7);
            return;
        }
    }
    arg0[arg1] = 0;
}
/* localdecomp:end func_L39_006DF4E8 */

/* localdecomp:start func_L39_006DF598 */
extern f32 D_001A6950[];

s32 func_L39_006DF598(f32 arg0, f32 arg1) {
    s32 lo;
    s32 hi;
    lo = 1;
    if (arg1 <= D_001A6950[0x114 / 4]) {
        if (!(arg0 <= D_001A6950[0x120 / 4])) {
            if (arg0 <= D_001A6950[0x124 / 4]) {
                lo = 2;
            } else if (arg0 <= D_001A6950[0x128 / 4]) {
                lo = 3;
            } else {
                lo = 4;
            }
        }
        hi = 1;
        if (arg1 <= D_001A6950[0x11C / 4]) {
            hi = 3;
        } else if (arg1 <= D_001A6950[0x118 / 4]) {
            hi = 2;
        }
        if (hi >= lo) {
            lo = hi;
        }
    } else {
        lo = 1;
    }
    return lo;
}
/* localdecomp:end func_L39_006DF598 */

/* localdecomp:start func_L39_006DF640 */
typedef struct {
    char pad[0x98];
    s32 x;
    s32 y;
    char pad2[0xA4 - 0xA0];
} E_006DF640;
typedef struct {
    char pad[0x120];
    s32 sel[34];
    s32 cur;
    char pad2[0x2E8 - 0x1AC];
    E_006DF640 ent[8];
} S_006DF640;
typedef struct { s32 id; char pad[0x30]; u8 on; } A_006DF640;
typedef struct { char pad[0x38]; A_006DF640 *a; char pad2[8]; s32 h; } G_006DF640;
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern S_006DF640 D_001FD7E8_006DF640;
extern s32 func_L39_006D6E50(s32, s32, s32, s32 *);
extern void func_L39_006D6E30(s32, s32, s32 *);
extern void func_L39_006DF4E8(s32 *arg0, s32 arg1, s32 arg2, s32 arg3);

void func_L39_006DF640(s32 arg0) {
    G_006DF640 *g = (G_006DF640 *)D_L39_0024D760;
    A_006DF640 *a = g->a;
    s32 buf[100];
    s32 h;
    s32 sel;
    s32 same;
    s32 other;

    if (a->on) {
        h = g->h;
        if (func_L39_006D6E50(h, a->id, 1, buf)) {
            same = 0;
            sel = D_001FD7E8_006DF640.sel[arg0];
            other = 0;
            if (D_001FD7E8_006DF640.cur != -1) {
                if (D_001FD7E8_006DF640.cur == sel) {
                    same = 1;
                    other = 0;
                } else {
                    same = 0;
                    other = 1;
                }
            }
            buf[0] += D_001FD7E8_006DF640.ent[sel].x;
            buf[1] += D_001FD7E8_006DF640.ent[sel].y;
            func_L39_006DF4E8(buf, 16, 0, 1);
            buf[2] += same;
            buf[3] += other;
            func_L39_006DF4E8(buf, 15, 2, 3);
            func_L39_006D6E30(h, 1, buf);
        }
    }
}
/* localdecomp:end func_L39_006DF640 */

INCLUDE_ASM("asm/levels", func_L39_006DF760);

/* localdecomp:start func_L39_006E0150 */
typedef struct {
    s32 ids[8];
    f32 a[8];
    f32 b[8];
    char pad[0x8C - 0x60];
    s32 count;
    char pad2[0xA4 - 0x90];
} S_006E0150_Ent;
typedef struct {
    char pad[0x100];
    s32 active[8];
    char pad2[0x2E8 - 0x120];
    S_006E0150_Ent ent[8];
} S_006E0150;
extern S_006E0150 D_001FD7E8;

void func_L39_006E0150(s32 *total, s32 *num, s32 *key, s32 *out) {
    s32 i;
    s32 j;

    for (i = 0; i < 8; i++) {
        if (D_001FD7E8.active[i] != 0 && *key == -1) {
            *key = i;
        }
        if (D_001FD7E8.ent[i].count > 0) {
            *total += D_001FD7E8.ent[i].count;
            (*num)++;
        }
    }
    for (i = 0; i < 8; i++) {
        for (j = 0; j < D_001FD7E8.ent[i].count; j++) {
            if (D_001FD7E8.ent[i].ids[j] == *key) {
                *out = j;
                break;
            }
        }
    }
}
/* localdecomp:end func_L39_006E0150 */

/* localdecomp:start func_L39_006E0220 */
extern u8 D_L39_001A5D8D[];
extern u8 D_L39_001A6950[];

s32 func_L39_006E0220(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_a3 = 0;
    f32 *p;

    if (D_L39_001A5D8D[0] != 0) {
        if (arg0 >= 2) {
            temp_a3 = arg1 >= 2;
        }
    }
    arg1 = temp_a3;
    if (arg1 != 0) {
        p = (f32 *)D_L39_001A6950;
        if (p[0x110 / 4] <= 0.0f) {
            arg1 = 0;
        } else if (arg2 >= 2) {
            if (p[0x10C / 4] <= 0.0f) {
                arg1 = 0;
            }
        }
    }
    return arg1;
}
/* localdecomp:end func_L39_006E0220 */
