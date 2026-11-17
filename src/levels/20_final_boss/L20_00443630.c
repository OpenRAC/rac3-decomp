#include "common.h"

/* localdecomp:start func_L20_00443630 */
typedef int u128_t_00443630 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00443630;
extern void func_003D9508(void *, s32, u32, s32, f32, f32, f32);

void func_L20_00443630(void) {
    V4_00443630 v;

    *(u128_t_00443630 *)&v = 0;
    v.x = 271.0f;
    v.y = 649.0f;
    v.z = 334.0f;
    func_003D9508(&v, 0xB, 0x20404080, 1, 35.0f, 0.08f, 0.0f);
}
/* localdecomp:end func_L20_00443630 */
