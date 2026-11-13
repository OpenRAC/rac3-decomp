#include "common.h"

/* declared by functions of L39_00537998.c, which this file was cut from */
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_L39_0025F760[];
extern s32 func_003D3CB0(f32 *, u8 *, s32, u8 *, s32);
extern void func_0038CE20(f32 *, void *, f32);

/* localdecomp:start func_L39_0053C110 */
#include "vu0.h"

__asm__(".extern D_L39_0024ADA8, 4");
extern s32 D_L39_0024ADA8;

s32 func_L39_0053C110(u8 *a0, u128_t *a1, u128_t *a2) {
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;

    c = *(vu0_v4 *)(*(u8 **)(a0 + 0x68) + 0x20);
    func_0038CE20((f32 *)&a, &c, -30.0f);
    vec_add_ba(&a, &a, a2);
    func_0038CE20((f32 *)&b, &c, 0.5f);
    vec_add_ab(&b, &b, a2);
    if (func_003D3CB0((f32 *)&b, (u8 *)&a, D_L39_0024ADA8 | 2, 0, 0)) {
        *a1 = *(u128_t *)D_L39_0025F760;
        return 1;
    }
    *a1 = *a2;
    return 0;
}
/* localdecomp:end func_L39_0053C110 */
