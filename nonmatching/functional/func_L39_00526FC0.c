/* functional: high. Same reads, writes, calls and call order as retail. The per-row/column table index, the loop bounds (rows 2..11, columns 0..19 wrapping) and the f32 scroll arithmetic follow retail; retail's data[0x3C] old value is used as the u coordinate and kept. Only register allocation and stack layout differ. */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_00526FC0;

typedef struct {
    V_00526FC0 m[4];
    s32 c40, c44, c48, c4C;
    f32 uv[4][2];
    long x70, x78, x80, x88;
} S_00526FC0;

extern long func_L39_00589890(s32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_0038CE68(void *, void *);
extern void func_003D2DA0(void *, s32, s32);
extern void func_L39_00527460(void *, void *, s32, s32, s32, s32, f32, f32, f32, f32);
extern void func_L39_00527A38(void *);
extern V_00526FC0 D_L39_003B5740[][12];
extern V_00526FC0 D_L39_003B5D40[][12];
extern V_00526FC0 D_L39_003B6340[][12][20];

void func_L39_00526FC0(u8 *obj)
{
    S_00526FC0 s;
    V_00526FC0 d0;
    V_00526FC0 d1;
    V_00526FC0 nrm;
    V_00526FC0 d;
    u8 *data;
    u8 *e;
    s32 id;
    s32 i;
    s32 j;
    s32 n;
    s32 color;
    f32 f0, f1, f2;
    f32 fu, fv0, fv1, fu2;

    if (obj == 0) {
        return;
    }
    if (*(s16 *)(obj + 0xAA) != 0x10A7) {
        return;
    }
    if (obj[0x20] == 0xFE || obj[0x20] == 0xFD) {
        return;
    }
    data = *(u8 **)(obj + 0x68);
    if (data == 0) {
        return;
    }
    e = *(u8 **)(data + 0x54);
    id = 0;
    if (e != 0) {
        id = *(s32 *)(e + 0x2544);
    }
    f1 = *(f32 *)(data + 0x28) - 0.36f;
    *(f32 *)(data + 0x28) = f1;
    if (f1 <= -8.0f) {
        *(f32 *)(data + 0x28) = f1 + 8.0f;
    }
    func_L39_00527460(&D_L39_003B5740[id][0], e + 0x23A0, 0x80, 0x40, 12, 0x103FFF, 0.05f, 0.4f, 0.9f, *(f32 *)(data + 0x28));
    color = 0x400000FF;
    func_L39_00527460(&D_L39_003B5D40[id][0], e + 0x23A0, 0x80, 0x40, 12, 0x10107F, 0.05f, 0.4f, 0.9f, *(f32 *)(data + 0x28));
    func_L39_00527A38(obj);
    s.x78 = func_L39_00589890(13);
    s.x80 = 0xFF9000000260L;
    s.x88 = 0x8000000048L;
    s.c40 = color;
    s.x70 = 0;
    s.c4C = color;
    s.c48 = color;
    s.c44 = color;
    fu = *(f32 *)(data + 0x3C);
    f1 = fu - 0.048f;
    *(f32 *)(data + 0x3C) = f1;
    if (f1 <= -8.0f) {
        *(f32 *)(data + 0x3C) = f1 + 8.0f;
    }
    f1 = *(f32 *)(data + 0x20);
    f2 = 0.012f;
    f1 = f1 - f2;
    *(f32 *)(data + 0x20) = f1;
    if (f1 <= -7.0f) {
        *(f32 *)(data + 0x20) = f1 + 7.0f;
    }
    f0 = *(f32 *)(data + 0x24) + f2;
    *(f32 *)(data + 0x24) = f0;
    if (5.0f <= f0) {
        *(f32 *)(data + 0x24) = f0 - 5.0f;
    }
    for (i = 2; i < 12; i++) {
        fv0 = *(f32 *)(data + 0x20);
        fv1 = *(f32 *)(data + 0x24);
        for (j = 0; j < 20; j++) {
            n = (j + 1) % 20;
            s.m[0] = D_L39_003B6340[id][i][j];
            s.m[1] = D_L39_003B6340[id][i][n];
            s.m[2] = D_L39_003B6340[id][i - 1][j];
            s.m[3] = D_L39_003B6340[id][i - 1][n];
            vec_sub_ab(&d0, &s.m[0], &s.m[1]);
            vec_sub_ab(&d1, &s.m[2], &s.m[1]);
            func_0038CE90(&nrm, &d1, &d0);
            vec_sub_ab(&d, &s.m[1], e + 0x23A0);
            if (0.0f <= func_0038CE68(&nrm, &d)) {
                fv0 += 0.05f;
                fv1 += 0.05f;
            } else {
                if (i == 11) {
                    s.c40 = 0xFF;
                    s.c44 = 0xFF;
                }
                fu2 = fu - 0.066667f;
                s.uv[0][0] = fu;
                s.uv[0][1] = fv0;
                s.uv[1][0] = fu;
                s.uv[2][0] = fu2;
                s.uv[2][1] = fv0;
                fv0 = fv0 + 0.05f;
                s.uv[1][1] = fv0;
                s.uv[3][0] = fu2;
                s.uv[3][1] = fv0;
                func_003D2DA0(&s, 0, 0);
                s.uv[0][1] = fv1;
                s.uv[2][1] = fv1;
                s.uv[1][0] = fu;
                s.uv[0][0] = fu;
                s.uv[3][0] = fu2;
                s.uv[2][0] = fu2;
                fv1 = fv1 + 0.05f;
                s.uv[1][1] = fv1;
                s.uv[3][1] = fv1;
                func_003D2DA0(&s, 0, 0);
            }
        }
        fu = fu + 0.066667f;
    }
}
