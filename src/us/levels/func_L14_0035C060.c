#include "common.h"

/* NTSC-U counterpart of func_L14_0035D088 (src/levels/14_koros/L14_0035C810.c) */
#include "vu0.h"
extern void func_L14_0035C060(u8 *, f32, f32);

/* localdecomp:start func_L14_0035C060 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_35D088;
typedef struct {
    u8 pad[0x80];
    f32 x;
    f32 y;
} S_35D088_a;
typedef struct {
    u8 pad[0x140];
    f32 x;
    f32 y;
} S_35D088_b;
typedef struct {
    u8 pad[0x5C];
    u8 *p5C;
} S_35D088_c;
extern S_35D088_a D_001A4BE0;
extern S_35D088_b D_L14_001E1F80_0035C060;
extern S_35D088_c D_L14_0021F958_0035C060;
extern f32 func_00388A28(f32, f32);
extern f32 func_0037E250(f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_00389380(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_0046DCB8(void *, void *, s32, f32, f32, u32, s32, s32, s32, f32, s32);
void func_L14_0035C060(u8 *a0, f32 unused_f12, f32 unused_f13) {
    V4_35D088 m;
    V4_35D088 v;
    V4_35D088 p;
    f32 base;
    f32 r;
    f32 ang;
    s32 i;
    u32 col;
    s32 life;
    s32 k;
    u8 *e;
    s32 i2;
    u32 col2;
    s32 life2;
    f32 ang2;
    m = *(V4_35D088 *)(a0 + 0xC0);
    base = func_00388A28(D_001A4BE0.x - D_L14_001E1F80_0035C060.x, D_001A4BE0.y - D_L14_001E1F80_0035C060.y);
    for (i = 14; i >= 0; i--) {
        col = 0x625D34;
        r = func_0037E250(0.004166666883975267f, 0.010000000707805157f);
        ang = func_00389380(base, func_L01_00440918(0.0f, -6.2831855f));
        v.x = func_00388960(ang) * r;
        v.y = func_00388978(ang) * r;
        v.z = 0.0f;
        p.x = *(f32 *)(a0 + 0x10) + func_0037E250(-1.0f, 1.0f);
        p.y = *(f32 *)(a0 + 0x14) + func_0037E250(-1.0f, 1.0f);
        p.z = *(f32 *)(a0 + 0x18) + 0.5f;
        if (func_0037E1D8(4) != 0) {
            col = 0x4F5C8DC0;
        }
        life = func_0037E208(40, 60);
        k = func_0037E208(-1, -3);
        e = func_L01_0046DCB8(&p, &v, life, 63000.004f, 336000.0f, col, k, 0x3F, 0, func_0037E250(-0.5f, -3.0f) * 0.00027777778450399637f, 0);
        if (e != 0) {
            e[3] = 0x44;
            e[2] = D_L14_0021F958_0035C060.p5C[0];
        }
    }
    if (*(f32 *)(a0 + 0xE8) == 1.0f) {
        for (i2 = 39; i2 >= 0; i2--) {
            col2 = 0x625D34;
            p.x = *(f32 *)(a0 + 0x10) + func_L01_00440918(0.0f, 0.15f);
            p.y = *(f32 *)(a0 + 0x14) + func_L01_00440918(0.0f, 0.15f);
            p.z = *(f32 *)(a0 + 0x18) + 0.2f;
            ang2 = func_00389380(base, func_L01_00440918(0.0f, -6.2831855f));
            v.x = func_00388960(ang2) * 0.10000000894069672f;
            v.y = func_00388978(ang2) * 0.10000000894069672f;
            v.z = 0.0f;
            if (func_0037E1D8(3) != 0) {
                col2 = 0x4C777C;
            }
            life2 = func_0037E208(50, 70);
            k = func_0037E208(-2, -4);
            e = func_L01_0046DCB8(&p, &v, life2, 63000.004f, 168000.0f, col2, k, 0x40, 0, 0.0f, 0);
            if (e != 0) {
                e[2] = D_L14_0021F958_0035C060.p5C[0];
            }
        }
    }
}
/* localdecomp:end func_L14_0035C060 */
