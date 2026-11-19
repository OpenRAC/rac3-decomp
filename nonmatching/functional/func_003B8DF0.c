/* functional: medium. Written from PAL's assembly (no draft). Retail keeps the snapshot in one big frame plus a 0x40-byte alloca for the 15 bytes at D_001426E0+0xB0; here they are ordinary locals. Retail also copies D_001D55B0[0..5] into the frame but never writes it back: that dead read is left out. The block copies of D_00142660 (0x80 bytes) and D_1D4BE0 (8 bytes) are struct copies in retail (ldl/ldr when unaligned); here byte copies of the same size. */
typedef struct { u8 b[0x80]; } Blk80_3B8DF0;
typedef struct { u8 b[8]; } Blk8_3B8DF0;
extern u8 D_001426E0[];          /* game progress block: +0x3E, +0x45, +0xB0[15], +0xC1, +0xC3[5], +0xC8 */
extern u8 D_00142660[];          /* 0x80-byte block: +0x00 s32, +0x32 u8, +0x38/+0x3C/+0x44 s32, +0x42 s16, +0x5A/+0x5B u8 */
extern u8 D_1A7E18[];            /* +0x120 u16 */
extern s32 D_001D5528;
extern s32 D_1D4C38;
extern u8 D_1D4BE0[];
extern u8 D_00142CA0[];          /* [156] */
extern s32 D_00142DE0[];         /* [156] */
extern u8 D_001425C0[];          /* [156] */
extern s32 D_001427F0[];         /* [156] */
extern u8 D_1DAA40[];            /* records of 0xF0 bytes, u16 at +0x8A */
extern s32 D_001D54D0;
extern u8 D_001D54B0[];          /* [32] */
extern u8 D_001D5468[];          /* [19] */
extern u8 D_001D5498[];          /* [19] */
extern u16 D_001D55A0[];         /* [6] */
extern u8 D_1BBB18[];            /* 0x128 bytes */
extern u8 D_00142A60[];          /* [156] */
extern u8 D_00142B00[];
extern u16 D_001D54D8[];         /* [32] */
extern s32 D_1D4C60[];           /* [8] */
extern s32 D_1D4C80[];           /* [8] */
extern u8 D_00143950[];
extern u8 D_1A4BE0[];            /* +0x2884 s16 */
extern u8 D_00142430[];          /* save-slot table: +0x18 s16, +0x30 + slot*0x1C s32, +0x148, +0x174 */
extern s32 D_001D8A9C;
extern void func_0038D068(void *, void *, s32);
extern void func_0038CF58(void *, s32, s32);
extern s32 func_003823D0();
extern void func_003C1080(s32);
extern void func_0039C6E0(void);
extern void func_00381C90(s32, s32);
extern void func_0039E9C0(s32);

void func_003B8DF0(s32 slot) {
    s32 cA0[156];               /* D_00142CA0, with some entries cleared */
    s32 cDE0[156];              /* D_00142DE0 */
    s32 c5C0[156];              /* D_001425C0 */
    s32 c4B0[32];               /* D_001D54B0 */
    u8 a60[156];                /* D_00142A60 */
    s32 c4D8[32];               /* D_001D54D8 */
    u8 g3[5];                   /* D_001426E0 + 0xC3 */
    u16 c5A0[6];                /* D_001D55A0 */
    s32 c468[19];               /* D_001D5468 */
    s32 c498[19];               /* D_001D5498 */
    s32 gB0[16];                /* D_001426E0 + 0xB0 (retail: alloca) */
    Blk80_3B8DF0 savedP;
    Blk8_3B8DF0 saved4BE0;
    u8 bbb18[0x128];
    s32 gC1, gC8, g3E, g45, e120, s5528, s4C38, s54D0;
    s32 i, keep;

    gC1 = D_001426E0[0xC1];
    e120 = *(u16 *)(D_1A7E18 + 0x120);
    g3E = D_001426E0[0x3E];
    gC8 = D_001426E0[0xC8];
    D_00142660[0x32] = D_00142660[0x32] + 1;
    *(s32 *)D_00142660 = *(s32 *)D_00142660 + 2;
    D_00142660[0x5A] = 0;
    D_00142660[0x5B] = 0;
    savedP = *(Blk80_3B8DF0 *)D_00142660;
    s5528 = D_001D5528;
    s4C38 = D_1D4C38;
    saved4BE0 = *(Blk8_3B8DF0 *)D_1D4BE0;
    for (i = 0; i < 15; i++) {
        gB0[i] = D_001426E0[0xB0 + i];
    }
    for (i = 0; i < 156; i++) {
        cA0[i] = D_00142CA0[i];
        cDE0[i] = D_00142DE0[i];
        c5C0[i] = D_001425C0[i];
    }
    s54D0 = D_001D54D0;
    for (i = 0; i < 5; i++) {
        g3[i] = D_001426E0[0xC3 + i];
    }
    for (i = 0; i < 32; i++) {
        c4B0[i] = D_001D54B0[i];
    }
    for (i = 0; i < 19; i++) {
        c468[i] = D_001D5468[i];
        c498[i] = D_001D5498[i];
    }
    for (i = 0; i < 6; i++) {
        c5A0[i] = D_001D55A0[i];
    }
    /* these entries of D_00142CA0 come back cleared */
    cA0[27] = 0; cA0[14] = 0; cA0[11] = 0; cA0[24] = 0; cA0[30] = 0;
    cA0[15] = 0; cA0[2] = 0;  cA0[3] = 0;  cA0[4] = 0;  cA0[13] = 0;
    cA0[8] = 0;  cA0[31] = 0; cA0[18] = 0; cA0[33] = 0; cA0[34] = 0;
    func_0038D068(bbb18, D_1BBB18, 0x128);
    g45 = D_001426E0[0x45];
    for (i = 0; i < 156; i++) {
        a60[i] = D_00142A60[i];
    }
    for (i = 0; i < 32; i++) {
        c4D8[i] = D_001D54D8[i];
    }

    func_003C1080(func_003823D0(0xBB7));
    func_0039C6E0();

    for (i = 0; i < 32; i++) {
        D_001D54D8[i] = c4D8[i];
    }
    D_001426E0[0x3E] = g3E;
    D_001426E0[0xC8] = gC8;
    D_001426E0[0xC1] = gC1;
    func_0038D068(D_1BBB18, bbb18, 0x128);
    D_001426E0[0x45] = g45;
    for (i = 0; i < 6; i++) {
        D_001D55A0[i] = c5A0[i];
    }
    for (i = 0; i < 15; i++) {
        D_001426E0[0xB0 + i] = gB0[i];
    }
    func_0038CF58(D_00142B00, 0, 0x9C);
    for (i = 0; i < 156; i++) {
        D_00142A60[i] = a60[i];
    }
    for (i = 0; i < 8; i++) {
        D_1D4C60[i] = 0;
        D_1D4C80[i] = 0;
    }
    D_001D5528 = s5528;
    D_1D4C38 = s4C38;
    *(Blk8_3B8DF0 *)D_1D4BE0 = saved4BE0;
    *(Blk80_3B8DF0 *)D_00142660 = savedP;
    *(s32 *)(D_00142660 + 0x3C) = 0;
    D_00143950[5] = 0;
    *(s16 *)(D_00142660 + 0x42) = 0;
    *(s32 *)(D_00142660 + 0x44) = 0;
    *(s32 *)(D_00142660 + 0x38) = 0;
    D_00143950[4] = 0;
    if (e120 != 0 && *(u16 *)(D_1A7E18 + 0x120) == 0) {
        *(u16 *)(D_1A7E18 + 0x120) = 1;
    }
    for (i = 0; i < 5; i++) {
        D_001426E0[0xC3 + i] = g3[i];
    }
    for (i = 0; i < 156; i++) {
        u8 v;
        D_00142CA0[i] = cA0[i];
        D_00142DE0[i] = cDE0[i];
        v = c5C0[i];
        D_001425C0[i] = v;
        D_001427F0[i] = *(u16 *)(D_1DAA40 + v * 0xF0 + 0x8A);
    }
    for (i = 0; i < 32; i++) {
        D_001D54B0[i] = c4B0[i];
    }
    for (i = 0; i < 19; i++) {
        D_001D5468[i] = c468[i];
        D_001D5498[i] = c498[i];
    }
    D_00143950[4] = 0;
    D_00143950[5] = 0;
    func_00381C90(9, 3);
    *(s16 *)(D_1A4BE0 + 0x2884) = 1;
    D_001D54D0 = s54D0;
    if (slot >= 0) {
        s32 *p;
        *(s16 *)(D_00142430 + 0x18) = slot;
        p = (s32 *)(D_00142430 + 0x30 + slot * 0x1C);
        keep = *p;
        *p = 1;
        func_0039E9C0(D_001D8A9C);
        *p = keep;
        *(s32 *)(D_00142430 + 0x174) = D_001D8A9C;
        *(s32 *)(D_00142430 + 0x148) = 0;
    }
}
