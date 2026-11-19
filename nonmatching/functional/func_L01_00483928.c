/* functional: high. Builds a three-entry choice popup: four corner frame quads (mirrored by the +/-0.5 offsets), title/background widgets, the three text lines (the third copied to a local buffer with control bytes 0x12 and 0x3A stripped), then lays the three entries out vertically with spacing 2*D_001D84F0. Same calls, arguments and order as retail; floats are retail's exact constants. Not byte-checked. */
extern f32 D_001D84E4;
extern f32 D_001D84E8;
extern f32 D_001D84EC;
extern f32 D_001D84F0;
extern f32 D_001D84F4;
extern f32 D_001D84F8;
extern f32 D_001D84FC;
extern f32 D_001D8500;
extern s32 D_001D84B0[];
extern s32 D_001D84B4;
extern s32 D_001D84C4;
extern s32 D_001D84D4;
extern char D_001E06F0[];
extern u8 D_00143950[];

extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern void func_L01_00516B90(s32, s32, s32);
extern s32 func_L01_00517190(s32, s32);
extern s32 func_003B5060(s32);
extern s32 func_003E8B98(s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E8348(s32, s32);
extern s32 func_00381FF0(s32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_0011B868(char *);
extern s32 func_L01_00516AA0(s32, s32, s32);
extern s32 func_L01_00518110(s32, s32, s32, s32);
extern s32 func_L01_00516470(s32, f32, f32);
extern s32 func_L01_00517538(s32, f32, f32);

void func_L01_00483928(void) {
    f32 half = 0.5f;
    f32 zero = 0.0f;
    f32 one = 1.0f;
    f32 e;
    f32 f20, f21;
    char *s16;
    s32 v, i, idx, n, handle;
    s32 *p;

    func_003E9138(0x100000, 0x80808080, 0, D_001D84F4 + half, D_001D84F8 + half, D_001D84E4, D_001D84E4);
    func_L01_00516B90(0x100000, 2, 2);
    func_L01_00517190(0x100000, 0xED93);
    e = D_001D84E4;
    func_003E9138(0x100001, 0x80808080, 0, half - D_001D84F4, D_001D84F8 + half, -e, e);
    func_L01_00516B90(0x100001, 2, 2);
    func_L01_00517190(0x100001, 0xED93);
    e = D_001D84E4;
    func_003E9138(0x100002, 0x80808080, 0, D_001D84F4 + half, half - D_001D84F8, e, -e);
    func_L01_00516B90(0x100002, 2, 2);
    func_L01_00517190(0x100002, 0xED93);
    e = -D_001D84E4;
    func_003E9138(0x100003, 0x80808080, 0, half - D_001D84F4, half - D_001D84F8, e, e);
    func_L01_00516B90(0x100003, 2, 2);
    func_L01_00517190(0x100003, 0xED93);
    func_003E9138(0xD0028, 0x36808080, 0, half, half, D_001D84EC, D_001D84E8);
    func_L01_00516B90(0xD0028, 3, 3);
    e = D_001D84E4;
    func_003E9138(0x100004, 0x80808080, 0, half, half, D_001D84FC * e, D_001D8500 * e);
    func_L01_00516B90(0x100004, 3, 3);
    func_L01_00517190(0x100004, 0xED89);
    func_003B5060(0xD000B);
    func_003E8B98(0xD000B, 0x100004, 0x100000, 0x100001, 0x100002, 0x100003, 0xD0028);
    func_003E8348(0x10, 0xD000B);
    s16 = (char *)func_00381FF0(D_001D84D4);
    v = func_00381FF0(D_001D84B4);
    func_003E8FE8(0xD000C, v, 0x8066CCFF, zero, zero, one, one);
    v = func_00381FF0(D_001D84C4);
    func_003E8FE8(0xD000D, v, 0x8066CCFF, zero, zero, one, one);
    idx = 0;
    n = 0;
    for (;;) {
        s32 old = idx;
        u8 c;
        s32 len = func_0011B868(s16);
        idx++;
        if (!((u32)old < (u32)len)) {
            break;
        }
        c = (u8)s16[old];
        if (c != 0x12 && c != 0x3A) {
            D_001E06F0[n] = c;
            n++;
        }
    }
    D_001E06F0[n] = 0;
    func_003E8FE8(0xD000E, (s32)D_001E06F0, 0x8066CCFF, zero, zero, one, one);
    p = D_001D84B0;
    func_L01_00516AA0(0xD000C, 0x40, 1);
    func_L01_00516AA0(0xD000D, 0x40, 1);
    func_L01_00516AA0(0xD000E, 0x40, 1);
    func_003B5060(0xD0025);
    func_L01_00518110(0xD0025, 0xD000C, 0xD000D, 0xD000E);
    func_003E8348(0x11, 0xD0025);
    f20 = D_001D84F0 + D_001D84F0;
    f21 = half - f20 * half;
    i = 0;
    do {
        s32 old = i;
        f32 f13 = (f32)old;
        i++;
        func_L01_00516470(p[0], half, f21 + f20 * f13 * half);
        if (D_00143950[0xB7] >= 2) {
            func_L01_00517538(p[0], 0.7f, 0.8f);
        }
        p += 4;
    } while (i < 3);
}
