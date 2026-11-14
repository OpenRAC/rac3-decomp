#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L33_00352A08 */
extern s32 func_0038CAD0(void *);
extern void func_L01_0044ABD0(void *, void *);
extern s32 func_L01_00447490(void *, s32, s32);
extern void func_003C4A40(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038CF00(void *, void *);
extern s32 func_L30_0034D8D8(void *, f32);
extern s32 func_00382380(void *, s32, s32);
extern void func_L33_00352760(s32, s32, s32);
extern void func_003C2880(void *);
extern void func_L30_0034C8A8(void *, void *);
extern void func_L33_00352ED0(void *, s32);
extern u8 D_001A4BE0[];
extern s32 D_L33_001E1878;
__asm__(".extern D_L33_001E1878, 16");
extern f32 D_L33_001DD8F0[2];
__asm__(".extern D_L33_001DD8F0, 8");
extern f32 D_L33_001DD910[2];
__asm__(".extern D_L33_001DD910, 8");
extern f32 D_L33_001DD920[2];
__asm__(".extern D_L33_001DD920, 8");
extern f32 D_L33_001DD9C0[2];
__asm__(".extern D_L33_001DD9C0, 8");
extern f32 D_L33_001DD9F0[2];
__asm__(".extern D_L33_001DD9F0, 8");
extern f32 D_L33_001DDA00[2];
__asm__(".extern D_L33_001DDA00, 8");
extern f32 D_L33_001DDB08[2];
__asm__(".extern D_L33_001DDB08, 8");
extern f32 D_L33_001DDA0C;
__asm__(".extern D_L33_001DDA0C, 4");
extern f32 D_L33_001DDACC;
__asm__(".extern D_L33_001DDACC, 4");

void func_L33_00352A08(u8 *a0) {
    vu0_v4 v;
    u8 *s1 = *(u8 **)(a0 + 0x68);
    s32 idx = 0x1761 - *(s16 *)(a0 + 0xAA);
    u8 *s0;
    u8 *p;
    u8 t;

    func_0038CAD0(s1 + 0xB0);
    func_0038CAD0(s1 + 0x74);
    t = a0[0x20];
    if (t != 0x42 && t != 2) {
        func_0038CAD0(s1 + 0xA8);
    }
    func_L01_0044ABD0(a0, s1 + 0x40);
    s0 = (u8 *)func_L01_00447490(a0, 0x10000, 0);
    if (s0 != 0) {
        f32 dmg;
        a0[0xA8] = 0xFF;
        dmg = *(f32 *)(s0 + 0x2C);
        if (0.0f < dmg) {
            p = *(u8 **)(s0 + 0x20);
            if (p == 0 || *(s16 *)(p + 0xAA) != 0x174B) {
                t = a0[0x20];
                if (t != 0x42 && t != 2 && *(s32 *)(s1 + 0x74) <= 0) {
                    s1[0x49] = 0;
                    s1[0x48] = 0;
                    *(s32 *)(s1 + 0x74) = 0xC;
                    s1[0x47] = 0xFF;
                    *(f32 *)s1 = *(f32 *)s1 - dmg;
                    func_003C4A40(a0, s1 + 0x40);
                    if (*(f32 *)s1 <= 0.0f) {
                        p = *(u8 **)(s0 + 0x20);
                        if (p != 0 && *(s16 *)(p + 0xAA) == 0x173F) {
                            func_0038CF68(&v, s0 + 0x10, D_L33_001DDA0C);
                            *(s32 *)(s1 + 0xA8) = 1;
                        } else {
                            func_0038CF68(&v, s0 + 0x10, func_003824E0(D_L33_001DD920[idx], D_L33_001DD910[idx]));
                        }
                        v.z += fabs_asm(v.x) / D_L33_001DD8F0[idx];
                        vec_add_ab(s1 + 0x60, s1 + 0x60, &v);
                        func_L33_00352ED0(a0, 2);
                    } else {
                        func_0038CF68(&v, s0 + 0x10, func_003824E0(D_L33_001DDA00[idx], D_L33_001DD9F0[idx]));
                        v.z += fabs_asm(v.x) / D_L33_001DD9C0[idx];
                        vec_add_ab(s1 + 0x60, s1 + 0x60, &v);
                        func_L33_00352ED0(a0, 4);
                    }
                }
            }
        }
    }
    *(s32 *)(s1 + 0x64) = 0;

    t = a0[0x20];
    if (t != 7 && t != 8 && t != 0xF) {
        *(f32 *)(a0 + 0x14) = *(f32 *)(D_001A4BE0 + 0x84);
    }
    if (func_0038CF00(D_001A4BE0 + 0x80, a0 + 0x10) < D_L33_001DDB08[idx]) {
        t = a0[0x20];
        if (t == 0x42) goto end;
        if (t != 2) {
            u8 *h = D_001A4BE0;
            if (*(f32 *)(h + 0x80) < *(f32 *)(a0 + 0x10)) {
                if (0.0f < *(f32 *)(h + 0xF0)) {
                    *(f32 *)(h + 0x100) -= *(f32 *)(h + 0xF0);
                }
            } else {
                if (*(f32 *)(h + 0xF0) < 0.0f) {
                    *(f32 *)(h + 0x100) -= *(f32 *)(h + 0xF0);
                }
            }
        }
    }
    t = a0[0x20];
    if (t != 0x42 && t != 0 && (*(s32 *)(s1 + 0x70) & 1)
        && func_L30_0034D8D8(a0 + 0x10, D_L33_001DDACC) == 0) {
        if (func_00382380(D_001A4BE0 + 0x80, *(s32 *)(s1 + 0xA0), 0) == 0
            || func_00382380(a0 + 0x10, *(s32 *)(s1 + 0xA0), 0) == 0) {
            func_L33_00352760(0, *(s16 *)(a0 + 0xAA), 0);
            func_003C2880(a0);
            return;
        }
    }
end:
    if (*(s32 *)(s1 + 0xA8) != 0) {
        func_L30_0034C8A8(&D_L33_001E1878, a0);
    }
}
/* localdecomp:end func_L33_00352A08 */

/* localdecomp:start func_L33_00352E08 */
extern f32 func_003C3D30(void *, s32, s32, f32);

s32 func_L33_00352E08(u8 *a0, s32 a1, s32 a2, s32 a3) {
    u8 *s1 = *(u8 **)(a0 + 0x68);
    vu0_v4 v __attribute__((aligned(16)));
    f32 d;
    f32 y;

    if (a2 == 0 && a3 != 0) {
        return 0;
    }
    qzero(&v);
    d = *(f32 *)(s1 + 0xB8) * (*(f32 *)(s1 + 0xB8) + *(f32 *)(s1 + 0xB4)) / *(f32 *)(s1 + 0xB4);
    if (a1 != 0) {
        d = -d;
    }
    v.x = d;
    v.z += 0.5f;
    vec_add_ba(&v, &v, a0 + 0x10);
    y = func_003C3D30(&v, 0, 0, 0.5f);
    return fabs_asm(v.x - *(f32 *)(a0 + 0x10)) <= fabs_asm(y - *(f32 *)(a0 + 0x18));
}
/* localdecomp:end func_L33_00352E08 */
