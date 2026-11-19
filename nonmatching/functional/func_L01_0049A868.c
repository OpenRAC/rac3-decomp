/* functional: high. Compiles at level_01 (208 diff, frame 0x60 matches; float constants bit-exact). Uses the file context's D_00160C40 (S_func_00496AB0 array) via a u8 * cast, and its void * returns of func_003BB3A8/func_003B42F8. */
extern f32 D_L01_001D93E0;
extern f32 D_L01_001D93F0;
extern s32 D_L01_001D937C;
extern s32 D_L01_001DC1B0;
extern s32 D_L01_001D9380;
extern s32 D_L01_001D9384;

extern s32 D_L01_001E15E0[];
extern f32 D_L01_001D93E4;
extern f32 D_L01_001D93E8;
extern f32 D_L01_001D93EC;
extern f32 D_L01_001D93F4;
extern f32 D_L01_001D93F8;
extern f32 D_L01_001D93FC;
extern s32 D_L01_001D9340[];
extern s32 func_00381FF0(s32);
extern void func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, f32, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_00518D40(s32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern void func_003E8630(s32, s32);
extern s32 func_003E7F20(s32, s32);
extern s32 func_003E8A08(s32, s32, s32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E8A58(s32, s32, s32, s32, s32);
extern s32 func_003E8348(s32, s32);
extern s32 func_003B4528(void *, s32, s32, s32, s32);
extern s32 *func_003E6C08(void);
extern s32 func_003E6DE8(s32 *);
extern u8 *func_003E6378(s32, s32);
extern s32 func_L01_00517190(s32, s32);
extern s32 func_L01_0049B490(s32);

void func_L01_0049A868(void) {
    s32 s;
    s32 mem;
    s32 *inst;
    u8 *z;
    s32 i;

    s = func_00381FF0(0x1652);
    func_003B9298(0x10, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005, 5.0f,
                  0xD0008, s, 0xD0006, 0xE62, 0xD0007, 0xE63);
    func_L01_00518D40(0x4D0000);
    s = func_00381FF0(0xCD5);
    func_003E8FE8(0x4D0001, s, 0x8066CCFF, 0.5f, 0.93f, 1.0f, 1.0f);
    func_L01_00516AA0(0x4D0001, 0x40, 1);
    func_003E8630(0x4D0000, 0x4D0001);
    s = func_00381FF0(0x1B99);
    func_003E8FE8(0xD0009, s, 0x8066CCFF, 0.035f, 0.5f, 1.0f, 1.0f);
    func_003E7F20(0xD0009, 1);
    s = func_00381FF0(0x1B9A);
    func_003E8FE8(0xD000A, s, 0x8066CCFF, 0.97f, 0.5f, 1.0f, 1.0f);
    func_003E7F20(0xD000A, 1);
    func_003E8A08(0x4D0000, 0xD0009, 0xD000A);
    func_003E9270(0x4D0002, 0x332299DE, D_L01_001D93E0, D_L01_001D93E4, D_L01_001D93E8, D_L01_001D93EC, 0.0035f, 0.006f);
    s = func_00381FF0(0xCD5);
    func_003E8FE8(0x4D0003, s, 0x8066CCFF, D_L01_001D93E0, D_L01_001D93E4, 1.0f, 1.0f);
    func_L01_00516AA0(0x4D0003, 0x40, 1);
    func_003E9138(0x4D0005, 0x80808080, 0, D_L01_001D93F0, D_L01_001D93F4, D_L01_001D93F8 - 0.0035f, D_L01_001D93FC - 0.006f);
    func_003E9270(0x4D0004, 0x332299DE, D_L01_001D93F0, D_L01_001D93F4, D_L01_001D93F8, D_L01_001D93FC, 0.0035f, 0.006f);
    func_003E8A58(0x4D0000, 0x4D0003, 0x4D0002, 0x4D0005, 0x4D0004);
    func_003E8348(0x11, 0x4D0000);
    mem = (s32)func_003BB3A8(1);
    D_L01_001D937C = (mem + 0xF) & ~0xF;
    func_003B4528((void *)func_003B42F8(0), D_L01_001D937C, 0, *(s32 *)((u8 *)D_00160C40 + 0x694), (s32)((u8 *)D_00160C40 + 0x1278));
    inst = D_L01_001E15E0;
    if (D_L01_001E15E0[1] == 0) {
        inst = func_003E6C08();
    }
    z = func_003E6378(func_003E6DE8(inst), 0x4D0005);
    if (z != 0) {
        s32 *vt = *(s32 **)(z + 8);
        if (((s32 (*)(u8 *, s32))vt[4])(z, D_L01_001DC1B0) == 0) {
            z = 0;
        }
    }
    *(s32 *)(z + 0x50) = (s32)func_003B42F8(0);
    func_L01_00517190(0x4D0005, 1);
    for (i = 14; i >= 0; i--) {
        D_L01_001D9340[i] = 0;
    }
    D_L01_001D9380 = -1;
    if (D_L01_001D9384 == -1) {
        D_L01_001D9384 = func_L01_0049B490(-1);
    }
}
