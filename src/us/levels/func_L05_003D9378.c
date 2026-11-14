#include "common.h"

/* NTSC-U counterpart of func_L05_003DB7A0 (src/levels/05_daxx/L05_003DB7A0.c) */
/* localdecomp:start func_L05_003D9378 */
#include "vu0.h"
typedef int q_3DB7A0 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3DB7A0;

extern u8 D_L05_001D66B0_003D9378[8];
__asm__(".extern D_L05_001D66B0_003D9378, 16");
extern f32 D_L05_001DF198;
__asm__(".extern D_L05_001DF198, 4");
extern void func_L01_0044ED60(void *m, s32 a, void *b, f32 x1, f32 x2, f32 x3, f32 x4, s32 e,
                              f32 x5, f32 x6, s32 f, s32 g, s32 c, s32 d, f32 x0, f32 one,
                              s32 h, s32 k);
extern u8 *func_L01_0044F1E8(void *, s32, s32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_0032FE90(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_0044EBF8(void *, s32, f32);
extern void func_003BD360(void *);

void func_L05_003D9378(u8 *o) {
    V4_3DB7A0 b;
    V4_3DB7A0 v;
    q_3DB7A0 z;
    u8 *m;

    func_L01_0044ED60(o, 0x1FF, D_L05_001D66B0_003D9378, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF, -1.0f, -1.0f, 0xB4, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
    m = func_L01_0044F1E8(o, 0x1E51, 0);
    *(s32 *)(o + 0x98) = 0;
    o[0x31] = 0;
    *(u16 *)(o + 0x34) |= 1;
    if (m != 0) {
        *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
    }
    z = 0;
    *(q_3DB7A0 *)&v = z;
    v.z = D_L05_001DF198;
    b = v;
    *(q_3DB7A0 *)&v = z;
    v.z = -0.116666675f;
    func_L02_003E0520(o, &b, 0.100000001f, &v, 0x50, 3, 0, 0.15f, 2.5f, 20.0f, 1.0f);
    vec_add_ba(&b, &b, o + 0x10);
    func_L01_0032FE90(&b, 0, 0, 0, 0, 2, 5, 0, 1.0f, 0.0f, 0.0f, 0.0f, 0, 1, 0, 0, 0, 0, 0x1000000, 0, 0x7FD68F, 0xFF8400, 0, 0, 0, 0, 0x7F60A0FF, 0x280000FF, 0, 0);
    func_L01_0044EBF8(o, 1, 0.0f);
    func_003BD360(o);
}
/* localdecomp:end func_L05_003D9378 */
