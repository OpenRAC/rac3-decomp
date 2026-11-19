/* functional: high. Builds the 3-row (two-column) selection menu: lazily initialises three cached layout floats on first use (D_001E0720 = base*0.25, D_001E0728 = base*0.125, D_001E0730 = D_001D851C/15), creates the three frame quads, six text widgets (three label strings plus a shared D_001D8528 string) and positions/aligns them, then clears two state words. Same calls, arguments and order as retail; float constants are retail's exact values. Not byte-checked. */
extern s32 D_001E0724;
extern f32 D_001E0720;
extern s32 D_001E072C;
extern f32 D_001E0728;
extern s32 D_001E0734;
extern f32 D_001E0730;
extern f32 D_001D8510;
extern f32 D_001D8514;
extern f32 D_001D8518;
extern f32 D_001D851C;
extern f32 D_001D8520;
extern s32 D_001D8508;
extern char D_001D8528[];
extern s32 D_001E0754;
extern s32 D_001E0758;

extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern void func_L01_00516B90(s32, s32, s32);
extern s32 func_L01_00517190(s32, s32);
extern s32 func_003B5060(s32);
extern s32 func_L01_00518110(s32, s32, s32, s32);
extern s32 func_003E8348(s32, s32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_00381FF0(s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_003E8B98(s32, s32, s32, s32, s32, s32, s32);

void func_L01_00484080(void) {
    f32 zero = 0.0f;
    f32 one = 1.0f;
    f32 three = 3.0f;
    f32 A, B, C;
    s32 col;
    s32 v;

    if (D_001E0724 == 0) {
        D_001E0724 = 1;
        D_001E0720 = D_001D8510 * 0.25f;
    }
    if (D_001E072C == 0) {
        D_001E072C = 1;
        D_001E0728 = D_001D8510 * 0.125f;
    }
    if (D_001E0734 == 0) {
        D_001E0734 = 1;
        D_001E0730 = D_001D851C / 15.0f;
    }
    A = D_001E0720;
    func_003E9138(0x100005, 0x80808080, 0, D_001D8514 + D_001D851C, (D_001D8518 + A) + D_001E0728,
                  D_001E0730, D_001E0730);
    func_L01_00516B90(0x100005, 2, 3);
    func_L01_00517190(0x100005, 0xED81);
    A = D_001E0720;
    func_003E9138(0x100008, 0x80808080, 0, D_001D8514 + D_001D851C, (D_001D8518 + A * three) + D_001E0728,
                  D_001E0730, D_001E0730);
    func_L01_00516B90(0x100008, 2, 3);
    func_L01_00517190(0x100008, 0xED81);
    A = D_001E0720;
    func_003E9138(0x100009, 0x80808080, 0, D_001D8514, (D_001D8518 + (A + A)) + D_001E0728,
                  D_001D851C - D_001E0730 * 0.5f, D_001D8520);
    func_L01_00516B90(0x100009, 1, 3);
    func_003B5060(0xD000B);
    func_L01_00518110(0xD000B, 0x100005, 0x100008, 0x100009);
    func_003E8348(0x10, 0xD000B);
    col = D_001D8508;
    func_003E8FE8(0x100006, (s32)D_001D8528, col, zero, zero, one, one);
    v = func_00381FF0(0x1645);
    func_003E8FE8(0x100007, v, D_001D8508, zero, zero, one, one);
    func_003E8FE8(0x10000A, (s32)D_001D8528, D_001D8508, zero, zero, one, one);
    v = func_00381FF0(0x1646);
    func_003E8FE8(0x10000B, v, D_001D8508, zero, zero, one, one);
    func_003E8FE8(0x10000C, (s32)D_001D8528, D_001D8508, zero, zero, one, one);
    v = func_00381FF0(0xF07);
    func_003E8FE8(0x10000D, v, D_001D8508, zero, zero, one, one);
    func_L01_00516AA0(0x100006, 0x40, 1);
    func_L01_00516AA0(0x100007, 0x40, 1);
    func_L01_00516AA0(0x10000A, 0x40, 1);
    func_L01_00516AA0(0x10000B, 0x40, 1);
    func_L01_00516AA0(0x10000C, 0x40, 1);
    func_L01_00516AA0(0x10000D, 0x40, 1);
    func_L01_00516470(0x100006, D_001D8514 + D_001D851C, (D_001D8518 + D_001E0720) + D_001E0728);
    func_L01_00516470(0x100007, D_001D8514, (D_001D8518 + D_001E0720) + D_001E0728);
    A = D_001E0720;
    func_L01_00516470(0x10000A, D_001D8514 + D_001D851C, (D_001D8518 + A * three) + D_001E0728);
    A = D_001E0720;
    func_L01_00516470(0x10000B, D_001D8514, (D_001D8518 + A * three) + D_001E0728);
    func_L01_00516470(0x10000C, D_001D8514 + D_001D851C, D_001D8518 + D_001E0728);
    func_L01_00516470(0x10000D, D_001D8514, D_001D8518 + D_001E0728);
    func_L01_00516B90(0x100006, 2, 3);
    func_L01_00516B90(0x100007, 1, 3);
    func_L01_00516B90(0x10000A, 2, 3);
    func_L01_00516B90(0x10000B, 1, 3);
    func_L01_00516B90(0x10000C, 2, 3);
    func_L01_00516B90(0x10000D, 1, 3);
    func_003B5060(0xD0025);
    func_003E8B98(0xD0025, 0x100006, 0x100007, 0x10000A, 0x10000B, 0x10000C, 0x10000D);
    func_003E8348(0x11, 0xD0025);
    D_001E0754 = 0;
    D_001E0758 = 0;
}
