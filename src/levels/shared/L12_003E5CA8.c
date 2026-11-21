#include "common.h"

typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
} S_3E40A0;

/* localdecomp:start func_L12_003E5CA8 */
typedef struct {
    u8 pad[0x100];
} S_003E5CA8;

typedef struct {
    u8 pad00[0x54];
    s32 i54;
    s32 i58;
    f32 f5C;
    u8 b60;
    u8 b61;
    u8 b62;
} V_003E5CA8;

extern s32 func_L12_003E5F28_003E5CA8(u8 *, void *);
extern void func_L12_003E6160(u8 *m, s32 b);
extern void func_L12_003E61E0(void *);
extern s32 func_L01_00456250(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L01_00404A10(void *, void *);
extern void func_003C7C38(void *);
extern struct Obj_003E6790 *D_L12_001DFD1C;
__asm__(".extern D_L12_001DFD1C, 16");
extern S_003E5CA8 *D_L12_001DFD1C_003E5CA8;
__asm__(".extern D_L12_001DFD1C_003E5CA8, 4");
extern f32 D_L12_001DF2E0;
__asm__(".extern D_L12_001DF2E0, 4");
extern f32 D_L12_001DF2E4;
__asm__(".extern D_L12_001DF2E4, 4");
extern f32 D_L12_001DF2E8;
__asm__(".extern D_L12_001DF2E8, 4");
extern f32 D_L12_001DF2EC;
__asm__(".extern D_L12_001DF2EC, 4");

void func_L12_003E5CA8(u8 *a0) {
    V_003E5CA8 *v = *(V_003E5CA8 **)(a0 + 0x68);

    if (a0[0x20] == 0) {
        if (func_L12_003E5F28_003E5CA8(a0, v) == 0) {
            return;
        }
    }
    switch (a0[0x20]) {
    case 1:
        if (func_L01_00456250((S_003E5CA8 *)D_L12_001DFD1C + v->i54)) {
            func_L01_004450F0(a0, 2, -1);
        }
        break;
    case 2:
        v->f5C += D_L12_001DF2E0 * 0.020000001f;
        if (1.0f <= v->f5C) {
            v->f5C = 1.0f;
            func_L01_004450F0(a0, 4, -1);
        }
        if (v->f5C > D_L12_001DF2E8) {
            v->b60 = 1;
            if (v->b62 == 0) {
                *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
            }
        }
        func_L01_00404A10(func_L12_003E61E0, a0);
        break;
    case 3:
        v->f5C -= D_L12_001DF2E4 * 0.020000001f;
        if (v->f5C <= 0.0f) {
            v->f5C = 0.0f;
            func_L01_004450F0(a0, 1, -1);
            if (v->b61 == 0) {
                func_L12_003E6160(a0, 1);
                return;
            }
        }
        if (v->f5C < D_L12_001DF2EC) {
            v->b60 = 0;
            if (v->b62 == 0) {
                *(s32 *)(a0 + 0x98) = 0;
            }
        }
        if (a0[0x20] != 1) {
            func_L01_00404A10(func_L12_003E61E0, a0);
        }
        break;
    case 4:
        if (v->i58 != -1) {
            if (v->i54 == v->i58) {
                if (!func_L01_00456250(D_L12_001DFD1C_003E5CA8 + v->i58)) {
                    func_L01_004450F0(a0, 3, -1);
                }
            } else {
                if (func_L01_00456250(D_L12_001DFD1C_003E5CA8 + v->i58)) {
                    func_L01_004450F0(a0, 3, -1);
                }
            }
        }
        func_L01_00404A10(func_L12_003E61E0, a0);
        break;
    }
    if (v->b60) {
        *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
        func_003C7C38(a0);
        *(s32 *)(a0 + 0x98) = 0;
    }
}
/* localdecomp:end func_L12_003E5CA8 */

/* localdecomp:start func_L12_003E5F28 */
extern S_3E40A0 *func_L01_0043B548(s32, s32);
extern void func_003C7C38(void *);
extern void func_0038D308(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_004450F0(void *, s32, s32);

typedef struct {
    u8 pad00[0x30];
    s32 count;
    u8 pad34[0x40 - 0x34];
    f32 x;
    f32 y;
    f32 z;
    f32 max;
    u8 pad50[0x54 - 0x50];
    s32 i54;
    u8 pad58[0x5C - 0x58];
    f32 f5C;
    u8 b60;
    u8 pad61;
    u8 b62;
} S_003E5F28;

s32 func_L12_003E5F28(u8 *a0, S_003E5F28 *a1) {
    f32 m;

    if (a1->count > 0) {
        S_3E40A0 *v = func_L01_0043B548(6625, 108);
        a1->count = -1;
        v->f0(a0);
        return 0;
    }
    a0[0x31] = 0;
    *(u16 *)(a0 + 0x34) |= 1;
    if (a1->x == 0.0f) {
        a1->x = 1.0f;
    }
    if (a1->y == 0.0f) {
        a1->y = 1.0f;
    }
    if (a1->z == 0.0f) {
        a1->z = 1.0f;
    }
    m = ((a1->x > a1->y ? a1->x : a1->y) > a1->z) ? (a1->x > a1->y ? a1->x : a1->y) : a1->z;
    a1->max = m;
    *(f32 *)(a0 + 0x2C) = *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24) * m;
    *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
    func_003C7C38(a0);
    *(s32 *)(a0 + 0x98) = 0;
    *(u16 *)(a0 + 0x34) |= 0x144;
    func_0038D308(a0 + 0xC0, a0 + 0xF0);
    func_0038CE20(a0 + 0xC0, a0 + 0xC0, a1->x / a1->max);
    func_0038CE20(a0 + 0xD0, a0 + 0xD0, a1->y / a1->max);
    func_0038CE20(a0 + 0xE0, a0 + 0xE0, a1->z / a1->max);
    if (a1->i54 != -1) {
        a1->b60 = 0;
        a1->f5C = 0;
        func_L01_004450F0(a0, 1, -1);
    } else {
        a1->b60 = 1;
        if (a1->b62 == 0) {
            *(s32 *)(a0 + 0x98) = *(s32 *)(*(u8 **)(a0 + 0x24) + 0x10);
        }
        a1->f5C = 1.0f;
        func_L01_004450F0(a0, 4, -1);
    }
    return 1;
}
/* localdecomp:end func_L12_003E5F28 */
