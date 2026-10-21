#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef union {
    u128_t q;
    f32 f[4];
} Vec4;

/* localdecomp:start func_L05_0035D560 */
extern void func_L05_0035E050(s32);
extern void func_L05_0035DF68(s32);

void func_L05_0035D560(s32 a0) {
    u8 buf[448];
    func_L05_0035E050(a0);
    func_L05_0035DF68(a0);
}
/* localdecomp:end func_L05_0035D560 */

INCLUDE_ASM("asm/levels", func_L05_0035D590);

INCLUDE_ASM("asm/levels", func_L05_0035DA38);

INCLUDE_ASM("asm/levels", func_L05_0035DF68);

INCLUDE_ASM("asm/levels", func_L05_0035E050);

INCLUDE_ASM("asm/levels", func_L05_0035E148);

/* localdecomp:start func_L05_0035E5A8 */
extern s32 D_L05_001EA6D8[];
extern s32 func_003D3CB0(Vec4 *a0, Vec4 *a1, s32 a2, u8 *a3, s32 t0);
void func_L05_0035E5A8(u8 *a0) {
    Vec4 a;
    Vec4 b;
    u8 *s0;
    a.q = *(u128_t *)(a0 + 16);
    s0 = *(u8 **)(a0 + 104);
    b.q = *(u128_t *)(s0 + 768);
    a.f[2] += *(f32 *)(s0 + 120);
    b.f[2] += *(f32 *)(s0 + 120);
    if (!func_003D3CB0(&a, &b, 16, a0, 0) || (D_L05_001EA6D8[0] != 0 && D_L05_001EA6D8[0] == *(s32 *)(s0 + 560))) {
        *(u128_t *)(s0 + 784) = *(u128_t *)(s0 + 752) = *(u128_t *)(s0 + 768);
    }
}
/* localdecomp:end func_L05_0035E5A8 */

/* localdecomp:start func_L05_0035E640 */
extern s32 func_003D3CB0(Vec4 *a0, Vec4 *a1, s32 a2, u8 *a3, s32 t0);
extern s32 D_L05_001EA6D8[];
extern void func_003C2F58(u8 *a0, s32 a1, u8 *a2);
s32 func_L05_0035E640(u8 *a0) {
    u8 buf[16];
    u128_t q;
    u8 *s1;
    s32 d;
    s1 = *(u8 **)(a0 + 104);
    func_003C2F58(a0, 6, buf);
    q = *(u128_t *)(s1 + 544);
    if (((s32 (*)(u8 *a0, u128_t *a1, s32 a2, u8 *a3, s32 t0))func_003D3CB0)(buf, &q, 16, a0, 0) == 0) {
        return 1;
    }
    d = D_L05_001EA6D8[0];
    if (d != 0) {
        if (d == *(s32 *)(s1 + 560)) {
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L05_0035E640 */

INCLUDE_ASM("asm/levels", func_L05_0035E6C8);

INCLUDE_ASM("asm/levels", func_L05_0035E820);

INCLUDE_ASM("asm/levels", func_L05_0035E8F0);
