/* NTSC-U draft (2026-11-14, Claude worker): C of func_L02_003261F0, the NTSC-U twin of func_L02_00326A80, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2" (src/levels/shared/L02_00326430.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 */
#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of func_L02_00326430 (src/levels/shared/L02_00326430.c) */
/* localdecomp:start func_L02_003261F0 */
__asm__(".extern D_L02_001DC964, 4");
extern f32 D_L02_001DC964;
__asm__(".extern D_L02_001DC968, 4");
extern f32 D_L02_001DC968;
__asm__(".extern D_L02_001DC96C, 4");
extern f32 D_L02_001DC96C;
__asm__(".extern D_L02_001DC970, 4");
extern f32 D_L02_001DC970;
__asm__(".extern D_L02_001DC974, 4");
extern s32 D_L02_001DC974;
__asm__(".extern D_L02_001DC978, 4");
extern s32 D_L02_001DC978;
__asm__(".extern D_L02_001DC97C, 4");
extern s32 D_L02_001DC97C;
__asm__(".extern D_L02_001DC980, 4");
extern f32 D_L02_001DC980;
__asm__(".extern D_L02_001DC984, 4");
extern f32 D_L02_001DC984;
extern f32 D_001A4CC8;
extern void func_003BDA38(void *, s32, void *);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_00440A88(void *, f32, f32);
extern s32 func_0037E1D8(s32);
extern void func_L01_00468DC0(void *, void *, s32, s32, s32, s32, s32, s32, f32);

void func_L02_003261F0(u8 *a0) {
    vu0_v4 p;
    vu0_v4 v;
    vu0_v4 w;
    s32 i;
    f32 k;

    if (a0[0x20] == 1) {
        func_003886E8(&p, a0, 0.0009765625f);
    } else {
        func_003BDA38(a0, 0, &p);
        if (p.z < D_001A4CC8) {
            return;
        }
    }
    k = 0.0166666675f;
    func_L01_00440A88(&v, D_L02_001DC964 * k, D_L02_001DC968 * k);
    func_L01_00468DC0(&p, &v, D_L02_001DC978, D_L02_001DC974, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0, D_L02_001DC980);
    for (i = 0; i < 3; i++) {
        func_L01_00440A88(&w, D_L02_001DC96C * k, D_L02_001DC970 * k);
        vec_add_ab(&v, &v, &w);
        func_L01_00468DC0(&p, &v, D_L02_001DC97C, D_L02_001DC974, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0, D_L02_001DC984);
    }
}
/* localdecomp:end func_L02_003261F0 */
