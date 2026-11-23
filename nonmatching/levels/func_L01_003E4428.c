/* PAL near miss (sol-round3-c): 4 words differ with the file's flags; two dot-product argument moves interleave differently with VU0 copy and add instructions. */
/* localdecomp:start func_L01_003E4428 */
#include "vu0.h"
extern u8 D_L01_001E2AA0[];
static __inline__ void copy_003E4428(vu0_v4 *d, vu0_v4 *s) {
    __asm__("lqc2 $vf2, %1\n\tsqc2 $vf2, %0" : "=m"(*(vu0_q *)d) : "m"(*(vu0_q *)s) : "vf2");
}
f32 func_L01_003E4428(u8 *obj, f32 distance) {
    extern void func_L01_003E4028(u8 *, u128_t *);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_0038CE68(void *, void *);
    extern f32 func_0038CEA8(f32 *);
    extern f32 func_0038D0C8(f32);
    vu0_v4 p, scaled, delta, projection, origin_copy, point_copy;
    u8 *entry = D_L01_001E2AA0 + *(s32 *)(obj + 0x94) * 1120;
    f32 dot, len, angle;
    func_L01_003E4028(obj, (u128_t *)&p);
    func_0038CE20((f32 *)&scaled, entry + 0x20, distance);
    {
        vu0_q point, scale, sum;
        __asm__("lqc2 $vf2, %2\n\tlqc2 %0, %3\n\tsqc2 $vf2, %1"
            : "=j"(scale), "=m"(point_copy) : "m"(p), "m"(scaled) : "vf2");
        copy_003E4428(&origin_copy, (vu0_v4 *)(obj + 0x30));
        __asm__("lqc2 %0, %1" : "=j"(point) : "m"(point_copy));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(sum) : "j"(scale), "j"(point));
        __asm__("sqc2 %1, %0" : "=m"(scaled) : "j"(sum));
    }
    vec_sub_ba(&delta, &scaled, &origin_copy);
    dot = func_0038CE68((f32 *)&delta, (f32 *)(obj + 0x10));
    func_0038CE20((f32 *)&projection, obj + 0x10, dot);
    vec_sub_ab(&delta, &delta, &projection);
    dot = func_0038CE68((f32 *)&delta, (f32 *)obj);
    len = func_0038CEA8((f32 *)&delta);
    if (len == 0.0f) return 0.0f;
    angle = 1.57079637f - func_0038D0C8(dot / len);
    if (func_0038CE68((f32 *)&delta, (f32 *)(obj + 0x20)) < 0.0f) angle = -angle;
    return angle;
}
/* localdecomp:end func_L01_003E4428 */
