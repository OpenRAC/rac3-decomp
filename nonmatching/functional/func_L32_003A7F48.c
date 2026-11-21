/* functional: high. Draft (114 diff: callee-saved register assignment only) verified line by line against PAL asm: gp globals DE8A8..DE8D8, callees, offsets, alpha/fade and colour-lerp formulas. func_L03_0034B148(f32, s32 cur, s32 max): retail reaches $a1 only by passthrough (a1->0x8 left in $a1 for the call), so it is passed explicitly here. */
extern f32 D_L32_001DE8C0;
extern f32 D_L32_001DE8D4;
extern f32 D_L32_001DE8C8;
extern f32 D_L32_001DE8C4;
extern s32 D_L32_001DE8A8;
extern s32 D_L32_001DE8AC;
extern f32 D_L32_001DE8B0;
extern f32 D_L32_001DE8D0;
extern f32 D_L32_001DE8D8;
extern u8 D_L32_002A2E40[];
extern void func_L02_003BAFA0(void *, void *, void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(f32, s32, s32);
extern s32 func_00382498(s32, s32);
extern f32 func_L03_0034B440(f32, f32, f32, s32, s32, s32);
extern f32 func_L03_0034B148(f32, s32, s32);
extern f32 func_003C4088(f32, f32, f32);

void func_L32_003A7F48(u8 *a0, u8 *a1) {
    u8 *o;
    u8 *v;
    s32 t;
    f32 k, y;
    s32 w;
    f32 r, f1, lo, x, one;
    s32 al;
    s32 hi;
    if (a1 != 0) {
        o = *(u8 **)a1;
        t = *(s32 *)(a1 + 4);
        if (o != 0) {
            v = *(u8 **)(o + 0x68);
            if (v != 0 && t != 0) {
                if (*(u16 *)(a1 + 0xA) & 1) {
                    func_L02_003BAFA0(o, D_L32_002A2E40, a0 + 0x10, a1 + 0x14, 0.0f);
                    *(f32 *)(a0 + 0x14) = *(f32 *)(a0 + 0x14) + D_L32_001DE8C0;
                    *(f32 *)(a1 + 0x10) = 0.0f;
                    k = D_L32_001DE8D4;
                    *(f32 *)(a1 + 0x18) = k * *(f32 *)(v + 0x90);
                    *(f32 *)(a1 + 0x1C) = k * *(f32 *)(v + 0x98);
                    w = func_0038DBD8(func_003824E0(0.0f, 1.0f), D_L32_001DE8A8, D_L32_001DE8AC);
                    y = func_003824E0(D_L32_001DE8C8, D_L32_001DE8C4);
                    *(s32 *)(a0 + 4) = w;
                    *(f32 *)(a0 + 0xC) = y;
                    *(s16 *)(a1 + 0xC) = func_00382498(0, *(s16 *)(a1 + 8));
                }
                one = 1.0f;
                r = func_L03_0034B440((f32)*(s16 *)(a0 + 0xA), (f32)*(s16 *)(a1 + 8), one, 1, 0, 0);
                if (*(s16 *)(a0 + 0xA) < *(s16 *)(a1 + 0xC)) {
                    *(f32 *)(a1 + 0x10) = *(f32 *)(a1 + 0x10) + D_L32_001DE8B0;
                    *(f32 *)(a0 + 0x18) = *(f32 *)(a0 + 0x18) + *(f32 *)(a1 + 0x10);
                    *(f32 *)(a0 + 0x10) = *(f32 *)(a0 + 0x10) + *(f32 *)(a1 + 0x18);
                    *(f32 *)(a0 + 0x18) = *(f32 *)(a0 + 0x18) + *(f32 *)(a1 + 0x1C);
                }
                f1 = (one - r) / D_L32_001DE8D0;
                if (one < f1) {
                    al = 0x80000000;
                } else {
                    al = (s32)(f1 * 128.0f) << 24;
                }
                *(u32 *)(a0 + 4) = (*(u32 *)(a0 + 4) & 0xFFFFFF) | al;
                hi = *(u16 *)(a1 + 0xE) >> 8;
                lo = (f32)(*(u16 *)(a1 + 0xE) & 0xFF);
                x = D_L32_001DE8D8 * (f32)*(s16 *)(a1 + 8) * (f32)hi * 0.00390625f;
                x = lo + x;
                x = lo + x;
                *(u8 *)(a0 + 8) = func_003C4088(lo, x, func_L03_0034B148(0.0f, *(s16 *)(a0 + 0xA), *(s16 *)(a1 + 8)));
            }
        }
    }
}
