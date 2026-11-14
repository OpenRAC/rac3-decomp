#include "common.h"

/* NTSC-U counterpart of func_L03_003ADE98 (src/levels/shared/L03_003AD8C8.c): 0.125664 -> 0.10472 */
typedef struct { u8 p0[0x34]; u16 h34; } M_3ABF90;
extern void func_003C1A40(M_3ABF90 *, s32, s32, s32, s32);

/* localdecomp:start func_L03_003AC560 */
extern f32 func_00389380(f32, f32);
extern s32 func_L03_0043BF68(s32, s32, f32);

void func_L03_003AC560(u8 *a0, s32 a1, s32 a2) {
    u8 *pv = *(u8 **)(a0 + 0x68);
    f32 x = func_00389380(*(f32 *)(pv + 0x10), 0.104719765f);
    *(f32 *)(pv + 0x10) = x;
    func_003C1A40(*(M_3ABF90 **)pv, func_L03_0043BF68(a1, a2, x), 14, 14, 14);
    func_003C1A40(*(M_3ABF90 **)(pv + 0x30), func_L03_0043BF68(a1, a2, *(f32 *)(pv + 0x10)), 14, 14, 14);
}
/* localdecomp:end func_L03_003AC560 */
