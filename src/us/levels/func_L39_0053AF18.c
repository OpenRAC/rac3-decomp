#include "common.h"

/* NTSC-U counterpart of func_L39_0053B6B0 (src/levels/shared/L39_00537998.c): 0.00472 -> 0.00327778 */
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L39_0053AF18 */
extern u8 *D_L39_0024CF20[8] __attribute__((section(".sdata")));
__asm__(".extern D_L39_0024CF20, 32");
extern u8 D_L39_0025F860[];
extern s32 func_L39_0062F938(u8 *, f32 *, s32, f32, f32, f32);
extern s32 func_003CE740(f32 *, u8 *, s32, u8 *, s32);
extern void func_003886E8(f32 *, void *, f32);
extern s32 func_L39_005FC5C0(u8 *, f32, u8 *, u8 *, u8 *, u8 *, s32, s32, s32, s32, s32);
extern void func_L39_0053B2D0(u8 *);
extern void func_L01_00402498(void *, void *);

s32 func_L39_0053AF18(u8 *a0, u8 *a1, u8 *a2) {
    u8 *obj = 0;
    s32 r;
    f32 buf[4];
    if (*(u16 *)(a0 + 0x7C) < 8) {
        obj = D_L39_0024CF20[*(s16 *)(a0 + 0x7C)];
    }
    if (obj == 0) {
        return 0;
    }
    if (a1[0x20] != 0) {
        *(s16 *)(a0 + 0x36) = 1;
        return 0;
    }
    r = 0;
    if (obj[0x1A14] != 0) {
        func_L39_0062F938(obj, buf, 1, 0.0f, 0.0f, 0.37f);
        if (func_003CE740(buf, a2, 0x32, a1, 0) != 0) {
            r = 1;
            func_003886E8((f32 *)(a0 + 0x20), D_L39_0025F860 + 0x20, 0.0009765625f);
            *(u128_t *)(a0 + 0x10) = *(u128_t *)D_L39_0025F860;
        } else {
            r = func_L39_005FC5C0(obj, 0.00327777793f, a2, a0, a0 + 0x10, a0 + 0x20, *(s32 *)(a1 + 0xB8), 1, 0, (s32)(a0 + 0x78), 0);
        }
    }
    if (r != 0) {
        func_L01_00402498(func_L39_0053B2D0, a1);
    }
    return r;
}
/* localdecomp:end func_L39_0053AF18 */
