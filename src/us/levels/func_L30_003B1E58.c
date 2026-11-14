#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L30_003B1E58 */
extern struct {
    u8 p0[0x188];
    u8 *f188;
} D_L30_0021F098;
extern f32 D_001DED5C_sda;
__asm__(".extern D_001DED5C_sda, 4");
extern s32 D_001DED54_sda;
__asm__(".extern D_001DED54_sda, 4");
extern s32 D_001DED58_sda_003B1E58;
__asm__(".extern D_001DED58_sda_003B1E58, 4");
extern s32 D_001DED4C_sda;
__asm__(".extern D_001DED4C_sda, 4");
extern s32 D_001DED50_sda;
__asm__(".extern D_001DED50_sda, 4");
extern f32 D_001DED60_sda;
__asm__(".extern D_001DED60_sda, 4");
extern f32 D_001DED64_sda;
__asm__(".extern D_001DED64_sda, 4");
extern f32 D_001DED68_sda;
__asm__(".extern D_001DED68_sda, 4");
extern f32 D_001DED6C_sda;
__asm__(".extern D_001DED6C_sda, 4");
extern void func_0037E2F0(void *, f32, f32);
extern f32 func_0037E250(f32, f32);
extern void func_00388830(void *, void *, f32);
extern s32 func_0037E1D8(s32);
extern s32 func_0037E208(s32, s32);
extern u8 *func_L01_004708F8(void *, void *, s32, f32, f32, f32, f32, s32, s32, s32, s32);

void func_L30_003B1E58(u8 *obj, s32 count) {
    f32 a[4] __attribute__((aligned(16)));
    f32 b[4] __attribute__((aligned(16)));
    u8 *p;
    s32 lifetime;
    s32 i;

    for (i = 0; i < count; i++) {
        func_0037E2F0(a, 0.1f, 1.5f);
        func_00388830(b, a, func_0037E250(D_001DED5C_sda * 0.7f, D_001DED5C_sda) * 0.016666668f);
        b[1] = -fabs_asm(b[1]);
        if (func_0037E1D8(3) != 0) {
            b[2] = fabs_asm(b[2]);
        }
        func_0037E2F0(a, 0.1f, 1.5f);
        vec_add_ab(a, a, obj + 0x10);
        lifetime = func_0037E208(D_001DED54_sda, D_001DED58_sda_003B1E58);
        p = func_L01_004708F8(a, b, lifetime, D_001DED60_sda, D_001DED64_sda, D_001DED68_sda, D_001DED6C_sda,
                              D_001DED4C_sda, D_001DED50_sda, func_0037E208(D_001DED54_sda - 5, D_001DED54_sda), 0);
        if (p != 0) {
            p[2] = *D_L30_0021F098.f188;
        }
    }
}
/* localdecomp:end func_L30_003B1E58 */
