#include "common.h"

/* NTSC-U counterpart of func_L08_003BE9C0 (src/levels/08_aquatos/L08_003BE9C0.c) */
/* localdecomp:start func_L08_003BC888 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003BE9C0;
__asm__(".extern D_L08_001DE858, 4");
__asm__(".extern D_L08_001DE85C, 4");
__asm__(".extern D_L08_001DE860, 4");
__asm__(".extern D_L08_001DE864, 4");
extern s32 D_L08_001DE858;
extern s32 D_L08_001DE85C;
extern f32 D_L08_001DE860;
extern f32 D_L08_001DE864;
extern void func_0037E2F0(void *, f32, f32);
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *out, void *v, f32 r);
extern s32 func_0037E208(s32, s32);
extern void *func_L01_0046CF70(void *, void *, s32, f32);

void func_L08_003BC888(V4_003BE9C0 *at, V4_003BE9C0 *offset, f32 scale) {
    V4_003BE9C0 pos;
    V4_003BE9C0 v;
    f32 r;
    s32 i;
    s32 n;

    pos = *at;
    for (i = 0; i < D_L08_001DE858; i++) {
        r = D_L08_001DE860 * scale;
        func_0037E2F0(&v, r * 0.5f, r);
        vec_add_ab(&v, &v, offset);
        func_00388830(&v, &v, func_0037E250(D_L08_001DE864 * 0.5f, D_L08_001DE864) * 0.016666668f);
        n = func_0037E208((f32)D_L08_001DE85C * 0.5f, D_L08_001DE85C);
        func_L01_0046CF70(&pos, &v, n, func_0037E250(10.0f, 15.0f) * 0.00027777778f);
    }
}
/* localdecomp:end func_L08_003BC888 */
