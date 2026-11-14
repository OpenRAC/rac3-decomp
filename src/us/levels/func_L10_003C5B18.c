#include "common.h"

/* NTSC-U counterpart of func_L10_003C7F18 (src/levels/10_zeldrin_starport/L10_003C7C28.c): 0.02 -> 0.0166667; 0.0004 -> 0.000277778; 50 -> 60 */
#include "vu0.h"

/* localdecomp:start func_L10_003C5B18 */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C7F18;
__asm__(".extern D_L10_001DE954, 4");
__asm__(".extern D_L10_001DE958, 4");
__asm__(".extern D_L10_001DE95C, 4");
extern f32 D_L10_001DE954;
extern f32 D_L10_001DE958;
extern f32 D_L10_001DE95C;
extern f32 func_0037E250(f32, f32);
extern void func_00389158(void *, void *, void *, f32);
extern void func_0037E2F0(void *, f32, f32);
extern void func_003886E8(void *, void *, f32);
extern void func_L01_0046CF70(void *, void *, s32, f32);

void func_L10_003C5B18(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    V4_3C7F18 a;
    V4_3C7F18 p;
    V4_3C7F18 t;
    s32 i;
    f32 f;

    f = func_0037E250(0.7853982f, -0.7853982f);
    func_00389158(&a, v, m + 0xD0, f);
    p = *(V4_3C7F18 *)(m + 0x10);
    for (i = 0; i < 2; i++) {
        func_0037E2F0(&t, D_L10_001DE954, D_L10_001DE954);
        vec_add_ab(&t, &t, &a);
        func_003886E8(&t, &t, func_0037E250(D_L10_001DE958 * 0.75f, D_L10_001DE958 * 1.25f) * 0.0166666675f);
        func_L01_0046CF70(&p, &t, 0x3C, D_L10_001DE95C * 0.000277777785f);
    }
}
/* localdecomp:end func_L10_003C5B18 */
