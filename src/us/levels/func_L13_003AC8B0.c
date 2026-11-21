#include "common.h"

/* NTSC-U counterpart of func_L13_003AE698 (src/levels/shared/L13_003AE698.c): 0.0004 -> 0.000277778; 0.02 -> 0.0166667 */
extern void func_L13_003AC8B0(u8 *a);

/* localdecomp:start func_L13_003AC8B0 */
typedef int u128_t __attribute__((mode(TI)));
__asm__(".extern D_L13_001DE69C_003AC8B0, 4");
__asm__(".extern D_L13_001DE6A0_003AC8B0, 4");
__asm__(".extern D_L13_001DE6A4, 4");
__asm__(".extern D_L13_001DE6C0, 4");
__asm__(".extern D_L13_001DE6C4, 4");
__asm__(".extern D_L13_001DE6C8, 4");
extern f32 D_L13_001DE69C_003AC8B0;
extern f32 D_L13_001DE6A0_003AC8B0;
extern f32 D_L13_001DE6A4;
extern f32 D_L13_001DE6C0;
extern f32 D_L13_001DE6C4;
extern f32 D_L13_001DE6C8;
extern u8 *D_L13_0021D5C0[];
extern void func_L13_003AD2C8(void *, f32, f32, f32);
extern void func_003BE4F0(u8 *, s32, s32, s32);
extern void func_L01_00441FB8(u8 *, s32, s32);
extern f32 func_003BE7F0(void *, s32, s32, f32);
extern void func_L13_003ACD60(void *);

void func_L13_003AC8B0(u8 *a) {
    u8 *s1;
    u8 *t;

    s1 = *(u8 **)(a + 0x68);
    if (a[0x95] == 0) {
        func_L13_003AD2C8(s1 + 0x150, D_L13_001DE69C_003AC8B0 * 0.017453292f * 0.0166666675f, D_L13_001DE6A0_003AC8B0 * 0.017453292f * 0.000277777785f, D_L13_001DE6A4 * 0.017453292f * 0.000277777785f);
        *(s32 *)(s1 + 0x188) |= 0x414;
        if (*(s32 *)(s1 + 0x384) != -1) {
            if (a[0x43] != 0) {
                func_003BE4F0(a, 0, 0, 0);
            }
            func_L01_00441FB8(a, 2, -1);
        } else {
            if (a[0x43] != 0x18) {
                func_003BE4F0(a, 0x18, 0, 0);
            }
            func_L01_00441FB8(a, 1, -1);
        }
    } else {
        func_L13_003AD2C8(s1 + 0x150, D_L13_001DE6C0 * 0.017453292f * 0.0166666675f, D_L13_001DE6C4 * 0.017453292f * 0.000277777785f, D_L13_001DE6C8 * 0.017453292f * 0.000277777785f);
        if (*(s32 *)(s1 + 0x384) != -1) {
            t = D_L13_0021D5C0[*(s32 *)(s1 + 0x384)];
            *(s16 *)(s1 + 0x218) = 0;
            *(u8 **)(s1 + 0x214) = t;
            *(s16 *)(s1 + 0x21A) = *(u16 *)t - 1;
            *(u128_t *)(a + 0x10) = *(u128_t *)(t + 0x10);
            *(f32 *)(a + 0x18) = func_003BE7F0(a + 0x10, 0, 0, 0.5f);
            func_L13_003ACD60(a);
            func_L01_00441FB8(a, 5, -1);
        } else {
            if (a[0x43] != 0) {
                func_003BE4F0(a, 0, 0, 0);
            }
            func_L01_00441FB8(a, 4, -1);
        }
    }
}
/* localdecomp:end func_L13_003AC8B0 */
