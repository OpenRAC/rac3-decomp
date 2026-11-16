/* PAL near miss (Claude wave S2/pal): near miss: 2 words differ with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 * Worker's note: 11 diff with -mvu0-use-vf0-vf2 (file line lacks it, so it cannot land anyway): i = func_L06_0045AFF8(&c, line, pos); *index = i; i == *line - 1 -> *dist = 0 else vec_sub_ab(&d, &c, line+i*16+0x10); *dist = func_0038CEA8(&d); only the final sqc2 differs: it ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L06_0045B1F8 */
extern s32 func_L06_0045AFF8(void *out, void *line, void *pos);
extern f32 func_0038CEA8(void *);

void func_L06_0045B1F8(s32 *line, void *pos, s32 *index, f32 *dist) {
    vu0_v4 c;
    vu0_v4 d;
    s32 i;

    i = func_L06_0045AFF8(&c, line, pos);
    *index = i;
    if (i == *line - 1) {
        *dist = 0.0f;
    } else {
        vec_sub_ab(&d, &c, (u8 *)line + i * 16 + 0x10);
        *dist = func_0038CEA8(&d);
    }
}
/* localdecomp:end func_L06_0045B1F8 */
