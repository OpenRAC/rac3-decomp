#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_00423690 */
typedef struct {
    vu0_v4 v[4];
    s32 c[4];
    f32 uv[8];
    long x70, x78, x80, x88;
} Quad_00423690;
typedef struct {
    u8 pad0[8];
    s32 f8;
    u8 padC[4];
    s32 f10;
} Tex_00423690;
extern Tex_00423690 *D_L01_001DFE60_00423690;
extern s32 D_L01_001DFE20;
extern s32 D_L01_001DFE30;
extern s32 D_L01_001DFE40_00423690;
extern s32 D_L01_001E6DB4[];
extern u8 D_L01_001D6AF5;
__asm__(".extern D_L01_001D6AF5, 4");
extern s32 D_L01_001D6C14;
__asm__(".extern D_L01_001D6C14, 4");
extern s32 D_L01_001D6C18;
__asm__(".extern D_L01_001D6C18, 4");
extern s32 D_L01_001D6C1C;
__asm__(".extern D_L01_001D6C1C, 4");
extern s32 D_L01_001D6B90;
__asm__(".extern D_L01_001D6B90, 4");
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_003D2DA0(void *, void *, s32);
extern s32 func_00382468(s32);
extern f32 func_0038DB48(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CE20(void *, void *, f32);

void func_L01_00423690(void) {
    Quad_00423690 t;
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
    func_003D93B0(&t, D_L01_001DFE60_00423690->f8, D_L01_001DFE60_00423690->f10, 0x80);
    if (D_L01_001D6AF5 != 0) {
        col = ((func_00382468(0x1E) + 0x96) << 24) | 0x323232;
    } else {
        f = func_0038D0B0(func_0038DB48((f32)((D_L01_001E6DB4[0] * 5 + 2) / 6) * 0.017453292f));
        base = D_L01_001D6C18;
        f = (f32)D_L01_001D6C14 * fabs_asm(f) + (f32)base;
        col = (((s32)f + func_00382468(base)) << 24) | (D_L01_001D6C1C << 16) | (D_L01_001D6C1C << 8) | D_L01_001D6C1C;
    }
    t.c[3] = col;
    t.c[2] = col;
    t.c[1] = col;
    t.c[0] = col;
    vec_sub_ab(&v90, (void *)&D_L01_001DFE40_00423690, (void *)&D_L01_001DFE20);
    func_0038CE20(&v90, &v90, half);
    vec_sub_ba(&vA0, (void *)&D_L01_001DFE30, (void *)&D_L01_001DFE20);
    func_0038CE20(&vA0, &vA0, half);
    r = func_00382468(4);
    D_L01_001D6B90 = D_L01_001D6B90 + (func_00382468(4) + 1);
    if (D_L01_001D6B90 >= 4) {
        D_L01_001D6B90 = D_L01_001D6B90 - 4;
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
            vec_add_ab(&vD0, &vC0, (void *)&D_L01_001DFE20);
            vec_add_ab(&vD0, &vB0, &vD0);
            *(vu0_q *)&t.v[0] = *(vu0_q *)&vD0;
            vec_add_ba(&t.v[1], &vA0, &vD0);
            vec_add_ab(&t.v[2], &v90, &vD0);
            vec_add_ba(&t.v[3], &vA0, &vD0);
            vec_add_ab(&t.v[3], &v90, &t.v[3]);
            func_003D2DA0(&t, 0, 0);
            vec_add_ab(&vC0, &vA0, &vC0);
        }
        vec_add_ab(&vB0, &v90, &vB0);
    }
}
/* localdecomp:end func_L01_00423690 */

LINKER_REMNANT("asm/levels", func_L01_004239F8);
