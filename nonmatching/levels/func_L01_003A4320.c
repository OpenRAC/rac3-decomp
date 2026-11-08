/* func_L01_003A4320: p2w2 near miss by w6. Matches levels 01,04,09,12,18,26,29 + NTSC-U;
   level 08 differs (store offset 0x2D8 instead of 0x2E8): false fold, needs a split place.
   rac2 twin func_L18_00432D60 family (group/entity scan). */
extern u16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C;
__asm__(".extern D_L01_001E001C, 16");
extern s32 D_L01_001E0058;
extern void func_L01_00445BE0(s32 a0, s32 a1);

void func_L01_003A4320(u8 *a0) {
    u16 *p;
    u8 *e;
    if (a0[0x21] == 0xFF) return;
    func_L01_00445BE0(a0[0x21], 0);
    p = D_L01_0021DE20[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L01_001E0058 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L01_0021DE20[a0[0x21]])) {
        e = D_L01_001E001C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        p++;
        if (*(s16 *)(e + 0xAA) == *(s16 *)(a0 + 0xAA)) {
            *(s32 *)(*(u8 **)(e + 0x68) + 0x2E8) = 1;
        }
    }
}
