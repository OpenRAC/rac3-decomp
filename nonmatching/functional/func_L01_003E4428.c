/* functional: high. 11 diff vs retail (VU0 asm scheduling); every call, offset, constant checked vs asm */
/* localdecomp:start func_L01_003E4428 */
#include "vu0.h"
extern u8 D_L01_001E2AA0[];
static __inline__ void copy_003E4428(vu0_v4 *d, vu0_v4 *s) {
    __asm__("lqc2 $vf2, %1\n\tsqc2 $vf2, %0" : "=m"(*(vu0_q *)d) : "m"(*(vu0_q *)s) : "vf2");
}
static __inline__ void add_003E4428(vu0_v4 *d, vu0_v4 *s) {
    __asm__("lqc2 $vf1, %0\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "+m"(*(vu0_q *)d) : "m"(*(vu0_q *)s) : "vf1", "vf2");
}
static __inline__ void sub_003E4428(vu0_v4 *d, vu0_v4 *a, vu0_v4 *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(vu0_q *)d) : "m"(*(vu0_q *)a), "m"(*(vu0_q *)b) : "vf1", "vf2");
}

f32 func_L01_003E4428(u8 *obj, f32 distance) {
    extern void func_L01_003E4028(u8 *, u128_t *);
    extern void func_0038CE20(f32 *, void *, f32);
    extern f32 func_0038CE68(f32 *, f32 *);
    extern f32 func_0038CEA8(f32 *);
    extern f32 func_0038D0C8(f32);
    vu0_v4 p, scaled, delta, projection, origin_copy, point_copy;
    u8 *entry = D_L01_001E2AA0 + *(s32 *)(obj + 0x94) * 1120;
    f32 dot, len, angle;
    func_L01_003E4028(obj, (u128_t *)&p);
    func_0038CE20((f32 *)&scaled, entry + 0x20, distance);
    copy_003E4428(&point_copy, &p);
    copy_003E4428(&origin_copy, (vu0_v4 *)(obj + 0x30));
    add_003E4428(&scaled, &point_copy);
    sub_003E4428(&delta, &scaled, &origin_copy);
    dot = func_0038CE68((f32 *)&delta, (f32 *)(obj + 0x10));
    func_0038CE20((f32 *)&projection, obj + 0x10, dot);
    __asm__("lqc2 $vf1, %0\n\t"
            "lqc2 $vf2, %1\n\t"
            "vsub.xyz $vf1, $vf1, $vf2\n\t"
            "sqc2 $vf1, %0"
            : "+m"(delta) : "m"(projection) : "vf1", "vf2");
    dot = func_0038CE68((f32 *)&delta, (f32 *)obj);
    len = func_0038CEA8((f32 *)&delta);
    if (len == 0.0f) return 0.0f;
    angle = 1.57079637f - func_0038D0C8(dot / len);
    if (func_0038CE68((f32 *)&delta, (f32 *)(obj + 0x20)) < 0.0f) angle = -angle;
    return angle;
}
/* localdecomp:end func_L01_003E4428 */
