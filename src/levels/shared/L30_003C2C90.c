#include "common.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L30_003C2C90 */

extern u128_t D_L30_001E1CD0;
extern u128_t D_L30_001E1CC0;
extern void func_0038CF68(u8 *, u8 *, f32);
extern void func_0038CE90(u8 *, u8 *, u8 *);

void func_L30_003C2C90(u8 *m) {
    u8 *p;

    *(u128_t *)m = D_L30_001E1CD0;
    func_0038CF68(m, m, 1.0f);
    p = m + 32;
    *(u128_t *)p = D_L30_001E1CC0;
    func_0038CF68(p, p, 1.0f);
    func_0038CE90(m + 16, m, p);
}
/* localdecomp:end func_L30_003C2C90 */

/* localdecomp:start func_L30_003C2D18 */

extern u8 *D_L30_001DEF84[];
extern void func_L30_003A8E10(s32, u128_t *, u128_t *, s32);

void func_L30_003C2D18(u8 *a0) {
    u128_t out;
    u128_t tmp;
    u8 *s = *(u8 **)(D_L30_001DEF84[0] + *(s16 *)(a0 + 132) * 32 + 28);

    tmp = *(u128_t *)(a0 + 48);
    func_L30_003A8E10(*(s32 *)(s + 252), &out, &tmp, *(s32 *)(s + 36));
    *(u128_t *)(a0 + 48) = out;
}
/* localdecomp:end func_L30_003C2D18 */

/* localdecomp:start func_L30_003C2D78 */
s32 func_L30_003C2D78(void) {
    return -1;
}
/* localdecomp:end func_L30_003C2D78 */

INCLUDE_ASM("asm/levels", func_L30_003C2D80);
