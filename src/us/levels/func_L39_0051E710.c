#include "common.h"

/* NTSC-U counterpart of func_L39_0051EB38 (src/levels/shared/L39_0051EB38.c): 0.02 -> 0.0166667; 100 -> 120; 125 -> 150 */
/* localdecomp:start func_L39_0051E710 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0051EB38;
typedef struct { s32 x, y, z, w; } W4_0051EB38;
typedef struct { u8 pad[0x24]; f32 f24; } Inner_0051EB38;
typedef struct { u8 pad[0x24]; Inner_0051EB38 *f24; u8 pad28[4]; f32 f2C; } Obj_0051EB38;

extern f32 D_L39_0024A9E4;
__asm__(".extern D_L39_0024A9E4, 4");
extern f32 D_L39_0024A9BC;
__asm__(".extern D_L39_0024A9BC, 4");
extern f32 D_L39_0024A9E0_0051E710;
__asm__(".extern D_L39_0024A9E0_0051E710, 4");
extern f32 D_L39_0024A9C0;
__asm__(".extern D_L39_0024A9C0, 4");
extern f32 D_L39_0024A9C4;
__asm__(".extern D_L39_0024A9C4, 4");
extern s32 D_L39_0024A9D8;
__asm__(".extern D_L39_0024A9D8, 4");
extern s32 D_L39_0024A9DC;
__asm__(".extern D_L39_0024A9DC, 4");
extern s32 D_L39_0024A9C8;
__asm__(".extern D_L39_0024A9C8, 4");
extern s32 D_L39_0024A9CC;
__asm__(".extern D_L39_0024A9CC, 4");
extern s32 D_L39_0024A9D0;
__asm__(".extern D_L39_0024A9D0, 4");
extern s32 D_L39_0024A9D4;
__asm__(".extern D_L39_0024A9D4, 4");
extern s32 D_L39_0024145C;

extern f32 func_L39_005B2510(f32, f32);
extern f32 func_L39_005B25C8_0051E710(void);
extern s32 func_L39_005B2498(s32);
extern s32 func_L39_005B24C8(s32, s32);
extern void func_0037E4B8(V4_0051EB38 *, f32, f32, f32);
extern void func_003888C8(void *, void *, void *);
extern Obj_0051EB38 *func_L01_00329470(V4_0051EB38 *a, V4_0051EB38 *b, s32 c, s32 d, s32 e, s32 f, W4_0051EB38 *g, s32 h, s32 i, s32 j, f32 k, f32 l);

void func_L39_0051E710(u8 *a0, V4_0051EB38 *a1) {
    V4_0051EB38 v1;
    V4_0051EB38 v2;
    W4_0051EB38 v3;
    f32 b, c, d;
    s32 col, flag;
    Obj_0051EB38 *o;

    v2 = *a1;
    b = func_L39_005B2510(D_L39_0024A9E4 * 0.4f, D_L39_0024A9E4);
    b = b * 0.0166666675f;
    b = b * D_L39_0024A9BC;
    c = func_L39_005B25C8_0051E710();
    d = func_L39_005B2510(0.43633232f, 0.78539819f);
    func_0037E4B8(&v1, b, c, d);
    func_003888C8(&v1, &v1, a0 + 0xC0);
    col = 0;
    switch (D_L39_0024145C) {
    case 0x20:
        col = 0x699A9C;
        if (func_L39_005B2498(3)) col = 0x96B3B4;
        break;
    case 0x29:
        col = 0x5A523E;
        if (func_L39_005B2498(3)) col = 0x605129;
        break;
    case 0x2A:
        if (func_L39_005B2498(3)) {
            col = D_L39_0024A9DC;
        } else {
            col = D_L39_0024A9D8;
        }
        break;
    }
    v3 = (W4_0051EB38){D_L39_0024A9C8, D_L39_0024A9CC, D_L39_0024A9D0, D_L39_0024A9D4};
    flag = func_L39_005B2498(3) == 0;
    o = func_L01_00329470(&v2, &v1, func_L39_005B24C8(120, 150), flag, 1, col, &v3, 0, 0x28, 0x3C, 1.0f, D_L39_0024A9E0_0051E710);
    if (o != 0) {
        o->f2C = o->f24->f24 * func_L39_005B2510(D_L39_0024A9C0, D_L39_0024A9C4);
    }
}
/* localdecomp:end func_L39_0051E710 */
