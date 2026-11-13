/* func_L24_00359E30: level 24 near miss. 34 differences after a statement-order hill climb from 59: a long run of independent stores whose retail scheduling order was not reproduced; needs the existing @ps2as, the $gp floats D_L24_001DD630/634 with .extern hints */
typedef int u128_t __attribute__((mode(TI)));
__asm__(".extern D_L24_001DD630, 4");
__asm__(".extern D_L24_001DD634, 4");
extern f32 D_L24_001DD630;
extern f32 D_L24_001DD634;
extern void func_L24_0035AB58(void *);
extern void func_L24_0035A300(u8 *);

void func_L24_00359E30(u8 *a0) {
    u8 *p = *(u8 **)(a0 + 0x68);
    f32 f6;
    p[0xB8] = 4;
    p[0x86] = 7;
    p[0x80] = 0xE;
    p[0xE3] = 0xF;
    p[0xE2] = 8;
    *(f32 *)(p + 0xAC) = 0.15f;
    p[0xE7] = 1;
    *(f32 *)(p + 0x8C) = 0.3f;
    *(f32 *)(p + 0x90) = 0.0200000014f;
    *(f32 *)(p + 0x94) = 0.0100000007f;
    *(f32 *)(p + 0x98) = 0.0140000004f;
    *(f32 *)(p + 0x9C) = 0.000800000038f;
    p[0xEA] = 3;
    *(f32 *)(p + 0x118) = 0.25f;
    p[0x58] = 0x14;
    p[0x5A] = 0xE;
    *(f32 *)(p + 0xA0) = 0.5f;
    *(f32 *)(p + 0xA4) = 0.5f;
    if (*(s16 *)(p + 0x34) == 0) {
        *(s16 *)(p + 0x34) = 1;
        *(f32 *)(p + 0x30) = 1.1f;
    }
    f6 = *(f32 *)(p + 0x1A8);
    p[0x39] = 1;
    p[0x44] = 1;
    *(f32 *)(p + 0x1F0) = D_L24_001DD630;
    *(f32 *)(p + 0x1F4) = D_L24_001DD634;
    *(f32 *)(p + 0x1FC) = -(f6 + 0.15f);
    *(f32 *)(p + 0x200) = 0.2f;
    *(f32 *)(p + 0x40) = 0.5f;
    *(f32 *)(p + 0x1DC) = 0.00392000005f;
    *(s16 *)(p + 0x36) = 0x19;
    *(f32 *)(p + 0x1F8) = f6;
    *(f32 *)(p + 0x204) = 0.2f;
    *(f32 *)(p + 0x214) = 0.00100000005f;
    *(f32 *)(a0 + 0x2C) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) * 0.75f;
    *(u128_t *)(p + 0x150) = *(u128_t *)(a0 + 0x10);
    p[0x198] = 1;
    *(s16 *)(p + 0x194) = 0;
    *(s32 *)(p + 0x1BC) = 0;
    func_L24_0035AB58(a0);
    func_L24_0035A300(a0);
}
