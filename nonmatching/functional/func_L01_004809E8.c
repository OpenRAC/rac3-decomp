/* functional: high. Options-screen exit: closes widgets 0x10/0x11, calls the object's vtable slot +0xC, refreshes, redraws, and calls func_L01_00425FE0 when the saved option byte differs from the live setting. From the existing near miss (only a lui order differs). D_L01_001D8318 (gp-0x4598) is level data, named per level since it moves (1D81D8 in L02). */
extern u8 D_001D5475[];
extern s32 D_001D4BA0[];
extern s32 D_L01_001D8318;

extern void func_L01_00517918(s32);
extern s32 func_003B9BD0(s32);
extern void func_003B9E90(s32);
extern u8 *func_003B42F8(s32);
extern void func_003A2750(s32);
extern void func_003BB468(s32);
extern void func_L01_00425FE0(void);
extern void func_L01_003F1E98(s32);

void func_L01_004809E8(void) {
    u8 *o;
    func_L01_00517918(0x10);
    func_L01_00517918(0x11);
    func_003B9E90(func_003B9BD0(0));
    o = func_003B42F8(0);
    (*(void (**)(u8 *))(*(u8 **)(o + 4) + 0xC))(o);
    func_003A2750(1);
    func_003BB468(D_L01_001D8318);
    if (D_001D5475[0] != D_001D4BA0[0]) {
        func_L01_00425FE0();
    }
    func_003A2750(1);
    func_L01_003F1E98(0);
}
