#include "common.h"

/* localdecomp:start func_L39_005CF720 */
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

extern void *func_003CD108(s32);
extern s32 func_0019D510();
extern void func_0038D5B0(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern u8 *D_L39_00296940[];

void *func_L39_005CF720(u8 *a0, u128_t *a1, f32 *a2, u8 *a3, s32 flag) {
    u8 *p = func_003CD108(0x4A);
    u8 *s;
    vu0_v4 v;
    vu0_v4 m[4];

    if (p != 0) {
        p[9] = 0xA0;
        p[3] = flag ? 0x48 : 0x44;
        p[1] = 0;
        p[2] = D_L39_00296940[0][0];
        p[8] = func_0019D510();
        *(s32 *)(p + 0xC) = 0;
        *(u128_t *)(p + 0x10) = *a1;
        s = p + 0x20;
        *(f32 *)(p + 0x20) = a2[0];
        *(f32 *)(s + 4) = a2[1];
        *(f32 *)(s + 8) = a2[2];
        if (a0 != 0) {
            vec_sub_ab(&v, a1, a0 + 0x10);
            qzero(&m[0]);
            qzero(&m[1]);
            qzero(&m[2]);
            qzero(&m[3]);
            func_0038D5B0(m, a0 + 0xC0);
            func_0038D028(&v, &v, m);
            *(f32 *)(s + 0x10) = v.x;
            *(f32 *)(s + 0x14) = v.y;
            *(f32 *)(s + 0x18) = v.z;
        }
        *(u8 **)(s + 0xC) = a0;
        *(u8 **)(s + 0x1C) = a3;
        *(u16 *)(p + 0xA) = *(u16 *)(a3 + 0xC);
        *(s32 *)(p + 4) = *(s32 *)a3;
    }
    return p;
}
/* localdecomp:end func_L39_005CF720 */
