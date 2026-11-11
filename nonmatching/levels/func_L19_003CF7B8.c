/* func_L19_003CF7B8: 62 diff (register allocation); file already @ps2as */
typedef int u128_t __attribute__((mode(TI)));

extern s32 func_0038DC20(f32 *, f32);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382468(s32);
extern void func_L01_0046B458(f32 *, s32, s32, s32, s32, f32 *, f32, f32, f32, s32);
extern f32 D_L19_001D66F0[2];

void func_L19_003CF7B8(u8 *pos, f32 x, f32 y, s32 n, s32 b, s32 m, s32 c) {
    u128_t q[2];
    f32 t;
    f32 z;
    s32 k;
    s32 r;
    q[1] = *(u128_t *)pos;
    q[0] = *(u128_t *)pos;
    ((f32 *)&q[1])[3] = 0.1f;
    if (func_0038DC20((f32 *)&q[1], 32.0f) > 0) {
        t = func_003824E0(x, y);
        r = func_00382468(2);
        z = 0.0f;
        k = r ? r : r - 1;
        func_L01_0046B458((f32 *)&q[0], (n * 5 + 2) / 6, b, 0, k, D_L19_001D66F0, t * 0.3f, t, z, 0);
        if (m != 0 && c != 0) {
            func_L01_0046B458((f32 *)&q[0], (m * 5 + 2) / 6, c, 1, -k, D_L19_001D66F0, t * 0.04f, t * 0.4f, z, 0);
        }
    }
}
