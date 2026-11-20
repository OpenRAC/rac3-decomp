/* functional: high. Read block by block against the PAL asm (both directions, index/fraction handling, limit clamping). Retail takes (path, direction, f12 initialLength, f13 position, f14 limit); the owning file declares it f32(int), so a private name with an asm label is used. The caller func_L01_00477ED0 passes only the path and should be fixed to pass the rest. */
#include "common.h"
/* Retail consumes a1 and f12-f14; the owner's float(int) declaration must be corrected. */
/* The unit declares this as float(int); retail takes more arguments, so it is defined under a private name bound to the same symbol. */
extern f32 L01_00477F20_impl(int address, s32 direction, f32 initialLength, f32 position, f32 limit) __asm__("func_L01_00477F20");
f32 L01_00477F20_impl(int address, s32 direction, f32 initialLength, f32 position, f32 limit) {
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
