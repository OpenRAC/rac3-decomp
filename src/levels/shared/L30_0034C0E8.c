#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L30_0034C0E8 */
#include "vu0.h"

extern f32 D_L30_001DD478;
__asm__(".extern D_L30_001DD478, 4");
extern f32 D_L30_001DD47C;
__asm__(".extern D_L30_001DD47C, 4");
extern f32 D_L30_001DD480;
__asm__(".extern D_L30_001DD480, 4");
extern s32 D_L30_001DD484;
__asm__(".extern D_L30_001DD484, 4");
extern f32 D_L30_001DD488;
__asm__(".extern D_L30_001DD488, 4");
extern f32 D_L30_001DD48C;
__asm__(".extern D_L30_001DD48C, 4");
extern f32 D_L30_001DD490;
__asm__(".extern D_L30_001DD490, 4");
extern f32 D_L30_001DD494;
__asm__(".extern D_L30_001DD494, 4");
extern s32 D_L30_001DD498;
__asm__(".extern D_L30_001DD498, 4");
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern s32 func_00382468(s32);
extern s32 func_0038DBD8(f32, s32, s32);
extern void func_L01_004713C8(void *, void *, s32, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_0046B458(void *, s32, u32, s32, s32, void *, f32, f32, f32, s32);

void func_L30_0034C0E8(char *a0) {
    char *s0 = *(char **)(a0 + 0x68);
    vu0_v4 pos;
    vu0_v4 vel;
    f32 f;
    f32 g;
    s32 c;
    s32 n;

    *(f32 *)(s0 + 0x2C) += D_L30_001DD494;
    if (*(f32 *)(s0 + 0x2C) > 1.0f) {
        do {
            f32 r = D_L30_001DD488;
            *(f32 *)(s0 + 0x2C) -= 1.0f;
            qzero(&pos);
            pos.x = func_003824E0(-r, r);
            pos.z = func_003824E0(-D_L30_001DD488, D_L30_001DD488);
            vec_add_ba(&pos, &pos, a0 + 0x10);
            qzero(&vel);
            c = func_0038DBD8(func_003824E0(0.0f, 1.0f), *(s32 *)(s0 + 0x20), *(s32 *)(s0 + 0x24));
            f = func_003824E0(D_L30_001DD48C, D_L30_001DD490);
            func_L01_004713C8(&pos, &vel, D_L30_001DD484, c, func_00382498(-4, 4), 0x80, 0, f, 0.0f, D_L30_001DD480, D_L30_001DD498);
        } while (*(f32 *)(s0 + 0x2C) > 1.0f);
    }
    if (func_00382468(2) == 0) {
        g = func_003824E0(D_L30_001DD478, D_L30_001DD47C);
        n = func_00382468(2);
        if (n == 0) {
            n--;
        }
        func_L01_0046B458(a0 + 0x10, 4, 0x7F7F2020, 0, n, s0, g * 0.1f, g, 0.0f, 0);
        func_L01_0046B458(a0 + 0x10, 4, 0x7F7F7F7F, 1, -n, s0, g * 0.07f, g * 0.7f, 0.0f, 0);
    }
}
/* localdecomp:end func_L30_0034C0E8 */
