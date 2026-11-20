#include "common.h"

/* localdecomp:start func_L39_00561D28 */
/* from func_L22_00344050 (rac3, level 22), the same object spawner */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_00456160(void *, s32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern u8 *func_00382348(s32);
u8 *func_L39_00561D28(s32 a0, u128_t *a1, u128_t *a2, s32 a3, s32 a4, f32 fa, s32 a5, f32 fb, s32 a6, f32 fc) {
    u8 *o = func_003C24B0(0x1B1E, 0x80);
    u8 *st;
    u8 *q;
    u128_t tmp;
    u8 *c0;
    u8 *d0;
    u8 *e0;
    if (o != 0) {
        st = *(u8 **)(o + 0x68);
        func_L01_00456160(o, a0);
        c0 = o + 0xC0;
        d0 = o + 0xD0;
        e0 = o + 0xE0;
        *(u128_t *)(o + 0x10) = *a1;
        tmp = *a2;
        func_0038CF68(&tmp, &tmp, 1.0f);
        *(u128_t *)c0 = tmp;
        func_0038CE90(d0, c0, e0);
        func_0038CE90(e0, d0, c0);
        *(u128_t *)st = *a2;
        *(s32 *)(st + 0x14) = a0;
        *(s32 *)(st + 0x18) = a3;
        *(s32 *)(st + 0x1C) = a4;
        *(f32 *)(st + 0x20) = fa;
        *(f32 *)(st + 0x28) = fb;
        *(f32 *)(st + 0x2C) = fc;
        *(u16 *)(st + 0x12) = 0;
        *(u16 *)(st + 0x10) = (a6 * 5 + 2) / 6;
        if (a5 != 0) {
            q = func_00382348(a5);
            *(u16 *)(o + 0x34) = *(u16 *)(o + 0x34) | 0x100;
            if (q != 0) {
                *(u16 *)(q + 0x1E) = *(u16 *)(q + 0x1E) | 0x80;
                if (q[0xB] != 0) {
                    *(s32 *)(st + 0x24) = 0;
                } else {
                    *(s32 *)(st + 0x24) = a5;
                }
            }
        }
        *(f32 *)(o + 0x2C) = *(f32 *)(*(u8 **)(o + 0x24) + 0x24) * 0.5f;
    }
    return o;
}
/* localdecomp:end func_L39_00561D28 */
