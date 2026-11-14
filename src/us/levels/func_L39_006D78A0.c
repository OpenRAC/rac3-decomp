#include "common.h"

/* NTSC-U counterpart of func_L39_006DA3F8 (src/levels/39_multiplayer_menu/L39_006D9FD8.c) */
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
extern Obj_006DA090 *D_L39_0024D860;
s32 func_001206F4(void *, s32);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
void func_001962D8(void *);
s32 func_001962E8(void);
void func_00195500(void);
extern s32 func_L39_006D5F80(void *);
void func_L39_005945F0(void *, void *, s32);
extern Obj_006DA090 *D_L39_0024D860 __attribute__((section(".data")));

typedef struct {
 int f0; char f4; char pad5[0xBB]; char fC0; char padC1[0x23];
 char fE4; char padE5[7]; char fEC; char padED[7]; char fF4;
 char padF5[0x67]; char f15C, f15D; char pad15E[2]; int f160, f164;
 char f168; char pad169[3]; int f16C, f170; char pad174[0x24];
 char f198, f199; char pad19A[2]; int f19C, f1A0; char f1A4;
 char pad1A5[3]; int f1A8, f1AC;
} Type1;
s32 func_L39_006DD608_006D78A0(s32, void *, s32);
s32 func_001206F4(void *, s32);
void func_L39_005945F0(void *, void *, s32);
void *func_0017EC38(void *);
void func_001962D8(void *);
s32 func_001962E8(void);
extern u16 D_L39_0024A050[];
s32 func_L39_006E16A0_006D78A0(void *, s32, s32, s32);
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
s32 func_L39_006E16A0_006D78A0(void *, s32, s32, s32);
s32 func_L39_006E1648_006D78A0(s32, s32, s32, s32);
void func_0011D534(s32, s32, s32);
s32 func_L39_006E16A0_006D78A0(void *, s32, s32, s32);
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
s32 func_L39_006E16A0_006D78A0(void *, s32, s32, s32);
s32 func_L39_006E1648_006D78A0(s32, s32, s32, s32);
void func_0011D534(s32, s32, s32);

/* localdecomp:start func_L39_006D78A0 */
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
s32 func_00183CCC_006D78A0(void);
void *func_0017E890_006D78A0(void *, void (*)(void), s32);
void func_00197EC0_006D78A0(void);
void func_00195500(void);
extern P_006DA3F8 D_001A5E50_006D78A0;

s32 func_L39_006D78A0(S_006DA3F8 *a0, Src_006DA3F8 *a1, s32 *a2) {
    Loc_006DA3F8 loc;
    G_006DA3F8 *g = (G_006DA3F8 *)D_L39_0024D860;
    s32 x = g->f50;
    s32 r;
    P_006DA3F8 *p;
    s32 v;

    func_0011D534((s32)&loc, 0, sizeof(loc));
    loc.f00 = D_L39_0024A050[0];
    func_001206F4((u8 *)&loc + 0x15, x);
    loc.f28 = func_00183CCC_006D78A0();
    loc.f2C = a1->f60;
    loc.f90 = a1->f64;
    loc.f94 = a1->f68;
    loc.f98 = a1->f6C;
    loc.f9C = a1->f70;
    loc.fA0 = a1->f74;
    func_L39_005945F0(loc.f30, a1->f00, 0x40);
    func_L39_005945F0(loc.f70, a1->f40, 0x20);
    a0->fC0 = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017E890_006D78A0(&loc, func_00197EC0_006D78A0, 0));
    p = &D_001A5E50_006D78A0;
    while (a0->fC0 != 0) {
        if (func_001962E8() != 0 || p->f2DC != 0) {
            g->f10 = 0x40;
            if (g->f14 == 0) {
                g->f14 = 0x40;
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
/* localdecomp:end func_L39_006D78A0 */
