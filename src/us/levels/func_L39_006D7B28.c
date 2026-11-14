#include "common.h"

/* NTSC-U counterpart of func_L39_006DA680 (src/levels/39_multiplayer_menu/L39_006D9FD8.c) */
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
s32 func_L39_006DD608_006D7B28(s32, void *, s32);
s32 func_001206F4(void *, s32);
void func_L39_005945F0(void *, void *, s32);
void *func_0017EC38(void *);
void func_001962D8(void *);
s32 func_001962E8(void);
extern u16 D_L39_0024A050[];
s32 func_L39_006E16A0_006D7B28(void *, s32, s32, s32);
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
s32 func_L39_006E16A0_006D7B28(void *, s32, s32, s32);
s32 func_L39_006E1648_006D7B28(s32, s32, s32, s32);
void func_0011D534(s32, s32, s32);
s32 func_L39_006E16A0_006D7B28(void *, s32, s32, s32);
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
s32 func_L39_006E16A0_006D7B28(void *, s32, s32, s32);
s32 func_L39_006E1648_006D7B28(s32, s32, s32, s32);
void func_0011D534(s32, s32, s32);
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
void func_00195500(void);
typedef struct { char bytes[32]; } Block_6DA628;
typedef struct { char pad[0xc0]; unsigned char fC0; char pad2[3]; Block_6DA628 fC4; } Type1_6DA628;
typedef struct { char pad[0x4c]; Type1_6DA628 *f4C; } Type2_6DA628;

/* localdecomp:start func_L39_006D7B28 */
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
void *func_0017EA10_006D7B28(void *, void (*)(void), s32);
void func_00197F10_006D7B28(void);
void func_00195500(void);
extern s32 func_L39_006D5F80(void *);
s32 func_L39_006DA7E0(void *);
s32 func_L39_006DA500(void *, void *);
extern P_006DA680 D_001A5E50_006D7B28;

s32 func_L39_006D7B28(S_006DA680 *a0, s32 a1, void *a2) {
    Loc_006DA680 loc;
    G_006DA680 *g = (G_006DA680 *)D_L39_0024D860;
    s32 x = g->f50;
    s32 r;

    loc.f00 = D_L39_0024A050[0];
    func_001206F4((u8 *)&loc + 0x15, x);
    loc.f28 = a1;
    if (a2) {
        func_L39_005945F0(loc.f2C, a2, 0x20);
    } else {
        loc.f2C[0] = 0;
    }
    a0->f4 = 1;
    g->f1 = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017EA10_006D7B28(&loc, func_00197F10_006D7B28, 0));
    r = 1;
    while (a0->f4 != 0) {
        if (func_001962E8() != 0 || D_001A5E50_006D7B28.f2DC != 0) {
            g->f10 = 0x42;
            if (g->f14 == 0) {
                g->f14 = 0x42;
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
    if (r != 0 && (r = func_L39_006DA7E0((void *)x)) != 0
        && (r = func_L39_006DA500((void *)x, a0->f24)) != 0) {
        a0->f0 = a1;
    } else {
        a0->f0 = -1;
    }
    D_001A5E50_006D7B28.f78 = a0->f0;
    return r;
}
/* localdecomp:end func_L39_006D7B28 */
