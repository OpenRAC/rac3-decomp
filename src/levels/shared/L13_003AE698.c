#include "common.h"

typedef struct {
    void (*f0)(void *);
    void (*f4)(void *);
} S_3AC810;

/* declared by functions of L13_003ADA98.c, which this file was cut from */
extern void func_L13_003AE698(u8 *a);

/* localdecomp:start func_L13_003AE698 */
typedef int u128_t __attribute__((mode(TI)));
__asm__(".extern D_L13_001DE66C, 4");
__asm__(".extern D_L13_001DE670, 4");
__asm__(".extern D_L13_001DE674, 4");
__asm__(".extern D_L13_001DE690, 4");
__asm__(".extern D_L13_001DE694, 4");
__asm__(".extern D_L13_001DE698, 4");
extern f32 D_L13_001DE66C;
extern f32 D_L13_001DE670;
extern f32 D_L13_001DE674;
extern f32 D_L13_001DE690;
extern f32 D_L13_001DE694;
extern f32 D_L13_001DE698;
extern u8 *D_L13_0021D540[];
extern void func_L13_003AF0B0(void *, f32, f32, f32);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_L01_004450F0(u8 *, s32, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_L13_003AEB48(void *);

void func_L13_003AE698(u8 *a) {
    u8 *s1;
    u8 *t;

    s1 = *(u8 **)(a + 0x68);
    if (a[0x95] == 0) {
        func_L13_003AF0B0(s1 + 0x150, D_L13_001DE66C * 0.017453292f * 0.020000001f, D_L13_001DE670 * 0.017453292f * 0.00040000002f, D_L13_001DE674 * 0.017453292f * 0.00040000002f);
        *(s32 *)(s1 + 0x188) |= 0x414;
        if (*(s32 *)(s1 + 0x384) != -1) {
            if (a[0x43] != 0) {
                func_003C3A10(a, 0, 0, 0);
            }
            func_L01_004450F0(a, 2, -1);
        } else {
            if (a[0x43] != 0x18) {
                func_003C3A10(a, 0x18, 0, 0);
            }
            func_L01_004450F0(a, 1, -1);
        }
    } else {
        func_L13_003AF0B0(s1 + 0x150, D_L13_001DE690 * 0.017453292f * 0.020000001f, D_L13_001DE694 * 0.017453292f * 0.00040000002f, D_L13_001DE698 * 0.017453292f * 0.00040000002f);
        if (*(s32 *)(s1 + 0x384) != -1) {
            t = D_L13_0021D540[*(s32 *)(s1 + 0x384)];
            *(s16 *)(s1 + 0x218) = 0;
            *(u8 **)(s1 + 0x214) = t;
            *(s16 *)(s1 + 0x21A) = *(u16 *)t - 1;
            *(u128_t *)(a + 0x10) = *(u128_t *)(t + 0x10);
            *(f32 *)(a + 0x18) = func_003C3D30(a + 0x10, 0, 0, 0.5f);
            func_L13_003AEB48(a);
            func_L01_004450F0(a, 5, -1);
        } else {
            if (a[0x43] != 0) {
                func_003C3A10(a, 0, 0, 0);
            }
            func_L01_004450F0(a, 4, -1);
        }
    }
}
/* localdecomp:end func_L13_003AE698 */
