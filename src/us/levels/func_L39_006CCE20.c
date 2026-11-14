#include "common.h"

/* NTSC-U counterpart of func_L39_006CF5A8 (src/levels/39_multiplayer_menu/L39_006CCE90.c) */
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
extern u16 D_L39_00249D58[];
extern void *func_001206F4(void *, void *);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void func_00195500(void);
extern void func_L39_005945F0(s32, s32, s32);
extern u16 D_L39_00249D58[];
extern u8 D_001A5E50[];
extern void *D_L39_0024D860;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void func_00195500(void);
extern s32 func_L39_006D5F80(u8 *);
extern void *D_L39_0024D860;
extern u16 D_L39_00249D58[];
extern u8 D_001A5E50[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern void func_L39_005945F0(s32, s32, s32);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void func_00195500(void);
extern s32 func_L39_006D5F80(u8 *);
extern u16 D_L39_00249D58[];
extern void *func_001206F4(void *, void *);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void func_00195500(void);
extern void func_L39_005945F0(s32, s32, s32);
s32 func_L39_006CE648(u8 *);

/* localdecomp:start func_L39_006CCE20 */
typedef struct {
    u16 f00;
    char _p02[0x28 - 0x02];
    s32 f28;
    char _p2C[0xF4 - 0x2C];
} Loc_006CF5A8;
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
} G_006CF5A8;
typedef struct {
    char _p0[0x84];
    u8 f84;
    char _p85[0x88 - 0x85];
    s32 f88;
    char _p8C[0x3EC - 0x8C];
    u8 f3EC;
    char _p3ED[0x3F4 - 0x3ED];
    u8 f3F4;
} S_006CF5A8;
typedef struct {
    char _p0[0x2DC];
    s32 f2DC;
} P_006CF5A8;

extern void func_L39_005945F0(s32, s32, s32);
s32 func_0017D3F8(void *, void *, s32);
s32 func_L39_006CE648(u8 *);
__asm__(".extern D_L39_0024D860, 16");
extern u8 D_00197BF0[];

/* same shape as func_L39_006DCAD0 */
s32 func_L39_006CCE20(S_006CF5A8 *arg0, s32 arg1, void *arg2) {
    Loc_006CF5A8 loc;
    G_006CF5A8 *g;
    P_006CF5A8 *p;
    s32 r;
    s32 code;
    void *name;

    g = (G_006CF5A8 *)D_L39_0024D860;
    name = (void *)g->f50;
    loc.f00 = D_L39_00249D58[0];
    func_001206F4((u8 *)&loc + 0x15, name);
    loc.f28 = arg1;
    func_L39_005945F0((s32)((u8 *)&loc + 0x2C), (s32)arg2, 0xC8);
    arg0->f84 = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017D3F8(&loc, D_00197BF0, 0));
    p = (P_006CF5A8 *)D_001A5E50;
    while (arg0->f84 != 0) {
        if (func_001962E8() != 0 || p->f2DC != 0) {
            g->f10 = 0x1E;
            if (g->f14 == 0) {
                g->f14 = 0x1E;
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
    arg0->f84 = 0;
    if (r != 0) {
        if (arg0->f88 == -0x3DE) {
            g->f10 = 0x23;
            if (g->f14 == 0) {
                g->f14 = 0x23;
            }
            r = 0;
        } else if (arg0->f88 != 0) {
            g->f10 = 0x1E;
            if (g->f14 == 0) {
                g->f14 = 0x1E;
            }
            r = 0;
        }
    }
    if (r != 0 && arg0->f3EC != 0 && arg0->f3F4 == 0) {
        r = func_L39_006CE648((u8 *)arg0);
    }
    return r;
}
/* localdecomp:end func_L39_006CCE20 */
