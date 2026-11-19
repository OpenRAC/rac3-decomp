/* functional: high. Same control flow, reads, writes and call order; only register allocation and gp/lui address form differ. */
extern u16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C;
extern s32 D_L01_001E0058;
extern s32 D_L01_001DFB40;
extern s32 D_L01_001DE630;
extern void func_L01_00456230(void *, s32);
extern void func_L01_003B5FD8(u8 *, u8 *);
extern void func_L01_003B4840(u8 *, u8 *);
extern void func_L01_00327038(u8 *);
extern void func_L01_004450F0(s32, s32, s32);

void func_L01_003B3098(u8 *m) {
    u8 *s = *(u8 **)(m + 104);
    u16 *p;
    u8 *n;

    D_L01_001DE630 = (s32)m;
    func_L01_00456230(m, 1);
    *(s32 *)(s + 4) = D_L01_001DFB40;
    if (*(s32 *)(s + 12) != -1) {
        p = D_L01_0021DE20[*(s32 *)(s + 12)];
        while ((*(s32 *)(s + 12) & 0xFF) != 255 && *(s32 *)(s + 12) <= D_L01_001E0058 && p != 0
               && ((s16)p[-1] >= 0 || p == D_L01_0021DE20[*(s32 *)(s + 12)])) {
            n = D_L01_001E001C + ((*p & 0x7FFF) << 8);
            if (n == 0) {
                break;
            }
            func_L01_003B5FD8(n, s);
            p++;
        }
    }
    func_L01_003B4840(m, s);
    func_L01_00327038(m);
    *(u16 *)(m + 52) &= 0xFFFD;
    *(s32 *)(s + 44) = 0;
    func_L01_004450F0((s32)m, 2, -1);
}
