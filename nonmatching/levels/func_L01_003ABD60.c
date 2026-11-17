#include "common.h"

typedef struct { s32 count; u8 pad[0x18]; f32 length; } Path_003ABD60;

f32 func_L01_003ABD60(u8 *object, Path_003ABD60 *path, s32 *index, f32 position, f32 distance) {
    f32 zero = 0.0f;
    f32 boundary = 0.0f;
    f32 step;
    f32 remaining = 1.0f;
    do {
        if (position < boundary) {
            *index = -1;
            step = (distance / *(f32 *)(object + 0xD6C)) * remaining;
            if (position + step >= zero) {
                *index = 0;
                remaining -= ((zero - position) / step) * remaining;
                position = zero;
            } else {
                position += step;
                remaining = 0.0f;
            }
        } else {
            s32 seg = (s32)position;
            f32 offset;
            *index = seg;
            step = (distance / ((Path_003ABD60 *)((s32)path + (seg << 4)))->length) * remaining;
            offset = position + step - (f32)seg;
            if (offset >= 1.0f && seg < path->count - 1) {
                f32 ratio = (step - (offset - 1.0f)) / step;
                position += step * ratio;
                remaining -= ratio * remaining;
                *index = (s32)position;
            } else {
                position += step;
                remaining = 0.0f;
            }
        }
    } while (0.0f < remaining);
    return position;
}
