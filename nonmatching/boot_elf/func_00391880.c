/* US draft of func_00391880 (rac3-uya-decomp func_003917C0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_00391880 */
typedef struct {
    u8 p0[0x150];
    s16 h150, h152, h154, h156, h158, h15A;
} E_38CC68;
extern unsigned long D_001D0560[];
extern E_38CC68 *D_001D4CF8_00391880;
extern u8 D_001439FD[];
extern s32 D_001D5520;
void func_00391880(s32 a0, s32 a1) {
    unsigned long *b = D_001D0560;
    s32 s;
    s32 n;
    s32 i;
    b[0] = (0xC22DUL << 46) | 1;
    b[1] = 0xEEE;
    b[2] = 0x30000;
    b[3] = 0x47;
    b[4] = (0x8000UL << 17) | 0x261;
    b[5] = 0x14;
    b[6] = ((long)D_001D4CF8_00391880->h156 << 5) | ((long)(((u16)D_001D4CF8_00391880->h150 >> 6) & 0x3F) << 14) | ((long)D_001D4CF8_00391880->h154 << 20) | (0xEA80UL << 20);
    b[7] = 6;
    b[8] = (0x8800UL << 47) | 0x8010;
    b[9] = 0x5353;
    if (a0 == 0) a1 = D_001439FD[0] != 0;
    if (a1) s = D_001D4CF8_00391880->h15A;
    else s = D_001D4CF8_00391880->h15A * 0x73 / 0xA0;
    n = 10;
    for (i = 0; i < 16; i++) {
        if (D_001D5520 != 0) {
            b[n++] = i * D_001D4CF8_00391880->h150;
            b[n++] = (i * 0x280 + 0x6BF8) | ((long)(0x7FF8 - s * 8) << 16);
            b[n++] = ((i + 1) * D_001D4CF8_00391880->h150) | (0x1A0L << 20);
            b[n++] = ((i + 1) * 0x280 + 0x6BF8) | ((long)(s * 8 + 0x7FF8) << 16);
        } else {
            b[n++] = i * D_001D4CF8_00391880->h150;
            b[n++] = (i * 0x200 + 0x6FF8) | ((long)(0x7FF8 - s * 8) << 16);
            b[n++] = ((i + 1) * D_001D4CF8_00391880->h150) | (0x1A0L << 20);
            b[n++] = ((i + 1) * 0x200 + 0x6FF8) | ((long)(s * 8 + 0x7FF8) << 16);
        }
    }
}
/* localdecomp:end func_00391880 */
