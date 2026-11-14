#include "common.h"

/* localdecomp:start func_L23_0044FD88 */
typedef int s128_44FD88 __attribute__((mode(TI)));
extern u8 *func_L01_0045E438(s32 size);
extern f32 func_0037E250(f32, f32);
extern u8 *D_L23_0021EF68[];

u8 *func_L23_0044FD88(s128_44FD88 *pos, s128_44FD88 *dir, s32 a2, u32 rgba, s32 index, f32 scale, f32 f13, f32 f14) {
    u8 *m = func_L01_0045E438(0x32);
    u8 *p;
    if (m != 0) {
        *(s128_44FD88 *)(m + 0x10) = *pos;
        p = m + 0x20;
        m[9] = 0x41;
        m[3] = 0x44;
        m[1] = 0;
        m[2] = D_L23_0021EF68[0][index];
        *(u32 *)(m + 4) = rgba;
        *(f32 *)(m + 0xC) = scale * 210000.0f;
        m[8] = (int)func_0037E250(0.0f, 255.0f);
        *(s16 *)(m + 0xA) = 0xF;
        *(s128_44FD88 *)(m + 0x20) = *dir;
        *(s32 *)(p + 0x1C) = a2;
        *(f32 *)(p + 0x10) = f13;
        *(s32 *)(p + 0x14) = (int)func_0037E250(-3.0f, 3.0f);
        *(f32 *)(p + 0x18) = f14;
    }
    return m;
}
/* localdecomp:end func_L23_0044FD88 */
