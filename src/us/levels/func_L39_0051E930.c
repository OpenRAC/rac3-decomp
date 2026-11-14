#include "common.h"

/* NTSC-U counterpart of func_L39_0051ED58 (src/levels/shared/L39_0051EB38.c) */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_0051EB38;
extern s32 D_L39_0024145C;
extern f32 func_L39_005B2510(f32, f32);
extern f32 func_L39_005B25C8_0051E930(void);
extern s32 func_L39_005B2498(s32);
extern s32 func_L39_005B24C8(s32, s32);
extern void func_0037E4B8(V4_0051EB38 *, f32, f32, f32);
extern void func_003888C8(void *, void *, void *);

/* localdecomp:start func_L39_0051E930 */
/* log: first draft 124 diff; matches only with --mode S --as ps2as (inline lui/ori/mtc1 float constants): 4 other levers found by hand:
 * g = D_L39_00296918 set before the loop (hoisted base), ternary for the colour, for (i = 0; i < 5; i++) (reversed by gcc), and func_L01_0046DCB8 declared as in L32_0034A2D0.c (f32 at position 3, f32 f32 s32 at 8..10) which orders the argument moves like retail. */
__asm__(".extern D_L39_0024145C, 16");
extern u8 D_L39_00296918[];
extern u8 *func_L01_0046DCB8(void *, void *, s32, f32, s32, s32, s32, s32, f32, f32, s32);

void func_L39_0051E930(u8 *a0, void *a1) {
    f32 v[4];
    f32 speed, yaw, size;
    u32 c;
    u8 *r;
    s32 i;
    u8 *g = D_L39_00296918;

    for (i = 0; i < 5; i++) {
        speed = func_L39_005B2510(7.5f, 15.0f) * 0.0166666675f;
        yaw = func_L39_005B25C8_0051E930();
        func_0037E4B8((V4_0051EB38 *)v, speed, yaw, func_L39_005B2510(0.43633232f, 1.3962634f));
        func_003888C8(v, v, a0 + 0xC0);
        size = func_L39_005B2510(0.06f, 0.22f);
        c = func_L39_005B2498(3) != 0 ? 0x605129 : 0x5A523E;
        switch (D_L39_0024145C) {
        case 0x20:
            c = func_L39_005B2498(3) != 0 ? 0x364E4E : 0x688383;
            break;
        case 0x29:
            c = func_L39_005B2498(3) != 0 ? 0x605129 : 0x5A523E;
            break;
        case 0x2A:
            c = func_L39_005B2498(3) != 0 ? 0x263438 : 0x273538;
            break;
        }
        r = func_L01_0046DCB8(a1, v, func_L39_005B24C8(0x5A, 0x96), size * 210000.0f, c, -2, 0x7F, 0x7F, size * 210000.0f, 0.00433333357796073f, 0);
        if (r != 0) {
            r[2] = (*(u8 **)(g + 0x184))[func_L39_005B2498(3) + 0xA];
            r[3] = 0x44;
        }
    }
}
/* localdecomp:end func_L39_0051E930 */
