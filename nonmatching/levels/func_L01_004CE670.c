/* NTSC-U draft (Claude wave K): C of func_L01_004CA9B0, the NTSC-U twin of func_L01_004CE670, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U, no count recorded (NTSC-U twin "func_L01_004CA9B0", whose code is not the PAL one).
 * Worker's note: 29 words off; same family as func_L01_004CAA98: retail keeps o, i and the constant 0x230 in saved regs (s5/s1/s4) and re-multiplies after the call, ours CSEs the product; address computed before the call (e = ...) and r split out did not change it
 */
#include "common.h"

/* localdecomp:start func_L01_004CA9B0 */
extern s32 func_0037DF98(s32);
extern void func_0011B2E8(void *, s32, s32);
extern void func_L01_004C9EF8(void *, s32, s32, f32, f32);

void func_L01_004CA9B0(u8 *o, s32 i, s32 a, s32 b, s32 c) {
    s32 v;
    u8 *e;
    s32 r;

    v = 0x78;
    if (c != -1) {
        v = c;
    }
    e = o + 0x4698 + i * 0x230;
    r = func_0037DF98(a);
    func_0011B2E8(e, r, b);
    func_L01_004C9EF8(o + 0x4610 + i * 0x230, 1, v, 255.0f, 135.0f);
}
/* localdecomp:end func_L01_004CA9B0 */
