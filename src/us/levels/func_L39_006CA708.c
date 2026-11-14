#include "common.h"

/* NTSC-U counterpart of func_L39_006CCE90 (src/levels/39_multiplayer_menu/L39_006CCE90.c) */
/* localdecomp:start func_L39_006CA708 */
typedef struct {
    u16 f00;
    char _p02[0x66 - 0x02];
} Loc_006CCE90;
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
} G_006CCE90;
typedef struct {
    char _p0[0x4];
    char name[0x20];
    u8 f24;
    char _p25[0x30 - 0x25];
    u8 f30;
    char _p31[0x6C - 0x31];
    s32 f6C;
} S_006CCE90;
typedef struct {
    char _p0[0x2DC];
    s32 f2DC;
} P_006CCE90;

void func_00120D28(s32, s32, s32);
void *func_001206F4(void *, void *);
s32 func_00120884(void *);
extern void func_L39_005945F0(s32, s32, s32);
long func_0012DCB0(void);
long func_00130760(long, long);
s32 func_0017E4E0(void *, void *, s32);
void func_001962D8(s32);
s32 func_001962E8(void);
void func_00195500(void);
s32 func_L39_006D5F80(u8 *);
extern u8 D_001977B8[];
extern void *D_001E1FD0_sda;
extern u16 D_L39_00249C98[];
extern u8 D_001A5E50[];

/* same shape as func_L39_006DCAD0 */
s32 func_L39_006CA708(S_006CCE90 *arg0, void *arg1, void *arg2) {
    Loc_006CCE90 loc;
    G_006CCE90 *g;
    P_006CCE90 *p;
    s32 r;

    g = (G_006CCE90 *)D_001E1FD0_sda;
    func_00120D28((s32)arg0->name, (s32)arg1, 0x20);
    arg0->f24 = 0;
    loc.f00 = D_L39_00249C98[0];
    func_001206F4((u8 *)&loc + 0x15, (void *)g->f50);
    func_L39_005945F0((s32)((u8 *)&loc + 0x26), (s32)arg0->name, func_00120884(arg0->name));
    func_L39_005945F0((s32)((u8 *)&loc + 0x46), (s32)arg2, 0x20);
    arg0->f30 = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017E4E0(&loc, D_001977B8, 0));
    p = (P_006CCE90 *)D_001A5E50;
    while (arg0->f30 != 0) {
        if (func_001962E8() != 0 || p->f2DC != 0) {
            g->f10 = 9;
            if (g->f14 == 0) {
                g->f14 = 9;
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
    arg0->f30 = 0;
    if (r != 0) {
        if (arg0->f6C != 0) {
            g->f10 = 9;
            if (g->f14 == 0) {
                g->f14 = 9;
            }
            r = 0;
        }
    }
    if (r != 0) {
        g->f10 = 0;
        g->f14 = 0;
    }
    return r;
}
/* localdecomp:end func_L39_006CA708 */
