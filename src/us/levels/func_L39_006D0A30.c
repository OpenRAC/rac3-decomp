#include "common.h"

/* NTSC-U counterpart of func_L39_006D31B8 (src/levels/39_multiplayer_menu/L39_006CCE90.c) */
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
void func_001962D8(s32);
s32 func_001962E8(void);
extern u16 D_L39_00249D58[];
extern void *func_001206F4(void *, void *);
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

/* localdecomp:start func_L39_006D0A30 */
__asm__(".extern D_L39_0024D860, 16");
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x13];
    s32 f28;
    s32 f2C;
} Loc_006D31B8;
typedef struct {
    u8 pad0[0x220];
    u8 f220;
    u8 pad221[3];
    u8 f224[0x18];
    s32 f23C;
} S_006D31B8;
typedef struct {
    u8 f0;
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
} G_006D31B8;
typedef struct {
    u8 pad[0x2DC];
    s32 f2DC;
} P_006D31B8;
extern u8 D_001978A8[];
extern u8 D_001A5E50[];
extern s32 func_0017CEF8(void *, u8 *, s32);
extern void func_00195500(void);
extern s32 func_L39_006D5F80(u8 *);

/* follows func_L39_006DCAD0 */
void *func_L39_006D0A30(S_006D31B8 *arg0, s32 arg1, s32 arg2) {
    G_006D31B8 *g = D_L39_0024D860;
    P_006D31B8 *p;
    s32 r;
    Loc_006D31B8 loc;
    void *t;
    s32 one;

    t = g->f50;
    loc.f0 = D_L39_00249D58[0];
    func_001206F4(loc.f15, t);
    loc.f28 = arg1;
    loc.f2C = arg2;
    arg0->f220 = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017CEF8(&loc, D_001978A8, 0));
    p = (P_006D31B8 *)D_001A5E50;
    while (arg0->f220 != 0) {
        if (func_001962E8() != 0 || p->f2DC != 0) {
            g->f10 = 0x27;
            if (g->f14 == 0) {
                g->f14 = 0x27;
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
    arg0->f220 = 0;
    if (r != 0) {
        if (arg0->f23C != 0) {
            g->f10 = 0x27;
            if (g->f14 == 0) {
                g->f14 = 0x27;
            }
            r = 0;
        }
    }
    return r != 0 ? arg0->f224 : 0;
}
/* localdecomp:end func_L39_006D0A30 */
