#include "common.h"

/* NTSC-U counterpart of func_L10_003C6B68 (src/levels/10_zeldrin_starport/L10_003C6B68.c) */
#include "vu0.h"

/* localdecomp:start func_L10_003C47C8 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C6B68;
__asm__(".extern D_L10_001DE8DC_003C47C8, 4");
__asm__(".extern D_L10_001DE908_003C47C8, 4");
extern s32 D_L10_001DE8DC_003C47C8;
extern f32 D_L10_001DE908_003C47C8;
extern void func_0037E2F0(void *, f32, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L08_003C50F0(void *, void *, void *);
extern s32 func_00388398(void *);

void func_L10_003C47C8(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    V4_3C6B68 a;
    V4_3C6B68 b;
    s32 st;
    s32 t;
    f32 f;

    st = m[0x20];
    switch (st) {
    case 0:
        func_0037E2F0(v, 1.0f, 1.0f);
        func_003886E8(&a, m + 0xE0, -1.0f);
        vec_add_ab(v, &a, v);
        func_00388830(v, v, 1.0f);
        t = D_L10_001DE8DC_003C47C8;
        f = *(f32 *)(m + 0x2C) / D_L10_001DE908_003C47C8;
        *(f32 *)(v + 0x14) = f;
        *(s32 *)(v + 0x10) = t;
        func_L01_00441FB8(m, 1, -1);
        break;
    case 1:
        func_003886E8(&b, m + 0xE0, -*(f32 *)(v + 0x14));
        vec_add_ab(&a, &b, m + 0x10);
        func_L08_003C50F0(m, &a, v);
        if (func_00388398(v + 0x10) != 0) {
            func_L01_00441FB8(m, 2, -1);
        }
        break;
    case 2:
        break;
    }
    m[0xA8] = 0xFF;
}
/* localdecomp:end func_L10_003C47C8 */
