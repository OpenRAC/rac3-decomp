#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L10_003C7378);

INCLUDE_ASM("asm/levels", func_L10_003C75E8);

/* localdecomp:start func_L10_003C78B8 */
typedef int u128_t_3C78B8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C78B8;
__asm__(".extern D_L10_001DE918, 4");
extern f32 D_L10_001DE918;
extern void func_0038CE20(void *, void *, f32);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_00382498(s32, s32);
extern void func_L02_003E2E38(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);

void func_L10_003C78B8(u8 *m) {
    s32 *v = *(s32 **)(m + 0x68);
    V4_3C78B8 b;
    V4_3C78B8 q;
    V4_3C78B8 c;
    V4_3C78B8 w;
    f32 s;
    s32 i;
    s32 r;

    *(u128_t_3C78B8 *)&q = 0;
    q.z = D_L10_001DE918;
    b = q;
    s = 5.05025f;
    func_0038CE20(&b, &b, s);
    for (i = 0; i < 2; i++) {
        func_0038CE20(&c, m + 0xC0, func_003824E0(-1.7f, 1.7f) * s);
        vec_add_ab(&q, &c, &b);
        func_0038CE20(&c, m + 0xD0, func_003824E0(-0.6f, 0.6f) * s);
        vec_add_ab(&q, &c, &q);
        *(u128_t_3C78B8 *)&w = 0;
        w.x = func_003824E0(-1.0f, 1.0f);
        w.y = func_003824E0(-1.0f, 1.0f);
        w.z = func_003824E0(-2.0f, 0.0f);
        c = w;
        func_0038CE20(&w, m + 0xE0, -1.0f);
        vec_add_ab(&c, &w, &c);
        func_0038CF68(&c, &c, func_003824E0(1.5f, 3.0f) * 0.020000001f);
        r = func_00382498(3, 6);
        func_L02_003E2E38(m, &q, 0.0f, &c, r, (i & 1) ? 3 : 0, 0.040000003f, s * 0.5f, 15.0f, 1.0f, 0);
    }
    *v = (func_00382498(0x5A, 0xB4) * 5 + 2) / 6;
}
/* localdecomp:end func_L10_003C78B8 */
