#include "common.h"

typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
} S_3E40A0;

INCLUDE_ASM("asm/levels", func_L12_003E5CA8);

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
