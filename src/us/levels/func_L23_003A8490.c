#include "common.h"

/* NTSC-U counterpart of func_L23_003A9D00 (src/levels/23_holostar_studios_clank/L23_003A6688.c) */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct {
    f32 m[4][4];
    s32 c40, c44, c48, c4C;
    s32 x50, x54, x58;
    f32 x5C, x60;
    s32 x64;
    f32 x68, x6C;
    long x70, x78, x80, x88;
    V4 axis;
    V4 r[4];
} S_3A9D00;
typedef struct {
    u8 pad0[0x140];
    f32 x140;
    f32 x144;
} S_1E1880;
#include "vu0.h"
#include "vu0.h"
extern s32 D_L23_001DECC0;
#include "vu0.h"
extern f32 func_00388978(f32);

/* localdecomp:start func_L23_003A8490 */
#include "vu0.h"
extern S_1E1880 D_L23_001E1900;
extern long func_00384EC0(s32);
extern f32 func_00388A28(f32, f32);
extern f32 func_00389410(f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_00389158(void *, void *, void *, f32);
extern void func_00388758(void *, void *, void *);
extern void func_003CD830(S_3A9D00 *, V4 *, s32);

void func_L23_003A8490(u8 *self)
{
    u8 *v = *(u8 **)(self + 0x68);
    S_3A9D00 s;
    s32 i;
    s32 n;
    s32 c;
    f32 ang;
    f32 b;
    f32 t;

    s.x78 = func_00384EC0(0x6A);
    s.x80 = 0xFF9000000260L;
    s.x70 = 4;
    s.x88 = 0x8000000044L;
    s.x50 = 0;
    s.x54 = 0;
    s.x58 = 0;
    s.x5C = 1.0f;
    s.x60 = 1.0f;
    s.x64 = 0;
    s.x68 = 1.0f;
    s.x6C = 1.0f;
    c = (*(s32 *)(v + 0x2C) << 24) | 0x303030;
    qzero(s.m[0]);
    qzero(s.m[1]);
    qzero(s.m[2]);
    qzero(s.m[3]);
    *(u128_t *)&s.axis = 0;
    s.m[0][0] = 3.0f;
    s.m[0][3] = 1.0f;
    s.c4C = c;
    s.m[1][1] = 3.0f;
    s.c48 = c;
    s.m[1][3] = 1.0f;
    s.c44 = c;
    s.c40 = c;
    s.m[2][3] = 1.0f;
    s.m[2][1] = -3.0f;
    s.m[3][0] = -3.0f;
    s.m[3][3] = 1.0f;
    s.axis.z = 1.0f;
    s.axis.w = 1.0f;
    n = *(f32 *)(v + 0x24) * 8.0f / 3.0f;
    for (i = 0; i < n; ) {
        ang = func_00388A28(D_L23_001E1900.x140 - *(f32 *)(self + 0x10),
                            D_L23_001E1900.x144 - *(f32 *)(self + 0x14));
        b = func_00389410((f32)i * 2 * 3.1415927f / (f32)n);
        t = (f32)((D_L23_001DECC0 + i * 16) % 120) / 120.0f * 6.2831855f - 1.5707964f;
        if (func_00389410(ang - b) > 0.0f) {
            t = -t;
        }
        i++;
        s.r[2].x = func_00388960(ang);
        s.r[2].y = func_00388978(ang);
        s.r[2].z = 0.0f;
        func_00389158(&s.r[0], &s.axis, &s.r[2], t);
        func_00388758(&s.r[1], &s.r[0], &s.r[2]);
        s.r[3].x = func_00388960(b) * (*(f32 *)(v + 0x24) * 0.6f);
        s.r[3].y = func_00388978(b) * (*(f32 *)(v + 0x24) * 0.6f);
        s.r[3].z = 0.0f;
        vec_add_ab(&s.r[3], &s.r[3], v + 0x30);
        s.r[3].z = *(f32 *)(v + 0x8) + 0.6f;
        func_003CD830(&s, &s.r[0], 1);
    }
}
/* localdecomp:end func_L23_003A8490 */
