#include "common.h"

/* localdecomp:start func_L39_006CA210 */
typedef struct {
    u16 f00;
    u8 pad02[0x26];
    s32 f28;
    u8 f2C[0x20];
    u8 f4C[0x20];
} Loc_006CA210;
typedef struct {
    u8 pad00;
    u8 f1;
    u8 pad02[6];
    s32 f8;
    u8 padC[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
    u8 pad1D[0x33];
    s32 f50;
    void *f54;
} G_006CA210;
typedef struct {
    u8 pad00[0x2D];
    u8 f2D;
    u8 pad2E[0x1E];
    s32 f4C;
} S_006CA210;
typedef struct {
    u8 pad00[0x2DC];
    s32 f2DC;
} P_006CA210;

s32 func_L39_006DAAA8(void *, void *, s32);
s32 func_001206F4(void *, s32);
void func_L39_005945F0(void *, void *, s32);
extern s32 func_0012DCB0(void);
extern long func_00130760(long, long);
s32 func_0017E5F0(void *, void *, s32);
void func_001962D8(s32);
s32 func_001962E8(void);
void func_00195500(void);
extern s32 func_L39_006D5F80(void *);
extern u8 D_001A5E50[];
__asm__(".extern D_L39_0024D860, 16");
extern G_006CA210 *D_L39_0024D860;
extern u16 D_L39_00249C98[];
extern u8 D_00197740[];

s32 func_L39_006CA210(S_006CA210 *arg0, void *arg1, void *arg2) {
    Loc_006CA210 loc;
    G_006CA210 *g;
    P_006CA210 *p;
    void *obj;
    s32 r;
    s32 code;

    g = D_L39_0024D860;
    obj = g->f54;
    if (func_L39_006DAAA8(obj, arg1, 0) == 0 || func_L39_006DAAA8(obj, arg2, 0) == 0) {
        g->f10 = 3;
        if (g->f14 == 0) {
            g->f14 = 3;
        }
        return 0;
    }
    loc.f00 = D_L39_00249C98[0];
    func_001206F4((u8 *)&loc + 0x15, g->f50);
    loc.f28 = 1;
    func_L39_005945F0(loc.f2C, arg1, 0x20);
    func_L39_005945F0(loc.f4C, arg2, 0x20);
    arg0->f2D = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017E5F0(&loc, D_00197740, 0));
    p = (P_006CA210 *)D_001A5E50;
    while (arg0->f2D != 0) {
        if (func_001962E8() != 0 || p->f2DC != 0) {
            g->f10 = 0xC;
            if (g->f14 == 0) {
                g->f14 = 0xC;
            }
            r = 0;
            break;
        }
        g->f1C = 1;
        func_00195500();
        g->f1C = 0;
        if (func_L39_006D5F80(g) == 0) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    arg0->f2D = 0;
    if (r != 0) {
        code = arg0->f4C;
        if (code != 0) {
            if (code == -0x3E7) {
                g->f10 = 0xE;
                if (g->f14 == 0) {
                    g->f14 = 0xE;
                }
            } else {
                g->f10 = 0xC;
                if (g->f14 == 0) {
                    g->f14 = 0xC;
                }
            }
            r = 0;
        }
        if (r != 0) {
            g->f10 = 0;
            g->f14 = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006CA210 */
