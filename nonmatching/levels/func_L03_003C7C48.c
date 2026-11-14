/* NTSC-U draft (2026-11-14, Claude worker): C of func_L03_003C5DB0, the NTSC-U twin of func_L03_003C7C48, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 8 words differ with its file's flags.
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L03_003C7C48 (src/levels/shared/L03_003C7C48.c) */
/* localdecomp:start func_L03_003C5DB0 */
extern vu0_v4 D_L03_001E24C0;
extern void func_00388830(void *, void *, f32);
extern void func_00389158(void *, void *, void *, f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern f32 func_L01_00440918(f32, f32);
extern u8 *func_L01_00467DA8(f32, void *, s32, f32, f32, u32, s32, s32, void *, s32);

void func_L03_003C5DB0(f32 *pos, s32 count) {
    f32 v0[4] __attribute__((aligned(16)));
    f32 v10[4] __attribute__((aligned(16)));
    f32 v20[4] __attribute__((aligned(16)));
    f32 v30[4] __attribute__((aligned(16)));
    f32 v40[4] __attribute__((aligned(16)));
    s32 dir;
    s32 i;
    f32 life;
    f32 ang;
    f32 sp1;
    f32 z;
    u8 *p;

    vec_sub_ab(v20, &D_L03_001E24C0, pos);
    func_00388830(v40, v20, 0.3f);
    v20[2] = 0.0f;
    v30[0] = 0.0f;
    v30[1] = 0.0f;
    v30[2] = 1.0f;
    v30[3] = 1.0f;
    if (count > 0) {
        z = v20[2];
        for (i = 0; i < count; i++) {
            life = func_0037E250(0.5f, 2.0f);
            dir = func_0037E1D8(2);
            if (dir == 0) {
                dir = dir - 1;
            }
            ang = func_0037E250(-1.0471976f, 1.0471976f);
            func_00389158(v0, v20, v30, ang);
            sp1 = func_0037E250(0.05f, 3.0f) * 0.016666668f;
            func_00388830(v0, v0, sp1);
            v0[2] = func_0037E250(1.0f, 5.0f) * 0.016666668f;
            vec_add_ba(v10, pos, v40);
            pos[0] += func_L01_00440918(z, 0.15f);
            pos[1] += func_L01_00440918(z, 0.15f);
            pos[2] += func_L01_00440918(z, 0.15f);
            p = func_L01_00467DA8(life * 0.1f, v10, 0x3C, life, 0.002f, 0xDD10FFFF, 0, dir, v0, 0);
            if (p != 0) {
                p[9] = 0x74;
            }
            p = func_L01_00467DA8(life * 0.07f, v10, 0x3C, life * 0.7f, 0.002f, 0xDD10FFFF, 1, -dir, v0, 0);
            if (p != 0) {
                p[9] = 0x74;
            }
        }
    }
}
/* localdecomp:end func_L03_003C5DB0 */
