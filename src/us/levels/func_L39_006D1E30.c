#include "common.h"

/* NTSC-U counterpart of func_L39_006D45B8 (src/levels/39_multiplayer_menu/L39_006CCE90.c) */
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
extern u16 D_L39_00249DB8[];
extern void *func_001206F4(void *, void *);
s32 func_0019B708(void);
extern void *D_L39_0024D860;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *D_L39_0024D860;

/* localdecomp:start func_L39_006D1E30 */
typedef struct S_6D45B8 {
    u8 pad0[0x12];
    u8 f12;
    u8 pad13[5];
    s32 f18;
} S_6D45B8;
typedef struct S_6D45B8_G {
    u8 pad0[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0x38];
    s32 f50;
} S_6D45B8_G;
extern u16 D_L39_00249DB8[];
extern u8 D_00197D58[];
__asm__(".extern D_L39_0024D860, 16");
extern void *D_L39_0024D860;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_0019B708(void);
extern s32 func_0017EAA8(u16 *, u8 *, s32);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);

s32 func_L39_006D1E30(u8 *arg0) {
    S_6D45B8 *p = (S_6D45B8 *)arg0;
    S_6D45B8_G *g = (S_6D45B8_G *)D_L39_0024D860;
    s32 r = 1;
    struct { u16 x[1]; u8 pad2[0x13]; u8 buf[0x13]; s32 v; } l;

    *(s32 *)(arg0 + 0xD20) = 0;
    l.x[0] = D_L39_00249DB8[0];
    func_001206F4(l.buf, (void *)g->f50);
    l.v = func_0019B708();
    p->f12 = 1;
    p->f18 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017EAA8(l.x, D_00197D58, 0));
    if (func_001962E8() != 0) {
        g->f10 = 0x2F;
        if (g->f14 == 0) {
            g->f14 = 0x2F;
        }
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L39_006D1E30 */
