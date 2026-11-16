/* PAL near miss (Codex wave 10): near miss: 13 words differ with the file's flags.
 * Worker's note: 13 word differences; check03-check05 identical residual in interpolation index allocation and loop scheduling; NEEDS divs row 'func_L01_003D2A18 2'; best log build/codex/w513/func_L01_003D2A18.check03.log
 */
#include "common.h"
/* localdecomp:start func_L01_003D2A18 */
extern s32 D_001A71A0 __attribute__((section(".data")));
typedef struct { u8 pad[0xF0]; f32 times[4]; s32 values[4]; } S_003D2A18;
void func_L01_003D2A18(void *obj, void *data) {
    extern s32 func_0038CAD0(s32 *);
    extern void func_L01_003D25D8(void *, void *, s32);
    u8 *p = data;
    s32 i;
    S_003D2A18 *state = data;
    if (*(s32 *)(p + 0x38) == 0) {
        if (*(f32 *)(p + 0x30) < *(f32 *)(p + 0xF0)) return;
        if (*(f32 *)(p + 0xFC) < *(f32 *)(p + 0x30)) return;
    } else if (!func_0038CAD0((s32 *)(p + 0x38))) return;
    func_L01_003D25D8(obj, data, D_001A71A0);
    {
        f32 *a = state->times;
        f32 *scan = a + 1;
        f32 t = *(f32 *)(p+0x30);
        for (i = 1; i < 4; i++, scan++) {
            f32 upper = *scan;
            if (t < upper) {
                s32 prev = ((u32)i-1) * 4;
                f32 lower = *(f32 *)((s32)a + prev);
                s32 *b = state->values;
                s32 base = *(s32 *)((s32)b + prev);
                s32 delta = b[(u32)i] - base;
                s32 value = (s32)((f32)delta * ((t-lower)/(upper-lower))) + base;
                *(s32 *)(p+0x38) = (value*5+2)/6;
                break;
            }
        }
    }
}
/* localdecomp:end func_L01_003D2A18 */
