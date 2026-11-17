#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L19_003C9F00 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3C9F00;
typedef struct { V_3C9F00 v[4]; } R_3C9F00;
typedef struct { u8 pad[0x30]; V_3C9F00 v; u8 pad2[0x40]; } P_3C9F00;
extern R_3C9F00 D_L19_002BDEB0[];
extern R_3C9F00 D_L19_002BDED0[];
extern R_3C9F00 D_L19_002BDEC0[];
extern P_3C9F00 *D_L19_001DF800;
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038D570(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);

static __inline__ V_3C9F00 vsub_3C9F00(void *a, void *b) {
    V_3C9F00 r;
    vec_sub_ba(&r, a, b);
    return r;
}

static __inline__ V_3C9F00 vadd_3C9F00(void *a, void *b) {
    V_3C9F00 r;
    vec_add_ab(&r, a, b);
    return r;
}

void func_L19_003C9F00(V_3C9F00 *obj, s32 idx) {
    V_3C9F00 p0;
    V_3C9F00 p1;
    R_3C9F00 m;
    V_3C9F00 d;
    s32 a;

    a = func_00382498(0, 5);
    switch (func_00382498(0, 3)) {
    case 0:
        p0 = D_L19_002BDEB0[a].v[0];
        p1 = *(V_3C9F00 *)((a << 6) + 0x10 + (u8 *)D_L19_002BDEB0);
        break;
    case 1:
        p0 = D_L19_002BDEB0[a].v[0];
        p1 = *(V_3C9F00 *)((a << 6) + 0x20 + (u8 *)D_L19_002BDEB0);
        break;
    case 2:
        p0 = D_L19_002BDED0[a].v[0];
        p1 = *(V_3C9F00 *)((a << 6) + 0x10 + (u8 *)D_L19_002BDED0);
        break;
    case 3:
        p0 = D_L19_002BDEC0[a].v[0];
        p1 = *(V_3C9F00 *)((a << 6) + 0x20 + (u8 *)D_L19_002BDEC0);
        break;
    }
    func_0038D570(&m, &D_L19_001DF800[idx]);
    m.v[3] = D_L19_001DF800[idx].v;
    m.v[3].w = 1.0f;
    d = vsub_3C9F00(&p1, &p0);
    func_0038CE20(&d, &d, func_003824E0(0.0f, 1.0f));
    *obj = vadd_3C9F00(&p0, &d);
    func_0038D028(obj, obj, &m);
}
/* localdecomp:end func_L19_003C9F00 */

/* localdecomp:start func_L19_003CA0A8 */
typedef int u128_t_3CA0A8 __attribute__((mode(TI)));
typedef struct {
    u128_t_3CA0A8 m[4];
    s32 c40, c44, c48, c4C;
    f32 uv[8];
    long x70, x78, x80, x88;
    f32 r[4][4];
} S_3CA0A8;
extern void func_0038D570(void *, void *);
extern long func_00389598(s32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_003D2DA0(S_3CA0A8 *, f32 *, s32);

void func_L19_003CA0A8(u8 *obj) {
    u8 *d = *(u8 **)(obj + 0x68);
    u8 *e;
    S_3CA0A8 s;
    f32 f;
    f32 cx;
    f32 sy;
    f32 a;
    f32 b;
    s32 color;
    s32 i;

    e = (u8 *)D_L19_001DF800 + *(s32 *)d * 0x80;
    func_0038D570(s.r[0], e);
    *(u128_t_3CA0A8 *)s.r[3] = *(u128_t_3CA0A8 *)(e + 0x30);
    s.r[3][3] = 1.0f;
    f = *(f32 *)(d + 4);
    color = ((s32)(f * 20.0f) << 24) | (d[0x1E] << 16) | (d[0x1D] << 8) | d[0x1C];
    f = f * f;
    f = f * 0.2f;
    cx = func_0038D098(*(f32 *)(d + 0x10)) * 0.08f;
    sy = func_0038D0B0(*(f32 *)(d + 0x10)) * 0.08f;
    s.x78 = func_00389598(0x1E);
    s.x80 = 0xFF9000000260L;
    s.x70 = 4;
    s.x88 = 0x8000000048L;
    s.uv[0] = (0.5f - f) + cx;
    s.uv[1] = (f + 0.5f) + sy;
    s.uv[2] = (f + 0.5f) - sy;
    s.uv[5] = (0.5f - f) - sy;
    s.uv[4] = (0.5f - f) - cx;
    s.uv[7] = (0.5f - f) - cx;
    s.c4C = color;
    s.c48 = color;
    s.c44 = color;
    s.uv[6] = (f + 0.5f) + sy;
    s.c40 = color;
    s.uv[3] = (f + 0.5f) + cx;
    for (i = 0; i < 6; i++) {
        *(R_3C9F00 *)s.m = D_L19_002BDEB0[i];
        func_003D2DA0(&s, s.r[0], 0);
    }
}
/* localdecomp:end func_L19_003CA0A8 */

/* localdecomp:start func_L19_003CA288 */
extern s32 D_001A7430[];
extern u8 D_001A30B0[];
extern s32 func_L01_004561B8(u8 *);
extern s32 func_003A52A0(s32, s32, u8 *);
extern void func_003A4F28(s32);
extern f32 func_0038CF38(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_0040E050(void *);
extern void func_003C4DA8(u8 *, void *, void *, void *);

void func_L19_003CA288(u8 *obj) {
    u8 *v = *(u8 **)(obj + 0x68);
    V_3C9F00 pos;
    V_3C9F00 f0;
    V_3C9F00 t;

    if (v == 0 || D_001A7430[0] <= 0)
        return;
    pos = *(V_3C9F00 *)(obj + 0x10);
    f0 = *(V_3C9F00 *)(obj + 0xF0);
    switch (obj[0x20]) {
    case 0: {
        s32 id;
        *(V_3C9F00 *)(v + 0x150) = pos;
        *(s32 *)(v + 0x144) = -1;
        id = *(s32 *)(v + 0x130);
        if (id != -1) {
            *(V_3C9F00 *)(v + 0x160) = D_L19_001DF800[id].v;
            func_L01_004450F0(obj, 1, -1);
        } else {
            func_L01_004450F0(obj, 3, -1);
        }
        break;
    }
    case 1:
        if (func_L01_004561B8(obj) != 0) {
            s32 id;
            u8 *e;
            id = *(s32 *)(v + 0x144);
            if (id == -1 || (e = D_001A30B0 + (id << 7), *(u8 **)(e + 0xDC) != obj) || e[0xD0] == 0)
                *(s32 *)(v + 0x144) = func_003A52A0(0, 4, obj);
        }
        if (func_0038CF38(obj + 0x10, v + 0x160) <= 0.88f) {
            t = *(V_3C9F00 *)(v + 0x150);
            *(V_3C9F00 *)(v + 0x150) = *(V_3C9F00 *)(v + 0x160);
            *(V_3C9F00 *)(v + 0x160) = t;
            *(f32 *)(v + 0x13C) = (*(f32 *)(v + 0x138) * 5.0f + 2.0f) / 6.0f;
            func_L01_004450F0(obj, 2, -1);
        } else {
            vec_sub_ba(&t, v + 0x160, obj + 0x10);
            func_0038CF68(&t, &t, *(f32 *)(v + 0x134) * 0.0200000014f);
            vec_add_ba(obj + 0x10, &t, obj + 0x10);
        }
        break;
    case 2:
        if (func_L01_004561B8(obj) != 0) {
            s32 id;
            u8 *e;
            id = *(s32 *)(v + 0x144);
            if (id != -1 && (e = D_001A30B0 + (id << 7), *(u8 **)(e + 0xDC) == obj) && e[0xD0] != 0)
                func_003A4F28(id);
            *(s32 *)(v + 0x144) = -1;
        }
        if (func_L01_0040E050(v + 0x13C) != 0)
            func_L01_004450F0(obj, 1, -1);
        break;
    }
    vec_sub_ba(&t, obj + 0x10, &pos);
    func_003C4DA8(v + 0x30, &t, &f0, obj + 0xF0);
}
/* localdecomp:end func_L19_003CA288 */
