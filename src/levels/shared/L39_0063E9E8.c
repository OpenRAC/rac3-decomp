#include "common.h"

/* localdecomp:start func_L39_0063E9E8 */
s32 func_L39_0063E9E8(u8 *a0, s32 a1) {
    if (a1 == 0) {
        return *(s32 *)(a0 + 0x2524);
    }
    if (a1 == 1) {
        return *(s32 *)(a0 + 0x544);
    }
    if (a1 == 2) {
        return *(s32 *)(a0 + 0x450);
    }
    return 0;
}
/* localdecomp:end func_L39_0063E9E8 */

INCLUDE_ASM("asm/levels", func_L39_0063EA20);

/* localdecomp:start func_L39_0063EC20 */
extern void func_L39_0063EA20(u8 *, u8 *);

void func_L39_0063EC20(u8 *a0) {
    s32 i;
    u8 *p = a0 + 1888;

    *(s16 *)(a0 + 9378) = 0;
    for (i = 11; i >= 0; i--) {
        func_L39_0063EA20(a0, p);
        p += 176;
    }
}
/* localdecomp:end func_L39_0063EC20 */

/* localdecomp:start func_L39_0063EC78 */
#include "vu0.h"

typedef struct Cur_0063EC78 {
    u8 pad0[0x760];
    u8 b760;
    u8 b761;
    u8 pad762[0x7A0 - 0x762];
    vu0_q q7A0;
    u8 pad7B0[0x10];
    vu0_q q7C0;
    u8 pad7D0[0x802 - 0x7D0];
    s16 h802;
    u8 pad804[0x80C - 0x804];
    f32 f80C;
} Cur_0063EC78;

typedef struct Self_0063EC78 {
    u8 pad0[0x24A2];
    s16 h24A2;
} Self_0063EC78;

extern s32 func_L39_0063E9E8(u8 *, s32);
extern void func_003C2C98(void *, void *);

void func_L39_0063EC78(Self_0063EC78 *self) {
    Cur_0063EC78 *p;
    u8 *q;
    u8 *end;

    if (self->h24A2 == 0) {
        q = (u8 *)self + 0x760;
        p = (Cur_0063EC78 *)self;
        end = (u8 *)self + 0x840;
        do {
            if (p->b761 != 0) {
                s32 e = func_L39_0063E9E8((u8 *)self, p->h802);
                if (e != 0) {
                    func_003C2C98((void *)e, q);
                }
            }
            qzero(&p->q7A0);
            qzero(&p->q7C0);
            p->f80C = 1.0f;
            p = (Cur_0063EC78 *)((u8 *)p + 0xB0);
            q += 0xB0;
        } while ((s32)p < (s32)end);
        self->h24A2 = 1;
    }
}
/* localdecomp:end func_L39_0063EC78 */
