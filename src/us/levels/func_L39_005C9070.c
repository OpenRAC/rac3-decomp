#include "common.h"

/* NTSC-U counterpart of func_L39_005CB428 (src/levels/shared/L39_005CB428.c) */
/* localdecomp:start func_L39_005C9070 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u32 w4;
    u8 b8;
    u8 b9;
    s16 hA;
    f32 fC;
    u128_t v10;
    u128_t v20;
    f32 f30;
    s16 h34;
    s16 h36;
    u8 b38;
    u8 b39;
    u8 pad3A[2];
    s32 w3C;
} Eff005CB428;

extern u8 *D_L39_00296948[];
extern void *func_003C7B98(s32);
extern s32 func_0019D650(void);
extern u32 func_L01_00445B88(f32, f32, f32, f32);
extern f32 func_L39_005B25C8_005C9070(void);
extern f32 func_L39_005B2510(f32, f32);

Eff005CB428 *func_L39_005C9070(u128_t *pos, u128_t *vec, u8 a, s32 w, u8 b, s32 c) {
    Eff005CB428 *e = func_003C7B98(0x28);
    u8 *s;
    f32 r;
    if (e != 0) {
        e->v10 = *pos;
        s = (u8 *)&e->v20;
        e->v20 = *vec;
        e->w4 = func_L01_00445B88(0.7f, 0.7f, 0.7f, 0.08f);
        e->b1 = 0;
        e->b9 = ((c >> 5) << 4) + 4;
        e->b3 = 0x44;
        r = func_L39_005B25C8_005C9070();
        *(f32 *)(s + 0x10) = r;
        e->b8 = r * 256.0f;
        e->b2 = D_L39_00296948[0][func_0019D650() & 7];
        s[0x19] = b;
        s[0x18] = a;
        *(s16 *)(s + 0x14) = 0;
        *(s16 *)(s + 0x16) = 0;
        if (a < 5) {
            f32 t = s[0x19] * 0.03125f;
            e->fC = func_L39_005B2510(t * 21000.0f, t * 30000.0f);
            e->hA = 18 - func_0019D650() % 15;
        } else {
            e->fC = s[0x19] * 0.03125f * 30000.0f;
            e->hA = 18;
        }
        *(s32 *)(s + 0x1C) = w;
    }
    return e;
}
/* localdecomp:end func_L39_005C9070 */
