/* PAL near miss (Codex wave 4): held at landing: the C of its NTSC-U twin func_L01_004B7588, which matches NTSC-U, renamed to PAL names: it matches PAL at level 01 but not at level 03 (1 word differs), so it cannot be the one source of every place.
 */
#include "common.h"

/* localdecomp:start func_L01_004BB120 */
/* Ported from rac4-decomp/src/core/0012C3A8.c. */
s32 func_L01_004BB120(s32 value)
{
    extern s32 func_L01_004BAE90(s32);
    return func_L01_004BAE90(value);
}
/* localdecomp:end func_L01_004BB120 */
