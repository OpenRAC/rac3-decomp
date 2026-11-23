#include "common.h"

/* NTSC-U counterpart of func_L01_0046A430 (src/levels/shared/L01_00465878.c) */
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
#include "structs/hero.h"
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"
#include "vu0.h"

/* localdecomp:start func_L01_00466DB8 */
#include "vu0.h"
void func_L01_00466DB8(u8 *self)
{
    extern void func_003C7CE0(u8 *);
    u8 *vars = self + 0x20;
    s32 time, life;
    f32 factor, r, g, b, total;
    u8 blue, green, red, alpha;
    ++*(s16 *)(self + 0xA);
    time = *(s16 *)(self + 0xA);
    life = *(s16 *)(vars + 0x18);
    if (time > life) {
        func_003C7CE0(self);
        return;
    }
    total = life;
    factor = (f32)time / total;
    factor = 1.0f - factor;
    g = vars[0x14] + -0.001f * factor;
    b = vars[0x15] + -0.0011f * factor;
    r = vars[0x16] + -0.00111f * factor;
    red = r;
    green = g;
    blue = b;
    if (time < 30) {
        factor = (f32)time / 30.0f;
        alpha = vars[0x17] * factor;
    } else {
        factor = (f32)(time - 30) / (f32)(life - 30);
        factor = 1.0f - factor;
        alpha = vars[0x17] * factor;
    }
    *(u32 *)(self + 4) = (alpha << 24) | (red << 16) | (blue << 8) | green;
    self[8]++;
    vec_add_ab(self + 0x10, self + 0x10, vars);
    *(f32 *)(vars + 8) += 0.0005f;
}
/* localdecomp:end func_L01_00466DB8 */
