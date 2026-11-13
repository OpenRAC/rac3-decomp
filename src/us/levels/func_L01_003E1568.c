#include "common.h"

/* NTSC-U version of func_L01_003E32F8 (src/levels/01_veldin/L01_003E32F8.c): 60 Hz timing, scale 1/60 instead of 0.02 and no (n * 5 + 2) / 6 conversion */
#include "vu0.h"

/* localdecomp:start func_L01_003E1568 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { f32 x, y, z, w; } W4;
typedef struct { char p0[0x10]; f32 x; f32 y; } H;
typedef struct { f32 x, y; char p[0x460 - 8]; } E;

extern s32 D_001D52F0;
__asm__(".extern D_001D52F0, 16");
extern E D_L01_001E2AC0[];
extern W4 D_L01_001DF648;
extern f32 D_L01_001DFBD0;
extern f32 D_001DF638_sda_003E1568;
__asm__(".extern D_001DF638_sda_003E1568, 4");
extern f32 D_001DF63C_sda_003E1568;
__asm__(".extern D_001DF63C_sda_003E1568, 4");
extern f32 D_001DF640_sda;
__asm__(".extern D_001DF640_sda, 4");

extern f32 func_00388A28(f32 a, f32 b);
extern f32 func_00389380(f32 a, f32 b);
extern f32 func_0037E250(f32 a, f32 b);
extern f32 func_L01_00440918(f32 a, f32 b);
extern void func_0037E4B8(V4 *v, f32 a, f32 b, f32 c);
extern s32 func_0037E1D8(s32 a);
extern s32 func_0037E208(s32 a, s32 b);
extern void func_L01_00329470(V4 *a, V4 *b, s32 c, s32 d, s32 e, s32 f, W4 *g, s32 h, s32 i, s32 j, f32 k, f32 l);

void func_L01_003E1568(H *a0, V4 *a1) {
    V4 v1;
    V4 v2;
    W4 v3;
    f32 a, b, c, d;
    s32 col, flag, n, t;

    E *e;
    e = &D_L01_001E2AC0[D_001D52F0];
    v2 = *a1;
    a = func_00388A28(e->x - a0->x, e->y - a0->y);
    b = func_0037E250(D_001DF638_sda_003E1568 * 0.300000011921f, D_001DF638_sda_003E1568);
    b = b * 0.0166666675f;
    c = func_L01_00440918(0.0f, 1.39626336098f);
    d = func_L01_00440918(0.0f, 1.57079637051f);
    func_0037E4B8(&v1, b, func_00389380(a, d), c);
    col = 0x7F3F81A3;
    if (func_0037E1D8(3)) col = 0x7F519DC5;
    v3 = D_L01_001DF648;
    if (D_L01_001DFBD0 < 0.800000011920929f && func_0037E1D8(4) == 0) {
        flag = 1;
    } else {
        flag = 0;
    }
    n = func_0037E208(100, 250);
    t = (s16)func_0037E208(250, 300);
    func_L01_00329470(&v2, &v1, n, flag, 0, col, &v3, 0, t, 400, D_001DF640_sda, D_001DF63C_sda_003E1568);
}
/* localdecomp:end func_L01_003E1568 */
