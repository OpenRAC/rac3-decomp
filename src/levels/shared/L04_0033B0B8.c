#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L04_0033B0B8 */
extern void func_L04_0033B308(u8 *m, u8 *s);
extern s32 func_L01_0043B568(s32, s32, s32);
extern void func_0038D308(void *, void *);
extern void func_0038D328(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_0044F450(void *, void *);
extern u8 D_001BBC40[][16];
extern s32 D_001D545C;
extern u8 *D_L04_001DFD9C;

void func_L04_0033B0B8(u8 *m) {
    vu0_v4 mat[4];
    vu0_v4 v;
    u8 *s;
    u8 *o;
    f32 (**vt)(u8 *);
    f32 t;
    f32 k;

    t = 0.0f;
    s = *(u8 **)(m + 0x68);
    switch (m[0x20]) {
    case 0:
        func_L04_0033B308(m, s);
        break;
    case 1:
        o = D_L04_001DFD9C + (*(s32 *)s << 8);
        if (o != 0) {
            vt = (f32 (**)(u8 *))func_L01_0043B568(*(s16 *)(o + 0xAA), 6, 4);
            if (m[0xB0] != 0xFF && (D_001BBC40[D_001D545C][m[0xB0]] & 0x80)) {
                k = 1.0f;
            } else {
                k = vt[0](o);
            }
            *(vu0_q *)(m + 0x10) = *(vu0_q *)(s + 0x30);
            if (0.0f < k) {
                func_0038D328(mat, s + 0x40);
                func_0038CE20(&v, &mat[0], k * *(f32 *)(s + 0x10));
                vec_add_ab(m + 0x10, &v, m + 0x10);
                func_0038CE20(&v, &mat[1], k * *(f32 *)(s + 0x14));
                vec_add_ab(m + 0x10, &v, m + 0x10);
                func_0038CE20(&v, &mat[2], k * *(f32 *)(s + 0x18));
                vec_add_ab(m + 0x10, &v, m + 0x10);
                *(f32 *)(m + 0xF0) = func_0038DAB8(*(f32 *)(s + 0x40), func_0038DB48(k * *(f32 *)(s + 0x1C) * 0.017453292f));
                *(f32 *)(m + 0xF4) = func_0038DAB8(*(f32 *)(s + 0x44), func_0038DB48(k * *(f32 *)(s + 0x20) * 0.017453292f));
                *(f32 *)(m + 0xF8) = func_0038DAB8(*(f32 *)(s + 0x48), func_0038DB48(k * *(f32 *)(s + 0x24) * 0.017453292f));
            } else {
                *(vu0_q *)(m + 0xF0) = *(vu0_q *)(s + 0x40);
            }
            func_0038D308(m + 0xC0, m + 0xF0);
            t = k;
        }
        if (1.00000011e-06f < (t - *(f32 *)(s + 0xC)) * (t - *(f32 *)(s + 0xC))) {
            func_L01_0044F450(m, s + 0x50);
        }
        *(f32 *)(s + 0xC) = t;
        break;
    }
}
/* localdecomp:end func_L04_0033B0B8 */

/* localdecomp:start func_L04_0033B308 */
extern void func_0038D308(void *, void *);
extern void func_L01_0044ED88(void *, void *, s32, s32, s32, s32, s32, s32);
extern void func_0038D328(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_0044F450(void *, void *);
extern void func_L01_004450F0(void *, s32, s32);
extern u8 D_001BBC40[][16];
extern s32 D_001D545C;

void func_L04_0033B308(u8 *m, u8 *s) {
    vu0_v4 mat[4];
    vu0_v4 v;
    u8 *ang;
    u8 *rot;

    ang = s + 0x40;
    rot = m + 0xF0;
    *(s32 *)(s + 0xC) = 0;
    *(vu0_q *)(s + 0x30) = *(vu0_q *)(m + 0x10);
    *(vu0_q *)(s + 0x40) = *(vu0_q *)(m + 0xF0);
    func_0038D308(m + 0xC0, rot);
    func_L01_0044ED88(m, s + 0x50, 8, *(s32 *)(s + 4), *(s32 *)(s + 8), -1, 7, 0);
    if (m[0xB0] != 0xFF && (D_001BBC40[D_001D545C][m[0xB0]] & 0x80)) {
        func_0038D328(mat, ang);
        func_0038CE20(&v, &mat[0], *(f32 *)(s + 0x10));
        vec_add_ab(m + 0x10, &v, m + 0x10);
        func_0038CE20(&v, &mat[1], *(f32 *)(s + 0x14));
        vec_add_ab(m + 0x10, &v, m + 0x10);
        func_0038CE20(&v, &mat[2], *(f32 *)(s + 0x18));
        vec_add_ab(m + 0x10, &v, m + 0x10);
        *(f32 *)(m + 0xF0) = func_0038DAB8(*(f32 *)(s + 0x40), func_0038DB48(*(f32 *)(s + 0x1C) * 0.017453292f));
        *(f32 *)(m + 0xF4) = func_0038DAB8(*(f32 *)(s + 0x44), func_0038DB48(*(f32 *)(s + 0x20) * 0.017453292f));
        *(f32 *)(m + 0xF8) = func_0038DAB8(*(f32 *)(s + 0x48), func_0038DB48(*(f32 *)(s + 0x24) * 0.017453292f));
        func_0038D308(m + 0xC0, rot);
        func_L01_0044F450(m, s + 0x50);
        *(f32 *)(s + 0xC) = 1.0f;
    }
    func_L01_004450F0(m, 1, -1);
}
/* localdecomp:end func_L04_0033B308 */
