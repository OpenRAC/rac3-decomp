/* PAL near miss (Codex wave 11): near miss: 124 words differ in its file's context with the file's flags.
 * Replaces the earlier draft (Codex wave 8 near miss: 159 words differ under tools/check.py in its file's context with the file's flags, measured 2026-11-21;
 * this one: 124).
 * Worker's note: needs the same line as func_L07_003ACD58 (same file): '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as' (vu0.h vec_sub/vec_add helpers: retail schedules argument moves inside each VU0 sequence; ps2as for dli 0x4000000044 as ori 0x8000+dsll 23+ori), but even then 124 diff (W/func_L07_003AD210.flags-experiment.log): every VU0 sequence and loop 2 shape match; left are global-alloc/loop.c choices: retail hoists %hi(D_L07_001E1EC0) into fp and recomputes la D_L07_001E1678 per iteration, mine keeps %hi(D_L07_001E1678) in s7 from the prologue (array form D[i] instead gives a giv: 152), so s5/s6/s7/fp rotate, and nverts = count * 2 is scheduled 3 calls earlier; file line: vu0 helpers do not compile (prior draft 161)
 */
#include "common.h"

/* localdecomp:start func_L07_003AD210 */
#include "vu0.h"
typedef struct { f32 x, y, z; } Point_003AD210;
extern vu0_v4 D_L07_001E1EC0;
extern Point_003AD210 D_L07_002A22E0[];
extern f32 D_L07_001E1678[];
extern u32 D_L07_002A23D0[][2];
extern vu0_v4 D_L07_002A2420[];

void func_L07_003AD210(void *object, void *points, s32 count, s32 start, s32 texture)
{
    vu0_v4 *v = points;
    extern void func_0038C750(void);
    extern unsigned long func_00389598(s32);
    extern void func_003A9440(s32, unsigned long);
    extern f32 func_0038CEA8(void *);
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern u32 func_0038DBD8(u32, u32, f32);
    extern void func_003D3A24(s32, void *, void *, void *, s32);
    vu0_v4 delta, previous, normal, view, cross, temp;
    f32 length, fraction, inv, d;
    s32 i, j, next, nverts;
    Point_003AD210 *out;
    f32 *len;
    u32 *colors;
    vu0_v4 *uv;

    if (count < 2) {
        return;
    }
    func_0038C750();
    length = 0.0f;
    func_003A9440(6, func_00389598(texture));
    func_003A9440(0x14, 0x0000FF9000000260UL);
    func_003A9440(8, 0);
    nverts = count * 2;
    func_003A9440(0x42, 0x0000004000000044UL);
    out = D_L07_002A22E0;
    for (i = 0; i < count; i++, out += 2) {
        j = (i + start) % count;
        next = (j + 1) % count;
        if (i != count - 1) {
            vec_sub_ab(&delta, &v[j], &v[next]);
            d = func_0038CEA8(&delta);
            length += d;
            *(f32 *)((s32)D_L07_001E1678 + (i << 2)) = d;
        }
        if (i != 0 && i != count - 1) {
            vec_add_ab(&normal, &delta, &previous);
        } else {
            *(vu0_q *)&normal = *(vu0_q *)&delta;
        }
        vec_sub_ab(&view, &D_L07_001E1EC0, &v[j]);
        func_0038CE90(&cross, &view, &normal);
        func_0038CF68(&cross, &cross, 0.5f);
        vec_add_ba(&temp, &v[j], &cross);
        out[0].x = temp.x;
        out[0].y = temp.y;
        out[0].z = temp.z;
        vec_sub_ba(&temp, &v[j], &cross);
        out[1].x = temp.x;
        out[1].y = temp.y;
        out[1].z = temp.z;
    }
    inv = 1.0f / length;
    fraction = 0.0f;
    len = D_L07_001E1678;
    colors = D_L07_002A23D0[0];
    uv = D_L07_002A2420;
    for (i = count; i != 0; i--) {
        u32 color = func_0038DBD8(0x00804020, 0x30202080, fraction);
        colors[0] = color;
        colors[1] = color;
        uv->x = fraction;
        uv->y = 0.0f;
        uv->z = fraction;
        uv->w = 1.0f;
        fraction += *len++ * inv;
        colors += 2;
        uv++;
    }
    func_003D3A24(nverts, D_L07_002A22E0, D_L07_002A23D0, D_L07_002A2420, 1);
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L07_003AD210 */
