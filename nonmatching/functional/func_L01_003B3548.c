/* functional: high. Same reads, writes and call order; only register allocation and scheduling differ. */
extern u16 *D_L01_0021DE20[];
extern u8 *D_L01_001E001C;
extern s32 D_L01_001E0058;
extern u8 D_L01_001FDBD0[];
extern s16 D_L01_001FD9F0[];
extern u8 *D_L01_001FD180[];
extern s32 func_L01_003B5B68(u8 *);
extern s32 func_L01_003B64C0(u8 *);

s32 func_L01_003B3548(u8 *m) {
    u8 *s = *(u8 **)(m + 104);
    s32 sum = 0;
    u16 *p;
    u8 *n;
    s32 k;
    s32 idx;
    s32 ok;

    if (*(s32 *)(s + 12) != -1) {
        p = D_L01_0021DE20[*(s32 *)(s + 12)];
        while ((*(s32 *)(s + 12) & 0xFF) != 255 && *(s32 *)(s + 12) <= D_L01_001E0058 && p != 0
               && ((s16)p[-1] >= 0 || p == D_L01_0021DE20[*(s32 *)(s + 12)])) {
            n = D_L01_001E001C + ((*p & 0x7FFF) << 8);
            if (n == 0) {
                break;
            }
            k = **(s32 **)(n + 104);
            idx = D_L01_001FDBD0[k];
            if (D_L01_001FD9F0[idx] == k) {
                ok = D_L01_001FD180[idx][0x46] == 5;
            } else {
                ok = k == 0x194C;
            }
            if (ok && !func_L01_003B5B68(n)) {
                sum += func_L01_003B64C0(n);
            }
            p++;
        }
    }
    return sum;
}
