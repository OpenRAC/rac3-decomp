#include "common.h"

LINKER_REMNANT("asm/levels", func_L01_004395D0);

/* localdecomp:start func_L01_004395E0 */
typedef struct {
    u8 pad0[4];
    s16 h4;
} S_436500b;

typedef struct {
    u8 pad0[0x40];
    u8 b40;
    u8 b41;
    u8 b42;
    u8 b43;
    f32 f44;
    u8 pad48[0x58 - 0x48];
    S_436500b *p58;
    S_436500b *p5C;
} S_436500;

f32 func_L01_004395E0(S_436500 *s) {
    S_436500b *a;
    f32 t;

    if (s->b42 != 255) {
        a = s->p58;
    } else {
        a = s->p5C;
    }
    t = s->f44;
    if (t == 0.0f) {
        return a->h4 * 0.0625f;
    }
    if (s->b42 != s->b43 || s->b40 > s->b41) {
        return a->h4 * 0.0625f + t;
    }
    return (a->h4 * (1.0f - t) + s->p5C->h4 * t) * 0.0625f;
}
/* localdecomp:end func_L01_004395E0 */

/* localdecomp:start func_L01_004396C0 */
f32 func_L01_004396C0(u8 *a0) {
    f32 t = *(f32 *)(a0 + 36);
    u8 *a = *(u8 **)(a0 + 56);
    u8 *b;
    if (t == 0.0f) {
        return *(s16 *)(a + 4) * 0.0625f;
    }
    if (a0[34] != a0[35] || a0[32] > a0[33]) {
        return *(s16 *)(a + 4) * 0.0625f + t;
    }
    b = *(u8 **)(a0 + 60);
    return (*(s16 *)(a + 4) * (1.0f - t) + *(s16 *)(b + 4) * t) * 0.0625f;
}
/* localdecomp:end func_L01_004396C0 */

LINKER_REMNANT("asm/levels", func_L01_00439788);

INCLUDE_ASM("asm/levels", func_L01_00439790);

INCLUDE_ASM("asm/levels", func_L01_00439880);

INCLUDE_ASM("asm/levels", func_L01_004398C8);

/* localdecomp:start func_L01_00439A68 */
s32 func_L01_00439A68(u8 *a0, u8 *a1) {
    u8 *t = *(u8 **)(a0 + 36);
    s16 n = *(s16 *)(t + 46);
    u8 *p;
    if (n == 0) {
        return 0;
    }
    p = a1 + ((u32)t + (n << 4));
    return p[1] != 0xff;
}
/* localdecomp:end func_L01_00439A68 */

INCLUDE_ASM("asm/levels", func_L01_00439A98);
