/* func_L39_0059DB38: near miss (w3 p2w2): MATCH at level 39; levels 40-53 differ only in 2 jal targets (func_L01_004077D0 / func_L08_004EE6F8 are level-specific there), NTSC-U 1 diff (jal target). False fold. */
extern s32 D_001FC45C[];
extern s32 D_002402F4;
__asm__(".extern D_002402F4, 16");
extern s32 D_001D4BE0_sda;
extern s32 D_001D5BCC_sda;
extern s32 D_002412DC;
__asm__(".extern D_002412DC, 16");
extern u8 D_L39_0024BBC0[];
extern u8 D_L39_00272590[];
extern u8 D_L39_002757B0[];
extern u8 D_L39_00275030[];
extern u8 D_L39_002BA740[];
extern u8 D_L39_002C1B40[];
extern u8 D_L39_002C1740[];
extern u8 D_L39_002B6BA0[];
extern u8 D_L39_002B89A0[];
extern u8 D_L39_002B83A0[];
extern s32 D_L39_002431F0;
__asm__(".extern D_L39_002431F0, 16");
extern void func_L39_005C1460(void);
extern void func_L39_005FCC58(void);
extern void func_L39_0059DDB0(void);
extern void func_L39_005872D8(void);
extern void func_L01_004077D0(void);
extern void func_003A9108(void);
extern void func_L39_005C5428(void);
extern void func_L39_005FD668(void);
extern void func_L01_0043B5C8(void);
extern s32 func_L39_00577818(void);
extern void func_L01_003E32E8(void);
extern void func_L39_005B9F40(s32 a);
extern void func_L08_004EE6F8(void);

void func_L39_0059DB38(void) {
    s32 v;
    s32 a;
    func_L39_005C1460();
    func_L39_005FCC58();
    func_L39_0059DDB0();
    v = D_001FC45C[0];
    D_001D4BE0_sda = v;
    D_002402F4 = v;
    func_0038CB78(D_L39_0024BBC0, 0x87654321, 0x10);
    func_0038CB78(D_L39_00272590, -1, 0x2000);
    func_0038CB78(D_L39_002757B0, -1, 0xF00);
    func_0038CB78(D_L39_00275030, 0, 0xF0);
    func_0038CB78(D_L39_002BA740, -1, 0x2000);
    func_0038CB78(D_L39_002C1B40, -1, 0x800);
    func_0038CB78(D_L39_002C1740, 0, 0x80);
    func_0038CB78(D_L39_002B6BA0, -1, 0x1000);
    func_0038CB78(D_L39_002B89A0, -1, 0x400);
    func_0038CB78(D_L39_002B83A0, 0, 0x40);
    func_00387268();
    func_L39_005872D8();
    func_L01_004077D0();
    func_003A9108();
    func_L39_005C5428();
    func_L39_005FD668();
    func_L01_0043B5C8();
    if (func_L39_00577818() != 0) {
        a = D_001D5BCC_sda;
    } else {
        func_L01_003E32E8();
        a = D_002412DC;
    }
    if (a != 0) {
        func_L39_005B9F40(a % 0x3C);
        func_L08_004EE6F8();
    }
    D_L39_002431F0 = 0;
}
