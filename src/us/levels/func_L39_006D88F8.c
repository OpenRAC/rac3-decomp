#include "common.h"

/* localdecomp:start func_L39_006D88F8 */
typedef struct {
    u16 f00;
    char _p02[0x18 - 0x02];
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2C;
} Loc_6D88F8;
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
} G_6D88F8;
typedef struct {
    char _p0[0xE4];
    u8 fE4;
    char _pE5[0xE8 - 0xE5];
    s32 fE8;
} S_6D88F8;
typedef struct {
    char _p0[0x2DC];
    s32 f2DC;
} P_6D88F8;

extern G_6D88F8 *D_001E1FD0_sda;
__asm__(".extern D_001E1FD0_sda, 4");
extern u16 D_L39_0024A050[];
extern u8 D_001A5E50[];
extern s32 func_0012DCB0(void);
extern long func_00130760(s32, long);
extern s32 func_0017FCB8(void *, void *, s32);
extern void func_00197F88(void);
extern void func_001962D8(s32);
extern s32 func_001962E8();
extern void func_00195500(void);
extern s32 func_L39_006D5F80(u8 *);

s32 func_L39_006D88F8(S_6D88F8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    Loc_6D88F8 loc;
    G_6D88F8 *g;
    P_6D88F8 *p;
    s32 r;

    loc.f00 = D_L39_0024A050[0];
    loc.f18 = arg2;
    loc.f1C = arg3;
    loc.f20 = arg4;
    loc.f24 = arg5;
    g = D_001E1FD0_sda;
    if (arg1 != 0) {
        loc.f28 = 1;
    } else {
        loc.f28 = 0;
    }
    loc.f2C = 0x20;
    arg0->fE4 = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017FCB8(&loc, func_00197F88, 0));
    p = (P_6D88F8 *)D_001A5E50;
    while (arg0->fE4 != 0) {
        if (func_001962E8() != 0 || p->f2DC != 0) {
            g->f10 = 0x46;
            if (g->f14 == 0) {
                g->f14 = 0x46;
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
    arg0->fE4 = 0;
    if (r != 0) {
        if (arg0->fE8 != 0) {
            g->f10 = 0x46;
            if (g->f14 == 0) {
                g->f14 = 0x46;
            }
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006D88F8 */
