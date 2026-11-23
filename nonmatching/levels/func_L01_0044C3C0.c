/* PAL near miss (opus-w4): 1 word differs with the file's flags plus -mvu0-use-vf0-vf2 (j-form vec_sub_ba; without vf2 the j-form does not compile); in the angle > 2.88 arm the second func_0038CE90 call passes axis ($s1) as $a1 where retail passes the &rotation temporary ($s0): cse picks the copy that lives longer. Needs the divs_nops row func_L01_0044C3C0 2. */
#include "common.h"
/* localdecomp:start func_L01_0044C3C0 */
#include "vu0.h"
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
extern void func_0038D850(f32 *out, f32 *in, f32 *quat);
extern f32 func_00382C58(void *, f32, f32, f32, f32, f32);

void func_L01_0044C3C0(Vec_44C280 *from, Vec_44C280 *dir, Vec_44C280 *to, void *state, Vec_44C280 *axis, Vec_44C280 *out, f32 low, f32 high, f32 rate, f32 distance)
{
    Vec_44C280 delta, cross, rotation;
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
        axis = &rotation;
        func_0038CE90(&cross.x, &rotation.x, &dir->x);
    } else {
        axis = &rotation;
        if (length < distance && angle < 1.5707964f) {
            high = 1.0f;
            low = 0.5f;
        }
    }
    half = func_00382C58(state, 0.0f, angle, low, high, rate) * 0.5f;
    func_0038CF68(&axis->x, &cross.x, func_0038D0B0(half));
    rotation.w = func_0038D098(half);
    func_0038D850(&dir->x, &dir->x, &axis->x);
    if (out) *out = rotation;
}
/* localdecomp:end func_L01_0044C3C0 */
