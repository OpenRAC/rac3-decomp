#include "common.h"

/* NTSC-U counterpart of func_L39_006D34D8 (src/levels/39_multiplayer_menu/L39_006D08E8.c) */
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
extern void *func_001206F4(void *, void *);
void func_001962D8(s32);
s32 func_001962E8(void);
extern void func_0011D534(void *, s32, s32);
extern void func_0011D534(void *, s32, s32);
extern void *func_001206F4(void *, void *);
extern void *D_L39_0024D860;
void func_0011D534(void *, s32, s32);
extern void *func_001206F4(void *, void *);
extern void func_0011D534(void *, s32, s32);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void func_0011D534(void *, s32, s32);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_001962E8(void);
extern void func_0011D534(void *, s32, s32);
extern void *D_L39_0024D860;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void func_0011D534(void *, s32, s32);
extern void func_L39_005945F0(s32, s32, s32);
extern void func_00195500(void);
extern u8 D_001A5E50[];
extern u8 D_001A5E50[];
extern void func_00195500(void);
extern s32 func_L39_006D5F80(u8 *);
extern void *D_L39_0024D860;

/* localdecomp:start func_L39_006D0D50 */
__asm__(".extern D_L39_0024D860, 16");
__asm__(".extern D_L39_002407C8, 16");
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
    u8 pad1D[0x13];
    s32 *f30;
    u8 pad34[0x1C];
    void *f50;
} G_006D34D8;
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x13];
    s32 f28;
    u8 pad2C[4];
    u8 f30[0x20];
    s32 f50;
    u8 pad54[0x70];
} Loc_006D34D8;
typedef struct { u8 b[0x20]; } Blk_006D34D8;
typedef struct { u8 b[0x10]; } Blk16_006D34D8;
typedef struct {
    s32 f0;
    s32 f4;
    Blk16_006D34D8 f8;
    Blk16_006D34D8 f18;
    u16 f28;
    u16 f2A;
    u16 f2C;
    u16 f2E;
    u8 f30[0x10];
    u8 f40[0x10];
    u8 f50[8];
} Msg_006D34D8;
typedef struct {
    u8 pad0[4];
    s32 f4;
    u8 pad8[4];
    s32 fC;
    u8 pad10[8];
    s32 f18;
    s32 f1C;
    u8 pad20[0x3E];
    u8 f5E[0x22];
    u8 f80[8];
    Blk_006D34D8 f88;
    u8 padA8[0x56];
    u8 fFE[0x10];
    u8 pad10E[0x1CE];
    s32 f2DC;
    u8 pad2E0[0x350];
    u8 f630;
    u8 pad631[3];
    s32 f634;
} D_006D34D8;
extern u8 D_001A5E50[];
extern u16 D_L39_00249DB8[];
extern u8 D_L39_00249DC0[];
extern u8 D_L39_00249DC8[];
extern s32 D_L39_002407C8;
extern u8 D_00197C90[];
extern s32 func_L39_006D25C0(void *);
extern void func_0011D534(void *, s32, s32);
extern u32 func_00120884(void *);
extern void func_L39_005945F0(s32, s32, s32);
extern s32 func_0017E918(void *, void *, s32);
extern void func_00195500(void);
extern s32 func_L39_006D5F80(u8 *);
extern s32 func_00195620(void *);
extern s32 func_00195900(void);
extern s32 func_0019B8C8(void);
s32 func_L39_006D1928(void);
extern s32 func_00120048(u8 *, u8 *, ...);
extern s32 func_L39_006D1E30(u8 *);
extern void func_0014AD08(s32, s32, s32, s32, s32, void *);
extern void func_0019B6F8(s32);
extern void func_0019BFF8(s32);
extern void func_0019CB68(s32);

static __inline__ s32 pump_006D34D8(G_006D34D8 *g) {
    g->f1C = 1;
    func_00195500();
    g->f1C = 0;
    return func_L39_006D5F80((u8 *)g);
}

s32 func_L39_006D0D50(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3, s32 arg4, s32 arg5) {
    G_006D34D8 *g;
    Loc_006D34D8 loc;
    Msg_006D34D8 msg;
    s32 r;
    u8 *name;

    r = func_L39_006D25C0(arg0);
    if (r == 0) {
        return 0;
    }
    arg0[2] = 0;
    arg0[0x11] = 0;
    g = (G_006D34D8 *)D_L39_0024D860;
    func_0011D534(&loc, 0, sizeof(loc));
    loc.f0 = D_L39_00249DB8[0];
    func_001206F4(loc.f15, g->f50);
    loc.f28 = arg1;
    func_L39_005945F0((s32)loc.f30, (s32)arg2, func_00120884(arg2));
    loc.f50 = arg5;
    arg0[0] = 1;
    g->f1 = 1;
    g->f8 = (s32)func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017E918(&loc, D_00197C90, 0));
    while (arg0[0] != 0) {
        if (func_001962E8() != 0 || ((D_006D34D8 *)D_001A5E50)->f2DC != 0) {
            g->f10 = 0x28;
            if (g->f14 == 0) {
                g->f14 = 0x28;
            }
            r = 0;
            break;
        }
        if (pump_006D34D8(g) == 0) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    arg0[0] = 0;
    if (r != 0) {
        if (func_00195620(arg0 + 0x48) != 0) {
            r = 0;
        }
        if (r != 0) {
            ((D_006D34D8 *)D_001A5E50)->fC = arg3;
            ((D_006D34D8 *)D_001A5E50)->f18 = arg4;
            if (func_00195900() != 0) {
                r = 0;
            }
        }
    }
    if (func_0019B8C8() != 0) {
        if (r == 0) {
            ((s32 (*)(u8 *))func_L39_006D1928)(arg0);
        }
        return r;
    }
    ((D_006D34D8 *)D_001A5E50)->f630 = 1;
    if (r != 0) {
        name = ((D_006D34D8 *)D_001A5E50)->f5E;
        msg.f4 = *g->f30;
        msg.f0 = ((D_006D34D8 *)D_001A5E50)->fC;
        msg.f28 = ((D_006D34D8 *)D_001A5E50)->f18;
        msg.f2C = ((D_006D34D8 *)D_001A5E50)->f1C;
        msg.f2A = ((D_006D34D8 *)D_001A5E50)->f18;
        msg.f2E = ((D_006D34D8 *)D_001A5E50)->f1C;
        func_001206F4(msg.f30, name);
        func_001206F4(msg.f50, ((D_006D34D8 *)D_001A5E50)->f80);
        msg.f50[4] = 0;
        if (func_00120884(name) < 10) {
            func_00120048(msg.f40, D_L39_00249DC0, name, 2);
        } else {
            func_00120048(msg.f40, D_L39_00249DC8, name, 2);
        }
        msg.f8 = *(Blk16_006D34D8 *)(D_001A5E50 + 0x88);
        msg.f18 = *(Blk16_006D34D8 *)(D_001A5E50 + 0x98);
        func_0014AD08(0x50, ((D_006D34D8 *)D_001A5E50)->f4, -1, D_L39_002407C8, 0x58, &msg);
        func_0019B6F8(arg1);
        if (r != 0) {
            g->f1 = 1;
            g->f8 = (s32)func_00130760(func_0012DCB0(), 0x24000);
            while (((D_006D34D8 *)D_001A5E50)->f630 != 0) {
                if (func_001962E8() != 0 || ((D_006D34D8 *)D_001A5E50)->f2DC != 0) {
                    g->f10 = 0x28;
                    if (g->f14 == 0) {
                        g->f14 = 0x28;
                    }
                    r = 0;
                    break;
                }
                if (pump_006D34D8(g) == 0) {
                    r = 0;
                    break;
                }
            }
            g->f1 = 0;
        }
    }
    ((D_006D34D8 *)D_001A5E50)->f630 = 0;
    if (r != 0) {
        if (((D_006D34D8 *)D_001A5E50)->f634 == 4) {
            g->f10 = 0x31;
            if (g->f14 == 0) {
                g->f14 = 0x31;
            }
            ((s32 (*)(u8 *))func_L39_006D1928)(arg0);
            r = 0;
        } else if (((D_006D34D8 *)D_001A5E50)->f634 == 1) {
            g->f10 = 0x32;
            if (g->f14 == 0) {
                g->f14 = 0x32;
            }
            ((s32 (*)(u8 *))func_L39_006D1928)(arg0);
            r = 0;
        } else if (((D_006D34D8 *)D_001A5E50)->f634 == 3) {
            g->f10 = 0x33;
            if (g->f14 == 0) {
                g->f14 = 0x33;
            }
            ((s32 (*)(u8 *))func_L39_006D1928)(arg0);
            r = 0;
        } else if (((D_006D34D8 *)D_001A5E50)->f634 == 5) {
            g->f10 = 0x34;
            if (g->f14 == 0) {
                g->f14 = 0x34;
            }
            ((s32 (*)(u8 *))func_L39_006D1928)(arg0);
            r = 0;
        } else if (((D_006D34D8 *)D_001A5E50)->f634 == 2) {
            r = 0;
        }
        if (r != 0 && arg0[0x12] == 0) {
            r = func_L39_006D1E30(arg0);
        }
    }
    func_001206F4(((D_006D34D8 *)D_001A5E50)->fFE, arg2);
    if (r == 0) {
        ((s32 (*)(u8 *))func_L39_006D1928)(arg0);
    } else {
        func_0019BFF8(6);
        func_0019CB68(1);
    }
    return r;
}
/* localdecomp:end func_L39_006D0D50 */
