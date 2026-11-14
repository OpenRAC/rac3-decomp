#include "common.h"

/* NTSC-U counterpart of func_L39_006D2FA0 (src/levels/39_multiplayer_menu/L39_006D08E8.c) */
extern void *D_L39_0024D860;
extern u8 D_001A5E50[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
void *func_001206F4(void *, void *);
long func_0012DCB0(void);
long func_00130760(long, long);
void func_001962D8(s32);
s32 func_001962E8(void);
void func_00195500(void);
s32 func_L39_006D5F80(u8 *);
extern u16 D_L39_00249D58[];
extern void *func_001206F4(void *, void *);
extern u16 D_L39_00249D58[];
void func_001962D8(s32);
s32 func_001962E8(void);
extern u16 D_L39_00249D58[];
extern void *func_001206F4(void *, void *);
extern void *D_L39_0024D860;
extern u16 D_L39_00249D58[];
extern void *func_001206F4(void *, void *);
extern u16 D_L39_00249D58[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_001962E8(void);
extern u16 D_L39_00249D58[];
extern u16 D_L39_00249D58[];
extern void *D_L39_0024D860;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);

/* localdecomp:start func_L39_006D0818 */
typedef struct {
    u16 f00;
    char _p02[0x15 - 0x02];
    u8 f15[0x28 - 0x15];
    s32 f28;
    u8 f2C[0x20];
    char _p4C[0x50 - 0x4C];
} Loc_006D2FA0;
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
    void *f50;
} G_006D2FA0;
typedef struct {
    char _p0[0xD4];
    u8 fD4;
    char _pD5[0xD8 - 0xD5];
    u8 fD8[0xF0 - 0xD8];
    s32 fF0;
} S_006D2FA0;
typedef struct {
    char _p0[0x2DC];
    s32 f2DC;
} P_006D2FA0;

__asm__(".extern D_L39_0024D860, 16");
extern s32 func_00183CCC(void);
extern void func_L39_005945F0(s32, s32, s32);
extern s32 func_0017CE78(void *, void *, s32);
extern void func_00197880(void);
extern void func_00195500(void);
extern u8 D_001A5E50[];

void *func_L39_006D0818(S_006D2FA0 *arg0, void *arg1) {
    Loc_006D2FA0 loc;
    G_006D2FA0 *g;
    P_006D2FA0 *p;
    s32 r;
    void *t;

    g = D_L39_0024D860;
    t = g->f50;
    loc.f00 = D_L39_00249D58[0];
    func_001206F4(loc.f15, t);
    loc.f28 = func_00183CCC();
    func_L39_005945F0((s32)loc.f2C, (s32)arg1, 0x20);
    arg0->fD4 = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017CE78(&loc, func_00197880, 0));
    p = (P_006D2FA0 *)D_001A5E50;
    while (arg0->fD4 != 0) {
        if (func_001962E8() != 0 || p->f2DC != 0) {
            g->f10 = 0x26;
            if (g->f14 == 0) {
                g->f14 = 0x26;
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
    arg0->fD4 = 0;
    if (r != 0) {
        if (arg0->fF0 != 0) {
            r = 0;
        }
    }
    return r ? arg0->fD8 : 0;
}
/* localdecomp:end func_L39_006D0818 */
