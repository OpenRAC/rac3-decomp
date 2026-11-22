/* func_L01_004A22C8: matches level 01 (check.py MATCH) but not every level: its 8th call (func_L01_00516090 in level 01) goes to a different catalogue function in levels 04, 12, 18, 26 and 29. */
__asm__(".extern D_001D52FC, 16");
extern u8 *D_001D52FC;
__asm__(".extern D_L01_001D672C, 16");
extern u8 D_L01_001D672C;
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
        s32 *p = func_003B9BD0(0);
        u8 *q = D_001D52FC;
        func_003BA4F8(p, *(s32 *)(q + 0x1C4));
        func_L01_004A28C8();
        func_L01_004A2878(a0);
    }
    if (func_L01_0047DAB0()) {
        func_L01_0047DAC8();
        func_L01_00516090(a0);
        if (D_L01_001D672C == 0) {
            func_L01_00517748(func_L01_0047EBE0());
        }
    }
}
