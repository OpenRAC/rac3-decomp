#include "common.h"

/* localdecomp:start func_L30_00350050 */
__asm__(".extern D_L30_001DD6F0, 1");
extern u8 D_L30_001DD6F0;
__asm__(".extern D_L30_001DD700, 4");
extern s32 D_L30_001DD700;
__asm__(".extern D_L30_001DD704, 4");
extern f32 D_L30_001DD704;
__asm__(".extern D_L30_001DD714, 4");
extern f32 D_L30_001DD714;
__asm__(".extern D_L30_001DD710, 4");
extern f32 D_L30_001DD710;
__asm__(".extern D_L30_001DD6FC, 4");
extern f32 D_L30_001DD6FC;
__asm__(".extern D_L30_001DD6F8, 4");
extern s32 D_L30_001DD6F8;
__asm__(".extern D_L30_001DD6F4, 4");
extern s32 D_L30_001DD6F4;
__asm__(".extern D_L30_001DD6EC, 4");
extern s32 D_L30_001DD6EC;
__asm__(".extern D_L30_001DD6E8, 4");
extern s32 D_L30_001DD6E8;
extern u8 *D_L30_0021F26C __attribute__((section(".data")));
extern f32 func_L03_0034B440(s32, s32, s32, f32, f32, f32);
extern s32 func_0038DBD8(s32, s32, f32);
typedef int q_00350050 __attribute__((mode(TI)));

void func_L30_00350050(u8 *a0, u8 *a1) {
    u8 *src;
    s32 b;
    f32 r;
    f32 t;
    s32 c0;
    s32 c1;
    s32 n;

    if (a1 == 0) {
        return;
    }
    src = *(u8 **)a1;
    n = *(s32 *)(a1 + 4);
    if (src == 0 || n == 0) {
        return;
    }
    b = *(u16 *)(a1 + 0xC) & 1;
    if ((*(u16 *)(a1 + 0xA) & 1) && b) {
        a0[3] = D_L30_001DD6F0;
        a0[2] = D_L30_0021F26C[D_L30_001DD700];
    }
    r = func_L03_0034B440(1, 0, 0, (f32)*(s16 *)(a0 + 0xA), (f32)*(s16 *)(a1 + 8), 1.0f);
    *(q_00350050 *)(a0 + 0x10) = *(q_00350050 *)(src + 0x10);
    if (b) {
        *(f32 *)(a0 + 0x14) += D_L30_001DD704;
    }
    t = D_L30_001DD714 * (1.0f - r);
    if (1.0f < t) {
        t = 1.0f;
    }
    *(f32 *)(a0 + 0xC) = t * D_L30_001DD710 * 210000.0f;
    if (b) {
        c0 = D_L30_001DD6F8;
        c1 = D_L30_001DD6F4;
        *(f32 *)(a0 + 0xC) *= D_L30_001DD6FC;
    } else {
        c0 = D_L30_001DD6EC;
        c1 = D_L30_001DD6E8;
    }
    *(s32 *)(a0 + 4) = func_0038DBD8(c0, c1, r);
    a0[8] = a1[0xE];
}
/* localdecomp:end func_L30_00350050 */
