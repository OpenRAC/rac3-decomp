/* PAL near miss (Codex wave 4): held at landing: the C of its NTSC-U twin func_L01_0047BB78, which matches NTSC-U, renamed to PAL names: it matches PAL at level 01 but not at level 04 (1 word differs), so it cannot be the one source of every place.
 */
#include "common.h"

/* localdecomp:start func_L01_0047F3D8 */
void func_L01_0047F3D8(void) {
    extern s32 func_L01_00487EB0(void);
    func_L01_00517748(func_L01_00487EB0());
}
/* localdecomp:end func_L01_0047F3D8 */
