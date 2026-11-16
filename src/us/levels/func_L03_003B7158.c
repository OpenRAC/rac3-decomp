#include "common.h"

/* NTSC-U counterpart of func_L03_003B8DF8 (src/levels/shared/L03_003B8B28.c) */
/* localdecomp:start func_L03_003B7158 */
typedef int u128_3B8DF8 __attribute__((mode(TI)));
extern u8 *func_003BCFB0(s32, s32);
extern void func_003BDA38(void *, s32, void *);
extern void func_L03_0034A658(u8 *, s32, s32, f32, s32, void *);
extern void func_L03_003B7490(u8 *, void *);
__asm__(".extern D_L03_001DEAC8, 4");
extern s32 D_L03_001DEAC8;
extern u8 D_L03_001E1E88[8];

u8 *func_L03_003B7158(u8 *a0, s32 a1, f32 a2) {
    u8 *m = func_003BCFB0(0x1C16, 0x80);
    u8 *mv;
    u8 *pv;
    if (m != 0) {
        mv = *(u8 **)(m + 0x68);
        m[0x30] = 0xFF;
        *(u16 *)(m + 0x32) = 0x40;
        m[0x31] = 1;
        *(u8 **)(m + 0xB8) = a0;
        *(f32 *)(mv + 0x20) = a2 * 0.0166666675f;
        *(s32 *)(mv + 0x24) = 0;
        *(s32 *)(mv + 0x2C) = a1;
        pv = *(u8 **)(a0 + 0x68);
        func_003BDA38(*(void **)pv, a1, mv + 0x10);
        func_003BDA38(*(void **)pv, a1 - 0x20, mv);
        *(s32 *)(mv + 0x28) = *(s32 *)pv;
        *(u128_3B8DF8 *)(m + 0x10) = *(u128_3B8DF8 *)(mv + 0x10);
    }
    if (D_L03_001DEAC8 == 0) {
        D_L03_001DEAC8 = 1;
        func_L03_0034A658(D_L03_001E1E88, 0x1E, 0x14, 2.1f, 2, func_L03_003B7490);
    }
    return m;
}
/* localdecomp:end func_L03_003B7158 */
