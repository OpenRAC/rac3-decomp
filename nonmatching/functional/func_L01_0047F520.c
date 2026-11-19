/* functional: high. Builds the pause/options menu layout: picks one of three entry lists by menu mode, clamps the scroll index, then creates the title/frame/entry/arrow widgets with the same ids, colours and float args as retail. Float constants are the exact retail bit patterns; not byte-checked. */
extern s32 D_001D545C;
extern s32 D_001D7BE0;
extern s32 *D_001D82E0;
extern f32 *D_001D82E4;
extern s32 D_001D82E8;
extern s32 D_001D82EC;
extern s32 D_001D82F0;
extern f32 D_001D82F4;
extern f32 D_001D82F8;
extern f32 D_001D82FC;
extern f32 D_001D82C8[];
extern f32 D_001D82D0[];
extern f32 D_001D82D8[];
extern s32 D_L01_002EA0C0[];
extern s32 D_L01_002EA178[];
extern s32 D_L01_002EA020[];
extern u8 D_00143950[];

extern s32 func_003E8EF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003B5060(s32);
extern s32 func_003E8AE8(s32, s32, s32, s32, s32, s32);
extern s32 func_003E8348(s32, s32);
extern s32 func_00381FF0(s32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_L01_00517538(s32, f32, f32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_003E8A08(s32, s32, s32);

void func_L01_0047F520(void) {
    s32 mode = D_001D545C;
    s32 flag;
    s32 cnt;
    s32 old;
    s32 i;
    s32 off;
    f32 f21;
    f32 f20;
    f32 zero = 0.0f;
    f32 one = 1.0f;
    f32 half = 0.5f;
    s32 useDefault = 0;

    if (mode == 0xC || mode == 0x12 || mode == 0x14 || mode == 0x1A || mode == 0x1D || mode == 4) {
        if (D_001D7BE0 != -1) {
            D_001D82E0 = D_L01_002EA0C0;
            D_001D82E4 = D_001D82D0;
            cnt = 9;
            flag = 1;
        } else {
            useDefault = 1;
        }
    } else if (mode == 7 || mode == 3) {
        if (D_001D7BE0 != -1) {
            D_001D82E0 = D_L01_002EA178;
            D_001D82E4 = D_001D82D8;
            cnt = 9;
            flag = 1;
        } else {
            useDefault = 1;
        }
    } else {
        useDefault = 1;
    }
    if (useDefault) {
        D_001D82E0 = D_L01_002EA020;
        D_001D82E4 = D_001D82C8;
        cnt = 8;
        flag = 0;
    }
    D_001D82EC = cnt;
    old = D_001D82F0;
    if (old != flag) {
        D_001D82F0 = flag;
        D_001D82E8 = D_001D82E8 + (flag - old);
    }
    if (cnt < D_001D82E8) {
        D_001D82E8 = cnt;
    }
    if (D_001D82E8 < 0) {
        D_001D82E8 = 0;
    }
    f21 = (f32)cnt * 0.09f + -0.18f;
    if (f21 < zero) {
        f21 = zero;
    }
    f21 = f21 + one;
    func_003E8EF0(0xD0000, 0x3D, 0x332299DE, half, half, one, one, f21);
    func_003E8EF0(0xD0001, 0x3E, 0x332299DE, half, half, one, one, f21);
    func_003E8EF0(0xD0002, 0x3F, 0x331465B7, half, half, one, one, f21);
    func_003E8EF0(0xD0003, 0x40, 0x802299DE, half, half, one, one, f21);
    func_003E9138(0xD0028, 0x402299DE, 0, half, half, 0.333333f, 0.025f);
    func_003B5060(0xD000B);
    func_003E8AE8(0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0028);
    func_003E8348(0x10, 0xD000B);
    func_003B5060(0xD0025);
    func_003B5060(0xD0026);
    if (D_001D82EC > 0) {
        off = 0;
        for (i = 0; ; ) {
            s32 *e = (s32 *)((u8 *)D_001D82E0 + off);
            s32 r = func_00381FF0(e[1]);
            func_003E8FE8(e[0], r, 0x8066CCFF, zero, zero, one, one);
            func_L01_00516AA0(*(s32 *)((u8 *)D_001D82E0 + off), 0x40, 1);
            func_003E8630(0xD0025, *(s32 *)((u8 *)D_001D82E0 + off));
            if (i < D_001D82EC - 1) {
                s32 h = 0xD0019 + i;
                func_003E9138(h, 0x202299DE, 0, zero, zero, one, one);
                func_003E8630(0xD0026, h);
            }
            if (D_00143950[0xB7] >= 2) {
                func_L01_00517538(*(s32 *)((u8 *)D_001D82E0 + off), 0.7f, 0.8f);
            }
            i++;
            if (!(i < D_001D82EC)) {
                break;
            }
            off += 0x14;
        }
    }
    func_003E8630(0xD0025, 0xD0026);
    func_003E8348(0x11, 0xD0025);
    cnt = D_001D82EC;
    f20 = 0.5f - (f32)(cnt - 1) * 0.03f;
    if (cnt > 0) {
        off = 0;
        for (i = 0; ; ) {
            func_L01_00516470(*(s32 *)((u8 *)D_001D82E0 + off), half, f20);
            if (i < D_001D82EC - 1) {
                s32 h = 0xD0019 + i;
                f32 f13 = D_001D82F4;
                func_L01_00516470(h, half, f20 + f13 * half);
                func_L01_00517538(h, 0.43f, 0.0048f);
            }
            f20 = f20 + D_001D82F4;
            i++;
            if (!(i < D_001D82EC)) {
                break;
            }
            off += 0x14;
        }
    }
    func_003E9138(0x5A0001, 0x332299DE, 0xED5A, D_001D82F8, D_001D82E4[0], -0.07f, 0.08615385f);
    func_003E9138(0x5A0002, 0x332299DE, 0xED5A, D_001D82FC, D_001D82E4[1], 0.07f, -0.08615385f);
    func_003E8A08(0xD000B, 0x5A0001, 0x5A0002);
}
