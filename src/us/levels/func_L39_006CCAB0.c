#include "common.h"

/* NTSC-U counterpart of func_L39_006CF238 (src/levels/39_multiplayer_menu/L39_006CCE90.c) */
void *func_001206F4(void *, void *);
extern void func_L39_005945F0(s32, s32, s32);
long func_0012DCB0(void);
long func_00130760(long, long);
void func_001962D8(s32);
s32 func_001962E8(void);
void func_00195500(void);
s32 func_L39_006D5F80(u8 *);
extern u8 D_001A5E50[];
extern void *D_L39_0024D860;
extern u8 D_001A5E50[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void func_00195500(void);
extern s32 func_L39_006D5F80(u8 *);
extern void *D_L39_0024D860;
extern u8 D_001A5E50[];
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void *D_L39_0024D860;
extern u8 D_001A5E50[];
extern void *D_L39_0024D860;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void func_00195500(void);
extern s32 func_L39_006D5F80(u8 *);
extern u8 D_001A5E50[];
extern void *D_L39_0024D860;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void func_00195500(void);
extern s32 func_L39_006D5F80(u8 *);
typedef struct {
    s32 f0;
    char _p4[0x30 - 0x4];
    u8 f30[4];
    u8 f34;
    u8 f35;
    char _p36[0x38 - 0x36];
    s32 f38;
    char _p3C[0x5C - 0x3C];
    u8 f5C;
    char _p5D[0x60 - 0x5D];
    u32 f60;
} A_006CEA18;
extern void *D_L39_0024D860;
void *func_001206F4(void *, void *);
long func_0012DCB0(void);
long func_00130760(long, long);
void func_001962D8(s32);
s32 func_001962E8(void);
void func_00195500(void);
s32 func_L39_006D5F80(u8 *);
extern u16 D_L39_00249D58[];
extern u8 D_001A5E50[];
extern void *D_L39_0024D860;
extern u8 D_001A5E50[];
extern void *func_001206F4(void *, void *);
extern u16 D_L39_00249D58[];
extern void *func_001206F4(void *, void *);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void func_00195500(void);
extern void func_L39_005945F0(s32, s32, s32);
extern u16 D_L39_00249D58[];
extern u8 D_001A5E50[];
extern void *D_L39_0024D860;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void func_00195500(void);
extern s32 func_L39_006D5F80(u8 *);
extern s32 func_L39_006CC290(A_006CEA18 *, s32);

/* localdecomp:start func_L39_006CCAB0 */
typedef struct {
    u8 pad0[0x74];
    u8 f74;
    u8 pad75[3];
    s32 f78;
} T_006CF238;
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
} G_006CF238;
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x13];
    s32 f28;
    u8 f2C[0x24];
} B_006CF238;
typedef struct {
    u8 pad0[0x2DC];
    s32 f2DC;
} P_006CF238;
__asm__(".extern D_L39_0024D860, 16");
extern void *D_L39_0024D860;
extern u16 D_L39_00249D58[];
extern u8 D_00197920[];
extern u8 D_001A5E50[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern void func_L39_005945F0(s32, s32, s32);
extern s32 func_0017CF78(void *, u8 *, s32);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void func_00195500(void);
extern s32 func_L39_006D5F80(u8 *);
extern s32 func_L39_006CC290(A_006CEA18 *, s32);

s32 func_L39_006CCAB0(T_006CF238 *a0, s32 a1, void *a2) {
    s32 r;
    G_006CF238 *g;
    B_006CF238 buf;
    P_006CF238 *p;

    void *n;

    g = (G_006CF238 *)D_L39_0024D860;
    n = g->f50;
    buf.f0 = D_L39_00249D58[0];
    func_001206F4(buf.f15, n);
    buf.f28 = a1;
    func_L39_005945F0((s32)buf.f2C, (s32)a2, 0x20);
    a0->f74 = 1;
    g->f1 = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017CF78(&buf, D_00197920, 0));
    p = (P_006CF238 *)D_001A5E50;
    r = 1;
    while (a0->f74) {
        if (func_001962E8() != 0 || p->f2DC != 0) {
            g->f10 = 0x16;
            if (g->f14 == 0) {
                g->f14 = 0x16;
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
    a0->f74 = 0;
    if (r) {
        if (a0->f78 == -0x3DE) {
            g->f10 = 0x23;
            if (g->f14 == 0) {
                g->f14 = 0x23;
            }
            r = 0;
        } else if (a0->f78 != 0) {
            g->f10 = 0x17;
            if (g->f14 == 0) {
                g->f14 = 0x17;
            }
            r = 0;
        }
        if (r) {
            r = func_L39_006CC290((A_006CEA18 *)a0, 0);
        }
    }
    return r;
}
/* localdecomp:end func_L39_006CCAB0 */
