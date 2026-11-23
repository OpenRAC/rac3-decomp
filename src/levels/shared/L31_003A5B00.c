#include "common.h"

/* localdecomp:start func_L31_003A5B00 */
f32 func_L31_003A5B00(void *m, f32 *pos) {
    if (pos[0] > *(f32 *)((u8 *)m + 0x10)) {
        return 0.0f;
    }
    return 3.1415927f;
}
/* localdecomp:end func_L31_003A5B00 */

/* localdecomp:start func_L31_003A5B30 */
#include "vu0.h"
extern f32 D_L31_001DE980;
__asm__(".extern D_L31_001DE980, 4");
extern f32 D_L31_001DE9A0;
__asm__(".extern D_L31_001DE9A0, 4");
extern f32 D_L31_001DE9B0;
__asm__(".extern D_L31_001DE9B0, 4");
extern vu0_v4 D_L31_001E91A0;
extern u8 *D_L31_001ED200[];
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_003D4D00(void *, s32, void *, void *, f32);
extern s32 func_L30_003445B8(u8 *);
extern s32 func_L30_00343830(u8 *, void *, void *, f32);

s32 func_L31_003A5B30(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 0x68);
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 c;
    vu0_v4 d;
    f32 h;
    f32 t;
    f32 k;
    f32 x;
    s32 n;
    s32 i;
    u8 *m;

    a = *(vu0_v4 *)(a0 + 0x10);
    x = a.x;
    if (*(f32 *)(a0 + 0x10) < *(f32 *)(s + 0x180)) {
        k = D_L31_001DE980;
        t = x + k;
    } else {
        k = -D_L31_001DE980;
        t = x + k;
    }
    a.x = t;
    b = a;
    c = a;
    h = D_L31_001DE9A0 * 0.5f;
    a.z += h;
    b.z -= h;
    if (func_003D3CB0(&a, &b, 2, a0, 0) != 0
        && fabs_asm(D_L31_001E91A0.z - *(f32 *)(a0 + 0x18)) < D_L31_001DE9B0) {
        return 1;
    }
    n = func_003D4D00(&c, 0, a0, 0, D_L31_001DE9B0);
    if (n != 0) {
        for (i = 0; i < n; i++) {
            m = D_L31_001ED200[i];
            if (func_L30_003445B8(m) != 0 && func_L30_00343830(m, &d, &c, D_L31_001DE9B0) != 0) {
                return 1;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L31_003A5B30 */
