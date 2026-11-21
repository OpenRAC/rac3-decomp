/* functional: medium. Straight block translation of the loop; branch order checked against asm. */
extern s32 D_L39_00242914;
extern u8 *D_L39_0024C9F4;
extern u8 *D_L39_0024CA58[];
extern s32 D_L39_0024CA20;
extern void *D_L39_0024BA40[];
extern s32 D_L39_0024BA50[];
extern s32 D_L39_00241128;
extern unsigned long D_L39_00240200;
extern s32 D_L39_00240304;
extern s32 *D_L39_00241120;
extern s32 D_L39_00242A00;
extern s32 D_L39_0024BB44;
extern s32 D_L39_0024B9C8;
extern s32 D_001D72F0_sda;
extern s32 D_001D5A0C_sda;
extern s32 D_001E02B4_sda;
extern s32 D_001E02B8_sda;
extern s32 D_001E0434_sda;
extern s32 D_001D7204_sda;
extern s32 D_001A5810[];
extern void func_L01_004126E8(void);
extern void func_L01_003F1760(void);
extern void func_L01_003F1780(void);
extern void func_L01_003F17A0(void);
extern void func_003A92F0(s32);
extern void func_003A9108(void);
extern void func_00193590(void);
extern void func_L39_0058CC68(void);
extern void func_L01_003F17C0(s32 n, s32 *out);
extern void func_L39_00576E48(s32 a, s32 b, s32 c, s32 d);
extern void func_0038E138(void);
extern void func_L01_003F6F10(s32);
extern void func_L01_00403168(s32);
extern void func_L39_00587E80(void);
extern void func_003A9440(s32, s32);
extern void func_0038AF30(s32, s32, s32, s32, long);
extern void func_L39_00589538(s32);
extern s32 func_003A0EA8(s32);
extern void func_003B3158(s32);
extern void func_00389370(void);
extern void func_L39_005FCDF8(void);
extern void func_003A9150(void);
extern void func_L01_0045A550(void);
extern void func_L39_00577148(void);
extern void func_00139E08(s32);
extern void func_L39_0057B1C0(void);
extern void func_L39_005BF490(void);
extern void func_003923D0(void);
extern void func_00392748(s32);
extern void func_L39_00597E70(void);

void func_L39_005771D0(void) {
    s32 sp[8];
    s32 half;

    D_L39_0024CA58[1] = D_L39_0024C9F4 + 0x80000;
    D_L39_0024CA20 = 0x8000;
    D_L39_0024CA58[0] = D_L39_0024C9F4;
    D_L39_0024BA40[0] = func_L01_004126E8;
    D_L39_0024BA40[1] = func_L01_003F1760;
    D_L39_0024BA40[2] = func_L01_003F1780;
    D_L39_0024BA40[3] = func_L01_003F17A0;
    D_L39_0024BA50[0] = 0;
    D_L39_0024BA50[3] = 0;
    D_L39_0024BA50[1] = 0;
    D_L39_0024BA50[2] = 0;
    func_003A92F0(1);
    func_003A9108();
    D_001D72F0_sda = 1;
    if (D_L39_00241128 != 0 || D_L39_00242914 == 0) return;
    do {
        D_L39_00240200 += *(volatile u32 *)0x10000800;
        *(volatile u32 *)0x10000800 = 0;
        D_001D5A0C_sda = 1;
        func_00193590();
        func_L39_0058CC68();
        D_001E02B4_sda = 0xBF;
        if (D_L39_00242914 == 2) {
            func_L01_003F17C0(3, &sp[4]);
            func_L39_00576E48(sp[4], sp[4] + 3, 1, 0);
            func_0038E138();
            func_L39_00576E48(sp[5], sp[5] + 3, 0, 0);
            func_0038E138();
            func_L39_00576E48(sp[6], sp[6] + 3, 0, 1);
        } else if (D_L39_00242914 < 3 && D_L39_00242914 == 1) {
            func_L01_003F17C0(2, &sp[0]);
            func_L39_00576E48(sp[0], sp[0] + 1, 1, 0);
            func_0038E138();
            func_L39_00576E48(sp[1], sp[1] + 1, 0, 1);
        } else {
            func_L01_003F17C0(4, &sp[0]);
            func_L39_00576E48(sp[0], sp[0] + 6, 1, 0);
            func_0038E138();
            func_L39_00576E48(sp[1], sp[1] + 6, 0, 0);
            func_0038E138();
            func_L39_00576E48(sp[2], sp[2] + 6, 0, 0);
            func_0038E138();
            func_L39_00576E48(sp[3], sp[3] + 6, 0, 1);
        }
        func_L01_003F6F10(0);
        func_L01_00403168(0);
        func_L39_00587E80();
        func_003A9440(0x47, 0x33001);
        half = D_L39_00240304 >> 1;
        if (D_L39_00242914 == 1) {
            func_0038AF30(0, half, 0x155, 0x200, 0x80000000L);
            func_0038AF30(half, D_L39_00240304, 0, 0xAA, 0x80000000L);
            func_0038AF30(half - 1, half, 0, 0x200, 0x80000000L);
        } else if (D_L39_00242914 == 2) {
            func_0038AF30(half, D_L39_00240304, 0x100, 0x200, 0x80000000L);
            func_0038AF30(0, D_L39_00240304, 0xFF, 0x100, 0x80000000L);
            func_0038AF30(half - 1, half, 0, 0x200, 0x80000000L);
        } else {
            func_0038AF30(0, D_L39_00240304, 0xFF, 0x100, 0x80000000L);
            func_0038AF30(half - 1, half, 0, 0x200, 0x80000000L);
        }
        func_L39_00589538(0);
        if (func_003A0EA8(3) == 0) {
            func_003A9440(0x47, 0x33001);
            func_0038E138();
        }
        func_003B3158(4);
        func_00389370();
        func_003A92F0(1);
        func_L39_005FCDF8();
        func_003A9150();
        func_L01_0045A550();
        func_L39_00577148();
        if (*D_L39_00241120 >= 3) D_L39_00242A00 ^= 1;
        func_L01_003F6F10(0);
        if ((s32)*(volatile u32 *)0x10000800 < (D_001A5810[0] != 0 ? 0x2D00 : 0x2580))
            func_00139E08(0);
        func_L39_00577148();
        if (*D_L39_00241120 >= 3) D_L39_00242A00 ^= 1;
        if (*D_L39_00241120 >= 2) func_L39_0057B1C0();
        {
            s32 nv;
            if ((D_001A5810[0] != 0 ? 0x5A00 : 0x4B00) < (s32)*(volatile u32 *)0x10000800) {
                func_L01_003F6F10(0);
                D_001D5A0C_sda = 2;
                func_L39_00577148();
                if (*D_L39_00241120 >= 3) D_L39_00242A00 ^= 1;
                if (*D_L39_00241120 >= 2) {
                    func_L39_0057B1C0();
                    nv = D_L39_0024BB44 + 1;
                } else {
                    nv = D_001E0434_sda + 1;
                }
            } else {
                nv = D_L39_0024BB44 + 1;
            }
            D_001E0434_sda = nv;
            func_L39_005BF490();
        }
        func_003923D0();
        func_00392748(1);
        func_L39_00597E70();
        func_003A92F0(1);
        func_00139E08(0);
        D_001E02B8_sda = D_L39_0024B9C8 + 1;
        func_L39_005FCDF8();
        func_003A9150();
    } while (D_L39_00241128 == 0 && D_001D7204_sda != 0);
}
