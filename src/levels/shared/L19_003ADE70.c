#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

INCLUDE_ASM("asm/levels", func_L19_003ADE70);

INCLUDE_ASM("asm/levels", func_L19_003AE108);

INCLUDE_ASM("asm/levels", func_L19_003AE5A8);

/* localdecomp:start func_L19_003AEBD8 */
extern void func_L01_004450F0(void *, int, int);
void func_L19_003AEBD8(unsigned char *a) {
    if (a[32] == 1) {
        func_L01_004450F0(a, 3, -1);
    }
}
/* localdecomp:end func_L19_003AEBD8 */

/* localdecomp:start func_L19_003AEC08 */

extern void func_L01_0040A8C0(u128_t *a, u128_t *b, s32 c, s32 d, u32 c0, u32 c1, u32 c2, u32 c3,
                          f32 f0, f32 f1, f32 f2);
extern void func_003D9508(void *p, s32 a, u32 color, s32 b, f32 f0, f32 f1, f32 f2);

void func_L19_003AEC08(u8 *moby) {
    u128_t v[2];
    u8 *pvars = *(u8 **)(moby + 104);
    v[0] = *(u128_t *)(moby + 16);
    v[1] = *(u128_t *)(pvars + 96);
    func_L01_0040A8C0(&v[0], &v[1], 14, 1, 0x401010FF, 0x401010FF, 0x401010FF, 0x401010FF, 0.05f, 1.0f, 0.5f);
    func_003D9508(pvars + 96, 6, 0x401010FF, 1, 0.175f, 0.08f, 0.0f);
}
/* localdecomp:end func_L19_003AEC08 */

INCLUDE_ASM("asm/levels", func_L19_003AECC0);

INCLUDE_ASM("asm/levels", func_L19_003AEFA8);

INCLUDE_ASM("asm/levels", func_L19_003AF080);
