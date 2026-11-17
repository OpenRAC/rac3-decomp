#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L19_003B86E8 */
#include "vu0.h"
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_0040A8C0(void *, void *, s32, s32, u32, u32, u32, u32, f32, f32, f32);
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);
void func_L19_003B86E8(u8 *m) {
    u128_t v[2];
    v[0] = *(u128_t *)(m + 0x10);
    func_0038CF68(&v[1], *(u8 **)(m + 0x68) + 0x10, 1.0f);
    vec_sub_ab(&v[1], &v[0], &v[1]);
    func_L01_0040A8C0(&v[0], &v[1], 0xE, 1, 0x80007080, 0x80007080, 0x4080, 0x4080, 0.1f, 1.0f, 0.0f);
    func_003D9508(&v[0], 6, 0xFF008080, 1, 0.2f, 0.0f, 0.0f);
}
/* localdecomp:end func_L19_003B86E8 */
