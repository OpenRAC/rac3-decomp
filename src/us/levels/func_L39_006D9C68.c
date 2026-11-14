#include "common.h"

/* NTSC-U counterpart of func_L39_006DC7C8 (src/levels/39_multiplayer_menu/L39_006DC228.c): 2 -> 1 */
/* localdecomp:start func_L39_006D9C68 */
typedef struct {
    u16 f00;
    char _p02[0x18 - 0x02];
    s32 f18;
    char _p1C[0x20 - 0x1C];
} Loc_006DC7C8;
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
} G_006DC7C8;
typedef struct {
    char _p0[0x11];
    u8 f11[0x94 - 0x11];
    s32 f94;
    u8 f98;
    u8 f99;
    char _p9A[0x9C - 0x9A];
    u8 f9C;
    char _p9D[0xB8 - 0x9D];
    s32 fB8;
} S_006DC7C8;
typedef struct {
    char _p0[0x2DC];
    s32 f2DC;
} P_006DC7C8;

__asm__(".extern D_L39_0024D860, 16");
extern void *D_L39_0024D860;
extern u16 D_L39_0024A0B0[];
extern u8 D_L39_0024A0B8[];
extern u8 D_001A5E50[];
extern u8 D_001A5A47[];
extern u8 D_00197FB0[];
extern u8 D_001981F0[];
s32 func_001206F4(void *, s32);
s32 func_L39_006DA258_006D9C68(S_006DC7C8 *);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
s32 func_0017E370(void *, void *, s32);
s32 func_0017F838(void *, void *, s32);
void func_001962D8(s32);
s32 func_001962E8();
void func_00195500(void);
s32 func_L39_006D5F80(u8 *);
s32 func_L39_006DA120(void);
s32 func_00120048(u8 *, u8 *, ...);
s32 func_00183CCC(void);
s32 func_0019B8A0(void *, void *, s32);
void func_0011D534(void *, s32, s32);

s32 func_L39_006D9C68(u8 *a0, s32 arg1, char *a2, s32 arg3) {
    S_006DC7C8 *arg0 = (S_006DC7C8 *)a0;
    s32 arg2 = (s32)a2;
    Loc_006DC7C8 loc;
    u8 buf[0x800];
    G_006DC7C8 *g;
    P_006DC7C8 *p;
    s32 r;

    arg0->f98 = arg1;
    if (arg2 != 0) {
        func_001206F4(arg0->f11, arg2);
    }
    if (arg3 != -1) {
        arg0->f94 = arg3;
    }
    g = D_L39_0024D860;
    if (func_L39_006DA258_006D9C68(arg0) == 0) {
        return 0;
    }
    loc.f00 = D_L39_0024A0B0[0];
    loc.f18 = 1;
    arg0->f99 = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017E370(&loc, D_00197FB0, 0));
    p = (P_006DC7C8 *)D_001A5E50;
    while (arg0->f99 != 0) {
        if (func_001962E8() != 0 || p->f2DC != 0) {
            g->f10 = 0x4B;
            if (g->f14 == 0) {
                g->f14 = 0x4B;
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
    if (r != 0) {
        if (arg0->fB8 != 0) {
            g->f10 = 0x4B;
            if (g->f14 == 0) {
                g->f14 = 0x4B;
            }
            r = 0;
        }
    }
    if (r != 0) {
        r = ((s32 (*)(S_006DC7C8 *))func_L39_006DA120)(arg0);
        if (r != 0) {
            func_00120048(buf, D_L39_0024A0B8, arg0->f94);
            if (func_0019B8A0(arg0->f11, buf, func_00183CCC()) != 0) {
                g->f10 = 6;
                if (g->f14 == 0) {
                    g->f14 = 6;
                }
                r = 0;
            }
            if (r != 0) {
                ((void *(*)(void *, s32, s32))func_0011D534)(buf, 0, 0x30);
                *(s32 *)(buf + 0x28) = 2;
                switch (D_001A5A47[0]) {
                case 0:
                    *(s32 *)(buf + 0x2C) = 1;
                    break;
                case 2:
                    *(s32 *)(buf + 0x2C) = 8;
                    break;
                case 3:
                    *(s32 *)(buf + 0x2C) = 7;
                    break;
                case 4:
                    *(s32 *)(buf + 0x2C) = 6;
                    break;
                case 5:
                    *(s32 *)(buf + 0x2C) = 5;
                    break;
                }
                arg0->f9C = 1;
                g->f1 = 1;
                g->f8 = func_00130760(func_0012DCB0(), 0x24000);
                func_001962D8(func_0017F838(buf, D_001981F0, 0));
                while (arg0->f9C != 0) {
                    if (func_001962E8() != 0 || ((P_006DC7C8 *)D_001A5E50)->f2DC != 0) {
                        g->f10 = 0x51;
                        if (g->f14 == 0) {
                            g->f14 = 0x51;
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
                arg0->f9C = 0;
            }
        }
    }
    return r;
}
/* localdecomp:end func_L39_006D9C68 */
