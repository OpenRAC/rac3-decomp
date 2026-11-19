/* functional: high. Read against the asm; the one-pass loop over D_L01_001DF950/958 is plain stores; retail stores D_001E1070 and D_001D6674/D_001D5638 gp-relative (here named D_..._sda / asm-sized externs); the delay-slot store D_001E1070=v is done before the func_003A8220 call. D_0016C580_004ACBC8 is an alias suffix for the file's differently typed D_0016C580. */
extern u8 D_0016C580_004ACBC8[];
extern u8 D_001A4BE0[];
extern u32 D_001D545C;
extern s32 D_001D673C;
extern s32 D_00143950;
extern u8 D_001D5638;
extern s32 D_001D6674_sda;
extern u8 D_L01_001E6D80[];
extern s32 D_L01_001E1060[];
extern s32 D_L01_001E1070[];
extern s32 D_L01_001DFB44;
extern f32 D_L01_001DF950[];
extern s32 D_L01_001DF958[];
__asm__(".extern D_001D6674_sda, 4");
__asm__(".extern D_001D5638, 1");
extern void func_L01_004AC900(s32);
extern void func_0039A690(s32);
extern void func_0039EC28(s32, s32);
extern void func_L01_005003D0(s32, s32);
extern void func_L01_005108C0(s32);
extern void func_L01_004B9798(s32);
extern void func_003A9050(void);
extern void func_003A8220(s32, s32);

void func_L01_004ACBC8(s32 a0) {
    u8 *r = D_0016C580_004ACBC8;
    s32 k;
    s32 v;

    D_L01_001DF950[0] = 1.0f;
    D_L01_001DF958[0] = 0;
    *(s16 *)(r + 0x20) = 0;
    *(s16 *)(r + 0x22) = -1;
    if (D_001D545C == (u32)a0) {
        func_L01_004AC900(3);
        k = D_00143950 != 0 ? 0x50 : 0x60;
        *(s32 *)(D_L01_001E6D80 + 0x3C) = 0;
        *(s32 *)(D_L01_001E6D80 + 0x34) = 0;
        func_0039A690(0);
        *(s32 *)(D_L01_001E6D80 + 0x38) = *(s32 *)(D_L01_001E6D80 + 0x34) % k;
    } else if (D_001D673C != 0) {
        D_L01_001DFB44 = a0;
        D_001D6674_sda = 1;
    } else {
        if (D_001D5638 != 0) {
            D_001D5638 = 0;
        } else {
            func_0039EC28(0, a0);
        }
        func_L01_005003D0(0x65, 2);
        D_001A4BE0[0x25E5] = 1;
        func_L01_005108C0(0);
        func_L01_004B9798(1);
        D_L01_001DFB44 = a0;
        *(s16 *)(r + 0x22) = -1;
        *(s16 *)(r + 0x20) = 1;
        func_003A9050();
        v = D_L01_001E1070[0] + (s32)0xFFFA0000;
        D_L01_001E1070[0] = v;
        func_003A8220(D_L01_001E1060[0] + v, v);
    }
}
