#include "common.h"

/* localdecomp:start func_L09_003E75A0 */
extern void func_L09_0045B510(s32, s32, s32);

/* Stores value (or 0x96 when value is -1) at offset 0x70 of the moby's vars, then calls
 * func_L09_0045B510 on it with 2 and -1. */
void func_L09_003E75A0(void *object, s32 value) {
    void *vars = *(void **)((u8 *)object + 0x68);
    if (value != -1) {
        *(s32 *)((u8 *)vars + 0x70) = value;
    } else {
        *(s32 *)((u8 *)vars + 0x70) = 0x96;
    }
    func_L09_0045B510((s32)object, 2, -1);
}
/* localdecomp:end func_L09_003E75A0 */
