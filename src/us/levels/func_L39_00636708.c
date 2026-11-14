#include "common.h"

/* NTSC-U counterpart of func_L39_00638F50 (src/levels/shared/L39_00638DF0.c) */
/* localdecomp:start func_L39_00636708 */
typedef int u128_t __attribute__((mode(TI)));
typedef union V4_00638F50 {
    u128_t q;
    f32 f[4];
} V4_00638F50;

extern f32 func_00388A28(f32, f32);
extern f32 func_00389468(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_003CE740(void *, void *, s32, void *, void *);
extern V4_00638F50 D_L39_0025F860;

s32 func_L39_00636708(u8 *g) {
    V4_00638F50 a;
    V4_00638F50 b;
    f32 d;

    if (g[0x1A06] == 2) {
        return 0;
    }
    if (*(f32 *)(g + 0x1A4) < *(f32 *)(g + 0x1F4) / 20.0f) {
        return 0;
    }
    if (func_00389468(func_00388A28(*(f32 *)(g + 0x140), *(f32 *)(g + 0x144)), *(f32 *)(g + 0xB8)) > 0.5235988f) {
        return 0;
    }
    a.q = *(u128_t *)(g + 0xA0);
    a.f[0] += func_00388960(*(f32 *)(g + 0xB8)) * (*(f32 *)(g + 0x1F4) * 0.75f);
    a.f[1] += func_00388978(*(f32 *)(g + 0xB8)) * (*(f32 *)(g + 0x1F4) * 0.75f);
    b.q = a.q;
    a.f[2] += 0.47f;
    b.f[2] -= 1.0f;
    if (func_003CE740(&a, &b, 2, *(void **)(g + 0x2524), 0) == 0) {
        return 0;
    }
    d = D_L39_0025F860.f[2] - *(f32 *)(g + 0xA8);
    if (d < 0.37f && -1.0f < d) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_00636708 */
