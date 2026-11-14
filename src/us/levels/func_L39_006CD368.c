#include "common.h"

/* NTSC-U counterpart of func_L39_006CFAF0 (src/levels/39_multiplayer_menu/L39_006CCE90.c) */
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
extern void *D_L39_0024D860;
extern u16 D_L39_00249D58[];
extern u8 D_001A5E50[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern void func_L39_005945F0(s32, s32, s32);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void func_00195500(void);
extern s32 func_L39_006D5F80(u8 *);
extern u16 D_L39_00249D58[];
extern void *func_001206F4(void *, void *);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void func_00195500(void);
extern void func_L39_005945F0(s32, s32, s32);
extern void func_L39_005945F0(s32, s32, s32);
extern void *D_L39_0024D860;
extern u16 D_L39_00249D58[];
extern u8 D_001A5E50[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void func_00195500(void);
extern s32 func_L39_006D5F80(u8 *);
extern u16 D_L39_00249D58[];
extern void *D_L39_0024D860;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern void func_L39_005945F0(s32, s32, s32);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void func_00195500(void);
extern s32 func_L39_006D5F80(u8 *);
extern s32 func_L39_006CFD78(void *, s32, s32);

/* localdecomp:start func_L39_006CD368 */
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x13];
    s32 f28;
    s32 f2C;
    u8 f30[0xCC];
} L_006CFAF0;
typedef struct {
    u8 pad0[0x9C];
    u8 f9C;
    u8 pad9D[3];
    s32 fA0;
    u8 padA4[0x430];
    u8 f4D4;
    u8 pad4D5[3];
    s32 f4D8;
    u8 f4DC;
    u8 pad4DD[7];
    u8 f4E4;
} S_006CFAF0;
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
} G_006CFAF0;
typedef struct { u8 pad[0x2DC]; s32 f2DC; } D_006CFAF0;
extern u16 D_L39_00249D58[];
extern u8 D_00197BC8[];
extern u8 D_001A5E50[];
__asm__(".extern D_L39_0024D860, 16");
extern void *D_L39_0024D860;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern void func_L39_005945F0(s32, s32, s32);
extern s32 func_0017D578(void *, u8 *, s32);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void func_00195500(void);
extern s32 func_L39_006D5F80(u8 *);
/* defined in L39_006D08E8.c (S_006D2500 *); declared here as func_L39_006CFCD0 and L39_006D05A0.c do, with the return value */
extern s32 func_L39_006CFD78(void *, s32, s32);

s32 func_L39_006CD368(S_006CFAF0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    G_006CFAF0 *g = (G_006CFAF0 *)D_L39_0024D860;
    s32 r;
    L_006CFAF0 l;

    void *n = g->f50;

    l.f0 = D_L39_00249D58[0];
    func_001206F4(l.f15, n);
    l.f28 = arg1;
    l.f2C = arg2;
    func_L39_005945F0((s32)l.f30, arg3, 200);
    g->f1 = arg0->f9C = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017D578(&l, D_00197BC8, 0));
    r = 1;
    while (arg0->f9C != 0) {
        if (func_001962E8() != 0 || ((D_006CFAF0 *)D_001A5E50)->f2DC != 0) {
            g->f10 = 0x21;
            if (g->f14 == 0) {
                g->f14 = 0x21;
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
    arg0->f9C = 0;
    if (r != 0) {
        if (arg0->fA0 == -0x3DE) {
            r = 0;
        } else if (arg0->fA0 != 0) {
            g->f10 = 0x19;
            if (g->f14 == 0) {
                g->f14 = 0x19;
            }
            r = 0;
        }
    }
    if (r != 0 && arg0->f4DC != 0 && arg0->f4E4 == 0) {
        r = func_L39_006CFD78(arg0, arg0->f4D4, arg0->f4D8);
    }
    return r;
}
/* localdecomp:end func_L39_006CD368 */
