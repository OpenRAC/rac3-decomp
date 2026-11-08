/* func_L02_003A5138: NEAR 2 (p2w2 w5). MATCH at level 02 and NTSC-U; false fold: levels 05/08/11/28 use 0x2F8 and gp slot D_001DF... (+0x3328) instead of 0x2D8/+0x2128.
   Needs a split of the shared place. */
extern u16 *D_L02_0021B460[];
extern u8 *D_L02_001DE99C;
__asm__(".extern D_L02_001DE99C, 16");
extern s32 D_001DE9D8_sda;

void func_L02_003A5138(u8 *a0) {
    u16 *p;
    u8 *e;
    if (a0[0x21] == 0xFF) {
        return;
    }
    p = D_L02_0021B460[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_001DE9D8_sda && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L02_0021B460[a0[0x21]])) {
        e = D_L02_001DE99C + ((*p & 0x7FFF) << 8);
        if (e == 0) {
            break;
        }
        if (*(s16 *)(e + 0xAA) == *(s16 *)(a0 + 0xAA)) {
            *(s32 *)(*(u8 **)(e + 0x68) + 0x2D8) = 1;
        }
        p++;
    }
}
