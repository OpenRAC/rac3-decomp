#include "common.h"
#include "vu0.h"

/* NTSC-U-only function (flags of its neighbours: @ps2as) */
/* localdecomp:start func_L07_003E1598 */
extern u8 D_L07_001DEA00[0x30] __attribute__((section(".sdata")));
__asm__(".extern D_L07_001DEA00, 8");
extern void func_003BD9A0(void *, void *, void *);
extern f32 func_0037E250(f32, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_003BF6A8(void *, f32);
extern void func_L01_0046A9C8(void *, void *, void *, void *, s32);

void func_L07_003E1598(u8 *obj, void *bone) {
    vu0_v4 m[4];
    vu0_v4 dir;
    vu0_v4 pos;
    u8 *p;
    f32 r;
    s32 i;

    func_003BD9A0(obj, bone, m);
    r = func_0037E250(0.15f, 12.0f * 0.016666668f);
    func_003886E8(&dir, &m[2], -r);
    p = D_L07_001DEA00;
    for (i = 2; i >= 0; i--) {
        pos = m[3];
        func_003BF6A8(&pos, 0.025f);
        func_L01_0046A9C8(obj, &pos, &dir, p, 1);
        p += 0x10;
    }
}
/* localdecomp:end func_L07_003E1598 */
