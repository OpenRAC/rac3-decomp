#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_0052BCA8);

/* localdecomp:start func_L39_0052BD50 */
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    char pad0[0x290];
    u128_t q290;
    u128_t q2A0;
    char pad1[0x308 - 0x2B0];
    f32 f308;
    f32 f30C;
} B_0052BD50;
typedef struct {
    char pad0[0x1E0];
    s32 i1E0;
    char pad1[0x1F0 - 0x1E4];
    s32 i1F0;
    char pad2[4];
    B_0052BD50 *b;
    u128_t t;
} Q_0052BD50;
extern void func_L01_004450F0(void *, s32, s32);

void func_L39_0052BD50(void *self) {
    char *p = self;
    Q_0052BD50 *q = *(Q_0052BD50 **)(p + 0x68);
    B_0052BD50 *b;
    u128_t t;

    b = q->b;
    q->i1E0 = 0;
    q->i1F0 = 0;
    t = b->q290;
    b->f308 = 50.0f;
    b->f30C = 50.0f;
    *(u128_t *)(p + 0x10) = t;
    *(f32 *)(p + 0x18) -= 1.0f;
    *(u128_t *)(p + 0xF0) = b->q2A0;
    func_L01_004450F0(self, 1, -1);
}
/* localdecomp:end func_L39_0052BD50 */

INCLUDE_ASM("asm/levels", func_L39_0052BDB8);

INCLUDE_ASM("asm/levels", func_L39_0052CA90);
