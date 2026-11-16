/* NTSC-U draft (Claude wave K): C of func_L13_003ACEF8, the NTSC-U twin of func_L13_003AECE0, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L13_003ACEF8", whose code is not the PAL one).
 * Worker's note: 10 words off with @ps2as (float lui/ori need it; PAL line lacks it) + .extern 4 on D_L13_001DE710; p+0x204 gets CSE'd into an extra saved reg (s3/s4) in ours, retail recomputes; 6 variants of the address expression tried
 */
#include "common.h"

/* localdecomp:start func_L13_003ACEF8 */
extern f32 D_L13_001DE70C;
__asm__(".extern D_L13_001DE710, 4");
extern f32 D_L13_001DE710;

extern s32 func_L01_00457440(void *);
extern f32 func_00389380(f32, f32);
extern f32 func_00388978(f32);
extern void func_L13_003AD0C8(void *, void *, f32);
extern f32 func_00388A28(f32, f32);
extern void func_L01_00445758(void *, void *, s32, f32, f32, f32, f32);

s32 func_L13_003ACEF8(u8 *o) {
    u8 *p;
    s32 r;
    f32 a;

    p = *(u8 **)(o + 0x68);
    *(f32 *)(o + 0x18) = *(f32 *)(o + 0x18) - *(f32 *)(p + 0x3B4);
    r = func_L01_00457440(o);
    a = func_00389380(*(f32 *)(p + 0x3B0), D_L13_001DE710 * 0.017453292f * 0.016666668f);
    *(f32 *)(p + 0x3B0) = a;
    *(f32 *)(p + 0x3B4) = func_00388978(a) * D_L13_001DE70C;
    *(f32 *)(o + 0x18) = *(f32 *)(o + 0x18) + *(f32 *)(p + 0x3B4);
    func_L13_003AD0C8(o, p + 0x1F0, *(f32 *)(p + 0x204));
    func_L01_00445758(o + 0xF8, p + 0x204, 0,
                      func_00388A28(*(f32 *)(p + 0x130) - *(f32 *)(o + 0x10), *(f32 *)(p + 0x134) - *(f32 *)(o + 0x14)),
                      *(f32 *)(p + 0x164), *(f32 *)(p + 0x168), *(f32 *)(p + 0x16C));
    return r;
}
/* localdecomp:end func_L13_003ACEF8 */
