#include "vu0.h"
#include "common.h"

/* localdecomp:start func_L06_003505D8 */
extern void func_L06_0042EC58(void *, void *, s32, f32, f32);
extern s32 D_L06_001DD318;
__asm__(".extern D_L06_001DD318, 4");
extern s32 D_L06_001DD31C[];
void func_L06_003505D8(s32 a0, u8 *a1) {
    qzero(a1 + 0x400);
    func_L06_0042EC58(*(void **)(a1 + 0x260), a1 + 0x3A0, D_L06_001DD318, 0.03f, 0.3f);
    qzero(a1 + 0x480);
    func_L06_0042EC58(*(void **)(a1 + 0x260), a1 + 0x420, D_L06_001DD31C[0], 0.03f, 0.3f);
}
/* localdecomp:end func_L06_003505D8 */
