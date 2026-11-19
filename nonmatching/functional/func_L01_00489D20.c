/* functional: high. functional: layout only; callee order and arguments follow the asm */
extern u8 *D_001D52FC;
extern u8 D_001D672C;
extern s32 D_L01_001D8848;
extern s32 D_L01_001D8838;
extern s32 D_L01_001D883C;
extern s32 D_L01_001D88E0;
extern s32 D_L01_001D88E4;
extern s32 D_L01_001D88E8;
extern s32 func_L01_00517190(s32, s32);
extern s32 func_L01_00516D60(s32, s32);
extern void func_L01_00489CB0(s32, s32, s32, s32);
extern void func_L01_00489758(void);
extern void func_L01_00489870(void);
extern void func_003BB5D0(void);
extern void func_003BB590(s32);
extern void func_L01_00489160(void);
extern s32 func_L01_0047EBE0(void);
extern s32 func_L01_0047FE28(void);
extern void func_L01_00517748(s32);
extern s32 func_003A5348(s32, s32, s32);
extern void func_L01_004895E8(void);
extern void func_L01_00489C68(void);
extern void func_L01_00489060(void);
extern void func_L01_004892C0(void);
extern void func_L01_00489410(void);
extern void func_L01_00487FC8(void);
extern void func_L01_00488108(void);
extern s32 func_L01_0047DAB0(void);
extern void func_L01_0047DAC8(void);
extern void func_L01_00516090_00489D20(s32);

void func_L01_00489D20(s32 a0) {
    s32 b;

    func_L01_00517190(0x190002, 1);
    func_L01_00516D60(0x190002, 1);
    if (D_L01_001D88E0 != D_L01_001D8838 || D_L01_001D88E4 != D_L01_001D883C || D_L01_001D88E8 != D_L01_001D8848) {
        if (D_L01_001D88E0 >= 0 && D_L01_001D88E4 >= 0 && D_L01_001D88E8 >= 0) {
            func_L01_00489CB0(D_L01_001D88E8, D_L01_001D88E0, D_L01_001D88E4, 0x706EC8FF);
        }
    }
    func_L01_00489CB0(D_L01_001D8848, D_L01_001D8838, D_L01_001D883C, 0x80FFFFFF);
    D_L01_001D88E0 = D_L01_001D8838;
    D_L01_001D88E4 = D_L01_001D883C;
    D_L01_001D88E8 = D_L01_001D8848;
    func_L01_00489758();
    func_L01_00489870();
    func_003BB5D0();
    func_003BB590(0x19000E);
    func_003BB590(0x19000F);
    func_003BB590(0x190001);
    func_L01_00489160();
    b = *(s32 *)(D_001D52FC + 0x1C4);
    if (b & 0x900) {
        func_L01_00517748(func_L01_0047EBE0());
        func_L01_00516090_00489D20(a0);
    } else if (b & 0x10) {
        func_003A5348(4, 0, 0);
        func_L01_00517748(func_L01_0047FE28());
        func_L01_00516090_00489D20(a0);
    }
    func_L01_004895E8();
    func_L01_00489C68();
    func_L01_00489060();
    func_L01_004892C0();
    func_L01_00489410();
    func_L01_00487FC8();
    func_L01_00488108();
    if (func_L01_0047DAB0() != 0) {
        func_L01_0047DAC8();
        func_L01_00516090_00489D20(a0);
        if (D_001D672C == 0) {
            func_L01_00517748(func_L01_0047EBE0());
        }
    }
}
