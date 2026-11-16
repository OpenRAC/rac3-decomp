#include "common.h"

/* NTSC-U counterpart of func_L09_003F1840 (src/levels/09_tyhrranosis/L09_003F1840.c) */
/* localdecomp:start func_L09_003EF9B8 */
#include "vu0.h"
/* func_L09_003EF9B8: log
 * - first wording after func_L01_003E32F8's call of func_L01_00329470: 124 (with --as ps2as)
 * - v.z = 345, b.z = random, qzero for the bare sq $0: 123; &b in a temporary (retail keeps it in $s4): 21
 * - s *= random; v.x += s: 13; separate sin and cos variables: MATCH (with --as ps2as)
 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003F1840;
typedef struct { f32 x, y, z, w; } W4_003F1840;

extern W4_003F1840 D_L09_001DF5B0;
extern f32 func_0037E2A8(void);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_00329470(V4_003F1840 *a, V4_003F1840 *b, s32 c, s32 d, s32 e, s32 f, W4_003F1840 *g, s32 h, s32 i, s32 j, f32 k, f32 l);

void func_L09_003EF9B8(u8 *a0) {
    V4_003F1840 b;
    V4_003F1840 v;
    W4_003F1840 w;
    f32 scale;
    f32 ang;
    f32 lo;
    f32 s;
    f32 c;
    s32 col;
    s32 flag;
    s32 n;
    u8 *o;
    V4_003F1840 *pb;

    scale = *(f32 *)(a0 + 0x2C) / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24);
    col = 0x44925;
    ang = func_0037E2A8();
    v = *(V4_003F1840 *)(a0 + 0x10);
    s = func_00388960(ang);
    scale = scale * 8.0f;
    lo = scale * 0.5f;
    s *= func_0037E250(lo, scale);
    v.x += s;
    c = func_00388978(ang);
    c *= func_0037E250(lo, scale);
    v.y += c;
    pb = &b;
    qzero(pb);
    v.z = 345.0f;
    b.z = func_0037E250(-3.0f, -0.5f) * 0.01666666754f;
    if (func_0037E1D8(3) != 0) {
        col = 0xC3F24;
    }
    w = D_L09_001DF5B0;
    flag = func_0037E1D8(5) == 0;
    n = func_0037E208(90, 150);
    o = func_L01_00329470(&v, pb, n, flag, 0, col, &w, 0, 0x96, 0x96, 1.0f, func_0037E250(3.0f, 18.0f));
    if (o != 0) {
        *(f32 *)(o + 0x2C) = *(f32 *)(*(u8 **)(o + 0x24) + 0x24) * func_0037E250(2.0f, 4.0f);
    }
}
/* localdecomp:end func_L09_003EF9B8 */
