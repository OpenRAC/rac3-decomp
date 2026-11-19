/* functional: high. functional: high. gp-relative table addressing is lui/addiu in this C instead of $gp; same addresses and values */
typedef int u128_3CD878 __attribute__((mode(TI)));
extern void func_003C5180(void *, void *, s32);
extern u8 *func_003C24B0(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_L01_0046B458(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);
extern void func_L01_00470C78(void *, s32, f32, f32, s32, s32, s32, void *, s32, s32, s32, s32);
extern void func_L01_0040C7A0(void *);
extern u8 D_L01_001D66B0[];
extern s32 D_001DF0A0_sda;
extern s32 D_001DF0A4_sda;
extern s32 D_001DF0A8_sda;
extern s32 D_001DF0B0_sda[4];
extern s32 D_001DF0F0_sda[8];
extern f32 D_001DF110_sda[8];
extern f32 D_001DF130_sda[8];
extern s32 D_001DF150_sda[8];
__asm__(".extern D_001DF0A0_sda, 4");
__asm__(".extern D_001DF0A4_sda, 4");
__asm__(".extern D_001DF0A8_sda, 4");
__asm__(".extern D_001DF0B0_sda, 4");
__asm__(".extern D_001DF0F0_sda, 4");
__asm__(".extern D_001DF110_sda, 4");
__asm__(".extern D_001DF130_sda, 4");
__asm__(".extern D_001DF150_sda, 4");

u8 *func_L01_003CD878(s32 owner, u8 *pos, u8 *vec, s32 arg3, s32 arg4, f32 farg) {
    u8 tmp10[16];
    u8 tmp20[16];
    u8 *obj;
    u8 *vars;
    s32 t;
    s32 i;

    func_003C5180(pos, tmp10, 1);
    obj = func_003C24B0(0x1B3C, 0x100);
    if (obj == 0) {
        return obj;
    }
    vars = *(u8 **)(obj + 0x68);
    if (arg4 == -1) {
        t = D_001DF0A8_sda;
    } else {
        t = arg4;
    }
    *(s32 *)(vars + 0xD0) = (t * 5 + 2) / 6;
    *(s16 *)(obj + 0x32) = 0xFF;
    *(u8 *)(obj + 0x30) = 0xFF;
    *(u8 *)(obj + 0x20) = 0;
    *(u128_3CD878 *)(obj + 0x10) = *(u128_3CD878 *)pos;
    *(s32 *)(vars + 0xC8) = arg3;
    *(f32 *)(vars + 0xD4) = farg;
    *(s32 *)(vars + 0xCC) = 0;
    *(u128_3CD878 *)(vars + 0xB0) = *(u128_3CD878 *)vec;
    func_0038CF68(tmp20, vec, 1.0f);
    *(u128_3CD878 *)(obj + 0xC0) = *(u128_3CD878 *)tmp20;
    func_0038CE90(obj + 0xD0, obj + 0xC0, tmp10);
    func_0038CF68(obj + 0xD0, obj + 0xD0, 1.0f);
    func_0038CE90(obj + 0xE0, obj + 0xD0, obj + 0xC0);
    *(f32 *)(obj + 0xCC) = 0.0f;
    *(f32 *)(obj + 0xEC) = 0.0f;
    *(f32 *)(obj + 0xDC) = 0.0f;
    *(s32 *)(vars + 0xC4) = owner;
    for (i = 3; i >= 0; i--) {
        func_L01_0046B458(pos, 0xC, D_001DF110_sda[3 - i], D_001DF130_sda[3 - i], D_001DF0F0_sda[3 - i], 2, 1, D_L01_001D66B0, 0.0f, 1);
    }
    for (i = 4; i < 7; i++) {
        func_L01_00470C78(pos, 0x11, D_001DF110_sda[i], D_001DF130_sda[i], D_001DF0F0_sda[i], 2, 2, D_L01_001D66B0, 0, D_001DF150_sda[i - 4], 6, 1);
    }
    *(s32 **)(vars + 0xC0) = D_001DF0B0_sda;
    *(s32 *)(vars + 0x24) = D_001DF0A0_sda;
    *(s32 *)(vars + 0x2C) = D_001DF0A4_sda;
    *(s32 *)(vars + 0x20) = D_001DF0A0_sda;
    *(s32 *)(vars + 0x28) = D_001DF0A4_sda;
    func_L01_0040C7A0(vars);
    return obj;
}
