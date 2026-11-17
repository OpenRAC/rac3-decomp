#include "common.h"

INCLUDE_ASM("asm/levels", func_L17_003B8400);

/* localdecomp:start func_L17_003B8658 */
#include "vu0.h"
extern s32 D_L17_001DE560;
__asm__(".extern D_L17_001DE560, 4");
extern s32 D_L17_001DE564;
__asm__(".extern D_L17_001DE564, 4");
extern f32 D_L17_001DE568;
__asm__(".extern D_L17_001DE568, 4");
extern s32 D_L17_001DE56C;
__asm__(".extern D_L17_001DE56C, 4");
extern s32 D_L17_001DE570;
__asm__(".extern D_L17_001DE570, 4");
extern s32 D_L17_001DE580;
__asm__(".extern D_L17_001DE580, 4");
extern u8 D_L17_002A3270[];
extern void func_0038CF68(void *, void *, f32);

void func_L17_003B8658(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    vu0_v4 d;
    vu0_v4 step;
    s32 i;
    u32 a;

    if (D_L17_001DE564 != 0) {
        D_L17_001DE564 = 0;
        vec_sub_ab(&d, s + 0x10, s);
        func_0038CF68(&step, &d, D_L17_001DE568 / (f32)D_L17_001DE560);
        a = *(s32 *)(s + 0x38) * 640;
        a += (u32)D_L17_002A3270;
        *(vu0_q *)a = *(vu0_q *)s;
        for (i = 1; i < D_L17_001DE560; i++) {
            vec_add_ba(&((vu0_v4 *)(D_L17_002A3270 + *(s32 *)(s + 0x38) * 640))[i],
                       &((vu0_v4 *)(D_L17_002A3270 + *(s32 *)(s + 0x38) * 640))[i - 1], &step);
        }
        D_L17_001DE56C = 0;
        D_L17_001DE570 = 0;
        D_L17_001DE580 = 0;
    }
}
/* localdecomp:end func_L17_003B8658 */

INCLUDE_ASM("asm/levels", func_L17_003B8748);
