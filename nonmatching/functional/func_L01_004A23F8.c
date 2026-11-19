/* functional: high. 65 diff at default flags (retail builds the scale constant with lui/ori, we load it from small data; switch layout differs); behaviour identical. cvt.w.s truncates on the EE FPU, so (s32) cast is exact. */
extern s32 D_L01_001E0D20;
extern s32 D_L01_001E0D1C;
extern s32 D_L01_001D96C4;
extern s32 D_L01_001D9704;
extern s32 D_L01_001D9708;
extern s32 D_L01_001D970C;
extern s32 D_L01_001DFCC0[];
extern u16 D_001A8EC8[];
__asm__(".extern D_L01_001E0D20, 4");
__asm__(".extern D_L01_001E0D1C, 4");
__asm__(".extern D_L01_001D96C4, 4");
__asm__(".extern D_L01_001D9704, 4");
__asm__(".extern D_L01_001D9708, 4");
__asm__(".extern D_L01_001D970C, 4");
extern void func_L01_0047E520(void);
extern s32 func_00381F80(s32);
extern long func_00389598(s32);
extern void func_0038B4D0(s32, s32, s32, s32, s32, s32, s32, s32, long, long);
void func_L01_004A23F8(void) {
    s32 id;
    if (D_L01_001E0D20 == 0) {
        D_L01_001E0D20 = 1;
        D_L01_001E0D1C = (s32)((f32)D_L01_001D970C * 1.11607146f);
    }
    func_L01_0047E520();
    id = *(s16 *)((u8 *)D_L01_001DFCC0[0] + (func_00381F80(D_001A8EC8[D_L01_001D96C4]) << 4) + 0xE);
    switch (id) {
    case 0x1DC:
        id = 0x5C;
        break;
    case 0xB0E:
        id = 0x61;
        break;
    case 0x150E:
        id = 0x5D;
        break;
    case 0x166A:
        id = 0x62;
        break;
    case 0x1736:
        id = 0x5E;
        break;
    default:
        return;
    }
    func_0038B4D0(D_L01_001D9704, D_L01_001D9708, D_L01_001D970C, D_L01_001E0D1C, 0, 0, 0x40, 0x40,
                  0x80808080L, func_00389598(id));
}
