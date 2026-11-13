#include "common.h"

/* NTSC-U counterpart of func_L39_006CEA18 (src/levels/39_multiplayer_menu/L39_006CCE90.c) */
extern void *D_L39_0024D860;
extern u8 D_001A5E50[];
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);

/* localdecomp:start func_L39_006CC290 */
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

__asm__(".extern D_L39_0024D860, 16");
extern void *D_L39_0024D860;
void func_00120D28(s32, s32, s32);
void *func_001206F4(void *, void *);
long func_0012DCB0(void);
long func_00130760(long, long);
s32 func_0017D6F8(void *, void *, s32);
void func_001962D8(s32);
s32 func_001962E8(void);
void func_00195500(void);
void func_001962F8(void);
s32 func_L39_006D5F80(u8 *);
s32 func_L39_006D46C0(void *, s32, s32, void *);
void func_L39_006D46A0(void *, s32, void *);
s32 func_L39_006D0790(void *, void *, void *);
void func_L39_006D0768(void *, s32, s32);
R_006CEA18 *func_L39_006D67D0(void *, s32);
extern u8 D_00197970[];
extern u16 D_L39_00249D58[];
extern u8 D_001A5E50[];

s32 func_L39_006CC290(A_006CEA18 *a, s32 arg1) {
    Loc_006CEA18 loc;
    Loc2_006CEA18 loc2;
    s32 o1;
    s32 o2;
    G_006CEA18 *g;
    s32 r;
    void *name;

    g = (G_006CEA18 *)D_L39_0024D860;
    name = (void *)g->f50;
    loc.f00 = D_L39_00249D58[0];
    func_001206F4((u8 *)&loc + 0x15, name);
    loc.f28 = 1;
    loc.f2C = 1;
    a->f5C = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017D6F8(&loc, D_00197970, 0));
    while (a->f5C != 0) {
        if (func_001962E8() != 0 || ((P_006CEA18 *)D_001A5E50)->f2DC != 0) {
            g->f10 = 0x14;
            if (g->f14 == 0) {
                g->f14 = 0x14;
            }
            r = 0;
            break;
        }
        g->f1C = 1;
        func_00195500();
        g->f1C = 0;
        if (func_L39_006D5F80((u8 *)g) == 0) {
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

        func_00120D28((s32)((P_006CEA18 *)D_001A5E50)->f80, (s32)a->f30, 4);
        ((P_006CEA18 *)D_001A5E50)->f84 = 0;
        id = a->f0;
        key = *((G_006CEA18 *)D_L39_0024D860)->f30;
        if (((P_006CEA18 *)D_001A5E50)->fAC != id || ((P_006CEA18 *)D_001A5E50)->fA9 != a->f34 || arg1 != 0) {
            ((P_006CEA18 *)D_001A5E50)->fAC = id;
            ((P_006CEA18 *)D_001A5E50)->fA9 = a->f34;
            func_001962F8();
            if (func_L39_006D46C0(((G_006CEA18 *)D_L39_0024D860)->f44, key, 0, &loc2) != 0) {
                loc2.f30 = id;
                loc2.f104 = id;
                func_L39_006D46A0(((G_006CEA18 *)D_L39_0024D860)->f44, 0, &loc2);
            }
        }
        if (a->f34 != 0) {
            a->f35 = 1;
            if (func_L39_006D0790(a, &o1, &o2) == 0 && o1 >= 0) {
                func_L39_006D0768(a, -1, -1);
            }
        } else {
            R_006CEA18 *e = func_L39_006D67D0(((G_006CEA18 *)D_L39_0024D860)->f48, a->f38);
            a->f35 = e != 0 && e->f40 != 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006CC290 */
