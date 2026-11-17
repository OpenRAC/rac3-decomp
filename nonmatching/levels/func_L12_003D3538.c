/* func_L12_003D3538: 16 diff with the file's flags (-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as). Still differs: the schedule of the stack-argument stores (0x40..0x60) and the 0x1010000 constant load against the div.s, retail places them after the div.s and before the float moves; the arithmetic, the u128 copy, the 18 stack ints and the calls match. Tried: the division before the struct copy (47 diff), the division inline as an argument (16). */
#include "common.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4;

extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_00452310(void *, s32, void *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32);
extern void func_L01_004443E8(u8 *, s32, s32);
extern u8 D_L12_001D6700[8];

void func_L12_003D3538(u8 *a0, u8 *a1, s32 a2) {
    V4 tmp;
    f32 q;

    if (a2 != 0) {
        tmp = *(V4 *)(a0 + 0x10);
        tmp.z = tmp.z + *(f32 *)(a1 + 0x40);
        q = *(f32 *)(a0 + 0x2C) / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24);
        func_L01_003303B8(&tmp, 1, 0x19, 0x14, 0x14, 0x14, 0x2D, 2, q, 0.0f, 0.0f, 2.0f,
            1, 1, 1, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
            0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
        func_003A52A0(1, 0, a0);
        func_L01_00452310(a0, 0x1F, D_L12_001D6700, 1, 0x23, 0xFF, 0xB4, 0,
            -1.0f, 3.0f, 6.0f, 3.0f, 6.0f, -1.0f, -1.0f);
    }
    func_L01_004443E8(a0, 0, 3);
}
