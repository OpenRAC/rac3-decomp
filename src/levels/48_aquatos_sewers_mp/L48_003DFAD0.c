#include "common.h"

/* localdecomp:start func_L48_003DFAD0 */
#include "vu0.h"
typedef struct { f32 x, y; } F2_3DFAD0;
typedef struct { f32 x, y, z; } F3_3DFAD0;
typedef struct {
    u8 p0[3]; u8 b3; u8 p4[4];
    u8 col0[4]; u8 col1[4];
    s32 w10; s32 w14; f32 f18; s32 tex1C; f32 f20; u8 p24[4]; f32 f28; f32 f2C;
    u8 p30[0x20]; s32 w50;
} S_3DFAD0;
typedef struct { u8 p0[0x68]; S_3DFAD0 *s; } M_3DFAD0;
typedef struct { u8 p0[0x140]; f32 x, y, z; } C_3DFAD0;
typedef struct { u8 p0[0x238]; f32 f238; f32 f23C; } G_3DFAD0;
__asm__(".extern D_L48_002412DC, 16");
extern s32 D_L48_002412DC;
__asm__(".extern D_L48_002424A8, 16");
extern u8 D_L48_002424A8;
extern G_3DFAD0 D_L48_00259500;
extern C_3DFAD0 D_L48_00249A00;
extern vu0_v4 D_L48_00249B40;
extern F2_3DFAD0 D_L48_00246A40[1];
__asm__(".extern D_L48_00246A40, 8");
extern F2_3DFAD0 D_L48_00246A60[1];
__asm__(".extern D_L48_00246A60, 8");
extern f32 D_L48_002469B0[2];
__asm__(".extern D_L48_002469B0, 8");
extern f32 D_L48_002469C0[2];
__asm__(".extern D_L48_002469C0, 8");
extern f32 D_L48_00246A10[2];
__asm__(".extern D_L48_00246A10, 8");
extern f32 D_L48_00246A20[2];
__asm__(".extern D_L48_00246A20, 8");
extern f32 D_L48_00246A30[2];
__asm__(".extern D_L48_00246A30, 8");
extern F3_3DFAD0 D_L48_003973A0[];
extern s32 D_L48_00249330[] __attribute__((section(".sdata")));
extern F2_3DFAD0 D_L48_00249310[1];
extern F2_3DFAD0 D_L48_00397B30[];
extern f32 D_L48_00397460[][2];
extern f32 D_L48_00397640[];
extern F3_3DFAD0 D_L48_00397730[];
extern s32 D_L48_00397A30[];
extern F2_3DFAD0 D_L48_00397BB0[];
extern void func_003A9440(s32, unsigned long);
extern long func_L39_00589890(s32);
extern void func_0038C750(void);
extern void func_L02_00326FC0(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CC88(void *, void *, s32);
extern void func_003D3A24(s32, void *, void *, void *, s32);
extern s32 func_0038DBD8(u32, u32, f32);

/* from func_L02_00327038 (src/levels/shared/L02_00326C90.c), the same routine in 18 single-player levels */
void func_L48_003DFAD0(M_3DFAD0 *m) {
    S_3DFAD0 *s;
    vu0_v4 t;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 v[4];
    vu0_v4 d0;
    vu0_v4 d1;
    vu0_v4 u;
    u32 ca;
    u32 cb;
    f32 *sc;
    F2_3DFAD0 *tbl;
    F2_3DFAD0 *o;
    f32 (*g)[2];
    f32 save23C;
    f32 save238;
    f32 dist;
    f32 size;
    f32 r;
    f32 h;
    f32 k;
    f32 f;
    f32 uvs;
    f32 xys;
    s32 i;
    s32 j;
    s32 n;

    if (D_L48_002412DC == 5) return;
    save238 = D_L48_00259500.f238;
    save23C = D_L48_00259500.f23C;
    s = m->s;
    if (D_L48_002424A8 == 0) {
        D_L48_00259500.f238 = 255.0f;
        D_L48_00259500.f23C = 249.9f;
    }
    func_003A9440(0x42, 0x3200000044UL);
    func_003A9440(8, 0);
    func_003A9440(0x14, 0xFF9000000260UL);
    if (s->b3 & 0x80) {
        func_003A9440(0x47, 0x5310B);
    } else {
        func_003A9440(0x47, 0x513F1);
    }
    func_003A9440(6, func_L39_00589890(0x16));
    func_0038C750();
    func_L02_00326FC0(&a, &b);
    tbl = D_L48_00246A40;
    if (D_L48_00249A00.z - s->f20 > 200.0f) {
        tbl = D_L48_00246A60;
    }
    for (i = 0; i < 4; i++) {
        func_0038CE20(&v[i], &a, tbl[i].x);
        func_0038CE20(&t, &b, tbl[i].y);
        if (i & 1) {
            func_0038CE20(&u, &a, s->f28);
            vec_add_ab(&t, &u, &t);
        }
        vec_add_ab(&v[i], &v[i], &t);
    }
    for (i = 0; i < 4; i++) {
        vec_add_ab(&v[i], &v[i], &D_L48_00249B40);
        v[i].z = s->f2C;
    }
    vec_sub_ba(&d0, &v[1], &v[0]);
    vec_sub_ab(&d1, &v[3], &v[2]);
    for (i = 0; i < 12; i += 2) {
        f = i;
        f /= 10.0f;
        func_0038CE20(&t, &d0, f);
        vec_add_ab(&t, &t, &v[0]);
        func_0038CC88(&D_L48_003973A0[i], &t, 12);
        func_0038CE20(&t, &d1, f);
        vec_add_ab(&t, &t, &v[2]);
        func_0038CC88(&D_L48_003973A0[i + 1], &t, 12);
    }
    func_003D3A24(12, D_L48_003973A0, D_L48_00249330, D_L48_00397B30, 1);
    ca = (s->col0[3] << 24) | (s->col0[2] << 16) | (s->col0[1] << 8) | s->col0[0];
    cb = (s->col1[3] << 24) | (s->col1[2] << 16) | (s->col1[1] << 8) | s->col1[0];
    if (s->w10 != 0 && s->w14 >= 3) {
        sc = D_L48_002469C0;
    } else {
        sc = D_L48_002469B0;
    }
    if (s->w10 != 0) {
        func_003A9440(6, func_L39_00589890(s->tex1C + 100));
    } else {
        func_003A9440(0x42, 0x8000000048UL);
    }
    func_003A9440(8, 0);
    func_003A9440(0x14, 0xFF9000000260UL);
    func_003A9440(0x47, 0x513F1);
    dist = fabs_asm(D_L48_00249A00.z - s->f2C);
    r = s->f18;
    size = r * 2.5f;
    if (dist < 10.0f) {
        dist = 10.0f;
    }
    if (s->b3 & 0x80) {
        h = dist * r * 2e-5f * 1.05f;
        if (h < 0.15f) h = 0.15f;
    } else {
        h = dist * r * 2e-5f;
        if (h < 0.125f) h = 0.125f;
    }
    if (D_L48_00249A00.z < s->f2C) {
        h = -h;
    }
    for (j = 0; j < s->w14; j++) {
        if (D_L48_00246A10[j] < dist) continue;
        k = (1.0f - dist / D_L48_00246A10[j]) * D_L48_00246A20[j];
        if (1.0f < k) {
            k = 1.0f;
        } else if (k < 0.0f) {
            k = 0.0f;
        }
        cb = (cb & 0xFFFFFF) | ((s32)(s->col1[3] * k) << 24);
        if (s->w10 != 0 && (j & 1)) {
            ((u8 *)&ca)[3] = 0;
            ((u8 *)&cb)[3] = 0;
        } else {
            ((u8 *)&ca)[3] = s->col0[3];
            ((u8 *)&cb)[3] = s->col1[3];
        }
        if (s->w10 != 0) {
            if ((s->w14 & 1) && j == s->w14 - 1) continue;
            if (j & 1) {
                if (s->w50 != 0) {
                    func_003A9440(0x42, 0x8000000051UL);
                } else {
                    func_003A9440(0x42, 0x8000000058UL);
                }
            } else {
                func_003A9440(0x42, 0x800000006AUL);
            }
        } else {
            func_003A9440(6, func_L39_00589890(s->tex1C + 100 + j));
        }
        uvs = sc[j] / size;
        xys = D_L48_00246A30[j];
        o = &D_L48_00249310[j];
        g = D_L48_00397460;
        for (n = 0; n < 60; n++) {
            s32 c = func_0038DBD8(cb, ca, D_L48_00397640[n] * k);
            f32 x = g[n][0];
            f32 y = g[n][1];
            D_L48_00397A30[n] = c;
            D_L48_00397BB0[n].x = x * uvs + o->x;
            D_L48_00397BB0[n].y = y * uvs + o->y;
            D_L48_00397730[n].x = x * xys + D_L48_00249A00.x;
            D_L48_00397730[n].y = y * xys + D_L48_00249A00.y;
            D_L48_00397730[n].z = s->f2C + h;
        }
        func_003D3A24(60, D_L48_00397730, D_L48_00397A30, D_L48_00397BB0, 1);
    }
    D_L48_00259500.f238 = save238;
    D_L48_00259500.f23C = save23C;
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L48_003DFAD0 */
