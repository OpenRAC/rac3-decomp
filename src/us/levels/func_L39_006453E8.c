#include "common.h"

/* localdecomp:start func_L39_006453E8 */
typedef struct {
    u8 pad0[0xA0];
    f32 x;
    f32 y;
    u8 padA8[0xB8 - 0xA8];
    f32 angle;
    u8 padBC[0x2C0 - 0xBC];
    f32 z;
    u8 pad2C4[0x354 - 0x2C4];
    s32 counter;
} S_006453E8;

extern f32 func_00389380(f32, f32);
extern f32 func_003893C8(f32, f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_L39_005B2510(f32, f32);
extern s32 func_L39_005B2498(s32);
extern void func_L01_00467510(f32 *, f32 *, f32 *, f32, f32);

void func_L39_006453E8(S_006453E8 *self, int arg1, int arg2)
{
    f32 v[4] __attribute__((aligned(16)));
    f32 w[4] __attribute__((aligned(16)));
    f32 f;
    f32 r;
    f32 g;
    int n;
    int i;

    n = self->counter + 1;
    self->counter = n;
    if (arg2 < n) {
        for (i = 0; i < 2; i++) {
            if (i == 0)
                f = func_00389380(self->angle, 0.785398006f);
            else
                f = func_003893C8(self->angle, 0.785398006f);
            v[0] = func_00388960(f) * 0.0100000007f;
            v[1] = func_00388978(f) * 0.0100000007f;
            w[0] = self->x + v[0] * 18.0f;
            w[1] = self->y + v[1] * 18.0f;
            w[2] = self->z;
            v[2] = 0.0f;
            v[0] = v[0] - func_00388960(self->angle) * 0.0250000022f;
            v[1] = v[1] - func_00388978(self->angle) * 0.0250000022f;
            r = func_L39_005B2510(0.4f, 0.5f);
            g = i == 0 ? 2.0f : -2.0f;
            func_L01_00467510(w, v, &self->z, r, g);
            if (arg1 != 0)
                self->counter = func_L39_005B2498(arg1);
            else
                self->counter = 0;
        }
    }
}
/* localdecomp:end func_L39_006453E8 */
