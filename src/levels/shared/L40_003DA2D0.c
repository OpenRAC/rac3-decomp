#include "common.h"
typedef int u128_t_003DA350 __attribute__((mode(TI)));
typedef union {
    u128_t_003DA350 q;
    f32 f[4];
} V_003DA350;

/* localdecomp:start func_L40_003DA2D0 */
extern void func_0038D890(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern u8 D_L40_00249650[8];
extern u8 D_L40_00249690[8];

void func_L40_003DA2D0(void)
{
    u8 *p = D_L40_00249650;
    u8 *q = D_L40_00249690;
    s32 i;

    for (i = 3; i >= 0; i--) {
        func_0038D890(p, p, q, 0.0698131695f);
        q += 0x10;
        func_0038CF68(p, p, 0.25f);
        p += 0x10;
    }
}
/* localdecomp:end func_L40_003DA2D0 */

/* localdecomp:start func_L40_003DA350 */
extern s32 func_L39_005BE900(void *, s32, f32);

s32 func_L40_003DA350(V_003DA350 *a0, f32 radius) {
    V_003DA350 v;
    s32 r;

    v.q = a0->q;
    v.f[3] = 1.0f;
    r = func_L39_005BE900(&v, 0, radius);
    if (~r < 0) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L40_003DA350 */

/* localdecomp:start func_L40_003DA390 */
#include "vu0.h"

extern u8 *D_L40_00249640;
__asm__(".extern D_L40_00249640, 4");
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L40_003D9E78(void *, void *);
extern s32 func_L39_005B4398(s32);
extern void func_L40_003D9D28(void *, void *);
extern s32 func_0038CB00(void *);
extern void func_L40_003DB068(u8 *);
extern void func_003CD250(u8 *);
extern f32 func_L01_004451D0(f32, f32, f32, f32, f32);
extern f32 func_L39_005B4468(f32, f32);
extern u8 *func_L01_0046CA28(void *, s32, s32, s32);
extern void func_L40_003DA2D0(void);
extern s32 func_L40_003DA350(V_003DA350 *a0, f32 radius);

void func_L40_003DA390(u8 *self) {
    vu0_v4 vB;
    vu0_v4 vA;
    vu0_v4 v20;
    vu0_v4 vC;
    vu0_v4 v40;
    u8 *m;
    u8 *t;
    u8 *c;
    u8 *d;
    u8 **slot;
    u8 *p;
    s32 i;
    f32 ratio;
    f32 *src;

    m = *(u8 **)(self + 0x68);
    t = *(u8 **)(m + 0x4C);
    if (t == 0) {
        return;
    }
    if (func_L40_003DA350((V_003DA350 *)(t + 0xA0), 48.0f) == 0) {
        return;
    }
    if (D_L40_00249640 == self) {
        func_L40_003DA2D0();
    }
    if (m[0x42] != 0) {
        func_0038CE20(self + 0x10, t + 0x250, -0.75f);
        vec_add_ab(self + 0x10, t + 0xA0, self + 0x10);
        *(f32 *)(self + 0xFC) = 0.5235988f;
        if (func_L40_003D9E78(self, t) != 0 && func_L39_005B4398(5) == 0) {
            func_L40_003D9D28(self, t);
        }
    }
    if (func_0038CB00(m + 0x40) != 0) {
        func_L40_003DB068(self);
        return;
    }
    func_0038CE20(&v20, t + 0x250, -0.75f);
    vec_add_ab(&v20, t + 0xA0, &v20);
    slot = (u8 **)(m + 0x30);
    for (i = 3; i >= 0; i--, slot++) {
        c = *slot;
        if (c == 0) {
            continue;
        }
        d = c + 0x20;
        if (func_0038CB00(d + 0x1E) != 0) {
            if (m[0x42] == 0 && D_L40_00249640 != 0) {
                m[0x42] = 1;
            }
            func_003CD250(c);
            *slot = 0;
            continue;
        }
        ratio = 1.0f - (f32)*(s16 *)(d + 0x1E) / (f32)*(s16 *)(d + 0x1C);
        src = (f32 *)(c + 0x30);
        vA.x = src[0];
        vA.y = src[1];
        vA.z = src[2];
        vA.w = 0.0f;
        vB.x = vA.x - *(f32 *)(d + 0x4);
        vB.y = vA.y - *(f32 *)(d + 0x8);
        vB.z = vA.z - *(f32 *)(d + 0xC);
        vC.x = v20.x - *(f32 *)(d + 0x4);
        vC.y = v20.y - *(f32 *)(d + 0x8);
        vC.z = v20.z - *(f32 *)(d + 0xC);
        *(f32 *)(c + 0x10) = func_L01_004451D0(vB.x, vA.x, v20.x, vC.x, ratio);
        *(f32 *)(c + 0x14) = func_L01_004451D0(vB.y, vA.y, v20.y, vC.y, ratio);
        *(f32 *)(c + 0x18) = func_L01_004451D0(vB.z, vA.z, v20.z, vC.z, ratio);
        v40.x = func_L39_005B4468(0.0f, 0.01f) + *(f32 *)(c + 0x10);
        v40.y = func_L39_005B4468(0.0f, 0.01f) + *(f32 *)(c + 0x14);
        v40.z = func_L39_005B4468(0.0f, 0.01f) + *(f32 *)(c + 0x18);
        p = func_L01_0046CA28(&v40, 0x11, 0, 0);
        if (p != 0) {
            *(s32 *)(p + 4) = 0x7F7F4040;
            *(f32 *)(p + 0xC) = 10000.0f;
        }
    }
}
/* localdecomp:end func_L40_003DA390 */
