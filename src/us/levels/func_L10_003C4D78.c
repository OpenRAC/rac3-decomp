#include "common.h"

/* NTSC-U counterpart of func_L10_003C7148 (src/levels/10_zeldrin_starport/L10_003C6B68.c) */
#include "vu0.h"
extern void func_003886E8(void *, void *, f32);
extern void func_00388830(void *, void *, f32);
extern f32 func_0037E250(f32, f32);

/* localdecomp:start func_L10_003C4D78 */
typedef int u128_t_3C7148 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_3C7148;
__asm__(".extern D_L10_001DE920_003C4D78, 4");
__asm__(".extern D_L10_001DE924_003C4D78, 4");
extern f32 D_L10_001DE920_003C4D78;
extern f32 D_L10_001DE924_003C4D78;
extern void func_003886E8(void *, void *, f32);
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E208(s32, s32);
extern void func_L02_003E0520(void *, void *, f32, void *, s32, s32, f32, f32, f32, f32, s32);

void func_L10_003C4D78(u8 *m) {
    s32 *v = *(s32 **)(m + 0x68);
    V4_3C7148 b;
    V4_3C7148 q;
    V4_3C7148 w;
    f32 s;
    s32 i;
    s32 r;

    *(u128_t_3C7148 *)&q = 0;
    q.y = D_L10_001DE920_003C4D78;
    q.z = D_L10_001DE924_003C4D78;
    b = q;
    s = 3.2523499f;
    func_003886E8(&b, &b, s);
    for (i = 0; i < 2; i++) {
        *(u128_t_3C7148 *)&w = 0;
        w.x = func_0037E250(-1.0f, 1.0f);
        w.y = func_0037E250(-1.0f, 1.0f);
        w.z = func_0037E250(0.0f, 2.0f);
        q = w;
        vec_add_ba(&q, &q, m + 0xC0);
        func_00388830(&q, &q, func_0037E250(1.5f, 3.0f) * 0.016666668f);
        r = func_0037E208(3, 6);
        func_L02_003E0520(m, &b, 0.0f, &q, r, (i & 1) ? 3 : 0, 0.033333335f, s * 0.5f, 15.0f, 1.0f, 0);
    }
    *v = func_0037E208(0x5A, 0xB4);
}
/* localdecomp:end func_L10_003C4D78 */
