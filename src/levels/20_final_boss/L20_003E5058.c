#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L20_003E5058 */
#include "vu0.h"
extern void func_L01_00443B88(void *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern u8 *func_L01_0046B458(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);

void func_L20_003E5058(void *a0) {
    u8 *p = *(u8 **)((u8 *)a0 + 0x68);
    vu0_v4 col;
    vu0_v4 pos;
    f32 s;
    s32 i;

    for (i = 0; i < 2; i++) {
        func_L01_00443B88(&col, 0.120000005f, 0.20000002f);
        s = func_003824E0(1.0f, 2.0f);
        func_0038CF68(&pos, p, *(f32 *)(p + 0x30));
        vec_add_ba(&pos, p + 0x10, &pos);
        func_L01_0046B458(&pos, 8, s, s, 0x7F070760, 0, func_00382498(-3, 3), &col, 0.0f, 0);
    }
}
/* localdecomp:end func_L20_003E5058 */
