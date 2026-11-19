/* functional: high. 42 instructions differ (stack layout and scheduling); same reads, writes and calls. */
#include "vu0.h"
extern f32 D_L01_001DECC8_003C7C80;
extern f32 D_L01_001DECCC_003C7C80;
extern f32 D_L01_001DECD0_003C7C80;
__asm__(".extern D_L01_001DECC8_003C7C80, 4");
__asm__(".extern D_L01_001DECCC_003C7C80, 4");
__asm__(".extern D_L01_001DECD0_003C7C80, 4");
extern f32 func_0038CEA8(void *);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CF68(void *, void *, f32);

void func_L01_003C7C80(u8 *obj, void *unused, vu0_q *from, f32 *out_a, f32 *out_b) {
    vu0_v4 diff;
    vu0_q src = *from;
    vec_sub_ab(&diff, obj + 0x10, &src);
    if (D_L01_001DECC8_003C7C80 < func_0038CEA8(&diff)) {
        func_0038CF68(&diff, &diff, D_L01_001DECC8_003C7C80);
    }
    *out_a = func_0038CE68(&diff, obj + 0xD0) * D_L01_001DECCC_003C7C80;
    *out_b = func_0038CE68(&diff, obj + 0xC0) * D_L01_001DECD0_003C7C80;
}
