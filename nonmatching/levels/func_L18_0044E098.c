/* PAL near miss (Claude wave S2/pal): near miss: 2 words differ with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 * Study aid: it uses inline asm for EE instructions (lui mtc1 nop qmfc2.ni), which matched C may not (nonmatching/README.md); plain C is still needed.
 * Worker's note: 2 diff: whole-function VU0 asm body (vector-library sphere gap: /a-b/ via vsqrt, 2^-10 scale, - (a.w+b.w)) matches every COP2 word, but retail has mtc1 $at,$f0 in the jr delay slot and cc1 leaves a nop after an asm; handwritten vector-library function: ...
 */
#include "common.h"

/* localdecomp:start func_L18_0044E098 */
f32 func_L18_0044E098(void) {
    __asm__ __volatile__(
        "lqc2 $vf1, 0($4)\n"
        "vaddw.xyz $vf3, $vf0, $vf0w\n"
        "lqc2 $vf2, 0($5)\n"
        "nop\n"
        "vsub.xyz $vf4, $vf1, $vf2\n"
        "nop\n"
        "vmul.xyz $vf4, $vf4, $vf4\n"
        "vadday.x ACC, $vf4, $vf4y\n"
        "vmaddz.x $vf4, $vf3, $vf4z\n"
        "vsqrt Q, $vf4x\n"
        "vadd.w $vf1, $vf1, $vf2\n"
        "lui $at, 0x3A80\n"
        "qmtc2.ni $at, $vf3\n"
        "vmulw.x $vf1, $vf3, $vf1w\n"
        "vwaitq\n"
        "vmulq.x $vf3, $vf3, Q\n"
        "vsub.x $vf1, $vf3, $vf1\n"
        "qmfc2.ni $at, $vf1\n"
        "mtc1 $at, $f0\n"
    );
}
/* localdecomp:end func_L18_0044E098 */
