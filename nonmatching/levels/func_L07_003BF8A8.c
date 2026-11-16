/* PAL level-07 reconstruction from the owned retail ELF (Wave2 P04).
 * Near miss: stock tools/check.py reports 20 diff with the owning-file flags.
 * Drawing loops; float register allocation, loop-counter setup and call argument scheduling still differ.
 * Checked with the owning file's normal prelude/earlier declarations; not linked.
 */
#include "common.h"
extern f32 D_L07_001E1EC0[];
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DB00(f32, f32);
extern void func_L07_003BFAE8(void *, s32, f32, f32);
void func_L07_003BF8A8(void *arg0) {
    u8 *self = arg0;
    u8 *p;
    s32 n, count, i, j, side, total;
    f32 step;
    f32 opacity, angle, time;
    if (!self || self[0x20] == 0xFE || self[0x20] == 0xFD || *(s16 *)(self + 0xAA) != 0x1A9F) return;
    p = *(u8 **)(self + 0x68);
    step = 0.15f;
    n = *(f32 *)(p + 0x10) / step;
    opacity = *(f32 *)(p + 0x10) / 0.85f;
    count = n + 1;
    if (opacity > 1.0f) opacity = 1.0f;
    angle = func_0038D160(D_L07_001E1EC0[0] - *(f32 *)(self + 0x10), D_L07_001E1EC0[1] - *(f32 *)(self + 0x14));
    angle = func_0038DB00(angle, *(f32 *)(self + 0xF8));
    if (__builtin_fabsf(angle) < 0.34906584f) {
        if (count > 0) for (j = n + 1; j != 0; j--, n--) {
            time = *(f32 *)(p + 0x10) - (f32)n * step;
            func_L07_003BFAE8(self, 0, time, opacity);
            func_L07_003BFAE8(self, 1, time, opacity);
        }
    } else {
        side = angle > 0.0f;
        total = count * 2;
        for (i = 0, j = total - 1; i < total; i++, j--) {
            if (i < count) {
                func_L07_003BFAE8(self, !side, *(f32 *)(p + 0x10) - (f32)i * step, opacity);
            } else {
                func_L07_003BFAE8(self, side, *(f32 *)(p + 0x10) - (f32)j * step, opacity);
            }
        }
    }
}
