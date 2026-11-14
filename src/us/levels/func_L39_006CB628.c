#include "common.h"

/* NTSC-U counterpart of func_L39_006CDDB0 (src/levels/39_multiplayer_menu/L39_006CCE90.c) */
void *func_001206F4(void *, void *);
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
extern u16 D_L39_00249D00[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void *D_L39_0024D860;
extern u16 D_L39_00249D00[];
extern u8 D_001A5E50[];
extern void *D_L39_0024D860;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void func_00195500(void);
extern s32 func_L39_006D5F80(u8 *);

/* localdecomp:start func_L39_006CB628 */
typedef struct {
    u8 pad0[0x1C];
    u8 f1C;
    u8 pad1D[3];
    s32 f20;
} S_006CDDB0;
typedef struct {
    u8 f0;
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
} S_006CDDB0_G;
extern u16 D_L39_00249D00[];
extern u8 D_00197858[];
typedef struct { u8 pad[0x2DC]; s32 f2DC; } S_006CDDB0_D;
extern u8 D_001A5E50[];
__asm__(".extern D_L39_0024D860, 16");
extern void *D_L39_0024D860;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern s32 func_0017EE18(void *, u8 *, s32);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void func_00195500(void);
extern s32 func_L39_006D5F80(u8 *);

s32 func_L39_006CB628(S_006CDDB0 *arg0, s32 arg1) {
    S_006CDDB0_G *g = (S_006CDDB0_G *)D_L39_0024D860;
    s32 r;
    struct { u16 x[1]; u8 pad2[0x13]; u8 buf[0x13]; s32 a; u8 pad3[0x4]; } l;

    void *name = g->f50;
    l.x[0] = D_L39_00249D00[0];
    func_001206F4(l.buf, name);
    l.a = arg1;
    g->f1 = arg0->f1C = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017EE18(&l, D_00197858, 0));
    r = 1;
    while (arg0->f1C != 0) {
        if (func_001962E8() != 0 || ((S_006CDDB0_D *)D_001A5E50)->f2DC != 0) {
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
/* localdecomp:end func_L39_006CB628 */
