/* PAL near miss (Codex wave 6): near miss: 5 words differ with the file's flags.
 * Worker's note: 5 diff: zero/one return scheduling; eight compiles, branch/result/switch forms do not improve base; best build/codex/w292/func_L01_00511A98.base.log. Fixed flags, no metadata.
 */
#include "common.h"
/* localdecomp:start func_L01_00511A98 */
extern int D_001A71A4[];
s32 func_L01_00511A98(void)
{
    s32 state = D_001A71A4[0];
    if (state == 104) goto two;
    if (state < 105) {
        if (state < 102) goto zero;
        return 1;
    } else {
        if (state != 105) goto zero;
        return 1;
    }
two:
    return 2;
zero:
    return 0;
}
/* localdecomp:end func_L01_00511A98 */
