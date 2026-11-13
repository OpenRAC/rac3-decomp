#include "common.h"

/* NTSC-U counterpart of func_L23_004D1678 (src/levels/23_holostar_studios_clank/L23_004D1678.c): 0.002 -> 0.00166667 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_4D1678;
typedef struct {
    V4_4D1678 v0;
    u8 pad10[0xF0 - 0x10];
    V4_4D1678 pos;
    u8 pad100[0x290 - 0x100];
    s32 w290;
    u8 pad294[0x25C0 - 0x294];
    void *p25C0;
    u8 pad25C4[8];
    s32 w25CC;
    u8 pad25D0[0x25E4 - 0x25D0];
    u8 b25E4;
} G_4D1678;
typedef struct { u8 pad0[0x18]; s32 w18; s32 w1C; u8 pad20[0x20]; V4_4D1678 v40; } H_4D1678;

/* localdecomp:start func_L23_004CD8D8 */
#include "vu0.h"
extern G_4D1678 D_001A4BE0;
extern H_4D1678 D_L23_001E8800;
__asm__(".extern D_L23_001E8800, 16");
extern f32 func_L01_0050D430(void *);
extern void func_L01_0050D110(f32 *, f32, f32, f32, s32);
extern f32 func_0038CED8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0050D530(void *dst, void *src, f32 k);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003D5630(void);
extern f32 func_L01_0050D870(void *);
extern f32 func_0038CE68(void *, void *);

void func_L23_004CD8D8(s32 force)
{
    V4_4D1678 a;
    V4_4D1678 b;
    V4_4D1678 c;
    V4_4D1678 d;
    f32 h;
    f32 k;
    f32 f;
    f32 g;
    s32 r;

    if (func_L01_0050D430(&D_001A4BE0.pos) < 0.00166666682f) {
        return;
    }
    h = 0.395f;
    k = 0.5f;
    if ((u32)(D_001A4BE0.w25CC - 0x11) < 2) {
        h = 0.0f;
        k = 0.7f;
    } else if (D_001A4BE0.b25E4 == 1) {
        h = 0.35f;
        k = 0.27f;
    } else if (D_001A4BE0.b25E4 == 2) {
        h = 0.75f;
        k = 3.75f;
    }
    func_L01_0050D110(&a.x, 0.0f, 0.0f, h, 1);
    func_L01_0050D110(&c.x, 0.0f, 0.0f, h * 0.3f, 1);
    if (force != 0 || func_0038CED8(&D_001A4BE0.pos) < 0.01f) {
        func_0038CF68(&b, &D_001A4BE0.v0, k);
        func_0038CF68(&d, &D_001A4BE0.v0, k * 1.4f);
    } else {
        func_L01_0050D530(&b, &D_001A4BE0.pos, 0.0f);
        func_0038CF68(&b, &b, k);
        func_0038CE20(&d, &b, 1.4f);
    }
    vec_add_ba(&b, &b, &a);
    vec_add_ab(&d, &d, &c);
    r = -1;
    if (func_003D3CB0(&c, &d, 2, D_001A4BE0.p25C0, 0) != 0 && D_L23_001E8800.w1C > 0) {
        r = func_003D5630();
    }
    f = 0.0f;
    if (func_003D3CB0(&a, &b, 2, D_001A4BE0.p25C0, 0) != 0 && D_L23_001E8800.w1C > 0) {
        f = func_L01_0050D870(&D_L23_001E8800.v40);
    }
    if (f >= 0.87266463f || r == 8 || r == 12) {
        D_001A4BE0.w290 = D_L23_001E8800.w18;
        func_L01_0050D530(&D_L23_001E8800.v40, &D_L23_001E8800.v40, 0.0f);
        func_0038CF68(&D_L23_001E8800.v40, &D_L23_001E8800.v40, 1.0f);
        g = func_0038CE68(&D_L23_001E8800.v40, &D_001A4BE0.pos);
        if (g < 0.0f) {
            func_0038CE20(&D_L23_001E8800.v40, &D_L23_001E8800.v40, -g);
            vec_add_ba(&D_001A4BE0.pos, &D_001A4BE0.pos, &D_L23_001E8800.v40);
        }
    }
}
/* localdecomp:end func_L23_004CD8D8 */
