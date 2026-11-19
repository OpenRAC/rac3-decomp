/* functional: high. 280 instruction positions differ at L01 (register allocation: retail keeps 1, 2 and the timer pointer in s-registers; the two limit compares are folded to slti); the call sequence, arguments, stores and branch structure match retail. */
typedef void (*Fn_3F19B8)(void);
extern Fn_3F19B8 D_L01_001DF9C0[];
extern Fn_3F19B8 D_L01_001DF9D0[];
extern s32 D_L01_001D6694;
extern s32 D_L01_001D6698;
extern s32 D_001D6694_sda;
extern s32 D_001D6698_sda;
__asm__(".extern D_001D6694_sda, 4");
__asm__(".extern D_001D6698_sda, 4");
extern s32 D_001D52F4_sda;
__asm__(".extern D_001D52F4_sda, 4");
extern s32 D_001DF944_sda;
__asm__(".extern D_001DF944_sda, 4");
extern s32 D_L01_001DF948;
extern s32 D_001DF948_sda;
__asm__(".extern D_001DF948_sda, 4");
extern s32 D_L01_001DFB48;
extern s32 D_001DFB48_sda;
__asm__(".extern D_001DFB48_sda, 4");
extern unsigned long D_001D4AC0;
extern s32 D_001D4BC4;
extern s32 D_00143950[];
extern void func_L01_003F1740(void);
extern void func_L01_003F1760(void);
extern void func_L01_003F1780(void);
extern void func_L01_003F17A0(void);
extern void func_L01_003F17C0(s32, s32 *);
extern void func_L01_003F1850(s32, s32, s32, s32);
extern void func_L01_003F19B0(void);
extern void func_L01_003F6F10(s32);
extern void func_L01_00407950(void);
extern void func_L01_00459F60(void);
extern void func_L01_0045A550(void);
extern void func_003A92F0(s32);
extern void func_003A91D0(void);
extern void func_003A9150(void);
extern void func_003A9108(void);
extern void func_0013B620(void);
extern void func_0038E138(void);
extern void func_L01_00403168(s32);
extern void func_00387F68(void);
extern void func_003A9440(s32, unsigned long);
extern void func_0038AF30(s32, s32, s32, s32, unsigned long);
extern void func_00389240(s32);
extern s32 func_003A0EA8(s32);
extern void func_003B3158(s32);
extern void func_00389370(void);
extern void func_003923D0(void);
extern void func_00392748(s32);
extern void func_003922B8(void);

void func_L01_003F19B8(void) {
    s32 buf[4];
    s32 buf2[4];
    s32 sel;
    s32 x;
    s32 r;
    D_L01_001DF9C0[0] = func_L01_003F1740;
    D_L01_001DF9C0[1] = func_L01_003F1760;
    D_L01_001DF9C0[2] = func_L01_003F1780;
    D_L01_001DF9C0[3] = func_L01_003F17A0;
    D_L01_001DF9D0[0] = 0;
    D_L01_001DF9D0[3] = 0;
    D_L01_001DF9D0[1] = 0;
    D_L01_001DF9D0[2] = 0;
    func_003A92F0(1);
    func_003A9108();
    if (D_L01_001D6694 != 0 || D_L01_001D6698 == 0) {
        return;
    }
    do {
        D_001D4AC0 += *(volatile u32 *)0x10000800;
        *(volatile s32 *)0x10000800 = 0;
        D_001D52F4_sda = 1;
        func_0013B620();
        func_L01_00407950();
        D_001DF944_sda = 0xBF;
        sel = D_L01_001D6698;
        switch (sel) {
        case 1:
            func_L01_003F17C0(2, buf);
            func_L01_003F1850(buf[0], buf[0] + 1, 1, 0);
            func_0038E138();
            func_L01_003F1850(buf[1], buf[1] + 1, 0, 1);
            break;
        case 2:
            func_L01_003F17C0(3, buf2);
            func_L01_003F1850(buf2[0], buf2[0] + 3, 1, 0);
            func_0038E138();
            func_L01_003F1850(buf2[1], buf2[1] + 3, 0, 0);
            func_0038E138();
            func_L01_003F1850(buf2[2], buf2[2] + 3, 0, 1);
            break;
        default:
            func_L01_003F17C0(4, buf);
            func_L01_003F1850(buf[0], buf[0] + 6, 1, 0);
            func_0038E138();
            func_L01_003F1850(buf[1], buf[1] + 6, 0, 0);
            func_0038E138();
            func_L01_003F1850(buf[2], buf[2] + 6, 0, 0);
            func_0038E138();
            func_L01_003F1850(buf[3], buf[3] + 6, 0, 1);
            break;
        }
        func_L01_003F6F10(0);
        func_L01_00403168(0);
        func_00387F68();
        func_003A9440(0x47, 0x33001);
        sel = D_L01_001D6698;
        switch (sel) {
        case 1:
            func_0038AF30(0, D_001D4BC4 >> 1, 0x155, 0x200, 0x80000000UL);
            func_0038AF30(D_001D4BC4 >> 1, D_001D4BC4, 0, 0xAA, 0x80000000UL);
            break;
        case 2:
            func_0038AF30(D_001D4BC4 >> 1, D_001D4BC4, 0x100, 0x200, 0x80000000UL);
            func_0038AF30(0, D_001D4BC4, 0xFF, 0x100, 0x80000000UL);
            break;
        default:
            func_0038AF30(0, D_001D4BC4, 0xFF, 0x100, 0x80000000UL);
            break;
        }
        func_0038AF30((D_001D4BC4 >> 1) - 1, D_001D4BC4 >> 1, 0, 0x200, 0x80000000UL);
        func_00389240(0);
        r = func_003A0EA8(3);
        if (r == 0) {
            func_003A9440(0x47, 0x33001);
            func_0038E138();
            func_003B3158(4);
        }
        func_00389370();
        func_003A92F0(1);
        func_003A91D0();
        func_003A9150();
        func_L01_0045A550();
        func_L01_003F19B0();
        func_L01_003F6F10(0);
        if (*(volatile s32 *)0x10000800 < (D_00143950[0] != 0 ? 0x2D00 : 0x2580)) {
            func_0012C908(0);
        }
        func_L01_003F19B0();
        if ((D_00143950[0] != 0 ? 0x5A00 : 0x4B00) < *(volatile s32 *)0x10000800) {
            D_001D52F4_sda = 2;
            func_L01_003F6F10(0);
            func_L01_003F19B0();
        }
        D_001DFB48_sda = D_L01_001DFB48 + 1;
        func_L01_00459F60();
        func_003923D0();
        func_00392748(1);
        func_003922B8();
        func_003A92F0(1);
        func_0012C908(0);
        D_001DF948_sda = D_L01_001DF948 + 1;
        func_003A91D0();
        func_003A9150();
    } while (D_L01_001D6694 == 0 && D_001D6698_sda != 0);
}
