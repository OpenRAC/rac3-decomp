/* func_L31_003A5B30: 86 diff with the file's flags. The shape is right (copies, two calls, the loop over D_001ED200, the two float tests), but the register and order choices differ: retail keeps the dst pointer (the C array) in $20 and compares m+0x10 with the copy loaded from the stack; the ternary form (A[0] + (cond ? D : -D)) gave bc1fl/bc1t layouts that were no closer, and the early return test as a single condition gave 87. */
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

extern f32 D_L31_001DE980;
__asm__(".extern D_L31_001DE980, 4");
extern f32 D_L31_001DE9A0;
__asm__(".extern D_L31_001DE9A0, 4");
extern f32 D_L31_001DE9B0;
__asm__(".extern D_L31_001DE9B0, 4");
extern f32 D_L31_001E91A0[];
extern s32 D_L31_001ED200[];
extern s32 func_003D3CB0(void *a, void *b, s32 c, void *d, s32 e);
extern s32 func_003D4D00(void *a, s32 b, void *c, s32 d, f32 e);
extern s32 func_L30_003445B8(void *a);
extern s32 func_L30_00343830(void *a, void *b, void *c, f32 d);

s32 func_L31_003A5B30(u8 *m) {
    f32 A[4];
    f32 B[4];
    f32 C[4];
    f32 D[4];
    u8 *vars;
    f32 t;
    s32 r;
    s32 i;
    s32 *q;
    s32 o;

    vars = *(u8 **)(m + 0x68);
    *(u128_t *)A = *(u128_t *)(m + 0x10);
    if (A[0] < *(f32 *)(vars + 0x180)) {
        A[0] = A[0] + D_L31_001DE980;
    } else {
        A[0] = A[0] + -D_L31_001DE980;
    }
    *(u128_t *)B = *(u128_t *)A;
    *(u128_t *)C = *(u128_t *)A;
    t = D_L31_001DE9A0 * 0.5f;
    A[2] = A[2] + t;
    B[2] = B[2] - t;
    r = func_003D3CB0(A, B, 2, m, 0);
    if (r == 0 || !(fabs_asm(D_L31_001E91A0[2] - *(f32 *)(m + 0x18)) < D_L31_001DE9B0)) {
        o = 0;
    } else {
        return 1;
    }
    r = func_003D4D00(C, 0, m, 0, D_L31_001DE9B0);
    if (r <= 0) {
        return 0;
    }
    i = 0;
    q = D_L31_001ED200;
    do {
        o = func_L30_003445B8((void *)*q);
        if (o != 0) {
            if (func_L30_00343830((void *)*q, D, C, D_L31_001DE9B0)) {
                return 1;
            }
        }
        i++;
        q++;
    } while (i < r);
    return 0;
}
