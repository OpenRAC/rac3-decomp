#include "common.h"

/* NTSC-U counterpart of func_L13_003AECE0 (src/levels/shared/L13_003AEB48.c): 0.02 -> 0.0166667 */
#include "vu0.h"
extern f32 D_L13_001DE70C, D_L13_001DE710, D_L13_001DE6EC_003ACEF8;

/* localdecomp:start func_L13_003ACEF8 */
__asm__(".extern D_L13_001DE70C, 4");
__asm__(".extern D_L13_001DE710, 4");
extern f32 D_L13_001DE70C;
extern f32 D_L13_001DE710;
extern s32 func_L01_00457440(void *);
extern f32 func_00389380(f32, f32);
extern f32 func_00388978(f32);
extern void func_L13_003AD0C8(u8 *, u8 *, f32);
extern f32 func_00388A28(f32, f32);
extern void func_L01_00445758(void *, void *, s32, f32, f32, f32, f32);

s32 func_L13_003ACEF8(u8 *o) {
    u8 *p;
    s32 r;
    f32 a;
    u8 *q = o + 0xF8;

    p = *(u8 **)(o + 0x68);
    *(f32 *)(o + 0x18) = *(f32 *)(o + 0x18) - *(f32 *)(p + 0x3B4);
    r = func_L01_00457440(o);
    a = func_00389380(*(f32 *)(p + 0x3B0), D_L13_001DE710 * 0.017453292f * 0.0166666675f);
    *(f32 *)(p + 0x3B0) = a;
    *(f32 *)(p + 0x3B4) = func_00388978(a) * D_L13_001DE70C;
    *(f32 *)(o + 0x18) = *(f32 *)(o + 0x18) + *(f32 *)(p + 0x3B4);
    func_L13_003AD0C8(o, p + 0x1F0, *(f32 *)(p + 0x204));
    a = func_00388A28(*(f32 *)(p + 0x130) - *(f32 *)(o + 0x10), *(f32 *)(p + 0x134) - *(f32 *)(o + 0x14));
    func_L01_00445758(q, p + 0x204, 0, a, *(f32 *)(p + 0x164), *(f32 *)(p + 0x168), *(f32 *)(p + 0x16C));
    return r;
}
/* localdecomp:end func_L13_003ACEF8 */
