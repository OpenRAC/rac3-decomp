#include "common.h"

INCLUDE_ASM("asm/levels", func_L29_003D34E8);

/* localdecomp:start func_L29_003D3930 */
typedef struct { u8 p0[4]; f32 f4; u8 p8[0x20]; s32 f28; u8 p2C[0x34]; f32 f60; f32 f64; } S_3930_S;
typedef struct { u8 p0[0x80]; s32 f80; u8 p84[8]; s32 f8C; u8 p90[0x20]; f32 fB0; u8 pB4[4]; f32 fB8; f32 fBC; } S_3930_D;
typedef struct { u8 p0[0x68]; void *f68; } S_3930_O;
void func_L29_003D3930(S_3930_O *a0, S_3930_O *a1) {
    S_3930_D *d = a0->f68;
    S_3930_S *s = a1->f68;
    d->f80 = 0;
    if (s->f4 != -1.0f) {
        if (s->f4 < 0.0f) {
            d->f80 = 1;
            d->fBC = -s->f4;
        } else {
            d->fBC = s->f4;
        }
    }
    if (s->f64 >= 0.0f) d->fB0 = s->f64; else d->fB0 = 0.01f;
    if (s->f60 >= 0.0f) d->fB8 = s->f60; else d->fB8 = 1.75f;
    d->f8C = s->f28;
}
/* localdecomp:end func_L29_003D3930 */
