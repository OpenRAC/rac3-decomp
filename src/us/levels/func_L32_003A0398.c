#include "common.h"

/* NTSC-U counterpart of func_L32_003A1BF0 (src/levels/32_vidcomic_4/L32_003A1BF0.c) */
#include "vu0.h"
extern f32 D_L32_001DE708_003A0398;

/* localdecomp:start func_L32_003A0398 */
extern f32 D_L32_001DE73C;
extern f32 D_L32_001DE708_003A0398;
extern f32 D_L32_001DE740;
__asm__(".extern D_L32_001DE73C, 4");
__asm__(".extern D_L32_001DE708_003A0398, 4");
__asm__(".extern D_L32_001DE740, 4");
extern u8 D_L32_001D66B0_003A0398[] __attribute__((section(".sdata")));
extern f32 func_00388770(void *);
extern void func_003BEE20(void *, f32, f32, f32, f32);
extern s32 func_L30_0034C308(void *, void *, void *, void *, f32, f32, f32, f32, f32, f32, s32, s32, s32, s32);

void func_L32_003A0398(void *arg0, void *arg1, f32 r, f32 s) {
    vu0_v4 d;
    u8 *p;
    f32 a;

    vec_sub_ab(&d, arg1, (u8 *)arg0 + 0x10);
    p = *(u8 **)((u8 *)arg0 + 0x68);
    if (func_00388770(&d) > 0.0f) {
        a = r * __builtin_fabsf(d.x / func_00388770(&d));
        r = r * __builtin_fabsf(d.z / func_00388770(&d));
    } else {
        a = r;
    }
    func_003BEE20(p + 0x60, d.x, a, a, D_L32_001DE73C);
    func_003BEE20(p + 0x68, d.z, r, r, 1.66666675f);
    func_L30_0034C308(arg0, (u8 *)arg0 + 0x10, p + 0x60, D_L32_001D66B0_003A0398, D_L32_001DE708_003A0398, 0.0f, s,
                      s * D_L32_001DE73C, D_L32_001DE740, 0.0f, 1, 0, 0, 1);
}
/* localdecomp:end func_L32_003A0398 */
