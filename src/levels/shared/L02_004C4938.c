#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_004C4938;
typedef struct {
    V4_004C4938 v0;
    u8 pad10[0xF0 - 0x10];
    V4_004C4938 pos;
    u8 pad100[0x290 - 0x100];
    s32 w290;
    u8 pad294[0x25C0 - 0x294];
    void *p25C0;
    u8 pad25C4[8];
    s32 w25CC;
} G_004C4938;
typedef struct { u8 pad0[0x18]; s32 w18; s32 w1C; u8 pad20[0x20]; V4_004C4938 v40; } H_004C4938;

/* localdecomp:start func_L02_004C4938 */
#include "vu0.h"

extern G_004C4938 D_001A4BE0;
extern H_004C4938 D_L02_001E8040;
__asm__(".extern D_L02_001E8040, 16");
extern f32 func_L01_00511408(void *);
extern void func_L01_005110E8(f32 *, f32, f32, f32, s32);
extern f32 func_0038CED8(void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_00511508(void *dst, void *src, f32 k);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003D5630(void);
extern f32 func_L01_00511848(void *);
extern f32 func_0038CE68(void *, void *);

void func_L02_004C4938(s32 force)
{
    V4_004C4938 a;
    V4_004C4938 b;
    V4_004C4938 c;
    V4_004C4938 d;
    f32 h;
    f32 k;
    f32 f;
    f32 g;
    s32 r;

    if (func_L01_00511408(&D_001A4BE0.pos) < 0.002f) {
        return;
    }
    h = 0.395f;
    k = 0.5f;
    if ((u32)(D_001A4BE0.w25CC - 0x11) < 2) {
        h = 0.0f;
        k = 0.7f;
    }
    func_L01_005110E8(&a.x, 0.0f, 0.0f, h, 1);
    func_L01_005110E8(&c.x, 0.0f, 0.0f, h * 0.3f, 1);
    if (force != 0 || func_0038CED8(&D_001A4BE0.pos) < 0.01f) {
        func_0038CF68(&b, &D_001A4BE0.v0, k);
        func_0038CF68(&d, &D_001A4BE0.v0, k * 1.4f);
    } else {
        func_L01_00511508(&b, &D_001A4BE0.pos, 0.0f);
        func_0038CF68(&b, &b, k);
        func_0038CE20(&d, &b, 1.4f);
    }
    vec_add_ba(&b, &b, &a);
    vec_add_ab(&d, &d, &c);
    r = -1;
    if (func_003D3CB0(&c, &d, 2, D_001A4BE0.p25C0, 0) != 0 && D_L02_001E8040.w1C > 0) {
        r = func_003D5630();
    }
    f = 0.0f;
    if (func_003D3CB0(&a, &b, 2, D_001A4BE0.p25C0, 0) != 0 && D_L02_001E8040.w1C > 0) {
        f = func_L01_00511848(&D_L02_001E8040.v40);
    }
    if (f >= 0.87266463f || r == 8 || r == 12) {
        D_001A4BE0.w290 = D_L02_001E8040.w18;
        func_L01_00511508(&D_L02_001E8040.v40, &D_L02_001E8040.v40, 0.0f);
        func_0038CF68(&D_L02_001E8040.v40, &D_L02_001E8040.v40, 1.0f);
        g = func_0038CE68(&D_L02_001E8040.v40, &D_001A4BE0.pos);
        if (g < 0.0f) {
            func_0038CE20(&D_L02_001E8040.v40, &D_L02_001E8040.v40, -g);
            vec_add_ba(&D_001A4BE0.pos, &D_001A4BE0.pos, &D_L02_001E8040.v40);
        }
    }
}
/* localdecomp:end func_L02_004C4938 */
