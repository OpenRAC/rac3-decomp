#include "common.h"

/* localdecomp:start func_L07_003BCE80 */
extern void func_L07_003BCA60(void *, s32);

/* Sets a 0x3C timer in the object's vars, then calls func_L07_003BCA60 with 0xF when a flag byte is
 * set, else with 0xC. */
void func_L07_003BCE80(void *object) {
    u8 *vars = *(u8 **)((u8 *)object + 0x68);
    *(s16 *)(vars + 0x4F8) = 0x3C;
    if (vars[0x4FA] != 0) {
        func_L07_003BCA60(object, 0xF);
        return;
    }
    func_L07_003BCA60(object, 0xC);
}
/* localdecomp:end func_L07_003BCE80 */
