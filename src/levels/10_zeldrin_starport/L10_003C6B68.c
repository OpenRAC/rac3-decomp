#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L10_003C6B68 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C6B68;
__asm__(".extern D_L10_001DE8AC, 4");
__asm__(".extern D_L10_001DE8D8, 4");
extern s32 D_L10_001DE8AC;
extern f32 D_L10_001DE8D8;
extern void func_00382580(void *, f32, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_L01_004450F0(void *, s32, s32);
extern void func_L08_003C73B8(void *, void *, void *);
extern s32 func_0038CAD0(void *);

void func_L10_003C6B68(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    V4_3C6B68 a;
    V4_3C6B68 b;
    s32 st;
    s32 t;
    f32 f;

    st = m[0x20];
    switch (st) {
    case 0:
        func_00382580(v, 1.0f, 1.0f);
        func_0038CE20(&a, m + 0xE0, -1.0f);
        vec_add_ab(v, &a, v);
        func_0038CF68(v, v, 1.0f);
        t = (D_L10_001DE8AC * 5 + 2) / 6;
        f = *(f32 *)(m + 0x2C) / D_L10_001DE8D8;
        *(f32 *)(v + 0x14) = f;
        *(s32 *)(v + 0x10) = t;
        func_L01_004450F0(m, 1, -1);
        break;
    case 1:
        func_0038CE20(&b, m + 0xE0, -*(f32 *)(v + 0x14));
        vec_add_ab(&a, &b, m + 0x10);
        func_L08_003C73B8(m, &a, v);
        if (func_0038CAD0(v + 0x10) != 0) {
            func_L01_004450F0(m, 2, -1);
        }
        break;
    case 2:
        break;
    }
    m[0xA8] = 0xFF;
}
/* localdecomp:end func_L10_003C6B68 */

INCLUDE_ASM("asm/levels", func_L10_003C6CB8);

INCLUDE_ASM("asm/levels", func_L10_003C6ED0);

INCLUDE_ASM("asm/levels", func_L10_003C7148);
