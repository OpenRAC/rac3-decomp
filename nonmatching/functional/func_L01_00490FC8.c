/* functional: high. Same float math/call order as retail; byte diff only in literal handling (retail builds 0.002f/0 inline, no literal pool) and stack frame size */
extern s32 D_00143950[];
extern f32 D_L01_001D8D88 __attribute__((section(".sdata")));
extern f32 D_L01_001D8D8C __attribute__((section(".sdata")));
extern f32 D_L01_001D8D90 __attribute__((section(".sdata")));
extern void func_L01_00516558(s32, f32 *, f32 *);
extern void func_L01_00516470(s32, f32, f32);

void func_L01_00490FC8(void) {
    f32 v[4];
    f32 sy, sx, a, b, c;

    sy = (f32)D_00143950[4] * 0.0009765625f;
    sx = (f32)D_00143950[3] * 0.0009765625f;
    v[3] = 0.0f;
    v[0] = 0.0f;
    v[1] = 0.0f;
    v[2] = 0.0f;
    func_L01_00516558(0x1E0009, &v[0], &v[1]);
    func_L01_00516558(0x1E000C, &v[2], &v[3]);
    a = D_L01_001D8D88 + D_L01_001D8D90;
    c = D_L01_001D8D8C - a;
    b = a + 0.002f;
    c = c - 0.002f;
    sy = c * sy;
    c = c * sx;
    sy = b + sy;
    b = b + c;
    v[2] = sy;
    v[0] = b;
    func_L01_00516470(0x1E0009, b, v[1]);
    func_L01_00516470(0x1E000C, v[2], v[3]);
}
