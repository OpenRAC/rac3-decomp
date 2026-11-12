#include "common.h"

/* localdecomp:start func_L39_006D5208 */
typedef struct {
    s8 f0;
    u8 pad1[7];
    s8 f8;
    u8 pad9[7];
    s8 f10;
    u8 pad11[3];
    s32 f14;
    s32 f18;
    s8 f1C;
    u8 pad1D[3];
    s32 f20;
    s32 f24;
} S_006D5208;
void func_L39_006D5208(s32 arg0) {
    S_006D5208 *p = (S_006D5208 *)arg0;
    p->f0 = 0;
    p->f8 = 0;
    p->f10 = 0;
    p->f14 = 10000;
    p->f18 = -1;
    p->f1C = 0;
    p->f24 = p->f20 = -1;
}
/* localdecomp:end func_L39_006D5208 */

INCLUDE_ASM("asm/levels", func_L39_006D5238);

/* localdecomp:start func_L39_006D52D0 */
typedef struct {
    u8 f0;
    u8 pad1[3];
    s32 f4;
} S_006D52D0;
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
    u8 pad1D[0x50 - 0x1D];
    s32 f50;
} G_006D52D0;
typedef struct {
    u16 f0;
    u8 pad2[0x26];
    s32 f28;
    s32 f2C;
    s32 f30;
} Loc_006D52D0;
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern u16 D_L39_00249CE8[];
extern u8 D_00197BC8[];
extern u8 D_001A5CD0[];
s32 func_001206F4(void *, s32);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
s32 func_0017F1D8(void *, void *, s32);
void func_001961E8(s32);
s32 func_001961F8(void);
void func_00195410(void);
s32 func_L39_006D8AD8(u8 *);

s32 func_L39_006D52D0(S_006D52D0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Loc_006D52D0 loc;
    G_006D52D0 *g;
    u8 *p;
    s32 r;

    g = D_L39_0024D760;
    loc.f0 = D_L39_00249CE8[0];
    func_001206F4((u8 *)&loc + 0x15, g->f50);
    loc.f28 = arg1;
    loc.f2C = arg2;
    loc.f30 = arg3;
    arg0->f0 = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017F1D8(&loc, D_00197BC8, 0));
    p = D_001A5CD0;
    while (arg0->f0 != 0) {
        if (func_001961F8() != 0 || *(s32 *)(p + 0x2DC) != 0) {
            g->f10 = 0x36;
            if (g->f14 == 0) {
                g->f14 = 0x36;
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
    arg0->f0 = 0;
    if (r != 0) {
        if (arg0->f4 != 0) {
            g->f10 = 0x46;
            if (g->f14 == 0) {
                g->f14 = 0x46;
            }
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006D52D0 */

/* localdecomp:start func_L39_006D5440 */
typedef struct {
    s8 f0;
    u8 pad1[3];
    s32 f4;
} S_6D5440_B;
typedef struct {
    u8 pad0[0x18];
    s32 f18;
} S_6D5440_C;
typedef struct {
    u8 pad0[0x70];
    S_6D5440_B *f70;
} S_6D5440_A;
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006D5440(S_6D5440_C *arg0) {
    S_6D5440_B *p = ((S_6D5440_A *)D_L39_0024D760)->f70;
    p->f0 = 0;
    p->f4 = arg0->f18;
}
/* localdecomp:end func_L39_006D5440 */

/* localdecomp:start func_L39_006D5460 */
typedef struct {
    u8 pad0[8];
    u8 f8;
    u8 pad9[3];
    s32 fC;
} S_006D5460;
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
    u8 pad1D[0x50 - 0x1D];
    s32 f50;
} G_006D5460;
typedef struct {
    u16 f0;
    u8 pad2[0x26];
    s32 f28;
} Loc_006D5460;
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern u16 D_L39_00249CE8[];
extern u8 D_00197B78[];
extern u8 D_001A5CD0[];
s32 func_001206F4(void *, s32);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
s32 func_0017F258(void *, void *, s32);
void func_001961E8(s32);
s32 func_001961F8(void);
void func_00195410(void);
s32 func_L39_006D8AD8(u8 *);

s32 func_L39_006D5460(S_006D5460 *arg0, s32 arg1) {
    Loc_006D5460 loc;
    G_006D5460 *g;
    u8 *p;
    s32 r;

    g = D_L39_0024D760;
    loc.f0 = D_L39_00249CE8[0];
    func_001206F4((u8 *)&loc + 0x15, g->f50);
    loc.f28 = arg1;
    arg0->f8 = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017F258(&loc, D_00197B78, 0));
    p = D_001A5CD0;
    while (arg0->f8 != 0) {
        if (func_001961F8() != 0 || *(s32 *)(p + 0x2DC) != 0) {
            g->f10 = 0x37;
            if (g->f14 == 0) {
                g->f14 = 0x37;
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
    arg0->f8 = 0;
    if (r != 0) {
        if (arg0->fC != -0x3D4 && arg0->fC != 0) {
            g->f10 = 0x47;
            if (g->f14 == 0) {
                g->f14 = 0x47;
            }
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006D5460 */

/* localdecomp:start func_L39_006D55C0 */
typedef struct {
    u8 pad0[8];
    s8 f8;
    u8 pad1[0xc - 8 - 1];
    s32 fC;
} S_006D55C0_B;
typedef struct {
    u8 pad0[0x18];
    s32 f18;
} S_006D55C0_C;
typedef struct {
    u8 pad0[0x70];
    S_006D55C0_B *f70;
} S_006D55C0_A;
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006D55C0(S_006D55C0_C *arg0) {
    S_006D55C0_B *p = ((S_006D55C0_A *)D_L39_0024D760)->f70;
    p->f8 = 0;
    p->fC = arg0->f18;
}
/* localdecomp:end func_L39_006D55C0 */

INCLUDE_ASM("asm/levels", func_L39_006D55E0);

/* localdecomp:start func_L39_006D59D8 */
s32 func_0012DCB0(void);
long func_00130760(s32, long);
s32 func_L39_006D5AB8(u8 *);

s32 func_L39_006D59D8(void *arg0) {
    s32 ret = 1;

    if (*(u8 *)((u8 *)arg0 + 0x1C) == 0) {
        if (*(u8 *)((u8 *)arg0 + 0x10) != 0) {
            s32 now = func_00130760(func_0012DCB0(), 0x24000);
            s32 t = *(s32 *)((u8 *)arg0 + 0x20);
            s32 ok = 1;
            if (t >= 0 && now - t < *(s32 *)((u8 *)arg0 + 0x14)) {
                ok = 0;
            }
            if (ok) {
                ret = func_L39_006D5AB8((u8 *)arg0);
            }
        }
    } else {
        s32 now = func_00130760(func_0012DCB0(), 0x24000);
        if (now - *(s32 *)((u8 *)arg0 + 0x20) >= 15001) {
            *(u8 *)((u8 *)arg0 + 0x1C) = 0;
            ret = 0;
            func_L39_006D5AB8((u8 *)arg0);
        }
    }
    return ret;
}
/* localdecomp:end func_L39_006D59D8 */

/* localdecomp:start func_L39_006D5AB8 */
typedef struct {
    u16 f0;
    u8 pad2[0x16 - 2];
    u16 f16;
    u16 f18;
} S_006D5AB8;
extern u16 D_L39_00249CE8[];
extern u8 D_00197BA0[];
s32 func_0012DCB0(void);
long func_00130760(s32, long);
s32 func_0017F8D0(void *, void *, s32);
void func_001961E8(s32);
s32 func_001961F8(void);

s32 func_L39_006D5AB8(u8 *arg0) {
    S_006D5AB8 buf;
    s32 ret;

    buf.f0 = D_L39_00249CE8[0];
    buf.f18 = *(u16 *)(arg0 + 0x28);
    buf.f16 = 1;
    arg0[0x1C] = 1;
    *(s32 *)(arg0 + 0x20) = (s32) func_00130760(func_0012DCB0(), 0x24000);
    ret = func_0017F8D0(&buf, D_00197BA0, 0);
    func_001961E8(ret);
    return func_001961F8() == 0;
}
/* localdecomp:end func_L39_006D5AB8 */

/* localdecomp:start func_L39_006D5B40 */
typedef struct {
    s8 f0;
    u8 pad1[3];
    s32 f4;
    s8 f8;
    u8 pad9[3];
    s32 fC;
    s32 f10;
    s8 f14;
    u8 pad15[7];
    s8 f1C;
} S_006D5B40;

S_006D5B40 *func_L39_006D5B40(S_006D5B40 *arg0) {
    arg0->f0 = 0;
    arg0->f4 = -1;
    arg0->f8 = 0;
    arg0->fC = -1;
    arg0->f10 = -1;
    arg0->f14 = 0;
    arg0->f1C = 0;
    return arg0;
}
/* localdecomp:end func_L39_006D5B40 */

/* localdecomp:start func_L39_006D5B68 */
typedef struct { u8 pad0[4]; s32 f4; s8 f8; u8 pad9[3]; s32 fC; s32 f10; s8 f14; u8 pad15[7]; s8 f1C; } S_006D5B68;

void func_L39_006D5B68(s32 arg0) {
    S_006D5B68 *p = (S_006D5B68 *)arg0;

    p->f4 = -1;
    p->f8 = 0;
    p->fC = -1;
    p->f14 = 0;
    p->f10 = -1;
    p->f1C = 0;
}
/* localdecomp:end func_L39_006D5B68 */

INCLUDE_ASM("asm/levels", func_L39_006D5B88);

/* localdecomp:start func_L39_006D5BF0 */
s32 func_L39_006E16A0(s32, s32, s32, s32);
s32 func_L39_006E1648(s32, s32, s32, s32);
void func_0011D534(s32 *, s32, s32);

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
} S_006D5BF0_Node;

void func_L39_006D5BF0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *s = (u8 *)arg0;
    u32 r;
    u32 m;
    u32 rem;
    u32 a;
    s32 n;
    S_006D5BF0_Node *p;
    S_006D5BF0_Node *q;

    if (*s == 0) {
        r = arg1;
        s[8] = 0;
        *(s32 *)(s + 0x24) = arg3;
        *s = 1;
        n = func_L39_006E16A0(r, arg3 * 2, 0x48, 4);
        *(s32 *)(s + 0x40) = func_L39_006E1648(r, n, 0x48, 4);
        r += n;
        m = 4;
        rem = r % m;
        a = r;
        if (rem != 0) {
            a = r + (m - rem);
        }
        r = a;
        *(s32 *)(s + 0x44) = r;
        func_0011D534((s32 *)r, 0, *(s32 *)(s + 0x24) * 8);
        p = (S_006D5BF0_Node *)(s + 0x28);
        p->f0 = 0;
        p->f8 = *(s32 *)(s + 0x44);
        p->f4 = 0;
        q = (S_006D5BF0_Node *)(s + 0x34);
        q->f0 = 0;
        q->f8 = *(s32 *)(s + 0x24) * 4 + *(s32 *)(s + 0x44);
        q->f4 = 0;
    }
}
/* localdecomp:end func_L39_006D5BF0 */

/* localdecomp:start func_L39_006D5CE0 */
s32 func_0012DCB0(void);
long func_00130760(s32, long);
s32 func_L39_006D5D68(void *);

s32 func_L39_006D5CE0(u8 *arg0) {
    s32 ret = 1;

    if (arg0[0] != 0) {
        if (arg0[8] != 0) {
            s32 t = func_00130760(func_0012DCB0(), 0x24000);

            if (t - *(s32 *)(arg0 + 0xC) >= 0x3A99) {
                arg0[8] = 0;
                func_L39_006D5D68(arg0);
                ret = 0;
            }
        }
    }
    return ret;
}
/* localdecomp:end func_L39_006D5CE0 */

/* localdecomp:start func_L39_006D5D68 */
extern u16 D_L39_00249D50[];
extern u8 D_00197C68[];
s32 func_0012DCB0(void);
long func_00130760(s32, long);
s32 func_0017EDB0(void *, void *, s32);
void func_001961E8(s32);
s32 func_001961F8(void);

s32 func_L39_006D5D68(void *arg0) {
    u16 buf[24];
    s32 ret = 1;
    s32 k;

    if (*(u8 *)arg0 != 0) {
        buf[0] = D_L39_00249D50[0];
        *(u8 *)((u8 *)arg0 + 8) = ret;
        k = func_0012DCB0();
        *(s32 *)((u8 *)arg0 + 0xC) = (s32) func_00130760(k, 0x24000);
        func_001961E8(func_0017EDB0(buf, D_00197C68, 0));
        if (func_001961F8() != 0) {
            ret = 0;
        }
    }
    return ret;
}
/* localdecomp:end func_L39_006D5D68 */

INCLUDE_ASM("asm/levels", func_L39_006D5DF8);

/* localdecomp:start func_L39_006D6210 */
typedef struct {
    u8 pad0[0x14];
    u8 f14;
    u8 pad15[3];
    s32 f18;
} S_006D6210;
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
    u8 pad1D[0x50 - 0x1D];
    s32 f50;
} G_006D6210;
typedef struct {
    u16 f0;
    u8 pad2[0x26];
    s32 f28;
} Loc_006D6210;
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern u16 D_L39_00249D50[];
extern u8 D_00197C40[];
extern u8 D_001A5CD0[];
s32 func_001206F4(void *, s32);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
s32 func_0017EE30(void *, void *, s32);
void func_001961E8(s32);
s32 func_001961F8(void);
void func_00195410(void);
s32 func_L39_006D8AD8(u8 *);

s32 func_L39_006D6210(S_006D6210 *arg0, s32 arg1) {
    Loc_006D6210 loc;
    G_006D6210 *g;
    u8 *p;
    s32 r;
    s32 n;

    g = D_L39_0024D760;
    n = g->f50;
    loc.f0 = D_L39_00249D50[0];
    func_001206F4((u8 *)&loc + 0x15, n);
    loc.f28 = arg1;
    arg0->f14 = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017EE30(&loc, D_00197C40, 0));
    p = D_001A5CD0;
    while (arg0->f14 != 0) {
        if (func_001961F8() != 0 || *(s32 *)(p + 0x2DC) != 0) {
            g->f10 = 0x38;
            if (g->f14 == 0) {
                g->f14 = 0x38;
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
            g->f10 = 0x38;
            if (g->f14 == 0) {
                g->f14 = 0x38;
            }
        }
    }
    return r;
}
/* localdecomp:end func_L39_006D6210 */

/* localdecomp:start func_L39_006D6378 */
__asm__(".extern D_L39_0024D760, 16");

/* from rac4-decomp's func_L00_00766C00 */
void func_L39_006D6378(void *arg0) {
    void *temp_v1;
    temp_v1 = (*(void **)((u8 *)D_L39_0024D760 + 0x40));
    (*(s8 *)((u8 *)(temp_v1) + 0x14)) = 0;
    (*(s32 *)((u8 *)(temp_v1) + 0x18)) = (s32) (*(s32 *)((u8 *)(arg0) + 0x18));
}
/* localdecomp:end func_L39_006D6378 */

/* localdecomp:start func_L39_006D6398 */
typedef struct {
    u8 pad0[0x1C];
    u8 f1C;
    u8 pad1D[3];
    s32 f20;
} S_006D6398;
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
    u8 pad1D[0x50 - 0x1D];
    s32 f50;
} G_006D6398;
typedef struct {
    u16 f0;
    u8 pad2[0x26];
    s32 f28;
} Loc_006D6398;
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern u16 D_L39_00249D50[];
extern u8 D_00197C90[];
extern u8 D_001A5CD0[];
s32 func_001206F4(void *, s32);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
s32 func_0017EEB0(void *, void *, s32);
void func_001961E8(s32);
s32 func_001961F8(void);
void func_00195410(void);
s32 func_L39_006D8AD8(u8 *);

s32 func_L39_006D6398(S_006D6398 *arg0, s32 arg1) {
    Loc_006D6398 loc;
    G_006D6398 *g;
    u8 *p;
    s32 r;
    s32 n;

    g = D_L39_0024D760;
    n = g->f50;
    loc.f0 = D_L39_00249D50[0];
    func_001206F4((u8 *)&loc + 0x15, n);
    loc.f28 = arg1;
    arg0->f1C = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017EEB0(&loc, D_00197C90, 0));
    p = D_001A5CD0;
    while (arg0->f1C != 0) {
        if (func_001961F8() != 0 || *(s32 *)(p + 0x2DC) != 0) {
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
/* localdecomp:end func_L39_006D6398 */

/* localdecomp:start func_L39_006D6500 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { char pad[0x1c]; char flag; char pad2[3]; int val; } T_006D6500;
typedef struct { char pad[0x40]; T_006D6500 *p; } S_006D6500;

/* from rac4-decomp's func_L00_00766DB0 */
void func_L39_006D6500(char *arg0) {
    T_006D6500 *t = ((S_006D6500 *)D_L39_0024D760)->p;
    t->flag = 0;
    t->val = *(int *)(arg0 + 0x18);
}
/* localdecomp:end func_L39_006D6500 */

/* localdecomp:start func_L39_006D6520 */
typedef struct {
    s8 f0;
    u8 pad1[3];
    s32 f4;
    s8 f8;
    u8 pad9[3];
    s32 fC;
    s32 f10;
    s8 f14;
    s8 f15;
} S_006D6520;

S_006D6520 *func_L39_006D6520(S_006D6520 *arg0) {
    arg0->f0 = 0;
    arg0->f4 = -1;
    arg0->f8 = 0;
    arg0->fC = -1;
    arg0->f10 = -1;
    arg0->f14 = 0;
    arg0->f15 = 0;
    return arg0;
}
/* localdecomp:end func_L39_006D6520 */

/* localdecomp:start func_L39_006D6548 */
typedef struct S_006D6548 { s32 pad0; s32 a4; s8 b8; s8 p9[3]; s32 aC; s32 a10; s8 b14; } S_006D6548;

void func_L39_006D6548(s32 arg0) {
    S_006D6548 *p = (S_006D6548 *)arg0;

    p->a4 = -1;
    p->b14 = 0;
    p->aC = -1;
    p->a10 = -1;
    p->b8 = 0;
}
/* localdecomp:end func_L39_006D6548 */

INCLUDE_ASM("asm/levels", func_L39_006D6568);

/* localdecomp:start func_L39_006D65D0 */
s32 func_L39_006E16A0(s32, s32, s32, s32);
s32 func_L39_006E1648(s32, s32, s32, s32);
void func_0011D534(s32 *, s32, s32);

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
} S_006D65D0_Node;

void func_L39_006D65D0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *s = (u8 *)arg0;
    u32 r;
    u32 m;
    u32 rem;
    u32 a;
    s32 n;
    S_006D65D0_Node *p;
    S_006D65D0_Node *q;

    if (*s == 0) {
        r = arg1;
        s[8] = 0;
        *(s32 *)(s + 0x64) = arg3;
        *s = 1;
        n = func_L39_006E16A0(r, arg3 * 2, 0x1D8, 4);
        *(s32 *)(s + 0x80) = func_L39_006E1648(r, n, 0x1D8, 4);
        r += n;
        m = 4;
        rem = r % m;
        a = r;
        if (rem != 0) {
            a = r + (m - rem);
        }
        r = a;
        *(s32 *)(s + 0x84) = r;
        func_0011D534((s32 *)r, 0, *(s32 *)(s + 0x64) * 8);
        p = (S_006D65D0_Node *)(s + 0x68);
        p->f0 = 0;
        p->f8 = *(s32 *)(s + 0x84);
        p->f4 = 0;
        q = (S_006D65D0_Node *)(s + 0x74);
        q->f0 = 0;
        q->f8 = *(s32 *)(s + 0x64) * 4 + *(s32 *)(s + 0x84);
        q->f4 = 0;
    }
}
/* localdecomp:end func_L39_006D65D0 */

/* localdecomp:start func_L39_006D66B8 */
s32 func_0012DCB0(void);
long func_00130760(s32, long);
void func_L39_006D6750(void *, s32, s32, s32);

s32 func_L39_006D66B8(void *arg0) {
    s32 temp_s1;
    s32 temp_v0;

    temp_s1 = 1;
    if (*(u8 *)arg0 != 0) {
        if (*(u8 *)((u8 *)arg0 + 0x8) != 0) {
            s32 temp_a0;

            temp_a0 = func_0012DCB0();
            temp_v0 = (s32) func_00130760(temp_a0, 0x24000);
            if ((temp_v0 - *(s32 *)((u8 *)arg0 + 0xC)) >= 0x3A99) {
                *(u8 *)((u8 *)arg0 + 0x8) = 0;
                temp_s1 = 0;
                func_L39_006D6750(arg0, *(s32 *)((u8 *)arg0 + 0x5C), *(s32 *)((u8 *)arg0 + 0x60), 1);
            }
        }
    }
    return temp_s1;
}
/* localdecomp:end func_L39_006D66B8 */

INCLUDE_ASM("asm/levels", func_L39_006D6750);

/* localdecomp:start func_L39_006D6808 */
typedef struct { int words[9]; } S_006D6808_Copy;
typedef struct { char pad[0x14]; char f14; char pad2[0x23]; S_006D6808_Copy f38; } S_006D6808_Type2;
typedef struct { char pad[0x44]; S_006D6808_Type2 *f44; } S_006D6808_Type3;
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;

void func_L39_006D6808(S_006D6808_Copy *arg0) {
    S_006D6808_Type2 *p = ((S_006D6808_Type3 *)D_L39_0024D760)->f44;
    p->f14 = 0;
    p->f38 = *arg0;
}
/* localdecomp:end func_L39_006D6808 */

/* localdecomp:start func_L39_006D6868 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { unsigned long x[4]; } __attribute__((packed)) Block_6D6868;
typedef struct { char pad[0x15]; char flag; char pad2[2]; Block_6D6868 data; } Target_6D6868;

/* from rac4-decomp's func_L00_00771D80 */
void func_L39_006D6868(Block_6D6868 *p) {
    Target_6D6868 *t = *(Target_6D6868 **)((char *)D_L39_0024D760 + 0x44);
    t->flag = 0;
    t->data = *p;
}
/* localdecomp:end func_L39_006D6868 */

INCLUDE_ASM("asm/levels", func_L39_006D68C0);

/* localdecomp:start func_L39_006D6CF8 */
typedef struct {
    u16 f0;
    u8 pad2[0x18 - 2];
    s32 f18;
    s32 f1C;
    s32 f20;
    u8 pad24[0x30 - 0x24];
} Loc_006D6CF8;
typedef struct {
    u8 pad0[1];
    u8 f1;
    u8 pad2[6];
    s32 f8;
    u8 padC[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
} G_006D6CF8;
typedef struct {
    u8 pad0[0x14];
    u8 f14;
    u8 pad15[0x38 - 0x15];
    u8 f38[0x18];
    s32 f50;
} S_006D6CF8;
typedef struct {
    u8 pad0[0x2DC];
    s32 f2DC;
} P_006D6CF8;
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern u16 D_L39_00249DA8[];
extern u8 D_001980D8[];
extern u8 D_001A5CD0[];
s32 func_0012DCB0(void);
long func_00130760(s32, long);
s32 func_0017FA40(void *, void *, s32);
void func_001961E8(s32);
s32 func_001961F8(void);
void func_00195410(void);
s32 func_L39_006D8AD8(u8 *);

void *func_L39_006D6CF8(S_006D6CF8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Loc_006D6CF8 loc;
    G_006D6CF8 *g;
    P_006D6CF8 *p;
    s32 r;

    loc.f0 = D_L39_00249DA8[0];
    loc.f18 = arg1;
    loc.f1C = arg2;
    loc.f20 = arg3;
    g = (G_006D6CF8 *)D_L39_0024D760;
    arg0->f14 = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017FA40(&loc, D_001980D8, 0));
    p = (P_006D6CF8 *)D_001A5CD0;
    while (arg0->f14 != 0) {
        if (func_001961F8() != 0 || p->f2DC != 0) {
            g->f10 = 0x5D;
            if (g->f14 == 0) {
                g->f14 = 0x5D;
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
    arg0->f14 = 0;
    g->f1 = 0;
    if (r != 0) {
        if (arg0->f50 != 0) {
            r = 0;
        }
    }
    return r != 0 ? arg0->f38 : 0;
}
/* localdecomp:end func_L39_006D6CF8 */

/* localdecomp:start func_L39_006D6E30 */
void func_00196510(s32, s32);

void func_L39_006D6E30(s32 arg0, s32 arg1, s32 arg2) {
    func_00196510(arg1, arg2);
}
/* localdecomp:end func_L39_006D6E30 */

/* localdecomp:start func_L39_006D6E50 */
void func_00196D08(s32, s32, s32);

void func_L39_006D6E50(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_00196D08(arg1, arg2, arg3);
}
/* localdecomp:end func_L39_006D6E50 */

/* localdecomp:start func_L39_006D6E78 */
typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
} S_006D6E78_L;
typedef struct {
    s8 f0;
    u8 pad1[3];
    s32 f4;
    s32 f8;
    s8 fC;
    s8 fD;
    u8 padE[2];
    s32 f10;
    S_006D6E78_L f14;
    s32 f20;
    s32 f24;
} S_006D6E78;
s32 func_L39_006E16A0(s32, s32, s32, s32);
s32 func_L39_006E1648(s32, s32, s32, s32);
void func_0011D534(s32 *, s32, s32);

s32 func_L39_006D6E78(s32 arg0, s32 arg1, s32 arg2) {
    S_006D6E78 *p = (S_006D6E78 *)arg0;
    u32 r;
    u32 m;
    u32 rem;
    u32 a;
    u32 b;
    s32 n;
    S_006D6E78_L *l;

    p->f0 = 0;
    p->f4 = -1;
    p->f8 = -1;
    p->fC = 0;
    p->fD = 0;
    p->f10 = arg2;
    b = arg0 + 0x28;
    m = 4;
    rem = b % m;
    if (rem != 0) {
        b += m - rem;
    }
    r = b;
    n = func_L39_006E16A0(r, arg2, 100, 4);
    p->f20 = func_L39_006E1648(r, n, 100, 4);
    r += n;
    rem = r % m;
    a = r;
    if (rem != 0) {
        a = r + (m - rem);
    }
    r = a;
    p->f24 = r;
    func_0011D534((s32 *)r, 0, p->f10 * 4);
    l = &p->f14;
    l->f0 = 0;
    l->f8 = p->f24;
    l->f4 = 0;
    return arg0;
}
/* localdecomp:end func_L39_006D6E78 */

/* localdecomp:start func_L39_006D6F60 */
typedef struct {
    s8 f0;
    u8 pad1[3];
    s32 f4;
    s32 f8;
    s8 fC;
    s8 fD;
} S_006D6F60;

void func_L39_006D6F60(s32 arg0) {
    S_006D6F60 *p = (S_006D6F60 *)arg0;
    p->f0 = 0;
    p->f4 = -1;
    p->f8 = -1;
    p->fC = 0;
    p->fD = 0;
}
/* localdecomp:end func_L39_006D6F60 */

INCLUDE_ASM("asm/levels", func_L39_006D6F80);

INCLUDE_ASM("asm/levels", func_L39_006D7018);

INCLUDE_ASM("asm/levels", func_L39_006D7138);

INCLUDE_ASM("asm/levels", func_L39_006D7810);

/* localdecomp:start func_L39_006D7838 */
s32 func_0012DCB0(void);
long func_00130760(s32, long);
void func_L39_006D7018(void *);

s32 func_L39_006D7838(u8 *arg0) {
    s32 ret = 1;

    if (arg0[0] != 0) {
        s32 t = func_00130760(func_0012DCB0(), 0x24000);

        if (t - *(s32 *)(arg0 + 4) >= 0x3A99) {
            arg0[0] = 0;
            func_L39_006D7018(arg0);
            ret = 0;
        }
    }
    return ret;
}
/* localdecomp:end func_L39_006D7838 */

/* localdecomp:start func_L39_006D78B8 */
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
s32 func_L01_00521C90(s32, s32);
s32 func_L39_006D7930(s32, s32);

void func_L39_006D78B8(s32 arg0, s32 arg1) {
    s32 temp_s0;
    temp_s0 = func_L01_00521C90(0x88, arg0);
    D_L39_0024D760 = (void *)func_L39_006D7930(temp_s0, arg1);
}
/* localdecomp:end func_L39_006D78B8 */

/* localdecomp:start func_L39_006D78F8 */
__asm__(".extern D_L39_0024D760, 16");
extern void func_L39_006D8060(void *, s32);

/* from rac4-decomp's func_L00_007731F8 */
s32 func_L39_006D78F8(void) {
    void *temp_v0;
    func_L39_006D8060(D_L39_0024D760, 2);
    temp_v0 = D_L39_0024D760;
    D_L39_0024D760 = 0;
    return (s32)temp_v0;
}
/* localdecomp:end func_L39_006D78F8 */

/* localdecomp:start func_L39_006D7930 */
typedef struct {
    s8 f0;
    s8 f1;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s8 f1C;
    s8 f1D;
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2C;
    void *f30;
    void *f34;
    void *f38;
    void *f3C;
    void *f40;
    void *f44;
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    s8 f58[13];
    s32 f68;
    s32 f6C;
    s32 f70;
    s8 f74;
    s32 f78;
    s8 f7C;
    s32 f80;
    s32 f84;
} S_006D7930;
extern s32 D_0022F280[];
void func_001974D8(s32);
void func_L39_006D80F8(void *);
void *func_L39_006D8EF0(u32);
s32 func_L39_006D8F30(u32);
void *func_L39_006D8F58(u32);
u32 func_L39_006D8F98(u32);
void *func_L39_006D8FC0(u32);
u32 func_L39_006D9000(u32);
void *func_L39_006D9028(u32);
u32 func_L39_006D9068(u32);
void *func_L39_006D9090(u32);
u32 func_L39_006D90D0(u32);
void *func_L39_006D90F8(u32);
u32 func_L39_006D9138(u32);
void *func_L39_006D9160(u32);
u32 func_L39_006D91A0(u32);
void *func_L39_006D91C8(u32);
u32 func_L39_006D9208(u32);
void *func_L39_006D9230(u32);
u32 func_L39_006D9270(u32);
s32 func_L39_006D9298(s32);
u32 func_L39_006D92D8(u32);
void func_L39_006D5440();
void func_L39_006D55C0();
void func_L39_006D6378();
void func_L39_006D6500();
void func_L39_006D6808();
void func_L39_006D6868();
void func_L39_006CD1B8();
void func_L39_006CD218();
void func_L39_006CD270();
void func_L39_006CD2C8();
void func_L39_006CD488();
void func_L39_006CD808();
void func_L39_006CDD90();
void func_L39_006CDF18();
void func_L39_006CED88();
void func_L39_006CF080();
void func_L39_006CF218();
void func_L39_006CF3C8();
void func_L39_006CF588();
void func_L39_006CF750();
void func_L39_006CF900();
void func_L39_006CFAD0();
void func_L39_006CFCB0();
void func_L39_006CFE68();
void func_L39_006CFE88();
void func_L39_006D0058();
void func_L39_006D0208();
void func_L39_006D0398();
void func_L39_006D0550();
void func_L39_006D0990();
void func_L39_006D0F08();
void func_L39_006D12C8();
void func_L39_006D1710();
void func_L39_006D1BF8();
void func_L39_006D20E8();
void func_L39_006D25E0();
void func_L39_006D2AC0();
void func_L39_006D30F8();
void func_L39_006D3318();
void func_L39_006D33D8();
void func_L39_006D3950();
void func_L39_006D4018();
void func_L39_006D4278();
void func_L39_006D44F0();
void func_L39_006D4688();
void func_L39_006D4A68();
void func_L39_006D55E0();
void func_L39_006D5DF8();
void func_L39_006D68C0();
void func_L39_006D7138();
void func_L39_006D7810();
void func_L39_006D8E88();
void func_L39_006D8E90();
void func_L39_006D8EC0();
void func_L39_006D9808();
void func_L39_006D9BC0();
void func_L39_006D9E10();
void func_L39_006DA628();
void func_L39_006DA878();
void func_L39_006DABF0();
void func_L39_006DB098();
void func_L39_006DB5B0();
void func_L39_006DB730();
void func_L39_006DB890();
void func_L39_006DCCE0();
void func_L39_006DCD38();
void func_L39_006DD028();
void func_L39_006DD3C0();
void func_L39_006DD3C8();
void func_L39_006DD3D0();
void func_L39_006DD770();
void func_L39_006DD9B0();
void func_L39_006DDF78();
void func_L39_006DE010();
void func_L39_006DE2D0();
void func_L39_006DE4E0();
void func_L39_006DE548();
void func_L39_006DE948();
void func_L39_006DEA18();
void func_L39_006DEA58();
void func_L39_006DEA78();
void func_L39_006DEAA0();
void func_L39_006DEAC0();

/* Entries 31 and 54 point 8 bytes into func_L39_006D33D8 and func_L39_006D7810: the catalogue
   starts those two functions on the previous function's last two instructions. */
s32 func_L39_006D7930(s32 arg0, s32 arg1) {
    S_006D7930 *p = (S_006D7930 *)arg0;

    p->f0 = 0;
    p->f1 = 0;
    p->f4 = -1;
    p->f8 = 0;
    p->fC = 15000;
    p->f10 = 0;
    p->f14 = 0;
    p->f18 = 0;
    p->f1C = 0;
    p->f1D = 0;
    p->f20 = 0;
    p->f24 = 0;
    p->f28 = arg1 - 0x88;
    p->f2C = arg0 + 0x88;
    p->f58[0] = 0;
    p->f58[1] = 0;
    p->f58[2] = 0;
    p->f58[3] = 0;
    p->f58[4] = 0;
    p->f58[5] = 0;
    p->f58[6] = 0;
    p->f58[7] = 0;
    p->f58[8] = 0;
    p->f58[9] = 0;
    p->f58[10] = 0;
    p->f58[11] = 0;
    p->f58[12] = 0;
    p->f70 = 0;
    p->f74 = 0;
    p->f78 = 0;
    p->f7C = 0;
    p->f80 = 0;
    p->f84 = 0;
    p->f30 = func_L39_006D8EF0(p->f2C);
    p->f28 -= func_L39_006D8F30(p->f2C);
    p->f2C += func_L39_006D8F30(p->f2C);
    p->f34 = func_L39_006D8F58(p->f2C);
    p->f28 -= func_L39_006D8F98(p->f2C);
    p->f2C += func_L39_006D8F98(p->f2C);
    p->f38 = func_L39_006D8FC0(p->f2C);
    p->f28 -= func_L39_006D9000(p->f2C);
    p->f2C += func_L39_006D9000(p->f2C);
    p->f3C = func_L39_006D9028(p->f2C);
    p->f28 -= func_L39_006D9068(p->f2C);
    p->f2C += func_L39_006D9068(p->f2C);
    p->f44 = func_L39_006D9090(p->f2C);
    p->f28 -= func_L39_006D90D0(p->f2C);
    p->f2C += func_L39_006D90D0(p->f2C);
    p->f40 = func_L39_006D90F8(p->f2C);
    p->f28 -= func_L39_006D9138(p->f2C);
    p->f2C += func_L39_006D9138(p->f2C);
    p->f48 = func_L39_006D9160(p->f2C);
    p->f28 -= func_L39_006D91A0(p->f2C);
    p->f2C += func_L39_006D91A0(p->f2C);
    p->f4C = func_L39_006D91C8(p->f2C);
    p->f28 -= func_L39_006D9208(p->f2C);
    p->f2C += func_L39_006D9208(p->f2C);
    p->f50 = func_L39_006D9230(p->f2C);
    p->f28 -= func_L39_006D9270(p->f2C);
    p->f2C += func_L39_006D9270(p->f2C);
    p->f54 = (void *)func_L39_006D9298(p->f2C);
    p->f28 -= func_L39_006D92D8(p->f2C);
    p->f2C += func_L39_006D92D8(p->f2C);
    p->f68 = p->f28;
    p->f6C = p->f2C;
    D_0022F280[4] = (s32)func_L39_006CD270;
    D_0022F280[5] = (s32)func_L39_006CD1B8;
    D_0022F280[6] = (s32)func_L39_006CD218;
    D_0022F280[7] = (s32)func_L39_006D9E10;
    D_0022F280[8] = (s32)func_L39_006CD2C8;
    D_0022F280[9] = (s32)func_L39_006CD488;
    D_0022F280[10] = (s32)func_L39_006CDD90;
    D_0022F280[11] = (s32)func_L39_006CD808;
    D_0022F280[12] = (s32)func_L39_006CDF18;
    D_0022F280[13] = (s32)func_L39_006D8E90;
    D_0022F280[14] = (s32)func_L39_006D30F8;
    D_0022F280[15] = (s32)func_L39_006D3318;
    D_0022F280[16] = (s32)func_L39_006CF080;
    D_0022F280[17] = (s32)func_L39_006CF218;
    D_0022F280[18] = (s32)func_L39_006CF3C8;
    D_0022F280[19] = (s32)func_L39_006D0F08;
    D_0022F280[22] = (s32)func_L39_006CED88;
    D_0022F280[23] = (s32)func_L39_006D1BF8;
    D_0022F280[24] = (s32)func_L39_006D0990;
    D_0022F280[25] = (s32)func_L39_006D12C8;
    D_0022F280[26] = (s32)func_L39_006D1710;
    D_0022F280[27] = (s32)func_L39_006D20E8;
    D_0022F280[20] = (s32)func_L39_006D25E0;
    D_0022F280[21] = (s32)func_L39_006D2AC0;
    D_0022F280[28] = (s32)func_L39_006D0058;
    D_0022F280[29] = (s32)func_L39_006D0550;
    D_0022F280[30] = (s32)func_L39_006D0208;
    D_0022F280[32] = (s32)func_L39_006D0398;
    D_0022F280[31] = (s32)((u8 *)func_L39_006D33D8 + 8);
    D_0022F280[33] = (s32)func_L39_006CF588;
    D_0022F280[34] = (s32)func_L39_006CFAD0;
    D_0022F280[35] = (s32)func_L39_006CFE68;
    D_0022F280[36] = (s32)func_L39_006CFCB0;
    D_0022F280[37] = (s32)func_L39_006CFE88;
    D_0022F280[38] = (s32)func_L39_006CF750;
    D_0022F280[39] = (s32)func_L39_006CF900;
    D_0022F280[40] = (s32)func_L39_006D8EC0;
    D_0022F280[41] = (s32)func_L39_006D44F0;
    D_0022F280[42] = (s32)func_L39_006D4A68;
    D_0022F280[0] = (s32)func_L39_006D4018;
    D_0022F280[43] = (s32)func_L39_006D3950;
    D_0022F280[44] = (s32)func_L39_006D55C0;
    D_0022F280[45] = (s32)func_L39_006D55E0;
    D_0022F280[46] = (s32)func_L39_006D5440;
    D_0022F280[47] = (s32)func_L39_006D4278;
    D_0022F280[48] = (s32)func_L39_006D4688;
    D_0022F280[49] = (s32)func_L39_006D6378;
    D_0022F280[50] = (s32)func_L39_006D5DF8;
    D_0022F280[51] = (s32)func_L39_006D6500;
    D_0022F280[52] = (s32)func_L39_006D68C0;
    D_0022F280[53] = (s32)func_L39_006D7138;
    D_0022F280[54] = (s32)((u8 *)func_L39_006D7810 + 8);
    D_0022F280[55] = (s32)func_L39_006D8E88;
    D_0022F280[56] = (s32)func_L39_006D9808;
    D_0022F280[57] = (s32)func_L39_006D9BC0;
    D_0022F280[58] = (s32)func_L39_006DB730;
    D_0022F280[59] = (s32)func_L39_006DA628;
    D_0022F280[60] = (s32)func_L39_006DB890;
    D_0022F280[61] = (s32)func_L39_006DA878;
    D_0022F280[62] = (s32)func_L39_006DABF0;
    D_0022F280[63] = (s32)func_L39_006DB098;
    D_0022F280[64] = (s32)func_L39_006DB5B0;
    D_0022F280[65] = (s32)func_L39_006DCD38;
    D_0022F280[66] = (s32)func_L39_006DCCE0;
    D_0022F280[3] = (s32)func_L39_006DD028;
    D_0022F280[1] = (s32)func_L39_006DD3C0;
    D_0022F280[2] = (s32)func_L39_006DD3C8;
    D_0022F280[77] = (s32)func_L39_006DD3D0;
    D_0022F280[67] = (s32)func_L39_006DE2D0;
    D_0022F280[68] = (s32)func_L39_006DE4E0;
    D_0022F280[69] = (s32)func_L39_006DD770;
    D_0022F280[70] = (s32)func_L39_006DD9B0;
    D_0022F280[71] = (s32)func_L39_006DDF78;
    D_0022F280[72] = (s32)func_L39_006DE010;
    D_0022F280[73] = (s32)func_L39_006DE948;
    D_0022F280[74] = (s32)func_L39_006DEA18;
    D_0022F280[75] = (s32)func_L39_006DEA58;
    D_0022F280[76] = (s32)func_L39_006DEAC0;
    D_0022F280[78] = (s32)func_L39_006D6808;
    D_0022F280[79] = (s32)func_L39_006DEA78;
    D_0022F280[80] = (s32)func_L39_006DEAA0;
    D_0022F280[81] = (s32)func_L39_006D6868;
    func_001974D8((s32)func_L39_006DE548);
    func_L39_006D80F8(p);
    return (s32)p;
}
/* localdecomp:end func_L39_006D7930 */

/* localdecomp:start func_L39_006D8060 */
extern s32 D_0022F280[];
void func_0011D534(s32 *, s32, s32);
void func_001974D8(s32);
void func_L39_006D8938(void *);
void func_L01_004D3BD0(void *);

void func_L39_006D8060(void *arg0, s32 arg1) {
    func_0011D534(D_0022F280, 0, 0x148);
    func_001974D8(0);
    func_L39_006D8938(arg0);
    if (arg1 & 1) {
        func_L01_004D3BD0(arg0);
    }
}
/* localdecomp:end func_L39_006D8060 */

/* localdecomp:start func_L39_006D80C8 */
void func_001961E8(s32);

typedef struct {
    /* 0x00 */ u8 pad00[0x10];
    /* 0x10 */ s32 f10;
    /* 0x14 */ s32 f14;
    /* 0x18 */ s32 f18;
} S_006D80C8;

void func_L39_006D80C8(arg0)
S_006D80C8 *arg0;
{
    arg0->f10 = 0;
    arg0->f14 = 0;
    arg0->f18 = 0;
    func_001961E8(0);
}
/* localdecomp:end func_L39_006D80C8 */

/* localdecomp:start func_L39_006D80F8 */
void func_L39_006CCC88(s32);
void func_L39_006CD568(s32);
void func_L39_006CDF38(s32);
void func_L39_006D3490(s32);
void func_L39_006D5208(s32);
void func_L39_006D5B68(s32);
void func_L39_006D6548(s32);
void func_L39_006D6F60(s32);
void func_L39_006D80C8();
void func_L39_006D9318(s32);
void func_L39_006DA038(s32);
void func_L39_006DC7A8(s32);
void func_L39_006DD438(s32);

void func_L39_006D80F8(void *arg0) {
    s32 temp_a0;
    s32 temp_a0_2;

    func_L39_006D80C8();
    func_L39_006CCC88((*(s32 *)((u8 *)arg0 + 0x30)));
    func_L39_006CD568((*(s32 *)((u8 *)arg0 + 0x34)));
    func_L39_006CDF38((*(s32 *)((u8 *)arg0 + 0x38)));
    temp_a0 = *(s32 *)((u8 *)arg0 + 0x70);
    if (temp_a0 != 0) {
        func_L39_006D5208(temp_a0);
    }
    func_L39_006D3490((*(s32 *)((u8 *)arg0 + 0x3C)));
    func_L39_006D5B68((*(s32 *)((u8 *)arg0 + 0x40)));
    func_L39_006D6548((*(s32 *)((u8 *)arg0 + 0x44)));
    temp_a0_2 = *(s32 *)((u8 *)arg0 + 0x78);
    if (temp_a0_2 != 0) {
        func_L39_006D6F60(temp_a0_2);
    }
    func_L39_006D9318((*(s32 *)((u8 *)arg0 + 0x48)));
    func_L39_006DA038((*(s32 *)((u8 *)arg0 + 0x4C)));
    func_L39_006DC7A8((*(s32 *)((u8 *)arg0 + 0x50)));
    func_L39_006DD438((*(s32 *)((u8 *)arg0 + 0x54)));
}
/* localdecomp:end func_L39_006D80F8 */

/* localdecomp:start func_L39_006D8198 */
s32 func_L01_00521C90(s32, s32);
s32 func_L39_006D6E78(s32, s32, s32);
s32 func_L39_006D6F80(s32);

s32 func_L39_006D8198(void *arg0, s32 arg1) {
    s32 temp_s0;

    if ((*(u8 *)((u8 *)arg0 + 0x7C)) == 0) {
        temp_s0 = func_L39_006D6F80((*(s32 *)((u8 *)arg0 + 0x2C)));
        *(s32 *)((u8 *)arg0 + 0x78) = func_L39_006D6E78(func_L01_00521C90(0x28, (*(s32 *)((u8 *)arg0 + 0x2C))), temp_s0, arg1);
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_s0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_s0);
        *(u8 *)((u8 *)arg0 + 0x7C) = 1U;
    }
    return (*(s32 *)((u8 *)arg0 + 0x78));
}
/* localdecomp:end func_L39_006D8198 */

/* localdecomp:start func_L39_006D8228 */
s32 func_L01_00521C90(s32, s32);
s32 func_L39_006D50F0(s32, s32, s32);
s32 func_L39_006D5238(s32);

s32 func_L39_006D8228(void *arg0, s32 arg1) {
    s32 temp_s0;

    if ((*(u8 *)((u8 *)arg0 + 0x74)) == 0) {
        temp_s0 = func_L39_006D5238((*(s32 *)((u8 *)arg0 + 0x2C)));
        *(s32 *)((u8 *)arg0 + 0x70) = func_L39_006D50F0(func_L01_00521C90(0x4C, (*(s32 *)((u8 *)arg0 + 0x2C))), temp_s0, arg1);
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_s0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_s0);
        *(u8 *)((u8 *)arg0 + 0x74) = 1U;
    }
    return (*(s32 *)((u8 *)arg0 + 0x70));
}
/* localdecomp:end func_L39_006D8228 */

/* localdecomp:start func_L39_006D82B8 */
s32 func_L39_006DD468(s32);
void func_L39_006DD4D0(s32, s32, s32, s32);

void func_L39_006D82B8(void *arg0, s32 arg1) {
    s32 temp_v0;

    if ((*(u8 *)((u8 *)arg0 + 0x58)) == 0) {
        temp_v0 = func_L39_006DD468((*(s32 *)((u8 *)arg0 + 0x2C)));
        func_L39_006DD4D0((*(s32 *)((u8 *)arg0 + 0x54)), (*(s32 *)((u8 *)arg0 + 0x2C)), temp_v0, arg1);
        *(u8 *)((u8 *)arg0 + 0x58) = 1U;
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_v0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_v0);
    }
}
/* localdecomp:end func_L39_006D82B8 */

/* localdecomp:start func_L39_006D8338 */
s32 func_L39_006CD588(s32);
void func_L39_006CD5F0(s32, s32, s32, s32);

void func_L39_006D8338(void *arg0, s32 arg1) {
    s32 temp_v0;

    if ((*(u8 *)((u8 *)arg0 + 0x59)) == 0) {
        temp_v0 = func_L39_006CD588((*(s32 *)((u8 *)arg0 + 0x2C)));
        func_L39_006CD5F0((*(s32 *)((u8 *)arg0 + 0x34)), (*(s32 *)((u8 *)arg0 + 0x2C)), temp_v0, arg1);
        *(u8 *)((u8 *)arg0 + 0x59) = 1U;
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_v0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_v0);
    }
}
/* localdecomp:end func_L39_006D8338 */

/* localdecomp:start func_L39_006D83B8 */
s32 func_L39_006D5B88(s32);
void func_L39_006D5BF0(s32, s32, s32, s32);

void func_L39_006D83B8(void *arg0, s32 arg1) {
    s32 temp_v0;

    if ((*(u8 *)((u8 *)arg0 + 0x61)) == 0) {
        temp_v0 = func_L39_006D5B88((*(s32 *)((u8 *)arg0 + 0x2C)));
        func_L39_006D5BF0((*(s32 *)((u8 *)arg0 + 0x40)), (*(s32 *)((u8 *)arg0 + 0x2C)), temp_v0, arg1);
        *(u8 *)((u8 *)arg0 + 0x61) = 1U;
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_v0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_v0);
    }
}
/* localdecomp:end func_L39_006D83B8 */

/* localdecomp:start func_L39_006D8438 */
s32 func_L39_006D6568(s32);
void func_L39_006D65D0(s32, s32, s32, s32);

void func_L39_006D8438(void *arg0, s32 arg1) {
    s32 temp_v0;

    if ((*(u8 *)((u8 *)arg0 + 0x62)) == 0) {
        temp_v0 = func_L39_006D6568((*(s32 *)((u8 *)arg0 + 0x2C)));
        func_L39_006D65D0((*(s32 *)((u8 *)arg0 + 0x44)), (*(s32 *)((u8 *)arg0 + 0x2C)), temp_v0, arg1);
        *(u8 *)((u8 *)arg0 + 0x62) = 1U;
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_v0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_v0);
    }
}
/* localdecomp:end func_L39_006D8438 */

/* localdecomp:start func_L39_006D84B8 */
s32 func_L39_006CE000(s32);
void func_L39_006CE068(s32, s32, s32, s32);

void func_L39_006D84B8(void *arg0, s32 arg1) {
    s32 temp_v0;

    if ((*(u8 *)((u8 *)arg0 + 0x5A)) == 0) {
        temp_v0 = func_L39_006CE000((*(s32 *)((u8 *)arg0 + 0x2C)));
        func_L39_006CE068((*(s32 *)((u8 *)arg0 + 0x38)), (*(s32 *)((u8 *)arg0 + 0x2C)), temp_v0, arg1);
        *(u8 *)((u8 *)arg0 + 0x5A) = 1U;
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_v0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_v0);
    }
}
/* localdecomp:end func_L39_006D84B8 */

/* localdecomp:start func_L39_006D8538 */
s32 func_L39_006CE150(s32);
void func_L39_006CE1B8(s32, s32, s32, s32);

void func_L39_006D8538(void *arg0, s32 arg1) {
    s32 temp_v0;

    if ((*(u8 *)((u8 *)arg0 + 0x5B)) == 0) {
        temp_v0 = func_L39_006CE150((*(s32 *)((u8 *)arg0 + 0x2C)));
        func_L39_006CE1B8((*(s32 *)((u8 *)arg0 + 0x38)), (*(s32 *)((u8 *)arg0 + 0x2C)), temp_v0, arg1);
        *(u8 *)((u8 *)arg0 + 0x5B) = 1U;
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_v0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_v0);
    }
}
/* localdecomp:end func_L39_006D8538 */

/* localdecomp:start func_L39_006D85B8 */
s32 func_L39_006CE2A0(s32);
void func_L39_006CE308(s32, s32, s32, s32);

void func_L39_006D85B8(void *arg0, s32 arg1) {
    s32 temp_v0;

    if ((*(u8 *)((u8 *)arg0 + 0x5C)) == 0) {
        temp_v0 = func_L39_006CE2A0((*(s32 *)((u8 *)arg0 + 0x2C)));
        func_L39_006CE308((*(s32 *)((u8 *)arg0 + 0x38)), (*(s32 *)((u8 *)arg0 + 0x2C)), temp_v0, arg1);
        *(u8 *)((u8 *)arg0 + 0x5C) = 1U;
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_v0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_v0);
    }
}
/* localdecomp:end func_L39_006D85B8 */

/* localdecomp:start func_L39_006D8638 */
s32 func_L39_006CE3F0(s32);
void func_L39_006CE458(s32, s32, s32, s32);

void func_L39_006D8638(void *arg0, s32 arg1) {
    s32 temp_v0;

    if ((*(u8 *)((u8 *)arg0 + 0x5D)) == 0) {
        temp_v0 = func_L39_006CE3F0((*(s32 *)((u8 *)arg0 + 0x2C)));
        func_L39_006CE458((*(s32 *)((u8 *)arg0 + 0x38)), (*(s32 *)((u8 *)arg0 + 0x2C)), temp_v0, arg1);
        *(u8 *)((u8 *)arg0 + 0x5D) = 1U;
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_v0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_v0);
    }
}
/* localdecomp:end func_L39_006D8638 */

/* localdecomp:start func_L39_006D86B8 */
s32 func_L39_006CE540(s32);
void func_L39_006CE5A8(s32, s32, s32, s32);

void func_L39_006D86B8(void *arg0, s32 arg1) {
    s32 temp_v0;

    if ((*(u8 *)((u8 *)arg0 + 0x5E)) == 0) {
        temp_v0 = func_L39_006CE540((*(s32 *)((u8 *)arg0 + 0x2C)));
        func_L39_006CE5A8((*(s32 *)((u8 *)arg0 + 0x38)), (*(s32 *)((u8 *)arg0 + 0x2C)), temp_v0, arg1);
        *(u8 *)((u8 *)arg0 + 0x5E) = 1U;
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_v0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_v0);
    }
}
/* localdecomp:end func_L39_006D86B8 */

/* localdecomp:start func_L39_006D8738 */
s32 func_L39_006CE690(s32);
void func_L39_006CE6F8(s32, s32, s32, s32);

void func_L39_006D8738(void *arg0, s32 arg1) {
    s32 temp_v0;

    if ((*(u8 *)((u8 *)arg0 + 0x5F)) == 0) {
        temp_v0 = func_L39_006CE690((*(s32 *)((u8 *)arg0 + 0x2C)));
        func_L39_006CE6F8((*(s32 *)((u8 *)arg0 + 0x38)), (*(s32 *)((u8 *)arg0 + 0x2C)), temp_v0, arg1);
        *(u8 *)((u8 *)arg0 + 0x5F) = 1U;
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_v0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_v0);
    }
}
/* localdecomp:end func_L39_006D8738 */

/* localdecomp:start func_L39_006D87B8 */
s32 func_L39_006CE7E0(s32);
void func_L39_006CE848(s32, s32, s32, s32);

void func_L39_006D87B8(void *arg0, s32 arg1) {
    s32 temp_v0;

    if ((*(u8 *)((u8 *)arg0 + 0x60)) == 0) {
        temp_v0 = func_L39_006CE7E0((*(s32 *)((u8 *)arg0 + 0x2C)));
        func_L39_006CE848((*(s32 *)((u8 *)arg0 + 0x38)), (*(s32 *)((u8 *)arg0 + 0x2C)), temp_v0, arg1);
        *(u8 *)((u8 *)arg0 + 0x60) = 1U;
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_v0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_v0);
    }
}
/* localdecomp:end func_L39_006D87B8 */

/* localdecomp:start func_L39_006D8838 */
s32 func_L39_006DA158(s32);
void func_L39_006DA1C0(s32, s32, s32, s32);

void func_L39_006D8838(void *arg0, s32 arg1) {
    s32 temp_v0;

    if ((*(u8 *)((u8 *)arg0 + 0x63)) == 0) {
        temp_v0 = func_L39_006DA158((*(s32 *)((u8 *)arg0 + 0x2C)));
        func_L39_006DA1C0((*(s32 *)((u8 *)arg0 + 0x4C)), (*(s32 *)((u8 *)arg0 + 0x2C)), temp_v0, arg1);
        *(u8 *)((u8 *)arg0 + 0x63) = 1U;
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_v0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_v0);
    }
}
/* localdecomp:end func_L39_006D8838 */

/* localdecomp:start func_L39_006D88B8 */
s32 func_L39_006DA2A8(s32);
void func_L39_006DA310(s32, s32, s32, s32);

void func_L39_006D88B8(void *arg0, s32 arg1) {
    s32 temp_v0;

    if ((*(u8 *)((u8 *)arg0 + 0x64)) == 0) {
        temp_v0 = func_L39_006DA2A8((*(s32 *)((u8 *)arg0 + 0x2C)));
        func_L39_006DA310((*(s32 *)((u8 *)arg0 + 0x4C)), (*(s32 *)((u8 *)arg0 + 0x2C)), temp_v0, arg1);
        *(u8 *)((u8 *)arg0 + 0x64) = 1U;
        *(s32 *)((u8 *)arg0 + 0x28) = (s32) ((*(s32 *)((u8 *)arg0 + 0x28)) - temp_v0);
        *(s32 *)((u8 *)arg0 + 0x2C) = (s32) ((*(s32 *)((u8 *)arg0 + 0x2C)) + temp_v0);
    }
}
/* localdecomp:end func_L39_006D88B8 */

/* localdecomp:start func_L39_006D8938 */
typedef struct {
    char _p0[0x28];
    s32 f28;
    s32 f2C;
    char _p30[0x4];
    u8 *f34;
    u8 *f38;
    char _p3C[0x4];
    u8 *f40;
    u8 *f44;
    char _p48[0x4];
    u8 *f4C;
    char _p50[0x4];
    u8 *f54;
    u8 f58;
    u8 f59;
    u8 f5A;
    u8 f5B;
    u8 f5C;
    u8 f5D;
    u8 f5E;
    u8 f5F;
    u8 f60;
    u8 f61;
    u8 f62;
    u8 f63;
    u8 f64;
    char _p65[0x3];
    s32 f68;
    s32 f6C;
    void *f70;
    u8 f74;
    char _p75[0x3];
    void *f78;
    u8 f7C;
} S_006D8938;

void func_L01_004D3BD0(void *);

void func_L39_006D8938(void *arg0) {
    S_006D8938 *p = (S_006D8938 *)arg0;

    if (p->f58) {
        p->f54[0x2F88] = 0;
        p->f58 = 0;
    }
    if (p->f59) {
        p->f34[0x0] = 0;
        p->f59 = 0;
    }
    if (p->f5A) {
        p->f38[0x3B4] = 0;
        p->f5A = 0;
    }
    if (p->f5B) {
        p->f38[0x3EC] = 0;
        p->f5B = 0;
    }
    if (p->f5C) {
        p->f38[0x424] = 0;
        p->f5C = 0;
    }
    if (p->f5D) {
        p->f38[0x45C] = 0;
        p->f5D = 0;
    }
    if (p->f5E) {
        p->f38[0x49C] = 0;
        p->f5E = 0;
    }
    if (p->f5F) {
        p->f38[0x4DC] = 0;
        p->f5F = 0;
    }
    if (p->f60) {
        p->f38[0x515] = 0;
        p->f60 = 0;
    }
    if (p->f61) {
        p->f40[0x0] = 0;
        p->f61 = 0;
    }
    if (p->f63) {
        p->f4C[0x15C] = 0;
        p->f63 = 0;
    }
    if (p->f64) {
        p->f4C[0x198] = 0;
        p->f64 = 0;
    }
    if (p->f62) {
        p->f44[0x0] = 0;
        p->f62 = 0;
    }
    if (p->f74) {
        func_L01_004D3BD0(p->f70);
        p->f70 = 0;
        p->f74 = 0;
    }
    if (p->f7C) {
        func_L01_004D3BD0(p->f78);
        p->f78 = 0;
        p->f7C = 0;
    }
    p->f2C = p->f6C;
    p->f28 = p->f68;
}
/* localdecomp:end func_L39_006D8938 */

/* localdecomp:start func_L39_006D8AD8 */
extern s32 func_001961F8(void);
extern s32 func_0012DCB0(void);
extern long func_00130760(s32, long);

s32 func_L39_006D8AD8(u8 *arg0) {
    s32 r = 1;
    s32 v;
    s32 diff;

    if (func_001961F8() != 0) {
        v = 8;
    } else {
        if (*(u8 *)((u8 *)arg0 + 0x1) == 0) {
            goto done;
        }
        if (*(s32 *)((u8 *)arg0 + 0x8) == 0) {
            goto done;
        }
        if (*(s32 *)((u8 *)arg0 + 0xC) <= 0) {
            goto done;
        }
        diff = (s32)func_00130760(func_0012DCB0(), 0x24000) - *(s32 *)((u8 *)arg0 + 0x8);
        if (*(s32 *)((u8 *)arg0 + 0xC) < diff) {
            v = 2;
        } else {
            goto done;
        }
    }
    *(s32 *)((u8 *)arg0 + 0x10) = v;
    if (*(s32 *)((u8 *)arg0 + 0x14) == 0) {
        *(s32 *)((u8 *)arg0 + 0x14) = v;
    }
    r = 0;
done:
    return r;
}
/* localdecomp:end func_L39_006D8AD8 */

/* localdecomp:start func_L39_006D8B88 */
typedef struct G_006D8B88 {
    u8 pad0[0x2D8];
    s32 f2D8;
    s32 f2DC;
    u8 pad2E0[4];
    u8 f2E4;
} G_006D8B88;
extern u8 D_001A5CD0[];
s32 func_001961F8(void);
s32 func_0019B7A8(void);
s32 func_0019B5C8(void);
s32 func_L39_006DE2F0(void *);
s32 func_L39_006CD6E0(void *);
s32 func_L39_006D05A0(void *);
s32 func_L39_006D5CE0(u8 *);
s32 func_L39_006D66B8(void *);
s32 func_L39_006D7838(u8 *);
s32 func_L39_006D59D8(void *);
s32 func_L39_006D4B98(void *);
s32 func_L39_006DA958(void *);

typedef struct S_006D8B88 {
    u8 pad0[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0x34 - 0x18];
    void *f34;
    void *f38;
    void *f3C;
    void *f40;
    void *f44;
    u8 pad48[0x4C - 0x48];
    void *f4C;
    u8 pad50[0x54 - 0x50];
    void *f54;
    u8 pad58[0x70 - 0x58];
    void *f70;
    u8 f74;
    u8 pad75[0x78 - 0x75];
    void *f78;
    u8 pad7C[0x80 - 0x7C];
    s32 f80;
    s32 f84;
} S_006D8B88;

s32 func_L39_006D8B88(S_006D8B88 *arg0)
{
    s32 r;
    r = 1;
    if (((G_006D8B88 *)D_001A5CD0)->f2E4 == 0) {
        return 0;
    }
    if (func_001961F8() != 0) {
        arg0->f10 = 8;
        if (arg0->f14 == 0) {
            arg0->f14 = 8;
        }
        r = 0;
    }
    if (((G_006D8B88 *)D_001A5CD0)->f2DC != 0) {
        arg0->f80++;
    } else {
        arg0->f80 = 0;
    }
    if (arg0->f80 > 0x3C) {
        arg0->f10 = 8;
        if (arg0->f14 == 0) {
            arg0->f14 = 8;
        }
        r = 0;
    }
    if (func_0019B7A8() != 0) {
        if (((G_006D8B88 *)D_001A5CD0)->f2D8 != 0) {
            arg0->f84++;
        } else {
            arg0->f84 = 0;
        }
        if (arg0->f84 > 0x3C) {
            arg0->f10 = 8;
            if (arg0->f14 == 0) {
                arg0->f14 = 8;
            }
            r = 0;
        }
    }
    if (arg0->f54 != 0) {
        func_L39_006DE2F0(arg0->f54);
    }
    if (arg0->f34 != 0) {
        func_L39_006CD6E0(arg0->f34);
    }
    if (arg0->f38 != 0) {
        func_L39_006D05A0(arg0->f38);
    }
    if (arg0->f40 != 0) {
        func_L39_006D5CE0(arg0->f40);
    }
    if (arg0->f44 != 0) {
        func_L39_006D66B8(arg0->f44);
    }
    if (arg0->f78 != 0) {
        func_L39_006D7838(arg0->f78);
    }
    if (r != 0) {
        if (arg0->f74) {
            r = func_L39_006D59D8(arg0->f70);
        }
        if (r != 0) {
            if (arg0->f3C != 0 && ~func_0019B5C8() != 0) {
                r = func_L39_006D4B98(arg0->f3C);
            }
            if (r != 0 && arg0->f4C != 0) {
                r = func_L39_006DA958(arg0->f4C);
            }
        }
    }
    return r;
}
/* localdecomp:end func_L39_006D8B88 */

/* localdecomp:start func_L39_006D8D80 */
extern u8 D_00198028[];
extern u8 D_00198050[];
extern u8 D_00198078[];
extern u8 D_001A5CD0[];

s32 func_0017DE30(void *, void *);
void func_001961E8(s32);
s32 func_001961F8(void);
void func_0019B6D8(s32);
void func_0019B5B8(s32);

s32 func_L39_006D8D80(void *arg0) {
    s32 loc[16];
    u8 *p;
    s32 v;

    loc[0] = (s32)D_00198028;
    loc[4] = 0;
    loc[6] = (s32)D_00198050;
    loc[8] = (s32)D_00198078;
    func_001961E8(func_0017DE30(loc, &loc[12]));
    if (func_001961F8() != 0) {
        v = *(s32 *)((u8 *)arg0 + 0x14);
        *(s32 *)((u8 *)arg0 + 0x10) = 5;
        if (v == 0) {
            *(s32 *)((u8 *)arg0 + 0x14) = 5;
        }
        return 0;
    }
    p = D_001A5CD0;
    *(u8 *)(p + 0x2E6) = 0;
    *(s32 *)(p + 0x2E8) = 0;
    *(u8 *)(p + 0x2E4) = 1;
    func_0019B6D8(1);
    func_0019B5B8(-1);
    return 1;
}
/* localdecomp:end func_L39_006D8D80 */

/* localdecomp:start func_L39_006D8E30 */
typedef struct {
    u8 pad0[0x9D];
    u8 f9D;
} S3_006D8E30;
typedef struct {
    u8 pad0[0x50];
    S3_006D8E30 *f50;
} S_006D8E30;
extern u8 D_001A5FB4[];
s32 func_0019B720(void);
void func_0017DF60(void);
void func_L39_006DD340(void *);

s32 func_L39_006D8E30(S_006D8E30 *arg0) {
    D_001A5FB4[0] = 0;
    func_0019B720();
    if (arg0->f50->f9D) {
        func_L39_006DD340(arg0->f50);
    }
    func_0017DF60();
    return 1;
}
/* localdecomp:end func_L39_006D8E30 */
