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
    u8 padC0[0x30];
    f32 *pF0;
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
    u128_t q160;
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

/* localdecomp:start func_L39_0061FBC8 */
#include "vu0.h"

extern f32 D_L39_0024118C_0061FBC8;
extern f32 func_L39_0061FDF0_0061FBC8(u128_t *, u128_t *, u128_t *);
extern void func_L39_0061FEA8_0061FBC8(u128_t *, u128_t *, u128_t *, u128_t *, u128_t *, s32 *, s32 *, s32 *);
extern void func_0038CE20(void *, void *, f32);

void func_L39_0061FBC8(S_0061ECE0 *s, u128_t *pos, s32 time) {
    vu0_v4 q;
    s32 idx, next, tmp;
    s32 *tp;
    s32 *cur_t, *next_t;
    u128_t *cur_q, *next_q;
    f32 f;

    if (time >> 9 != s->i158 >> 9 && s->i158 != -1 && (time & 0x1FF) < 0x100) {
        s->q160 = *pos;
        s->i15C = time + 0xF5;
    }
    idx = s->i28;
    tp = &time;
    next = idx + 1;
    next %= 2;
    cur_t = &s->i20 + idx;
    cur_q = &s->q00 + idx;
    next_q = &s->q00 + next;
    next_t = &s->i20 + next;
    s->i158 = time;
    if (time < *cur_t) {
        return;
    }
    if (time < *next_t) {
        tmp = *next_t;
        *next_t = time;
        time = tmp;
        q = *(vu0_v4 *)next_q;
        *next_q = *pos;
        *(vu0_v4 *)pos = q;
    }
    f = func_L39_0061FDF0_0061FBC8(cur_q, next_q, pos);
    if ((s->i148 & 4) || f < *s->pF0) {
        f = 1.0f / ((f32)(time - *next_t) / (D_L39_0024118C_0061FBC8 * 1000.0f));
        vec_sub_ab(&s->q30, pos, next_q);
        func_0038CE20(&s->q30, &s->q30, f);
        qzero(&s->q40);
    } else {
        func_L39_0061FEA8_0061FBC8(&s->q30, &s->q40, cur_q, next_q, pos, cur_t, next_t, tp);
    }
    *cur_q = *pos;
    *cur_t = time;
    s->i28 = (s->i28 + 1) % 2;
    s->q70 = s->q90 = *pos;
    s->iFC = *tp;
    s->iF4 = *tp;
}
/* localdecomp:end func_L39_0061FBC8 */
