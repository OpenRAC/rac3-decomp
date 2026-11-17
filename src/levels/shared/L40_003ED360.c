#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* declared by functions of L40_003EBB98.c, which this file was cut from */
extern f32 func_0038CF38(void *, void *);

/* localdecomp:start func_L40_003ED360 */
#include "vu0.h"

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V_003ED360;

extern u8 *D_L40_0025B980[];
extern V_003ED360 D_L40_0025B9A0;
extern f32 func_0038CF00(void *, void *);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CED8(void *);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038CF38(void *, void *);

void func_L40_003ED360(u8 *o) {
    u8 *v = *(u8 **)(o + 0x68);
    V_003ED360 a;
    V_003ED360 b;
    V_003ED360 c;
    V_003ED360 d;
    V_003ED360 e;
    f32 ang;
    f32 dir;
    f32 len;
    f32 r;
    f32 dist;
    u8 *p;

    *(u128_t *)(v + 0x260) = *(u128_t *)(v + 0x270);
    a = *(V_003ED360 *)(o + 0x10);
    b = *(V_003ED360 *)(v + 0x270);
    a.z += *(f32 *)(v + 0x78);
    b.z += *(f32 *)(v + 0x78);
    if (func_0038CF00(&a, &b) < 30.0f && func_003D3CB0(&a, &b, 0x10, o, 0) == 0) {
        return;
    }
    if (D_L40_0025B980[6] != 0 && D_L40_0025B980[6] == *(u8 **)(v + 0x230)) {
        return;
    }

    for (ang = 10.0f; ang <= 100.0f; ang += 10.0f) {
        vec_sub_ab(&d, &b, &a);
        dir = func_0038D160(d.x, d.y);
        len = func_0038CED8(&d);
        if (len < 15.0f) {
            len = 15.0f;
        }

        r = ang * 0.017453292f;
        c.x = func_0038D098(func_0038DAB8(r, dir)) * len;
        c.y = func_0038D0B0(func_0038DAB8(r, dir)) * len;
        c.z = 0.0f;
        vec_add_ab(&c, &a, &c);
        if (c.x < 0.0f) {
            c.x = 0.5f;
        }
        if (c.y < 0.0f) {
            c.y = 0.5f;
        }
        if (c.z < 0.0f) {
            c.z = 0.5f;
        }
        if (func_0038CF00(&a, &c) < 30.0f && func_003D3CB0(&a, &c, 0x10, o, 0) == 0) {
            *(V_003ED360 *)(v + 0x260) = c;
            return;
        }
        p = D_L40_0025B980[6];
        if (p != 0 && p == *(u8 **)(v + 0x230)) {
            *(V_003ED360 *)(v + 0x260) = c;
        } else if (p != 0 && *(s16 *)(p + 0xAA) == *(s16 *)(o + 0xAA)) {
            *(V_003ED360 *)(v + 0x260) = *(V_003ED360 *)(o + 0x10);
            return;
        }
        vec_sub_ab(&e, o + 0x10, &D_L40_0025B9A0);
        dist = func_0038CED8(&e);
        if (*(f32 *)(v + 0x2A8) < dist && ang < 60.0f &&
            func_0038CF38(&D_L40_0025B9A0, v + 0x270) < func_0038CF38(v + 0x290, v + 0x270)) {
            *(f32 *)(v + 0x2A8) = dist;
            *(V_003ED360 *)(v + 0x290) = D_L40_0025B9A0;
        }

        r = -(ang * 0.017453292f);
        c.x = func_0038D098(func_0038DAB8(r, dir)) * len;
        c.y = func_0038D0B0(func_0038DAB8(r, dir)) * len;
        c.z = 0.0f;
        vec_add_ab(&c, &a, &c);
        if (c.x < 0.0f) {
            c.x = 0.5f;
        }
        if (c.y < 0.0f) {
            c.y = 0.5f;
        }
        if (c.z < 0.0f) {
            c.z = 0.5f;
        }
        if (func_0038CF00(&a, &c) < 30.0f && func_003D3CB0(&a, &c, 0x10, o, 0) == 0) {
            *(V_003ED360 *)(v + 0x260) = c;
            return;
        }
        p = D_L40_0025B980[6];
        if (p != 0 && p == *(u8 **)(v + 0x230)) {
            *(V_003ED360 *)(v + 0x260) = c;
        } else if (p != 0 && *(s16 *)(p + 0xAA) == *(s16 *)(o + 0xAA)) {
            *(V_003ED360 *)(v + 0x260) = *(V_003ED360 *)(o + 0x10);
            return;
        }
        vec_sub_ab(&e, o + 0x10, &D_L40_0025B9A0);
        dist = func_0038CED8(&e);
        if (*(f32 *)(v + 0x2A8) < dist && ang < 60.0f) {
            *(f32 *)(v + 0x2A8) = dist;
            *(V_003ED360 *)(v + 0x290) = D_L40_0025B9A0;
        }
    }
}
/* localdecomp:end func_L40_003ED360 */
