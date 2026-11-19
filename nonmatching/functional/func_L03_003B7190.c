/* functional: medium. Same shape as func_L03_003B6370 but unconditional colour 0x880220/size 210000 and no kind switch. q layout guessed as there. Skip check on owner mode byte 0xFE/0xFF. */
/* localdecomp:start func_L03_003B7190 */
typedef int Q_3B7190 __attribute__((mode(TI)));
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_L03_0034B148(f32, s32);
extern f32 func_003C4088(f32, f32, f32);

void func_L03_003B7190(u8 *p, u8 *q) {
    u8 *obj;
    f32 f20;
    f32 f21;
    if (q == 0) return;
    obj = *(u8 **)q;
    if (obj == 0) return;
    if (*(s32 *)(q + 4) == 0) return;
    if ((u8)(obj[0x20] + 2) < 2) {
        *(s16 *)(p + 0xA) = 0;
        return;
    }
    if (*(u16 *)(q + 0xA) & 1) {
        f21 = func_0038DB48(func_003824E0(0.0f, 6.2831855f));
        f20 = func_003824E0(0.25f, 0.6f);
        *(Q_3B7190 *)(p + 0x10) = *(Q_3B7190 *)(obj + 0x10);
        *(f32 *)(p + 0x10) = *(f32 *)(p + 0x10) + f20 * func_0038D098(f21);
        *(f32 *)(p + 0x14) = *(f32 *)(p + 0x14) + f20 * func_0038D098(f21);
        *(f32 *)(p + 0x18) = *(f32 *)(p + 0x18) + f20 * func_0038D0B0(f21);
        *(f32 *)(q + 0x10) = *(f32 *)(obj + 0x10);
        *(f32 *)(q + 0x14) = *(f32 *)(obj + 0x14);
        *(f32 *)(q + 0x18) = *(f32 *)(obj + 0x18);
        *(s32 *)(p + 4) = 0x88880220;
        *(s32 *)(p + 4) = 0x880220 | ((s32)((f32)*(s16 *)(p + 0xA) * 128.0f / (f32)*(s16 *)(q + 8)) << 24);
        {
            u16 w = *(u16 *)(q + 0xE);
            s32 h8 = *(s16 *)(q + 8);
            f32 hi = (f32)(s32)(w >> 8);
            f32 lo = (f32)(s32)(w & 0xFF);
            f32 hi2 = ((f32)h8 * hi) * 0.00390625f;
            p[8] = (s32)func_003C4088(lo, lo + hi2, func_L03_0034B148(0.0f, h8));
        }
        *(f32 *)(p + 0xC) = 210000.0f;
    }
    *(s32 *)(p + 4) = (*(s32 *)(p + 4) & 0xFFFFFF)
        | ((s32)((f32)*(s16 *)(p + 0xA) * 128.0f / (f32)*(s16 *)(q + 8)) << 24);
    *(f32 *)(p + 0x10) = *(f32 *)(p + 0x10) + (*(f32 *)(obj + 0x10) - *(f32 *)(q + 0x10));
    *(f32 *)(q + 0x10) = *(f32 *)(obj + 0x10);
    *(f32 *)(p + 0x14) = *(f32 *)(p + 0x14) + (*(f32 *)(obj + 0x14) - *(f32 *)(q + 0x14));
    *(f32 *)(q + 0x14) = *(f32 *)(obj + 0x14);
    *(f32 *)(p + 0x18) = *(f32 *)(p + 0x18) + (*(f32 *)(obj + 0x18) - *(f32 *)(q + 0x18));
    *(f32 *)(q + 0x18) = *(f32 *)(obj + 0x18);
}
/* localdecomp:end func_L03_003B7190 */
