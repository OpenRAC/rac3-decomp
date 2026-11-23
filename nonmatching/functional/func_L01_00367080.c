/* functional: high. 12 words differ (VU0 asm block scheduling) only; control flow, constants (-0.07), offsets and all 8 callees verified against asm */
/* localdecomp:start func_L01_00367080 */
static __inline__ void sub_00367080(s128 *d, s128 *a, s128 *b) {
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
static __inline__ void add_00367080(s128 *d, s128 *a, s128 *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*d) : "m"(*a), "m"(*b) : "vf1", "vf2");
}
s32 func_L01_00367080(s128 *a0, s128 *a1, s128 *out0, s128 *out1) {
    extern s32 func_L01_00367018(s128 *, f32 *);
    extern void func_L01_00446630(s128 *, s128 *, s128 *, s128 *);
    extern f32 func_L01_0040E548(s128 *, s128 *);
    extern f32 func_0038D0C8(f32);
    extern f32 func_0038D098(f32);
    extern void func_0038CF68(s128 *, s128 *, f32);
    extern f32 func_0038CE68(s128 *, s128 *);
    struct { s128 plane, direction, center; f32 radius; } local;
    f32 distance, half, lo, hi, middle;
    s32 flags;
    if (!func_L01_00367018(&local.plane, &local.radius)) return 0;
    local.radius += -0.07f;
    func_L01_00446630(&local.center, a0, a1, &local.plane);
    distance = func_L01_0040E548(&local.center, &local.plane);
    if (distance > local.radius) return 0;
    half = func_0038D098(func_0038D0C8(distance / local.radius)) * local.radius;
    flags = 0;
    sub_00367080(&local.direction, a1, a0);
    func_0038CF68(&local.direction, &local.direction, 1.0f);
    lo = func_0038CE68(&local.direction, a0);
    hi = func_0038CE68(&local.direction, a1);
    middle = func_0038CE68(&local.direction, &local.center);
    if (lo < middle - half) {
        func_0038CE20(out0, &local.direction, -half);
        flags = 1;
        add_00367080(out0, out0, &local.center);
    }
    if (middle + half < hi) {
        func_0038CE20(out1, &local.direction, half);
        add_00367080(out1, out1, &local.center);
        if ((flags ^ 1) & 1) *out0 = *out1;
        flags |= 2;
    }
    return flags;
}
/* localdecomp:end func_L01_00367080 */
