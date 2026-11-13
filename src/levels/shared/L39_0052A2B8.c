#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0052A2B8);

INCLUDE_ASM("asm/levels", func_L39_0052AA00);

/* localdecomp:start func_L39_0052B400 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 *func_003C24B0(s32, s32);
extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
extern void func_003C2F58(s32, s32, void *);
extern void func_003C3A10(u8 *, s32, s32, s32);
extern void func_003C7C38(u8 *);
u8 *func_L39_0052B400(u8 *a0, f32 f) {
    u8 *m;
    u8 *pv;
    m = func_003C24B0(6369, 128);
    if (m != 0) {
        pv = *(u8 **)(m + 104);
        *(f32 *)(pv + 4) = f;
        *(u8 **)pv = a0;
        m[48] = 255;
        *(s16 *)(m + 50) = 255;
        m[49] = 1;
        func_L01_0043B9E8(m, 128, 128, 128);
        func_003C2F58((s32)a0, 0, m + 16);
        *(u128_t *)(m + 192) = *(u128_t *)(a0 + 192);
        *(u128_t *)(m + 208) = *(u128_t *)(a0 + 208);
        *(u128_t *)(m + 224) = *(u128_t *)(a0 + 224);
        if (m[67] != 0) {
            func_003C3A10(m, 0, 0, 8);
        }
        func_003C7C38(m);
        m[32] = 0;
        *(u16 *)(m + 52) |= 5;
    }
    return m;
}
/* localdecomp:end func_L39_0052B400 */

INCLUDE_ASM("asm/levels", func_L39_0052B4E0);
