/* functional: high. functional: layout/addressing only */
extern u8 *D_001D52FC;
extern s32 D_001D545C;
extern u8 D_001D672C;
extern void func_L01_0047EC88(void);
extern s32 func_003B9BD0(s32);
extern void func_003BA4F8(s32, s32);
extern void func_L01_0048B588(s32);
extern void func_L01_0048B3F0(void);
extern void func_L01_0048B738(void);
extern void func_L01_0048BD78(void);
extern s32 func_L01_0047DAB0(void);
extern s32 func_003A5348(s32, s32, s32);
extern s32 func_L01_00495030(void);
extern s32 func_003BB0E8(s32);
extern s32 func_L01_0047EBE0(void);
extern void func_L01_0047DAC8(void);
extern void func_L01_00516090_0048A8F8(s32);

void func_L01_0048A8F8(s32 a0) {
    s32 state;

    func_L01_0047EC88();
    func_003BA4F8(func_003B9BD0(0), *(s32 *)(D_001D52FC + 0x1C4));
    func_L01_0048B588(a0);
    func_L01_0048B3F0();
    func_L01_0048B738();
    func_L01_0048BD78();
    if (func_L01_0047DAB0() != 0) {
        if (D_001D672C == 0) {
            state = D_001D545C;
            if (state == 0xC || state == 0x12) {
                func_003A5348(5, 0, 0);
                func_L01_00517748(func_L01_00495030());
                func_L01_00516090_0048A8F8(a0);
            } else {
                func_003BB0E8(state);
                func_003A5348(0x14, 0, 0);
                func_L01_00517748(func_L01_0047EBE0());
            }
        }
        func_L01_0047DAC8();
        func_L01_00516090_0048A8F8(a0);
    }
}
