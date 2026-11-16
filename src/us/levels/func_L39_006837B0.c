#include "common.h"

/* NTSC-U counterpart of func_L39_006862D0 (src/levels/39_multiplayer_menu/L39_006862D0.c) */
typedef struct {
    u8 pad0[0x1C0];
    u32 f1C0;
    u32 f1C4;
    u8 pad1C8[0x5C0 - 0x1C8];
} Pad_00686138;

/* localdecomp:start func_L39_006837B0 */
typedef struct VT_006862D0 {
    u8 pad0[0x14];
    s32 (*fn14)(void *, s32);
    u8 pad18[0xF8 - 0x18];
    void (*fnF8)(void *, s32);
} VT_006862D0;
typedef struct Obj_006862D0 {
    u8 pad0[0x60];
    VT_006862D0 *vt;
    u8 pad64[0x108 - 0x64];
    s32 f108;
} Obj_006862D0;
typedef struct P_006862D0 {
    u8 pad0[0x110];
    Obj_006862D0 *objs[44];
    s32 f1C0[44];
    s32 f270;
    s32 f274;
    u8 pad278[4];
    s32 f27C;
    u8 f280;
} P_006862D0;
typedef struct G_006862D0 {
    u8 pad0[0x2DC];
    s32 f2DC;
    u8 pad2E0[0x85D - 0x2E0];
    u8 b85D;
    u8 pad85E[0x864 - 0x85E];
    u8 b864;
    u8 pad865[0x868 - 0x865];
    s32 f868;
    u8 pad86C[0x87C - 0x86C];
    u8 s87C[1];
} G_006862D0;
typedef struct M_006862D0 {
    u8 pad0[0x34];
    s32 f34;
    s32 f38;
    u8 pad3C[0x44 - 0x3C];
    s32 f44;
    s32 f48;
    s32 f4C;
} M_006862D0;
typedef struct Q_006862D0 {
    u8 pad0[0x14];
    s32 f14;
} Q_006862D0;
extern G_006862D0 D_001A5E50;
extern s32 D_001A612C[];
extern Pad_00686138 *D_L39_002412E4;
__asm__(".extern D_L39_002412E4, 16");
extern u8 D_L39_00372BC0[];
extern u8 D_L39_00247B00[];
extern M_006862D0 D_L39_003D2980;
extern s32 D_L39_004AE188[];
__asm__(".extern D_001DC1E4_sda, 4");
__asm__(".extern D_001E1FD0_sda, 4");
extern s32 D_001DC1E4_sda;
extern Q_006862D0 *D_001E1FD0_sda;
extern void func_L39_00686A68(void);
extern s32 func_00120884(u8 *);
extern void func_L39_005945F0(u8 *, u8 *, s32);
extern s32 func_0037DF98(s32);
extern s32 func_L39_006847C8(void *, s32, s32, s32, s32, f32);
extern void func_L39_006855C8(void *, u8 *, u8 *);
extern void func_L01_00512AB0(s32, s32, s32);
extern s32 func_L01_00513548(s32, f32, f32);
extern s32 func_L39_00684EC0(void *, s32);
extern void func_L39_00684320(void *);
extern s32 func_001962E8(void);
extern void func_001962D8(s32);
extern void func_001375B0(u8 *, u8 *, s32);

void func_L39_006837B0(P_006862D0 *arg0)
{
    u8 a[0x40];
    u8 b[0x40];
    u8 c[0x40];
    s32 s19;
    s32 str;
    s32 n;
    s32 i;
    Obj_006862D0 *o;
    s32 ev;


    func_L39_00686A68();
    s19 = func_L39_00683618((u8 *)arg0, D_L39_002412E4);

    if (arg0->f274 == -1 && D_001A5E50.b85D != 0 && arg0->f1C0[arg0->f270] != 0x21) {
        if (D_001A5E50.f868 != 2) {
            str = (s32)D_001A5E50.s87C;
        } else {
            n = func_00120884(D_001A5E50.s87C);
            func_L39_005945F0(D_L39_00372BC0, D_001A5E50.s87C, n < 0x400 ? n : 0x3FF);
            str = (s32)D_L39_00372BC0;
        }
        switch (D_001A5E50.b864) {
        case 1:
            str = func_0037DF98(0x1B91);
            break;
        case 2:
            str = func_0037DF98(0x1B92);
            break;
        case 3:
            str = func_0037DF98(0x1B93);
            break;
        }
        D_001A5E50.b85D = 0;
        func_L39_006847C8(arg0, (s32)D_L39_00247B00, str, 4, 1, 1.6f);
        if (D_001A5E50.b864 >= 2) {
            func_L39_006855C8(arg0, a, b);
            return;
        }
    }
    if (arg0->f270 >= 0 || arg0->f274 >= 0) {
        if (arg0->f274 >= 0) {
            func_L01_00512AB0(D_L39_003D2980.f44, 1, 0);
            func_L01_00512AB0(D_L39_003D2980.f4C, 1, 0);
            func_L01_00512AB0(D_L39_003D2980.f48, 1, 0);
            func_L01_00513548(D_L39_003D2980.f34, 1.0f, 1.0f);
            func_L01_00513548(D_L39_003D2980.f38, 1.0f, 1.0f);
            if (arg0->objs[arg0->f274]->vt->fn14(arg0->objs[arg0->f274], s19) == 0) {
                arg0->objs[arg0->f274]->vt->fnF8(arg0->objs[arg0->f274], s19);
            }
            if (arg0->f270 >= 0) {
                o = arg0->objs[arg0->f270];
                if (o->f108 == 0x21) {
                    o->vt->fn14(o, 0);
                }
            }
        } else if (func_L39_00684EC0(arg0, s19) == 0) {
            if (arg0->objs[arg0->f270]->vt->fn14(arg0->objs[arg0->f270], s19) == 0) {
                arg0->objs[arg0->f270]->vt->fnF8(arg0->objs[arg0->f270], s19);
            }
        }
    }
    if (D_001DC1E4_sda == 0) {
        return;
    }
    ev = D_001E1FD0_sda->f14;
    D_001E1FD0_sda->f14 = 0;
    if (ev == 0 && D_001A612C[0] == 0 && func_001962E8() == 0) {
        arg0->f27C = 0;
    } else if (arg0->f280 == 0) {
        if (D_001A5E50.f2DC == 2 || ev == 8 || ev == 2) {
            if (++arg0->f27C >= 0x79 && arg0->f274 < 0) {
                u8 *buf;
                arg0->f27C = 0;
                func_001375B0(a, c, 0x40);
                buf = D_L39_00247B00;
                if (func_L39_006847C8(arg0, func_0037DF98(0x1189), (s32)buf, 0x30, 0, 0.6f) == 0x20) {
                    func_L39_006855C8(arg0, a, c);
                    return;
                }
                D_001A5E50.f2DC = 0;
                func_001962D8(0);
                arg0->f27C = 0;
            }
        } else {
            if (ev != 0 && ev != 0x3E && ev != 0x2E && ev != 0x12 && ev != 0x2F && ev != 0x27 &&
                ev != 0x26 && ev != 0x4B && ev != 0xF) {
                func_L39_006847C8(arg0, (s32)D_L39_00247B00, func_0037DF98(D_L39_004AE188[ev]), 4, 0, 0.6f);
            }
        }
    }
    func_L39_00684320(arg0);
}
/* localdecomp:end func_L39_006837B0 */
