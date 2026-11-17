#include "common.h"

/* localdecomp:start func_L24_0035B1F8 */
typedef struct { f32 x, y, z, w; } V_0035B1F8;
f32 func_0038CE68(void *, void *);

void func_L24_0035B1F8(void *arg0, f32 f) {
    u8 *p = *(u8 **)((u8 *)arg0 + 0x68);
    f32 *s = (f32 *)(p + 0x1B0);
    V_0035B1F8 v;
    f32 d;

    v.x = s[0];
    v.y = s[1];
    v.z = s[2];
    v.w = 0.0f;
    if (func_0038CE68((u8 *)arg0 + 0xE0, &v) > 0.0f) {
        f = -f;
    }
    d = 4.0f;
    *(s16 *)(p + 0x196) = 4;
    *(f32 *)(p + 0x1AC) = f / d;
}
/* localdecomp:end func_L24_0035B1F8 */
