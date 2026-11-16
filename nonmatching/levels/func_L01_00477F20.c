/* PAL near miss (Codex wave 6): near miss: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details).
 * Worker's note: Context compile blocked (01/02.log), no byte diff: existing float func_L01_00477F20(int) conflicts with retail a0,a1,f12,f13,f14. Correct target declaration and audit earlier func_L01_00477ED0 caller; no casts/alias workaround
 */
#include "common.h"
/* localdecomp:start func_L01_00477F20 */
/* Retail consumes a1 and f12-f14; the owner's float(int) declaration must be corrected. */
f32 func_L01_00477F20(int address, s32 direction, f32 initialLength, f32 position, f32 limit) {
    Tab_00477BC0 *path = (Tab_00477BC0 *)address;
    f32 total = 0.0f;
    f32 first = initialLength;
    f32 fraction;
    s32 index;
    if (direction > 0) {
        if (position < 0.0f) {
            if (first > 0.0f) {
                fraction = -position;
                total += first * fraction;
                if (total >= limit) return limit;
            }
            index = (s32)position;
        } else {
            index = (s32)position;
            if (*(f32 *)((u8 *)path + index * 16 + 0x1C) > 0.0f) {
                fraction = position - (f32)index;
                if (fraction >= 1.0f) { fraction -= 1.0f; index++; }
                fraction = 1.0f - fraction;
                total += *(f32 *)((u8 *)path + index * 16 + 0x1C) * fraction;
                if (total >= limit) return limit;
            }
        }
        for (index++; index < path->n; index++) {
            if (*(f32 *)((u8 *)path + index * 16 + 0x1C) > 0.0f) {
                total += *(f32 *)((u8 *)path + index * 16 + 0x1C);
                if (total >= limit) return limit;
            }
        }
    } else {
        if (position < 0.0f) {
            if (first > 0.0f) {
                fraction = -position;
                total += first * (1.0f - fraction);
                if (total >= limit) return limit;
            }
            return total;
        }
        index = (s32)position;
        if (*(f32 *)((u8 *)path + index * 16 + 0x1C) > 0.0f) {
            fraction = position - (f32)index;
            if (fraction >= 1.0f) { fraction -= 1.0f; index++; }
            total += *(f32 *)((u8 *)path + index * 16 + 0x1C) * fraction;
            if (total >= limit) return limit;
        }
        for (index--; index >= 0; index--) {
            if (*(f32 *)((u8 *)path + index * 16 + 0x1C) > 0.0f) {
                total += *(f32 *)((u8 *)path + index * 16 + 0x1C);
                if (total >= limit) return limit;
            }
        }
        if (first > 0.0f) {
            total += first;
            if (total >= limit) return limit;
        }
    }
    return total;
}
/* localdecomp:end func_L01_00477F20 */
