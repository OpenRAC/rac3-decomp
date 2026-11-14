#include "common.h"

/* localdecomp:start func_L39_00532550 */
#include "vu0.h"

__asm__(".extern D_L39_0024AD10, 8");
extern u8 D_L39_0024AD10[8];
extern f32 D_L39_0024ACE0;
__asm__(".extern D_L39_0024ACE0, 4");
extern vu0_q D_L39_0025F780;
extern vu0_v4 D_L39_00243F20_00532550 __attribute__((section(".sdata")));

extern void func_0038D000(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern void func_0038CF68(void *, void *, f32);

void func_L39_00532550(u8 *a0) {
    u8 *o = *(u8 **)(a0 + 0x68);
    u8 *p = *(u8 **)(o + 0x160);
    vu0_v4 v0;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_q v30;
    u8 *d = D_L39_0024AD10;
    s32 i;

    qzero(&v20);
    for (i = 3; i >= 0; i--, d += 16) {
        func_0038D000(&v0, d, *(u8 **)(p + 0x2D0) + 0xC0);
        vec_add_ab(&v0, &v0, *(u8 **)(p + 0x2D0) + 0x10);
        func_0038CE20(&v10, *(u8 **)(p + 0x2D0) + 0xE0, -D_L39_0024ACE0);
        vec_add_ab(&v10, &v10, &v0);
        if (func_003D3CB0(&v0, &v10, 4, *(u8 **)(p + 0x2D0), 0) != 0) {
            v30 = D_L39_0025F780;
            func_0038CF68(&v30, &v30, 1.0f);
            vec_add_ab(&v20, &v20, &v30);
        } else {
            vec_add_ab(&v20, &v20, &D_L39_00243F20_00532550);
        }
    }
    func_0038CF68(o + 0x100, &v20, 1.0f);
}
/* localdecomp:end func_L39_00532550 */

INCLUDE_ASM("asm/levels", func_L39_00532698);

INCLUDE_ASM("asm/levels", func_L39_00532BE0);
