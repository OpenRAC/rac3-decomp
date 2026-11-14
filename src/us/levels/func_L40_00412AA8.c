#include "common.h"

/* NTSC-U counterpart of func_L40_004132C8 (src/levels/shared/L40_004132C8.c): 50 -> 60 */
/* localdecomp:start func_L40_00412AA8 */
extern void func_L39_00660240(u8 *, void *, s32);
extern void func_L40_00513D18(u8 *g, void *pos, s32 a2, s32 a3, f32 f);
extern u8 *D_L40_002494B0[8] __attribute__((section(".sdata")));
extern u8 *D_L40_002485DC;
__asm__(".extern D_L40_002485DC, 16");

void func_L40_00412AA8(u8 *self, u8 *buf) {
    s32 *vars = *(s32 **)(self + 0x68);
    s32 pos[4];
    s32 idx;
    f32 f;
    s32 b;

    if ((*(u32 *)buf & 0xF) < 8) {
        func_L39_00660240(buf, &idx, 4);
        func_L39_00660240(buf, pos, 16);
        func_L39_00660240(buf, &f, 4);
        func_L39_00660240(buf, &b, 4);
        if (D_L40_002494B0[idx] != 0) {
            func_L40_00513D18(D_L40_002494B0[idx], pos, (s32)(D_L40_002485DC + (vars[0] << 8)), 0x3C, f);
            D_L40_002494B0[idx][0x1A15] = b;
        }
    }
}
/* localdecomp:end func_L40_00412AA8 */
