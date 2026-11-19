/* functional: high. Per-tick update of a drifting effect object (q = obj+0x20, q[0x10] = remaining fade steps): counts the fade down (clamped at 0), bumps the age byte, adds the velocity q to the position (the w lane of the position takes q's w, as retail's vadd.xyz leaves vf1's w), grows size by 1575, damps q by 0.99, adds a wind vector from func_L39_005FF198 scaled by a tiny constant (larger when the alpha byte is < 0x20), fades the colour via func_0038DBD8 and the fade count, and frees the object when the fade count reaches 0. */
/* localdecomp:start func_L39_005D3CA0 */
extern void func_L39_005FFB48(void *, void *);
extern void func_L39_005FF198(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_0038DBD8(s32, s32, f32);

void func_L39_005D3CA0(u8 *p) {
    f32 v[4] __attribute__((aligned(16)));
    u8 *q;
    s32 n;

    func_L39_005FFB48(p + 0x10, p + 0x10);
    q = p + 0x20;
    n = *(s32 *)(q + 0x10) - 1;
    *(s32 *)(q + 0x10) = n;
    if (n < 0) {
        *(s32 *)(q + 0x10) = 0;
    }
    p[8] = p[8] + 1;
    *(f32 *)(p + 0x10) = *(f32 *)(p + 0x20) + *(f32 *)(p + 0x10);
    *(f32 *)(p + 0x14) = *(f32 *)(p + 0x24) + *(f32 *)(p + 0x14);
    *(f32 *)(p + 0x18) = *(f32 *)(p + 0x28) + *(f32 *)(p + 0x18);
    *(f32 *)(p + 0x1C) = *(f32 *)(p + 0x2C);
    *(f32 *)(p + 0xC) = *(f32 *)(p + 0xC) + 1575.0f;
    func_0038CE20(q, q, 0.99f);
    func_L39_005FF198(0, p + 0x10, v);
    func_0038CE20(v, v, p[4] < 0x20 ? 0.0015f : -0.00075f);
    *(f32 *)(p + 0x20) = *(f32 *)(p + 0x20) + v[0];
    *(f32 *)(p + 0x24) = *(f32 *)(p + 0x24) + v[1];
    *(f32 *)(p + 0x28) = *(f32 *)(p + 0x28) + v[2];
    *(s32 *)(p + 4) = func_0038DBD8(*(s32 *)(p + 4) & 0xFFFFFF, 0, 0.025f) | (*(s32 *)(q + 0x10) << 24);
    if (*(s32 *)(q + 0x10) == 0) {
        func_003CD250(p);
    }
}
/* localdecomp:end func_L39_005D3CA0 */
