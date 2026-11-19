/* functional: high. Checked call by call against PAL's assembly; the US draft called func_0038A8A0 where PAL calls func_0038A8F8 (fixed). Byte-identical except the read of timer 1's count (0x10000800, T1_COUNT): it goes through a named volatile declaration (honest-flags rule), so the compiler folds the address into the load instead of lui+ori+lw; same single 32-bit read. */
__asm__(".extern D_001D58D0, 4");
__asm__(".extern D_001D5884, 1");
extern void func_0038A8F8(void);
extern volatile u32 D_10000800; /* EE timer 1 count (T1_COUNT) */

void func_00388ED8(s32 arg0) {
    s32 t;
    f32 n;
    u128_00384420 *src, *dst;

    if (D_001DA5F0 == 0 || D_001DA5F0->x4 != 0 || ((*(u8 *)&D_001D9BC4 ^ 1) & 1)) {
        func_00392730(0);
    }
    func_003865D0();
    func_003C3178();
    func_003875F8();
    func_00388348();
    D_001D9D1C = -1;
    D_001D9348 = 0;
    D_001D934C = 0;
    if (D_001DA5F0 != 0 && (D_001D9BC4 & 1)) {
        func_0038CD90();
    }
    if (D_001D9BC4 & 2) {
        func_003CF4A8();
    }
    func_003AA028_00388ED8(0x2010000);
    if (D_001D9BC4 & 4) {
        func_003DA0A8();
    }
    func_003AA028_00388ED8(0x2020000);
    if ((D_001D9BC4 & 0x20) && D_001D9C10_00388ED8 != 0) {
        func_003A9A90();
        func_00389620(1);
        func_0038A208();
        func_00389750();
        func_003A9A30();
    }
    if (D_001D9BC4 & 8) {
        func_003DF2E0();
    }
    func_003AA028_00388ED8(0x2040000);
    if (D_001D58D0 != 0) {
        func_0038B120_00388ED8(&D_001D58D0);
    }
    if ((D_001D9BC4 & 0x20) && D_001D9C14_00388ED8 != 0) {
        func_003A9A90();
        func_00389620(1);
        func_0038A280();
        func_00389750();
        func_003A9A30();
    }
    if (D_001D9BC4 & 0x10) {
        if (D_001D5B94 == 2) {
            func_00388A90();
        } else {
            func_003C3C18();
        }
    }
    func_003AA028_00388ED8(0x2080000);
    func_00389620(0);
    if (D_001D9BC4 & 0x20) {
        func_003A9A90();
        if (D_001D9C08_00388ED8 != 0) {
            func_0038A190();
        }
        func_003A97F8(0x42, 0x8000000048UL);
        func_00385400();
        func_003A9A90();
        func_0038A438();
        func_003A97F8(8, 5);
        func_003A9A90();
        func_003A97F8(0x47, 0x53001);
        func_11F0A0(0);
        func_003CD790();
        D_001D9D1C = 9;
        func_003A97F8(0x47, 0x5360B);
        if (D_001D9C0C_00388ED8 != 0) {
            func_003A9A90();
            func_0038A348();
        }
        func_00389750();
        if (D_001D9348 != 0) {
            func_003D8978_00388ED8(0);
            if (D_001D9348 != 0) {
                func_003D89F8();
            }
        }
        if (D_001D9364 != 0) {
            func_003D9618_00388ED8(0);
        }
        {
            s32 t2 = D_001D9364;
            D_001D9364 = 0;
            D_001D9368 = t2;
        }
        func_00389620(0);
        if (D_001D9C38_00388ED8 != 0) {
            func_003A9A90();
            func_0038A3C0();
        }
        func_003A97F8(0x42, 0x8000000044UL);
        func_00386108(arg0);
        func_00389750();
    }
    func_00392AC8();
    func_00389620(0);
    func_003A9A90();
    if ((D_001D9BC4 & 0x180) && func_003A12A8(3) == 0) {
        func_003A97F8(0x47, 0x33001);
        func_0038AD28();
        if (D_001D9BC4 & 0x80) {
            func_003AA060_00388ED8(0);
            func_003AFA18();
            t = D_001D9EC0;          /* kept across func_00396C18 */
            func_00396C18();
            D_001D9EC0 = t;
            func_003B34A0();
            func_003B3510(D_001D52F0);
            func_003B34D8();
            func_00381C70();
        }
    }
    if (D_001D5B94 == 2) {
        func_0038A8F8();
    }
    func_00389750();
    if (D_001D9BC4 & 0x40) {
        func_003A97F8(0x42, 0x8000000044UL);
        if (((P_00384420 *)((u8 *)D_00222480_00388ED8 + arg0 * sizeof(P_00384420)))->x450 != 0) {
            func_0038B200(D_001D5780, D_001D5781, D_001D5782, D_001D5783);
        }
        if (D_001D9BD0 > 0.0f && D_001D5B98 == 0) {
            if (D_001D9BD0 > 1.0f) {
                D_001D9BD0 = 1.0f;
            }
            func_0038B200(0, 0, 0, (s32)(D_001D9BD0 * 128.0f));
        }
        if (D_001D9BD8[0] > 0.0f && D_001D5B98 == 0) {
            if (D_001D9BD8[0] > 1.0f) {
                D_001D9BD8[0] = 1.0f;
            }
            func_0038B200(0xFF, 0xFF, 0xFF, (s32)(D_001D9BD8[arg0] * 128.0f));
        }
        if (D_001D5884 != 0 && D_001D58B8 != 0) {
            func_0038AFA0();
        }
    }
    func_003A9348_00388ED8(D_100AE0);
    func_11F0A0(0);
    n = (f32)D_10000800;
    D_001D9D10 = n / (D_00143950[0] != 0 ? 11520.0f : 9600.0f);
    func_003A96A8(2);
    if (D_001D9BC4 & 2) {
        func_003D0538(D_002FDC00);
        func_003CF408();
    }
    func_003A96A8(4);
    if (D_001D9BC4 & 4) {
        /* retail copies quadwords 0, -1 and 2 of D_00225AA0 to 0, 1 and 2 of D_00334EC0 */
        src = (u128_00384420 *)&D_00225AA0;
        dst = (u128_00384420 *)&D_00334EC0;
        dst[0] = src[0];
        dst[1] = src[-1];
        dst[2] = src[2];
        func_003DDB20();
        func_003D9FE8();
    }
    func_003A96A8(8);
    if (D_001D9BC4 & 8) {
        func_003E0EC8(D_003064C0);
        func_003DF1D8();
    }
    func_003A96A8(0x10);
    if (D_001D9BC4 & 0x10) {
        func_003C3568();
    }
    func_003868A0(arg0);
    D_001D9D50_00388ED8 = 0;
}
