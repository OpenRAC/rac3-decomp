/* functional: high. 6 diff at default flags (scheduling of the D_001D52FC load / D_L01_001D672C byte load); behaviour identical. */
extern u8 *D_001D52FC[];
extern u8 D_L01_001D672C[];
extern s32 func_L01_004A2E88(void);
extern void func_L01_004A28C8(void);
extern void func_L01_004A2878(s32);
extern s32 func_L01_0047DAB0(void);
extern s32 func_L01_0047DAC8(void);
extern s32 func_L01_0047EBE0(void);
extern s32 *func_003B9BD0(s32);
extern void func_003BA4F8(void *, s32);
extern void func_L01_00516090(s32);
void func_L01_004A22C8(s32 a0) {
    if (func_L01_004A2E88() == 0) {
        func_003BA4F8(func_003B9BD0(0), *(s32 *)(D_001D52FC[0] + 0x1C4));
        func_L01_004A28C8();
        func_L01_004A2878(a0);
    }
    if (func_L01_0047DAB0()) {
        func_L01_0047DAC8();
        func_L01_00516090(a0);
        if (D_L01_001D672C[0] == 0) {
            func_L01_00517748(func_L01_0047EBE0());
        }
    }
}
