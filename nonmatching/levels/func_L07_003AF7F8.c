/* PAL near miss (Codex wave 10): near miss: 2 words differ with the file's flags.
 * Worker's note: 2 word diffs at +0xE0/+0xE4 (f12 move and a1 address order); c01.log and c03.log. Raw pointer, integer address, named state fields compile to same wrong words; original simple candidate retained.
 */
#include "common.h"
/* localdecomp:start func_L07_003AF7F8 */
typedef int Q_003AF7F8 __attribute__((mode(TI)));
void func_L07_003AF7F8(u8 *self) {
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DB00(f32, f32);
    extern f32 func_0038CF38(void *, void *);
    extern void func_L01_00448728(void *, void *, s32, f32, f32, f32, f32);
    Q_003AF7F8 position;
    u8 *state = *(u8 **)(self + 0x68);
    f32 yaw, pitch;
    position = *(Q_003AF7F8 *)(state + 0x30);
    ((f32 *)&position)[2] += -0.75f;
    yaw = func_0038DB00(func_0038D160(((f32 *)&position)[0] - *(f32 *)(self + 0x10),
                                  ((f32 *)&position)[1] - *(f32 *)(self + 0x14)), 1.57079637f);
    pitch = func_0038D160(func_0038CF38(self + 0x10, &position),
                         ((f32 *)&position)[2] - *(f32 *)(self + 0x18));
    func_L01_00448728(self + 0xF8, state + 0xDC, 0, yaw, 0.000720000069f, 0.0144000007f, 0.0f);
    func_L01_00448728(self + 0xF0, state + 0xD8, 0, pitch, 0.000720000069f, 0.0144000007f, 0.0f);
}
/* localdecomp:end func_L07_003AF7F8 */
