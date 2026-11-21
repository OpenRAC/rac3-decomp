/* functional: medium. Closes the Veldin vendor/shop menu (counterpart of func_L01_004BB4E0): frees the list menu object if page 5, releases the two selected-sound ids, restores the hero and camera (computing the hero's menu-exit camera placement with a collision test), runs the vendor-object callback when the "bought" flag is set, resets the clamped hero/vehicle slots, and plays the closing sound unless the one-shot flag D_L01_001DABD8 was set (then just clears it). vadd.xyz and lq/sq are written as plain C; names/fields mine, offsets from the asm. */
extern u8 D_001A4BE0[];
extern u8 D_001A4C60[];
extern u8 D_L01_001E2CBD;
extern u8 D_L01_001EAA20[];
extern u8 D_L01_001DAC20_sda[];
extern s32 D_L01_001D6694;
extern s32 D_L01_001D673C;
extern u8 D_L01_001DABDC_sda;
extern s32 D_L01_001DABD8_sda;
extern u8 D_001CCFD0[];

extern u8 *func_003B9BD0(s32);
extern s32 func_003B9E90(u8 *);
extern void func_003935B0(s32, s32);
extern void func_L01_0041FE68(void);
extern void func_L01_00510AD0(void);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038DAB8(f32, f32);
extern void func_003C5180(void *, void *, s32);
extern void func_L01_004515D8(void *, void *, s32);
extern void func_003C48A8(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, s32, s32);
extern void func_L01_004F50C8(void *, void *, s32, s32);
extern void func_L01_003EB5E0(s32, s32);
extern void *func_L01_0043B548(s32, s32);
extern void func_L01_004A3610(u8 *, u8 *);
extern void func_L01_004BF950(void);
extern void func_003C2880(void *);
extern s32 func_0013C1D0(s32);
extern void func_003A1D00(void);
extern void func_0013B620(void);

static void copy16_004BBD90(void *d, void *s) {
    ((u64 *)d)[0] = ((u64 *)s)[0];
    ((u64 *)d)[1] = ((u64 *)s)[1];
}

static void addxyz_004BBD90(f32 *d, f32 *a) {
    d[0] = d[0] + a[0];
    d[1] = d[1] + a[1];
    d[2] = d[2] + a[2];
}

void func_L01_004BBD90(void) {
    u8 *T = (u8 *)D_L01_002446C0;
    u8 *hero = D_001A4BE0;
    u8 *obj;
    u8 *hw;
    void *snd;
    void (*fn)(s32, s32);
    f32 sp[24] __attribute__((aligned(16)));

    if (*(s32 *)(T + 0x50) == 5) {
        func_003B9E90(func_003B9BD0(0));
    }
    if (*(s32 *)(T + 0x7C) != -1) {
        func_003935B0(*(s32 *)(T + 0x7C), 0);
    }
    if (*(s32 *)(T + 0x78) != -1) {
        func_003935B0(*(s32 *)(T + 0x78), 0);
    }
    *(s32 *)(T + 0x78) = -1;
    *(s32 *)(T + 0x7C) = -1;
    func_L01_0041FE68();
    D_L01_001E2CBD = T[0x764];
    D_L01_001D6694 = 0;
    hero[0x25E5] = 0;
    func_L01_00510AD0();
    if (*(s32 *)(T + 0x60) == 0) {
        copy16_004BBD90(sp + 8, D_L01_001DAC20_sda);
        func_0038D000(sp, sp + 8, (u8 *)*(s32 *)(T + 0x28) + 0xC0);
        obj = (u8 *)*(s32 *)(T + 0x28);
        addxyz_004BBD90(sp, (f32 *)(obj + 0x10));
        sp[4] = 0;
        sp[5] = 0;
        sp[6] = func_0038DAB8(*(f32 *)(obj + 0xF8), 3.1415927f);
        if (D_L01_001D673C != 0) {
            hw = (u8 *)*(s32 *)(hero + 0x25C0);
            func_003C5180(sp, sp + 12, 1);
            func_L01_004515D8(hw + 0xC0, sp + 12, 0);
            func_003C48A8(hw + 0xC0, sp + 4);
            func_0038CF68(sp + 16, hw + 0xE0, 1.0f);
            func_0038CF68(sp + 20, hw + 0xE0, 1.0f);
            addxyz_004BBD90(sp + 16, sp);
            addxyz_004BBD90(sp + 20, sp);
            if (func_003D3CB0(sp + 16, sp + 20, 0, *(s32 *)(hero + 0x25C0), 0) != 0) {
                copy16_004BBD90(sp, D_L01_001EAA20);
                func_003C5180(sp, sp + 12, 1);
                func_L01_004515D8(hw + 0xC0, sp + 12, 0);
                func_003C48A8(hw + 0xC0, sp + 4);
            }
        }
        func_L01_004F50C8(sp, sp + 4, 0, 0);
        func_L01_003EB5E0(0, 2);
    }
    if (T[0x758] != 0) {
        snd = func_L01_0043B548(0x1936, 0x10);
        func_L01_004A3610(D_001A4C60, D_001A4C60 + 0x10);
        fn = *(void (**)(s32, s32))snd;
        fn(*(s32 *)(T + 0x75C), D_L01_001DABDC_sda);
        D_L01_001DABDC_sda = 0;
    }
    obj = (u8 *)*(s32 *)(T + 0x28);
    obj[0x20] = 1;
    if ((u32)(*(u16 *)(D_001CCFD0 + 0x76) - 6) >= 2) {
        *(u16 *)(D_001CCFD0 + 0x76) = 5;
    }
    if ((u32)(*(u16 *)(D_001CCFD0 + 0x9E) - 6) >= 2) {
        *(u16 *)(D_001CCFD0 + 0x9E) = 5;
    }
    if (T[0x89] != 0) {
        func_L01_004BF950();
    }
    if (*(s32 *)(T + 0x60) != 0) {
        func_003C2880((void *)*(s32 *)(T + 0x28));
    }
    if (D_L01_001DABD8_sda != 0) {
        D_L01_001DABD8_sda = 0;
    } else {
        func_0013C1D0(0x4D);
        func_003A1D00();
    }
    func_0013B620();
}
