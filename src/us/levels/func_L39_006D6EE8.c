#include "common.h"

/* NTSC-U counterpart of func_L39_006D9A40 (src/levels/39_multiplayer_menu/L39_006D8E90.c) */
typedef struct Obj_006DA090 {
    u8 pad00[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0x38];
    s32 f50;
    s32 f54;
} Obj_006DA090;
extern Obj_006DA090 *D_L39_0024D860;
extern Obj_006DA090 *D_L39_0024D860;
s32 func_001206F4(void *, s32);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
void *func_0017ECA8(void *, void *, s32);
void func_001962D8(void *);
s32 func_001962E8(void);
void func_00195500(void);
extern s32 func_L39_006D5F80(void *);
extern u16 D_L39_00249FF8[];
extern u8 D_00197E70[];

/* localdecomp:start func_L39_006D6EE8 */
typedef struct {
    s16 f00;
    u8 pad02[0x26];
    s32 f28;
    s32 f2C;
    u8 pad30[0x20];
} Loc_006D9A40;
typedef struct {
    u8 pad00[0x14C];
    u8 f14C;
    u8 pad14D[3];
    u8 f150[0x18];
    s32 f168;
} S_006D9A40;
typedef struct {
    u8 pad00;
    u8 f1;
    u8 pad02[6];
    s32 f8;
    u8 pad0C[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
    u8 pad1D[0x33];
    s32 f50;
} G_006D9A40;
typedef struct {
    u8 pad00[0x2DC];
    s32 f2DC;
} P_006D9A40;

s32 func_001206F4(void *, s32);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
void *func_0017ECA8(void *, void *, s32);
void func_001962D8(void *);
s32 func_001962E8(void);
void func_00195500(void);
void func_L39_005945F0(void *, void *, s32);
extern s32 func_L39_006D5F80(void *);
extern u8 D_001A5E50[];
__asm__(".extern D_L39_0024D860, 16");
extern u16 D_L39_00249FF8[];
extern u8 D_00197E70[];

void *func_L39_006D6EE8(S_006D9A40 *arg0, void *arg1) {
    Loc_006D9A40 loc;
    G_006D9A40 *g;
    P_006D9A40 *p;
    s32 r;
    s32 x;
    void *ret;

    g = (G_006D9A40 *)D_L39_0024D860;
    x = g->f50;
    loc.f00 = D_L39_00249FF8[0];
    func_001206F4((u8 *)&loc + 0x15, x);
    loc.f28 = 1;
    func_L39_005945F0((u8 *)&loc + 0x30, arg1, 0x20);
    arg0->f14C = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017ECA8(&loc, D_00197E70, 0));
    p = (P_006D9A40 *)D_001A5E50;
    while (arg0->f14C != 0) {
        if (func_001962E8() != 0 || p->f2DC != 0) {
            g->f10 = 0x3E;
            if (g->f14 == 0) {
                g->f14 = 0x3E;
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
    arg0->f14C = 0;
    ret = 0;
    if (r != 0) {
        if (arg0->f168 == -0x3DD) {
            g->f10 = 0x3D;
            if (g->f14 == 0) {
                g->f14 = 0x3D;
            }
            r = 0;
        } else if (arg0->f168 != 0) {
            g->f10 = 0x3E;
            if (g->f14 == 0) {
                g->f14 = 0x3E;
            }
            r = 0;
        }
        ret = r ? arg0->f150 : 0;
    }
    return ret;
}
/* localdecomp:end func_L39_006D6EE8 */
