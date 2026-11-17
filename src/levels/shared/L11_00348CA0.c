#include "common.h"

/* localdecomp:start func_L11_00348CA0 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00348CA0;
typedef struct { V4_00348CA0 r[3]; } M3_00348CA0;
__asm__(".extern D_L11_001DD1D0, 4");
__asm__(".extern D_L11_001DD1D8, 4");
__asm__(".extern D_L11_001DD1E0, 4");
extern s32 D_L11_001DD1D0;
extern s32 D_L11_001DD1D8;
extern f32 D_L11_001DD1E0;
extern s32 D_L11_001DD1D4;
extern s32 D_L11_001DD1DC;
extern f32 D_L11_001DD1E4;
extern M3_00348CA0 D_L11_001DD1F0;
extern u8 D_L11_001D66B0[8];
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D000(void *, void *, void *);
extern s32 *func_L01_00470668(void *, void *, s32, f32);

void func_L11_00348CA0(u8 *m) {
    f32 w[3];
    V4_00348CA0 a;
    V4_00348CA0 b;
    M3_00348CA0 axes;
    f32 scale;
    f32 sum;
    s32 n;
    s32 i;
    s32 j;
    s32 *p;

    scale = -(func_003824E0(D_L11_001DD1E0, D_L11_001DD1E4) * 0.00040000002f);
    n = (func_00382498(D_L11_001DD1D8, D_L11_001DD1DC) * 5 + 2) / 6;
    for (i = 0; i < 3; i++) {
        w[i] = func_003824E0(0.0f, 1.0f);
    }
    sum = 1.0f / (w[0] + w[1] + w[2]);
    for (j = 0; j < 3; j++) {
        w[j] *= sum;
    }
    axes = D_L11_001DD1F0;
    func_0038CE20(&a, &axes.r[0], w[0]);
    func_0038CE20(&b, &axes.r[1], w[1]);
    vec_add_ba(&a, &a, &b);
    func_0038CE20(&b, &axes.r[2], w[2]);
    vec_add_ba(&a, &a, &b);
    func_0038D000(&a, &a, m + 0xC0);
    vec_add_ba(&a, &a, m + 0x10);
    p = func_L01_00470668(&a, D_L11_001D66B0, n, scale);
    if (p != 0) {
        p[1] = D_L11_001DD1D0;
        p[3] = D_L11_001DD1D4;
    }
}
/* localdecomp:end func_L11_00348CA0 */
