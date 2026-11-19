/* functional: high. Item detail panel refresh: looks up the selected item index (func_L01_00485A38 of the two selection globals), shows/hides the three tier icons (ids 0xE0058..0xE005A by tier 5/6/7), and, when the item is owned, formats the five info strings (name, count/level, tier, price, and either the owned-remaining/total line or the 'max' line) into the shared text buffers; when not owned it writes the locked placeholder strings and clears the first byte of D_L01_00233CD8. Same calls, arguments and order as retail; not byte-checked. */
typedef struct {
    u8 pad0;
    u8 tier;
    u8 pad2[2];
    s32 w4;
    u8 pad8[0x60];
    s32 w68;
    u8 pad6C[0x1E];
    u16 h8A;
    u8 pad8C[0x64];
} S_002C5600_00485D00;
extern S_002C5600_00485D00 D_L01_002C5600[];
extern u8 D_001425C0[];
extern u8 D_00142CA0[];
extern s32 D_00142DE0[];
extern s32 D_001427F0[];
extern u8 D_L01_002EA2D8[];
extern s32 D_001D855C;
extern s32 D_001D8560;
extern char D_L01_00233C58[];
extern char D_L01_00233CD8[];
extern char D_001E07D0[];
extern char D_001E07E8[];
extern char D_001E07F0[];
extern char D_001E0810[];
extern char D_001D8648[];
extern char D_001D8650[];
extern char D_001D8660[];
extern char D_001D8668[];
extern char D_001D8670[];
extern char D_001D8680[];
extern char D_001D8688[];
extern char D_001D8698[];
extern char D_001D86A8[];
extern char D_001D86B0[];
extern char D_001D86B8[];

extern s32 func_L01_00485A38(s32, s32);
extern s32 func_L01_00516D60(s32, s32);
extern s32 func_L01_00418DE0(s32, s32);
extern s32 func_00381FF0(s32);
extern s32 func_0011B2E8(char *, ...);
extern s32 func_L01_00485B68(s32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_L01_00485A60(s32, s32);

void func_L01_00485D00(void) {
    s32 idx;
    s32 s23 = 0;
    s32 fp;
    S_002C5600_00485D00 *e;
    s32 k;
    s32 str;
    s32 s17;

    idx = func_L01_00485A38(D_001D855C, D_001D8560);
    func_L01_00516D60(0xE0058, 0);
    func_L01_00516D60(0xE0059, 0);
    func_L01_00516D60(0xE005A, 0);
    if (D_00142CA0[idx] == 0) {
        func_0011B2E8(D_L01_00233C58, D_001D8688);
        func_0011B2E8(D_001E07D0, D_001D8698, func_00381FF0(0x178));
        func_0011B2E8(D_001E07E8, D_001D86A8, func_00381FF0(0xBF5));
        func_0011B2E8(D_001E07F0, D_001D86B0, func_00381FF0(0x1604));
        func_0011B2E8(D_001E0810, D_001D86B8, func_00381FF0(0x1605));
        D_L01_00233CD8[0] = 0;
        return;
    }
    e = &D_L01_002C5600[D_001425C0[idx]];
    if (e->w68 > 0) {
        k = e->tier;
        if (k > 0) {
            func_L01_00418DE0(idx, k - 1);
            e = &D_L01_002C5600[D_001425C0[idx]];
            s23 = e->w68;
            func_L01_00418DE0(idx, k);
            if (!(-1 < s23)) {
                s23 = 0;
            }
        }
    }
    e = &D_L01_002C5600[D_001425C0[idx]];
    switch (e->tier) {
    case 6:
        func_L01_00516D60(0xE0059, 1);
        break;
    case 5:
        func_L01_00516D60(0xE0058, 1);
        break;
    case 7:
        func_L01_00516D60(0xE005A, 1);
        break;
    default:
        break;
    }
    e = &D_L01_002C5600[D_001425C0[idx]];
    fp = (D_00142DE0[idx] >> 5) - s23;
    s23 = e->w68 - s23;
    str = func_00381FF0(e->w4);
    func_0011B2E8(D_L01_00233C58, D_001D8648, str);
    str = func_00381FF0(0x178);
    e = &D_L01_002C5600[D_001425C0[idx]];
    func_0011B2E8(D_001E07D0, D_001D8650, str, D_001427F0[idx], e->h8A);
    str = func_00381FF0(0xBF5);
    e = &D_L01_002C5600[D_001425C0[idx]];
    func_0011B2E8(D_001E07E8, D_001D8660, str, e->tier + 1);
    s17 = func_00381FF0(0x1604);
    func_0011B2E8(D_001E07F0, D_001D8668, s17, func_L01_00485B68(idx));
    if (s23 > 0) {
        if (s23 < 10000) {
            func_L01_00517538(0xE0007, 1.0f, 1.0f);
        } else {
            func_L01_00517538(0xE0007, 0.9f, 1.0f);
        }
        str = func_00381FF0(0x1605);
        func_0011B2E8(D_001E0810, D_001D8670, str, fp, s23);
    } else {
        s17 = func_00381FF0(0x1605);
        str = func_00381FF0(0x1606);
        func_0011B2E8(D_001E0810, D_001D8680, s17, str);
    }
    e = &D_L01_002C5600[D_001425C0[idx]];
    {
        s32 r = func_L01_00485A60(D_001D855C, D_001D8560);
        s32 sid = *(s32 *)(D_L01_002EA2D8 + e->tier * 4 + r * 0x44 + 4);
        func_0011B2E8(D_L01_00233CD8, D_001D8648, func_00381FF0(sid));
    }
}
