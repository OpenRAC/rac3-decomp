#include "common.h"

/* NTSC-U counterpart of func_L22_003BCF38 (src/levels/22_mylon/L22_003BCF38.c): 25 -> 30 */
/* localdecomp:start func_L22_003BB628 */
extern f32 func_0038D0B0(f32);
extern void func_0038AE20(s32, s32, s32, s32);
extern void func_003A9440(s32, unsigned long);
void func_L22_003BB628(u8 *self) {
    u8 *st = *(u8 **)(self + 0x68);
    s32 t;
    f32 s;
    if (*(s32 *)(st + 0x178) > 0) {
        t = *(s32 *)(st + 0x170) + 1;
        *(s32 *)(st + 0x170) = t;
        if (t >= 0x1E) {
            *(s32 *)(st + 0x178) = -1;
        }
    } else {
        t = *(s32 *)(st + 0x170) - 1;
        *(s32 *)(st + 0x170) = t;
        if (t <= 0) {
            *(s32 *)(st + 0x178) = 1;
        }
    }
    s = func_0038D0B0((f32)*(s32 *)(st + 0x170) * 3.14159274f / 60.0f);
    func_0038AE20(0x7F, 0, 0, (s32)(s * 0.85000002f * 16.0f));
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L22_003BB628 */
