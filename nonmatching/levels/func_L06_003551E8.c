/* Level 06 shared (src/levels/shared/L06_00354F18.c) draft, 2026-11-15. 34 differences with the file's flags (-mvu0-use-vf0-vf2 @ps2as): retail's range test of +0x20 is `andi`+`sltiu` (this C gets `slti`; every unsigned spelling drops the `andi`), and retail sets $f12 = 0 before the div.s and loads $a1 last before the call. The call's argument order in the prototype did not change it; a switch is further off. */
#include "common.h"
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);
extern s32 func_L06_00351390(u8 *a0, u8 *a1);
extern f32 func_L01_00477F20(void *a0, s32 a1, f32 f12, f32 f13, f32 f14);
typedef struct { f32 x, y, z, w; } E16;
s32 func_L06_003551E8(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    s32 state;
    s32 idx;

    if (*(s32 *)(v + 0x350) == 0 && func_L06_00351390(a0, v)) {
        func_L01_004450F0(a0, 1, 1);
        return 1;
    }
    state = a0[0x20];
    if ((state & 0xFF) == 15) {
        func_L01_004450F0(a0, 16, -1);
        return 1;
    }
    if ((state & 0xFF) == 1 || ((state - 4) & 0xFF) < 11) {
        idx = *(s32 *)(v + 0x344);
        *(f32 *)(v + 0x34C) = func_L01_00477F20(*(E16 **)(v + 0x358), *(s32 *)(v + 0x27C), 0.0f,
                              idx + *(f32 *)(v + 0x348) / (*(E16 **)(v + 0x358))[idx + 1].w, 20.0f)
                          * *(s32 *)(v + 0x27C);
        if ((u32)(a0[0x20] - 4) >= 11) {
            func_L01_004450F0(a0, 3, -1);
            return 1;
        }
    }
    return 0;
}
