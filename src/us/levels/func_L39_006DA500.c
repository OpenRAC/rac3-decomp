#include "common.h"

/* NTSC-U counterpart of func_L39_006DD060 (src/levels/39_multiplayer_menu/L39_006DC228.c) */
typedef struct {
    char _p0[0x2DC];
    s32 f2DC;
} P_006DCAD0;
s32 func_001206F4(void *, s32);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
void func_001962D8(s32);
s32 func_001962E8();
void func_00195500(void);
s32 func_L39_006D5F80(u8 *);
extern u8 D_001A5E50[];
void func_001962D8(s32);
extern void *D_L39_0024D860;
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
extern void *D_L39_0024D860;
extern u8 D_001A5E50[];
extern void *D_L39_0024D860;

/* localdecomp:start func_L39_006DA500 */
typedef struct { s32 words[39]; } Data_006DD060;
typedef struct {
    Data_006DD060 data;
    char _p9C[0xF0 - 0x9C];
    s32 fF0;
    void (*fF4)(s32);
    void (*fF8)(void);
    void (*fFC)(void);
} Loc_006DD060;
typedef struct {
    char _p0[0x14];
    s32 f14;
    char _p18[0x20 - 0x18];
} LocB_006DD060;
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
} G_006DD060;
typedef struct {
    char _p0[0x9B];
    u8 f9B;
    char _p9C[0x9D - 0x9C];
    u8 f9D;
} A_006DD060;
__asm__(".extern D_L39_0024D860, 16");
extern void *D_L39_0024D860;
void func_0011D534(void *, s32, s32);
s32 func_0017DFE0(void *, void *, s32);
s32 func_0017E310(void *);
void func_L39_006D6328(void *);
void func_L39_006DA4C8(s32);
void func_L39_006DA860(void);
void func_L39_006DA868(void);

s32 func_L39_006DA500(A_006DD060 *arg0, Data_006DD060 *arg1) {
    G_006DD060 *g = (G_006DD060 *)D_L39_0024D860;
    Loc_006DD060 loc;
    char locA[0x10];
    LocB_006DD060 locB;
    P_006DCAD0 *p;
    s32 r;
    s32 tries;

    g->f1C = 1;
    func_00195500();
    g->f1C = 0;
    func_0011D534(&loc, 0, 0x100);
    loc.data = *arg1;
    loc.fF0 = 0xFF;
    loc.fF4 = func_L39_006DA4C8;
    loc.fF8 = func_L39_006DA860;
    loc.fFC = func_L39_006DA868;
    r = 1;
    tries = 1;
    while (arg0->f9D == 0) {
        arg0->f9B = 1;
        p = (P_006DCAD0 *)D_001A5E50;
        g->f1 = 1;
        g->f8 = func_00130760(func_0012DCB0(), 0x24000);
        func_001962D8(func_0017DFE0(&loc, locA, 0));
        while (arg0->f9B != 0) {
            if (func_001962E8() != 0 || p->f2DC != 0) {
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
        if (tries++ >= 4) {
            break;
        }
    }
    if (r != 0) {
        if (arg0->f9D == 0) {
            g->f10 = 0x4F;
            if (g->f14 == 0) {
                g->f14 = 0x4F;
            }
            r = 0;
        } else {
            g->f10 = 0;
            g->f14 = 0;
            func_L39_006D6328(g);
        }
        if (r != 0) {
            func_001206F4(&locB, (s32)arg0);
            locB.f14 = 1;
            func_001962D8(func_0017E310(&locB));
            if (func_001962E8() != 0) {
                g->f10 = 4;
                if (g->f14 == 0) {
                    g->f14 = 4;
                }
                r = 0;
            }
        }
    }
    return r;
}
/* localdecomp:end func_L39_006DA500 */
