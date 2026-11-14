#include "common.h"

/* NTSC-U counterpart of func_L39_006D48C8 (src/levels/39_multiplayer_menu/L39_006D08E8.c) */
extern void *D_L39_0024D860;
extern u8 D_001A5E50[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
void *func_001206F4(void *, void *);
long func_0012DCB0(void);
long func_00130760(long, long);
void func_001962D8(s32);
s32 func_001962E8(void);
void func_00195500(void);
s32 func_L39_006D5F80(u8 *);
extern void *func_001206F4(void *, void *);
void func_001962D8(s32);
s32 func_001962E8(void);
extern void *func_001206F4(void *, void *);
extern void *D_L39_0024D860;
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
extern void func_00195500(void);
extern u8 D_001A5E50[];
extern u8 D_001A5E50[];
extern void func_00195500(void);
extern s32 func_L39_006D5F80(u8 *);
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern void *func_001206F4(void *, void *);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern u16 D_L39_00249DB8[];
extern void *func_001206F4(void *, void *);
extern void *D_L39_0024D860;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern u16 D_L39_00249DB8[];
extern u8 D_001A5E50[];
extern void *D_L39_0024D860;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void func_00195500(void);
extern void *D_L39_0024D860;
extern u16 D_L39_00249DB8[];
extern void *D_L39_0024D860;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_0017EAA8(u16 *, u8 *, s32);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void *D_L39_0024D860;

/* localdecomp:start func_L39_006D2140 */
__asm__(".extern D_L39_0024D860, 16");
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x13];
    s32 f28;
} Loc_006D48C8;
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
} G_006D48C8;
typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad21[3];
    s32 f24;
    u8 pad28[0x1644 - 0x28];
    s32 f1644;
    u8 f1648[1];
} S_006D48C8;
typedef struct {
    u8 pad0[0x2DC];
    s32 f2DC;
} D_006D48C8;
extern u16 D_L39_00249DB8[];
extern u8 D_00197C68[];
extern void *func_001206F4(void *, void *);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_001962D8(s32);
extern s32 func_001962E8(void);
extern void func_00195500(void);

u8 *func_L39_006D2140(S_006D48C8 *p, s32 a, s32 *out) {
    G_006D48C8 *g;
    Loc_006D48C8 x;
    D_006D48C8 *d;
    s32 r;
    s32 code;
    u8 *ret;

    g = D_L39_0024D860;
    p->f1644 = 0;
    x.f0 = D_L39_00249DB8[0];
    func_001206F4(x.f15, g->f50);
    x.f28 = a;
    p->f20 = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001962D8(func_0017EAA8((u16 *)&x, D_00197C68, 0));
    d = (D_006D48C8 *)D_001A5E50;
    while (p->f20) {
        if (func_001962E8() != 0 || d->f2DC != 0) {
            g->f10 = 0x2F;
            if (g->f14 == 0) {
                g->f14 = 0x2F;
            }
            r = 0;
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
    p->f20 = 0;
    code = p->f24;
    if (code == 1) {
        p->f1644 = 0;
    } else if (code == -0x3DF || code == -0x3D1) {
        g->f10 = 0x35;
        if (g->f14 == 0) {
            g->f14 = 0x35;
        }
        r = 0;
    } else if (code < 0) {
        g->f10 = 0x2F;
        if (g->f14 == 0) {
            g->f14 = 0x2F;
        }
        r = 0;
    }
    ret = 0;
    *out = 0;
    if (r) {
        *out = p->f1644;
        ret = p->f1648;
    }
    return ret;
}
/* localdecomp:end func_L39_006D2140 */
