#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_003C7560);

INCLUDE_ASM("asm/levels", func_L01_003C76A0);

INCLUDE_ASM("asm/levels", func_L01_003C7810);

/* localdecomp:start func_L01_003C7A68 */
extern void func_L01_00477ED0(int, int, float, float, float);
void func_L01_003C7A68(void *a, char *b, float f) {
    func_L01_00477ED0(*(int *)(b + 192), 1, *(float *)(b + 332), *(float *)(b + 196), f);
}
/* localdecomp:end func_L01_003C7A68 */

INCLUDE_ASM("asm/levels", func_L01_003C7A98);

/* localdecomp:start func_L01_003C7BC0 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    s32 count;
    u128_t e[1];
} L_003C7BC0;
extern void func_0038CDF8(u8 *, u128_t *, u128_t *);

static inline u128_t quad_003C7BC0(u128_t *p) {
    return *p;
}

void func_L01_003C7BC0(u8 *a0, L_003C7BC0 *l, s32 idx, u8 *out) {
    u128_t a;
    u128_t b;
    s32 n = l->count;
    if (idx >= n) {
        a = quad_003C7BC0((u128_t *)(a0 + 0x150));
        b = quad_003C7BC0((u128_t *)(a0 + 0x160));
    } else if (idx == n - 2) {
        a = quad_003C7BC0(&l->e[idx]);
        b = quad_003C7BC0(&l->e[idx + 1]);
    } else if (idx == n - 1) {
        a = quad_003C7BC0(&l->e[idx]);
        b = quad_003C7BC0((u128_t *)(a0 + 0x150));
    } else {
        if (idx < 0) {
            a = quad_003C7BC0((u128_t *)(a0 + 0x140));
        } else {
            a = quad_003C7BC0(&l->e[idx]);
        }
        b = quad_003C7BC0(&l->e[idx + 1]);
    }
    func_0038CDF8(out, &a, &b);
}
/* localdecomp:end func_L01_003C7BC0 */

INCLUDE_ASM("asm/levels", func_L01_003C7C80);

INCLUDE_ASM("asm/levels", func_L01_003C7D38);

INCLUDE_ASM("asm/levels", func_L01_003C8400);

INCLUDE_ASM("asm/levels", func_L01_003C88E0);

/* localdecomp:start func_L01_003C8D60 */
extern void func_L01_003C8400(u8 *, u8 *);
extern void func_L01_003C88E0(u8 *, u8 *);
extern void func_003A9440(s32, unsigned long);

void func_L01_003C8D60(u8 *a0) {
    u8 *s = *(u8 **)(a0 + 104);

    func_L01_003C8400(a0, s);
    func_L01_003C88E0(a0, s);
    func_003A9440(8, 0);
    func_003A9440(71, 0x5360B);
}
/* localdecomp:end func_L01_003C8D60 */
