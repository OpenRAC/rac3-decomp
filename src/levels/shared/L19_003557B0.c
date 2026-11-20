#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L19_003557B0 */
typedef struct {
    vu0_v4 m[4];
    s32 c[4];
    f32 uv[4][2];
    long x70, x78, x80, x88;
} S_003557B0;

typedef struct {
    f32 u, v;
} UV_003557B0;

extern f32 D_L19_001E2098[];
extern f32 D_L19_001DD72C;
extern f32 D_L19_001DD730;
extern f32 D_L19_001DD734;
extern f32 D_L19_001DD738;
__asm__(".extern D_L19_001DD72C, 4");
__asm__(".extern D_L19_001DD730, 4");
__asm__(".extern D_L19_001DD734, 4");
__asm__(".extern D_L19_001DD738, 4");
__asm__(".extern D_L19_001DD6C8, 4");
__asm__(".extern D_L19_001DD708, 4");
extern s32 D_L19_001DD6C8[4][4] __attribute__((section(".sdata")));
extern s32 D_L19_001DD708[] __attribute__((section(".sdata")));
extern vu0_v4 D_L19_002B5750[];
extern UV_003557B0 D_L19_002B57E0[];

extern void func_0038D308(void *, void *);
extern long func_00389598(s32);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003D2DA0(void *, void *, s32);

void func_L19_003557B0(u8 *self) {
    vu0_v4 rot[3];
    vu0_v4 ang;
    S_003557B0 s;
    vu0_v4 v[4];
    u8 *vars;
    s32 i;
    s32 j;
    s32 k;
    f32 h;
    f32 a;
    f32 b;
    f32 z0;
    f32 z1;
    s32 c;

    vars = *(u8 **)(self + 0x68);
    ang.x = 0.0f;
    ang.y = 0.0f;
    ang.z = D_L19_001E2098[0];
    func_0038D308(rot, &ang);

    D_L19_001DD734 += 0.01f;
    if (D_L19_001DD734 > 1.0f) {
        D_L19_001DD734 -= 1.0f;
    }
    D_L19_001DD738 += 0.02f;
    if (D_L19_001DD738 > 1.0f) {
        D_L19_001DD738 = 0.0f;
    }

    s.x80 = 1;
    s.x88 = 0x4000000044L;
    s.x70 = 0;
    s.x78 = func_00389598(0x18);
    for (i = 0; i < 4; i++) {
        func_0038D000(&v[0], &D_L19_002B5750[D_L19_001DD6C8[i][0]], rot);
        func_0038D000(&v[1], &D_L19_002B5750[D_L19_001DD6C8[i][1]], rot);
        func_0038D000(&v[2], &D_L19_002B5750[D_L19_001DD6C8[i][2]], rot);
        func_0038D000(&v[3], &D_L19_002B5750[D_L19_001DD6C8[i][3]], rot);
        for (j = 0; j < 4; j++) {
            func_0038CE20(&v[j], &v[j], D_L19_001DD72C);
        }
        s.m[0].x = *(f32 *)(self + 0x10) + v[0].x * *(f32 *)(vars + 0x24);
        s.m[0].y = *(f32 *)(self + 0x14) + v[0].y * *(f32 *)(vars + 0x24);
        s.m[0].z = *(f32 *)(self + 0x18) + v[0].z - 1.0f + D_L19_001DD730;
        s.m[1].x = *(f32 *)(self + 0x10) + v[1].x * *(f32 *)(vars + 0x24);
        s.m[1].y = *(f32 *)(self + 0x14) + v[1].y * *(f32 *)(vars + 0x24);
        s.m[1].z = *(f32 *)(self + 0x18) + v[1].z - 1.0f + D_L19_001DD730;
        s.m[2].x = *(f32 *)(self + 0x10) + v[2].x * *(f32 *)(vars + 0x24);
        s.m[2].y = *(f32 *)(self + 0x14) + v[2].y * *(f32 *)(vars + 0x24);
        s.m[2].z = *(f32 *)(self + 0x18) + v[2].z - 1.0f + D_L19_001DD730;
        s.m[3].x = *(f32 *)(self + 0x10) + v[3].x * *(f32 *)(vars + 0x24);
        s.m[3].y = *(f32 *)(self + 0x14) + v[3].y * *(f32 *)(vars + 0x24);
        s.m[3].z = *(f32 *)(self + 0x18) + v[3].z - 1.0f + D_L19_001DD730;
        s.c[0] = D_L19_001DD708[D_L19_001DD6C8[i][0]];
        s.c[1] = D_L19_001DD708[D_L19_001DD6C8[i][1]];
        s.c[2] = D_L19_001DD708[D_L19_001DD6C8[i][2]];
        s.c[3] = D_L19_001DD708[D_L19_001DD6C8[i][3]];
        s.uv[0][0] = D_L19_002B57E0[D_L19_001DD6C8[i][0]].u;
        s.uv[0][1] = D_L19_002B57E0[D_L19_001DD6C8[i][0]].v + D_L19_001DD734;
        s.uv[1][0] = D_L19_002B57E0[D_L19_001DD6C8[i][1]].u;
        s.uv[1][1] = D_L19_002B57E0[D_L19_001DD6C8[i][1]].v + D_L19_001DD734;
        s.uv[2][0] = D_L19_002B57E0[D_L19_001DD6C8[i][2]].u;
        s.uv[2][1] = D_L19_002B57E0[D_L19_001DD6C8[i][2]].v + D_L19_001DD734;
        s.uv[3][0] = D_L19_002B57E0[D_L19_001DD6C8[i][3]].u;
        s.uv[3][1] = D_L19_002B57E0[D_L19_001DD6C8[i][3]].v + D_L19_001DD734;
        func_003D2DA0(&s, 0, 1);
    }

    s.x78 = func_00389598(0x1B);
    h = D_L19_001DD738;
    a = -h * 1.2f;
    b = h * 1.2f;
    z0 = h * 1.4f + 1.1f;
    z1 = z0 - 0.2f;
    {
        vu0_v4 src[4] = {
            { a * *(f32 *)(vars + 0x24), a * *(f32 *)(vars + 0x24), z0 },
            { b * *(f32 *)(vars + 0x24), a * *(f32 *)(vars + 0x24), z1 },
            { a * *(f32 *)(vars + 0x24), b * *(f32 *)(vars + 0x24), z0 },
            { b * *(f32 *)(vars + 0x24), b * *(f32 *)(vars + 0x24), z1 },
        };
        func_0038D000(&v[0], &src[0], rot);
        func_0038D000(&v[1], &src[1], rot);
        func_0038D000(&v[2], &src[2], rot);
        func_0038D000(&v[3], &src[3], rot);
    }
    for (k = 0; k < 4; k++) {
        func_0038CE20(&v[k], &v[k], D_L19_001DD72C);
    }
    c = ((s32)((1.0f - D_L19_001DD738 * D_L19_001DD738) * 255.0f) << 24) | 0x204080;
    s.m[0].x = *(f32 *)(self + 0x10) + v[0].x;
    s.m[0].y = *(f32 *)(self + 0x14) + v[0].y;
    s.m[0].z = *(f32 *)(self + 0x18) + v[0].z - 1.0f + D_L19_001DD730;
    s.m[1].x = *(f32 *)(self + 0x10) + v[1].x;
    s.m[1].y = *(f32 *)(self + 0x14) + v[1].y;
    s.m[1].z = *(f32 *)(self + 0x18) + v[1].z - 1.0f + D_L19_001DD730;
    s.m[2].x = *(f32 *)(self + 0x10) + v[2].x;
    s.m[2].y = *(f32 *)(self + 0x14) + v[2].y;
    s.m[2].z = *(f32 *)(self + 0x18) + v[2].z - 1.0f + D_L19_001DD730;
    s.m[3].x = *(f32 *)(self + 0x10) + v[3].x;
    s.m[3].y = *(f32 *)(self + 0x14) + v[3].y;
    s.m[3].z = *(f32 *)(self + 0x18) + v[3].z - 1.0f + D_L19_001DD730;
    s.c[3] = c;
    s.c[2] = c;
    s.c[1] = c;
    s.c[0] = c;
    s.uv[0][0] = 0.0f;
    s.uv[0][1] = 0.0f;
    s.uv[1][0] = 1.0f;
    s.uv[1][1] = 0.0f;
    s.uv[2][0] = 0.0f;
    s.uv[2][1] = 1.0f;
    s.uv[3][0] = 1.0f;
    s.uv[3][1] = 1.0f;
    func_003D2DA0(&s, 0, 1);
}
/* localdecomp:end func_L19_003557B0 */
