/* func_L24_0034C208: 50 differences (level 24, file L24_0034A2C8.c). The loop bodies, the gp floats and the lq/sq
   copies match; what differs is the allocation across the two loops. Retail keeps nothing shared: it rebuilds the
   0.02f constant ($f20) and the base (s + 0x380) before the second loop and its frame is 0x50, this C hoists
   s + 0x380 into $s3 and the constant once (frame 0x60). A separate counter/pointer for the second loop (as in
   func_L24_0034C7A8) changes nothing; comparing `s[0x584] >= D` instead of `D <= s[0x584]` fixes the compare operand
   order only. About 4 compiles, not pursued further. */
#include "common.h"
typedef int u128_t __attribute__((mode(TI)));
extern s32 D_L24_001DF0C0[];
extern f32 D_L24_001DD398;
extern f32 D_L24_001DD3A4;
extern void func_003C4098(void *, void *, void *, f32);

void func_L24_0034C208(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    u8 *p;
    s32 n;
    f32 a[4];
    f32 b[4];

    if (D_L24_001DF0C0[0] >= 5) {
        p = s + 0x250;
        n = 3;
        do {
            if (*(f32 *)(s + 0x584) >= D_L24_001DD398) {
                *(u128_t *)a = *(u128_t *)(p + 0x90);
                *(u128_t *)b = *(u128_t *)p;
                func_003C4098(p, a, b, D_L24_001DD3A4 / *(f32 *)(s + 0x584) * 0.02f);
            } else {
                *(u128_t *)p = *(u128_t *)(p + 0x90);
            }
            p += 0x10;
            n--;
        } while (n >= 0);
        p = s + 0x380;
        n = 3;
        do {
            if (*(f32 *)(s + 0x584) >= D_L24_001DD398) {
                *(u128_t *)a = *(u128_t *)(p + 0x90);
                *(u128_t *)b = *(u128_t *)p;
                func_003C4098(p, a, b, D_L24_001DD3A4 / *(f32 *)(s + 0x584) * 0.02f);
            } else {
                *(u128_t *)p = *(u128_t *)(p + 0x90);
            }
            p += 0x10;
            n--;
        } while (n >= 0);
    }
}
