#include "common.h"

INCLUDE_ASM("asm/levels", func_L04_0035B430);

INCLUDE_ASM("asm/levels", func_L04_0035B5D8);

INCLUDE_ASM("asm/levels", func_L04_0035B838);

/* localdecomp:start func_L04_0035B908 */
typedef int u128_35A960 __attribute__((mode(TI)));

typedef struct {
    u128_35A960 a;
    u128_35A960 b;
    s32 active;
} S_35A960;

extern s32 func_L04_004BB4F8(u128_35A960 *, u128_35A960 *, f32);
extern u32 func_L04_004BB268(void);
extern s32 func_L04_004BB348(u32, s32, s32, s32);
extern void func_L04_004BB288(u32, f32);
extern void func_L04_004BB2E0(u32, u128_35A960 *, u128_35A960 *);
extern void func_L04_004BB3A8(u32);

void func_L04_0035B908(s32 arg0, S_35A960 *p, S_35A960 *q, u32 *h) {
    u128_35A960 v[2];
    u32 n;

    if (p->active == 1 || q->active == 1) {
        if (p->active == 1) {
            v[0] = p->a;
            if (q->active == 1) {
                v[1] = q->b;
            } else {
                v[1] = p->b;
            }
        } else {
            v[0] = q->a;
            v[1] = q->b;
        }
        if (*h == 0xFFFFFFFF) {
            if (func_L04_004BB4F8(&v[0], &v[1], 24.0f) == 0) {
                n = func_L04_004BB268();
                *h = n;
                func_L04_004BB348(n, 0, arg0, 6455);
                func_L04_004BB288(*h, 24.0f);
                func_L04_004BB2E0(*h, &v[0], &v[1]);
            }
        } else if (func_L04_004BB4F8(&v[0], &v[1], 24.0f) == 0) {
            func_L04_004BB2E0(*h, &v[0], &v[1]);
        } else {
            func_L04_004BB3A8(*h);
            *h = 0xFFFFFFFF;
        }
    } else if (*h != 0xFFFFFFFF) {
        func_L04_004BB3A8(*h);
        *h = 0xFFFFFFFF;
    }
}
/* localdecomp:end func_L04_0035B908 */

INCLUDE_ASM("asm/levels", func_L04_0035BA58);

INCLUDE_ASM("asm/levels", func_L04_0035BC10);

INCLUDE_ASM("asm/levels", func_L04_0035C1B8);

INCLUDE_ASM("asm/levels", func_L04_0035C2B0);

INCLUDE_ASM("asm/levels", func_L04_0035C398);

INCLUDE_ASM("asm/levels", func_L04_0035C9C8);
