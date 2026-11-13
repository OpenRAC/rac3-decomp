#include "common.h"

/* NTSC-U counterpart of func_L39_006D4188 (src/levels/39_multiplayer_menu/L39_006CCE90.c) */
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void *D_L39_0024D860;
void *func_001206F4(void *, void *);
long func_0012DCB0(void);
long func_00130760(long, long);
void func_001962D8(s32);
s32 func_001962E8(void);
extern void *D_L39_0024D860;
extern void *func_001206F4(void *, void *);
void func_001962D8(s32);
s32 func_001962E8(void);
extern void *func_001206F4(void *, void *);
extern void *func_001206F4(void *, void *);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_001962E8(void);
extern void *D_L39_0024D860;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern void *func_001206F4(void *, void *);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);

/* localdecomp:start func_L39_006D1A00 */
__asm__(".extern D_L39_0024D860, 16");
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x13];
    s32 f28;
    u8 pad2C[4];
} S_006D4188;
typedef struct {
    u8 pad0;
    u8 f1;
    u8 pad2[6];
    s32 f8;
    u8 padC[4];
    s32 f10;
    s32 f14;
    u8 pad18[0x38];
    void *f50;
} G_006D4188;
extern u16 D_L39_00249DB8[];
extern u8 D_00197D30[];
extern void *func_001206F4(void *, void *);
s32 func_0019B708(void);
extern s32 func_0017EBA8(void *, u8 *, s32);

s32 func_L39_006D1A00(u8 *arg0) {
    G_006D4188 *g;
    s32 r = 1;
    S_006D4188 x;

    x.f0 = D_L39_00249DB8[0];
    g = (G_006D4188 *)D_L39_0024D860;
    func_001206F4(x.f15, g->f50);
    x.f28 = func_0019B708();
    arg0[3] = 1;
    *(s32 *)(arg0 + 0xC) = (s32) func_00130760(func_0012DCB0(), 0x24000);
    g->f1 = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017EBA8(&x, D_00197D30, 0));
    if (func_001962E8() != 0) {
        g->f10 = 0x2E;
        if (g->f14 == 0) {
            g->f14 = 0x2E;
        }
        r = 0;
    }
    g->f1 = 0;
    return r;
}
/* localdecomp:end func_L39_006D1A00 */
