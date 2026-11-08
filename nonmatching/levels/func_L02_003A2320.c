/* Level 02 (Florana), PAL. 4 diff with check.py --target level_02. 4 differences with `@ps2as` (set for its file): the `addiu 7` and `addiu 100` are swapped (`$v0`/`$a0`) and the `sh 0x2e` and `sw 0x20` stores are swapped; all 120 orderings of the five stores after the call, and 2520 orderings including the two stores through arg0, give the same two differences. */
#include "common.h"
extern f32 func_003824E0(f32, f32);
void func_L02_003A2320(void *arg0) {
    u8 *p;
    if (*(u8 *)((u8 *)arg0 + 0x20) == 0) {
        p = *(u8 **)((u8 *)arg0 + 0x68);
        *(f32 *)(p + 0x28) = func_003824E0(0.031415928f, 0.12566371f);
        *(s16 *)(p + 0x2E) = 7;
*(f32 *)(p + 0x24) = 0.65f;
*(s16 *)(p + 0x2C) = 50;
*(f32 *)(p + 8) = 0.00392f;
*(s32 *)(p + 0x20) = 100;
        *(u8 *)((u8 *)arg0 + 0x20) = 1;
        *(u16 *)((u8 *)arg0 + 0x34) |= 0x808;
    }
}
