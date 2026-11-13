#include "common.h"

/* NTSC-U counterpart of func_L39_006D6CF8 (src/levels/39_multiplayer_menu/L39_006D5208.c) */
extern void *D_L39_0024D860;
extern u8 D_001A5E50[];
s32 func_0012DCB0(void);
long func_00130760(s32, long);
void func_001962D8(s32);
s32 func_001962E8(void);
void func_00195500(void);
s32 func_L39_006D5F80(u8 *);
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern u8 D_001A5E50[];
s32 func_0012DCB0(void);
long func_00130760(s32, long);
void func_001962D8(s32);
s32 func_001962E8(void);
void func_00195500(void);
s32 func_L39_006D5F80(u8 *);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
void func_001962D8(s32);
s32 func_001962E8(void);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
void func_001962D8(s32);
s32 func_001962E8(void);
extern void *D_L39_0024D860;
extern u8 D_001A5E50[];
s32 func_0012DCB0(void);
long func_00130760(s32, long);
void func_001962D8(s32);
s32 func_001962E8(void);
void func_00195500(void);
s32 func_L39_006D5F80(u8 *);
extern void *D_L39_0024D860;
extern u8 D_001A5E50[];
s32 func_0012DCB0(void);
long func_00130760(s32, long);
void func_001962D8(s32);
s32 func_001962E8(void);
void func_00195500(void);
s32 func_L39_006D5F80(u8 *);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
extern void *D_L39_0024D860;

/* localdecomp:start func_L39_006D4568 */
typedef struct {
    u16 f0;
    u8 pad2[0x18 - 2];
    s32 f18;
    s32 f1C;
    s32 f20;
    u8 pad24[0x30 - 0x24];
} Loc_006D6CF8;
typedef struct {
    u8 pad0[1];
    u8 f1;
    u8 pad2[6];
    s32 f8;
    u8 padC[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
} G_006D6CF8;
typedef struct {
    u8 pad0[0x14];
    u8 f14;
    u8 pad15[0x38 - 0x15];
    u8 f38[0x18];
    s32 f50;
} S_006D6CF8;
typedef struct {
    u8 pad0[0x2DC];
    s32 f2DC;
} P_006D6CF8;
__asm__(".extern D_L39_0024D860, 16");
extern void *D_L39_0024D860;
extern u16 D_L39_00249EE8_006D4568[];
extern u8 D_00198218[];
extern u8 D_001A5E50[];
s32 func_0012DCB0(void);
long func_00130760(s32, long);
s32 func_0017FB30(void *, void *, s32);
void func_001962D8(s32);
s32 func_001962E8(void);
void func_00195500(void);
s32 func_L39_006D5F80(u8 *);

void *func_L39_006D4568(S_006D6CF8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Loc_006D6CF8 loc;
    G_006D6CF8 *g;
    P_006D6CF8 *p;
    s32 r;

    loc.f0 = D_L39_00249EE8_006D4568[0];
    loc.f18 = arg1;
    loc.f1C = arg2;
    loc.f20 = arg3;
    g = (G_006D6CF8 *)D_L39_0024D860;
    arg0->f14 = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017FB30(&loc, D_00198218, 0));
    p = (P_006D6CF8 *)D_001A5E50;
    while (arg0->f14 != 0) {
        if (func_001962E8() != 0 || p->f2DC != 0) {
            g->f10 = 0x5D;
            if (g->f14 == 0) {
                g->f14 = 0x5D;
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
    arg0->f14 = 0;
    g->f1 = 0;
    if (r != 0) {
        if (arg0->f50 != 0) {
            r = 0;
        }
    }
    return r != 0 ? arg0->f38 : 0;
}
/* localdecomp:end func_L39_006D4568 */
