/* functional: high. ~20 diff at default flags, scheduling/reg order only */
extern f32 D_L24_001DE464;
extern f32 D_L24_001DE468;
extern f32 D_L24_001DE46C;
extern f32 D_L24_001DE470;
extern f32 D_L24_001DE474;
extern s32 D_L24_001DE478;
extern f32 D_L24_001DE47C;
extern f32 D_L24_001DE480;
__asm__(".extern D_L24_001DE464, 4");
__asm__(".extern D_L24_001DE468, 4");
__asm__(".extern D_L24_001DE46C, 4");
__asm__(".extern D_L24_001DE470, 4");
__asm__(".extern D_L24_001DE474, 4");
__asm__(".extern D_L24_001DE478, 4");
__asm__(".extern D_L24_001DE47C, 4");
__asm__(".extern D_L24_001DE480, 4");
extern f32 func_003824E0(f32, f32);
extern f32 func_L03_0034B148(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);

void func_L24_003A9C10(u8 *out, u8 *in) {
    u8 *p;
    f32 s;
    f32 x;
    f32 lo;
    f32 hi;
    f32 t;
    s32 col;

    if (in == 0) {
        return;
    }
    p = *(u8 **)in;
    if (p == 0) {
        return;
    }
    if (*(u32 *)(in + 4) == 0) {
        return;
    }
    s = *(f32 *)(p + 0xC) * 0.0009765625f;
    if (*(u16 *)(in + 0xA) & 1) {
        *(u32 *)(out + 0x10) = *(u32 *)(p + 0x10);
        *(u32 *)(out + 0x14) = *(u32 *)(p + 0x14);
        *(u32 *)(out + 0x18) = *(u32 *)(p + 0x18);
        *(u32 *)(out + 0x1C) = *(u32 *)(p + 0x1C);
        *(f32 *)(out + 0x10) += func_003824E0(-D_L24_001DE464 * s, D_L24_001DE464 * s);
        *(f32 *)(out + 0x18) += func_003824E0(0.0f, D_L24_001DE468 * s);
    }
    x = D_L24_001DE470 * (f32)(*(u16 *)(in + 0xC) & 0xFF) * 0.00390625f;
    if (*(u16 *)(in + 0xC) & 1) {
        *(f32 *)(out + 0x10) = *(f32 *)(out + 0x10) + (D_L24_001DE46C + x);
    } else {
        *(f32 *)(out + 0x10) = *(f32 *)(out + 0x10) - (D_L24_001DE46C + x);
    }
    lo = (f32)(*(u16 *)(in + 0xE) & 0xFF);
    hi = D_L24_001DE474 * (f32)*(s16 *)(in + 8) * (f32)(*(u16 *)(in + 0xE) >> 8) * 0.00390625f;
    hi = lo + (lo + hi);
    t = func_L03_0034B148(*(s16 *)(out + 0xA), *(s16 *)(in + 8), 0.0f);
    *(u8 *)(out + 8) = (s32)func_003C4088(lo, hi, t);
    col = D_L24_001DE478 & 0xFFFFFF;
    t = func_L03_0034B148(*(s16 *)(out + 0xA), *(s16 *)(in + 8), 0.0f);
    *(s32 *)(out + 4) = func_0038DBD8(D_L24_001DE478, col, t);
    if (*(u16 *)(in + 0xA) & 1) {
        *(f32 *)(out + 0xC) = func_003824E0(D_L24_001DE480, D_L24_001DE47C);
    }
}
