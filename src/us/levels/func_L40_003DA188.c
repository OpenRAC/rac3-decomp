#include "common.h"

/* NTSC-U counterpart of func_L40_003DA390 (src/levels/shared/L40_003DA2D0.c): 17 -> 20 */
typedef int u128_t_003DA350 __attribute__((mode(TI)));
typedef union {
    u128_t_003DA350 q;
    f32 f[4];
} V_003DA350;

/* localdecomp:start func_L40_003DA188 */
#include "vu0.h"

extern u8 *D_L40_002497C0;
__asm__(".extern D_L40_002497C0, 4");
extern void func_003886E8(void *, void *, f32);
extern s32 func_L40_003D9C70(void *, void *);
extern s32 func_L39_005B2498(s32);
extern void func_L40_003D9B20(void *, void *);
extern s32 func_003883C8(void *);
extern void func_L40_003DAE40(u8 *);
extern void func_003C7CE0(u8 *);
extern f32 func_L01_00442098(f32, f32, f32, f32, f32);
extern f32 func_L39_005B2568(f32, f32);
extern u8 *func_L01_00469378(void *, s32, s32, s32);
extern void func_L40_003DA0C8(void);
extern s32 func_L40_003DA148(V_003DA350 *a0, f32 radius);

void func_L40_003DA188(u8 *self) {
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
    if (func_L40_003DA148((V_003DA350 *)(t + 0xA0), 48.0f) == 0) {
        return;
    }
    if (D_L40_002497C0 == self) {
        func_L40_003DA0C8();
    }
    if (m[0x42] != 0) {
        func_003886E8(self + 0x10, t + 0x250, -0.75f);
        vec_add_ab(self + 0x10, t + 0xA0, self + 0x10);
        *(f32 *)(self + 0xFC) = 0.5235988f;
        if (func_L40_003D9C70(self, t) != 0 && func_L39_005B2498(5) == 0) {
            func_L40_003D9B20(self, t);
        }
    }
    if (func_003883C8(m + 0x40) != 0) {
        func_L40_003DAE40(self);
        return;
    }
    func_003886E8(&v20, t + 0x250, -0.75f);
    vec_add_ab(&v20, t + 0xA0, &v20);
    slot = (u8 **)(m + 0x30);
    for (i = 3; i >= 0; i--, slot++) {
        c = *slot;
        if (c == 0) {
            continue;
        }
        d = c + 0x20;
        if (func_003883C8(d + 0x1E) != 0) {
            if (m[0x42] == 0 && D_L40_002497C0 != 0) {
                m[0x42] = 1;
            }
            func_003C7CE0(c);
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
        *(f32 *)(c + 0x10) = func_L01_00442098(vB.x, vA.x, v20.x, vC.x, ratio);
        *(f32 *)(c + 0x14) = func_L01_00442098(vB.y, vA.y, v20.y, vC.y, ratio);
        *(f32 *)(c + 0x18) = func_L01_00442098(vB.z, vA.z, v20.z, vC.z, ratio);
        v40.x = func_L39_005B2568(0.0f, 0.01f) + *(f32 *)(c + 0x10);
        v40.y = func_L39_005B2568(0.0f, 0.01f) + *(f32 *)(c + 0x14);
        v40.z = func_L39_005B2568(0.0f, 0.01f) + *(f32 *)(c + 0x18);
        p = func_L01_00469378(&v40, 0x14, 0, 0);
        if (p != 0) {
            *(s32 *)(p + 4) = 0x7F7F4040;
            *(f32 *)(p + 0xC) = 10000.0f;
        }
    }
}
/* localdecomp:end func_L40_003DA188 */
