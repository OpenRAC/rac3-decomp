#include "common.h"

/* localdecomp:start func_L39_0061ECE0 */
#include "vu0.h"
typedef int u128_t __attribute__((mode(TI)));
typedef struct S_0061ECE0 {
    u128_t q00;
    u128_t q10;
    s32 i20;
    s32 i24;
    s32 i28;
    u8 pad2C[4];
    u128_t q30;
    u128_t q40;
    u128_t q50;
    u128_t q60;
    u128_t q70;
    u128_t q80;
    u128_t q90;
    u128_t qA0;
    u128_t qB0;
    u8 padC0[0x34];
    s32 iF4;
    s32 iF8;
    s32 iFC;
    u8 pad100[0x30];
    s32 i130;
    s32 i134;
    s32 i138;
    u8 pad13C[8];
    s32 i144;
    s32 i148;
    u8 pad14C[0xC];
    s32 i158;
    s32 i15C;
} S_0061ECE0;

void func_L39_0061ECE0(S_0061ECE0 *s, u128_t *a1, s32 a2) {
    s32 t = a2 - 0x1E;
    s->i138 = 0;
    s->i144 = 0x1E;
    s->i130 = 0;
    s->i134 = 0;
    s->q00 = *a1;
    s->q10 = *a1;
    s->i20 = a2 - 0x20;
    qzero(&s->q30);
    qzero(&s->q40);
    s->i24 = a2 - 0x1F;
    qzero(&s->q50);
    s->i28 = 0;
    qzero(&s->q60);
    qzero(&s->qA0);
    qzero(&s->qB0);
    s->q70 = *a1;
    s->q80 = *a1;
    s->q90 = *a1;
    s->iF4 = t;
    s->iF8 = t;
    s->iFC = t;
    s->i15C = -1;
    s->i158 = -1;
    s->i148 = 1;
}
/* localdecomp:end func_L39_0061ECE0 */

LINKER_REMNANT("asm/levels", func_L39_0061ED70);

INCLUDE_ASM("asm/levels", func_L39_0061ED80);

INCLUDE_ASM("asm/levels", func_L39_0061F3F0);

INCLUDE_ASM("asm/levels", func_L39_0061F5A0);

INCLUDE_ASM("asm/levels", func_L39_0061FBC8);
