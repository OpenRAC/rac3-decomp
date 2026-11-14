#include "common.h"

/* NTSC-U counterpart of func_L39_006CD038 (src/levels/39_multiplayer_menu/L39_006CCE90.c) */
void *func_001206F4(void *, void *);
long func_0012DCB0(void);
long func_00130760(long, long);
void func_001962D8(s32);
s32 func_001962E8(void);
void func_00195500(void);
s32 func_L39_006D5F80(u8 *);
extern u16 D_L39_00249C98[];
extern u8 D_001A5E50[];

/* localdecomp:start func_L39_006CA8B0 */
typedef struct {
    u8 pad0[0x31];
    u8 f31;
    u8 pad32[0xFE];
    s32 f130;
} T_006CD038;
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
    u8 pad1D[0x33];
    void *f50;
} G_006CD038;
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x1B];
} B_006CD038;
typedef struct {
    u8 pad0[0x2DC];
    s32 f2DC;
} P_006CD038;
__asm__(".extern D_L39_0024D860, 16");
extern void *D_L39_0024D860;
extern u16 D_L39_00249C98[];
extern u8 D_001977E0[];
extern u8 D_001A5E50[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern s32 func_0017E568(void *, u8 *, s32);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void func_00195500(void);
extern s32 func_L39_006D5F80(u8 *);

s32 func_L39_006CA8B0(T_006CD038 *a0, s32 a1) {
    s32 r;
    G_006CD038 *g;
    B_006CD038 buf;
    P_006CD038 *p;

    buf.f0 = D_L39_00249C98[0];
    g = (G_006CD038 *)D_L39_0024D860;
    func_001206F4(buf.f15, g->f50);
    a0->f31 = 1;
    g->f1 = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017E568(&buf, D_001977E0, 0));
    p = (P_006CD038 *)D_001A5E50;
    r = 1;
    while (a0->f31) {
        if (func_001962E8() != 0 || p->f2DC != 0) {
            g->f10 = 0xB;
            if (g->f14 == 0) {
                g->f14 = 0xB;
            }
            r = 0;
            break;
        }
        g->f1C = 1;
        func_00195500();
        g->f1C = 0;
        if (!func_L39_006D5F80((u8 *)g)) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    a0->f31 = 0;
    if (r) {
        if (a0->f130 != 0 && a1 == 0) {
            g->f10 = 0xB;
            if (g->f14 == 0) {
                g->f14 = 0xB;
            }
            r = 0;
        }
        if (a1) {
            func_001962D8(0);
        }
        if (r) {
            g->f10 = 0;
            g->f14 = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006CA8B0 */
