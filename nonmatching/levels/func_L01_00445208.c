/* near miss: vec_cubic (open-rac-engine, effects.md: the Spitting Hydra's arcs). Every
 * instruction matches; 24 words differ in float registers only: retail keeps t^3 in $f2 and the
 * bow/end loads in $f3/$f4, gcc gives t^3 $f3 and the loads $f4/$f2. Tried: a t3 variable or
 * (t2 * t) at each use, t * t * t, operand orders, declaration orders, the loads in locals
 * (as the scalar 0x4451D0 would inline), t as the first parameter. */
#include "common.h"

/* localdecomp:start func_L01_00445208 */
typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec_445208;

/* vec_cubic: a point on a cubic curve of vectors, start at t 0 and end at t 1 (bow and far
 * shape it between); the Spitting Hydra lays its arcs' points on it. Per axis as 0x4451D0. */
void func_L01_00445208(f32 t, Vec_445208 *out, Vec_445208 *start, Vec_445208 *end, Vec_445208 *bow, Vec_445208 *far) {
    f32 t2;
    f32 t3;
    f32 a;
    f32 b;

    if (t == 0.0f) {
        *out = *start;
        return;
    }
    if (t == 1.0f) {
        *out = *end;
        return;
    }
    t2 = t * t;
    t3 = t2 * t;
    a = (far->x - end->x) - (bow->x - start->x);
    b = (bow->x - start->x) - a;
    out->x = a * t3 + b * t2 + (end->x - bow->x) * t + start->x;
    a = (far->y - end->y) - (bow->y - start->y);
    b = (bow->y - start->y) - a;
    out->y = a * t3 + b * t2 + (end->y - bow->y) * t + start->y;
    a = (far->z - end->z) - (bow->z - start->z);
    b = (bow->z - start->z) - a;
    out->z = a * t3 + b * t2 + (end->z - bow->z) * t + start->z;
    out->w = 0.0f;
}
/* localdecomp:end func_L01_00445208 */
