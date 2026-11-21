/* functional: high. Compiles at level_01 only with --no-context (102 diff; the file's context declares it extern void func_L01_00497210(void) at src line 333, so that declaration must become (s32, f32 *) when it lands). gp slots -36A8/-36AC/-36B0/-36B4 are ints converted to float (lwc1 + cvt.s.w in retail); -3700/-36FC floats are the 5th/6th float args of func_003E9270. */
extern f32 D_L01_001D91B0;
extern f32 D_L01_001D91B4;
extern s32 D_L01_001D91FC;
extern s32 D_L01_001D9200;
extern s32 D_L01_001D9208;
extern s32 D_L01_001D9204;

extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern void func_003E8630(s32, s32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_00516AA0(s32, s32, s32);

void func_L01_00497210(s32 a, f32 *r) {
    s32 i;
    s32 h;
    f32 w;
    f32 hh;

    func_003E9270(0x470013, 0x332299DE, r[0], r[1], r[2], r[3], D_L01_001D91B0 * 0.001953125f, D_L01_001D91B4 / 416.0f);
    func_003E8630(a, 0x470013);
    w = r[2] / 3.0f - (f32)D_L01_001D91FC * 0.001953125f;
    hh = r[3] - (f32)D_L01_001D9200 / 416.0f;
    r[1] = r[1] + (f32)D_L01_001D9208 / 416.0f;
    r[0] = r[0] + (f32)D_L01_001D9204 * 0.001953125f;
    i = 0;
    do {
        h = 0x470014 + i;
        func_003E9138(h, 0x8066CCFF, 0, r[0] + w * (f32)(i - 1), r[1], w, hh);
        i++;
        func_L01_00516AA0(h, 0x40, 1);
        func_003E8630(a, h);
    } while (i < 3);
}
