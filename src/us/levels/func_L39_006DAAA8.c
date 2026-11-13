#include "common.h"

/* NTSC-U counterpart of func_L39_006DD608 (src/levels/39_multiplayer_menu/L39_006DC228.c) */
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
void func_001962D8(s32);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
s32 func_001962E8();
void func_00195500(void);
s32 func_L39_006D5F80(u8 *);
extern void *D_L39_0024D860;
extern u8 D_001A5E50[];
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
s32 func_001962E8();
void func_001962D8(s32);

/* localdecomp:start func_L39_006DAAA8 */
typedef struct {
    u16 f00;
    char _p02[0x28 - 0x02];
    s32 f28;
    u8 f2C[0x70 - 0x2C];
} Loc_006DD608;
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
} G_006DD608;
typedef struct {
    u8 f0;
    char _p1[0x5C - 0x1];
    s32 f5C;
} S_006DD608;
typedef struct {
    char _p0[0x2DC];
    s32 f2DC;
} P_006DD608;

__asm__(".extern D_L39_0024D860, 16");
extern void *D_L39_0024D860;
extern u16 D_L39_0024A120[];
extern u8 D_001A5E50[];
s32 func_001206F4(void *, s32);
s32 func_00120884(void *);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
s32 func_0017E810(void *, void *, s32);
void func_001962D8(s32);
s32 func_001962E8();
void func_00195500(void);
void func_00198050(void);
void func_L39_005945F0(void *, void *, s32);
s32 func_L39_006D5F80(u8 *);

s32 func_L39_006DAAA8(s32 arg0, void *arg1, s32 arg2) {
    Loc_006DD608 loc;
    S_006DD608 *s = (S_006DD608 *)arg0;
    G_006DD608 *g;
    u8 *dst;

    loc.f00 = D_L39_0024A120[0];
    g = (G_006DD608 *)D_L39_0024D860;
    func_001206F4((u8 *)&loc + 0x15, g->f50);
    dst = loc.f2C;
    loc.f28 = arg2;
    func_L39_005945F0(dst, arg1, func_00120884(arg1));
    s->f0 = 1;
    g->f1 = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017E810(&loc, func_00198050, 0));
    while (s->f0 != 0) {
        if (func_001962E8() != 0 || ((P_006DD608 *)D_001A5E50)->f2DC != 0) {
            g->f10 = 0x52;
            if (g->f14 == 0) {
                g->f14 = 0x52;
            }
            return 0;
        }
        g->f1C = 1;
        func_00195500();
        g->f1C = 0;
        if (func_L39_006D5F80((u8 *)g) == 0) {
            return 0;
        }
    }
    g->f1 = 0;
    if (s->f5C == -0x3C6) {
        g->f10 = 3;
        if (g->f14 == 0) {
            g->f14 = 3;
        }
        return 0;
    }
    if (s->f5C == -0x3C7) {
        g->f10 = 0x52;
        if (g->f14 == 0) {
            g->f14 = 0x52;
        }
        return 0;
    }
    return 1;
}
/* localdecomp:end func_L39_006DAAA8 */
