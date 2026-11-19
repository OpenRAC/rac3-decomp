/* functional: high. EXACT: byte-identical at level_01, level_02, level_05 under the file flags. */
/* localdecomp:start func_L01_0037A880 */
extern u8 D_L01_001E29C0[];
extern f32 D_L01_001DDB14;
__asm__(".extern D_L01_001DDB14, 4");
extern f32 D_L01_001DDB18;
__asm__(".extern D_L01_001DDB18, 4");
extern f32 D_L01_001DDB1C;
__asm__(".extern D_L01_001DDB1C, 4");
extern f32 D_L01_001DDB20;
__asm__(".extern D_L01_001DDB20, 4");
extern s32 D_L01_001DDB44;
__asm__(".extern D_L01_001DDB44, 4");
extern s32 D_L01_001DDB4C;
__asm__(".extern D_L01_001DDB4C, 4");
extern s32 D_L01_001DDB50;
__asm__(".extern D_L01_001DDB50, 4");
extern s32 D_L01_001DDB54;
__asm__(".extern D_L01_001DDB54, 4");
static inline u32 fade_0037A880(u32 color, f32 fade) {
    if (fade != 1.0f) {
        u8 a = (color >> 24) * fade;
        s32 alpha = 127;
        if (a < 128) alpha = a;
        color = (alpha << 24) | (color & 0xFFFFFF);
    }
    return color;
}
void func_L01_0037A880(u8 *obj) {
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_L01_0040E570(void *, void *);
    extern void func_L01_0037BE80(void *, void *, s32, s32, u32, f32, f32, f32, f32, f32, f32, s32);
    extern void func_L01_0037BCF8(void *, void *, s32, u32, s32, f32, f32, f32);
    u8 *vars = *(u8 **)(obj + 0x68);
    f32 d, fade1, fade2, t;
    u8 *pos;
    *(f32 *)(vars + 0x44) = func_0038DAB8(*(f32 *)(vars + 0x44), func_003824E0(-0.5f, -1.0f) * 0.017453292f);
    *(f32 *)(vars + 0x34) = func_0038DAB8(*(f32 *)(vars + 0x34), func_003824E0(-1.0f, -2.0f) * 0.017453292f);
    *(f32 *)(vars + 0x48) = func_0038DAB8(*(f32 *)(vars + 0x48), func_003824E0(-1.0f, -1.5f) * 0.017453292f);
    *(f32 *)(vars + 0x38) = func_0038DAB8(*(f32 *)(vars + 0x38), func_003824E0(1.5f, 2.5f) * 0.017453292f);
    *(f32 *)(vars + 0x4C) = func_0038DAB8(*(f32 *)(vars + 0x4C), func_003824E0(-0.5f, -1.5f) * 0.017453292f);
    *(f32 *)(vars + 0x3C) = func_0038DAB8(*(f32 *)(vars + 0x3C), func_003824E0(0.5f, 1.5f) * 0.017453292f);
    d = func_L01_0040E570(obj + 0x10, D_L01_001E29C0);
    if (d < D_L01_001DDB18) t = (d - D_L01_001DDB14) / (D_L01_001DDB18 - D_L01_001DDB14);
    else t = 1.0f;
    fade1 = t < 0.0f ? 0.0f : t;
    if (d < D_L01_001DDB20) t = (d - D_L01_001DDB1C) / (D_L01_001DDB20 - D_L01_001DDB1C);
    else t = 1.0f;
    fade2 = t < 0.0f ? 0.0f : t;
    pos = obj + 0x10;
    if (D_L01_001DDB44) {
        func_L01_0037BE80(obj, pos, 71, 72, 0x8F800032, 1.0f, 1.0f, 1.7f, *(f32 *)(vars + 0x44), *(f32 *)(vars + 0x34), 0.0f, 0);
    }
    if (fade1 > 0.0f && D_L01_001DDB50) {
        func_L01_0037BE80(obj, pos, 71, 72, fade_0037A880(0x8F204080, fade1), 1.0f, 1.0f, 1.7f, *(f32 *)(vars + 0x48), *(f32 *)(vars + 0x38), 0.05f, 0);
        func_L01_0037BE80(obj, pos, 71, 72, fade_0037A880(0x8F7F2020, fade1), 1.0f, 1.0f, 1.7f, *(f32 *)(vars + 0x4C), *(f32 *)(vars + 0x3C), 0.1f, 0);
    }
    func_L01_0037BCF8(obj, pos, 27, 0x2F2040FF, 1, 1.15f, 0.0f, *(f32 *)(vars + 0x34));
    func_L01_0037BCF8(obj, pos, 27, 0x2F2040FF, 1, 1.15f, 0.0f, *(f32 *)(vars + 0x38));
    if (fade2 > 0.0f && D_L01_001DDB4C) {
        func_L01_0037BCF8(obj, pos, 76, fade_0037A880(0x7F320080, fade2), 1, 0.5f, 0.0f, -*(f32 *)(vars + 0x38));
        func_L01_0037BCF8(obj, pos, 76, fade_0037A880(0x7F050530, fade2), 1, 0.2f, 0.0f, *(f32 *)(vars + 0x38));
    }
    if (fade2 > 0.0f && D_L01_001DDB54) {
        func_L01_0037BCF8(obj, pos, 75, fade_0037A880(0x7F204080, fade2), 0, 0.6f, 0.0f, *(f32 *)(vars + 0x34));
    }
}
/* localdecomp:end func_L01_0037A880 */
