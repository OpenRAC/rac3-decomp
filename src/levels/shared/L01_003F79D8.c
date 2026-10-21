#include "common.h"

typedef struct {
    f32 v[4];
} V4_003F5ED8;
typedef int u128_3F6DA0 __attribute__((mode(TI)));
typedef struct {
    f32 x, y, z, w;
} V_003F6ED8;

INCLUDE_ASM("asm/levels", func_L01_003F79D8);

INCLUDE_ASM("asm/levels", func_L01_003F7CE0);

INCLUDE_ASM("asm/levels", func_L01_003F7EE8);

/* localdecomp:start func_L01_003F8080 */
extern s32 func_L01_003F8F98(f32 *v, f32 *a, f32 *b, f32 scale, f32 min);
extern void func_L01_003F8620(u8 *self);
extern void func_L01_003F8480(u8 *self);
extern s32 func_L01_003F8820(u8 *self);
extern void func_0038CF68(void *a, void *b, f32 s);
extern void func_0038CE90(void *out, void *m, void *v);
extern void func_L01_003F8E78(u8 *self, void *a, void *b);
extern void func_003C5180(void *a, void *b, s32 c);

extern s32 func_003A52A0(s32 a, s32 b, u8 *c);
extern void func_L01_003F8B30(u8 *self, s32 a, void *b);
extern void func_L01_004AAFD0(s32 a, void *b);
extern u8 D_L01_001EAA40[];

s32 func_L01_003F8080(u8 *self) {
    V4_003F5ED8 a;
    V4_003F5ED8 b;
    u8 *v;
    u8 st;
    s32 idx;
    s32 h;

    v = *(u8 **)(self + 104);
    st = v[92];
    if (st >= 3) {
        return 1;
    }
    if (st != 0) {
        func_L01_003F8620(self);
    } else {
        func_L01_003F8480(self);
    }
    idx = func_L01_003F8820(self);
    if (idx != -1) {
        h = -1;
        func_0038CF68(D_L01_001EAA40, D_L01_001EAA40, 1.0f);
        func_0038CE90(&a, D_L01_001EAA40, v);
        func_L01_003F8E78(self, v + 16, &a);
        func_003C5180(self + 16, &b, 1);
        if (((s32 (*)(void *a, void *b, void *c, f32 d, f32 e))func_L01_003F8F98)(v, D_L01_001EAA40, &b, *(f32 *)(v + 56), *(f32 *)(v + 60)) == 0) {
            if (v[94] != 255 && v[92] == 0) {
                h = func_003A52A0(v[94], 0, self);
            }
            func_L01_003F8B30(self, idx, &b);
        } else if (v[94] != 255) {
            h = func_003A52A0(v[94], 0, self);
        }
        if (h != -1) {
            func_L01_004AAFD0(h, v + 32);
        }
    }
    return 0;
}
/* localdecomp:end func_L01_003F8080 */

INCLUDE_ASM("asm/levels", func_L01_003F8208);

/* localdecomp:start func_L01_003F8470 */
s32 func_L01_003F8470(void) {
    return 1;
}
/* localdecomp:end func_L01_003F8470 */

/* localdecomp:start func_L01_003F8478 */
s32 func_L01_003F8478(void) {
    return 1;
}
/* localdecomp:end func_L01_003F8478 */

INCLUDE_ASM("asm/levels", func_L01_003F8480);

INCLUDE_ASM("asm/levels", func_L01_003F8550);

INCLUDE_ASM("asm/levels", func_L01_003F8620);

INCLUDE_ASM("asm/levels", func_L01_003F8820);

INCLUDE_ASM("asm/levels", func_L01_003F8A90);

INCLUDE_ASM("asm/levels", func_L01_003F8B30);

INCLUDE_ASM("asm/levels", func_L01_003F8BE0);

INCLUDE_ASM("asm/levels", func_L01_003F8E78);

/* localdecomp:start func_L01_003F8F48 */
extern f32 func_0038CE68(f32 *, f32 *);
extern void func_0038CF68(void *a, void *b, f32 s);
extern void func_003C4CE8(u8 *a0, void *a1, f32 f12);
void func_L01_003F8F48(s32 a0, u8 *a1, u8 *a2) {
    u128_3F6DA0 tmp;
    ((void (*)(void *a0, u8 *a1, f32 f12))func_0038CF68)(&tmp, a2, 1.0f);
    func_003C4CE8(a1, &tmp, ((f32 (*)(void *a0, u8 *a1))func_0038CE68)(&tmp, a1));
}
/* localdecomp:end func_L01_003F8F48 */

/* localdecomp:start func_L01_003F8F98 */
extern void func_0038CF68(void *a, void *b, f32 s);
extern void func_L01_0040E790(f32 *, f32 *, f32 *);
extern f32 func_0038CEA8(f32 *);
extern f32 func_0038CE68(f32 *, f32 *);
extern void func_003C4138(f32 *, f32, f32);
s32 func_L01_003F8F98(f32 *v, f32 *a, f32 *b, f32 scale, f32 min) {
    f32 len;
    f32 hi;
    func_L01_0040E790(v, v, a);
    len = func_0038CEA8(v);
    if (0.7f < func_0038CE68(b, a)) {
        hi = len * scale;
        if (hi < min) {
            hi = min;
        }
        func_003C4138(&len, 0.0f, hi);
        ((void (*)(f32 *, f32 *, f32))func_0038CF68)(v, v, len);
    }
    return len != 0.0f;
}
/* localdecomp:end func_L01_003F8F98 */

/* localdecomp:start func_L01_003F9080 */
extern void func_0038CE20(V_003F6ED8 *, V_003F6ED8 *, f32);
s32 func_L01_003F9080(u8 *m, V_003F6ED8 *out, s32 max) {
    u8 *p;
    s16 *src;
    s32 n;
    s32 i;
    f32 scale;
    p = *(u8 **)(*(u8 **)(m + 36) + 16);
    if (p == 0) {
        return 0;
    }
    n = *(s32 *)(p + 12) / 8;
    src = (s16 *)(p + *(s32 *)(p + 4) + 16);
    if (max < n) {
        n = max;
    }
    scale = *(f32 *)(m + 44) * 0.0009765625f;
    for (i = 0; i < n; i++) {
        out[i].x = src[0];
        out[i].y = src[1];
        out[i].z = src[2];
        src += 4;
        func_0038CE20(&out[i], &out[i], scale);
        out[i].w = 1.0f;
    }
    return n;
}
/* localdecomp:end func_L01_003F9080 */
