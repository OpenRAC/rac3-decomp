#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union { u128_t q; f32 f[4]; } Vec4;

/* localdecomp:start func_L30_003A10B8 */
typedef struct { u8 pad0[0x100]; f32 x100; u8 pad1[0x35C - 0x104]; u8 *x35C; s32 x360; } S_003A10B8;
extern S_003A10B8 D_001A4BE0;
extern f32 D_L30_001E2258 __attribute__((section(".data")));
extern f32 D_L30_001DE880;
extern f32 func_0038DBA0(f32, f32);
void func_L30_003A10B8(u8 *a0) {
    S_003A10B8 *h = &D_001A4BE0;
    if (h->x35C == a0 && h->x360 != 0) {
        if (func_0038DBA0(*(f32 *)(a0 + 0xF8), D_L30_001E2258) < 1.5707964f) {
            h->x100 = D_L30_001DE880 * 0.020000001f;
        } else {
            h->x100 = -(D_L30_001DE880 * 0.020000001f);
        }
    }
}
/* localdecomp:end func_L30_003A10B8 */

INCLUDE_ASM("asm/levels", func_L30_003A1150);

INCLUDE_ASM("asm/levels", func_L30_003A14F8);
