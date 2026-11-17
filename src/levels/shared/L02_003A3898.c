#include "common.h"

typedef struct Obj_003A2C98 {
    u8 pad00[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0xC];
    f32 f24;
    f32 f28;
    f32 f2C;
    f32 f30;
    u8 pad34[0x20];
    f32 f54;
    f32 f58;
    u8 pad5C[4];
    f32 f60[1];
} Obj_003A2C98;

/* localdecomp:start func_L02_003A3898 */
extern f32 D_L02_001DDD18;
__asm__(".extern D_L02_001DDD18, 4");
extern f32 D_L02_001DDD1C;
__asm__(".extern D_L02_001DDD1C, 4");
extern f32 D_L02_001DDD20;
__asm__(".extern D_L02_001DDD20, 4");
extern f32 func_0038CE68(void *, void *);

void func_L02_003A3898(u8 *obj, void *other, f32 x) {
    f32 s;
    f32 r;
    f32 t;

    s = D_L02_001DDD18 * 0.017453292f;
    *(f32 *)(obj + 0xF0) = *(f32 *)(obj + 0xF0) - x * D_L02_001DDD1C * D_L02_001DDD20;
    r = func_0038CE68(other, obj + 0xD0) / 0.120000005f;
    if (r < 1.0f) {
        t = s * (func_0038CE68(other, obj + 0xD0) / 0.120000005f);
    } else {
        t = s;
    }
    *(f32 *)(obj + 0xF0) = *(f32 *)(obj + 0xF0) * (1.0f - D_L02_001DDD20) + t * D_L02_001DDD20;
}
/* localdecomp:end func_L02_003A3898 */
