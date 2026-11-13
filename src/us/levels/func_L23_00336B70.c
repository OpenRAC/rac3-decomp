#include "common.h"

/* NTSC-U counterpart of func_L23_003373D0 (src/levels/23_holostar_studios_clank/L23_003373D0.c): 0.4 -> 0.333333; 125 -> 150 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { V4 r[3]; } M3;

/* localdecomp:start func_L23_00336B70 */
__asm__(".extern D_L23_001DCD28, 4");
extern f32 D_L23_001DCD28;
extern f32 D_L23_001DBD0C;
extern s32 D_001A71A4[];
extern M3 D_L23_001E1E40;
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00452E70(void *, void *);
extern void func_003C48A8(void *, void *);

u8 *func_L23_00336B70(u8 *src, V4 *pos, s32 arg)
{
    u8 *m = func_003C24B0(0x100, 0x80);
    u8 *v;

    if (m != 0) {
        v = *(u8 **)(m + 0x68);
        func_L01_00452E70(m, src);
        *(f32 *)(m + 0x2C) *= D_L23_001DCD28 * D_L23_001DBD0C;
        *(f32 *)(v + 0x2C) = 0.333333343f;
        *(M3 *)(m + 0xC0) = *(M3 *)(src + 0xC0);
        if (D_001A71A4[0] == 1)
            *(M3 *)(m + 0xC0) = D_L23_001E1E40;
        func_003C48A8(m + 0xC0, m + 0xF0);
        *(u8 **)(v + 0x20) = src;
        *(s32 *)(v + 0x28) = arg;
        *(V4 *)(m + 0x10) = *pos;
        *(s32 *)(v + 0x24) = 0x96;
        *(f32 *)(m + 0x2C) += *(f32 *)(m + 0x2C);
    }
    return m;
}
/* localdecomp:end func_L23_00336B70 */
