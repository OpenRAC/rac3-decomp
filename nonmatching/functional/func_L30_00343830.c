/* functional: high. Rewritten from asm; same branch structure (axis-zero cases, aspect ratio compare, vec_set_length/scale paths); diffs are abs/branch scheduling */
#include "vu0.h"
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L30_00343AC8(void *, void *, f32 *, f32 *);

s32 func_L30_00343830(u8 *o, vu0_v4 *out, vu0_v4 *target, f32 margin) {
    vu0_v4 off;
    vu0_v4 center;
    vu0_v4 d;
    vu0_v4 tgt;
    vu0_v4 tmp;
    f32 w;
    f32 h;
    f32 len;
    f32 s;

    func_L30_00343AC8(o, &off, &w, &h);
    *(vu0_q *)&tmp = *(vu0_q *)&off;
    vec_add_ab(&center, o + 0x10, &tmp);
    *(vu0_q *)&tgt = *(vu0_q *)target;
    vec_sub_ab(&d, &tgt, &center);

    if (d.x == 0.0f) {
        if (d.z == 0.0f) {
            *(vu0_q *)out = *(vu0_q *)&center;
            return 1;
        }
        len = func_0038CEA8(&d);
        if (h + margin < len) {
            return 0;
        }
        *(vu0_q *)out = *(vu0_q *)&center;
        out->z += h * (d.z < 0.0f ? -d.z : d.z) / d.z;
        return 1;
    }
    if (d.z == 0.0f) {
        len = func_0038CEA8(&d);
        if (h + margin < len) {
            return 0;
        }
        *(vu0_q *)out = *(vu0_q *)&center;
        out->x += w * (d.x < 0.0f ? -d.x : d.x) / d.x;
        return 1;
    }
    {
        f32 rz = d.z / d.x;
        f32 rh = h / w;
        f32 az;
        f32 ax;
        if (rz < 0.0f) {
            rz = -rz;
        }
        if (rh < 0.0f) {
            rh = -rh;
        }
        az = d.z < 0.0f ? -d.z : d.z;
        ax = d.x < 0.0f ? -d.x : d.x;
        if (rh < rz) {
            if (az < h) {
                func_0038CF68(out, &d, func_0038CEA8(&d) - margin);
                goto done;
            }
            s = h / az;
        } else {
            if (ax < w) {
                func_0038CF68(out, &d, func_0038CEA8(&d) - margin);
                goto done;
            }
            s = w / ax;
        }
        func_0038CE20(out, &d, s);
        len = func_0038CEA8(&d);
        if (margin + func_0038CF00(out, &center) < len) {
            return 0;
        }
    }
done:
    vec_add_ab(out, out, &center);
    return 1;
}
