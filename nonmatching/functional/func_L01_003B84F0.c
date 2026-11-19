/* functional: medium. Not byte-matched. abs.s on vec[2] written as a conditional negate; gp-relative level globals named D_L01_001DE7CC.. (gp+0x1F1C..0x1F3C). Arg shapes of func_L01_003D8E60/003303B8/00475C60 follow the EABI independent int/float register counters and match sibling call sites (L18_00322F80). */
extern f32 D_L01_001DE7CC;
extern s32 D_L01_001DE7D4;
extern f32 D_L01_001DE7D8;
extern f32 D_L01_001DE7DC;
extern f32 D_L01_001DE7E0;
extern f32 D_L01_001DE7E8;
extern f32 D_L01_001DE7EC;
extern u8 D_00221098[];
extern void func_00382580(void *, f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_003D8E60(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern s32 func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L01_003B84F0(u8 *m, s32 count, s32 a2, s32 a3, s32 a4, f32 scale) {
    f32 vec[4] __attribute__((aligned(16)));
    s32 kind, r16;
    f32 f20, f21, r;
    u8 *particle;

    func_00382580(vec, D_L01_001DE7CC * 0.5f * 0.020000001f, D_L01_001DE7CC * 0.020000001f);
    func_L01_003D8E60(m, vec, D_L01_001DE7D4, 7, 5, count, a2, 0, -100000.0f, scale * 3.5f, -5.0f);
    if (a3 > 0 && func_00382468(a3) == 0) {
        func_L01_003303B8(m, 0, 2, 2, 2, 1, 2, 1, scale, 0.0f, 0.0f, 0.0f,
                          0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF,
                          0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    }
    if (count > 0) {
        do {
            func_00382580(vec, D_L01_001DE7D8 * 0.5f * 0.020000001f, D_L01_001DE7D8 * 0.020000001f);
            kind = (a4 * 5 + 2) / 6;
            r16 = func_00382498(-2, 2);
            f20 = D_L01_001DE7E0 * scale * 210000.0f;
            r = func_003824E0(D_L01_001DE7E8 * 0.6f, D_L01_001DE7E8);
            particle = func_L01_00475C60(m, vec, kind, r16, 0x7F407FFF, 0x407FFF, f20, f20, r, 0);
            if (particle != 0) {
                particle[9] = 0xF2;
                particle[2] = (*(u8 **)(D_00221098 + 0x184))[3];
            }
            if (func_00382468(5) == 0) {
                func_0038CE20(vec, vec, D_L01_001DE7DC);
                vec[2] = vec[2] < 0.0f ? -vec[2] : vec[2];
                r16 = func_00382498(-2, 2);
                f20 = D_L01_001DE7E0 * scale;
                f21 = f20 * 0.04f;
                f20 = f20 * 0.4f;
                f21 = f21 * 210000.0f;
                f20 = f20 * 210000.0f;
                r = func_003824E0(D_L01_001DE7EC * 0.6f, D_L01_001DE7EC);
                particle = func_L01_00475C60(m, vec, kind, r16, 0x7F0048FF, 0x48FF, f20, f21, r, 0);
                if (particle != 0) {
                    particle[9] = 0xF2;
                    particle[2] = (*(u8 **)(D_00221098 + 0x184))[3];
                }
            }
            count--;
        } while (count != 0);
    }
}
