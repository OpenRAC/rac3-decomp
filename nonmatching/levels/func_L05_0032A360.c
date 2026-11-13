/* Level 5. File L05_00328BF8.c (@ps2as). check.py: 23 diff. The case a2 == n-2 differs (retail copies the element pointer into $a0 before the second lq) and the last case's addressing; the first and third cases match. */
#include "common.h"

typedef int u128_32A360 __attribute__((mode(TI)));
extern void func_0038CDF8(f32 *, f32 *, f32 *, f32);

void func_L05_0032A360(u8 *a0, u8 *a1, s32 a2, f32 *dst, f32 t) {
    u128_32A360 v0;
    u128_32A360 v1;
    u128_32A360 *pts = (u128_32A360 *)a1;
    u128_32A360 *q;
    s32 n = *(s32 *)a1;
    if (a2 >= n) {
        v0 = *(u128_32A360 *)(a0 + 0x190);
        v1 = *(u128_32A360 *)(a0 + 0x1A0);
    } else if (a2 == n - 2) {
        q = pts + a2;
        v0 = q[1];
        v1 = q[2];
    } else if (a2 == n - 1) {
        v1 = *(u128_32A360 *)(a0 + 0x190);
        v0 = pts[a2 + 1];
    } else {
        if (a2 < 0) {
            v0 = *(u128_32A360 *)(a0 + 0x180);
        } else {
            v0 = pts[a2 + 1];
        }
        v1 = pts[a2 + 2];
    }
    func_0038CDF8(dst, (f32 *)&v0, (f32 *)&v1, t);
}
