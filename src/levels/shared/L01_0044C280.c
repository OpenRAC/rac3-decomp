#include "common.h"

/* localdecomp:start func_L01_0044C280 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec_44C280;

extern void func_0038CE90(f32 *out, f32 *a, f32 *b);
extern void func_0038CF68(f32 *out, f32 *in, f32 length);
extern f32 func_0038CE68(f32 *a, f32 *b);
extern f32 func_0038CEA8(f32 *v);
extern f32 func_0038D0C8(f32 x);
extern f32 func_0038D0B0(f32 angle);
extern f32 func_0038D098(f32 angle);
extern void func_0038CE20(f32 *out, f32 *in, f32 s);
extern void func_0038D850(f32 *out, f32 *in, f32 *quat);

/* dir_turn_towards: from turned towards to by a share (by) of the angle between them, about
 * their cross product (the whip rope's lag); unit says both are unit length already. */
void func_L01_0044C280(Vec_44C280 *out, Vec_44C280 *from, Vec_44C280 *to, s32 unit, f32 by) {
    Vec_44C280 turn;
    f32 cos_angle;
    f32 half;

    func_0038CE90(&turn.x, &to->x, &from->x);
    func_0038CF68(&turn.x, &turn.x, 1.0f);
    cos_angle = func_0038CE68(&from->x, &to->x);
    if (!unit) {
        f32 lengths = func_0038CEA8(&from->x) * func_0038CEA8(&to->x);
        if (lengths == 0.0f) {
            *out = *from;
            return;
        }
        cos_angle /= lengths;
    }
    /* half the share of the angle, acos as pi/2 - asin */
    half = (1.5707964f - func_0038D0C8(cos_angle)) * 0.5f * by;
    func_0038CE20(&turn.x, &turn.x, func_0038D0B0(half));
    turn.w = func_0038D098(half);
    func_0038D850(&out->x, &from->x, &turn.x);
}
/* localdecomp:end func_L01_0044C280 */

INCLUDE_ASM("asm/levels", func_L01_0044C3C0);

LINKER_REMNANT("asm/levels", func_L01_0044C5F0);
