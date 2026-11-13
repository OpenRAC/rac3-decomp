#include "common.h"

/* NTSC-U counterpart of func_L24_003A7870 (src/levels/24_insomniac_museum/L24_003A76B8.c): 0.0432 -> 0.03; 0.432 -> 0.3 */
#include "vu0.h"
extern u8 *D_L24_001DF51C_003A5C98;

/* localdecomp:start func_L24_003A5C98 */
extern f32 func_00388A28(f32, f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_003887A0(void *);
extern void func_L01_0044B5C8(void *, void *, s32, f32, f32);

void func_L24_003A5C98(u8 *a0, u8 *a1, s32 a2) {
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    f32 f20;
    f32 f1;
    *(vu0_q *)a = *(vu0_q *)(D_L24_001DF51C_003A5C98 + (*(s32 *)(a1 + 0x988) << 8) + 0x10);
    vec_sub_ab(b, c, a);
    f20 = func_003893C8(func_00388A28(b[0], b[1]), *(f32 *)(a0 + 0xF8));
    f1 = -func_00388A28(func_003887A0(b), b[2]);
    if (f20 > 1.5707964f) {
        f20 = 1.5707964f;
    } else if (f20 < -1.5707964f) {
        f20 = -1.5707964f;
    }
    if (f1 > 0.5235988f) {
        f1 = 0.5235988f;
    } else if (f1 < -0.5235988f) {
        f1 = -0.5235988f;
    }
    qzero(a1 + 0x9F0);
    *(f32 *)(a1 + 0x2A4) = f1;
    *(f32 *)(a1 + 0x2A8) = f20 * 0.5f;
    if (a2 != 0) {
        *(f32 *)(a1 + 0x9F8) = -0.20943952f;
    }
    func_L01_0044B5C8(a0, a1 + 0x990, 3, 0.0299999993f, 0.300000012f);
}
/* localdecomp:end func_L24_003A5C98 */
