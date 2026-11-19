/* functional: high. Draft (31 diff, float regalloc only) re-verified against PAL asm. func_L03_0034B148(f32, s32 cur, s32 max): $a1 (a1->0x8) reaches it by register passthrough in retail, passed explicitly here; func_L03_0034B440 prototype reordered (f32,f32,f32,s32,s32,s32). The duplicated func_003C4088 call in each clamp is retail's (recomputes when the ratio is <= 1); kept so the call trace matches. */

extern f32 D_L32_001DED60;
extern s32 D_L32_001DED54;
extern f32 D_L32_001DED74;
extern s32 D_L32_001DED1C;
extern s32 D_L32_001DED20;
extern s32 D_L32_001DED50;
extern f32 D_L32_001DED8C;
extern f32 D_L32_001DED88;
extern f32 D_L32_001DED7C;
extern f32 D_L32_001DED78;
extern f32 D_L32_001DED84;
extern f32 D_L32_001DED80;
extern f32 D_L32_001DEDC8;
extern f32 D_L32_001DECF0;
extern f32 D_L32_001DED70;
extern f32 D_L32_001DED6C;
extern u8 D_L32_001E2440[];
extern void func_L32_003B41E8(void *, void *, f32, f32, f32 *);
extern void func_00382580(f32 *, f32, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_0038DBD8(f32, s32, s32);
extern f32 func_L03_0034B440(f32, f32, f32, s32, s32, s32);
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_L03_0034B148(f32, s32, s32);


void func_L32_003B43F8(u8 *a0, u8 *a1) {
    u8 buf[0x30] __attribute__((aligned(16)));
    u8 *m;
    u8 *v;
    u8 *p;
    f32 f;
    f32 f20;
    f32 f21;
    f32 f22;
    f32 f23;
    f32 lo;
    f32 hi;
    f32 f24;
    s32 i;
    f32 x;
    f32 y;

    if (a1 != 0) {
        m = *(u8 **)a1;
        if (m != 0 && D_L32_001E2440 != 0 && (v = *(u8 **)(m + 0x68)) != 0) {
            p = a1 + 0x10;
            if (*(u16 *)(a1 + 0xA) & 1) {
                f = *(f32 *)(v + 0x34) - *(f32 *)(v + 0x3C) * 0.3f;
                if (f < 0.0f) {
                    f = 0.0f;
                }
                *(f32 *)(a1 + 0x10) = f;
                func_L32_003B41E8(m, buf, -1.0f, 0.01f, (f32 *)p);
                func_00382580((f32 *)(a0 + 0x10), 0.0f, D_L32_001DED60);
                vec_add_ab(a0 + 0x10, a0 + 0x10, buf);
                *(f32 *)(a0 + 0x14) = *(f32 *)(a0 + 0x14) + D_L32_001DED74;
                *(f32 *)(a1 + 0x14) = func_003824E0(0.0f, 1.0f);
                if (*(s32 *)(v + 0x40) != 0) {
                    i = D_L32_001DED1C;
                } else {
                    i = D_L32_001DED20;
                }
                i = func_0038DBD8(func_003824E0(0.0f, 1.0f), D_L32_001DED50, i);
                x = D_L32_001DED8C;
                y = D_L32_001DED88;
                *(s32 *)(a0 + 4) = i;
                f = func_003824E0(x, y);
                *(f32 *)(a1 + 0x18) = f;
                *(f32 *)(a0 + 0xC) = f;
                a0[3] = *(u8 *)&D_L32_001DED54;
            }
            f22 = func_L03_0034B440((f32)*(s16 *)(a0 + 0xA), (f32)*(s16 *)(a1 + 8), 1.0f, 1, 0, 0);
            f24 = 1.0f - f22;
            f23 = f24 / (1.0f - func_003C4088(D_L32_001DED7C, D_L32_001DED78, *(f32 *)(a1 + 0x14))) > 1.0f ? 1.0f : f24 / (1.0f - func_003C4088(D_L32_001DED7C, D_L32_001DED78, *(f32 *)(a1 + 0x14)));
            f21 = 1.0f - f22;
            f20 = f21 / (1.0f - func_003C4088(D_L32_001DED84, D_L32_001DED80, *(f32 *)(a1 + 0x14))) > 1.0f ? 1.0f : f21 / (1.0f - func_003C4088(D_L32_001DED84, D_L32_001DED80, *(f32 *)(a1 + 0x14)));
            func_L32_003B41E8(m, buf, -1.0f, 0.01f, (f32 *)p);
            f = *(f32 *)(a1 + 0x10) + D_L32_001DEDC8 * f20 * D_L32_001DECF0;
            if (1.0f < f) {
                f = 1.0f;
            }
            *(f32 *)(a1 + 0x10) = f;
            func_L32_003B41E8(m, buf + 0x10, -1.0f, 0.01f, (f32 *)p);
            vec_sub_ba(buf + 0x20, buf + 0x10, buf);
            vec_add_ba(a0 + 0x10, buf + 0x20, a0 + 0x10);
            lo = (f32)(*(u16 *)(a1 + 0xE) & 0xFF);
            hi = lo + D_L32_001DED70 * (f32)*(s16 *)(a1 + 8) * (f32)(*(u16 *)(a1 + 0xE) >> 8) * 0.00390625f;
            hi = lo + hi;
            a0[8] = (s32)func_003C4088(lo, hi, func_L03_0034B148(0.0f, *(s16 *)(a0 + 0xA), *(s16 *)(a1 + 8)));
            *(f32 *)(a0 + 0xC) = *(f32 *)(a1 + 0x18) * f23;
            *(s32 *)(a0 + 4) = (*(s32 *)(a0 + 4) & 0xFFFFFF) | ((s32)(D_L32_001DED6C * f23) << 24);
        }
    }
}

