#include "common.h"
#include "vu0.h"

/* NTSC-U counterpart of the PAL function at the same position (L01 shared, @ps2as) */
/* localdecomp:start func_L01_002F9A40 */
extern void func_00388398(void *);

void func_L01_002F9A40(u8 *obj) {
    u8 *sub = *(u8 **)(obj + 0x68);
    vu0_v4 v;
    f32 t;
    s32 x;
    s32 y;
    s32 z;

    *(vu0_q *)&v = 0;
    v.x = 128.0f;
    v.y = 128.0f;
    v.z = 128.0f;
    v.w = 255.0f;
    func_00388398(sub + 0x10);
    t = (f32) * (s32 *)(sub + 0x10) / 30.0f;
    x = (v.x - 255.0f) * t + 255.0f;
    y = (v.y - 64.0f) * t + 64.0f;
    z = (v.z - 64.0f) * t + 64.0f;
    *(s32 *)(obj + 0x78) = ((((z << 16) | 0xFF000000) | (y << 8)) | x);
}
/* localdecomp:end func_L01_002F9A40 */
