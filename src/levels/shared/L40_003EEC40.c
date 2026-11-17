#include "common.h"

INCLUDE_ASM("asm/levels", func_L40_003EEC40);

INCLUDE_ASM("asm/levels", func_L40_003EEE80);

/* localdecomp:start func_L40_003EFC00 */
#include "vu0.h"
__asm__(".extern D_L40_00246D94, 4");
extern f32 D_L40_00246D94;
extern s32 D_001A5DF8[];
extern void func_0038CE20(void *d, void *s, f32 k);
extern f32 func_0038CEA8(void *);
extern f32 func_0038D160(f32, f32);
extern void func_L40_003F1E48(u8 *m, void *p, f32 yaw);

void func_L40_003EFC00(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    vu0_v4 d;
    s32 n;
    f32 len;
    f32 yaw;
    f32 k;

    vec_sub_ba(&d, v + 0x2D0, m + 0x10);
    n = *(s32 *)(v + 0x2B4) + (s32)D_L40_00246D94 - D_001A5DF8[0];
    n = (s32)(n * 0.06f);
    d.z = 0.0f;
    if (n <= 0) {
        n = 0;
    }
    n += 1;
    k = 1.0f / n;
    func_0038CE20(v + 0x110, &d, k);
    len = func_0038CEA8(v + 0x110);
    if (len == 0.0f) {
        *(s32 *)(v + 0x250) -= 1;
    } else {
        yaw = func_0038D160(*(f32 *)(v + 0x2D0) - *(f32 *)(m + 0x10), *(f32 *)(v + 0x2D4) - *(f32 *)(m + 0x14));
        if (n != 1) {
            func_L40_003F1E48(m, v + 0x2D0, yaw);
        } else {
            func_L40_003F1E48(m, v + 0x2D0, yaw);
        }
        *(s32 *)(v + 0x250) -= 1;
    }
}
/* localdecomp:end func_L40_003EFC00 */
