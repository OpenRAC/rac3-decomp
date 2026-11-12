#include "common.h"

/* localdecomp:start func_L39_0053EA08 */
extern int D_L39_0024AE38 __attribute__((section(".sdata")));
extern int D_L39_0024AE3C __attribute__((section(".sdata")));
extern int D_L39_0024AE40 __attribute__((section(".sdata")));
extern int D_L39_0024AE44 __attribute__((section(".sdata")));
extern s32 func_L39_005B43C8(s32, s32);
extern f32 func_L39_005B44C8(void);
extern void func_L39_0053EB68(u8 *, int, f32, int, int, f32, f32, int, u8 *);

/* from rac2-decomp's func_L16_003E70E0 */
void func_L39_0053EA08(u8 *a0) {
    func_L39_0053EB68(a0 + 0x10, D_L39_0024AE40, *(f32 *)(a0 + 0x2C),
                      func_L39_005B43C8(0x5F, 0x6F), D_L39_0024AE38, func_L39_005B44C8(),
                      1.0f, 2, a0);
    {
        f32 half = *(f32 *)(a0 + 0x2C) * 0.5f;
        func_L39_0053EB68(a0 + 0x10, D_L39_0024AE44, half,
                          func_L39_005B43C8(0x6F, 0x7F), D_L39_0024AE3C,
                          func_L39_005B44C8(), 1.0f, 2, a0);
    }
}
/* localdecomp:end func_L39_0053EA08 */
