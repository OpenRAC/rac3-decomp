/* NTSC-U draft (2026-11-14, Claude worker): C of func_L01_00420978, the NTSC-U twin of func_L01_00423690, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L01_00422FE0.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L01_00423690 (src/levels/shared/L01_00422FE0.c) */
#include "vu0.h"

/* localdecomp:start func_L01_00420978 */
typedef struct {
    vu0_v4 v[4];
    s32 c[4];
    f32 uv[8];
    long x70, x78, x80, x88;
} Quad_00420978;
typedef struct {
    u8 pad0[8];
    s32 f8;
    u8 padC[4];
    s32 f10;
} Tex_00420978;
extern Tex_00420978 *D_L01_001DFEE0_00420978;
extern s32 D_L01_001DFEA0;
extern s32 D_L01_001DFEB0;
extern s32 D_L01_001DFEC0_00420978;
extern s32 D_L01_001E6E34[];
extern u8 D_001D6AF5_sda;
__asm__(".extern D_001D6AF5_sda, 4");
extern s32 D_001D6C14_sda;
__asm__(".extern D_001D6C14_sda, 4");
extern s32 D_001D6C18_sda;
__asm__(".extern D_001D6C18_sda, 4");
extern s32 D_001D6C1C_sda;
__asm__(".extern D_001D6C1C_sda, 4");
extern s32 D_001D6B90_sda;
__asm__(".extern D_001D6B90_sda, 4");
extern void func_003D3E40(void *, s32, s32, s32);
extern void func_003CD830(void *, void *, s32);
extern s32 func_0037E1D8(s32);
extern f32 func_00389410(f32);
extern f32 func_00388978(f32);
extern void func_003886E8(void *, void *, f32);

void func_L01_00420978(void) {
    Quad_00420978 t;
    vu0_v4 v90;
    vu0_v4 vA0;
    vu0_v4 vB0;
    vu0_v4 vC0;
    vu0_v4 vD0;
    s32 col, r, n, base;
    s32 i, j;
    f32 f;
    f32 half;

    half = 0.5f;
    func_003D3E40(&t, D_L01_001DFEE0_00420978->f8, D_L01_001DFEE0_00420978->f10, 0x80);
    if (D_001D6AF5_sda != 0) {
        col = ((func_0037E1D8(0x1E) + 0x96) << 24) | 0x323232;
    } else {
        f = func_00388978(func_00389410((f32)D_L01_001E6E34[0] * 0.017453292f));
        base = D_001D6C18_sda;
        f = (f32)D_001D6C14_sda * fabs_asm(f) + (f32)base;
        col = (((s32)f + func_0037E1D8(base)) << 24) | (D_001D6C1C_sda << 16) | (D_001D6C1C_sda << 8) | D_001D6C1C_sda;
    }
    t.c[3] = col;
    t.c[2] = col;
    t.c[1] = col;
    t.c[0] = col;
    vec_sub_ab(&v90, (void *)&D_L01_001DFEC0_00420978, (void *)&D_L01_001DFEA0);
    func_003886E8(&v90, &v90, half);
    vec_sub_ba(&vA0, (void *)&D_L01_001DFEB0, (void *)&D_L01_001DFEA0);
    func_003886E8(&vA0, &vA0, half);
    r = func_0037E1D8(4);
    D_001D6B90_sda = D_001D6B90_sda + (func_0037E1D8(4) + 1);
    if (D_001D6B90_sda >= 4) {
        D_001D6B90_sda = D_001D6B90_sda - 4;
    }
    switch (r) {
    case 0:
        t.uv[0] = 0.0f; t.uv[1] = 0.0f; t.uv[2] = 0.0f; t.uv[3] = 1.0f; t.uv[4] = 1.0f; t.uv[5] = 0.0f; t.uv[6] = 1.0f; t.uv[7] = 1.0f;
        break;
    case 1:
        t.uv[0] = 0.0f; t.uv[1] = 1.0f; t.uv[2] = 1.0f; t.uv[3] = 1.0f; t.uv[4] = 0.0f; t.uv[5] = 0.0f; t.uv[7] = 0.0f; t.uv[6] = 1.0f;
        break;
    case 2:
        t.uv[0] = 0.0f; t.uv[1] = 0.0f; t.uv[2] = 1.0f; t.uv[3] = 0.0f; t.uv[4] = 0.0f; t.uv[5] = 1.0f; t.uv[6] = 1.0f; t.uv[7] = 1.0f;
        break;
    case 3:
        t.uv[0] = 0.0f; t.uv[1] = 1.0f; t.uv[2] = 0.0f; t.uv[3] = 0.0f; t.uv[4] = 1.0f; t.uv[5] = 1.0f; t.uv[7] = 0.0f; t.uv[6] = 1.0f;
        break;
    }
    qzero(&vB0);
    for (i = 0; i < 2; i++) {
        qzero(&vC0);
        for (j = 0; j < 2; j++) {
            vec_add_ab(&vD0, &vC0, (void *)&D_L01_001DFEA0);
            vec_add_ab(&vD0, &vB0, &vD0);
            *(vu0_q *)&t.v[0] = *(vu0_q *)&vD0;
            vec_add_ba(&t.v[1], &vA0, &vD0);
            vec_add_ab(&t.v[2], &v90, &vD0);
            vec_add_ba(&t.v[3], &vA0, &vD0);
            vec_add_ab(&t.v[3], &v90, &t.v[3]);
            func_003CD830(&t, 0, 0);
            vec_add_ab(&vC0, &vA0, &vC0);
        }
        vec_add_ab(&vB0, &v90, &vB0);
    }
}
/* localdecomp:end func_L01_00420978 */
