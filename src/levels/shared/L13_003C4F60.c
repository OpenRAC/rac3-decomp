#include "common.h"

INCLUDE_ASM("asm/levels", func_L13_003C4F60);

/* localdecomp:start func_L13_003C5430 */
__asm__(".extern D_L13_001DEB58, 4");
extern f32 D_L13_001DEB58;
extern f32 D_L13_001E1B20[];
extern s32 D_L13_001E1B18[];
extern f32 func_003824E0(f32, f32);
extern void func_003C6FB0(s32, u32 *, u32 *, u32 *);

void func_L13_003C5430(u8 *self) {
    u32 r;
    u32 g;
    u32 b;
    u8 *o;
    f32 *s;
    s32 i;

    o = *(u8 **)(self + 0x68);
    s = &D_L13_001DEB58;
    for (i = 0; i < 5; i++) {
        D_L13_001E1B20[i] = s[i];
    }
    *(f32 *)(o + 0x25C) = func_003824E0(0.0628318564f, 0.1675516218f);
    func_003C6FB0((s32)self, &r, &g, &b);
    *(u8 *)(o + 0x264) = *(u8 *)&r;
    *(u8 *)(o + 0x265) = *(u8 *)&g;
    *(u8 *)(o + 0x266) = *(u8 *)&b;
    D_L13_001E1B18[0] = 0;
}
/* localdecomp:end func_L13_003C5430 */

INCLUDE_ASM("asm/levels", func_L13_003C54F8);

INCLUDE_ASM("asm/levels", func_L13_003C56A0);

INCLUDE_ASM("asm/levels", func_L13_003C5838);

INCLUDE_ASM("asm/levels", func_L13_003C59E8);
