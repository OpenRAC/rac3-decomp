/* functional: high. EXACT: byte-identical (MATCH) with check.py --no-context at level_01, level_03 and level_12 (file's flags). The file context declares it extern void func_L01_00497680(void) (src line 350), so that declaration must become (s32, f32 *) when landing; gp slots are D_L01_001D9xxx floats/int as the neighbours name them. */
extern f32 D_L01_001D91B0;
extern f32 D_L01_001D91B4;
extern f32 D_L01_001D9224;
extern f32 D_L01_001D91A8;
extern f32 D_L01_001D9228;
extern f32 D_L01_001D922C;
extern s32 D_L01_001D9220;

extern s32 func_00381FF0(s32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E8898(s32, f32, f32);
extern s32 func_003E8A58(s32, s32, s32, s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00516B90(s32, s32, s32);
extern s32 func_L01_00518010(s32, s32);

void func_L01_00497680(s32 a, f32 *r) {
    f32 x;
    f32 hh;
    s32 str;

    func_003E9270(0x47001D, 0x332299DE, r[0], r[1], r[2], r[3], D_L01_001D91B0 * 0.001953125f, D_L01_001D91B4 / 416.0f);
    x = r[0] + (r[2] - r[3]) * 0.5f;
    hh = r[3] - D_L01_001D9224;
    func_003E9138(0x470020, 0x8066CCFF, 0xED26, x, r[1], hh, hh);
    func_L01_00516AA0(0x470020, 0x40, 1);
    x = x - r[3] * 0.5f;
    x = x - D_L01_001D91A8 * 0.001953125f;
    func_003E8FE8(0x47001E, 0, 0x8066CCFF, x + D_L01_001D9228, r[1], 1.0f, 1.0f);
    func_L01_00518010(0x47001E, 1);
    func_003E8898(0x47001E, D_L01_001D922C, 0.0f);
    func_L01_00516AA0(0x47001E, 0x40, 1);
    func_L01_00516B90(0x47001E, 2, 3);
    str = func_00381FF0(0xCA7);
    func_003E8FE8(0x47001F, str, 0x8066CCFF, r[0] - r[2] * 0.5f + (f32)D_L01_001D9220 * 0.001953125f, r[1], 1.0f, 1.0f);
    func_L01_00516AA0(0x47001F, 0x40, 1);
    func_L01_00516B90(0x47001F, 1, 3);
    func_003E8A58(a, 0x47001D, 0x470020, 0x47001E, 0x47001F);
}
