/* functional: medium-high. Builds the options/settings screen: creates the title and text widgets, the 7 row labels (formatted through sprintf-style calls using string ids, enabled/disabled colour flags kept at row+0xC/+0xD), the cursor/scrollbar widgets, and finally snapshots 19 bytes of the saved options (D_001D5468 -> D_001D5480). Same calls, arguments and order as retail; the first-call-only init of the layout struct is guarded by D_L01_001E06A8. Float constants are retail's exact bit patterns; stack args of the 15-argument call follow the matched prototype. Level data above 0x1D5680 (the gp slots 1D8318..1D8360, 1E06A8) is named D_L01_ since it moves per level. Not byte-checked. */
typedef struct {
    s32 strId;
    s32 type;
    s32 arg;
    u8 on;
    u8 on2;
    u8 pad[2];
    s32 (*check)(s32);
    s32 pad14;
} OptRow_00480170;
extern u8 D_L01_00233A00[];
extern OptRow_00480170 D_L01_002EA230[];
extern u8 D_00160C40[];
extern u8 D_001D5468[];
extern u8 D_001D5480[];
extern s32 D_L01_001E06A8;
extern s32 D_L01_001D8318;
extern f32 D_L01_001D831C;
extern f32 D_L01_001D8320;
extern f32 D_L01_001D8324;
extern f32 D_L01_001D8328;
extern f32 D_L01_001D832C;
extern f32 D_L01_001D8330;
extern f32 D_L01_001D8334;
extern f32 D_L01_001D8338;
extern f32 D_L01_001D833C;
extern f32 D_L01_001D8340;
extern f32 D_L01_001D8344;
extern f32 D_L01_001D8348;
extern f32 D_L01_001D834C;
extern char D_L01_001D8350[];
extern char D_L01_001D8358[];
extern char D_L01_001D8360[];

extern s32 func_00381FF0(s32);
extern s32 func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, f32, s32, s32, s32, s32, s32, s32);
extern s32 func_003B5060(s32);
extern s32 func_003E8348(s32, s32);
extern s32 func_003E9138(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern void *func_003BB3A8(s32);
extern void *func_003B42F8(s32);
extern s32 func_003B4528(void *, s32, s32, s32, s32);
extern s32 func_003E8710(s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_0011A264(void *, s32, s32);
extern void func_L01_0047DE68(void);
extern s32 func_L01_0047DAE0(void);
extern s32 func_003BB118(s32);
extern s32 func_003B9BD0(s32);
extern s32 func_003B9C68(s32, void *);
extern void func_003BABB0(s32, f32, f32, f32, f32, f32, s32);
extern void func_003BABD0(s32, f32, f32, f32, f32);
extern s32 func_003B9E30(s32, s32, s32);
extern void func_L01_00498948(s32, s32, s32);
extern s32 func_0011B2E8(char *, ...);
extern void func_003BA358(s32, s32, s32, s32);
extern s32 func_003E9270(s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_003E8A08(s32, s32, s32);

void func_L01_00480170(void) {
    s32 str;
    u32 i;
    s32 off;
    s32 h;
    char *dst;
    s32 on;
    s32 sub;
    f32 one = 1.0f;
    f32 half;
    u8 *S2;
    s32 v;
    s32 n;

    str = func_00381FF0(0x1C1);
    func_003B9298(0x10, 0xD000B, 0xD0002, 0xD0003, 0xD0004, 0xD0000, 0xD0001, 0xD0005, 8.5f,
                  0xD0008, str, 0xD0006, 0xFF, 0xD0007, 0x177);
    func_003B5060(0x520000);
    func_003E8348(0x11, 0x520000);
    func_003E9138(0x520003, 0x80808080, 1, D_L01_001D831C, D_L01_001D8320, D_L01_001D8324, D_L01_001D8328);
    v = func_00381FF0(0x1C1);
    func_003E8FE8(0x520004, v, 0x8066CCFF, D_L01_001D8344, D_L01_001D8348, one, one);
    v = func_00381FF0(0x1BF);
    func_003E8FE8(0x520005, v, 0x8066CCFF, D_L01_001D834C, D_L01_001D8348, one, one);
    D_L01_001D8318 = (s32)func_003BB3A8(0);
    func_003B4528(func_003B42F8(0), D_L01_001D8318, 0, *(s32 *)(D_00160C40 + 0x694), (s32)(D_00160C40 + 0x10E0));
    func_003E8710(0x520003, (s32)func_003B42F8(0));
    func_003E8630(0x520000, 0x520003);
    func_003E8630(0x520000, 0x520004);
    func_003E8630(0x520000, 0x520005);
    S2 = D_L01_00233A00;
    if (D_L01_001E06A8 == 0) {
        func_0011A264(S2, 0, 0x54);
        *(f32 *)(S2 + 0x48) = 0.75f;
        *(s32 *)(S2 + 0x8) = 0x14;
        *(s32 *)(S2 + 0x10) = 7;
        *(s32 *)(S2 + 0x14) = 2;
        *(f32 *)(S2 + 0x18) = one;
        *(f32 *)(S2 + 0x1C) = 0.45f;
        *(f32 *)(S2 + 0x20) = 0.053f;
        *(f32 *)(S2 + 0x24) = 0.11f;
        *(f32 *)(S2 + 0x28) = 0.89f;
        *(f32 *)(S2 + 0x38) = 0.35f;
        D_L01_001E06A8 = 1;
        *(s32 *)(S2 + 0xC) = 7;
        *(f32 *)(S2 + 0x34) = 0.35f;
        *(f32 *)(S2 + 0x44) = 0.75f;
    }
    func_L01_0047DE68();
    *(s32 *)S2 = func_L01_0047DAE0();
    *(s32 *)(S2 + 4) = func_003BB118(0);
    func_003B9C68(func_003B9BD0(0), S2);
    half = 0.5f;
    func_003BABB0(func_003B9BD0(0), half, 0.79f, 0.045f, 0.38f, 0.35f, 1);
    func_003BABD0(func_003B9BD0(0), half, 0.58f, 0.81f, 0.56f);

    i = 0;
    off = 0;
    for (;;) {
        OptRow_00480170 *row = (OptRow_00480170 *)((u8 *)D_L01_002EA230 + off);
        if (row->check != 0 && row->check(row->arg) != 0) {
            dst = (char *)func_003B9E30(func_003B9BD0(0), 0, i);
            func_0011B2E8(dst, D_L01_001D8350, func_00381FF0(row->strId));
            if (row->type == 0x11) {
                dst = (char *)func_003B9E30(func_003B9BD0(0), 1, i);
                func_0011B2E8(dst, (char *)func_00381FF0(0x16FB));
            } else {
                dst = (char *)func_003B9E30(func_003B9BD0(0), 1, i);
                func_0011B2E8(dst, D_L01_001D8358, row->arg);
            }
            row->on = 1;
            on = (D_001D5468[row->type] != 0);
            sub = 3;
            if (!on) {
                sub = 0;
            }
            row->on2 = on;
            func_L01_00498948(func_003B9BD0(0), i, sub);
        } else {
            dst = (char *)func_003B9E30(func_003B9BD0(0), 0, i);
            func_0011B2E8(dst, D_L01_001D8350, func_00381FF0(0x16CE));
            if (row->type == 0x11) {
                dst = (char *)func_003B9E30(func_003B9BD0(0), 1, i);
                func_0011B2E8(dst, (char *)func_00381FF0(0x16CE));
            } else {
                dst = (char *)func_003B9E30(func_003B9BD0(0), 1, i);
                h = func_00381FF0(0x1BF);
                func_0011B2E8(dst, D_L01_001D8360, row->arg, h);
            }
            row->on = 0;
            row->on2 = 0;
            func_L01_00498948(func_003B9BD0(0), i, 1);
        }
        i++;
        off += 0x18;
        if (!(i < 7)) {
            break;
        }
    }
    func_003BA358(func_003B9BD0(0), 0, 1, 3);
    func_003BA358(func_003B9BD0(0), 1, 3, 3);
    func_003E9270(0x520001, 0x332299DE, D_L01_001D8334, D_L01_001D8338, D_L01_001D833C, D_L01_001D8340, 0.0035f, 0.006f);
    func_003E9270(0x520002, 0x332299DE, D_L01_001D831C, D_L01_001D832C, D_L01_001D8324, D_L01_001D8330, 0.0035f, 0.006f);
    func_003E8A08(0x520000, 0x520001, 0x520002);
    for (n = 0; n < 19; n++) {
        D_001D5480[n] = D_001D5468[n];
    }
}
