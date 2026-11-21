/* functional: medium. Particle p and entry q layouts guessed (q+0 owner obj, q+4 active, q+8 life, q+0xA flags bit0 = needs init, q+0xE packed range). Callees func_0038D098/D0B0/DB48/func_L03_0034B148/func_003C4088 inferred as float helpers. Init branch taken whenever q+0xA bit0 set (as retail). */
/* localdecomp:start func_L03_003B6370 */
typedef int Q_3B6370 __attribute__((mode(TI)));
__asm__(".extern D_001DEA34_sda, 4");
__asm__(".extern D_001DEA30_sda, 4");
extern s32 D_001DEA34_sda;
extern f32 D_001DEA30_sda;
extern u8 *D_L03_0021F2D4;
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_L03_0034B148(f32, s32);
extern f32 func_003C4088(f32, f32, f32);

void func_L03_003B6370(u8 *p, u8 *q) {
    u8 *obj;
    u8 *s;
    s32 kind;
    f32 f20;
    f32 f21;
    f32 d;
    if (q == 0) return;
    obj = *(u8 **)q;
    if (obj == 0) return;
    s = *(u8 **)(obj + 0x68);
    if (*(s32 *)(q + 4) == 0) return;
    if ((u8)(obj[0x20] + 3) < 3) {
        *(s16 *)(p + 0xA) = 0;
        return;
    }
    if (s == 0) {
        *(s16 *)(p + 0xA) = 0;
        return;
    }
    if (*(u16 *)(q + 0xA) & 1) {
        f21 = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        f20 = func_003824E0(0.25f, 0.6f);
        *(Q_3B6370 *)(p + 0x10) = *(Q_3B6370 *)(obj + 0x10);
        *(f32 *)(p + 0x10) = *(f32 *)(p + 0x10) + f20 * func_0038D098(f21);
        *(f32 *)(p + 0x14) = *(f32 *)(p + 0x14) + f20 * func_0038D098(f21);
        *(f32 *)(p + 0x18) = *(f32 *)(p + 0x18) + f20 * func_0038D0B0(f21);
        *(f32 *)(q + 0x10) = *(f32 *)(obj + 0x10);
        *(f32 *)(q + 0x14) = *(f32 *)(obj + 0x14);
        *(f32 *)(q + 0x18) = *(f32 *)(obj + 0x18);
        kind = *(s32 *)(s + 0x24);
        if (kind == 0 || kind == 3 || kind == 6) {
            *(s32 *)(p + 4) = D_001DEA34_sda;
            *(f32 *)(p + 0xC) = 63000.00390625f;
            p[2] = *D_L03_0021F2D4;
            *(s16 *)(p + 0xA) = 30;
        } else {
            *(s32 *)(p + 4) = 0x88028820;
            p[2] = func_00382498(1, 2);
            *(f32 *)(p + 0xC) = D_001DEA30_sda * 210000.0f;
            *(s16 *)(p + 0xA) = (func_00382498(20, 120) * 5 + 2) / 6;
        }
        *(f32 *)(s + 0x40) = *(f32 *)(p + 0xC);
        *(s32 *)(p + 4) = (*(s32 *)(p + 4) & 0xFFFFFF)
            | ((s32)((f32)*(s16 *)(p + 0xA) * 128.0f / (f32)*(s16 *)(q + 8)) << 24);
        {
            u16 w = *(u16 *)(q + 0xE);
            s32 h8 = *(s16 *)(q + 8);
            f32 hi = (f32)(s32)(w >> 8);
            f32 lo = (f32)(s32)(w & 0xFF);
            f32 hi2 = ((f32)h8 * hi) * 0.00390625f;
            d = func_L03_0034B148(0.0f, h8);
            p[8] = (s32)func_003C4088(lo, lo + hi2, d);
        }
    }
    *(s32 *)(p + 4) = (*(s32 *)(p + 4) & 0xFFFFFF)
        | ((s32)((f32)*(s16 *)(p + 0xA) * 128.0f / (f32)*(s16 *)(q + 8)) << 24);
    if (s != 0) {
        kind = *(s32 *)(s + 0x24);
        if (kind == 0 || kind == 3 || kind == 6) {
            *(f32 *)(p + 0xC) = *(f32 *)(p + 0xC) + (210000.0f - *(f32 *)(s + 0x40)) / (f32)*(s16 *)(q + 8);
        }
    }
    *(f32 *)(p + 0x10) = *(f32 *)(p + 0x10) + (*(f32 *)(obj + 0x10) - *(f32 *)(q + 0x10));
    *(f32 *)(q + 0x10) = *(f32 *)(obj + 0x10);
    *(f32 *)(p + 0x14) = *(f32 *)(p + 0x14) + (*(f32 *)(obj + 0x14) - *(f32 *)(q + 0x14));
    *(f32 *)(q + 0x14) = *(f32 *)(obj + 0x14);
    *(f32 *)(p + 0x18) = *(f32 *)(p + 0x18) + (*(f32 *)(obj + 0x18) - *(f32 *)(q + 0x18));
    *(f32 *)(q + 0x18) = *(f32 *)(obj + 0x18);
}
/* localdecomp:end func_L03_003B6370 */
