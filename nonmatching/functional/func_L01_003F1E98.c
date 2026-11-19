/* functional: high. EXACT at level 01. */
extern u8 D_001D5480;
extern u8 D_001D5477;
extern u8 D_001D548F;
extern s32 D_L01_001E0EE0;
extern s32 D_001E0EE0_sda;
extern u8 *D_001E0ED4_sda;
__asm__(".extern D_001E0EE0_sda, 4");
__asm__(".extern D_001E0ED4_sda, 4");
extern void func_0038CBC8();

void func_L01_003F1E98(s32 a0) {
    if (a0 != 0) {
        func_0038CBC8(&D_001D5480, 0x13);
    }
    if (D_001D5477 != D_001D548F) {
        s32 i;
        u8 *p;
        s32 n = D_001E0EE0_sda;
        p = D_001E0ED4_sda;
        for (i = 0; i < n; i++) {
            p[0x1E] ^= 8;
            p += 0x20;
            n = D_L01_001E0EE0;
        }
    }
}
