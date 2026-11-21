/* functional: high. compiles; 231 diff lines (regalloc/frame); sp18 z of the camera-delta intentionally reused; colour words split into 4 bytes little-endian */
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern void func_L01_002FB660(void *, void *, s32, s32, s32, s32);
extern void func_L01_0040E6B8(void *, void *, f32);
extern void func_L01_00464690(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32);
extern void func_L01_00304018(void *, void *, void *, s32, u8, u8, u8, u8, f32);
extern u8 D_L01_001E2A40[];
extern s32 D_001DE4BC_sda;
extern f32 D_001DE4C0_sda;
extern u32 D_001DE4C4_sda;
extern u32 D_001DE4C8_sda;
extern u32 D_001DE4CC_sda;
extern s32 D_001DE4D0_sda;
extern s32 D_001DE4D4_sda;

void func_L01_003AE1A0(u8 *m) {
    u8 *pv = *(u8 **)(m + 0x68);
    f32 v0[4] __attribute__((aligned(16)));
    f32 v10[4] __attribute__((aligned(16)));
    f32 v20[4] __attribute__((aligned(16)));
    f32 v30[4] __attribute__((aligned(16)));
    f32 len;
    f32 f22;
    f32 f20;
    s32 i;
    s32 c;
    s32 a;
    s32 b;
    u32 w;

    qzero(v0);
    v0[2] = 0.04f;
    for (i = 0; i < D_001DE4BC_sda; i++) {
        qzero(v20);
        v20[0] = func_003824E0(-1.0f, 1.0f);
        v20[1] = func_003824E0(-1.0f, 1.0f);
        vec_copy(v10, v20);
        func_0038CF68(v10, v10, func_003824E0(6.5f, 10.0f) * 0.02f);
        v10[2] = D_001DE4C0_sda * 0.02f;
        func_L01_002FB660(m + 0x10, v10, func_00382498(50, 75), 1, 4, 0);
    }
    vec_sub_ab(v10, D_L01_001E2A40, m + 0x10);
    len = func_0038CEA8(v10);
    qzero(v30);
    v30[0] = func_003824E0(-1.0f, 1.0f);
    v30[1] = func_003824E0(-1.0f, 1.0f);
    v30[2] = func_003824E0(-1.0f, 1.0f);
    vec_copy(v20, v30);
    v10[2] = v10[2] + len * 0.5f;
    func_0038CF68(v20, v20, len * 0.2f * 0.02f);
    func_0038CF68(v10, v10, (len + len) * 0.02f);
    vec_add_ba(v20, v20, v10);
    func_L01_0040E6B8(v20, v20, 0.2f);
    func_L01_002FB660(m + 0x10, v20, func_00382498(50, 75), 1, 4, 0);
    if (len < 6.0f) {
        c = (s32)len + 1;
    } else {
        c = 4;
    }
    f22 = 0.0f;
    if (len < 7.0f) {
        f22 = 7.0f - len;
    }
    for (i = c; i > 0; i--) {
        f20 = func_003824E0(8.0f, 10.0f) * 0.02f - f22 * 0.02f;
        a = func_00382498(12, 17);
        b = func_00382498(21, 25);
        func_L01_00464690(m + 0x10, v0, D_001DE4D0_sda, D_001DE4D4_sda, a, b, 0, 0, 400000.0f, f20);
    }
    if (len > 9.0f) {
        w = D_001DE4C8_sda;
        func_L01_00304018(m, m + 0x10, v0, 0x14, (u8)w, (u8)(w >> 8), (u8)(w >> 16), (u8)(w >> 24), 3.0f);
    }
    w = D_001DE4C4_sda;
    func_L01_00304018(m, m + 0x10, v0, 0x11, (u8)w, (u8)(w >> 8), (u8)(w >> 16), (u8)(w >> 24), 3.0f);
    w = D_001DE4CC_sda;
    func_L01_00304018(m, m + 0x10, v0, 0x18, (u8)w, (u8)(w >> 8), (u8)(w >> 16), (u8)(w >> 24), 2.0f);
    *(s32 *)pv = 0;
}
