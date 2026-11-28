#include "common.h"
/* localdecomp:start func_U_L39_006D1BF8 */
typedef struct {
    u8 pad0[2];
    u8 f2;
    u8 pad3[0xD];
    u8 f10;
    u8 pad11[0x25F];
    u8 f270[0x18];
    s32 f288;
} S_006D4380;
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
} S_006D4380_G;
extern u16 D_L39_00249DB8[];
extern u8 D_00197C40[];
typedef struct { u8 pad[0x2DC]; s32 f2DC; } S_006D4380_D;
extern u8 D_001A5E50[];
__asm__(".extern D_L39_0024D860, 16");
extern void *D_L39_0024D860;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern s32 func_0017EBA8(void *, u8 *, s32);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void func_00195500(void);

u8 *func_U_L39_006D1BF8(S_006D4380 *arg0, s32 arg1) {
    S_006D4380_G *g = (S_006D4380_G *)D_L39_0024D860;
    s32 r;
    struct { u16 x[1]; u8 pad2[0x13]; u8 buf[0x13]; s32 a; u8 pad3[0x4]; } l;

    arg0->f2 = 0;
    l.x[0] = D_L39_00249DB8[0];
    func_001206F4(l.buf, g->f50);
    l.a = arg1;
    g->f1 = arg0->f10 = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017EBA8(&l, D_00197C40, 0));
    r = 1;
    while (arg0->f10 != 0) {
        if (func_001962E8() != 0 || ((S_006D4380_D *)D_001A5E50)->f2DC != 0) {
            g->f10 = 0x2E;
            if (g->f14 == 0) {
                g->f14 = 0x2E;
            }
            r = 0;
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
    arg0->f10 = 0;
    if (r != 0) {
        s32 e = arg0->f288;
        s32 c;

        if (e == -0x3DF || e == -0x3D1) {
            c = 0x35;
            goto set;
        }
        if (e != 0) {
            c = 0x2E;
        set:
            g->f10 = c;
            if (g->f14 == 0) {
                g->f14 = c;
            }
            r = 0;
        }
    }
    return r ? arg0->f270 : 0;
}
/* localdecomp:end func_U_L39_006D1BF8 */
