#include "common.h"

typedef s32 (*FnVcall_006826C0)(void *, s32, s32);

typedef struct {
    u8 pad0[0x60];
    void *f60;
    s32 f64;
    s32 f68;
    s32 f6C;
    s32 f70;
    s32 f74;
} S_00683550;
typedef struct {
    u8 pad0[0x48];
    s32 f48;
} T_00683550;

typedef struct Vt_00685D48 {
    u8 pad_00[0x30];
    s32 (*f30)(void *, void *, void *);
    s32 (*f34)(void *, void *, void *);
} Vt_00685D48;

typedef void (*Fn_00686768)(void *);
typedef struct S_00686768 {
    u8 pad[0x110];
    u8 *arr[1];
} S_00686768;

/* declared by functions of L39_00686138.c, which this file was cut from */
typedef struct {
    u8 pad0[0x1C0];
    u32 f1C0;
    u32 f1C4;
    u8 pad1C8[0x5C0 - 0x1C8];
} Pad_00686138;

/* localdecomp:start func_L39_006862D0 */
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
extern G_006862D0 D_001A5CD0;
extern s32 D_001A5FAC[];
extern Pad_00686138 *D_L39_00241164;
__asm__(".extern D_L39_00241164, 16");
extern u8 D_L39_00372AC0[];
extern u8 D_L39_002479A0[];
extern M_006862D0 D_L39_003D2880;
extern s32 D_L39_004AE0C8[];
__asm__(".extern D_001DC204_sda, 4");
__asm__(".extern D_001E2050_sda, 4");
extern s32 D_001DC204_sda;
extern Q_006862D0 *D_001E2050_sda;
extern void func_L39_00689610(void);
extern s32 func_00120884(u8 *);
extern void func_L39_005958A0(u8 *, u8 *, s32);
extern s32 func_00381FF0(s32);
extern s32 func_L39_006872E8(void *, s32, s32, s32, s32, f32);
extern void func_L39_00688108(void *, u8 *, u8 *);
extern void func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_L39_006879E0(void *, s32);
extern void func_L39_00686E40(void *);
extern s32 func_001961F8(void);
extern void func_001961E8(s32);
extern void func_001375B0(u8 *, u8 *, s32);

void func_L39_006862D0(P_006862D0 *arg0)
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


    func_L39_00689610();
    s19 = func_L39_00686138((u8 *)arg0, D_L39_00241164);

    if (arg0->f274 == -1 && D_001A5CD0.b85D != 0 && arg0->f1C0[arg0->f270] != 0x21) {
        if (D_001A5CD0.f868 != 2) {
            str = (s32)D_001A5CD0.s87C;
        } else {
            n = func_00120884(D_001A5CD0.s87C);
            func_L39_005958A0(D_L39_00372AC0, D_001A5CD0.s87C, n < 0x400 ? n : 0x3FF);
            str = (s32)D_L39_00372AC0;
        }
        switch (D_001A5CD0.b864) {
        case 1:
            str = func_00381FF0(0x1B91);
            break;
        case 2:
            str = func_00381FF0(0x1B92);
            break;
        case 3:
            str = func_00381FF0(0x1B93);
            break;
        }
        D_001A5CD0.b85D = 0;
        func_L39_006872E8(arg0, (s32)D_L39_002479A0, str, 4, 1, 1.6f);
        if (D_001A5CD0.b864 >= 2) {
            func_L39_00688108(arg0, a, b);
            return;
        }
    }
    if (arg0->f270 >= 0 || arg0->f274 >= 0) {
        if (arg0->f274 >= 0) {
            func_L01_00516AA0(D_L39_003D2880.f44, 1, 0);
            func_L01_00516AA0(D_L39_003D2880.f4C, 1, 0);
            func_L01_00516AA0(D_L39_003D2880.f48, 1, 0);
            func_L01_00517538(D_L39_003D2880.f34, 1.0f, 1.0f);
            func_L01_00517538(D_L39_003D2880.f38, 1.0f, 1.0f);
            if (arg0->objs[arg0->f274]->vt->fn14(arg0->objs[arg0->f274], s19) == 0) {
                arg0->objs[arg0->f274]->vt->fnF8(arg0->objs[arg0->f274], s19);
            }
            if (arg0->f270 >= 0) {
                o = arg0->objs[arg0->f270];
                if (o->f108 == 0x21) {
                    o->vt->fn14(o, 0);
                }
            }
        } else if (func_L39_006879E0(arg0, s19) == 0) {
            if (arg0->objs[arg0->f270]->vt->fn14(arg0->objs[arg0->f270], s19) == 0) {
                arg0->objs[arg0->f270]->vt->fnF8(arg0->objs[arg0->f270], s19);
            }
        }
    }
    if (D_001DC204_sda == 0) {
        return;
    }
    ev = D_001E2050_sda->f14;
    D_001E2050_sda->f14 = 0;
    if (ev == 0 && D_001A5FAC[0] == 0 && func_001961F8() == 0) {
        arg0->f27C = 0;
    } else if (arg0->f280 == 0) {
        if (D_001A5CD0.f2DC == 2 || ev == 8 || ev == 2) {
            if (++arg0->f27C >= 0x79 && arg0->f274 < 0) {
                u8 *buf;
                arg0->f27C = 0;
                func_001375B0(a, c, 0x40);
                buf = D_L39_002479A0;
                if (func_L39_006872E8(arg0, func_00381FF0(0x1189), (s32)buf, 0x20, 0, 0.6f) == 0x20) {
                    func_L39_00688108(arg0, a, c);
                    return;
                }
                D_001A5CD0.f2DC = 0;
                func_001961E8(0);
                arg0->f27C = 0;
            }
        } else {
            if (ev != 0 && ev != 0x3E && ev != 0x2E && ev != 0x12 && ev != 0x2F && ev != 0x27 &&
                ev != 0x26 && ev != 0x4B && ev != 0xF) {
                func_L39_006872E8(arg0, (s32)D_L39_002479A0, func_00381FF0(D_L39_004AE0C8[ev]), 4, 0, 0.6f);
            }
        }
    }
    func_L39_00686E40(arg0);
}
/* localdecomp:end func_L39_006862D0 */
