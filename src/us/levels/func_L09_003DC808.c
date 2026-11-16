#include "common.h"

/* NTSC-U counterpart of func_L09_003DE328 (src/levels/09_tyhrranosis/L09_003DDEE0.c) */
#include "vu0.h"
#include "vu0.h"
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern s32 func_L01_0032FE90_003DC808(void *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_0039FE80(s32, s32, s32);

/* localdecomp:start func_L09_003DC808 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003DE328;
extern u8 D_L09_001D66B0_003DC808;
extern u8 D_L09_001E2C00[];
extern s16 D_001A4DBC[];
extern u8 *D_001E011C_sda;
extern s32 func_L01_00452F60(void *);
extern s32 func_L01_00452EC8(void *);
extern void func_L01_00452F40(void *, s32);
extern void func_L09_00512408(s32, s32);
extern void func_L09_003DC6E0(u8 *a0, f32 a2, f32 a3, f32 a4, f32 a5, s32 a1);
extern s32 func_00388398(void *);
extern f32 func_0037E250(f32, f32);
extern s32 func_0037E208(s32, s32);
extern void func_L01_0044ED60(void *, s32, void *, f32, f32, f32, f32, s32, f32, f32, s32, s32, s32, s32, f32, f32, s32, s32);
extern void func_0039FE80(s32, s32, s32);
extern s32 func_L01_0032FE90_003DC808(void *, f32, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_003BD360(void *);

void func_L09_003DC808(u8 *o) {
    u8 *p = *(u8 **)(o + 0x68);
    V4_003DE328 v;
    s32 k;
    s32 idx;

    switch (o[0x20]) {
    case 0:
        o[0x30] = 0xFF;
        func_L01_00441FB8(o, 1, -1);
        break;
    case 1:
        idx = *(s32 *)(p + 4);
        if (idx != -1 && func_L01_00452F60(D_001E011C_sda + idx * 0x100) != 0) {
            func_L01_00441FB8(o, 6, -1);
        }
        break;
    case 2:
        D_001A4DBC[0] = 0x1E;
        func_L09_00512408(0x74, 1);
        func_L01_00441FB8(o, 3, -1);
        break;
    case 3: {
        f32 r;
        if (func_L01_00452EC8(o) != 0) {
            o[0xBC] = 0;
            *(s32 *)(p + 8) = 200;
            D_001A4DBC[0] = 200;
            func_L01_00452F40(o, 1);
        }
        r = *(f32 *)(o + 0x2C) / *(f32 *)(*(u8 **)(o + 0x24) + 0x24);
        if (*(s32 *)(p + 8) % 30 == 0) {
            func_L09_003DC6E0(o, r * 28.0f, r * 6.0f, r * 10.0f, r * 3.0f, 5);
        }
        if (func_00388398(p + 8) != 0) {
            u8 *g = D_L09_001E2C00;
            f32 t;
            *(s32 *)(g + 0x28) = 0x2D;
            *(f32 *)(g + 0x20) = 0.8f;
            *(s32 *)(g + 0x2C) = 0;
            *(u16 *)(o + 0x34) |= 0x41;
            *(s32 *)(o + 0x98) = 0;
            t = func_0037E250(10.0f, 20.0f);
            k = func_0037E208(0x5A, 0x96);
            func_L01_0044ED60(o, 0x1FFF, &D_L09_001D66B0_003DC808, 2.0f, 3.0f, 5.0f, 7.0f, 0xFF, 6.0f, t, k, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
            ((s32 (*)(s32, s32, void *))func_0039FE80)(0, 0x10, o);
            *(s32 *)(p + 8) = 150;
            D_001A4DBC[0] = 0xB4;
            v = *(V4_003DE328 *)(o + 0x10);
            o[0xBC] = 0;
            v.z += 7.0f;
            func_L01_0032FE90_003DC808(&v, 3.0f, 0, 0x1E, 0x14, 0x14, 0x14, 0xF, 4, 0.0f, 30.0f, 15.0f,
                0, 1, 1, 1, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            ((s32 (*)(s32, s32, void *))func_0039FE80)(0, 0, o);
            func_L01_00441FB8(o, 4, -1);
        }
        break;
    }
    case 4: {
        f32 r;
        if (o[0xBC] == 0) {
            r = *(f32 *)(o + 0x2C) / *(f32 *)(*(u8 **)(o + 0x24) + 0x24);
            if (*(s32 *)(p + 8) % 15 == 0) {
                func_L09_003DC6E0(o, r * 28.0f * 1.5f, r * 6.0f, r * 10.0f, r * 3.0f, 10);
            }
            if (func_00388398(p + 8) != 0) {
                *(s32 *)(p + 8) = 30;
                o[0xBC] = 1;
            }
        } else if (o[0xBC] == 1) {
            if (func_00388398(p + 8) != 0) {
                func_L01_00441FB8(o, 5, -1);
            }
        }
        break;
    }
    case 5:
        D_001A4DBC[0] = 0x1E;
        func_L09_00512408(0, 1);
        func_L01_00441FB8(o, 7, -1);
        break;
    case 6: {
        f32 r;
        if (func_L01_00452EC8(o) != 0) {
            o[0xBC] = 0;
            *(s32 *)(p + 8) = func_0037E208(0xA0, 0xF0);
        }
        r = *(f32 *)(o + 0x2C) / *(f32 *)(*(u8 **)(o + 0x24) + 0x24);
        if (*(s32 *)(p + 8) % 30 == 0) {
            func_L09_003DC6E0(o, r * 28.0f, r * 6.0f, r * 10.0f, r * 3.0f, 5);
        }
        if (func_00388398(p + 8) != 0) {
            u8 *g = D_L09_001E2C00;
            f32 t;
            *(s32 *)(g + 0x28) = 0x2D;
            *(f32 *)(g + 0x20) = 0.8f;
            *(s32 *)(g + 0x2C) = 0;
            *(u16 *)(o + 0x34) |= 0x41;
            *(s32 *)(o + 0x98) = 0;
            t = func_0037E250(10.0f, 20.0f);
            k = func_0037E208(0x50, 0x6E);
            func_L01_0044ED60(o, 0x1FFF, &D_L09_001D66B0_003DC808, 2.0f, 3.0f, 5.0f, 7.0f, 0xFF, 6.0f, t, k, 0, 0, 0x23, 1.0f, 1.0f, 0, 3);
            ((s32 (*)(s32, s32, void *))func_0039FE80)(0, 0x10, o);
            *(s32 *)(p + 8) = 150;
            v = *(V4_003DE328 *)(o + 0x10);
            o[0xBC] = 0;
            v.z += r * 28.0f;
            func_L01_0032FE90_003DC808(&v, 10.0f, 0, 0xF, 0xA, 0, 0xA, 0, 4, 0.0f, 30.0f, 15.0f,
                0, 1, 1, 1, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF,
                0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
            func_L01_00441FB8(o, 4, -1);
        }
        break;
    }
    case 7:
        func_003BD360(o);
        break;
    }
}
/* localdecomp:end func_L09_003DC808 */
