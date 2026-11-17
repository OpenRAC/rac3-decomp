/* PAL near miss (Codex wave 8): near miss: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details).
 * Worker's note: 208 diff ordinary isolated snippet (func_L01_00476B98.01.log); wrapper COMPILE ERROR conflicting types for func_L01_004766E0 (contract-block.log): owner defines void(Vec4*,Vec4*,f32), retail caller requires f32. Draft requires owner correction, no cast/alias ...
 */
#include "common.h"
/* localdecomp:start func_L01_00476B98 */
#include "vu0.h"
typedef struct {
    s32 count;
    u8 pad4[0xC];
    Vec4 points[1];
} Path_00476B98;
/* Context correction required: the owning file currently defines
 * func_L01_004766E0 as void. Retail uses its floating-point result at
 * +0xA4, +0xFC, +0x1EC, +0x298 and +0x32C. This draft deliberately
 * retains the needed signature for review and must remain a near miss.
 * The same earlier block's func_0038CF38/func_0038CF00 declarations
 * and return statements must be corrected by the owner as well. */
s32 func_L01_00476B98(Path_00476B98 *path, Vec4 *target, Vec4 *out,
                     s32 *out_index, f32 *out_distance, s32 wrap,
                     f32 radius, f32 step, f32 vertical) {
    extern f32 func_L01_004766E0(Vec4 *, Vec4 *, f32);
    extern s32 func_L01_00476498(Path_00476B98 *, Vec4 *, s32 *, f32 *, s32, f32);
    extern s32 func_L01_00476440(const s32 *, s32, s32, s32);
    extern f32 func_L01_00476920(Vec4 *, Vec4 *, Vec4 *, Vec4 *, f32);
    Vec4 position;
    Vec4 a;
    Vec4 b;
    Vec4 c;
    s32 index = 0;
    f32 position_distance = 0.0f;
    s32 first;
    s32 last;
    s32 best = 0;
    s32 previous;
    s32 done;
    f32 best_distance;
    f32 best_position_distance = 0.0f;
    f32 distance;
    position.q = path->points[0].q;
    a.q = target->q;
    best_distance = func_L01_004766E0(&position, &a, vertical);
    if (path->count == 0) {
        qzero(out);
        return 0;
    }
    radius = step + radius;
    do {
        done = func_L01_00476498(path, &position, &index, &position_distance, wrap, step);
        a.q = target->q;
        distance = func_L01_004766E0(&position, &a, vertical);
        if (distance < best_distance) {
            best = index;
            best_distance = distance;
            best_position_distance = position_distance;
        }
    } while (done == 0);
    if (radius < best_distance) return 0;
    first = best;
    position_distance = best_position_distance;
    func_L01_00476498(path, &position, &first, &position_distance, wrap, -step);
    best_distance = 1000000000.0f;
    last = best;
    position_distance = best_position_distance;
    func_L01_00476498(path, &position, &last, &position_distance, wrap, step);
    last = func_L01_00476440(&path->count, last, 1, wrap);
    index = first;
    for (;;) {
        a.q = path->points[index].q;
        b.q = target->q;
        distance = func_L01_004766E0(&a, &b, vertical);
        if (distance < best_distance) {
            best = index;
            best_distance = distance;
        }
        if (index == last) break;
        index = (index + 1) % path->count;
    }
    best_distance = 1000000000.0f;
    if (best > 0 || wrap) {
        previous = (best + (path->count - 1)) % path->count;
        best_distance = func_L01_00476920(out, target, &path->points[previous], &path->points[best], vertical);
        *out_index = previous;
        a.q = path->points[previous].q;
        b.q = out->q;
        *out_distance = func_L01_004766E0(&a, &b, 0.0f);
    }
    if (best < path->count - 1 || wrap) {
        distance = func_L01_00476920(&a, target, &path->points[best], &path->points[(best + 1) % path->count], vertical);
        if (distance < best_distance) {
            out->q = a.q;
            *out_index = best;
            b.q = path->points[best].q;
            c.q = out->q;
            *out_distance = func_L01_004766E0(&b, &c, 0.0f);
        }
    }
    return 1;
}
/* localdecomp:end func_L01_00476B98 */
