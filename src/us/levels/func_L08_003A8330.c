#include "common.h"

/* localdecomp:start func_L08_003A8330 */
typedef int u128_t __attribute__((mode(TI)));

typedef struct V_003A8330 {
    f32 x, z, y, w;
} __attribute__((aligned(16))) V_003A8330;

extern s32 D_L08_001DE2F0;
extern s32 func_00388398(void *);

void func_L08_003A8330(u8 *o) {
    u8 *p;
    V_003A8330 c;
    f32 t;

    p = *(u8 **)(o + 0x68);
    if (p != 0) {
        *(u128_t *)&c = 0;
        c.x = 128.0f;
        c.z = 128.0f;
        c.y = 128.0f;
        c.w = 255.0f;
        func_00388398(p + 0x10);
        t = (f32)*(s32 *)(p + 0x10) / (f32)D_L08_001DE2F0;
        *(s32 *)(o + 0x78) = ((s32)((c.y - 64.0f) * t + 64.0f) << 16) | 0xFF000000 | ((s32)((c.z - 64.0f) * t + 64.0f) << 8) | (s32)((c.x - 255.0f) * t + 255.0f);
    }
}
/* localdecomp:end func_L08_003A8330 */
