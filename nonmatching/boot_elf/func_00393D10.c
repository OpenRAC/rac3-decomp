/* PAL near miss (Codex wave 10): 67 differences (tools/check.py) with 392DF8.c's line (2026-11-22); MATCH with --as ps2as.
 * The difference is one nop SN's assembler adds after mfc1 $a1, $f1 (retail reads $a1 next); see its README row for the recipe.
 * Worker's note: 67 raw word diffs: single extra assembler nop after mfc1 shifts tail; three clamp forms unchanged. Metadata tested divs 2 2.
 */
#include "common.h"
/* localdecomp:start func_00393D10 */
#include "vu0.h"
typedef struct { u8 p0[8]; s32 f8; s32 *fC; u8 p10[0x5C]; s32 f6C; u8 b70[4]; s32 f74; s32 f78; s32 f7C; } S_00393D10;
void func_00393D10(S_00393D10 *p) {
    extern s32 func_003967B0();
    u8 *b = p->b70;
    s32 n, step;
    if (p->fC != 0) {
        s32 initial = *p->fC;
        if (initial < 0) initial = 0;
        p->f78 = initial;
        if (p->f8 < initial) p->f78 = p->f8;
    }
    if (p->f74 != p->f78) {
        p->f7C = 150;
        if (p->f6C >= 24) {
            n = __builtin_abs(p->f74 - p->f78);
            if (n != 0) {
                step = (s32)(sqrt_asm((f32)n / 25.0f) * 5.0f);
                { s32 quarter = n / 4; if (quarter > step) step = quarter; }
                if (step > 121) step = 121;
                else if (step < 1) step = 1;
                b[3] += step;
                if (b[3] >= 3) {
                    u32 accum = b[3];
                    s32 current = p->f74;
                    step = accum >> 1;
                    if (p->f78 < current) p->f74 = current - step;
                    else p->f74 = current + step;
                    b[3] -= step * 2;
                }
            }
        }
    }
    if (p->f7C >= 4) {
        if (b[0] < 7) b[0]++;
        else if (b[1] < 7) b[1]++;
    } else {
        if (b[1] != 0 || b[0] != 0) p->f6C = 1;
        if (b[1] != 0) b[1]--;
        else if (b[0] != 0) b[0]--;
    }
    func_003967B0((u8 *)p + 0x40);
}
/* localdecomp:end func_00393D10 */
