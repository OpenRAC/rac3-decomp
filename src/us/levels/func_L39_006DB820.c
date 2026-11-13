#include "common.h"

/* NTSC-U counterpart of func_L39_006DE380 (src/levels/39_multiplayer_menu/L39_006DC228.c) */
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
extern void *D_L39_0024D860;
extern u16 D_L39_0024A120[];
extern u8 D_001A5E50[];
s32 func_001206F4(void *, s32);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
void func_001962D8(s32);
s32 func_001962E8();
void func_00195500(void);
s32 func_L39_006D5F80(u8 *);
extern void *D_L39_0024D860;
extern u16 D_L39_0024A120[];
extern u8 D_001A5E50[];
s32 func_001206F4(void *, s32);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
void func_001962D8(s32);
s32 func_001962E8();
void func_00195500(void);
s32 func_L39_006D5F80(u8 *);
extern void *D_L39_0024D860;
extern u16 D_L39_0024A120[];
extern void *D_L39_0024D860;
extern u16 D_L39_0024A120[];
extern void *D_L39_0024D860;

/* localdecomp:start func_L39_006DB820 */
typedef struct {
    u16 f00;
    char _p02[0x28 - 0x02];
    s32 f28;
    s32 f2C;
} Loc_006DE380;
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
} G_006DE380;
typedef struct {
    char _p0[0x2F5C];
    u8 f2F5C;
    char _p2F5D[0x2F60 - 0x2F5D];
    u8 f2F60[0x18];
    s32 f2F78;
} S_006DE380;
typedef struct {
    char _p0[0x2DC];
    s32 f2DC;
} P_006DE380;

__asm__(".extern D_L39_0024D860, 16");
extern void *D_L39_0024D860;
extern u16 D_L39_0024A120[];
extern u8 D_001A5E50[];
s32 func_001206F4(void *, s32);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
s32 func_0017F4D0(void *, void *, s32);
void func_001962D8(s32);
s32 func_001962E8();
void func_00195500(void);
void func_00198028(void);
s32 func_L39_006D5F80(u8 *);

void *func_L39_006DB820(S_006DE380 *arg0, s32 arg1, s32 arg2) {
    Loc_006DE380 loc;
    G_006DE380 *g;
    P_006DE380 *p;
    s32 r;
    s32 x;

    g = (G_006DE380 *)D_L39_0024D860;
    x = g->f50;
    loc.f00 = D_L39_0024A120[0];
    func_001206F4((u8 *)&loc + 0x15, x);
    loc.f28 = arg2;
    loc.f2C = arg1;
    arg0->f2F5C = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017F4D0(&loc, func_00198028, 0));
    p = (P_006DE380 *)D_001A5E50;
    while (arg0->f2F5C != 0) {
        if (func_001962E8() != 0 || p->f2DC != 0) {
            g->f10 = 0x59;
            if (g->f14 == 0) {
                g->f14 = 0x59;
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
    arg0->f2F5C = 0;
    if (r != 0) {
        if (arg0->f2F78 != 0) {
            g->f10 = 0x59;
            if (g->f14 == 0) {
                g->f14 = 0x59;
            }
            r = 0;
        }
    }
    return r != 0 ? arg0->f2F60 : 0;
}
/* localdecomp:end func_L39_006DB820 */
