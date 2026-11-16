/* PAL near miss (Codex wave 8): near miss: 24 words differ with the file's flags.
 * Worker's note: 24 diff: repeated identical wrong tail-call convergence; best try4.log; complete VU sequence with memory operands. No all-place proof.
 */
#include "common.h"
/* localdecomp:start func_L01_00511320 */
void func_L01_00511320(Vec4 *out, Vec4 *in) {
    extern f32 func_0038CE68(Vec4 *, Vec4 *);
    extern void func_0038CE20(Vec4 *, Vec4 *, f32);
    extern void func_0038CF68(void *, void *, f32);
    Vec4 tmp;
    u8 *base=(u8 *)&D_001A4BE0;
    switch (base[0x25F4]) {
    case 0:
        out->q=in->q;
        out->f[2]=0.0f;
        return;
    case 1:
        func_0038CF68(&tmp,base+0x2C0,1.0f);
        func_0038CE20(&tmp,&tmp,func_0038CE68(&tmp,in));
        break;
    case 2:
        func_0038CE20(&tmp,(Vec4 *)(base+0x2E0),func_0038CE68((Vec4 *)(base+0x2E0),in));
        break;
    default:
        return;
    }
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*out) : "m"(*in), "m"(tmp) : "vf1", "vf2");
}
/* localdecomp:end func_L01_00511320 */
