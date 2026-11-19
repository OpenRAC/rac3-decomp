#include "common.h"


/* localdecomp:start func_L13_003C3268 */
__asm__(".extern D_L13_001DEB88, 4");
extern f32 D_L13_001DEB88;
extern f32 D_L13_001E1BA0[];
extern s32 D_L13_001E1B98[];
extern f32 func_L13_00420D30(f32, f32);
extern void func_L13_00418DA8(s32, u32 *, u32 *, u32 *);

void func_L13_003C3268(u8 *self) {
    u32 r;
    u32 g;
    u32 b;
    u8 *o;
    f32 *s;
    s32 i;

    o = *(u8 **)(self + 0x68);
    s = &D_L13_001DEB88;
    for (i = 0; i < 5; i++) {
        D_L13_001E1BA0[i] = s[i];
    }
    *(f32 *)(o + 0x25C) = func_L13_00420D30(0.0523598827f, 0.139626354f);
    func_L13_00418DA8((s32)self, &r, &g, &b);
    *(u8 *)(o + 0x264) = *(u8 *)&r;
    *(u8 *)(o + 0x265) = *(u8 *)&g;
    *(u8 *)(o + 0x266) = *(u8 *)&b;
    D_L13_001E1B98[0] = 0;
}
/* localdecomp:end func_L13_003C3268 */
