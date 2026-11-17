/* NTSC-U draft (2026-11-14, Claude worker): C of func_L05_003C8CC8, the NTSC-U twin of func_L05_003CAE70, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L05_003CA628.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L05_003CAE70 (src/levels/shared/L05_003CA628.c) */
/* localdecomp:start func_L05_003C8CC8 */
#include "vu0.h"

extern u8 D_L05_001E2780[];
extern f32 func_00388A28(f32, f32);
extern f32 func_0037E250(f32, f32);
extern f32 func_L01_00440918(f32, f32);
extern f32 func_00389380(f32, f32);
extern void func_0037E4B8(void *, f32, f32, f32);
extern u8 *func_L01_00466F98(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32, f32);

void func_L05_003C8CC8(f32 *a0) {
    f32 d[4] __attribute__((aligned(16)));
    f32 vel[4] __attribute__((aligned(16)));
    f32 pos[4] __attribute__((aligned(16)));
    f32 angle;
    f32 r;
    f32 p;
    f32 t;
    s32 n;
    s32 i;
    f32 size;

    vec_sub_ab(d, D_L05_001E2780, a0);
    angle = func_00388A28(d[0], d[1]);
    for (i = 0; i < 15; i++) {
        r = func_0037E250(0.5f, 1.0f);
        n = func_L01_00440918(1.0f, 2.0f);
        size = func_0037E250(0.05f, 0.2f) * 210000.0f;
        p = func_0037E250(0.0f, 1.3962634f);
        t = func_00389380(angle, func_L01_00440918(0.0f, 1.3962634f));
        func_0037E4B8(vel, 0.016666668f * r, t, p);
        pos[0] = a0[0] + func_L01_00440918(0.0f, 0.1f);
        pos[1] = a0[1] + func_L01_00440918(0.0f, 0.1f);
        pos[2] = a0[2] + func_L01_00440918(0.0f, 0.1f);
        func_L01_00466F98(pos, vel, 30, 127, 0x7F7F7F, n, func_0037E250(0.05f, 0.2f) * 210000.0f, 500.0f, 1.0f, 0.0f, 0.0f);
    }
}
/* localdecomp:end func_L05_003C8CC8 */
