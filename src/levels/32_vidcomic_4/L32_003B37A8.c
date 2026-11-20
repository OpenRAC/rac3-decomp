#include "common.h"

/* localdecomp:start func_L32_003B37A8 */
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

extern void func_L32_003B4310(u8 *a0);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(u8 *);
extern s32 func_L01_004AAC98(s32, s32, s32, s32);
extern void func_L32_003B41E8(void *arg0, void *arg1, f32 arg2, f32 arg3, f32 *arg4);
extern void func_L30_0034C8A8(void *, void *);
extern void func_L01_00404A10(void *, void *);
extern void func_L01_004126A8(s32);
extern void func_L30_0034CC28(void *, void *, void *, s32, s32, f32);
extern s32 func_003D4D00(void *, s32, void *, void *, f32);
extern s32 func_0038CAD0(void *);
extern void func_003C2880(void *);
extern u8 D_L32_001D66B0[] __attribute__((section(".sdata")));
extern u8 D_L32_001E2440[] __attribute__((section(".sdata")));
extern u8 D_L32_001E2460[] __attribute__((section(".sdata")));
extern f32 D_L32_001DECDC;
__asm__(".extern D_L32_001DECDC, 4");
extern f32 D_L32_001DECE0;
__asm__(".extern D_L32_001DECE0, 4");
extern s32 D_L32_001DECE4;
__asm__(".extern D_L32_001DECE4, 4");
extern f32 D_L32_001DECF0;
__asm__(".extern D_L32_001DECF0, 4");
extern f32 D_L32_001DED2C;
__asm__(".extern D_L32_001DED2C, 4");

void func_L32_003B37A8(u8 *a0) {
    u8 *st = *(u8 **)(a0 + 0x68);
    vu0_v4 old;
    u8 buf[0x30];
    f32 f;

    if (a0[0x20] == 0) {
        func_L32_003B4310(a0);
        func_L01_004450F0(a0, 1, -1);
    }
    switch (a0[0x20]) {
    case 1:
        if (func_L01_004561B8(a0) != 0) {
            func_L01_004AAC98(8, 0, (s32)a0, 0x19D1);
        }
        *(f32 *)(st + 0x34) += D_L32_001DECF0;
        if (1.0f <= *(f32 *)(st + 0x34)) {
            func_L01_004450F0(a0, 2, -1);
            break;
        }
        old = *(vu0_v4 *)(a0 + 0x10);
        func_L32_003B41E8(a0, a0 + 0x10, -1.0f, 0.01f, (f32 *)(st + 0x34));
        vec_sub_ab(st + 0x20, a0 + 0x10, &old);
        f = *(f32 *)(st + 0x48) + D_L32_001DED2C;
        *(f32 *)(st + 0x48) = f - cvtsw_asm(cvtws_asm(f));
        if (0.0f < *(f32 *)(st + 0x34)) {
            func_L30_0034C8A8(D_L32_001E2440, a0);
            func_L01_00404A10(func_L01_004126A8, a0);
        }
        break;
    case 2:
        if (func_L01_004561B8(a0) != 0) {
            u8 *pos = a0 + 0x10;
            *(u128_t *)pos = *(u128_t *)(st + 0x10);
            func_L30_0034CC28(buf, a0, D_L32_001D66B0, 1, 0, D_L32_001DECDC);
            *(s32 *)(buf + 0x14) |= 0x30000;
            func_003D4D00(pos, 1, a0, buf, D_L32_001DECE0);
            *(s32 *)(st + 0x38) = D_L32_001DECE4;
            func_L01_004AAC98(9, 0, (s32)a0, 0x19D1);
        }
        *(f32 *)(st + 0x3C) -= D_L32_001DECF0;
        if (*(f32 *)(st + 0x3C) < 0.0f) {
            *(f32 *)(st + 0x3C) = 0.0f;
        }
        if (0.0f < *(f32 *)(st + 0x3C)) {
            func_L30_0034C8A8(D_L32_001E2460, a0);
            func_L01_00404A10(func_L01_004126A8, a0);
        }
        if (func_0038CAD0(st + 0x38) != 0) {
            func_003C2880(a0);
        }
        break;
    }
}
/* localdecomp:end func_L32_003B37A8 */
