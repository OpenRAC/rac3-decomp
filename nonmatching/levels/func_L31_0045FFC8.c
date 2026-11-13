/* near miss (level 31: 1 diff, the jr delay slot) */
#include "common.h"

/* localdecomp:start func_L31_0045FFC8 */
extern void func_L01_00517918(s32 a0);
extern void func_L01_00493038(void);
extern void func_003A2750(s32 a0);

void func_L31_0045FFC8(void) {
    func_L01_00517918(0x10);
    func_L01_00517918(0x11);
    func_L01_00517918(0x14);
    func_L01_00493038();
    func_003A2750(1);
}
/* localdecomp:end func_L31_0045FFC8 */
