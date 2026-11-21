/* functional: high. Same reads, writes and call order; only register allocation and scheduling differ. */
extern u16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C;
extern s32 D_L01_001E0058;
extern void func_L01_003B6458(u8 *);

void func_L01_003B3368(u8 *m) {
    u8 *s = *(u8 **)(m + 104);
    u16 *p;
    u8 *n;

    if (*(s32 *)(s + 12) != -1) {
        p = D_L01_0021DE20[*(s32 *)(s + 12)];
        while ((*(s32 *)(s + 12) & 0xFF) != 255 && *(s32 *)(s + 12) <= D_L01_001E0058 && p != 0
               && ((s16)p[-1] >= 0 || p == D_L01_0021DE20[*(s32 *)(s + 12)])) {
            n = D_L01_001E001C + ((*p & 0x7FFF) << 8);
            if (n == 0) {
                break;
            }
            func_L01_003B6458(n);
            p++;
        }
    }
}
