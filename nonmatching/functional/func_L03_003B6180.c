/* functional: high. Written from PAL asm. gp slots D_001DEA10-2C (mix of f32 and s32 args), kind 6 toggles s+0x3C between two sda floats when func_003C4138 returns 0. */
/* localdecomp:start func_L03_003B6180 */
__asm__(".extern D_001DEA20_sda, 4");
__asm__(".extern D_001DEA04_sda, 4");
__asm__(".extern D_001DE9FC_sda, 4");
__asm__(".extern D_001DEA00_sda, 4");
__asm__(".extern D_001DEA28_sda, 4");
__asm__(".extern D_001DEA2C_sda, 4");
__asm__(".extern D_001DEA24_sda, 4");
__asm__(".extern D_001DEA1C_sda, 4");
__asm__(".extern D_001DEA14_sda, 4");
__asm__(".extern D_001DEA18_sda, 4");
__asm__(".extern D_001DEA10_sda, 4");
extern f32 D_001DEA20_sda;
extern f32 D_001DEA04_sda;
extern f32 D_001DE9FC_sda;
extern f32 D_001DEA00_sda;
extern s32 D_001DEA28_sda;
extern s32 D_001DEA2C_sda;
extern s32 D_001DEA24_sda;
extern s32 D_001DEA1C_sda;
extern s32 D_001DEA14_sda;
extern s32 D_001DEA18_sda;
extern s32 D_001DEA10_sda;
extern u8 D_L03_001E1DC8[];
extern f32 func_0038DAB8(f32, f32);
extern void func_L03_0034B248(void *, u8 *);
extern f32 func_003C4138(void *, f32, f32);
extern void func_003D9508(void *, f32, f32, f32, s32, s32, s32);

void func_L03_003B6180(u8 *m) {
    u8 *s = *(u8 **)(m + 0x68);
    f32 a = func_0038DAB8(0.0f, *(f32 *)(s + 0x34) * 0.017453292f);
    s32 kind = *(s32 *)(s + 0x24);
    f32 t;
    if (kind == 0 || kind == 3 || kind == 6) {
        func_L03_0034B248(D_L03_001E1DC8, m);
        if (kind == 6) {
            if (func_003C4138(s + 0x38, *(f32 *)(s + 0x3C), D_001DEA04_sda) == 0.0f) {
                if (*(f32 *)(s + 0x3C) == D_001DE9FC_sda) *(f32 *)(s + 0x3C) = D_001DEA00_sda;
                else *(f32 *)(s + 0x3C) = D_001DE9FC_sda;
            }
            func_003D9508(m + 0x10, *(f32 *)(s + 0x38), 0.0f, -a, D_001DEA28_sda, D_001DEA2C_sda, 1);
            func_003D9508(m + 0x10, *(f32 *)(s + 0x38) * 0.9f, 0.0f, a, D_001DEA24_sda, D_001DEA2C_sda, 1);
        }
    } else {
        func_L03_0034B248(D_L03_001E1DC8, m);
        func_003D9508(m + 0x10, D_001DEA20_sda, 0.0f, -a, D_001DEA1C_sda, D_001DEA14_sda, 1);
        func_003D9508(m + 0x10, D_001DEA20_sda, 0.0f, a, D_001DEA18_sda, D_001DEA10_sda, 1);
    }
    t = *(f32 *)(s + 0x34) + 1.0f;
    *(f32 *)(s + 0x34) = t;
    if (359.0f < t) {
        *(s32 *)(s + 0x34) = 0;
    } else if (t < 0.0f) {
        *(f32 *)(s + 0x34) = 359.0f;
    }
}
/* localdecomp:end func_L03_003B6180 */
