#include "common.h"

/* NTSC-U counterpart of func_L39_006DCDB8 (src/levels/39_multiplayer_menu/L39_006DC228.c) */
s32 func_0012DCB0(void);
long func_00130760(s32, long);
void func_001962D8(s32);
s32 func_001962E8();
void func_00195500(void);
s32 func_L39_006D5F80(u8 *);
extern u8 D_001A5E50[];
void func_001962D8(s32);
extern void *D_L39_0024D860;

/* localdecomp:start func_L39_006DA258 */
typedef struct {
    u8 b[0x40];
} B_006DCDB8;
typedef struct {
    char _p0[0x38];
    B_006DCDB8 f38;
    char _p78[0xF0 - 0x78];
    s32 fF0;
    void *fF4;
    s32 fF8;
    s32 fFC;
} L_006DCDB8;
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
} G_006DCDB8;
typedef struct {
    char _p0[0x94];
    s32 f94;
    u8 f98;
    char _p99[0x9B - 0x99];
    u8 f9B;
    char _p9C[0x9D - 0x9C];
    u8 f9D;
} S_006DCDB8;
typedef struct {
    char _p0[0x2DC];
    s32 f2DC;
} P_006DCDB8;

void func_0017F710(void *, s32, void *, s32, s32);
void func_00183C2C(void *);
void func_0011D534(void *, s32, s32);
s32 func_0017DFE0(void *, void *, s32);
void func_001962D8(s32);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
s32 func_001962E8();
void func_00195500(void);
s32 func_L39_006D5F80(u8 *);
void func_L39_006D6328(void *);
void func_L39_006DA4C8(s32 arg0);
__asm__(".extern D_L39_0024D860, 16");
extern void *D_L39_0024D860;
extern u8 D_001A5E50[];

s32 func_L39_006DA258(S_006DCDB8 *arg0) {
    L_006DCDB8 loc;
    B_006DCDB8 tmp;
    s32 res;
    G_006DCDB8 *g;
    s32 r;
    s32 i;

    g = D_L39_0024D860;
    func_0017F710(&loc, 0, (u8 *)arg0 + 0x11, arg0->f94, 1);
    loc.fF0 = 0xFF;
    loc.fF4 = func_L39_006DA4C8;
    loc.fF8 = 0;
    loc.fFC = 0;
    if (arg0->f98 != 0) {
        func_00183C2C(&tmp);
    } else {
        func_0011D534(&tmp, 0, 0x40);
    }
    loc.f38 = tmp;
    r = 1;
    i = 1;
    while (arg0->f9D == 0 && r != 0) {
        g->f1C = 1;
        func_00195500();
        g->f1C = 0;
        arg0->f9B = 1;
        func_001962D8(func_0017DFE0(&loc, &res, 0));
        g->f1 = 1;
        g->f8 = func_00130760(func_0012DCB0(), 0x24000);
        while (arg0->f9B != 0) {
            if (func_001962E8() != 0 || ((P_006DCDB8 *)D_001A5E50)->f2DC != 0) {
                g->f10 = 0x4E;
                if (g->f14 == 0) {
                    g->f14 = 0x4E;
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
        arg0->f9B = 0;
        if (i++ >= 4) {
            break;
        }
    }
    if (r != 0) {
        if (arg0->f9D == 0) {
            g->f10 = 0x4E;
            if (g->f14 == 0) {
                g->f14 = 0x4E;
            }
            r = 0;
        } else {
            g->f10 = 0;
            g->f14 = 0;
            r = 1;
            func_L39_006D6328(g);
        }
    }
    return r;
}
/* localdecomp:end func_L39_006DA258 */
