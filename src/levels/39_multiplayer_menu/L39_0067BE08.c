#include "common.h"

typedef struct { int a, b, c; } T;

/* declared by functions of L39_0067BC58.c, which this file was cut from */
extern char *func_00381FF0(s32);

/* localdecomp:start func_L39_0067BE08 */
typedef struct { s32 a, b; } E_0067BE08;
typedef struct {
    u8 pad[0x4954];
    s32 base;
    E_0067BE08 tab[1];
} S_0067BE08;

extern S_0067BE08 D_001F0A00;
extern s32 D_L39_00247520;
extern f32 D_L39_00247A70;
extern f32 D_L39_00247A74;
extern f32 D_L39_00247A78;
extern f32 D_L39_00247A7C;
__asm__(".extern D_001DB0D4_sda, 4");
extern f32 D_001DB0D4_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DB0D8_sda, 4");
extern f32 D_001DB0D8_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DB0DC_sda, 4");
extern f32 D_001DB0DC_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DB0E0_sda, 4");
extern f32 D_001DB0E0_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DB0E4_sda, 4");
extern f32 D_001DB0E4_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DB0E8_sda, 4");
extern f32 D_001DB0E8_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DB0EC_sda, 4");
extern f32 D_001DB0EC_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DB0F0_sda, 4");
extern f32 D_001DB0F0_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DB0F4_sda, 4");
extern f32 D_001DB0F4_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DB0F8_sda, 4");
extern f32 D_001DB0F8_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DC364_sda, 4");
extern f32 D_001DC364_sda __attribute__((section(".sdata")));
__asm__(".extern D_001DC36C_sda, 4");
extern f32 D_001DC36C_sda __attribute__((section(".sdata")));

extern s32 func_003B5060(s32);
extern f32 func_L39_005B4410(f32, f32);
extern s32 func_003E9138(s32, s32, f32, f32, f32, f32, s32);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_003A26F0(s32, s32, s32);
extern s32 func_003B43B0(s32);
extern void func_L39_005DBEE8(s32, s32, s32);
extern s32 func_003E8710(s32, s32);
extern s32 func_L01_00517190(s32, s32);
extern s32 func_L01_00518110(s32, s32, s32, s32);
extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E8AE8(s32, s32, s32, s32, s32, s32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E8630(s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00517538(s32, f32, f32);
extern void func_L39_00611628(s32, f32 *);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_L01_005169C8(s32, f32);

extern s32 func_L01_00516C78(s32, s32, s32);
extern s32 func_003E8348(s32, s32);

s32 func_L39_0067BE08(s32 p0, s32 p1, s32 p2, s32 p3, s32 p4, s32 p5, s32 p6, s32 p7,
                      f32 scale, s32 p8, s32 p9, s32 p10, s32 p11, s32 p12, s32 p13,
                      s32 p14, s32 p15) {
    f32 box[4];
    s32 ok;
    f32 x;
    f32 w;
    f32 t;
    s32 s;

    ok = func_003B5060(p4) != 0;
    x = func_L39_005B4410(0.0f, 1.0f);
    x = x + x;
    { s32 r = func_003E9138(p1, 0, x + 0.0f, 0.5f, 1.999f, 1.0f, 0) != 0; ok &= r; }
    { s32 r = func_003E9138(p2, 0, x + -2.0f, 0.5f, 1.999f, 1.0f, 0) != 0; ok &= r; }
    { s32 r = func_003E9138(p3, 0x331465B7, D_001DB0E4_sda, D_001DB0E8_sda, D_001DB0EC_sda, D_001DB0F0_sda, 0) != 0; ok &= r; }
    s = D_001F0A00.tab[func_L39_005B43C8(0x41, 0x46)].a + D_001F0A00.base;
    func_003A26F0(D_L39_00247520, s, D_001F0A00.tab[func_L39_005B43C8(0x41, 0x46)].b);
    func_L39_005DBEE8(func_003B43B0(0), D_L39_00247520, 0);
    { s32 r = func_003E8710(p1, func_003B43B0(0)) != 0; ok &= r; }
    { s32 r = func_003E8710(p2, func_003B43B0(0)) != 0; ok &= r; }
    { s32 r = func_L01_00517190(p1, 1) != 0; ok &= r; }
    { s32 r = func_L01_00517190(p2, 1) != 0; ok &= r; }
    { s32 r = func_L01_00518110(p4, p1, p2, p3) != 0; ok &= r; }
    { s32 r = func_003E8EF0(p7, 0x35, 0x331465B7, D_001DB0E4_sda, D_001DB0E8_sda, 1.0f, 1.0f, scale) != 0; ok &= r; }
    { s32 r = func_003E8EF0(p8, 0x36, 0x802299DE, D_001DB0E4_sda, D_001DB0E8_sda, 1.0f, 1.0f, scale) != 0; ok &= r; }
    { s32 r = func_003E8EF0(p5, 0x33, 0x332299DE, D_001DB0E4_sda, D_001DB0E8_sda, 1.0f, 1.0f, scale) != 0; ok &= r; }
    { s32 r = func_003E8EF0(p6, 0x34, 0x332299DE, D_001DB0E4_sda, D_001DB0E8_sda, 1.0f, 1.0f, scale) != 0; ok &= r; }
    { s32 r = func_003E9270(p10, 0x332299DE, D_001DB0E4_sda, D_001DB0E8_sda, D_001DB0EC_sda, D_001DB0F0_sda, D_001DB0F4_sda, D_001DB0F8_sda) != 0; ok &= r; }
    { s32 r = func_003E8AE8(p4, p5, p6, p7, p8, p10) != 0; ok &= r; }
    { s32 r = func_003E8FE8(p9, p11, 0x8066CCFF, 0.5f, 0.07f, 1.2f, 1.2f) != 0; ok &= r; }
    { s32 r = func_003E8630(p4, p9) != 0; ok &= r; }
    { s32 r = func_L01_00516AA0(p9, 0x40, 1) != 0; ok &= r; }
    func_L01_00517538(p9, 1.2f, 1.2f);
    func_L39_00611628(p9, box);
    w = box[2] - box[0];
    if (D_L39_00247A78 < w) {
        f32 k = D_L39_00247A78 * 1.2f / w;
        func_L01_00517538(p9, k, k);
        w = D_L39_00247A78;
    }
    t = func_003C4088(D_L39_00247A74, D_001DC36C_sda,
                      (w - D_L39_00247A70) / (D_L39_00247A78 - D_L39_00247A70));
    if (D_L39_00247A7C < t) {
        t = D_L39_00247A7C;
    } else if (t < D_001DC364_sda) {
        t = D_001DC364_sda;
    }
    func_L01_005169C8(p5, t);
    func_L01_005169C8(p6, t);
    func_L01_005169C8(p7, t);
    func_L01_005169C8(p8, t);
    if (p12 != 0) {
        { s32 r = func_003E8FE8(p12, (s32)func_00381FF0(p13), 0x8066CCFF, D_001DB0D4_sda, D_001DB0D8_sda, 1.0f, 1.0f) != 0; ok &= r; }
        { s32 r = func_L01_00516AA0(p12, 0x40, 1) != 0; ok &= r; }
        { s32 r = func_L01_00516C78(p12, 3, 3) != 0; ok &= r; }
        { s32 r = func_003E8630(p4, p12) != 0; ok &= r; }
    }
    if (p14 != 0) {
        { s32 r = func_003E8FE8(p14, (s32)func_00381FF0(p15), 0x8066CCFF, D_001DB0DC_sda, D_001DB0E0_sda, 1.0f, 1.0f) != 0; ok &= r; }
        { s32 r = func_L01_00516AA0(p14, 0x40, 1) != 0; ok &= r; }
        { s32 r = func_L01_00516C78(p14, 3, 3) != 0; ok &= r; }
        { s32 r = func_003E8630(p4, p14) != 0; ok &= r; }
    }
    {
        s32 r = func_003E8348(p0, p4) != 0;
        return ok & r;
    }
}
/* localdecomp:end func_L39_0067BE08 */
