#include "common.h"

/* NTSC-U counterpart of func_L39_006DCAD0 (src/levels/39_multiplayer_menu/L39_006DC228.c) */
/* localdecomp:start func_L39_006D9F70 */
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

s32 func_0019B850(void);
s32 func_0019B8B8(s32);
s32 func_001206F4(void *, s32);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
s32 func_0017E3E8(void *, void *, s32);
void func_001962D8(s32);
s32 func_001962E8();
void func_00195500(void);
void func_00197FD8(void);
s32 func_L39_006D5F80(u8 *);
void func_L39_006D55A0(void *);
s32 func_L39_006DA7E0(void *);
extern void *D_001E1FD0_sda;
extern u16 D_L39_0024A0B0[];
extern u8 D_001A5E50[];

s32 func_L39_006D9F70(S_006DCAD0 *arg0, s32 arg1) {
    Loc_006DCAD0 loc;
    G_006DCAD0 *g;
    P_006DCAD0 *p;
    s32 r;

    g = D_001E1FD0_sda;
    if (func_0019B850() != 0 && func_0019B8B8(1) != 0) {
        g->f10 = 7;
        if (g->f14 == 0) {
            g->f14 = 7;
        }
        return 0;
    }
    loc.f00 = D_L39_0024A0B0[0];
    func_001206F4((u8 *)&loc + 0x15, g->f50);
    arg0->f9A = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017E3E8(&loc, func_00197FD8, 0));
    p = (P_006DCAD0 *)D_001A5E50;
    while (arg0->f9A != 0) {
        if (func_001962E8() != 0 || p->f2DC != 0) {
            g->f10 = 0x4C;
            if (g->f14 == 0) {
                g->f14 = 0x4C;
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
        if (func_L39_006DA7E0(arg0) == 0) {
            r = 0;
        }
    }
    if (arg1 != 0) {
        func_L39_006D55A0(g);
    }
    return r;
}
/* localdecomp:end func_L39_006D9F70 */
