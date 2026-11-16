/* PAL near miss (Codex wave 6): near miss: 24 words differ with the file's flags.
 * Worker's note: 24 diff: call-argument materialization/store scheduling. build/codex/w306/03-wrapper.log; three parameter-order forms reproduce same wrong bytes; retained first full PAL draft.
 */
#include "common.h"
/* localdecomp:start func_L01_0031C100 */
void func_L01_0031C100(void *arg0) {
    extern void func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32,
        f32, f32, f32, f32,
        s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
    func_L01_003303B8(arg0, 0, 5, 5, 5, 5, 10, 0,
        0.3f, 0.0f, 0.0f, 0.0f,
        0, 0, 0, 0, 0, 0, 0x10000, 0, 0x388EF7, 0x63F7,
        0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
}
/* localdecomp:end func_L01_0031C100 */
