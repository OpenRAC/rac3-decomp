/* functional: high. Builds a packet in a stack buffer with func_0012CB88 and sends it with func_0012CE48; differs from retail only in instruction scheduling. */
extern s32 D_001A1ED8[];
extern s32 D_001D4BC0[];
extern void func_0012CB88(void *, s32, s32, s32, s32, s32, s32, s32);
extern void func_0011F0A0(s32);
extern void func_0012CE48(void *, s32);

void func_L01_00415C18(s16 a, s16 b, s16 c, s16 d, s32 e) {
    long buf[14];
    s32 x = (D_001A1ED8[0] << 8) >> 16;
    s32 y = (D_001D4BC0[0] << 10) >> 16;
    func_0012CB88(buf, x, y, 0x30, a, b, c, d);
    func_0011F0A0(0);
    func_0012CE48(buf, e);
}
