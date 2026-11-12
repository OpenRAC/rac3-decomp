/* func_L24_003A7CE8: level 24 near miss. 21 differences, register allocation: retail keeps n in $s0 (reused as the last table-field pointer), the loop counter in $s1, the constant 6 in $s2 and the d-vector copy in $s3; this C rotates them (counter $s0, n a temp). Needs -mvu0-use-vf0-vf2 + @ps2as on L24_003A7AA8.c (already set) and a full table struct (fields 0,4,8,C,0x10) for D_L24_002B9460 in place of the pad-only one in func_L24_003A7AA8's block. Statement-order hill climb over the loop body gave no improvement, declaration order of n/i makes no change */
typedef struct { s32 f0, f4, f8, fC, f10; f32 f14; s32 f18, f1C, f20; f32 f24, f28; u8 pad2C[4]; } S_3A7CE8;
extern S_3A7CE8 D_L24_002B9460[];

extern void func_L24_00421460(void *, s32, void *);
extern void func_L24_003F6888(void *, void *, f32);
extern s32 func_L24_0042A3F8(s32, s32);
extern void func_L24_0044B980(void *, void *, s32, s32, s32, s32, f32);
extern void func_L24_004214F8(void *, s32, void *);
extern f32 func_L24_0042A440(f32, f32);
extern void func_L24_0042EBD8(void *, void *, void *, f32);
extern s32 func_L24_0042A3C8(s32);
extern void func_L24_00448BC0(void *, void *, s32, s32, s32, s32, s32, s32);

void func_L24_003A7CE8(void *a0, u8 *a1) {
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    f32 c[4] __attribute__((aligned(16)));
    f32 d[4] __attribute__((aligned(16)));
    f32 e[16] __attribute__((aligned(16)));
    s32 n;
    s32 i;
    qzero(d);
    func_L24_00421460(a0, 0, e);
    *(vu0_q *)a = *(vu0_q *)e;
    func_L24_003F6888(a, a, 0.300000012f);
    vec_add_ab(a, a, &e[12]);
    func_L24_0044B980(a, d, 0x70000FF, 0x10000FF, func_L24_0042A3F8(8, 0xC), 1, 50000.0f);
    n = *(s32 *)(a1 + 0x980);
    if (n != 0) {
        n--;
        func_L24_004214F8(a0, 2, b);
        func_L24_004214F8(a0, 1, c);
        for (i = 2; i >= 0; i--) {
            func_L24_0042EBD8(a, c, b, func_L24_0042A440(0.400000006f, 1.0f));
            qzero(d);
            d[0] = func_L24_0042A440(-0.0199999996f, 0.0199999996f);
            d[1] = func_L24_0042A440(-0.0199999996f, 0.0199999996f);
            if (func_L24_0042A3C8(5) == 0) {
                func_L24_003F6888(d, d, 20.0f);
            }
            d[2] = func_L24_0042A440(0.0500000007f, 0.100000001f);
            a[2] = a[2] - 0.5f;
            func_L24_00448BC0(a, d, D_L24_002B9460[n].f0, D_L24_002B9460[n].f4, (D_L24_002B9460[n].f10 * 5 + 2) / 6, D_L24_002B9460[n].f8, D_L24_002B9460[n].fC, 1);
        }
    }
}
