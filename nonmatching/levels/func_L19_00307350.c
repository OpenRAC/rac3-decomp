/* func_L19_00307350: 46 rows; compiles with the file's @ps2as but float register allocation and one store differ; logic checked against the asm. */
__asm__(".extern D_001DC534, 4");
__asm__(".extern D_001DC538, 4");
extern f32 D_001DC534;
extern f32 D_001DC538;
extern f32 D_001E0E00;
extern f32 D_001E0E04[];
extern f32 D_001E0E10;
extern s32 D_001E0E14;
extern f32 func_003824E0(f32, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038CEA8(void *);

void func_L19_00307350(s32 mode) {
    f32 v[2];
    f32 f2;
    f32 f20;
    f32 f21;
    f32 f22;
    f32 f23;
    f32 f24;
    f32 f25;

    if (mode == 0) {
        f2 = 5.0f;
        f25 = 10.0f;
        f24 = 2.0f;
        f23 = 8.0f;
        f22 = 4.0f;
    } else {
        f2 = 2.5f;
        f25 = 10.0f;
        f24 = 20.0f;
        f23 = 3.0f;
        f22 = 2.0f;
    }
    if (D_001DC534 >= 0.0f)
        f22 = D_001DC534;
    if (D_001DC538 >= 0.0f)
        f23 = D_001DC538;
    f20 = f2 * 0.020000001f;
    f21 = -f20;
    D_001E0E00 = func_003824E0(f21, f20);
    D_001E0E04[0] = func_003824E0(f21, f20);
    D_001E0E10 = func_003824E0((f24 * 5.0f + 2.0f) / 6.0f, (f25 * 5.0f + 2.0f) / 6.0f);
    v[0] = f20;
    v[1] = f20;
    f20 = func_0038CED8(&D_001E0E00);
    f20 = f20 / func_0038CEA8(v);
    D_001E0E14 = (s32)(f20 * (f23 - f22) + f22);
}
