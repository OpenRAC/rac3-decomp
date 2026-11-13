#include "common.h"

/* localdecomp:start func_L39_006455B0 */
typedef struct {
    u8 pad0[0xA0];
    f32 x;
    f32 y;
    f32 floor;
    u8 padAC[0x140 - 0xAC];
    f32 vx;
    f32 vy;
    u8 pad148[0x2C0 - 0x148];
    f32 z;
    u8 pad2C4[0x358 - 0x2C4];
    s32 counter;
} Emit_006455B0;

extern f32 func_L39_005B2510(f32, f32);
extern f32 func_L39_005B25C8_006455B0(void);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern s32 func_L39_005B24C8(s32, s32);
extern s32 func_L39_005B2498(s32);
extern void func_L01_00465410(f32 *, f32 *, s32, s32);

void func_L39_006455B0(Emit_006455B0 *state, int period, int threshold)
{
    f32 position[4];
    f32 velocity[4];
    f32 angle;
    f32 radius;
    int lifetime;
    state->counter++;
    if (threshold < state->counter) {
        position[0] = state->x + func_L39_005B2510(-0.15f, 0.15f) + state->vx * 8.0f;
        position[1] = state->y + func_L39_005B2510(-0.15f, 0.15f) + state->vy * 8.0f;
        position[2] = state->z + 0.1f;
        angle = func_L39_005B25C8_006455B0();
        radius = func_L39_005B2510(0.0f, 0.0500000045f);
        velocity[0] = func_00388960(angle) * radius + state->vx * 0.75f;
        velocity[1] = func_00388978(angle) * radius + state->vy * 0.75f;
        velocity[2] = func_L39_005B2510(0.0500000045f, 0.108333342f);
        lifetime = func_L39_005B24C8(90, 120);
        if (state->z - state->floor < 0.25f)
            func_L01_00465410(position, velocity, 3, lifetime);
        else
            func_L01_00465410(position, velocity, 1, lifetime);
        state->counter = func_L39_005B2498(period);
    }
}
/* localdecomp:end func_L39_006455B0 */
