#include "common.h"

/* NTSC-U counterpart of func_L39_006CEEE0 (src/levels/39_multiplayer_menu/L39_006CCE90.c) */
void *func_001206F4(void *, void *);
extern void func_L39_005945F0(s32, s32, s32);
long func_0012DCB0(void);
long func_00130760(long, long);
void func_001962D8(s32);
s32 func_001962E8(void);
void func_00195500(void);
s32 func_L39_006D5F80(u8 *);
extern u8 D_001A5E50[];
extern void *D_L39_0024D860;
extern u8 D_001A5E50[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void func_00195500(void);
extern s32 func_L39_006D5F80(u8 *);
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
extern void *D_L39_0024D860;
extern u8 D_001A5E50[];
extern void *D_L39_0024D860;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void func_00195500(void);
extern s32 func_L39_006D5F80(u8 *);
extern u8 D_001A5E50[];
extern void *D_L39_0024D860;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void func_00195500(void);
extern s32 func_L39_006D5F80(u8 *);
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
extern void *D_L39_0024D860;
void *func_001206F4(void *, void *);
long func_0012DCB0(void);
long func_00130760(long, long);
void func_001962D8(s32);
s32 func_001962E8(void);
void func_00195500(void);
s32 func_L39_006D5F80(u8 *);
extern u16 D_L39_00249D58[];
extern u8 D_001A5E50[];
extern void *D_L39_0024D860;
extern u8 D_001A5E50[];
extern void *func_001206F4(void *, void *);

/* localdecomp:start func_L39_006CC758 */
__asm__(".extern D_L39_0024D860, 16");
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
extern u16 D_L39_00249D58[];
extern u8 D_001978D0[];
extern void *func_001206F4(void *, void *);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_0017CD78(void *, u8 *, s32);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void func_00195500(void);
extern void func_L39_005945F0(s32, s32, s32);
extern s32 func_00183CCC(void);

s32 func_L39_006CC758(S_006CEEE0 *p, void *a) {
    G_006CEEE0 *g;
    Loc_006CEEE0 x;
    void *n;
    D_006CEEE0 *d;
    s32 r;

    g = D_L39_0024D860;
    n = g->f50;
    x.f0 = D_L39_00249D58[0];
    func_001206F4(x.f15, n);
    x.f28 = func_00183CCC();
    ((void (*)(void *, void *, s32))func_L39_005945F0)(x.f2C, a, 0x20);
    p->f64 = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017CD78(&x, D_001978D0, 0));
    d = (D_006CEEE0 *)D_001A5E50;
    while (p->f64) {
        if (func_001962E8() != 0 || d->f2DC != 0) {
            g->f10 = 0x15;
            if (g->f14 == 0) {
                g->f14 = 0x15;
            }
            r = 0;
            break;
        }
        g->f1C = 1;
        func_00195500();
        g->f1C = 0;
        if (!func_L39_006D5F80((u8 *)g)) {
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
            r = func_L39_006CC290((A_006CEA18 *)p, 0);
        }
    }
    return r;
}
/* localdecomp:end func_L39_006CC758 */
