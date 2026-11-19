/* functional: high. EXACT at default flags; byte-identical to retail. */
extern void func_0038CF68(f32, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, u8 *, s32);
extern u8 D_L01_001EAA00[];

void func_L01_0045D4B8(u8 *a, u8 *out, s32 keep) {
    f32 v0[4];
    f32 v1[4];

    func_0038CF68(0.4f, v0, a + 0xE0);
    func_0038CF68(-3.0f, v1, a + 0xE0);
    vec_add_ba(v0, v0, a + 0x10);
    vec_add_ba(v1, v1, a + 0x10);
    if (func_003D3CB0(v0, v1, 2, a, 0) != 0) {
        func_0038CF68(1.0f, out, D_L01_001EAA00 + 0x40);
    } else {
        func_0038CF68(-1.0f, out, a + 0xE0);
    }
    if (keep == 0) {
        func_0038CE20(out, out, -1.0f);
    }
}
