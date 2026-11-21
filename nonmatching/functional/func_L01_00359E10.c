/* functional: medium. same calls/args/order; only register allocation and frame layout differ; one dead branch (retail's kind<4 test after kind>=4 known) folded */
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern u8 D_L01_002C5600[];
extern u8 D_L01_00284320[];
extern u8 D_L01_00284460[];
extern u8 *D_001E1A20_sda;
extern u8 *D_L01_001E1A20[];
extern f32 func_003824E0(f32, f32);
extern void func_003C2F58(void *, s32, void *);
extern void func_L01_0035B0A0(u8 *);
extern void func_L01_0035A6B0(u8 *, void *, void *);
extern void func_L01_0035A218(void *, s32, s32, s32, s32, s32, f32, f32);

void func_L01_00359E10(u8 *a0) {
    u8 tmp[0x20] __attribute__((aligned(16)));
    u8 *obj;
    s32 kind, i;
    f32 lo, hi, w;
    s32 c0, c1;
    f32 f10;
    func_L01_0035B0A0(a0);
    obj = *(u8 **)(a0 + 0x68);
    kind = (D_L01_002C5600 + D_001425C0[0x7F] * 0xF0)[1];
    f10 = *(f32 *)(obj + 0x10) + 0.1f;
    *(f32 *)(obj + 0x10) = f10;
    if (4.0f <= f10) *(f32 *)(obj + 0x10) = f10 - 4.0f;
    for (i = 0; i < 9; i++) {
        func_003C2F58(D_L01_001E1A20[i], 0, tmp);
        func_003C2F58(D_L01_001E1A20[i + 1], 1, tmp + 0x10);
        func_L01_0035A6B0(a0, tmp, tmp + 0x10);
    }
    for (i = 0; i < 10; i++) *(u128_t *)(D_L01_00284460 + i * 16) = *(u128_t *)(D_L01_00284320 + i * 16);
    w = func_003824E0(0.03f, 0.05f);
    hi = func_003824E0(3.0f, 5.0f);
    if ((u32)(*(s32 *)(D_001A4BE0 + 0x25C4) - 19) < 2 || *(s32 *)(obj + 0x20) != 0) {
        w = func_003824E0(0.01f, 0.03f);
        hi = func_003824E0(3.0f, 5.0f);
    }
    func_003C2F58(D_L01_001E1A20[0], 0, D_L01_00284460);
    c0 = 0; c1 = 0;
    if (kind < 2) { c0 = 0x7F7F7F; c1 = 0x2020FF; }
    else if ((u32)(kind - 2) < 2) { c0 = 0x7F7F7F; c1 = 0xFF8040; }
    else if (!(kind < 4)) { c0 = 0xFF0000; c1 = 0xFF1010; }
    func_L01_0035A218(D_L01_00284460, 9, 0x4F, c0, c1, 0, w, hi);
    if (!(kind < 3)) {
        s32 col = (kind < 4) ? 0x2020FF : 0xFF2020;
        f32 hi2, lo2;
        if ((u32)(*(s32 *)(D_001A4BE0 + 0x25C4) - 19) < 2 || *(s32 *)(obj + 0x20) != 0) hi2 = 0.15f;
        else hi2 = 0.12f;
        lo2 = -hi2;
        for (i = 0; i < 10; i++) {
            f32 *p = (f32 *)(D_L01_00284460 + i * 16);
            p[0] += func_003824E0(lo2, hi2);
            p[1] += func_003824E0(lo2, hi2);
            p[2] += func_003824E0(lo2, hi2);
        }
        func_L01_0035A218(D_L01_00284460, 9, 0x4F, 0x7F7F7F, col, 0, 0.032f, 1.2f);
    }
}
