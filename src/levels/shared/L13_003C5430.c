#include "common.h"

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

/* localdecomp:start func_L13_003C56A0 */
typedef struct {
    u8 pad0[0x200];
    f32 f200[4];
    f32 f210[4];
    s32 f220[4];
    u8 pad230[0x10];
    s32 f240;
    s32 f244[3];
} S_003C56A0;
extern s32 func_00382468(s32);
extern f32 func_0038DB48(f32);
extern s32 func_00382498(s32, s32);

void func_L13_003C56A0(u8 *self)
{
    S_003C56A0 *p = *(S_003C56A0 **)(self + 0x68);
    s32 i;

    for (i = 0; i < 3; i++) {
        p->f244[i] = p->f240 - 1;
        if (p->f240 == 0) {
            p->f244[i] += func_00382468(4);
        }
    }
    if (p->f240 == 0 && p->f244[0] == p->f244[1] && p->f244[0] == p->f244[2]) {
        p->f244[2] += func_00382468(3) + 1;
    }
    for (i = 0; i < 3; i++) {
        p->f200[i] = func_0038DB48(p->f200[i]);
        if (i != 1) {
            p->f220[i] = func_00382498(4, 6) * 4 + p->f244[i];
        } else {
            s32 r = func_00382498(4, 6) * 4;
            s32 t = p->f244[1] - 4;
            p->f220[1] = r - t;
        }
        p->f210[i] = (f32)p->f220[i] * 6.2831855f * 0.25f;
    }
}
/* localdecomp:end func_L13_003C56A0 */
