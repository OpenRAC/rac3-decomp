/* functional: high. Multiplayer-menu list panel setup (sister of func_L39_005E5118): finds the 0x148/0x18E entries of the D_001D8478_sda table, builds the 0x54-byte panel descriptor for the panel chosen by func_L01_00517688 and sets its layout (values depend on player count *D_L39_00241120), then for each table entry formats its text row, sets its row flag and styles it. Nothing differs from retail except instruction layout. */
typedef struct {
    s32 f0;
    void *f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    f32 f18;
    f32 f1C;
    f32 f20;
    f32 a24[4];
    f32 a34[4];
    f32 a44[4];
} S_005E6D80;
extern s32 D_001D846C_sda;
extern s32 D_001D8468_sda;
extern f32 D_001D84BC_sda;
extern f32 D_001D84C0_sda;
extern s32 *D_L39_00241120;
extern u8 D_L39_00243BD8[];
extern void *func_L39_005E3A40(s32);
extern s32 func_L39_005E7E30(void *, void *);
extern void *func_L39_005E7FF8(void *, s32, s32);
extern void func_L39_005E8058(void *, s32, s32);
extern void func_L39_005E8F98(void *, s32, s32, f32, f32);
extern void func_003BABB0(void *, s32, f32, f32, f32, f32, f32);
extern void func_003BABD0(void *, f32, f32, f32, f32);
extern void func_003BA4E0(void *, s32, f32, f32, f32);
extern void func_L01_00498F18(void *, s32, s32);
extern u8 *func_L39_0059A970(s32);
extern s32 func_120048();

void func_L39_005E6D80(void) {
    S_005E6D80 s;
    s32 idx = 0;
    s32 mode;
    s32 count = 0;
    s32 first = -1;
    s32 second = -1;
    s32 i;
    f32 a = 0.500369012f;
    f32 c = 0.499706000f;
    f32 r = 0.814818025f;
    f32 b = 0.709469020f;
    u8 *buf;
    void *o;

    mode = func_L01_00517688();
    switch (mode) {
    case 1:
        idx = 1;
        break;
    case 2:
        idx = 2;
        break;
    case 3:
        idx = 3;
        break;
    }
    D_001D846C_sda = -1;
    D_001D8468_sda = -1;
    if (D_001D8478_sda[0].f0 > 0) {
        while (D_001D8478_sda[count].f0 > 0) {
            if (D_001D8478_sda[count].f0 == 0x148) {
                second = count;
            } else if (D_001D8478_sda[count].f0 == 0x18E) {
                first = count;
            }
            count++;
        }
        D_001D846C_sda = second;
        D_001D8468_sda = first;
    }
    mode = func_L01_00517688();
    if (*D_L39_00241120 >= 3) {
        c = 0.0f;
        r = 0.804817975f;
        b = 10.0f;
        switch (mode) {
        case 0:
        case 2:
            a = 0.5f;
            break;
        case 1:
        case 3:
            a = 1.5f;
            break;
        }
    } else if (*D_L39_00241120 >= 2) {
        c = 0.0f;
        r = 0.804817975f;
        b = 10.0f;
        switch (mode) {
        case 0:
            a = 0.5f;
            break;
        case 1:
            a = 1.0f;
            break;
        }
    }
    D_001D84C0_sda = 0.139494002f;
    s.f0 = 0x200;
    D_001D84BC_sda = 0.5f - ((f32)(count - 1) * D_001D84C0_sda) * 0.5f;
    s.f4 = func_L39_005E3A40(mode);
    s.f8 = 0x14;
    s.f1C = D_001D84BC_sda;
    s.f20 = D_001D84C0_sda;
    s.f10 = count < 7 ? count : 6;
    s.f14 = 1;
    s.f18 = 1.0f;
    s.fC = count;
    s.a24[0] = 0.5f;
    s.a24[1] = 1.0f;
    s.a24[2] = 1.0f;
    s.a24[3] = 1.0f;
    s.a34[0] = 0.795206010f;
    s.a34[1] = 0.0f;
    s.a34[2] = 0.0f;
    s.a34[3] = 0.0f;
    s.a44[0] = 0.0f;
    s.a44[1] = 0.0f;
    s.a44[2] = 0.0f;
    s.a44[3] = 0.0f;
    func_L39_005E7E30(func_003B9BD0(idx), &s);
    func_003BABB0(func_003B9BD0(idx), 0, a, r, 0.0450000018f, 0.0425000004f, 0.349999994f);
    func_003BABD0(func_003B9BD0(idx), a, c, r, b);
    func_003BA4E0(func_003B9BD0(idx), 1, 0.0329999998f, 0.00665999995f, 0.0299999993f);
    func_L01_00498F18(func_003B9BD0(idx), 0, 1);
    for (i = 0; i < count; i++) {
        buf = func_L39_005E7FF8(func_003B9BD0(idx), 0, i);
        func_120048(buf, D_L39_00243BD8, func_L39_0059A970(D_001D8478_sda[i].f0));
        func_L39_005E8058(func_003B9BD0(0), i, D_001D8478_sda[i].f4 == 0);
        if (*D_L39_00241120 >= 2) {
            func_L39_005E8F98(func_003B9BD0(idx), 0, i + 1, 1.0f, 2.0f);
        }
        func_003BABB0(func_003B9BD0(idx), 0, 0.5f, r, 0.0900000036f, 0.0425000004f, 0.349999994f);
    }
}
