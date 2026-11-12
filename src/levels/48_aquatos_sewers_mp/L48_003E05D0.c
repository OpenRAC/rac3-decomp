#include "common.h"

/* localdecomp:start func_L48_003E05D0 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3E05D0;
typedef struct { f32 x, y; } F2_3E05D0;
typedef struct { u8 p0[0x14]; s32 f14; f32 f18; u8 p1C[0x30]; s32 f4C; u8 p50[0x10]; V4_3E05D0 v60; } S_3E05D0;
typedef struct { u8 p0[0x30]; u8 b30; } O_3E05D0;
extern s32 D_L48_002412DC;
extern s32 *D_L48_00241120;
extern F2_3E05D0 D_L48_00249310[1];
extern V4_3E05D0 D_L48_00249B40;
extern void func_00476BF8(void *, s32, s32);
extern f32 func_004761C8(f32, f32);
extern void func_L48_003E03E0(void *, void *);

void func_L48_003E05D0(O_3E05D0 *o, S_3E05D0 *s) {
    s32 i;
    func_00476BF8(o, 1, -1);
    o->b30 = 0xFF;
    s->f14 = s->f14 << 1;
    if (D_L48_002412DC == 0x30) {
        if (D_L48_00241120[0] >= 3) s->f14 = 1;
    }
    if (s->f14 > 4) s->f14 = 4;
    else if (s->f14 < 0) s->f14 = 0;
    if (32.0f < s->f18) s->f18 = 32.0f;
    for (i = 0; i < s->f14; i++) {
        D_L48_00249310[i].x = func_004761C8(0.0f, 1.0f);
        D_L48_00249310[i].y = func_004761C8(0.0f, 1.0f);
    }
    s->f4C = 0;
    func_L48_003E03E0(o, s);
    s->v60 = D_L48_00249B40;
}
/* localdecomp:end func_L48_003E05D0 */
