/* PAL near miss (Codex wave 6): near miss: 46 words differ with the file's flags.
 * Worker's note: 45 diff; w263/func_L16_00345E98.try1.log; retail +004/+008 keeps cvt.w.s/cvt.s.w in FPU, plain C emits mfc1/mtc1; ordinary EE asm prohibited
 */
#include "common.h"
/* localdecomp:start func_L16_00345E98 */
extern f32 D_L16_00278200[];
f32 func_L16_00345E98(s32 path, f32 position, f32 distance, f32 unused) {
    f32 fraction=position-(s32)position;
    s32 index=(s32)position;
    while (distance>0.0f) {
        f32 length=D_L16_00278200[index];
        f32 step=distance/length;
        if (fraction<step) {
            distance-=fraction*length;
            index--;
            if (index<0) index=*(s32 *)path-1;
            fraction=1.0f;
            position=(f32)index;
        } else {
            position=(f32)index+(fraction-step);
            distance=0.0f;
        }
    }
    return position;
}
/* localdecomp:end func_L16_00345E98 */
