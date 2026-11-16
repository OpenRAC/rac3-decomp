/* PAL near miss (Claude wave S2/pal): flags: byte-exact only with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (its file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as").
 * Worker's note: byte-exact (vec_sub_ab, func_0038CEA8, func_0038CF68(&v,&v,thr), 2x func_0038CE68; thr/scales read as D_001DExxx_sda f32 with .extern ..,4) only with -mvu0-use-vf0-vf2, which the file line lacks; without it vu0.h asm fails (vf17 spilled); needs #include ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_003ABF48 */
extern f32 D_001DE418_sda;
__asm__(".extern D_001DE418_sda, 4");
extern f32 D_001DE41C_sda;
__asm__(".extern D_001DE41C_sda, 4");
extern f32 D_001DE420_sda;
__asm__(".extern D_001DE420_sda, 4");
extern f32 func_0038CEA8(Vec4 *);
extern f32 func_0038CE68(Vec4 *, u8 *);

void func_L01_003ABF48(u8 *obj, s32 unused, Vec4 *a2, f32 *out1, f32 *out2) {
    Vec4 q = *a2;
    Vec4 v;
    f32 t;

    vec_sub_ab(&v, obj + 0x10, &q);
    t = func_0038CEA8(&v);
    if (D_001DE418_sda < t) {
        func_0038CF68((u8 *)&v, &v, D_001DE418_sda);
    }
    *out1 = func_0038CE68(&v, obj + 0xD0) * D_001DE41C_sda;
    *out2 = func_0038CE68(&v, obj + 0xC0) * D_001DE420_sda;
}
/* localdecomp:end func_L01_003ABF48 */
