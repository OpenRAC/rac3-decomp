#include "common.h"

/* localdecomp:start func_L01_003C7560 */
extern s32 D_L01_001DFB40_003C7560;
extern s32 D_L01_001DEC34;
extern f32 D_L01_001DEC28_003C7560;
extern f32 D_L01_001DEC2C_003C7560;
extern f32 D_L01_001DEC24_003C7560;
extern f32 D_L01_001DEC44_003C7560;
extern f32 D_L01_001DEC48_003C7560;
extern f32 D_L01_001DEC40_003C7560;
__asm__(".extern D_L01_001DFB40_003C7560, 16");
__asm__(".extern D_L01_001DEC34, 4");
__asm__(".extern D_L01_001DEC28_003C7560, 4");
__asm__(".extern D_L01_001DEC2C_003C7560, 4");
__asm__(".extern D_L01_001DEC24_003C7560, 4");
__asm__(".extern D_L01_001DEC44_003C7560, 4");
__asm__(".extern D_L01_001DEC48_003C7560, 4");
__asm__(".extern D_L01_001DEC40_003C7560, 4");
extern s32 func_L01_003C7000(void *, void *);
extern f32 func_L01_00448890(void *, f32, void *, s32, f32, f32, f32);
extern f32 func_003C41A0(f32 *, void *, f32, f32, f32, f32);

s32 func_L01_003C7560(void *m, u8 *v) {
    if (D_L01_001DFB40_003C7560 - D_L01_001DEC34 < *(s32 *)(v + 0xA4)) {
        func_L01_003C7000(m, v);
    } else {
        func_L01_00448890(v + 0x674, 0.0f, v + 0x98, 0,
                          D_L01_001DEC28_003C7560 * 0.017453292f * 0.000400000019f,
                          D_L01_001DEC2C_003C7560 * 0.017453292f * 0.000400000019f,
                          D_L01_001DEC24_003C7560 * 0.017453292f * 0.0200000014f);
        *(f32 *)(v + 0x694) = *(f32 *)(v + 0x674);
    }
    func_003C41A0((f32 *)(v + 0x6A8), v + 0x9C, 0.0f,
                  D_L01_001DEC44_003C7560 * 0.017453292f * 0.000400000019f,
                  D_L01_001DEC48_003C7560 * 0.017453292f * 0.000400000019f,
                  D_L01_001DEC40_003C7560 * 0.017453292f * 0.0200000014f);
    if (*(f32 *)(v + 0x674) == 0.0f && *(f32 *)(v + 0x6A8) == 0.0f) {
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L01_003C7560 */

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
