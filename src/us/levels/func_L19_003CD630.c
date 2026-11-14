#include "common.h"

/* NTSC-U counterpart of func_L19_003CF7B8 (src/levels/19_thran_asteroid_belt/L19_003CDD90.c) */
#include "vu0.h"
extern f32 func_0037E250(f32, f32);

/* localdecomp:start func_L19_003CD630 */
typedef int u128_t __attribute__((mode(TI)));
extern s32 func_003894E8(void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern u8 D_L19_001D66F0_003CD630[8];
extern u8 *func_L01_00467DA8(u8 *position, s32 life, f32 size, f32 start_size, s32 colour, s32 roll_kind,
                             s32 spin, void *velocity, f32 unk, s32 delay);

void func_L19_003CD630(void *pos, s32 n, f32 x, f32 y, s32 b, s32 m, s32 c) {
    u128_t q[2];
    f32 t;
    f32 z;
    s32 k;
    s32 r;
    q[0] = *(u128_t *)pos;
    q[1] = *(u128_t *)pos;
    ((f32 *)&q[1])[3] = 0.1f;
    if (func_003894E8(&q[1], 32.0f) > 0) {
        t = func_0037E250(x, y);
        k = func_0037E1D8(2);
        z = 0.0f;
        if (k == 0)
            k--;
        func_L01_00467DA8((u8 *)&q[0], n, t * 0.3f, t, b, 0, k, D_L19_001D66F0_003CD630, z, 0);
        if (m != 0 && c != 0) {
            func_L01_00467DA8((u8 *)&q[0], m, t * 0.04f, t * 0.4f, c, 1, -k, D_L19_001D66F0_003CD630, z, 0);
        }
    }
}
/* localdecomp:end func_L19_003CD630 */
