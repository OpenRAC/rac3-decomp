/* functional: medium-high. Builds the big status/inventory screen: seeds the cached layout floats on first call (D_L01_001E0770..D_L01_001E07A8 with their flags), creates the title strip, text widgets (strings D_L01_001E07D0/07E8/07F0/0810, D_L01_00233C58/CD8 and ids 0x102/0xBF4/0x1B80/0x1B81), frame quads, scroll widgets and five rows of ten cells (ids 0xE0017.., 0xE0022.., 0xE002D.., 0xE0038.., 0xE0043.., 0xE004E..), ties them together and finally uploads the page texture. Same calls, arguments and order as retail; every float is the exact retail constant read from the instruction; the stack args of the 15-argument and 9-argument calls follow the matched prototypes. Not byte-checked. */
extern u8 D_L01_001D8558;
extern s32 D_L01_001D8564;
extern s32 D_L01_001D8568;
extern s32 D_L01_001D8550;
extern s32 D_L01_001D8554;
extern f32 D_L01_001D856C, D_L01_001D8570, D_L01_001D8574, D_L01_001D8578, D_L01_001D857C, D_L01_001D8580;
extern f32 D_L01_001D8584, D_L01_001D8588, D_L01_001D858C, D_L01_001D8590, D_L01_001D8594, D_L01_001D8598, D_L01_001D859C;
extern f32 D_L01_001D85A0, D_L01_001D85A4, D_L01_001D85A8, D_L01_001D85AC, D_L01_001D85B0, D_L01_001D85B4, D_L01_001D85B8;
extern f32 D_L01_001D85BC, D_L01_001D85C0, D_L01_001D85C4, D_L01_001D85C8, D_L01_001D85CC, D_L01_001D85D0, D_L01_001D85D4, D_L01_001D85D8;
extern f32 D_L01_001D85DC, D_L01_001D85E0, D_L01_001D85E4, D_L01_001D85E8, D_L01_001D85EC, D_L01_001D85F0, D_L01_001D85F4, D_L01_001D85F8;
extern f32 D_L01_001D85FC, D_L01_001D8600, D_L01_001D8604, D_L01_001D8608, D_L01_001D860C, D_L01_001D8610, D_L01_001D8614, D_L01_001D8618;
extern f32 D_L01_001D861C, D_L01_001D8620, D_L01_001D8624, D_L01_001D8628, D_L01_001D862C, D_L01_001D8630, D_L01_001D8634, D_L01_001D8638;
extern f32 D_L01_001D863C, D_L01_001D8640;
extern f32 D_L01_001E0770, D_L01_001E0778, D_L01_001E0780, D_L01_001E0788, D_L01_001E0790, D_L01_001E0798, D_L01_001E07A0, D_L01_001E07A8;
extern s32 D_L01_001E0774, D_L01_001E077C, D_L01_001E0784, D_L01_001E078C, D_L01_001E0794, D_L01_001E079C, D_L01_001E07A4, D_L01_001E07AC;
extern char D_L01_001E07D0[];
extern char D_L01_001E07E8[];
extern char D_L01_001E07F0[];
extern char D_L01_001E0810[];
extern char D_L01_00233C58[];
extern char D_L01_00233CD8[];
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
} S_160C40_00484AF8;
extern S_160C40_00484AF8 D_00160C40;

extern void *func_003BB3A8(s32);
extern s32 func_00381FF0(s32);
extern s32 func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, f32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E7F20(s32, s32);
extern s32 func_003E8A08(s32, s32, s32);
extern s32 func_003B5060(s32);
extern s32 func_003E9358(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_L01_00517340(s32, s32, s32, s32, s32);
extern void func_L01_00516B90(s32, s32, s32);
extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00518480(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_L01_00518110(s32, s32, s32, s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_003E8348(s32, s32);
extern s32 func_L01_00517BF8(s32, s32, s32, s32, s32, s32);
extern s32 func_L01_00517DB8(s32, s32, s32, f32);
extern s32 func_L01_00517190(s32, s32);
extern s32 func_L01_00516D60(s32, s32);
extern s32 func_003E8630(s32, s32);
extern void func_L01_00485A70(void);
extern s32 func_003E8C68(s32, s32, s32, s32, s32, s32, s32, s32);
extern void *func_003B42F8(s32);
extern s32 func_003B4528(void *, s32, s32, s32, s32);
extern s32 func_003E8710(s32, s32);
extern s32 func_003E87B8(s32, s32, s32);

void func_L01_00484AF8(void) {
    f32 zero = 0.0f;
    f32 one = 1.0f;
    f32 half = 0.5f;
    f32 f0, f2;
    s32 r, i, id, v;
    void *p;

    D_L01_001D8568 = -1;
    D_L01_001D8564 = -1;
    D_L01_001D8558 = 1;
    p = func_003BB3A8(0);
    r = (s32)p;
    D_L01_001D8554 = r;
    D_L01_001D8550 = r + 0x9600;
    v = func_00381FF0(0x102);
    func_003B9298(0x10, 0xD000B, 0xD0002, 0xD0003, 0xD0004, 0xD0000, 0xD0001, 0xD0005, 8.7f,
                  0xD0008, v, 0xD0006, 0x124, 0xD0007, 0xCD5);
    v = func_00381FF0(0x1B80);
    func_003E8FE8(0xD0009, v, 0x8066CCFF, 0.035f, half, one, one);
    func_003E7F20(0xD0009, 1);
    v = func_00381FF0(0x1B81);
    func_003E8FE8(0xD000A, v, 0x8066CCFF, 0.97f, half, one, one);
    func_003E7F20(0xD000A, 1);
    func_003E8A08(0xD000B, 0xD0009, 0xD000A);
    if (D_L01_001E0774 == 0) {
        D_L01_001E0774 = 1;
        D_L01_001E0770 = D_L01_001D85BC;
    }
    if (D_L01_001E077C == 0) {
        D_L01_001E077C = 1;
        D_L01_001E0778 = D_L01_001D85D0;
    }
    if (D_L01_001E0784 == 0) {
        D_L01_001E0784 = 1;
        D_L01_001E0780 = D_L01_001D85CC;
    }
    if (D_L01_001E078C == 0) {
        D_L01_001E078C = 1;
        D_L01_001E0788 = D_L01_001D85D0;
    }
    if (D_L01_001E0794 == 0) {
        D_L01_001E0794 = 1;
        D_L01_001E0790 = D_L01_001D85FC;
    }
    if (D_L01_001E079C == 0) {
        f0 = D_L01_001D8600 + D_L01_001D8604;
        D_L01_001E079C = 1;
        f0 = f0 * half;
        D_L01_001E0798 = f0 - 0.007212f;
    }
    if (D_L01_001E07A4 == 0) {
        f0 = D_L01_001D860C;
        D_L01_001E07A4 = 1;
        D_L01_001E07A0 = f0 - 0.017577f;
    }
    if (D_L01_001E07AC == 0) {
        f0 = D_L01_001D8600 - D_L01_001D8604;
        D_L01_001E07AC = 1;
        D_L01_001E07A8 = f0 - 0.03606f;
    }
    func_003B5060(0xE0001);
    func_003B5060(0xE0002);
    func_003E8FE8(0xE0003, (s32)D_L01_001E07D0, 0x8066CCFF, D_L01_001D8624, D_L01_001D8628, one, one);
    func_003E8FE8(0xE0004, (s32)D_L01_001E07E8, 0x8066CCFF, D_L01_001D862C, D_L01_001D8630, one, one);
    v = func_00381FF0(0xBF4);
    func_003E8FE8(0xE0005, v, 0x8066CCFF, D_L01_001D8634, D_L01_001D8638, one, one);
    func_003E8FE8(0xE0000, (s32)D_L01_00233C58, 0x8066CCFF, D_L01_001D863C, D_L01_001D8640, one, one);
    func_003E7F20(0xE0000, 1);
    func_003E8FE8(0xE0006, (s32)D_L01_001E07F0, 0x8066CCFF, D_L01_001E0770, D_L01_001E0778, one, one);
    func_003E8FE8(0xE0007, (s32)D_L01_001E0810, 0x8066CCFF, D_L01_001E0780, D_L01_001E0788, one, one);
    func_003E9358(0xE0008, (s32)D_L01_00233CD8, 0x8066CCFF, D_L01_001E0790, D_L01_001E0798, D_L01_001E07A0, D_L01_001E07A8, one);
    func_003E9138(0xE0009, 0x332299DE, 0, D_L01_001D856C, D_L01_001D8570, D_L01_001D857C, D_L01_001D8580);
    func_003E9138(0xE0013, 0x192299DE, 0, zero, zero, 0.07f, 0.08615385f);
    func_003E9270(0xE000A, 0x332299DE, D_L01_001D85CC, D_L01_001D8570, D_L01_001D8574, D_L01_001D8578, 0.005f, 0.004f);
    func_003E9270(0xE0010, 0x332299DE, D_L01_001D85BC, D_L01_001D85C0, D_L01_001D85C4, D_L01_001D85C8, 0.005f, 0.004f);
    func_003E9270(0xE0014, 0x332299DE, D_L01_001D85DC, D_L01_001D85E0, D_L01_001D85E4, D_L01_001D85E8, 0.005f, 0.004f);
    func_003E9270(0xE0011, 0x332299DE, D_L01_001D85CC, D_L01_001D85D0, D_L01_001D85D4, D_L01_001D85D8, 0.005f, 0.004f);
    func_003E9270(0xE000C, 0x332299DE, D_L01_001D85FC, D_L01_001D8600, D_L01_001D860C, D_L01_001D8610, 0.005f, 0.004f);
    func_003E9270(0xE000D, 0x332299DE, D_L01_001D85FC, D_L01_001D8604, D_L01_001D860C, D_L01_001D8610, 0.005f, 0.004f);
    func_003E9270(0xE000E, 0x332299DE, D_L01_001D85FC, D_L01_001D8608, D_L01_001D860C, D_L01_001D8610, 0.005f, 0.004f);
    func_003E9138(0xE000F, 0x332299DE, 0, D_L01_001D8614, D_L01_001D8618, D_L01_001D861C, D_L01_001D8620);
    func_003E9138(0xE0012, 0x80808080, 0, D_L01_001D85EC, D_L01_001D85F0, D_L01_001D85F4, D_L01_001D85F8);
    func_L01_00517340(0xE0009, 0x60336600, 0x6095C862, 0x60336600, 0x6095C862);
    func_L01_00516B90(0xE0009, 1, 3);
    func_003E7F20(0xE0006, 1);
    func_003E8EF0(0xE000B, 0x37, 0x332299DE, D_L01_001D8584 + D_L01_001D8588 * zero, D_L01_001D858C, one, one, zero);
    func_L01_00516AA0(0xE0003, 0x40, 1);
    func_L01_00516AA0(0xE0004, 0x40, 1);
    func_L01_00516AA0(0xE0005, 0x40, 1);
    func_L01_00516AA0(0xE0000, 0x40, 1);
    func_L01_00516AA0(0xE0008, 0x40, 1);
    func_L01_00516AA0(0xE0007, 0x40, 1);
    func_L01_00516AA0(0xE0006, 0x40, 1);
    func_003E7F20(0xE0003, 1);
    func_003E7F20(0xE0008, 1);
    func_003E7F20(0xE0004, 1);
    func_003E7F20(0xE0007, 1);
    func_003E7F20(0xE0008, 1);
    func_L01_00518480(0xE0001, 0xE0003, 0xE0004, 0xE0000, 0xE000B, 0xE0009, 0xE000C, 0xE000D, 0xE000E);
    func_L01_00518480(0xE0001, 0xE0010, 0xE0011, 0xE0006, 0xE0007, 0xE0008, 0xE000F, 0xE0012, 0xE0002);
    func_003E8A08(0xE0002, 0xE0014, 0xE000A);
    func_L01_00516470(0xE000B, 0.1f, 0.1f);
    func_003E8348(0x13, 0xE0001);
    func_L01_00517BF8(0xE0008, 1, 1, 1, 0, 0);
    func_L01_00517DB8(0xE0008, 0x64, 0, 0.0005f);
    func_003E9138(0xE0058, 0x706EC8FF, 0, 0.630249f, 0.195417f, 0.07f, 0.08615385f);
    func_003E9138(0xE0059, 0x706EC8FF, 0, 0.630249f, 0.195417f, 0.07f, 0.08615385f);
    func_003E9138(0xE005A, 0x706EC8FF, 0, 0.630249f, 0.195417f, 0.07f, 0.08615385f);
    func_L01_00517190(0xE0058, 0xED54);
    func_L01_00517190(0xE0059, 0xED52);
    func_L01_00517190(0xE005A, 0xED53);
    func_L01_00516D60(0xE0058, 0);
    func_L01_00516D60(0xE0059, 0);
    func_L01_00516D60(0xE005A, 0);
    func_L01_00518110(0xE0002, 0xE0058, 0xE0059, 0xE005A);
    func_003B5060(0xE0016);
    for (i = 0; i < 10; i++) {
        id = 0xE0017 + i;
        func_003E8EF0(id, 0x37, 0x332299DE, D_L01_001D8584 + (f32)i * D_L01_001D8588, D_L01_001D858C, one, one, zero);
        func_003E8630(0xE0016, id);
    }
    func_003B5060(0xE0021);
    for (i = 0; i < 10; i++) {
        id = 0xE0022 + i;
        func_003E8EF0(id, 0x37, 0x332299DE, D_L01_001D8584 + (f32)i * D_L01_001D8588, D_L01_001D8590, one, one, zero);
        func_003E8630(0xE0021, id);
    }
    func_003B5060(0xE002C);
    for (i = 0; i < 10; i++) {
        id = 0xE002D + i;
        func_003E9138(id, 0x706EC8FF, 0, (D_L01_001D85AC + (f32)i * D_L01_001D85B0) + 0.001953f,
                      D_L01_001D85B4 + -0.004808f, 0.07f, 0.08615385f);
        func_003E8630(0xE002C, id);
    }
    func_003B5060(0xE0037);
    for (i = 0; i < 10; i++) {
        id = 0xE0038 + i;
        func_003E9138(id, 0x706EC8FF, 0, (D_L01_001D85AC + (f32)i * D_L01_001D8588) + 0.001953f,
                      D_L01_001D85B8 + -0.004808f, 0.07f, 0.08615385f);
        func_003E8630(0xE0037, id);
    }
    func_003B5060(0xE0042);
    for (i = 0; i < 10; i++) {
        f32 f12;
        id = 0xE0043 + i;
        f2 = D_L01_001D8594 + (f32)i * D_L01_001D8598;
        if (i == 6 || i == 8) {
            f12 = f2 + 0.001953f;
        } else {
            f12 = f2 + zero;
        }
        func_003E9138(id, 0x706EC8FF, 0, f12, D_L01_001D859C - 0.004808f, D_L01_001D85A4, D_L01_001D85A8);
        func_L01_00517340(id, 0x60336600, 0x6095C862, 0x60336600, 0x6095C862);
        func_L01_00516B90(id, 1, 3);
        func_003E8630(0xE0042, id);
    }
    func_003B5060(0xE004D);
    for (i = 0; i < 10; i++) {
        f32 f12;
        id = 0xE004E + i;
        f2 = D_L01_001D8594 + (f32)i * D_L01_001D8598;
        if (i == 6 || i == 8) {
            f12 = f2 + 0.001953f;
        } else {
            f12 = f2 + zero;
        }
        func_003E9138(id, 0x706EC8FF, 0, f12, D_L01_001D85A0 - 0.004808f, D_L01_001D85A4, D_L01_001D85A8);
        func_L01_00517340(id, 0x60336600, 0x6095C862, 0x60336600, 0x6095C862);
        func_L01_00516B90(id, 1, 3);
        func_003E8630(0xE004D, id);
    }
    func_L01_00485A70();
    func_003B5060(0xE0015);
    func_003E8C68(0xE0015, 0xE0013, 0xE0016, 0xE0021, 0xE002C, 0xE0037, 0xE0042, 0xE004D);
    func_003E8348(0x11, 0xE0015);
    func_003B4528(func_003B42F8(0), D_L01_001D8554, D_L01_001D8550, D_00160C40.f4954, (s32)&D_00160C40 + 0x64C8);
    func_003E8710(0xE0012, (s32)func_003B42F8(0));
    func_L01_00517190(0xE0012, 0);
    func_L01_00516D60(0xE0012, 0);
    func_003E87B8(0xE0012, 1, 8);
}
