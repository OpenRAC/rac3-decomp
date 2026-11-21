/* functional: high. Same GS register writes, draw calls, table reads and float math as retail; 334 instrs differ in scheduling/addressing. Data tables named D_L06_<addr> from lui/gp operands (gp = 0x1DC8B0). */
extern void func_003A9440(s32, unsigned long);
extern long func_00389598(s32);
extern void func_0038C750(void);
extern f32 func_0038CF00(u8 *, u8 *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D3A24(s32, void *, void *, void *, s32);
extern vu0_v4 D_L06_001E1680[];
extern f32 D_L06_001DD378;
extern f32 D_L06_001DD37C;
extern f32 D_L06_001DD380;
extern f32 D_L06_001DD388[];
extern f32 D_L06_001DD38C[];
extern f32 D_L06_001DD3A8[];
extern f32 D_L06_001DD3AC[];
extern f32 D_L06_001E0820[];
extern f32 D_L06_001E0824[];
extern f32 D_L06_001E0828[];
extern u32 D_L06_001E0850[];
extern f32 D_L06_001E0860[];
extern f32 D_L06_001E0864[];
extern f32 D_L06_002B15C8[];

void func_L06_00358A70(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    vu0_v4 acc;
    vu0_v4 t;
    vu0_v4 base;
    f32 x;
    f32 dist;
    f32 k;
    f32 s1;
    f32 s2;
    s32 i;
    s32 j;
    s32 n;

    x = *(f32 *)(v + 0x10) + D_L06_001DD380;
    func_003A9440(8, 0);
    *(f32 *)(v + 0x10) = x - (f32)(s32)x;
    func_003A9440(0x14, 0xFF9000000260UL);
    func_003A9440(0x47, 0x513F1);
    func_0038C750();
    dist = func_0038CF00(a0 + 0x10, (u8 *)D_L06_001E1680);
    if (dist < D_L06_001DD378) {
        k = D_L06_001DD37C + dist / D_L06_001DD378 * (1.0f - D_L06_001DD37C);
    } else {
        k = 1.0f;
    }
    s1 = *(f32 *)(v + 0x2C) * k;
    s2 = s1 * *(f32 *)(v + 0x24);
    for (i = 0; i < 4; i++) {
        func_0038CE20(&acc, a0 + 0xC0, D_L06_001DD388[i * 2] * s2);
        func_0038CE20(&t, a0 + 0xD0, D_L06_001DD38C[i * 2] * s1);
        vec_add_ab(&acc, &t, &acc);
        vec_copy(&base, a0 + 0x10);
        vec_add_ab(&acc, &acc, &base);
        D_L06_001E0860[i * 2] = D_L06_001DD3A8[i * 2];
        D_L06_001E0864[i * 2] = D_L06_001DD3AC[i * 2];
        D_L06_001E0820[i * 3] = acc.x;
        D_L06_001E0824[i * 3] = acc.y;
        D_L06_001E0828[i * 3] = acc.z;
        D_L06_001E0850[i] = 0xF0808080;
    }
    func_003A9440(6, func_00389598(*(s32 *)(v + 0x20) + 0x64));
    func_003A9440(0x42, 0x800000006AUL);
    func_003D3A24(4, D_L06_001E0820, D_L06_001E0850, D_L06_001E0860, 1);
    for (i = 0; i < 4; i++) {
        D_L06_001E0864[i * 2] = D_L06_001E0864[i * 2] + *(f32 *)(v + 0x10);
    }
    func_003A9440(0x42, 0x8000000058UL);
    func_003D3A24(4, D_L06_001E0820, D_L06_001E0850, D_L06_001E0860, 1);
    func_003A9440(6, func_00389598(*(s32 *)(v + 0x20) + 0x65));
    for (j = 0; j < 5; j++) {
        f32 *row = D_L06_002B15C8 + j * 12;
        for (n = 0; n < 4; n++) {
            func_0038CE20(&acc, a0 + 0xC0, row[n * 3] * s2);
            func_0038CE20(&t, a0 + 0xD0, row[n * 3 + 1] * s1);
            vec_add_ab(&acc, &t, &acc);
            func_0038CE20(&t, a0 + 0xE0, row[n * 3 + 2] * s1);
            vec_add_ab(&acc, &t, &acc);
            vec_copy(&base, a0 + 0x10);
            vec_add_ab(&acc, &acc, &base);
            D_L06_001E0860[n * 2] = D_L06_001DD3A8[n * 2];
            D_L06_001E0864[n * 2] = D_L06_001DD3AC[n * 2];
            D_L06_001E0820[n * 3] = acc.x;
            D_L06_001E0824[n * 3] = acc.y;
            D_L06_001E0828[n * 3] = acc.z;
        }
        func_003A9440(0x42, 0x800000006AUL);
        func_003D3A24(4, D_L06_001E0820, D_L06_001E0850, D_L06_001E0860, 1);
        for (i = 0; i < 4; i++) {
            D_L06_001E0864[i * 2] = D_L06_001E0864[i * 2] + *(f32 *)(v + 0x10);
        }
        func_003A9440(0x42, 0x8000000058UL);
        func_003D3A24(4, D_L06_001E0820, D_L06_001E0850, D_L06_001E0860, 1);
    }
    func_003A9440(0x47, 0x5360B);
}
