#include "common.h"

/* localdecomp:start func_L39_00561630 */
typedef struct {
    u8 pad0[0x18];
    s32 x18;
    u8 pad1C[0x10];
    f32 x2C;
} S_00561630;

typedef struct {
    u8 pad0[0x68];
    S_00561630 *p68;
} O_00561630;

extern f32 D_L39_0024B460;
extern void func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                          s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);

void func_L39_00561630(O_00561630 *a0, u8 *a1) {
    S_00561630 *p = a0->p68;
    if (p->x2C > 0.0f) {
        func_L01_003303B8(a1, 0, 0, 20, 20, 10, 45, 0, D_L39_0024B460, 0.0f, (f32)p->x18, p->x2C,
                          0, 0, 0, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    } else {
        func_L01_003303B8(a1, 0, 0, 20, 20, 10, 45, 0, D_L39_0024B460, 0.0f, 0.0f, 2.0f,
                          0, 0, 0, 0, 1, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    }
}
/* localdecomp:end func_L39_00561630 */

INCLUDE_ASM("asm/levels", func_L39_005617D8);

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
