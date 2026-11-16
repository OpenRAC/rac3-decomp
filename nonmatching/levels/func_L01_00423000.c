/* NTSC-U draft (Codex wave 4): C of func_L01_00420340, the NTSC-U twin of func_L01_00423000 (same code),
 * with NTSC-U names and addresses. Held at landing: it matches as a candidate, but the NTSC-U block alone does not check MATCH (an aliased tail call), so it stayed assembly.
 */
#include "common.h"

/* localdecomp:start func_L01_00420340 */
s32 func_L01_00420340(s32 value)
{
    extern s32 func_L01_003FC858(s32);
    return func_L01_003FC858(value);
}
/* localdecomp:end func_L01_00420340 */
