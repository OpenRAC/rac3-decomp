/* functional: high. Written from the PAL asm, every branch and delay slot traced; fabs as a plain compare; 115 byte diffs (scheduling). */
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern s32 D_001427F0[];
extern u8 D_L01_002C5600[];
extern s32 D_L01_001D673C;
__asm__(".extern D_L01_001D673C, 16");
extern f32 func_L01_00451580(void *);
extern s32 func_L01_0040E020(void *);
extern f32 func_L01_0040E570(void *, void *);

s32 func_L01_0030F0B0(u8 *obj, s32 flag) {
    u8 *h = D_001A4BE0;
    u8 *vars;
    f32 d;
    s32 idx;

    if (*(s32 *)(h + 0x2850) == 0) {
        return 0;
    }
    vars = *(u8 **)(obj + 0x68);
    if (D_L01_001D673C != 0) {
        if (func_L01_00451580(obj + 0x10) < *(f32 *)(vars + 0x74) - 2.0f) {
            return 1;
        }
    } else {
        if (*(f32 *)(obj + 0x18) < *(f32 *)(vars + 0x74) - 2.0f) {
            return 1;
        }
    }
    if (h[0x25F3] != 0) {
        return 1;
    }
    idx = *(s32 *)(vars + 0x68);
    if (!(D_001427F0[idx] < *(u16 *)(D_L01_002C5600 + D_001425C0[idx] * 0xF0 + 0x8A))) {
        return 0;
    }
    if (vars[0x5C] != 0 || flag != 0) {
        if (func_L01_0040E020(vars + 0x78) == 0) {
            return 1;
        }
        d = *(f32 *)(obj + 0x18) - *(f32 *)(h + 0x88);
        if (d < 0.0f) {
            d = -d;
        }
        if (*(f32 *)(h + 0x2828) < d) {
            return 0;
        }
        if (*(f32 *)(h + 0x2824) * *(f32 *)(h + 0x2824) < func_L01_0040E570(obj + 0x10, h + 0x80)) {
            return 0;
        }
        return 1;
    }
    d = *(f32 *)(obj + 0x18) - *(f32 *)(h + 0x88);
    if (d < 0.0f) {
        d = -d;
    }
    if (!(d < *(f32 *)(h + 0x2828))) {
        return 0;
    }
    if (func_L01_0040E570(obj + 0x10, h + 0x80) < *(f32 *)(h + 0x2824) * *(f32 *)(h + 0x2824)) {
        vars[0x78] = 3;
    }
    return 0;
}
