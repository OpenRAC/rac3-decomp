#include "common.h"

/* NTSC-U counterpart of func_L39_0066AA50 (src/levels/shared/L39_0066A690.c): 0.02 -> 0.0166667 */
typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;
#include "vu0.h"
extern s32 D_001A5F78[];
extern f32 func_L39_005B2510(f32, f32);

/* localdecomp:start func_L39_00668148 */
typedef struct Slf_0066AA50 { u8 pad0[0x2E8]; s32 w2E8; } Slf_0066AA50;
typedef struct Obj_0066AA50 { u8 pad0[0xBC]; u8 bBC; } Obj_0066AA50;
extern s32 D_001A5F78[];
extern f32 D_001DAB08_sda_00668148;
extern f32 D_001DAB00_sda_00668148;
extern f32 D_001DAB04_sda_00668148;
__asm__(".extern D_001DAB08_sda_00668148, 4");
__asm__(".extern D_001DAB00_sda_00668148, 4");
__asm__(".extern D_001DAB04_sda_00668148, 4");
extern s32 func_L39_005B2498(s32);
extern f32 func_L39_005B2510(f32, f32);
extern void func_003BDA38(void *, s32, void *);
extern void func_L01_003D72E0(void *, void *, f32, f32, f32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                              s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L39_00668148(Slf_0066AA50 *self, Obj_0066AA50 *obj, s32 arg2, s32 *arg3) {
    s32 i;
    s32 idx;
    f32 v90[4];
    Vec4 a;
    Vec4 b;
    f32 d;

    if (obj->bBC != 9) {
        return;
    }
    if (self->w2E8 - 100 < D_001A5F78[0]) {
        return;
    }
    idx = func_L39_005B2498(15) ? -1 : func_L39_005B2498(arg2);
    b.q = 0;
    b.f[2] = D_001DAB08_sda_00668148 * 0.0166666675f;
    a.q = b.q;
    for (i = 0; i < 3; i++) {
        d = func_L39_005B2510(D_001DAB00_sda_00668148, D_001DAB00_sda_00668148 + 0.3f);
        func_003BDA38(obj, arg3[i], v90);
        func_L01_003D72E0(v90, &a, -100000.0f, d, D_001DAB04_sda_00668148, 10, 2, 0, 2, 0x40, 0);
        func_L01_003D72E0(v90, &a, -100000.0f, d, D_001DAB04_sda_00668148, 20, 2, 0, 2, 0x40, 0);
        if (idx == i) {
            func_L01_0032FE90(v90, 0, 5, 0, 5, 10, 0, 0, 0.5f, 0.0f, 0.0f, 2.0f,
                              0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        }
    }
}
/* localdecomp:end func_L39_00668148 */
