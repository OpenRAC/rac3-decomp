/* functional: medium. Written from the asm, no draft; compiles with the file flags. The 17 func_L01_003FF4E8 argument sets were checked by simulating the asm. Case numbers assume the jump table (not in the level asm) lists the 7 case blocks in code order 0..6, which matches the state flow 0->1->2->3->4->5->6->0. The 0x142BBC/0x143A07 absolute data and D_001D60C4_sda ($gp-0x67EC) are named by address. */
/* localdecomp:start func_L01_003FEA68 */
extern s32 D_001D4CEC;
extern s32 D_001D4BC0;
extern u8 D_001D60C4_sda;
extern s32 D_L01_001E64C0[];
extern u8 *D_001D52FC;
extern s16 D_001CCFD4[];
extern s32 D_L01_001E6D50;
extern u8 D_00143A07;
extern u8 D_00160C40[];
extern u32 D_00142BBC;
extern u8 D_L01_001EA7C0[];
extern f32 D_L01_001DF950;
extern void func_L01_003FF4E8(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, u32);
extern void func_003A0EC0(s32, s32, s32, s32, s32);
extern void func_003A0F98(s32, s32);
extern void func_003A2598(s32, s32, s32);
extern void func_003A4288(void);
extern s32 func_L01_0045A6F0(void);
extern void func_L01_00400100(void);
extern s32 func_0038CAD0(void *);
extern f32 func_003C4138(f32 *, f32, f32);
extern s32 func_L01_004001C8(void);
extern void func_L01_004001E8(void);
extern s32 func_00392B20(void *, s32);
extern void func_00392C78(void *);
extern s32 func_L01_004BA800(void);
void func_L01_003FEA68(void) {
    u8 *g;
    s32 r, k;
    D_001D60C4_sda = 0;
    if (D_001D4CEC & 1) {
        D_001D60C4_sda = 1;
        func_003A0EC0(4, 1, 1, 0, 0);
        return;
    }
    g = (u8 *)D_L01_001E64C0;
    if ((u32)(*(u16 *)(g + 0x28) - 1) < 4u) {
        if (*(unsigned long *)(D_001D52FC + 0x1A0) & ((unsigned long)0xF000 << 24)) {
            *(s16 *)(g + 0x28) = 5;
        }
    }
    switch (*(s16 *)(g + 0x28)) {
    case 0:
        if (D_001CCFD4[0] != 0) break;
        func_L01_003FF4E8(0x1FDC, 0x1FDD, 0x2056, 1, 0x28, 0x50, 1, 0xA, 0x20, 0, 0);
        func_L01_003FF4E8(0x20B9, 0x20BA, 0x20BB, 2, 0x28, 0x50, 0, 2, 0x82, 2, 1);
        func_L01_003FF4E8(0x2090, 0x2091, 0x2096, 3, 0x28, 0x50, 0, 6, 0x38, 6, 2);
        func_L01_003FF4E8(0x2097, 0x2098, 0x2099, 4, 0x28, 0x50, 0, 2, 0x50, 2, 3);
        func_L01_003FF4E8(0x209A, 0x209B, 0x20A4, 5, 0x28, 0x50, 0, 0xA, 0x20, 0xA, 4);
        func_L01_003FF4E8(0x2090, 0x20A5, 0x20B4, 6, 0x28, 0x50, 0, 2, 0xA0, 6, 5);
        func_L01_003FF4E8(0x20B5, 0x20B6, 0x20B8, 7, 0x28, 0x50, 0, 2, 0xA0, 6, 6);
        func_L01_003FF4E8(0x20C2, 0x20C3, 0x20D0, 8, 0x28, 0x50, 0, 2, 0x96, 5, 7);
        func_L01_003FF4E8(0x20BC, 0x20BD, 0x20C1, 9, 0x28, 0x50, 0, 5, 0x38, 5, 8);
        func_L01_003FF4E8(0, 0x208B, 0x208B, 0xA, 0, 0xA0, 0, 1, 0x64, 1, 9);
        func_L01_003FF4E8(0, 0x20E8, 0x20E8, 0xB, 0, 0xA0, 0, 1, 0x64, 1, 10);
        func_L01_003FF4E8(0, 0x208A, 0x208A, 0xC, 0, 0xA0, 0, 1, 0x64, 1, 11);
        func_L01_003FF4E8(0, 0x20D2, 0x20D2, 0xD, 0, 0xA0, 0, 1, 0x64, 1, 12);
        func_L01_003FF4E8(0, 0x20D4, 0x20D4, 0xE, 0, 0x50, 0, 1, 0xC8, 6, 13);
        func_L01_003FF4E8(0x20D5, 0x20D6, 0x20E5, 0xF, 0x28, 0x50, 0, 5, 0x38, 5, 14);
        func_L01_003FF4E8(0x20D5, 0x20E6, 0x20E7, 0x10, 0x28, 0x50, 0, 2, 0x96, 9, 15);
        func_L01_003FF4E8(0, 0x20E9, 0x20E9, 0x11, 0, 0x50, 0, 1, 0xC8, 6, 16);
        D_L01_001E6D50 = 0x11;
        *(s16 *)(g + 0x1E) = 0;
        *(s16 *)(g + 0x1C) = 0;
        *(s16 *)(g + 0x26) = 0;
        if (func_L01_0045A6F0() != 3) {
            *(s32 *)(g + 0x2C) = 100;
        } else {
            *(s32 *)(g + 0x2C) = 0;
        }
        k = D_00143A07 << 3;
        *(s32 *)(g + 0x370) = 8;
        *(s16 *)(g + 0x24) = -1;
        *(s32 *)(g + 0x374) = 0x17F;
        *(f32 *)(g + 0x378) = ((f32)D_001D4BC0 * 2.2f) * 1.2f;
        *(f32 *)(g + 0x37C) = 0.13054830f;
        *(s32 *)(g + 0x380) = 5;
        *(f32 *)(g + 0x384) = 0.03f;
        *(s32 *)(g + 0x388) = 0x12;
        *(s16 *)(g + 0x22) = -1;
        func_003A2598(*(s32 *)(g + 8),
                      *(s32 *)(D_00160C40 + k + 0xC50) + *(s32 *)(D_00160C40 + 0x694),
                      *(s32 *)(D_00160C40 + k + 0xC54));
        *(s16 *)(g + 0x28) = 1;
        break;
    case 1:
        if (D_001CCFD4[0] != 0) break;
        func_L01_00400100();
        *(s16 *)(g + 0x28) = 2;
        break;
    case 2:
        k = *(s16 *)(g + 0x1E) << 3;
        func_003A2598(*(s32 *)(g + (*(s16 *)(g + 0x1C) << 2)),
                      *(s32 *)(D_00160C40 + k + 0xC80) + *(s32 *)(D_00160C40 + 0x694),
                      *(s32 *)(D_00160C40 + k + 0xC84));
        *(s16 *)(g + 0x28) = 3;
        break;
    case 3:
        if (D_001CCFD4[0] != 0) break;
        if (func_0038CAD0(g + 0x2C) == 0) break;
        k = (s16)*(u16 *)(g + 0x1E) + 1;
        *(s16 *)(g + 0x26) = 1;
        *(s16 *)(g + 0x1C) = *(u16 *)(g + 0x1C) ^ 1;
        *(s16 *)(g + 0x1E) = k;
        if (k >= 0xD) *(s16 *)(g + 0x1E) = k - 0xD;
        k = *(s16 *)(g + 0x1E) << 3;
        func_003A2598(*(s32 *)(g + (*(s16 *)(g + 0x1C) << 2)),
                      *(s32 *)(D_00160C40 + k + 0xC80) + *(s32 *)(D_00160C40 + 0x694),
                      *(s32 *)(D_00160C40 + k + 0xC84));
        *(s16 *)(g + 0x28) = 4;
        break;
    case 4:
        func_003C4138(&D_L01_001DF950, 0.0f, 0.08f);
        if (func_L01_004001C8() == 0) break;
        func_L01_004001E8();
        if (*(s16 *)(g + 0x28) == 5) break;
        *(s16 *)(g + 0x20) = *(u16 *)(g + 0x20) + 1;
        if (*(s16 *)(g + 0x20) < 5) break;
        *(s16 *)(g + 0x20) = 0;
        *(s16 *)(g + 0x28) = 3;
        break;
    case 5:
        if (func_L01_0045A6F0() == 3) {
            func_003A0F98(0, 0);
            *(s16 *)(g + 0x28) = 0;
        } else {
            if (func_00392B20(D_L01_001EA7C0, 0x1C) == 0) break;
            func_00392C78(D_L01_001EA7C0);
            *(s16 *)(g + 0x28) = 6;
        }
        break;
    case 6:
        if ((D_00142BBC & 0x10000000) == 0) break;
        if (func_L01_004BA800() != 0) break;
        func_003A0EC0(3, 1, 7, 0, 0);
        *(s16 *)(g + 0x28) = 0;
        break;
    }
    func_003A4288();
}
/* localdecomp:end func_L01_003FEA68 */
