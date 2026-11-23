#include "common.h"

/* NTSC-U counterpart of func_L02_003A3898 (src/levels/shared/L02_003A3898.c): 0.12 -> 0.1 */
/* localdecomp:start func_L02_003A1AB8 */
extern f32 D_L02_001DDD58;
__asm__(".extern D_L02_001DDD58, 4");
extern f32 D_L02_001DDD5C;
__asm__(".extern D_L02_001DDD5C, 4");
extern f32 D_L02_001DDD60;
__asm__(".extern D_L02_001DDD60, 4");
extern f32 func_00388730(void *, void *);

void func_L02_003A1AB8(u8 *obj, void *other, f32 x) {
    f32 s;
    f32 r;
    f32 t;

    s = D_L02_001DDD58 * 0.017453292f;
    *(f32 *)(obj + 0xF0) = *(f32 *)(obj + 0xF0) - x * D_L02_001DDD5C * D_L02_001DDD60;
    r = func_00388730(other, obj + 0xD0) / 0.100000009f;
    if (r < 1.0f) {
        t = s * (func_00388730(other, obj + 0xD0) / 0.100000009f);
    } else {
        t = s;
    }
    *(f32 *)(obj + 0xF0) = *(f32 *)(obj + 0xF0) * (1.0f - D_L02_001DDD60) + t * D_L02_001DDD60;
}
/* localdecomp:end func_L02_003A1AB8 */
