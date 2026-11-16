/* PAL near miss (Codex wave 8): near miss: 5 words differ with the file's flags.
 * Worker's note: 5 diff / 144 words, retained 09.log (same bytes as 01/08): second-loop preheader uses s3 directly rather than v0 then s3 copy. Nine compiles; three loop formulations identical (01/08/09). Variant 03 reproduces retail preheader but swaps s3/s4 throughout (8 ...
 */
#include "common.h"

/* localdecomp:start func_L07_003BF8A8 */
extern f32 D_L07_001E1EC0[];
void func_L07_003BF8A8(void *arg0) {
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DB00(f32, f32);
    extern void func_L07_003BFAE8(void *, f32, f32, s32);
    u8 *self = arg0;
    u8 *state;
    f32 ratio, angle;
    s32 count, i, j, side, total;
    if (!self || self[0x20] == 0xFE || self[0x20] == 0xFD || *(s16 *)(self + 0xAA) != 0x1A9F) return;
    state = *(u8 **)(self + 0x68);
    i = (s32)(*(f32 *)(state + 0x10) / 0.15f);
    ratio = *(f32 *)(state + 0x10) / 0.85f;
    count = i + 1;
    if (ratio > 1.0f) ratio = 1.0f;
    angle = func_0038D160(D_L07_001E1EC0[0] - *(f32 *)(self + 0x10), D_L07_001E1EC0[1] - *(f32 *)(self + 0x14));
    angle = func_0038DB00(angle, *(f32 *)(self + 0xF8));
    if (__builtin_fabsf(angle) < 0.34906584f) {
        for (j = 0; j < count; i--, j++) {
            f32 t = *(f32 *)(state + 0x10) - i * 0.15f;
            func_L07_003BFAE8(self, t, ratio, 0);
            func_L07_003BFAE8(self, t, ratio, 1);
        }
    } else {
        side = angle > 0.0f;
        total = count * 2;
        for (i = 0; i < total; i++) {
            j = total - i - 1;
            if (i < count) func_L07_003BFAE8(self, *(f32 *)(state + 0x10) - i * 0.15f, ratio, !side);
            else func_L07_003BFAE8(self, *(f32 *)(state + 0x10) - j * 0.15f, ratio, side);
        }
    }
}
/* localdecomp:end func_L07_003BF8A8 */
