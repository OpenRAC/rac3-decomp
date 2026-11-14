#include "common.h"

/* localdecomp:start func_L07_003BC088 */
typedef int u128_t __attribute__((mode(TI)));
extern void func_L01_00442E08(u8 *moby, s32 class_id);
extern s32 func_L07_003C01A8(void);
extern f32 func_L07_003C01F0(s32);
extern void func_L01_00442F20(void *, s32, s32);
extern void func_L01_00458A70(void *, f32, f32, f32, f32);
extern void func_L07_003BCA20(void *);

void func_L07_003BC088(u8 *a0) {
    u8 *p;
    u8 *r;
    u8 *q;
    s32 k;
    f32 s;

    p = *(u8 **)(a0 + 0x68);
    func_L01_00442E08(a0, 0x19BE);
    r = p + 0x30;
    k = func_L07_003C01A8();
    s = func_L07_003C01F0(k);
    *(s16 *)(r + 4) = (f32)*(s16 *)(p + 0x34) * s;
    *(f32 *)(p + 0x30) = (f32)*(s16 *)(r + 4);
    r[0x14] = (f32)p[0x44] * s;
    r[0x15] = (f32)p[0x45] * s;
    r[0x16] = (f32)p[0x46] * s;
    if (k == 1 || k == 3) {
        func_L01_00442F20(a0, 0x1D89, 0x19BE);
    }
    r[0x28] = 0x14; r[0x2A] = 0xE; *(f32 *)(r + 0x10) = 1.0f; r[0xF] = 0; r[9] = 0;
    q = p + 0x70;
    q[0x48] = 0xFF; q[0x10] = 8; *(f32 *)(q + 0x3C) = 0.15f; *(f32 *)(q + 0x58) = 0.35f; *(f32 *)(q + 0x30) = 1.0f; *(f32 *)(q + 0x34) = 0.5f; *(f32 *)(q + 0xB0) = 1.0f; *(f32 *)(q + 0x5C) = 0.5f; *(s32 *)(q + 0xA8) = 0; q[0x77] = 1;
    *(f32 *)(p + 0x150) = 1.0f; *(f32 *)(p + 0x154) = 0.3f; *(f32 *)(p + 0x160) = 1.5707964f; *(f32 *)(p + 0x180) = 0.2443461f; *(f32 *)(p + 0x17C) = 0.0027222224f; *(s32 *)(p + 0x23C) = 0; *(f32 *)(p + 0x158) = 0.5f; *(f32 *)(p + 0x15C) = 0.5f; *(f32 *)(p + 0x184) = 0.5f; *(s16 *)(p + 0x4F6) = 0;
    *(u128_t *)(p + 0x340) = *(u128_t *)(a0 + 0x10);
    *(u128_t *)(p + 0x350) = *(u128_t *)(a0 + 0xF0);
    func_L01_00458A70(a0, 0.0013888889f, 0.083333336f, 0.0034906587f, 0.104719765f);
    func_L07_003BCA20(a0);
}
/* localdecomp:end func_L07_003BC088 */
