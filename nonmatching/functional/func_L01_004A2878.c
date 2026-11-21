/* functional: high. 4 diff at default flags (lui load scheduled before the sd saves); identical behaviour. */
extern u8 *D_001D52FC[];
extern void func_L01_00516090(s32);
extern s32 func_L01_004A1128(void);
void func_L01_004A2878(s32 a0) {
    if (*(s32 *)(D_001D52FC[0] + 0x1C4) & 0x910) {
        func_L01_00517748(func_L01_004A1128());
        func_L01_00516090(a0);
    }
}
