#include "common.h"

/* NTSC-U counterpart of func_L39_006CF3E8 (src/levels/39_multiplayer_menu/L39_006CCE90.c) */
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

/* localdecomp:start func_L39_006CCC60 */
__asm__(".extern D_L39_0024D860, 16");
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x11];
    u8 f26[0xC8];
} Loc_006CF3E8;
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
} G_006CF3E8;
typedef struct {
    u8 pad0[0x7C];
    u8 f7C;
    u8 pad7D[3];
    s32 f80;
    u8 pad84[0x3EC - 0x84];
    u8 f3EC;
    u8 pad3ED[7];
    u8 f3F4;
} S_006CF3E8;
typedef struct {
    u8 pad0[0x2DC];
    s32 f2DC;
} D_006CF3E8;
extern u16 D_L39_00249D58[];
extern u8 D_00197B50[];
extern void *func_001206F4(void *, void *);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_0017D378(void *, u8 *, s32);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void func_00195500(void);
extern void func_L39_005945F0(s32, s32, s32);
s32 func_L39_006CE648(u8 *);

s32 func_L39_006CCC60(S_006CF3E8 *p, void *a) {
    G_006CF3E8 *g;
    Loc_006CF3E8 x;
    void *n;
    D_006CF3E8 *d;
    s32 r;

    g = D_L39_0024D860;
    n = g->f50;
    x.f0 = D_L39_00249D58[0];
    func_001206F4(x.f15, n);
    ((void (*)(void *, void *, s32))func_L39_005945F0)(x.f26, a, 0xC8);
    p->f7C = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017D378(&x, D_00197B50, 0));
    d = (D_006CF3E8 *)D_001A5E50;
    while (p->f7C) {
        if (func_001962E8() != 0 || d->f2DC != 0) {
            g->f10 = 0x1D;
            if (g->f14 == 0) {
                g->f14 = 0x1D;
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
    p->f7C = 0;
    if (r) {
        if (p->f80 == -0x3DE) {
            g->f10 = 0x23;
            if (g->f14 == 0) {
                g->f14 = 0x23;
            }
            r = 0;
        } else if (p->f80 != 0) {
            g->f10 = 0x1D;
            if (g->f14 == 0) {
                g->f14 = 0x1D;
            }
            r = 0;
        }
        if (r && p->f3EC && !p->f3F4) {
            r = func_L39_006CE648((u8 *)p);
        }
    }
    return r;
}
/* localdecomp:end func_L39_006CCC60 */
