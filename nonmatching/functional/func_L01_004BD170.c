/* functional: medium. Finishes opening/leaving a Veldin vendor page (called after a purchase and when a page opens): restores the saved byte D_001D5477, clears T+0x8C/0x90, calls func_L01_004BF980, and unless D_L01_001E0F80 is set resets menu/HUD helpers (func_L01_00479280/0047B420/0047B990, func_003A9050, sound 5), copies camera/menu quads into D_L01_001E29D0 when T+0x60 is set, sets the object flag 0x100, puts T+0 = 2 and the display constants, then per page (T+0x50) 5: sets D_L01_001D7BE0 from D_L01_001DABA8 and re-runs func_L01_005147A8/00425978; 3: records the bought id words (D_00142660+0x40/+0x78, T+0x768), re-runs func_L01_00425978 and plays the bought item's message through func_L01_00436660; page 2: refreshes the player model state (D_0016C580) and calls func_003A56F8; finally calls func_0039EC28(0,-1) when a purchase happened on pages 2/3/0/5. D_ names that retail reaches by lui/addiu are unsized arrays; its $gp slots are D_L01_ names (they move per level: level 20 has 0x1E0FE8 at 0x1E1268, so a D_XXXXXXXX_sda name wrote the wrong word there), page 2 re-reads T+0x50 after func_003A56F8 as retail does. Names mine, offsets from asm; the 20-byte table D_L01_001DAD18 is copied to the stack as 5 words (retail uses unaligned loads). a0 for func_00398C80 is (D_001D54D2 & 0x1F) as retail leaves it in the register. */
extern s32 D_00142660[];
extern u8 D_001D5477[];
extern s32 D_001D54D0[];
extern u16 D_001D54D2[];
extern s16 D_001426A0[];
extern s32 D_L01_001E0F80[];
extern s32 D_L01_001E0F7C[];
extern u8 D_L01_001E0FA0[];
extern u8 D_L01_001E29D0[];
extern u8 D_L01_001DAD18[];
extern u8 D_0016C580[];
extern u8 D_L01_001DABA4;
extern s32 D_L01_001DABA8;
extern u8 D_L01_001DABC8;
extern s32 D_L01_001DABCC;
extern s32 D_L01_001DABD0;
extern s32 D_L01_001DABD4;
extern s32 D_L01_001D7BE0;
extern f32 D_L01_001DAC54;
extern f32 D_L01_001DAC58;
extern s32 D_L01_001DAC50;
extern s32 D_L01_001E0FD4[];
extern s32 D_L01_001E0FD8[];
extern s32 D_L01_001E0FDC[];
extern s32 D_L01_001E0FE0[];
extern s32 D_L01_001E0FE4[];
extern s32 D_L01_001E0FE8;

extern void func_L01_004BF980(void);
extern void func_L01_00479280(void);
extern s32 func_L01_0047B420(void);
extern void func_L01_0047B990(void);
extern void func_003A9050(void);
extern s32 func_003A52A0(s32, s32, void *);
extern s32 func_L01_005147A8(s32);
extern void func_L01_00425978(s32);
extern u8 *func_00381FF0(s32);
extern void func_L01_00436660(s32, s32, s32);
extern void func_00398BB8(s32);
extern void func_00398C80(s32);
extern void func_003A56F8(void *);
extern void func_0039EC28(s32, s32);

static void copy16_004BD170(void *d, void *s) {
    ((u64 *)d)[0] = ((u64 *)s)[0];
    ((u64 *)d)[1] = ((u64 *)s)[1];
}

void func_L01_004BD170(void) {
    u8 *T = (u8 *)D_L01_002446C0;
    u8 *obj;
    u8 *p;
    s32 mode;
    s32 v;
    s32 w;
    s32 z;
    s32 a;
    s32 h;
    s32 i;
    u32 tbl[5];

    D_001D5477[0] = D_L01_001DABA4;
    *(s32 *)(T + 0x8C) = 0;
    *(s32 *)(T + 0x90) = 0;
    func_L01_004BF980();
    if (D_L01_001E0F80[0] != 0) {
        return;
    }
    func_L01_00479280();
    func_L01_0047B420();
    func_L01_0047B990();
    func_003A9050();
    D_L01_001E0F7C[0] = 0;
    func_003A52A0(5, 0x11, (void *)*(s32 *)(T + 0x28));
    if (*(s32 *)(T + 0x60) != 0) {
        copy16_004BD170(D_L01_001E29D0 + 0x10, D_L01_001E0FA0);
        copy16_004BD170(D_L01_001E29D0 + 0x30, D_L01_001E0FA0 + 0x20);
        copy16_004BD170(D_L01_001E29D0, T + 0xE0);
        copy16_004BD170(D_L01_001E29D0 + 0x20, D_L01_001E0FA0 + 0x10);
    }
    obj = (u8 *)*(s32 *)(T + 0x28);
    *(u16 *)(obj + 0x34) = *(u16 *)(obj + 0x34) | 0x100;
    *(s32 *)(T + 0x00) = 2;
    mode = *(s32 *)(T + 0x50);
    D_L01_001DAC54 = 1.0f;
    D_L01_001DAC58 = 1.1f;
    D_L01_001E0FD4[0] = 0x41;
    D_L01_001E0FD8[0] = 0x60;
    D_L01_001E0FDC[0] = 0x46;
    D_L01_001DAC50 = 0;
    D_L01_001E0FE0[0] = 0;
    D_L01_001E0FE4[0] = 0;
    D_L01_001E0FE8 = 0;
    if (mode == 5) {
        D_L01_001D7BE0 = D_L01_001DABA8;
        func_L01_005147A8(D_L01_001DABCC);
        func_L01_00425978(D_001426A0[0]);
    } else if (mode == 3) {
        if (D_L01_001DABC8 != 0) {
            v = (u16)D_L01_001DABD0;
        } else {
            v = (u16)D_L01_001DABD4;
        }
        *(s16 *)((u8 *)D_00142660 + 0x40) = v;
        if (D_L01_001DABC8 != 0) {
            w = D_L01_001DABD0;
        } else {
            w = D_L01_001DABD4;
        }
        z = D_L01_001DABD0;
        if (D_L01_001DABC8 == 0) {
            z = 0;
        }
        *(s32 *)((u8 *)D_00142660 + 0x78) = w;
        *(s32 *)(T + 0x768) = z;
        func_L01_00425978(D_L01_001DABD4);
        for (i = 0; i < 5; i++) {
            tbl[i] = ((u32 *)D_L01_001DAD18)[i];
        }
        if (D_L01_001DABC8 != 0) {
            h = *(s16 *)((u8 *)D_00142660 + 0x40);
            func_L01_00436660((s32)func_00381FF0(tbl[h]), -1, 0);
        }
    }
    if (*(s32 *)(T + 0x50) == 2) {
        a = D_001D54D0[0];
        if (*(s32 *)(D_0016C580 + 0x18) != a) {
            func_00398BB8(a & 3);
        }
        h = D_001D54D2[0] & 0x1F;
        if (*(s32 *)(D_0016C580 + 0x30) != h) {
            func_00398C80(h);
        }
        p = (u8 *)*(s32 *)D_0016C580;
        if (p != 0 && *(s32 *)(p + 0x98) != 0) {
            *(s32 *)(p + 0x98) = *(s32 *)(*(u8 **)(p + 0x24) + 0x10);
        }
        func_003A56F8(0);
        if (*(s32 *)(T + 0x50) == 2 && *(s32 *)(T + 0x76C) > 0) {
            func_0039EC28(0, -1);
            return;
        }
    }
    mode = *(s32 *)(T + 0x50);
    if (mode == 3) {
        if (*(s32 *)(T + 0x768) > 0) {
            func_0039EC28(0, -1);
            return;
        }
    }
    if (mode == 0) {
        if (*(s32 *)(T + 0x68) > 0) {
            func_0039EC28(0, -1);
            return;
        }
    }
    if (mode == 5) {
        if (D_L01_001DABC8 != 0) {
            func_0039EC28(0, -1);
        }
    }
}
