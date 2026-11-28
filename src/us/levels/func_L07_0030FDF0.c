#include "common.h"
/* localdecomp:start func_L07_0030FDF0 */
#include "vu0.h"
#include "vu0.h"
typedef struct {
    vu0_v4 dir;
    void *owner;
    s32 flags;
    u8 a;
    u8 b;
    u16 id;
    f32 f;
    s32 g;
} Hit_00310160;
typedef union {
    Hit_00310160 hit;
    vu0_v4 v[4];
} U_00310160;
extern u8 *D_L07_001ECC80[];
typedef struct {
    f32 w[0x1C];
    f32 f70;
    s32 t74;
    f32 f78;
    u8 b7C;
} S_00310160;
typedef struct { u8 p0[0x25C0]; u8 *moby; } H_00310160;
extern H_00310160 D_001A4BE0;
extern f32 func_00389410(f32);
extern f32 func_00388960(f32);
extern f32 func_00388978(f32);
extern void func_0037E4B8(void *, f32, f32, f32);

static inline f32 Angle_00310160(u8 *e, u8 *m) {
    extern f32 func_00388A28(f32, f32);
    return func_00388A28(*(f32 *)(e + 0x10) - *(f32 *)(m + 0x10), *(f32 *)(e + 0x14) - *(f32 *)(m + 0x14));
}

void func_L07_0030FDF0(void *arg0, void *arg1) {
    extern s32 func_003CF790(f32, void *, s32, void *, s32);
    extern f32 func_00388A28(f32, f32);
    extern f32 func_00389468(f32, f32);
    extern f32 func_L01_0040C040(void *, void *);
    extern void func_L01_00443840(void *, void *);
    extern f32 func_00389380(f32, f32);
    extern void func_L01_00452F40(void *, s32);
    extern s32 func_003CE740(void *, void *, s32, void *, s32);
    U_00310160 tmp;
    u8 *m = arg0;
    S_00310160 *s = arg1;
    f32 r;
    f32 dz;
    f32 lim;
    f32 ang;
    f32 sgn;
    f32 a0;
    f32 a1;
    s32 n;
    s32 i;
    s32 k;
    s32 j;

    r = s->f70 * s->f78;
    if (r < 0.75f) {
        r = 0.75f;
    }
    n = func_003CF790(r, m + 0x10, 0x10, *(void **)(m + 0xB8), 0);
    for (i = 0; i < n; i++) {
        if (D_L07_001ECC80[i] == *(u8 **)(m + 0xB8)) {
            continue;
        }
        if (s->f78 > 0.0f) {
            if (0.7417649f < func_00389468(Angle_00310160(D_L07_001ECC80[i], m),
                                           *(f32 *)(m + 0xF8))) continue;
            dz = *(f32 *)(D_L07_001ECC80[i] + 0x18) - *(f32 *)(m + 0x18);
            if (0.2f < dz) {
                continue;
            }
            if (dz < -2.0f) {
                continue;
            }
            lim = r * 0.95f;
            if (func_L01_0040C040(m + 0x10, D_L07_001ECC80[i] + 0x10) < lim * lim) {
                continue;
            }
        }
        tmp.hit.owner = *(void **)(m + 0xB8);
        tmp.hit.flags = 0x430001;
        tmp.hit.f = s->b7C;
        tmp.hit.g = 0x430000;
        tmp.hit.a = 2;
        tmp.hit.b = 3;
        tmp.hit.id = *(u16 *)(m + 0xAA);
        ang = Angle_00310160(D_L07_001ECC80[i], m);
        tmp.hit.dir.x = func_00388960(ang);
        tmp.hit.dir.y = func_00388978(ang);
        tmp.hit.dir.z = 1.0f;
        tmp.hit.dir.w = 5627.9248f;
        if (D_L07_001ECC80[i] == D_001A4BE0.moby) {
            func_L01_00452F40(*(void **)(m + 0xB8), 1);
        }
        func_L01_00443840(D_L07_001ECC80[i], &tmp.hit);
    }
    for (k = 0; k < 2; k++) {
        sgn = (k & 1) ? 1.0f : -1.0f;
        j = 0;
        do {
            vu0_q qp, qv;
            a0 = func_00389410(j * sgn * 0.69813168f / 5.0f);
            a1 = func_00389410((j + 1) * sgn * 0.69813168f / 5.0f);
            func_0037E4B8(&tmp.v[0], r, func_00389380(a0, *(f32 *)(m + 0xF8)), -*(f32 *)(m + 0xF4));
            func_0037E4B8(&tmp.v[1], r, func_00389380(a1, *(f32 *)(m + 0xF8)), -*(f32 *)(m + 0xF4));
            __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(*(vu0_v4 *)(m + 0x10)));
            __asm__("lqc2 %0, %1" : "=j"(qv) : "m"(tmp.v[0]));
            *(vu0_q *)&tmp.v[3] = qp;
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qv) : "j"(qv), "j"(qp));
            __asm__("sqc2 %1, %0" : "=m"(tmp.v[0]) : "j"(qv));
            *(vu0_q *)&tmp.v[2] = qv;
            __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(tmp.v[1]));
            __asm__("lqc2 %0, %1" : "=j"(qv) : "m"(tmp.v[3]));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qp) : "j"(qp), "j"(qv));
            __asm__("sqc2 %1, %0" : "=m"(tmp.v[1]) : "j"(qp));
            *(vu0_q *)&tmp.v[2] = qp;
            if (func_003CE740(&tmp.v[0], &tmp.v[1], 0x12, *(void **)(m + 0xB8), 0) != 0) {
                func_0037E4B8(&tmp.v[2], 0.333333343f, *(f32 *)(m + 0xF8), -*(f32 *)(m + 0xF4));
            }
            j++;
        } while (j < 5);
    }
}
/* localdecomp:end func_L07_0030FDF0 */
