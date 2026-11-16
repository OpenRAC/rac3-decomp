/* PAL near miss (Codex wave 10): near miss: 2 words differ with the file's flags.
 * Worker's note: 2 instruction diffs/79 words, size 316: first call a2/f12 moves swapped at +0x98/+0xA8; exact existing callee prototype preserved. Three source forms same residual; contract compiles cleanly. Best build/codex/w552/attempt01.log; contract ...
 */
#include "common.h"
/* localdecomp:start func_L01_004F45F0 */
void func_L01_004F45F0(void) {
    extern f32 func_L01_00448728(f32 *, void *, s32, f32, f32, f32, f32);
    extern void func_L01_004EEC98(f32, f32, f32);
    extern void func_L01_004F4410(s32);
    vu0_q v;
    u8 *h = (u8 *)&D_001A4BE0;
    s32 mode = h[0x25F4];
    if (*(s16 *)(h + 0x218)) mode = 1;
    switch (mode) {
    case 0: {
        s32 state = *(s32 *)(h + 0x25C4);
        if (state == 36 || state == 37 || *(s32 *)(h + 0x25CC) == 17 || state == 121 || state == 48 || state == 44 || state == 43) return;
        v = *(vu0_q *)(h + 0x90);
        func_L01_00448728((f32 *)&v, h + 0xA0, 0, 0.0f, 0.02160000056028366f, 0.4320000410079956f, 0.10471975803375244f);
        func_L01_00448728((f32 *)((u8 *)&v + 4), h + 0xA4, 0, 0.0f, 0.02160000056028366f, 0.4320000410079956f, 0.10471975803375244f);
        func_L01_004EEC98(*(f32 *)(h + 0xA0), *(f32 *)(h + 0xA4), 0.0f);
        break;
    }
    case 1:
    case 2:
        func_L01_004F4410(mode);
        break;
    }
}
/* localdecomp:end func_L01_004F45F0 */
