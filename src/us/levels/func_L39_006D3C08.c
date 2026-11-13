#include "common.h"

/* NTSC-U counterpart of func_L39_006D6398 (src/levels/39_multiplayer_menu/L39_006D5208.c) */
extern void *D_L39_0024D860;
extern u8 D_001A5E50[];
s32 func_001206F4(void *, s32);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
void func_001962D8(s32);
s32 func_001962E8(void);
void func_00195500(void);
s32 func_L39_006D5F80(u8 *);
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern u8 D_001A5E50[];
s32 func_001206F4(void *, s32);
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
extern u16 D_L39_00249E90[];
s32 func_0012DCB0(void);
long func_00130760(s32, long);
void func_001962D8(s32);
s32 func_001962E8(void);
extern void *D_L39_0024D860;
extern u16 D_L39_00249E90[];
extern u8 D_001A5E50[];
s32 func_001206F4(void *, s32);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
void func_001962D8(s32);
s32 func_001962E8(void);
void func_00195500(void);
s32 func_L39_006D5F80(u8 *);

/* localdecomp:start func_L39_006D3C08 */
typedef struct {
    u8 pad0[0x1C];
    u8 f1C;
    u8 pad1D[3];
    s32 f20;
} S_006D6398;
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
    u8 pad1D[0x50 - 0x1D];
    s32 f50;
} G_006D6398;
typedef struct {
    u16 f0;
    u8 pad2[0x26];
    s32 f28;
} Loc_006D6398;
__asm__(".extern D_L39_0024D860, 16");
extern void *D_L39_0024D860;
extern u16 D_L39_00249E90[];
extern u8 D_00197DD0[];
extern u8 D_001A5E50[];
s32 func_001206F4(void *, s32);
s32 func_0012DCB0(void);
long func_00130760(s32, long);
s32 func_0017EFA0(void *, void *, s32);
void func_001962D8(s32);
s32 func_001962E8(void);
void func_00195500(void);
s32 func_L39_006D5F80(u8 *);

s32 func_L39_006D3C08(S_006D6398 *arg0, s32 arg1) {
    Loc_006D6398 loc;
    G_006D6398 *g;
    u8 *p;
    s32 r;
    s32 n;

    g = D_L39_0024D860;
    n = g->f50;
    loc.f0 = D_L39_00249E90[0];
    func_001206F4((u8 *)&loc + 0x15, n);
    loc.f28 = arg1;
    arg0->f1C = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017EFA0(&loc, D_00197DD0, 0));
    p = D_001A5E50;
    while (arg0->f1C != 0) {
        if (func_001962E8() != 0 || *(s32 *)(p + 0x2DC) != 0) {
            g->f10 = 0x13;
            if (g->f14 == 0) {
                g->f14 = 0x13;
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
    arg0->f1C = 0;
    if (r != 0) {
        if (arg0->f20 == -0x3DD) {
            r = 0;
        } else if (arg0->f20 == -0x3DC) {
            g->f10 = 0x13;
            if (g->f14 == 0) {
                g->f14 = 0x13;
            }
        }
    }
    return r;
}
/* localdecomp:end func_L39_006D3C08 */
