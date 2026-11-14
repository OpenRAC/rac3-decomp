#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L09_003DDEE0 */
#include "vu0.h"
extern void func_00382580(f32 *, f32, f32);
extern s32 func_00382468(s32);
extern s32 func_00382498(s32, s32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_003D8E60(void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern u8 *func_L01_00475C60(void *, void *, s32, s32, s32, s32, f32, f32, f32, s32);
extern void func_L01_003303B8(void *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u8 D_L09_00220018[];
__asm__(".extern D_L09_00220018, 16");

void func_L09_003DDEE0(f32 *p, s32 n, f32 x) {
    u8 loc[0x10];
    u8 *r;
    s32 k;
    f32 f22, f21, f20, f23, t;
    s32 v;
    s32 cnt;

    func_00382580(loc, 0.020000001f, 0.040000003f);
    func_L01_003D8E60(p, loc, 60, 7, 5, n, 0x1FF, 0, -1e+05f, x * 3.5f, -5.0f);
    if (func_00382468(2) != 0) {
        func_L01_003303B8(p, x, 0, 0, 0, 0, 0, 0, 0, 0.0f, 0.0f, 0.0f,
            0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
            0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    }
    if (n > 0) {
        u8 *tb = D_L09_00220018;
        cnt = n;
        v = 0xF2;
        do {
            func_00382580(loc, 0.070000008f, 0.14000002f);
            k = func_00382498(-2, 2);
            f22 = x * 3.0f;
            t = func_003824E0(-6.0f, -10.0f);
            f23 = f22 * 2.1e+05f;
            r = func_L01_00475C60(p, loc, 50, k, 0x7F407FFF, 0x407FFF, f23, f23, t, 0);
            if (r != 0) {
                r[9] = (u8)v;
                r[2] = ((u8 *)*(u8 **)(tb + 0x184))[3];
            }
            func_0038CE20(loc, loc, 2.0f);
            *(f32 *)(loc + 8) = fabs_asm(*(f32 *)(loc + 8));
            k = func_00382498(-2, 2);
            f21 = (f22 * 0.4f) * 2.1e+05f;
            f20 = (f22 * 0.04f) * 2.1e+05f;
            t = func_003824E0(24.0f, 4e+01f);
            r = func_L01_00475C60(p, loc, 50, k, 0x7F0048FF, 0x48FF, f21, f20, t, 0);
            if (r != 0) {
                r[9] = (u8)v;
                r[2] = ((u8 *)*(u8 **)(tb + 0x184))[3];
            }
            cnt--;
        } while (cnt != 0);
    }
}
/* localdecomp:end func_L09_003DDEE0 */

/* localdecomp:start func_L09_003DE200 */
extern void func_00382580(f32 *, f32, f32);
extern void func_L09_003DDEE0(f32 *, s32, f32);
extern void func_003A52A0(s32, s32, s32);

void func_L09_003DE200(u8 *a0, f32 a2, f32 a3, f32 a4, f32 a5, s32 a1) {
    f32 v[4];
    f32 w[4];
    s32 i;
    i = 1;
    func_00382580(v, a3 * 0.8f, a3 * 1.2f);
    v[2] = v[2] + a2;
    vec_add_ab(v, v, a0 + 0x10);
    do {
        func_00382580(w, a4 * 0.75f, a4 * 1.25f);
        i = i - 1;
        vec_add_ab(w, v, w);
        func_L09_003DDEE0(w, a1, a5 * 0.75f);
    } while (i >= 0);
    if (a0[0x20] != 4) {
        func_003A52A0(1, 0x10, (s32)a0);
    }
}
/* localdecomp:end func_L09_003DE200 */

/* localdecomp:start func_L09_003DE328 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003DE328;
extern u8 D_001D66B0;
extern u8 D_001E2B80[];
extern s16 D_001A4DBC[];
extern u8 *D_001E009C_sda;
extern s32 func_L01_00456250(void *);
extern s32 func_L01_004561B8(void *);
extern void func_L01_00456230(void *, s32);
extern void func_L09_005164C0(s32, s32);
extern void func_L09_003DE200(u8 *, f32, f32, f32, f32, s32);
extern s32 func_0038CAD0(void *);
extern f32 func_003824E0(f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_00451FE0(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_003A52A0(s32, s32, s32);
extern s32 func_L01_003303B8(void *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32,
    s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C2880(void *);

void func_L09_003DE328(u8 *o) {
    u8 *p = *(u8 **)(o + 0x68);
    V4_003DE328 v;
    s32 k;
    s32 idx;

    switch (o[0x20]) {
    case 0:
        o[0x30] = 0xFF;
        func_L01_004450F0(o, 1, -1);
        break;
    case 1:
        idx = *(s32 *)(p + 4);
        if (idx != -1 && func_L01_00456250(D_001E009C_sda + idx * 0x100) != 0) {
            func_L01_004450F0(o, 6, -1);
        }
        break;
    case 2:
        D_001A4DBC[0] = 0x1E;
        func_L09_005164C0(0x74, 1);
        func_L01_004450F0(o, 3, -1);
        break;
    case 3: {
        f32 r;
        if (func_L01_004561B8(o) != 0) {
            o[0xBC] = 0;
            *(s32 *)(p + 8) = 200;
            D_001A4DBC[0] = 200;
            func_L01_00456230(o, 1);
        }
        r = *(f32 *)(o + 0x2C) / *(f32 *)(*(u8 **)(o + 0x24) + 0x24);
        if (*(s32 *)(p + 8) % 30 == 0) {
            func_L09_003DE200(o, r * 28.0f, r * 6.0f, r * 10.0f, r * 3.0f, 5);
        }
        if (func_0038CAD0(p + 8) != 0) {
            u8 *g = D_001E2B80;
            f32 t;
            *(s32 *)(g + 0x28) = 0x25;
            *(f32 *)(g + 0x20) = 0.8f;
            *(s32 *)(g + 0x2C) = 0;
            *(u16 *)(o + 0x34) |= 0x41;
            *(s32 *)(o + 0x98) = 0;
            t = func_003824E0(10.0f, 20.0f);
            k = func_00382498(0x5A, 0x96);
            func_L01_00451FE0(o, 0x1FFF, &D_001D66B0, 2.0f, 3.0f, 5.0f, 7.0f, 0xFF, 6.0f, t, k, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
            ((s32 (*)(s32, s32, void *))func_003A52A0)(0, 0x10, o);
            *(s32 *)(p + 8) = 150;
            D_001A4DBC[0] = 0xB4;
            v = *(V4_003DE328 *)(o + 0x10);
            o[0xBC] = 0;
            v.z += 7.0f;
            func_L01_003303B8(&v, 3.0f, 0, 0x1E, 0x14, 0x14, 0x14, 0xF, 4, 0.0f, 30.0f, 15.0f,
                0, 1, 1, 1, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            ((s32 (*)(s32, s32, void *))func_003A52A0)(0, 0, o);
            func_L01_004450F0(o, 4, -1);
        }
        break;
    }
    case 4: {
        f32 r;
        if (o[0xBC] == 0) {
            r = *(f32 *)(o + 0x2C) / *(f32 *)(*(u8 **)(o + 0x24) + 0x24);
            if (*(s32 *)(p + 8) % 15 == 0) {
                func_L09_003DE200(o, r * 28.0f * 1.5f, r * 6.0f, r * 10.0f, r * 3.0f, 10);
            }
            if (func_0038CAD0(p + 8) != 0) {
                *(s32 *)(p + 8) = 30;
                o[0xBC] = 1;
            }
        } else if (o[0xBC] == 1) {
            if (func_0038CAD0(p + 8) != 0) {
                func_L01_004450F0(o, 5, -1);
            }
        }
        break;
    }
    case 5:
        D_001A4DBC[0] = 0x1E;
        func_L09_005164C0(0, 1);
        func_L01_004450F0(o, 7, -1);
        break;
    case 6: {
        f32 r;
        if (func_L01_004561B8(o) != 0) {
            o[0xBC] = 0;
            *(s32 *)(p + 8) = func_00382498(0xA0, 0xF0);
        }
        r = *(f32 *)(o + 0x2C) / *(f32 *)(*(u8 **)(o + 0x24) + 0x24);
        if (*(s32 *)(p + 8) % 30 == 0) {
            func_L09_003DE200(o, r * 28.0f, r * 6.0f, r * 10.0f, r * 3.0f, 5);
        }
        if (func_0038CAD0(p + 8) != 0) {
            u8 *g = D_001E2B80;
            f32 t;
            *(s32 *)(g + 0x28) = 0x25;
            *(f32 *)(g + 0x20) = 0.8f;
            *(s32 *)(g + 0x2C) = 0;
            *(u16 *)(o + 0x34) |= 0x41;
            *(s32 *)(o + 0x98) = 0;
            t = func_003824E0(10.0f, 20.0f);
            k = func_00382498(0x50, 0x6E);
            func_L01_00451FE0(o, 0x1FFF, &D_001D66B0, 2.0f, 3.0f, 5.0f, 7.0f, 0xFF, 6.0f, t, k, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
            ((s32 (*)(s32, s32, void *))func_003A52A0)(0, 0x10, o);
            *(s32 *)(p + 8) = 150;
            v = *(V4_003DE328 *)(o + 0x10);
            o[0xBC] = 0;
            v.z += r * 28.0f;
            func_L01_003303B8(&v, 10.0f, 0, 0xF, 0xA, 0, 0xA, 0, 4, 0.0f, 30.0f, 15.0f,
                0, 1, 1, 1, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L01_004450F0(o, 4, -1);
        }
        break;
    }
    case 7:
        func_003C2880(o);
        break;
    }
}
/* localdecomp:end func_L09_003DE328 */
