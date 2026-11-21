/* functional: high. functional: high. Compiles in the file context; bytes differ only in register/lui scheduling of constant loads */
extern f32 func_0038CEA8(void *);
extern f32 func_00382538(void);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
extern void func_L01_0040A4A0(void *, void *, s32, s32, s32, f32, f32, f32, s32);
extern f32 D_001DF018_sda;
extern s32 D_001DF028_sda;
extern f32 D_001DF038_sda;
extern f32 D_001DF048_sda;
extern s32 D_001DF058_sda;
extern s32 D_001DF068_sda;
extern f32 D_L01_001DF01C[];
extern f32 D_L01_001DF020[];
extern s32 D_L01_001DF02C[];
extern s32 D_L01_001DF030[];
extern f32 D_L01_001DF03C[];
extern f32 D_L01_001DF040[];
extern f32 D_L01_001DF04C[];
extern f32 D_L01_001DF050[];
extern s32 D_L01_001DF05C[];
extern s32 D_L01_001DF060[];
extern s32 D_L01_001DF06C[];
extern s32 D_L01_001DF070[];
__asm__(".extern D_001DF018_sda, 4");
__asm__(".extern D_001DF028_sda, 4");
__asm__(".extern D_001DF038_sda, 4");
__asm__(".extern D_001DF048_sda, 4");
__asm__(".extern D_001DF058_sda, 4");
__asm__(".extern D_001DF068_sda, 4");

void func_L01_003CD068(u8 *a0) {
    f32 vec[4];
    u8 *v;
    u8 *pos;
    f32 t;
    vec[0] = 0.0f; vec[1] = 0.0f; vec[2] = 0.0f;
    vec[3] = 1.0f;
    v = *(u8 **)(a0 + 0x68);
    t = *(f32 *)(v + 0x14) - 0.1f;
    *(f32 *)(v + 0x14) = t;
    if (t <= -8.0f) {
        *(f32 *)(v + 0x14) = t + 8.0f;
    }
    *(f32 *)(v + 0x18) += func_0038CEA8(v);
    pos = a0 + 0x10;
    func_003D9508(pos, 0x31, D_001DF028_sda, 1, D_001DF018_sda, 0.0f, func_00382538());
    func_003D9508(pos, 0x31, D_L01_001DF02C[0], 0, D_L01_001DF01C[0], 0.0f, func_00382538());
    func_003D9508(pos, 0x2F, D_L01_001DF030[0], 1, D_L01_001DF020[0], 0.0f, func_00382538());
    if (1.0f < *(f32 *)(v + 0x18)) {
        func_L01_0040A4A0(a0, vec, 1, D_001DF058_sda, D_001DF068_sda, D_001DF038_sda, D_001DF048_sda, *(f32 *)(v + 0x14), 0x17);
        func_L01_0040A4A0(a0, vec, 1, D_L01_001DF05C[0], D_L01_001DF06C[0], D_L01_001DF03C[0], D_L01_001DF04C[0], *(f32 *)(v + 0x14), 0x17);
        func_L01_0040A4A0(a0, vec, 1, D_L01_001DF060[0], D_L01_001DF070[0], D_L01_001DF040[0], D_L01_001DF050[0], *(f32 *)(v + 0x14), 0x17);
    }
}
