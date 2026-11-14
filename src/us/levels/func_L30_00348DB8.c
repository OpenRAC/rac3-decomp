#include "common.h"

/* NTSC-U counterpart of func_L30_00349B28 (src/levels/30_vidcomic_unnamed/L30_00349390.c) */
/* localdecomp:start func_L30_00348DB8 */
extern s32 D_001DD230_sda[2];
__asm__(".extern D_001DD230_sda, 8");
extern f32 D_001DD2E8_sda[2];
__asm__(".extern D_001DD2E8_sda, 8");
extern f32 D_001DD2F8_sda[2];
__asm__(".extern D_001DD2F8_sda, 8");
extern f32 D_001DD308_sda[2];
__asm__(".extern D_001DD308_sda, 8");
extern s32 D_001DD334_sda;
__asm__(".extern D_001DD334_sda, 4");
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);

void func_L30_00348DB8(u8 *a0) {
    f32 *tbl;
    f32 r;
    s32 i;
    u8 *d;

    i = 0;
    d = *(u8 **)(a0 + 0x68);
    if (a0[0x20] == 3) {
        tbl = D_001DD2E8_sda;
    } else if (a0[0x20] == 4) {
        tbl = D_001DD2F8_sda;
    } else if (a0[0x20] == 5) {
        tbl = D_001DD308_sda;
    } else {
        return;
    }
    *(s32 *)(d + 0xD0) = D_001DD230_sda[a0[0x20] - 3];
    r = func_0037E250(0.0f, 1.0f);
    while (tbl[i] < r) {
        r -= tbl[i];
        i++;
    }
    i += 4;
    *(s32 *)(d + 0xCC) = i;
    if (i == 4) {
        *(s32 *)(d + 0xC0) = func_0037E208(0, 1);
    }
    if (*(s32 *)(d + 0xCC) == 6) {
        if (a0[0x43] != 1) {
            func_003BE4F0(a0, 1, 0, D_001DD334_sda);
        }
        *(s32 *)(d + 0xA8) = 1;
    } else {
        if (a0[0x43] != 2) {
            func_003BE4F0(a0, 2, 0, D_001DD334_sda);
        }
        *(s32 *)(d + 0xA8) = 0;
    }
}
/* localdecomp:end func_L30_00348DB8 */
