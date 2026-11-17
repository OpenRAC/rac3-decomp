/* PAL near miss (Codex wave 6): near miss: 98 words differ with the file's flags.
 * Worker's note: 99 diff; first-09-detail.log; VU0/argument scheduling, saved-register allocation and branch layout; fixed flags, stopped after ten attempts
 */
#include "common.h"
/* localdecomp:start func_L01_0044C3C0 */
void func_L01_0044C3C0(Vec_44C280 *from, Vec_44C280 *dir, Vec_44C280 *to, void *state, Vec_44C280 *axis, Vec_44C280 *out, f32 low, f32 high, f32 rate, f32 distance)
{
    extern f32 func_00382C58(void *, f32, f32, f32, f32, f32);
    Vec_44C280 delta, cross, rotation;
    f32 length, dot, lengths, angle, half;
    Vec_44C280 *result = &rotation;
    __asm__ (
        "lqc2 $vf1, 0(%1)\n"
        "lqc2 $vf2, 0(%2)\n"
        "vsub.xyz $vf2, $vf2, $vf1\n"
        "sqc2 $vf2, %0\n"
        : "=m" (delta) : "r" (from), "r" (to));
    length = func_0038CEA8(&delta.x);
    if (length == 0.0f) return;
    func_0038CE90(&cross.x, &delta.x, &dir->x);
    dot = func_0038CE68(&dir->x, &delta.x);
    lengths = func_0038CEA8(&dir->x) * func_0038CEA8(&delta.x);
    if (lengths == 0.0f) return;
    angle = 1.5707964f - func_0038D0C8(dot / lengths);
    if (angle > 2.8797932f) {
        func_0038CE90(&result->x, &dir->x, &axis->x);
        axis = result;
        func_0038CE90(&cross.x, &result->x, &dir->x);
    } else {
        axis = result;
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
