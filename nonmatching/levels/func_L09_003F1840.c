/* NTSC-U draft (2026-11-14, Claude worker): C of func_L09_003EF9B8, the NTSC-U twin of func_L09_003F1840, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/09_tyhrranosis/L09_003F1600.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L09_003F1840 (src/levels/09_tyhrranosis/L09_003F1600.c) */
#include "vu0.h"

/* localdecomp:start func_L09_003EF9B8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4;
typedef struct { f32 x, y, z, w; } W4;
extern W4 D_L09_001DF5B0;
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern f32 func_0037E2A8(void);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_00329470(V4 *, V4 *, s32, s32, s32, s32, W4 *, s32, s32, s32, f32, f32);

void func_L09_003EF9B8(u8 *self) {
    V4 v1;
    V4 v2;
    W4 v3;
    f32 ratio, half, ang, s, c, size;
    s32 col, flag, life;
    u8 *p;
    V4 *vp;

    ratio = *(f32 *)(self + 0x2C) / *(f32 *)(*(u8 **)(self + 0x24) + 0x24);
    col = 0x44925;
    ang = func_0037E2A8();
    v2 = *(V4 *)(self + 0x10);
    s = func_00388960(ang);
    ratio = ratio * 8.0f;
    half = ratio * 0.5f;
    v2.x += s * func_0037E250(half, ratio);
    c = func_00388978(ang);
    v2.y += c * func_0037E250(half, ratio);
    vp = &v1;
    qzero(&v1);
    v2.z = 345.0f;
    v1.z = func_0037E250(-3.0f, -0.5f) * 0.0166666675f;
    if (func_0037E1D8(3) != 0) {
        col = 0xC3F24;
    }
    v3 = D_L09_001DF5B0;
    flag = func_0037E1D8(5) == 0;
    life = func_0037E208(0x5A, 0x96);
    size = func_0037E250(3.0f, 18.0f);
    p = func_L01_00329470(&v2, vp, life, flag, 0, col, &v3, 0, 0x96, 0x96, 1.0f, size);
    if (p != 0) {
        *(f32 *)(p + 0x2C) = *(f32 *)(*(u8 **)(p + 0x24) + 0x24) * func_0037E250(2.0f, 4.0f);
    }
}
/* localdecomp:end func_L09_003EF9B8 */
