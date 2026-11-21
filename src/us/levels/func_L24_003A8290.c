#include "common.h"

/* NTSC-U counterpart of func_L24_003A9E20 (src/levels/shared/L24_003A97D8.c): 120 and 60 (frames at 60 Hz) where PAL passes 100 and 50 */
/* localdecomp:start func_L24_003A8290 */
extern s32 D_L24_001DE47C;
extern f32 D_L24_001DE488;
__asm__(".extern D_L24_001DE47C, 4");
__asm__(".extern D_L24_001DE488, 4");
extern u8 D_L24_001E1750[] __attribute__((section(".sdata")));
extern u8 D_L24_001E1770[] __attribute__((section(".sdata")));
extern s32 D_L24_001E1790;
extern f32 func_0037E250(f32, f32);
extern void func_L03_0034A658(u8 *, s32, s32, f32, s32, void *);
extern void func_L24_00357F98(u8 *);
extern void func_L24_003A8080();

typedef struct {
    u8 pad0[4];
    s32 z[4];
    u8 pad14[0x50 - 0x14];
    f32 a[12];
} V_003A8290;

void func_L24_003A8290(u8 *a0) {
    V_003A8290 *v = *(V_003A8290 **)(a0 + 0x68);
    s32 i;

    if (D_L24_001DE47C == 0) {
        D_L24_001DE47C = 1;
        func_L03_0034A658(D_L24_001E1750, 120, 60, 2.2f, 4, func_L24_003A8080);
    }
    v->a[0] = func_0037E250(0.0f, 1.0f);
    for (i = 1; i < 12; i++) {
        v->a[i] = (1.0f - (D_L24_001DE488 < v->a[i - 1] ? D_L24_001DE488 : v->a[i - 1])) - (D_L24_001DE488 < 1.0f - v->a[i - 1] ? D_L24_001DE488 : 1.0f - v->a[i - 1]);
        v->a[i] = func_0037E250(0.0f, v->a[i]);
        if (v->a[i - 1] - (D_L24_001DE488 < v->a[i - 1] ? D_L24_001DE488 : v->a[i - 1]) < v->a[i]) {
            v->a[i] += (D_L24_001DE488 < v->a[i - 1] ? D_L24_001DE488 : v->a[i - 1]) + (D_L24_001DE488 < 1.0f - v->a[i - 1] ? D_L24_001DE488 : 1.0f - v->a[i - 1]);
        }
    }
    func_L24_00357F98(D_L24_001E1770);
    D_L24_001E1790 = 0x65;
    for (i = 3; i >= 0; i--) {
        v->z[i] = 0;
    }
}
/* localdecomp:end func_L24_003A8290 */
