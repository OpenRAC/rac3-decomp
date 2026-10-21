#include "common.h"

INCLUDE_ASM("asm/levels", func_L03_003AE9A0);

INCLUDE_ASM("asm/levels", func_L03_003AEA48);

/* localdecomp:start func_L03_003AEB30 */
typedef struct {
    u8 pad0[0xB0];
} S_3AD1F8c;

typedef struct {
    u8 pad0[0x270];
    S_3AD1F8c arr[8];
    u8 x7F0[0x10];
} S_3AD1F8b;

typedef struct {
    u8 pad0[0x68];
    S_3AD1F8b *p68;
} S_3AD1F8;

extern void func_L01_0040C8A0(S_3AD1F8c *a0, u8 *a1);
extern void func_L01_0040C948(S_3AD1F8c *a0, u8 *a1);

void func_L03_003AEB30(S_3AD1F8 *a0) {
    S_3AD1F8b *p = a0->p68;
    s32 i;
    for (i = 0; i < 8; i++) {
        func_L01_0040C8A0(&p->arr[i], p->x7F0);
        func_L01_0040C948(&p->arr[i], p->x7F0);
    }
}
/* localdecomp:end func_L03_003AEB30 */

/* localdecomp:start func_L03_003AEB98 */
void func_L03_003AEB98(u8 *self) {
    u8 *v = *(u8 **)(self + 104);

    *(s32 *)(v + 2032) = 12;
    *(f32 *)(v + 2036) = 0.33f;
    *(f32 *)(v + 2040) = 1200.0f;
    *(f32 *)(v + 2044) = 1500.0f;
    *(f32 *)(v + 2048) = 3.0f;
    *(f32 *)(v + 2052) = 3.5f;
    *(f32 *)(v + 2056) = 0.08f;
    *(f32 *)(v + 2060) = 0.02f;
    *(f32 *)(v + 2064) = 0.05f;
    *(f32 *)(v + 2068) = 3.0f;
    *(f32 *)(v + 2072) = 5.0f;
    *(f32 *)(v + 2076) = 0.2f;
    *(f32 *)(v + 2080) = 1.0f;
    *(s32 *)(v + 2084) = 0;
    *(s32 *)(v + 2088) = 0;
}
/* localdecomp:end func_L03_003AEB98 */
