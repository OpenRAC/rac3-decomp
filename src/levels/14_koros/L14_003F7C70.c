#include "common.h"
#include "vu0.h"

INCLUDE_ASM("asm/levels", func_L14_003F7C70);

INCLUDE_ASM("asm/levels", func_L14_003F7EB8);

/* localdecomp:start func_L14_003F8060 */
typedef struct { f32 x, y, z, w; } V_3F8060;
extern V_3F8060 D_L14_001E20C0;
extern f32 D_L14_001E20C0_z[];
extern f32 func_003C4088(f32, f32, f32);
extern f32 func_0038CF00(void *, void *);
s32 func_L14_003F8060(u8 *a0, vu0_v4 *a1, f32 scale) {
    vu0_v4 aq;
    V_3F8060 b;
    f32 r;
    f32 d;
    s32 n;
    aq = *a1;
    b.x = aq.x;
    b.y = aq.y;
    b.z = D_L14_001E20C0_z[2];
    r = func_003C4088(*(f32 *)(a0 + 0xE68), *(f32 *)(a0 + 0xE6C), (aq.z - D_L14_001E20C0_z[2]) / *(f32 *)(a0 + 8));
    if (r > *(f32 *)(a0 + 8)) {
        r = *(f32 *)(a0 + 8);
    } else if (r < 0.0f) {
        r = 0.0f;
    }
    d = func_0038CF00(&b, &D_L14_001E20C0);
    n = (s32)func_003C4088(0.0f, 127.0f, scale * (d - (r + 0.5f)));
    if (n > 0x80) {
        n = 0x80;
    } else if (n < 0) {
        n = 0;
    }
    return n;
}
/* localdecomp:end func_L14_003F8060 */

/* localdecomp:start func_L14_003F8170 */
extern void func_003D3A24(s32, s32, s32, s32, s32);
void func_L14_003F8170(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    s32 i = a0;
    s32 k = i - 3;
    func_003D3A24(a1 - k, i * 12 + a2, a3 + i * 4, a4 + i * 8, 1);
}
/* localdecomp:end func_L14_003F8170 */

INCLUDE_ASM("asm/levels", func_L14_003F81B8);

INCLUDE_ASM("asm/levels", func_L14_003F8550);
