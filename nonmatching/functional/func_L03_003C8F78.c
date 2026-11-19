/* functional: high. 100 words differ (retail forms the gp vector addresses with addiu $gp, mine via an extern array). */
extern u8 D_001DEEB0_sda[];
__asm__(".extern D_001DEEB0_sda, 4");
extern u8 D_L03_001D66B0[8];
extern s32 func_0038CAD0(void *);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern void func_0038CDF8(void *, void *, void *, f32);
extern u8 *func_L01_0046C470(void *, void *, s32, f32, s32, s32, s32, s32, s32);

void func_L03_003C8F78(u8 *m) {
    u8 *s = *(u8 **)(m + 0x68);
    vu0_v4 pos;
    f32 t;
    f32 size;
    s32 i;

    for (i = 0; i < 2; i++) {
        if (func_0038CAD0(s + 0x18 + i * 4) != 0) {
            *(s32 *)(s + 0x18 + i * 4) = func_00382498(0xA7, 0x14D);
            *(f32 *)(s + 0x10 + i * 4) = 0.0f;
            *(f32 *)(s + 0x8 + i * 4) = func_003824E0(0.0200000014f, 0.0600000024f);
        }
        t = *(f32 *)(s + 0x10 + i * 4) + *(f32 *)(s + 0x8 + i * 4);
        *(f32 *)(s + 0x10 + i * 4) = t;
        if (t > 0.0f && t <= 1.0f) {
            func_0038CDF8(&pos, &D_001DEEB0_sda[0], &D_001DEEB0_sda[0x10], t);
            pos.y = pos.y + (f32)i * 0.300000012f;
            size = func_003824E0(0.300000012f, 0.699999988f);
            func_L01_0046C470(&pos, D_L03_001D66B0, 0x4010A090, size, 2, func_00382468(0xFF) & 0xFF, 0, 0x40, 0);
        }
    }
}
