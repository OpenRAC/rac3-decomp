/* NTSC-U draft (2026-11-14, Claude worker): C of func_L08_003BBD58, the NTSC-U twin of func_L08_003BDE60, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/08_aquatos/L08_003BD8A0.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 */
#include "common.h"

/* NTSC-U counterpart of func_L08_003BDE60 (src/levels/08_aquatos/L08_003BD8A0.c) */
#include "vu0.h"

/* localdecomp:start func_L08_003BBD58 */
extern s32 func_0037E1D8(s32);
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern void func_003BF6A8(void *, f32);
extern s32 func_L01_00460318(void *, void *, u32, s32, s32, s32, s32, s32);

void func_L08_003BBD58(u8 *self, f32 spread, f32 scale) {
    vu0_v4 w;
    vu0_v4 vel;
    vu0_v4 pos;
    f32 ratio;
    s32 i;
    s32 r;

    ratio = *(f32 *)(self + 0x2C) / *(f32 *)(*(u8 **)(self + 0x24) + 0x24);
    func_00388830(&pos, self + 0xD0, ratio * scale);
    vec_add_ab(&pos, self + 0x10, &pos);
    for (i = 0; i < 30; i++) {
        r = func_0037E1D8(0x32);
        qzero(&w);
        func_003BF6A8(&w, spread);
        vec_add_ab(&w, &pos, &w);
        qzero(&vel);
        func_003BF6A8(&vel, 0.00500000035f);
        vel.z += func_0037E250(0.0f, 0.00833333377f);
        func_L01_00460318(&w, &vel, 0x70507080, 0, func_0037E1D8(0x5A) + 0x5A, (s32)(ratio * (f32)(r + 0x82)),
                          (s32)(ratio * (f32)(r + 0xFA)), i < 26);
    }
}
/* localdecomp:end func_L08_003BBD58 */
