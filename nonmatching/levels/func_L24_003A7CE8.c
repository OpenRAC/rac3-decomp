/* func_L24_003A7CE8: level 24 near miss, 21 differences (register allocation only, see nonmatching/README.md). Checked at its place in L24_003A7AA8.c (-mvu0-use-vf0-vf2, @ps2as). */
typedef struct { s32 f0, f4, f8, fC, f10; f32 f14; s32 f18, f1C, f20; f32 f24, f28; u8 pad2C[4]; } S_3A7CE8;
extern S_3A7CE8 D_L24_002B9460_3A7CE8[];

extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern void *func_L01_00466588(void *, void *, s32, s32, s32, s32, f32);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_003824E0(f32, f32);
extern void func_003C4098(void *, void *, void *, f32);
extern s32 func_00382468(s32);
extern void *func_L01_004637C8(void *, void *, s32, s32, s32, s32, s32, s32);

void func_L24_003A7CE8(void *a0, u8 *a1) {
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    f32 d[4] __attribute__((aligned(16)));
    f32 e[16] __attribute__((aligned(16)));
    s32 n;
    s32 i;
    qzero(d);
    func_003C2EC0(a0, 0, e);
    *(vu0_q *)a = *(vu0_q *)e;
    func_0038CF68(a, a, 0.300000012f);
    vec_add_ab(a, a, &e[12]);
    func_L01_00466588(a, d, 0x70000FF, 0x10000FF, func_00382498(8, 0xC), 1, 50000.0f);
    n = *(s32 *)(a1 + 0x980);
    if (n != 0) {
        n--;
        func_003C2F58(a0, 2, b);
        func_003C2F58(a0, 1, c);
        for (i = 2; i >= 0; i--) {
            func_003C4098(a, c, b, func_003824E0(0.400000006f, 1.0f));
            qzero(d);
            d[0] = func_003824E0(-0.0199999996f, 0.0199999996f);
            d[1] = func_003824E0(-0.0199999996f, 0.0199999996f);
            if (func_00382468(5) == 0) {
                func_0038CF68(d, d, 20.0f);
            }
            d[2] = func_003824E0(0.0500000007f, 0.100000001f);
            a[2] = a[2] - 0.5f;
            func_L01_004637C8(a, d, D_L24_002B9460_3A7CE8[n].f0, D_L24_002B9460_3A7CE8[n].f4, (D_L24_002B9460_3A7CE8[n].f10 * 5 + 2) / 6, D_L24_002B9460_3A7CE8[n].f8, D_L24_002B9460_3A7CE8[n].fC, 1);
        }
    }
}
