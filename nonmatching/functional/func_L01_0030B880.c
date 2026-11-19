/* functional: high. Rewritten from the assembly (the draft used a private asm helper; this uses the shared vector helpers). 8 points along a curve (t=i/7) from record+0x20 to +0x30 with control points record+0x00 and +0x10 offset by +0x20 and +0x30; alpha random 64..128 once the counter at +0x98 reaches half of +0x9C, else 0..64. 63 words differ. */
extern void func_L01_0030ABF8(void *, void *, void *, void *, void *, f32);
extern void func_L01_0030B9C8(s32, s32, void *, s32);
extern s32 func_00382498(s32, s32);

void func_L01_0030B880(s32 object, vu0_v4 *source)
{
    vu0_v4 points[9];
    vu0_v4 a, b, tangent;
    s32 i;

    for (i = 0; i < 8; i++) {
        a = source[0];
        b = source[1];
        tangent = source[3];
        vec_add_ab(&a, &a, &source[2]);
        vec_add_ab(&b, &b, &tangent);
        func_L01_0030ABF8(&points[i], &source[2], &source[3], &a, &b, (f32)i / 7.0f);
    }
    if (*(s32 *)((u8 *)source + 0x98) < (*(s32 *)((u8 *)source + 0x9C) >> 1)) {
        func_L01_0030B9C8(object, func_00382498(0, 64), points, 9);
    } else {
        func_L01_0030B9C8(object, func_00382498(64, 128), points, 9);
    }
}
