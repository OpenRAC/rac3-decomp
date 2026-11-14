#include "common.h"

/* NTSC-U counterpart of func_L10_003C6250 (src/levels/10_zeldrin_starport/L10_003C5FE8.c) */
#include "vu0.h"

/* localdecomp:start func_L10_003C3F00 */
typedef int u128_t_3C6250 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C6250;
__asm__(".extern D_L10_001DE8D0, 4");
extern f32 D_L10_001DE8D0;
extern void func_003886E8(void *, void *, f32);
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);

void func_L10_003C3F00(u8 *m) {
    s32 *v = *(s32 **)(m + 0x68);
    V4_3C6250 b;
    V4_3C6250 q;
    V4_3C6250 c;
    V4_3C6250 w;
    f32 s;
    s32 i;
    s32 r;

    *(u128_t_3C6250 *)&q = 0;
    q.z = D_L10_001DE8D0;
    b = q;
    s = 21.848372f;
    func_003886E8(&b, &b, s);
    for (i = 0; i < 2; i++) {
        func_003886E8(&c, m + 0xC0, func_0037E250(-1.0f, 1.0f) * s);
        vec_add_ab(&q, &c, &b);
        *(u128_t_3C6250 *)&w = 0;
        w.x = func_0037E250(-1.0f, 1.0f);
        w.y = func_0037E250(-1.0f, 1.0f);
        w.z = func_0037E250(0.0f, 2.0f);
        c = w;
        func_003886E8(&w, m + 0xE0, 1.0f);
        vec_add_ab(&c, &w, &c);
        func_00388830(&c, &c, func_0037E250(1.5f, 3.0f) * 0.016666668f);
        r = func_0037E208(3, 6);
        func_L02_003E0520(m, &q, 0.0f, &c, r, i & 1, 0.033333335f, s * 1.5f * *(f32 *)(m + 0x2C), 15.0f, 1.0f, 0);
    }
    *v = func_0037E208(0x5A, 0xB4);
}
/* localdecomp:end func_L10_003C3F00 */
