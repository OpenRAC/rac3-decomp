#include "common.h"

/* localdecomp:start func_L24_003554A8 */
#include "vu0.h"
extern f32 func_0038CF38(void *, void *);
extern s32 func_L01_00456250(void *);
extern s32 func_L24_00432C00(s32, s32, s32);
extern void func_L01_00456230(void *, s32);
extern u8 *D_L24_001DF528;
__asm__(".extern D_L24_001DF528, 16");
extern u8 *D_L24_001DF1CC;
__asm__(".extern D_L24_001DF1CC, 16");

s32 func_L24_003554A8(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    u8 *m;
    u8 *best;
    f32 bd;
    s32 ok;
    s32 a;
    s32 b;

    if (*(s32 *)(s + 0x2F0) != 0) {
        *(u8 **)(s + 0x2E0) = 0;
        return 0;
    }
    bd = 0.0f;
    best = 0;
    for (m = D_L24_001DF528; m != 0; m = *(u8 **)(m + 0x28)) {
        if (func_0038CF38(obj + 0x10, m + 0x10) <= 20.0f) {
            if (fabs_asm(*(f32 *)(m + 0x18) - *(f32 *)(obj + 0x18)) < 5.0f
                && (*(s16 *)(m + 0xAA) == 0x1F4 || *(s16 *)(m + 0xAA) == 0x1663) && *(s16 *)(m + 0xB2) != 0
                && func_L01_00456250(m) == 0) {
                a = *(s32 *)(s + 0x2C0);
                do {
                    b = *(s32 *)(s + 0x2F8);
                    if (a != -1 || b != -1) {
                        u8 *e = D_L24_001DF1CC + a * 0x30;
                        if (*(s16 *)(e + 0x30) != 0 || *(s16 *)(D_L24_001DF1CC + b * 0x30 + 0x30) != 0) {
                            if (b != -1) {
                                b = **(s32 **)(D_L24_001DF1CC + b * 0x30 + 0x3C);
                            } else {
                                b = **(s32 **)(e + 0x3C);
                            }
                            ok = func_L24_00432C00((s32)(m + 0x10), b, 0) != 0;
                            break;
                        }
                    }
                    ok = 1;
                } while (0);
                if (best == 0 && ok) {
                    best = m;
                    bd = func_0038CF38(obj + 0x10, best + 0x10);
                } else if (func_0038CF38(obj + 0x10, m + 0x10) <= bd && ok) {
                    bd = func_0038CF38(obj + 0x10, m + 0x10);
                    best = m;
                }
            }
        }
    }
    if (best != 0) {
        *(u8 **)(s + 0x2E0) = best;
        func_L01_00456230(best, 1);
        return 1;
    }
    *(u8 **)(s + 0x2E0) = 0;
    return 0;
}
/* localdecomp:end func_L24_003554A8 */

/* localdecomp:start func_L24_003556A8 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_003C3D30(void *, s32, s32, f32);

s32 func_L24_003556A8(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    f32 v[4];
    f32 w[4];
    f32 h;

    *(u128_t *)v = *(u128_t *)(obj + 0x10);
    w[0] = func_0038D098(*(f32 *)(obj + 0xF8));
    w[1] = func_0038D0B0(*(f32 *)(obj + 0xF8));
    w[2] = 0.0f;
    vec_add_ab(v, v, w);
    h = func_003C3D30(v, 0, 0, 0.5f);
    if (h < *(f32 *)(obj + 0x18)) {
        if (*(f32 *)(s + 0x7C) < fabs_asm(h - *(f32 *)(obj + 0x18))) {
            w[0] = func_0038D098(*(f32 *)(obj + 0xF8)) * 7.5f;
            w[1] = func_0038D0B0(*(f32 *)(obj + 0xF8)) * 7.5f;
            w[2] = 0.0f;
            vec_add_ab(v, obj + 0x10, w);
            h = func_003C3D30(v, 0, 0, 1.0f);
            if (*(f32 *)(obj + 0x18) - 5.0f < h) {
                *(f32 *)(s + 0x308) = h;
                return 1;
            }
            return 2;
        }
    }
    return 0;
}
/* localdecomp:end func_L24_003556A8 */
