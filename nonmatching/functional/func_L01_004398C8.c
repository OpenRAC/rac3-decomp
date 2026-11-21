/* functional: high. 16 diff at level 01 (scheduling/register order only; same calls, args and stores) under -mvu0-use-vf0-vf2 + @ps2as, which L01_004395D0.c needs for vec_add_ab. Retail also stores a copy of obj+0x10 to a dead stack slot; omitted. */
extern void func_003C97F0(void *, s32, s32);
extern void func_0038D080(void *, unsigned long);
extern void func_0038D028(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038CF00(void *, void *);

void func_L01_004398C8(u8 *obj, s32 idx, u8 *out) {
    u8 *p = *(u8 **)(obj + 0x24);
    u8 *r = p + (p[0x2C] << 4) + (idx << 4) + 0x40;
    s32 first = *(s16 *)(r + 6);
    s32 second = *(s16 *)(r + 0xE);
    f32 k;
    vu0_v4 a;
    vu0_v4 b;

    if (first < second) {
        first = second;
    }
    if (first >= 0) {
        func_003C97F0(obj, first + 1, 0x80000000);
    }
    func_0038D080(&a, *(unsigned long *)r);
    func_0038D080(&b, *(unsigned long *)(r + 8));
    a.w = 1.0f;
    b.w = 1.0f;
    if (first >= 0) {
        func_0038D028(&a, &a, (u8 *)0x70000000 + (*(s16 *)(r + 6) << 6));
        func_0038D028(&b, &b, (u8 *)0x70000000 + (*(s16 *)(r + 0xE) << 6));
    }
    k = 0.0009765625f;
    func_0038CE20(&a, &a, *(f32 *)(obj + 0x2C) * k);
    func_0038CE20(&b, &b, *(f32 *)(obj + 0x2C) * k);
    func_0038D000(&a, &a, obj + 0xC0);
    func_0038D000(&b, &b, obj + 0xC0);
    vec_add_ab(&a, &a, obj + 0x10);
    vec_add_ab(&b, &b, obj + 0x10);
    vec_add_ab(out, &a, &b);
    func_0038CE20(out, out, 0.5f);
    *(f32 *)(out + 0xC) = func_0038CF00(out, &a);
}
