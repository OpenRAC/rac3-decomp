#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct V_003A8330 {
    f32 x, z, y, w;
} __attribute__((aligned(16))) V_003A8330;

INCLUDE_ASM("asm/levels", func_L08_003A9B08);

INCLUDE_ASM("asm/levels", func_L08_003AA088);

/* localdecomp:start func_L08_003AA1F8 */
/* PAL port of the NTSC-U match src/us/levels/func_L08_003A8330.c */


extern s32 D_L08_001DE2B0;
extern s32 func_0038CAD0(void *);

void func_L08_003AA1F8(u8 *o) {
    u8 *p;
    V_003A8330 c;
    f32 t;

    p = *(u8 **)(o + 0x68);
    if (p != 0) {
        *(u128_t *)&c = 0;
        c.x = 128.0f;
        c.z = 128.0f;
        c.y = 128.0f;
        c.w = 255.0f;
        func_0038CAD0(p + 0x10);
        t = (f32)*(s32 *)(p + 0x10) / (f32)((D_L08_001DE2B0 * 5 + 2) / 6);
        *(s32 *)(o + 0x78) = ((s32)((c.y - 64.0f) * t + 64.0f) << 16) | 0xFF000000 | ((s32)((c.z - 64.0f) * t + 64.0f) << 8) | (s32)((c.x - 255.0f) * t + 255.0f);
    }
}
/* localdecomp:end func_L08_003AA1F8 */

INCLUDE_ASM("asm/levels", func_L08_003AA300);
