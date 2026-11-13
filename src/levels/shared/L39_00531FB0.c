#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_00531FB0);

/* localdecomp:start func_L39_005324E8 */
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

typedef struct {
    f32 x, y, z, w;
} __attribute__((aligned(16))) V4_005324E8;

typedef struct {
    u8 pad0[0x270];
    u128_t f270;
    u8 pad280[0x308 - 0x280];
    f32 f308;
    f32 f30C;
    s32 f310;
} Q_005324E8;

typedef struct {
    u8 pad0[0x100];
    V4_005324E8 f100;
    u128_t f110;
    u8 pad120[0x140 - 0x120];
    s32 f140;
    s32 f144;
    s32 f148;
    f32 f14C;
    s32 f150;
    s32 f154;
    s32 f158;
    s32 f15C;
    Q_005324E8 *f160;
    s32 f164;
    s32 f168;
} P_005324E8;

extern u128_t D_L39_00243F20;
extern f32 D_L39_0024AC8C;
__asm__(".extern D_L39_0024AC8C, 4");

void func_L39_005324E8(u8 *a0) {
    P_005324E8 *p = *(P_005324E8 **)(a0 + 0x68);
    Q_005324E8 *q = p->f160;

    qzero(&q->f270);
    q->f308 = 40.0f;
    q->f310 = 0;
    q->f30C = 40.0f;
    *(u128_t *)&p->f100 = D_L39_00243F20;
    p->f140 = 0;
    qzero(&p->f110);
    p->f144 = 0;
    p->f14C = D_L39_0024AC8C;
    p->f148 = 0;
    p->f150 = 0;
    p->f154 = 0;
    p->f158 = 0;
    p->f168 = 0;
    p->f164 = 0;
    p->f15C = 0;
}
/* localdecomp:end func_L39_005324E8 */

INCLUDE_ASM("asm/levels", func_L39_00532550);

INCLUDE_ASM("asm/levels", func_L39_00532698);

INCLUDE_ASM("asm/levels", func_L39_00532BE0);
