#include "common.h"

/* declared by functions of L30_00343398.c, which this file was cut from */
extern void func_L30_00343798(u8 *, f32);

/* localdecomp:start func_L30_00343660 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00343660;
extern u8 D_001A4BE0[];
extern void func_0038D308(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L30_00343AC8(void *, void *, f32 *, f32 *);
extern void func_L30_0034C540(void *, void *, f32, f32, f32, s32);
extern void func_003C7DD8(void *);

void func_L30_00343660(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    f32 x = *(f32 *)(m + 0x10);
    V_00343660 buf[10];
    f32 a, b;
    u8 *hero;

    func_0038D308(m + 0xC0, m + 0xF0);
    func_0038CE20(m + 0xC0, m + 0xC0, *(f32 *)(v + 0x1A4));
    func_0038CE20(m + 0xD0, m + 0xD0, *(f32 *)(v + 0x1A8));
    func_0038CE20(m + 0xE0, m + 0xE0, *(f32 *)(v + 0x1AC));
    func_L30_00343AC8(m, buf, &a, &b);
    vec_sub_ab(m + 0x10, v + 0x130, &buf[0]);
    hero = D_001A4BE0;
    if (*(u8 **)(hero + 0x3C0) == m && *(u8 **)(hero + 0x35C) == m && *(s16 *)(hero + 0x36E) == 0 &&
        x != *(f32 *)(m + 0x10)) {
        V_00343660 t;
        qzero(&t);
        t.x = x - *(f32 *)(m + 0x10);
        vec_add_ab(hero + 0x370, hero + 0x370, &t);
    }
    func_L30_0034C540(&buf[1], v + 0x130, a + a, b + b, 0.0f, 0);
    func_003C7DD8(m);
    *(vu0_q *)(v + 0x70) = *(vu0_q *)(m + 0x10);
}
/* localdecomp:end func_L30_00343660 */

/* localdecomp:start func_L30_00343798 */
void func_L30_00343798(u8 *m, f32 t) {
    u8 *v = *(u8 **)(m + 0x68);
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 old;
    vu0_v4 d;

    *(vu0_q *)&old = *(vu0_q *)(v + 0x130);
    func_0038CE20(&a, v + 0x140, 1.0f - t);
    func_0038CE20(&b, v + 0x150, t);
    vec_add_ab(v + 0x130, &a, &b);
    vec_sub_ab(&d, v + 0x130, &old);
    vec_add_ab(m + 0x10, m + 0x10, &d);
}
/* localdecomp:end func_L30_00343798 */

/* localdecomp:start func_L30_00343830 */
#include "vu0.h"

extern f32 func_0038CEA8(void *);
extern f32 func_0038CF00(void *, void *);
extern void func_0038CF68(void *, void *, f32);

/* The vector library's XYZ add and subtract retain the center's W lane. */
static __inline__ void box_center_and_delta(vu0_v4 *center, vu0_v4 *delta, const vu0_v4 *origin,
                                            const vu0_v4 *offset, const vu0_v4 *target,
                                            vu0_v4 *saved_target, vu0_v4 *saved_offset) {
    vu0_q base;
    vu0_q point;

    __asm__("lqc2 %2, %3\n\t"
            "lqc2 %1, %4\n\t"
            "sqc2 %2, %0\n\t"
            "lqc2 %2, %5"
            : "=m"(*saved_offset), "=&j"(base), "=&j"(point)
            : "m"(*offset), "m"(*origin), "m"(*target));
    __asm__("sqc2 %1, %0" : "=m"(*saved_target) : "j"(point));
    __asm__("lqc2 %0, %1" : "=j"(point) : "m"(*saved_offset));
    __asm__("vadd.xyz %0, %0, %1" : "+j"(base) : "j"(point));
    __asm__("sqc2 %1, %0" : "=m"(*center) : "j"(base));
    __asm__("lqc2 %0, %1" : "=j"(base) : "m"(*center));
    __asm__("lqc2 %0, %1" : "=j"(point) : "m"(*saved_target));
    __asm__("vsub.xyz %0, %1, %0" : "+j"(base) : "j"(point));
    __asm__("sqc2 %1, %0" : "=m"(*delta) : "j"(base));
}

s32 func_L30_00343830(u8 *o, vu0_v4 *out, vu0_v4 *target, f32 margin) {
    vu0_v4 off;
    vu0_v4 center;
    vu0_v4 d;
    f32 extents[2];
    vu0_v4 tgt;
    vu0_v4 tmp;
    f32 len;

    func_L30_00343AC8(o, &off, &extents[0], &extents[1]);
    box_center_and_delta(&center, &d, (const vu0_v4 *)(o + 0x10), &off, target, &tgt, &tmp);

    if (d.x == 0.0f) {
        if (d.z == 0.0f) {
            *(vu0_q *)out = *(vu0_q *)&center;
            return 1;
        }
        len = func_0038CEA8(&d);
        if (extents[1] + margin < len) {
            return 0;
        }
        *(vu0_q *)out = *(vu0_q *)&center;
        out->z += extents[1] * fabs_asm(d.z) / d.z;
        return 1;
    }
    if (d.z == 0.0f) {
        len = func_0038CEA8(&d);
        if (extents[1] + margin < len) {
            return 0;
        }
        *(vu0_q *)out = *(vu0_q *)&center;
        out->x += extents[0] * fabs_asm(d.x) / d.x;
        return 1;
    }
    {
        f32 rz = fabs_asm(d.z / d.x);
        f32 rh = fabs_asm(extents[1] / extents[0]);
        if (rh < rz) {
            f32 az = fabs_asm(d.z);
            if (az < extents[1]) {
                f32 distance = func_0038CEA8(&d);
                func_0038CF68(out, &d, distance - margin);
                vec_add_ab(out, out, &center);
                return 1;
            }
            func_0038CE20(out, &d, extents[1] / az);
        } else {
            f32 ax = fabs_asm(d.x);
            if (ax < extents[0]) {
                f32 distance = func_0038CEA8(&d);
                func_0038CF68(out, &d, distance - margin);
                vec_add_ab(out, out, &center);
                return 1;
            }
            func_0038CE20(out, &d, extents[0] / ax);
        }
        len = func_0038CEA8(&d);
        if (margin + func_0038CF00(out, &center) < len) {
            return 0;
        }
    }
    vec_add_ab(out, out, &center);
    return 1;
}
/* localdecomp:end func_L30_00343830 */

/* localdecomp:start func_L30_00343AC8 */
__asm__(".extern D_L30_001DCE54, 4");
extern f32 D_L30_001DCE54;
__asm__(".extern D_L30_001DCE58, 4");
extern f32 D_L30_001DCE58;
__asm__(".extern D_L30_001DCE5C, 4");
extern f32 D_L30_001DCE5C;
__asm__(".extern D_L30_001DCE60, 4");
extern f32 D_L30_001DCE60;
__asm__(".extern D_L30_001DCE64_00343AC8, 4");
extern f32 D_L30_001DCE64_00343AC8;
__asm__(".extern D_L30_001DCE68, 4");
extern f32 D_L30_001DCE68;
__asm__(".extern D_L30_001DCE6C, 4");
extern f32 D_L30_001DCE6C;
__asm__(".extern D_L30_001DCE70_00343AC8, 4");
extern f32 D_L30_001DCE70_00343AC8;
__asm__(".extern D_L30_001DCE74, 4");
extern f32 D_L30_001DCE74;
__asm__(".extern D_L30_001DCE78_00343AC8, 4");
extern f32 D_L30_001DCE78_00343AC8;
__asm__(".extern D_L30_001DCE7C, 4");
extern f32 D_L30_001DCE7C;
__asm__(".extern D_L30_001DCE80, 4");
extern f32 D_L30_001DCE80;
__asm__(".extern D_L30_001DCE84, 4");
extern f32 D_L30_001DCE84;
__asm__(".extern D_L30_001DCE88_00343AC8, 4");
extern f32 D_L30_001DCE88_00343AC8;
__asm__(".extern D_L30_001DCE8C_00343AC8, 4");
extern f32 D_L30_001DCE8C_00343AC8;
extern void func_0038D000(void *, void *, void *);

void func_L30_00343AC8(void *arg0, void *arg1, f32 *ow, f32 *oh) {
    u8 *o = arg0;
    vu0_v4 *out = arg1;
    vu0_v4 t;
    f32 w;
    f32 h;
    f32 s;

    switch (*(s16 *)(o + 0xAA)) {
    case 0x1745:
        w = D_L30_001DCE58;
        h = D_L30_001DCE54;
        break;
    case 0x19B7:
        w = D_L30_001DCE60;
        h = D_L30_001DCE5C;
        break;
    case 0x19B9:
        w = D_L30_001DCE6C;
        h = D_L30_001DCE68;
        break;
    case 0x1A2A:
        w = D_L30_001DCE74;
        h = D_L30_001DCE70_00343AC8;
        break;
    case 0x1AED:
        w = D_L30_001DCE7C;
        h = D_L30_001DCE78_00343AC8;
        break;
    case 0x1AEF:
        w = D_L30_001DCE84;
        h = D_L30_001DCE80;
        break;
    case 0x1B16:
        w = D_L30_001DCE8C_00343AC8;
        h = D_L30_001DCE88_00343AC8;
        break;
    default:
        h = 1.0f;
        w = h;
        break;
    }
    s = *(f32 *)(o + 0x2C) / *(f32 *)(*(u8 **)(o + 0x24) + 0x24);
    qzero(&t);
    w *= s;
    h *= s;
    t.x = w;
    t.z = h;
    func_0038D000(&t, &t, o + 0xC0);
    w = t.x;
    h = t.z;
    if (out != 0) {
        qzero(out);
        if (*(s16 *)(o + 0xAA) == 0x19B7 || *(s16 *)(o + 0xAA) == 0x1AED || *(s16 *)(o + 0xAA) == 0x1AEF) {
            out->x += w;
        }
        if (*(s16 *)(o + 0xAA) == 0x19B7) {
            out->z -= h;
        }
        if (*(s16 *)(o + 0xAA) == 0x19B9) {
            out->z += D_L30_001DCE64_00343AC8;
        }
        if (*(s16 *)(o + 0xAA) == 0x1AED || *(s16 *)(o + 0xAA) == 0x1AEF) {
            out->z += h;
        }
    }
    if (ow != 0) {
        *ow = w;
    }
    if (oh != 0) {
        *oh = h;
    }
}
/* localdecomp:end func_L30_00343AC8 */
