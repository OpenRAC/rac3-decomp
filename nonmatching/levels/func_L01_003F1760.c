/* PAL near miss (Codex wave 4): held at landing: the C of its NTSC-U twin func_L01_003EF820, which matches NTSC-U, renamed to PAL names: it matches PAL at level 01 but not at level 03 (1 word differs), so it cannot be the one source of every place.
 */
#include "common.h"

/* localdecomp:start func_L01_003F1760 */
void func_L01_003F1760(void) {
    extern void func_00384CC8();
    func_00384CC8(1);
}
/* localdecomp:end func_L01_003F1760 */
