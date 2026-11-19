/* functional: high. level init: clears the L01 effect/slot tables, relocates the D_L01_001E1070 base by -0x60000, resets the 0x16C580 player-state fields and waits for the load/transition state (0x76,0x9E,0x98 of D_001CCFD0) to settle. The do-once loop over D_L01_001DF950/958 (count 1) is written as plain stores. D_0016C580_004AC900 is an alias suffix because the file declares D_0016C580 with another type; same symbol. */
extern u8 D_0016C580_004AC900[];
extern u8 D_001CCFD0[];
extern u8 D_001A4BE0[];
extern u8 D_L01_001E6D80[];
extern u8 D_L01_001E13E0[];
extern u8 D_L01_00251400[];
extern u8 D_L01_001E1420[];
extern u8 D_L01_001EA940[];
extern s32 D_L01_001E1070[];
extern f32 D_L01_001DF950[];
extern s32 D_L01_001DF958[];
extern void func_0038CB78(unsigned int *, unsigned int, int);
extern void func_003A9050(void);
extern void func_L01_005003D0(s32, s32);
extern void func_L01_005108C0(s32);
extern void func_L01_004B9798(s32);
extern void func_0038A238(s32);
extern void func_003A2750(s32);
extern void func_L01_0042C740(s32, s32);
extern void func_003A2B68(s32, s32);
extern void func_0039A690(s32);
extern void func_003A4288(void);
extern void func_12C908(s32);
extern void func_003A1798(void);

void func_L01_004AC900(s32 a0) {
    u8 *r = D_0016C580_004AC900;
    u8 *o;
    s32 base;
    s32 mode;
    s32 h;

    *(s16 *)(r + 0x22) = -1;
    *(s32 *)(r + 0x6C) = 0;
    *(s16 *)(r + 0x20) = a0;
    *(s32 *)(r + 0x8) = 0;
    func_0038CB78((unsigned int *)D_L01_001E6D80, 0, 0x1E0);
    func_0038CB78((unsigned int *)D_L01_001E13E0, 0, 0x40);
    func_0038CB78((unsigned int *)D_L01_00251400, 0, 0x40);
    func_0038CB78((unsigned int *)(D_L01_00251400 + 0x40), 0, 0x40);
    func_0038CB78((unsigned int *)D_L01_001E1420, 0, 0x40);
    func_003A9050();
    base = D_L01_001E1070[0] + (s32)0xFFFA0000;
    D_L01_001E1070[0] = base;
    *(s32 *)(D_L01_001E6D80 + 0x68) = *(s32 *)(D_L01_001EA940 + 0xC) + base;
    *(s32 *)(D_L01_001E6D80 + 0x6C) = *(s32 *)(D_L01_001EA940 + 0x10) + base;
    D_L01_001DF950[0] = 1.0f;
    D_L01_001DF958[0] = 0;
    func_L01_005003D0(0x65, 2);
    D_001A4BE0[0x25E5] = 1;
    func_L01_005108C0(0);
    func_L01_004B9798(1);
    o = *(u8 **)r;
    *(u16 *)(o + 0x34) |= 1;
    if (*(s16 *)(D_001CCFD0 + 4) != 0) {
        func_0038A238(5);
        func_003A2750(1);
    }
    if (a0 == 0) {
        mode = 2;
        func_L01_0042C740(1, 5);
    } else {
        h = *(s16 *)(r + 0x2A);
        mode = h == 0;
        func_L01_0042C740(0, h != 0 ? 0 : 2);
    }
    func_003A2B68(mode | 0x1388, 0);
    func_0039A690(0);
    while (*(s16 *)(D_001CCFD0 + 0x76) != 0 || *(s16 *)(D_001CCFD0 + 0x9E) != 3 || *(s16 *)(D_001CCFD0 + 0x98) >= 0x1B58) {
        func_003A4288();
        func_12C908(0);
    }
    func_003A1798();
}
