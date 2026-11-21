#include "common.h"

/* localdecomp:start func_L30_00345BD0 */
#include "vu0.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_00345BD0;
typedef struct {
    V4_00345BD0 v[4];
    s32 c[4];
    f32 uv[8];
    u8 p70[0x88 - 0x70];
    unsigned long flags;
} R_00345BD0;
__asm__(".extern D_L30_001DCE90, 4");
extern f32 D_L30_001DCE90;
__asm__(".extern D_L30_001DCED4, 4");
extern f32 D_L30_001DCED4;
__asm__(".extern D_L30_001DCEC4, 4");
extern s32 D_L30_001DCEC4;
__asm__(".extern D_L30_001DCED0, 4");
extern s32 D_L30_001DCED0;
extern V4_00345BD0 D_L30_001E2240;
extern f32 D_L30_001E1148[8] __attribute__((section(".sdata")));
extern f32 D_L30_001E1168[8] __attribute__((section(".sdata")));
extern f32 D_L30_00283B60[8][8];
extern f32 D_L30_00283C60[8][8];
extern void func_L30_00343AC8(u8 *, V4_00345BD0 *, f32 *, f32 *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L30_0034C540(R_00345BD0 *, V4_00345BD0 *, s32, f32, f32, f32);
extern void func_003D93B0(void *, s32, s32, s32);
extern void func_003D2DA0(void *, s32, s32);
extern void func_003A9440(s32, unsigned long);
extern void func_L30_00346080(u8 *, V4_00345BD0 *, f32 *, f32 *, f32, f32, f32, f32);

void func_L30_00345BD0(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    R_00345BD0 r;
    V4_00345BD0 c;
    V4_00345BD0 pos;
    V4_00345BD0 d;
    V4_00345BD0 p;
    f32 w;
    f32 h;
    f32 t;
    f32 s;
    f32 rad;
    f32 size;
    f32 wid;
    f32 x0;
    f32 z0;
    s32 i;
    s32 j;

    func_L30_00343AC8(a0, &pos, &w, &h);
    *(vu0_q *)&c = *(vu0_q *)(v + 0x130);
    if (a0[0x20] == 1) {
        t = 1.0f - *(f32 *)(v + 0x160);
    } else {
        t = *(f32 *)(v + 0x160);
    }
    s = D_L30_001DCE90 * (1.0f - t) + 1.0f;
    rad = sqrt_asm(w * w + h * h) * s;
    wid = w * s;
    vec_sub_ba(&d, &D_L30_001E2240, &c);
    func_0038CF68(&d, &d, D_L30_001DCED4);
    size = rad + rad;
    vec_add_ab(&c, &c, &d);
    func_L30_0034C540(&r, &c, 0, size, size, 0.0f);
    func_003D93B0(&r, 0x3B, 1, 0x80);
    r.flags = 0x800000004A;
    r.c[3] = D_L30_001DCEC4;
    r.c[2] = D_L30_001DCEC4;
    r.c[1] = D_L30_001DCEC4;
    r.c[0] = D_L30_001DCEC4;
    r.uv[0] = 0.0f;
    r.uv[1] = 0.0f;
    r.uv[2] = 0.0f;
    r.uv[3] = 1.0f;
    r.uv[4] = 1.0f;
    r.uv[5] = 0.0f;
    r.uv[6] = 1.0f;
    r.uv[7] = 1.0f;
    func_003A9440(0x47, 0x31001);
    func_003D2DA0(&r, 0, 0);
    func_003D93B0(&r, -1, 2, 0x80);
    r.flags = 0x8000000054;
    func_003A9440(0x47, 0x53001);
    x0 = c.x - rad;
    z0 = c.z - rad;
    for (i = 0; i < 8; i++) {
        f32 k = size * ((f32)i / 7.0f);
        D_L30_001E1148[i] = x0 + k;
        D_L30_001E1168[i] = z0 + k;
    }
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            p.x = D_L30_001E1148[i];
            p.y = c.y;
            p.z = D_L30_001E1168[j];
            p.w = 1.0f;
            func_L30_00346080(a0, &p, &D_L30_00283B60[i][j], &D_L30_00283C60[i][j], (f32)i / 7.0f, (f32)j / 7.0f, wid, t);
        }
    }
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7; j++) {
            r.v[2].x = D_L30_001E1148[i];
            r.v[3].x = D_L30_001E1148[i + 1];
            r.v[1].z = D_L30_001E1168[j];
            r.v[3].z = D_L30_001E1168[j + 1];
            r.v[0].x = D_L30_001E1148[i];
            r.v[1].x = D_L30_001E1148[i + 1];
            r.v[0].z = D_L30_001E1168[j];
            r.v[2].z = D_L30_001E1168[j + 1];
            r.c[3] = D_L30_001DCED0;
            r.c[2] = D_L30_001DCED0;
            r.c[1] = D_L30_001DCED0;
            r.c[0] = D_L30_001DCED0;
            r.uv[0] = D_L30_00283B60[i][j];
            r.uv[1] = D_L30_00283C60[i][j];
            r.uv[2] = D_L30_00283B60[i + 1][j];
            r.uv[3] = D_L30_00283C60[i + 1][j];
            r.uv[4] = D_L30_00283B60[i][j + 1];
            r.uv[5] = D_L30_00283C60[i][j + 1];
            r.uv[6] = D_L30_00283B60[i + 1][j + 1];
            r.uv[7] = D_L30_00283C60[i + 1][j + 1];
            func_003D2DA0(&r, 0, 0);
        }
    }
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L30_00345BD0 */
