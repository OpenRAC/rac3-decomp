#include "common.h"

/* NTSC-U counterpart of func_L10_003C8048 (src/levels/10_zeldrin_starport/L10_003C7C28.c) */
#include "vu0.h"
extern f32 func_00389410(f32);
extern f32 func_0037E250(f32, f32);
extern void func_003886E8(void *, void *, f32);

/* localdecomp:start func_L10_003C5C48 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C8048;
__asm__(".extern D_L10_001DE960, 4");
__asm__(".extern D_L10_001DE964, 4");
__asm__(".extern D_L10_001DE968, 4");
extern f32 D_L10_001DE960;
extern s32 D_L10_001DE964;
extern s32 D_L10_001DE968;
extern u8 D_001A4C60[];
extern f32 func_00388730(void *, void *);
extern void func_003886E8(void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern f32 func_0037E250(f32, f32);
extern void func_L01_00441FB8(void *, s32, s32);
extern s32 func_00388398(void *);
extern void func_L01_0044EBF8(void *, s32, f32);
extern s32 func_0037E1D8(s32);
extern void func_L10_003C5B18(u8 *);
extern f32 func_00389410(f32);

void func_L10_003C5C48(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    V4_3C8048 d;
    s32 t;
    f32 r;

    switch (m[0x20]) {
    case 0:
        vec_sub_ba(&d, D_001A4C60, m + 0x10);
        if (func_00388730(&d, m + 0xE0) > 0.0f) {
            *(V4_3C8048 *)v = *(V4_3C8048 *)(m + 0xE0);
        } else {
            func_003886E8(v, m + 0xE0, -1.0f);
        }
        t = func_0037E208(200, 400);
        *(s32 *)(v + 0x14) = 0;
        *(s32 *)(v + 0x1C) = t;
        *(s32 *)(v + 0x10) = t;
        *(f32 *)(v + 0x18) = func_0037E250(0.68f, 0.72000003f);
        func_L01_00441FB8(m, 1, -1);
        break;
    case 1:
        if (func_00388398(v + 0x10) != 0) {
            func_L01_0044EBF8(m, 1, 0.0f);
            func_L01_00441FB8(m, 2, -1);
        }
        if (func_00388398(v + 0x14) != 0) {
            r = (f32)*(s32 *)(v + 0x10) / (f32)*(s32 *)(v + 0x1C);
            if (*(f32 *)(v + 0x18) < r && func_0037E1D8(D_L10_001DE968) == 0) {
                *(s32 *)(v + 0x14) = D_L10_001DE964;
                func_L10_003C5B18(m);
            }
            *(f32 *)(m + 0xF4) = func_00389410(*(f32 *)(m + 0xF4) + D_L10_001DE960 * r);
        }
        break;
    }
    m[0xA8] = 0xFF;
}
/* localdecomp:end func_L10_003C5C48 */
