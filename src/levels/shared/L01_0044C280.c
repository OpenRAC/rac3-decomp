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

/* localdecomp:start func_L01_0044C3C0 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec_44C3C0;

extern void func_0038CE90(f32 *out, f32 *a, f32 *b);
extern void func_0038CF68(f32 *out, f32 *in, f32 length);
extern f32 func_0038CE68(f32 *a, f32 *b);
extern f32 func_0038CEA8(f32 *v);
extern f32 func_0038D0C8(f32 x);
extern f32 func_0038D0B0(f32 angle);
extern f32 func_0038D098(f32 angle);
extern void func_0038D850(f32 *out, f32 *in, f32 *quat);
extern f32 func_00382C58(void *, f32, f32, f32, f32, f32);

void func_L01_0044C3C0(Vec_44C3C0 *from, Vec_44C3C0 *dir, Vec_44C3C0 *to, void *state, Vec_44C3C0 *axis, Vec_44C3C0 *out, f32 low, f32 high, f32 rate, f32 distance)
{
    Vec_44C3C0 delta, cross, rotation;
    f32 length, dot, lengths, angle, half;

    vec_sub_ba(&delta, to, from);
    length = func_0038CEA8(&delta.x);
    if (length == 0.0f) return;
    func_0038CE90(&cross.x, &delta.x, &dir->x);
    dot = func_0038CE68(&dir->x, &delta.x);
    lengths = func_0038CEA8(&dir->x) * func_0038CEA8(&delta.x);
    if (lengths == 0.0f) return;
    angle = 1.5707964f - func_0038D0C8(dot / lengths);
    if (angle > 2.8797932f) {
        func_0038CE90(&rotation.x, &dir->x, &axis->x);
        func_0038CE90(&cross.x, &rotation.x, &dir->x);
    } else {
        if (length < distance && angle < 1.5707964f) {
            high = 1.0f;
            low = 0.5f;
        }
    }
    half = func_00382C58(state, 0.0f, angle, low, high, rate) * 0.5f;
    func_0038CF68(&rotation.x, &cross.x, func_0038D0B0(half));
    rotation.w = func_0038D098(half);
    func_0038D850(&dir->x, &dir->x, &rotation.x);
    if (out) *out = rotation;
}
/* localdecomp:end func_L01_0044C3C0 */

LINKER_REMNANT("asm/levels", func_L01_0044C5F0);
