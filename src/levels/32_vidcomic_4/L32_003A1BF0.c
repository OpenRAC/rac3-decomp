#include "common.h"
#include "vu0.h"

/* declared by functions of L32_003A0BB8.c, which this file was cut from */
extern f32 D_L32_001DE6C8;

/* localdecomp:start func_L32_003A1BF0 */
extern f32 D_L32_001DE6FC;
extern f32 D_L32_001DE6C8;
extern f32 D_L32_001DE700;
__asm__(".extern D_L32_001DE6FC, 4");
__asm__(".extern D_L32_001DE6C8, 4");
__asm__(".extern D_L32_001DE700, 4");
extern u8 D_L32_001D66B0[] __attribute__((section(".sdata")));
extern f32 func_0038CEA8(void *);
extern void func_003C4360(void *, f32, f32, f32, f32);
extern s32 func_L30_0034D1E8(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);

void func_L32_003A1BF0(void *arg0, void *arg1, f32 r, f32 s) {
    vu0_v4 d;
    u8 *p;
    f32 a;

    vec_sub_ab(&d, arg1, (u8 *)arg0 + 0x10);
    p = *(u8 **)((u8 *)arg0 + 0x68);
    if (func_0038CEA8(&d) > 0.0f) {
        a = r * __builtin_fabsf(d.x / func_0038CEA8(&d));
        r = r * __builtin_fabsf(d.z / func_0038CEA8(&d));
    } else {
        a = r;
    }
    func_003C4360(p + 0x60, d.x, a, a, D_L32_001DE6FC);
    func_003C4360(p + 0x68, d.z, r, r, 2.0000002f);
    func_L30_0034D1E8(arg0, (u8 *)arg0 + 0x10, p + 0x60, D_L32_001D66B0, D_L32_001DE6C8, 0.0f, s,
                      s * D_L32_001DE6FC, D_L32_001DE700, 0.0f, 1, 0, 0, 1);
}
/* localdecomp:end func_L32_003A1BF0 */
