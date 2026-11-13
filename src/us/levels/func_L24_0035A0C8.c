#include "common.h"

/* localdecomp:start func_L24_0035A0C8 */
typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} V4_35A0C8;

extern f32 func_00388730(u8 *, V4_35A0C8 *);

void func_L24_0035A0C8(u8 *obj, f32 x) {
    u8 *s = *(u8 **)(obj + 0x68);
    V4_35A0C8 v;
    f32 side;
    f32 *pos = (f32 *)(s + 0x1B0);

    v.x = pos[0];
    v.y = pos[1];
    v.z = pos[2];
    v.w = 0.0f;
    side = func_00388730(obj + 0xE0, &v);
    if (0.0f < side) {
        x = -x;
    }
    *(s16 *)(s + 0x196) = 5;
    *(f32 *)(s + 0x1AC) = x / 5.0f;
}
/* localdecomp:end func_L24_0035A0C8 */
