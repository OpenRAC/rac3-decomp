#include "common.h"

/* localdecomp:start func_L39_0051EB38 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0051EB38;
typedef struct { s32 x, y, z, w; } W4_0051EB38;
typedef struct { u8 pad[0x24]; f32 f24; } Inner_0051EB38;
typedef struct { u8 pad[0x24]; Inner_0051EB38 *f24; u8 pad28[4]; f32 f2C; } Obj_0051EB38;

extern f32 D_L39_0024A8D4;
__asm__(".extern D_L39_0024A8D4, 4");
extern f32 D_L39_0024A8AC;
__asm__(".extern D_L39_0024A8AC, 4");
extern f32 D_L39_0024A8D0;
__asm__(".extern D_L39_0024A8D0, 4");
extern f32 D_L39_0024A8B0;
__asm__(".extern D_L39_0024A8B0, 4");
extern f32 D_L39_0024A8B4;
__asm__(".extern D_L39_0024A8B4, 4");
extern s32 D_L39_0024A8C8;
__asm__(".extern D_L39_0024A8C8, 4");
extern s32 D_L39_0024A8CC;
__asm__(".extern D_L39_0024A8CC, 4");
extern s32 D_L39_0024A8B8;
__asm__(".extern D_L39_0024A8B8, 4");
extern s32 D_L39_0024A8BC;
__asm__(".extern D_L39_0024A8BC, 4");
extern s32 D_L39_0024A8C0;
__asm__(".extern D_L39_0024A8C0, 4");
extern s32 D_L39_0024A8C4;
__asm__(".extern D_L39_0024A8C4, 4");
extern s32 D_L39_002412DC;

extern f32 func_L39_005B4410(f32, f32);
extern f32 func_L39_005B44C8(void);
extern s32 func_L39_005B4398(s32);
extern s32 func_L39_005B43C8(s32, s32);
extern void func_00382760(V4_0051EB38 *, f32, f32, f32);
extern void func_0038D000(void *, void *, void *);
extern Obj_0051EB38 *func_L01_003298C8(V4_0051EB38 *a, V4_0051EB38 *b, s32 c, s32 d, s32 e, s32 f, W4_0051EB38 *g, s32 h, s32 i, s32 j, f32 k, f32 l);

void func_L39_0051EB38(u8 *a0, V4_0051EB38 *a1) {
    V4_0051EB38 v1;
    V4_0051EB38 v2;
    W4_0051EB38 v3;
    f32 b, c, d;
    s32 col, flag;
    Obj_0051EB38 *o;

    v2 = *a1;
    b = func_L39_005B4410(D_L39_0024A8D4 * 0.4f, D_L39_0024A8D4);
    b = b * 0.0200000014156f;
    b = b * D_L39_0024A8AC;
    c = func_L39_005B44C8();
    d = func_L39_005B4410(0.43633232f, 0.78539819f);
    func_00382760(&v1, b, c, d);
    func_0038D000(&v1, &v1, a0 + 0xC0);
    col = 0;
    switch (D_L39_002412DC) {
    case 0x20:
        col = 0x699A9C;
        if (func_L39_005B4398(3)) col = 0x96B3B4;
        break;
    case 0x29:
        col = 0x5A523E;
        if (func_L39_005B4398(3)) col = 0x605129;
        break;
    case 0x2A:
        if (func_L39_005B4398(3)) {
            col = D_L39_0024A8CC;
        } else {
            col = D_L39_0024A8C8;
        }
        break;
    }
    v3 = (W4_0051EB38){D_L39_0024A8B8, D_L39_0024A8BC, D_L39_0024A8C0, D_L39_0024A8C4};
    flag = func_L39_005B4398(3) == 0;
    o = func_L01_003298C8(&v2, &v1, func_L39_005B43C8(100, 125), flag, 1, col, &v3, 0, 0x28, 0x3C, 1.0f, D_L39_0024A8D0);
    if (o != 0) {
        o->f2C = o->f24->f24 * func_L39_005B4410(D_L39_0024A8B0, D_L39_0024A8B4);
    }
}
/* localdecomp:end func_L39_0051EB38 */

/* localdecomp:start func_L39_0051ED58 */
/* log: first draft 124 diff; matches only with --mode S --as ps2as (inline lui/ori/mtc1 float constants): 4 other levers found by hand:
 * g = D_L39_00296818 set before the loop (hoisted base), ternary for the colour, for (i = 0; i < 5; i++) (reversed by gcc), and func_L01_004713C8 declared as in L32_0034A2D0.c (f32 at position 3, f32 f32 s32 at 8..10) which orders the argument moves like retail. */
__asm__(".extern D_L39_002412DC, 16");
extern u8 D_L39_00296818[];
extern u8 *func_L01_004713C8(void *, void *, s32, f32, s32, s32, s32, s32, f32, f32, s32);

void func_L39_0051ED58(u8 *a0, void *a1) {
    f32 v[4];
    f32 speed, yaw, size;
    u32 c;
    u8 *r;
    s32 i;
    u8 *g = D_L39_00296818;

    for (i = 0; i < 5; i++) {
        speed = func_L39_005B4410(7.5f, 15.0f) * 0.020000001f;
        yaw = func_L39_005B44C8();
        func_00382760((V4_0051EB38 *)v, speed, yaw, func_L39_005B4410(0.43633232f, 1.3962634f));
        func_0038D000(v, v, a0 + 0xC0);
        size = func_L39_005B4410(0.06f, 0.22f);
        c = func_L39_005B4398(3) != 0 ? 0x605129 : 0x5A523E;
        switch (D_L39_002412DC) {
        case 0x20:
            c = func_L39_005B4398(3) != 0 ? 0x364E4E : 0x688383;
            break;
        case 0x29:
            c = func_L39_005B4398(3) != 0 ? 0x605129 : 0x5A523E;
            break;
        case 0x2A:
            c = func_L39_005B4398(3) != 0 ? 0x263438 : 0x273538;
            break;
        }
        r = func_L01_004713C8(a1, v, (func_L39_005B43C8(0x5A, 0x96) * 5 + 2) / 6, size * 210000.0f, c, -2, 0x7F, 0x7F, size * 210000.0f, 0.0062400005f, 0);
        if (r != 0) {
            r[2] = (*(u8 **)(g + 0x184))[func_L39_005B4398(3) + 0xA];
            r[3] = 0x44;
        }
    }
}
/* localdecomp:end func_L39_0051ED58 */

INCLUDE_ASM("asm/levels", func_L39_0051EF98);
