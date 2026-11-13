#include "common.h"

/* NTSC-U counterpart of func_L23_0032B060 (src/levels/23_holostar_studios_clank/L23_0032B060.c): 67 -> 80 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;

/* localdecomp:start func_L23_0032AA28 */
extern u8 *func_003C24B0(s32, s32);
extern void func_003C5180(void *, void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);

u8 *func_L23_0032AA28(V4 *pos, V4 *dir, f32 *arg, f32 scale)
{
    V4 up;
    V4 fwd;
    u8 *m;
    u8 *v;

    func_003C5180(pos, &up, 1);
    m = func_003C24B0(0xF5D, 0x80);
    if (m != 0) {
        v = *(u8 **)(m + 0x68);
        *(f32 *)(v + 0x1C) = *arg;
        *(s32 *)(v + 0x10) = 0x50;
        m[0x30] = 0xFF;
        *(s16 *)(m + 0x32) = 0xFF;
        m[0x20] = 0;
        *(V4 *)(m + 0x10) = *pos;
        *(V4 *)v = *dir;
        *(s32 *)(v + 0x18) = 0;
        *(s32 *)(v + 0x14) = 0;
        func_0038CF68(&fwd, dir, 1.0f);
        *(f32 *)(m + 0x2C) = scale;
        *(V4 *)(m + 0xC0) = fwd;
        func_0038CE90(m + 0xD0, m + 0xC0, &up);
        func_0038CF68(m + 0xD0, m + 0xD0, 1.0f);
        func_0038CE90(m + 0xE0, m + 0xD0, m + 0xC0);
        *(f32 *)(m + 0xCC) = *(f32 *)(m + 0xDC) = *(f32 *)(m + 0xEC) = 0.0f;
    }
    return m;
}
/* localdecomp:end func_L23_0032AA28 */
