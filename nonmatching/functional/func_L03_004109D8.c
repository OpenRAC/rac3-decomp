/* functional: medium. Rewritten from the asm. Names for the three structures are guesses (D_L03_001E6800 is the game-state block with the object list at +0x1A0, as the neighbours' G_004121B8; D_L03_002E5CA0 is a 0x44-byte render-request block). gp-relative D_L03_001D70D0 (a buffer address) and D_L03_001D70C5 (a byte flag) are declared small via .extern as in the neighbours. Division by 6 is signed as in retail. Not byte-matched. Unsure what the 4 vectors at +0x00..0x30 of A mean (a quad; edge lengths give an aspect ratio). */
__asm__(".extern D_L03_001D70D0, 4");
__asm__(".extern D_L03_001D70C5, 1");
typedef int u128_004109D8 __attribute__((mode(TI)));
extern u8 D_L03_001D70D0[];
extern u8 D_L03_001D70C5;
extern u8 D_L03_001E6800[];
extern u8 D_L03_002E5CA0[];
extern f32 func_0038CF38(void *, void *);
extern void func_L01_004234E8(void *, void *);
extern void func_L01_00404808(void *, void *);
extern void func_L01_00423580(void);
extern void func_L01_00423530(void *, void *);
extern void func_L01_00423690(void);
void func_L03_004109D8(u8 *a, u8 *b, u8 *c, s32 d) {
    s32 ok = 1;
    s32 w = *(s32 *)(D_L03_001E6800 + 0x34);
    f32 w1, w2;
    s32 i;
    if (w < (*(s32 *)(a + 0x50) * 5 + 2) / 6) {
        ok = 0;
    } else if ((*(s32 *)(a + 0x54) * 5 + 2) / 6 < w) {
        ok = 0;
    } else {
        w1 = (func_0038CF38(a, a + 0x20) + func_0038CF38(a + 0x10, a + 0x30)) * 0.5f;
        w2 = (func_0038CF38(a, a + 0x10) + func_0038CF38(a + 0x10, a + 0x20)) * 0.5f;
        if (*(u8 **)(D_L03_002E5CA0 + 0x20) == 0) {
            *(u8 **)(D_L03_002E5CA0 + 0x20) = D_L03_001D70D0;
        }
        if (w2 < w1) {
            *(f32 *)(D_L03_002E5CA0 + 0x24) = 1.0f;
            *(f32 *)(D_L03_002E5CA0 + 0x28) = w2 / w1;
        } else {
            *(f32 *)(D_L03_002E5CA0 + 0x28) = 1.0f;
            *(f32 *)(D_L03_002E5CA0 + 0x24) = w1 / w2;
        }
        *(u128_004109D8 *)D_L03_002E5CA0 = *(u128_004109D8 *)(a + 0x40);
        for (i = 0; i < 4; i++) {
            *(u128_004109D8 *)(*(u8 **)(D_L03_002E5CA0 + 0x20) + i * 16) = *(u128_004109D8 *)(a + i * 16);
        }
        if (b != 0) {
            w = *(s32 *)(D_L03_001E6800 + 0x34);
            if (!(w < (*(s32 *)b * 5 + 2) / 6) && !((*(s32 *)(b + 4) * 5 + 2) / 6 < w)) {
                func_L01_004234E8(*(u8 **)(D_L03_002E5CA0 + 0x20), b);
                func_L01_00404808(func_L01_00423580, 0);
                if (*(s32 *)(b + 0x14) == 0) {
                    ok = 0;
                }
            }
        }
        if (c != 0 && d != 0) {
            func_L01_00423530(*(u8 **)(D_L03_002E5CA0 + 0x20), c);
            func_L01_00404808(func_L01_00423690, 0);
            if (D_L03_001D70C5 != 0) {
                ok = 0;
            }
        }
    }
    if (ok == 0 || *(s32 *)(a + 0x58) < 0) {
        *(u8 **)(D_L03_001E6800 + 0x50) = 0;
    } else {
        *(u8 **)(D_L03_001E6800 + 0x50) = D_L03_002E5CA0;
        i = 0;
        do {
            s32 v = *(s32 *)(a + 0x58 + i * 4);
            if (v < 0) {
                *(s32 *)(D_L03_002E5CA0 + 0x40 + i * 4) = 0;
            } else {
                *(s32 *)(D_L03_002E5CA0 + 0x40 + i * 4) = *(s32 *)(D_L03_001E6800 + 0x1A0 + v * 4);
            }
            i++;
        } while (i < 4);
    }
}
