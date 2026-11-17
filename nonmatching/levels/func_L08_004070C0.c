/* NTSC-U draft (Claude wave K): C of func_L08_00403E80, the NTSC-U twin of func_L08_004070C0, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 29 words differ on NTSC-U with "-O2 -G8 -mno-check-zero-division -mvu0-use-vf0-vf2 @ps2as (no -fopt-stack)" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division") (NTSC-U twin "func_L08_00403E80", whose code is not the PAL one).
 * Worker's note: full decode (particle burst with two counted loops, quad-save prologue), 29 aligned diffs of 138 of which ~22 are the $s save/restore layout: retail saves $s0-$s7/$fp/$ra with `sq` in ascending 16-byte slots ($s0 at 0x40, $ra at 0xD0, frame 0x100) - our gcc ...
 */
#include "common.h"

#include "vu0.h"

/* localdecomp:start func_L08_00403E80 */
extern u8 *D_L08_001E6080[];
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern void func_003BF6A8(void *, f32);
extern void func_L01_00468DC0(void *, void *, s32, f32, s32, s32, s32, s32, s32);
extern void func_L08_004038A8(void *, s32, s32, s32, f32, f32, f32);

void func_L08_00403E80(s32 idx, vu0_v4 *pos, s32 n1, s32 n2, s32 p4, s32 p5, s32 p6, s32 p7, f32 sz1, f32 sz2, s32 extra) {
    u8 *e;
    vu0_v4 base;
    vu0_v4 v10;
    vu0_v4 v20;
    vu0_v4 v30;
    s32 i;

    base = *pos;
    v30 = *pos;
    e = *(u8 **)((u8 *)D_L08_001E6080 + idx * 4 + 0x1A0);
    vec_add_ba(&v30, e + 0x10, &v30);
    if (n1 > 0) {
        i = n1;
        do {
            v10 = v30;
            func_003BF6A8(&v10, 1.0f);
            qzero(&v20);
            v20.z = func_0037E250(0.0f, 0.025000002f);
            func_L01_00468DC0(&v10, &v20, p6, sz1 * func_0037E250(0.2f, 0.5f), p4, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0);
            i--;
        } while (i != 0);
    }
    if (n2 > 0) {
        i = n2;
        do {
            v10 = v30;
            func_003BF6A8(&v10, 0.3f);
            qzero(&v20);
            v20.z = func_0037E250(0.0f, 0.008333334f);
            func_L01_00468DC0(&v10, &v20, p7, sz2 * func_0037E250(1.5f, 2.5f), p5, func_0037E1D8(0xFF) & 0xFF, 0, 0x40, 0);
            i--;
        } while (i != 0);
    }
    func_L08_004038A8(e, extra, extra, 10, 3.0f, 7.0f, 3.0f);
}
/* localdecomp:end func_L08_00403E80 */
