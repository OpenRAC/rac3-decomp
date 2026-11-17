#include "common.h"

INCLUDE_ASM("asm/levels", func_L06_0045AFF8);

/* localdecomp:start func_L06_0045B1F8 */
#include "vu0.h"

extern s32 func_L06_0045AFF8(void *out, s32 *path, void *pos);
extern f32 func_0038CEA8(void *v);

void func_L06_0045B1F8(s32 *path, void *pos, s32 *idx, f32 *dist) {
    vu0_v4 near;
    vu0_v4 d;
    s32 i;

    i = func_L06_0045AFF8(&near, path, pos);
    *idx = i;
    if (i == *path - 1) {
        *dist = 0.0f;
        return;
    }
    vec_sub_ab(&d, &near, (u8 *)path + i * 16 + 0x10);
    *dist = func_0038CEA8(&d);
}
/* localdecomp:end func_L06_0045B1F8 */
