#include "common.h"

/* NTSC-U counterpart of func_L01_003AB5D0 (src/levels/shared/L01_003A4970.c): timestep 1/60 for 0.02, the $gp data 0x40 later */
/* localdecomp:start func_L01_003A9E48 */
extern f32 D_L01_001DE480 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DE480, 4");
extern f32 D_L01_001DE3EC __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DE3EC, 4");
extern f32 D_L01_001DE3E8 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DE3E8, 4");
extern f32 D_L01_001DE3F8 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DE3F8, 4");
extern f32 D_L01_001DE3FC __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DE3FC, 4");
extern f32 D_L01_001DE400 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DE400, 4");
extern f32 D_L01_001DE3F0 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DE3F0, 4");
extern f32 D_L01_001DE3F4 __attribute__((section(".sdata")));
__asm__(".extern D_L01_001DE3F4, 4");
extern f32 func_00389380(f32, f32);
extern f32 func_00388978(f32);
extern f32 func_00388960(f32);
typedef struct { u8 pad0[0xC44]; f32 strength; u8 padC48[0xD00-0xC48]; f32 a, b, c; } State_003A9E48;
void func_L01_003A9E48(u8 *object, State_003A9E48 *state, f32 *x, f32 *y, f32 *z) {
    f32 radians;
    f32 timestep;
    if (object[0x20] == 2) {
        *x = 0;
        *y = 0;
        *z = 0;
    } else if (state->strength < 1.0f) {
        state->strength += D_L01_001DE480;
        if (state->strength > 1.0f)
            state->strength = 1.0f;
    }
    radians = 0.01745329238474369f;
    timestep = 0.01666666753590107f;
    state->a = func_00389380(state->a, D_L01_001DE3EC * radians * timestep);
    *x = func_00388978(state->a) * D_L01_001DE3E8 * state->strength;
    { f32 sb = func_00388978(state->b);
      f32 sc = func_00388978(state->c);
      *y = D_L01_001DE3F8 * sb * sc * 1.5f * state->strength; }
    { f32 sb = func_00388978(state->b);
      f32 cc = func_00388960(state->c);
      *z = D_L01_001DE3F8 * sb * cc * state->strength; }
    state->b = func_00389380(state->b, D_L01_001DE3FC * radians * timestep);
    state->c = func_00389380(state->c, D_L01_001DE400 * radians * timestep);
    *z += func_00388978(state->a + D_L01_001DE3F0) * D_L01_001DE3F4 * state->strength;
}
/* localdecomp:end func_L01_003A9E48 */
