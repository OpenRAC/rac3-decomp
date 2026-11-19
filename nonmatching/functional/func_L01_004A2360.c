/* functional: high. 31 diff at default flags (store/load scheduling); D_L01_001DFCC0 and D_L01_002E5F5C are unsized (lui-addressed) as in retail. */
extern s32 D_L01_001D96C8;
extern s32 D_L01_001D96E8;
extern s32 D_L01_001D96EC;
extern s32 D_L01_001D96C0;
extern s32 D_L01_001D96CC;
extern s32 D_L01_001D96D0;
extern s32 D_L01_001DFCC0[];
extern s32 D_L01_002E5F5C[];
__asm__(".extern D_L01_001D96C8, 4");
__asm__(".extern D_L01_001D96E8, 4");
__asm__(".extern D_L01_001D96EC, 4");
__asm__(".extern D_L01_001D96C0, 4");
__asm__(".extern D_L01_001D96CC, 4");
__asm__(".extern D_L01_001D96D0, 4");
extern void func_003BB468(s32);
extern void func_L01_00517918(s32);
extern void func_L01_004A2848(void);
extern void func_003A2750(s32);
void func_L01_004A2360(void) {
    D_L01_001D96C8 = -1;
    func_003BB468(D_L01_001D96E8);
    func_003BB468(D_L01_001D96EC);
    func_L01_00517918(0x10);
    func_L01_00517918(0x11);
    if (D_L01_001D96C0) {
        func_L01_00517918(0x14);
    }
    func_L01_004A2848();
    func_003A2750(1);
    D_L01_001DFCC0[0] = D_L01_001D96CC;
    D_L01_002E5F5C[0] = D_L01_001D96D0;
}
