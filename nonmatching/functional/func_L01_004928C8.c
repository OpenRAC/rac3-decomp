/* functional: high. Variant of func_L01_00491630 (same scale/clamp/panel setup) with string 0x162, an extra 'too wide' flag that shrinks element 0xD0005 by 0.588/width, and the list builder func_L01_00492D00; byte diff from float literal pool handling only */
extern s32 D_L01_001D8E6C __attribute__((section(".sdata")));
extern s32 D_L01_001D8E78 __attribute__((section(".sdata")));
extern f32 D_L01_001DC0E8[];
extern u8 D_L01_002EB4E8[];
extern void func_L01_00492FE0(void);
extern void func_0038E150(s32);
extern char *func_00381FF0(s32);
extern s32 func_0038E548(f32, char *, s32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003B9298(s32, f32, s32, s32, s32, s32, s32, s32, s32, s32, char *, s32, s32, s32, s32);
extern void func_003E8FE8(s32, char *, s32, f32, f32, f32, f32);
extern void func_003E7F20(s32, s32);
extern s32 func_003E8630(s32, s32);
extern void func_L01_00517538(s32, f32, f32);
extern void func_L01_00492D00(void *);
extern void func_003E8348(s32, s32);
extern s32 func_003B42F8(s32);
extern void func_003E8710(s32, s32);
extern void func_L01_00516D60(s32, s32);
extern s32 func_003E87B8(s32, s32, s32);
extern void func_L01_004931E0(void);

void func_L01_004928C8(void) {
    s32 flag = 0;
    f32 lo = 0.0f, hi = 0.49f, scale = 0.0f;
    f32 a = 6.0f, b = 11.0f;
    f32 w, x, r;

    D_L01_001D8E6C = -1;
    D_L01_001D8E78 = 0;
    func_L01_00492FE0();
    func_0038E150(0);
    w = (f32)func_0038E548(1.2f, func_00381FF0(0x162), -1) / D_L01_001DC0E8[0];
    if (hi < w) {
        flag = 1;
        scale = 0.58800006f / w;
        w = hi;
    }
    x = (w - lo) / hi;
    r = func_003C4088(a, b, x);
    if (b < r) r = b;
    else if (r < a) r = a;
    func_003B9298(0x10, r, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005, 0xD0008, func_00381FF0(0x162), 0xD0006, 0x124, 0xD0007, 0xCD5);
    func_003E8FE8(0xD0009, func_00381FF0(0x1B80), 0x8066CCFF, 0.035f, 0.5f, 1.0f, 1.0f);
    func_003E7F20(0xD0009, 1);
    func_003E8630(0xD000B, 0xD0009);
    if (flag) func_L01_00517538(0xD0005, scale, scale);
    func_L01_00492D00(D_L01_002EB4E8);
    func_003E8348(0x11, 0x1C0000);
    func_003E8710(0x1C0003, func_003B42F8(0));
    func_L01_00516D60(0x1C0003, 0);
    func_003E87B8(0x1C0003, 1, 8);
    func_L01_004931E0();
}
