#include "common.h"

typedef struct {
    f32 current;
    f32 delta;
    f32 target;
} Angle_L07_003E1980;

typedef struct {
    u8 pad0[0x18];
    f32 value;
    u8 pad1[4];
    u8 initialized;
    u8 pad2[0x47];
    Angle_L07_003E1980 *angle;
} Object_L07_003E1980;

/* localdecomp:start func_L07_003E1980 */
extern f32 func_L07_00440EE8(void);
extern f32 func_L07_00440E30(f32, f32);
extern f32 func_L07_0040D7D8(f32, f32);
extern f32 func_L07_0040CCF0(f32);

void func_L07_003E1980(Object_L07_003E1980 *object) {
    Angle_L07_003E1980 *angle = object->angle;
    f32 value;
    if (object->initialized == 0) {
        ((s32 *)angle)[1] = 0;
        angle->current = func_L07_00440EE8();
        angle->target = func_L07_00440E30(0.0349065885f, 0.069813177f);
        object->initialized = 1;
    }
    object->value = object->value - angle->delta;
    value = func_L07_0040D7D8(angle->current, angle->target);
    angle->current = value;
    angle->delta = func_L07_0040CCF0(value) * 0.2f;
    object->value = object->value + angle->delta;
}
/* localdecomp:end func_L07_003E1980 */
