/* functional: high. 200 instructions differ (store scheduling only); same fields, constants and calls as retail (constants read from the PAL assembly). */
typedef int u128_t __attribute__((mode(TI)));
extern s32 D_L01_001D545C;
extern f32 D_L01_001DAA30;
__asm__(".extern D_L01_001D545C, 4");
__asm__(".extern D_L01_001DAA30, 4");
extern u8 D_0014275B[];
extern f32 D_L01_002F1510[];
extern s32 func_L01_0041A4F0(void);
extern void func_0038CB78(void *, s32, s32);
extern void func_L01_00456160(void *, void *);
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C7C38(void *);

s32 func_L01_003CA6D8(u8 *self, u8 *other) {
    u8 *s0;
    u8 *o;
    u8 *t4;
    u8 *p;
    s32 a1;
    s32 a;
    f32 f20;
    f32 m;
    u16 fl;

    if (self[0x20] >= 2 || self == 0) {
        return 0;
    }
    t4 = *(u8 **)(other + 0x68);
    fl = *(u16 *)(self + 0x34) & 0xFFBC;
    o = *(u8 **)(self + 0x24);
    *(u16 *)(self + 0x34) = fl;
    s0 = *(u8 **)(self + 0x68);
    *(u16 *)(self + 0x34) = fl | (*(u16 *)(o + 0x44) & 0x1000);
    *(s32 *)(self + 0x98) = *(s32 *)(o + 0x10);
    *(f32 *)(s0 + 0xF4) = 0.010000000707805157f;
    *(f32 *)(s0 + 0xF8) = 0.014000000432133675f;
    *(f32 *)(s0 + 0xFC) = 0.000800000037997961f;
    s0[0xE0] = 0x1B;
    s0[0xE6] = 8;
    *(f32 *)(s0 + 0x104) = 0.5f;
    *(f32 *)(s0 + 0x10C) = 0.15000000596046448f;
    *(f32 *)(s0 + 0xF0) = 0.020000001415610313f;
    s0[0x14B] = 0xFF;
    s0[0x142] = 6;
    s0[0x143] = 0x10;
    s0[0x119] = 1;
    *(f32 *)(s0 + 0x190) = 0.4000000059604645f;
    *(f32 *)(s0 + 0x194) = 0.30000001192092896f;
    *(f32 *)(s0 + 0x198) = 2.200000047683716f;
    *(s16 *)(s0 + 0x108) = 0;
    s0[0x118] = 0xFF;
    s0[0xE1] = 8;
    s0[0xE2] = 8;
    *(f32 *)(s0 + 0x100) = 0.5f;
    s0[0x147] = 1;
    s0[0x148] = 0;
    s0[0x149] = 0;
    s0[0x14A] = 0;
    *(f32 *)(s0 + 0x19C) = 2.0f;
    *(f32 *)(s0 + 0x1A0) = 1.5707964f;
    *(f32 *)(s0 + 0x1C0) = 3.1415927f;
    *(f32 *)(s0 + 0x1BC) = 0.003920000046491623f;
    *(f32 *)(s0 + 0x1C4) = 2.0f;
    if (D_L01_001D545C == 4) {
        a = *(s16 *)(self + 0xB2);
        if (a == 0x20 || (u16)(*(u16 *)(self + 0xB2) - 0x22B) < 7 || a == 0x4ED) {
            *(f32 *)(s0 + 0x190) = 0.7799999713897705f;
        }
    }
    s0[0x38] = 1;
    *(f32 *)(s0 + 0x40) = 0.5f;
    s0[0x39] = 0;
    s0[0x3F] = 0;
    a1 = *(s16 *)(t4 + 0x7A);
    if (a1 == -1) {
        if (*(s16 *)(s0 + 0x34) == 0 || *(f32 *)(s0 + 0x30) <= 0.0f) {
            if (func_L01_0041A4F0() != 0) {
                if (D_L01_001D545C == 7 && D_0014275B[0] == 0) {
                    m = D_L01_001DAA30;
                } else {
                    m = D_L01_002F1510[D_L01_001D545C];
                }
                *(s16 *)(s0 + 0x34) = (s32)(m * 30.0f);
            } else {
                *(s16 *)(s0 + 0x34) = 0x1E;
            }
        }
    } else {
        f20 = (f32)a1;
        if (func_L01_0041A4F0() != 0) {
            if (D_L01_001D545C == 7 && D_0014275B[0] == 0) {
                m = D_L01_001DAA30;
            } else {
                m = D_L01_002F1510[D_L01_001D545C];
            }
            *(s16 *)(s0 + 0x34) = (s32)(f20 * m);
        } else {
            *(s16 *)(s0 + 0x34) = (s32)f20;
        }
    }
    s0[0x58] = 0x14;
    s0[0x5A] = 0xE;
    *(f32 *)(s0 + 0x30) = (f32) * (s16 *)(s0 + 0x34);
    *(u128_t *)(s0 + 0x4B0) = *(u128_t *)(self + 0x10);
    *(u128_t *)(s0 + 0x4C0) = *(u128_t *)(self + 0xF0);
    func_0038CB78(s0 + 0x4D0, 0, 0x80);
    if (*(s32 *)(s0 + 0x550) == 0) {
        p = func_003C24B0(0x19C1, 0x80);
        *(u8 **)(s0 + 0x550) = p;
        func_L01_00456160(p, self);
    }
    func_L01_004450F0(self, 2, -1);
    func_003C7C38(self);
    return 1;
}
