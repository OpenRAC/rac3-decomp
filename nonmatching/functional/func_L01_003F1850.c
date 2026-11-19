/* functional: high. EXACT at level 01. */
typedef void (*Fn_3F1850)(void);
extern Fn_3F1850 D_L01_001DF9C0[];
extern Fn_3F1850 D_L01_001DF9D0[];
extern s32 D_001D52F0_sda;
__asm__(".extern D_001D52F0_sda, 4");
extern s32 D_L01_001E0054;
extern s32 D_00143950[];
extern f32 D_L01_001DFB50;
extern f32 D_L01_001DF788[];
extern void func_L01_00403168(s32);
extern void func_00388AF8(s32);
extern void func_003A92F0(s32);
extern void func_003A91D0(void);
extern void func_003A9150(void);

void func_L01_003F1850(s32 a0, s32 a1, s32 a2, s32 a3) {
    f32 r;
    D_001D52F0_sda = a0;
    if (D_L01_001DF9C0[a0] != 0) {
        D_L01_001DF9C0[a0]();
    }
    func_L01_00403168(a1);
    if (a2 == 0) {
        D_L01_001E0054 = 1;
    }
    r = (f32)*(volatile u32 *)0x10000800 / (D_00143950[0] != 0 ? 11520.0f : 9600.0f);
    func_00388AF8(a0);
    D_L01_001DF788[a0] = D_L01_001DFB50 - r;
    if (a3 == 0) {
        func_003A92F0(1);
        func_003A91D0();
        func_003A9150();
    }
    if (D_L01_001DF9D0[a0] != 0) {
        D_L01_001DF9D0[a0]();
    }
}
