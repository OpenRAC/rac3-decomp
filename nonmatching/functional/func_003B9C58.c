/* functional: high. US draft verified against PAL asm (gp offsets resolve to D_1D8BB8..BE0 and D_1DA074, call args and stack slots agree). Dropped the draft's dead D_1DA070 ternary (retail loads it but adds 0.0 either way). */
extern void func_0038E530(s32);
extern s32 func_003823D0(s32);
extern void func_003914A0(s16 *p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern void func_003AF7C0(void *, u32, void *, s32, s32, s32, s32, void *, void *, s32);
extern s32 D_001D8BBC;
extern s32 D_001D8BB8;
extern s32 D_001D8BC4;
extern s32 D_001D8BC8;
extern s32 D_001D8BCC;
extern s8 D_001D8BD0;
extern s32 D_001D8BDC;
extern s32 D_001D8BE0;
extern f32 D_001DA074;
void func_003B9C58(void) {
    s16 buf[16];
    s32 v;
    if (D_001D8BBC == 1) return;
    func_0038E530(1);
    switch (D_001D8BB8) {
    case 0: {
        char *a, *b, *c;
        v = (s32)(D_001DA074 * 100.0f + 0.5f);
        func_003914A0(buf, 0xF0, 0x1E0, D_001D8BDC, D_001D8BE0, 0x100, v, 0x10, 3);
        if ((a = (char *)D_001D8BC4) == 0) a = (char *)func_003823D0(0x8E2);
        if ((b = (char *)D_001D8BC8) == 0) b = (char *)func_003823D0(0x8DF);
        if ((c = (char *)D_001D8BCC) == 0) c = (char *)func_003823D0(0x17C);
        func_003AF7C0(buf, 0x8066CCFF, c, 1, 1, -1, 0, a, b, *(u8 *)&D_001D8BD0);
        break;
    }
    case 1: {
        char *a, *c;
        v = (s32)(D_001DA074 * 100.0f + 0.5f);
        func_003914A0(buf, 0xF0, 0x1E0, D_001D8BDC, D_001D8BE0, 0x100, v, 0x10, 3);
        if ((a = (char *)D_001D8BC4) == 0) a = (char *)func_003823D0(0x8E2);
        if ((c = (char *)D_001D8BCC) == 0) c = (char *)func_003823D0(0x17C);
        func_003AF7C0(buf, 0x8066CCFF, c, 1, 1, -1, 0, a, 0, *(u8 *)&D_001D8BD0);
        break;
    }
    }
}
