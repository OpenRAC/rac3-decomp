/* functional: high. Jump table (12 cases) read from the retail ELF: 0,10 and >=12 are trivial; every case does the same calls with the same arguments as retail. Case 6 and 9 store the state before the call; not byte-checked. */
extern u8 D_L01_002E9F98[];
extern u8 D_L01_001EA7C0[];

extern void func_003A8F50(void);
extern void func_00392DF0(s32, s32);
extern void func_003A0F98(s32, s32);
extern void func_L01_004C0FD0(s32);
extern s32 func_003A0EC0(s32, s32, s32, s32, u8 *);
extern s32 func_00392C78(void *);

void func_L01_0047E908(void) {
    u8 *B = D_L01_002E9F98;
    s32 state = *(s32 *)(B + 0x74);

    switch (state) {
    case 7:
        func_003A8F50();
        func_003A0F98(0, 0);
        return;
    case 3:
        func_003A0EC0(4, 1, 0xB, 0, 0);
        return;
    case 1:
        func_00392DF0(*(s32 *)(B + 0x78), 0);
        func_003A0F98(0, 0);
        return;
    case 0:
    case 10:
        func_003A0F98(0, 0);
        return;
    case 2:
    case 4:
        func_L01_004C0FD0(*(s32 *)B);
        func_003A0EC0(5, 1, 0, 0, 0);
        return;
    case 11:
        func_L01_004C0FD0(7);
        func_003A0EC0(4, 1, 1, 0, 0);
        return;
    case 5:
        func_L01_004C0FD0(0x16);
        func_003A0EC0(5, 1, 5, 0, 0);
        return;
    case 6:
        *(s32 *)B = 0x12;
        B[0x70] = 1;
        B[0x71] = 0;
        func_003A0EC0(0x12, 1, *(s32 *)(B + 0x7C), 0, 0);
        return;
    case 8:
        *(s32 *)B = 0x14;
        B[0x70] = 1;
        B[0x71] = 1;
        func_00392C78(D_L01_001EA7C0);
        return;
    case 9:
        B[0x70] = 1;
        *(s32 *)B = 0x15;
        B[0x71] = 1;
        func_003A0EC0(9, 1, 0, 0, 0);
        return;
    default:
        return;
    }
}
