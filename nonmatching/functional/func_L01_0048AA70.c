/* functional: high. functional: register naming only */
extern s32 D_001D545C[];
extern s32 func_003BB0E8(s32);
extern s32 func_003A5348(s32, s32, s32);
extern void func_L01_00516090_0048AA70(s32);

void func_L01_0048AA70(s32 a0, s32 a1) {
    if (a1 >= 2 && a1 != D_001D545C[0] && (a1 != 3 || D_001D545C[0] != 6)) {
        func_003BB0E8(a1);
        func_003A5348(0x14, 0, 0);
        func_L01_00517748(func_L01_0047EBE0());
        func_L01_00516090_0048AA70(a0);
    }
}
