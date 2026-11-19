/* functional: high. functional: stack/register layout differs only */
extern u8 D_00142CA0[];
extern s32 D_L01_001D8848;
extern s32 D_L01_001D8838;
extern s32 D_L01_001D883C;
extern f32 D_L01_001D8878;
extern f32 D_L01_001D884C;
extern f32 D_L01_001D8850;
extern char D_L01_001D8818[];
extern char D_L01_001D89F8[];
extern char D_L01_001D8A00[];
extern s32 func_L01_00487F78(s32, s32, s32);
extern s32 func_L01_00485B68(s32);
extern s32 func_00381FF0(s32);
extern int func_0011B2E8(char *, char *, ...);
extern void func_L01_00516AA0(s32, s32, s32);
extern void func_L01_004784C0(s32, s32, f32, f32);

void func_L01_004892C0(void) {
    s32 r;

    r = func_L01_00487F78(D_L01_001D8848, D_L01_001D8838, D_L01_001D883C);
    if (D_L01_001D8848 == 0 && D_00142CA0[r] != 0) {
        s32 s = func_00381FF0(0x1604);
        func_0011B2E8(D_L01_001D8818, D_L01_001D89F8, s, func_L01_00485B68(r));
    } else {
        func_0011B2E8(D_L01_001D8818, D_L01_001D8A00, func_00381FF0(0x1604));
    }
    r = func_L01_00487F78(0, D_L01_001D8838, D_L01_001D883C);
    if (D_L01_001D8848 == 0 && D_00142CA0[r] != 0) {
        func_L01_00516AA0(0x190009, 1, 1);
        func_L01_004784C0(r, 0x190009, D_L01_001D884C - 0.007000000216066837f, D_L01_001D8850 - (D_L01_001D8878 + D_L01_001D8878));
    } else {
        func_L01_00516AA0(0x190009, 1, 0);
    }
}
