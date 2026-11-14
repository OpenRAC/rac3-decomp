#include "common.h"

/* NTSC-U counterpart of func_L39_005D59A8 (src/levels/shared/L39_005D59A8.c): 250 -> 300; 125 -> 150; 0.008 -> 0.00666667 */
/* localdecomp:start func_L39_005D3438 */
#include "vu0.h"

typedef struct S_005D59A8_Q {
    u8 pad0[0x8];
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    u8 pad18[0x1C - 0x18];
    u8 state;
} S_005D59A8_Q;

typedef struct S_005D59A8 {
    u8 pad0[0x4];
    s32 color;
    u8 pad8[0xA - 0x8];
    s16 timer;
    u8 padC[0x10 - 0xC];
    vu0_v4 pos;
    S_005D59A8_Q vel;
} S_005D59A8;

extern void func_L39_005FD3A8(void *, void *);
extern s32 func_003894A0(s32, s32, f32);
extern s32 func_003883C8(void *);
extern void func_003C7CE0(void *);

void func_L39_005D3438(S_005D59A8 *p)
{
    S_005D59A8_Q *q = &p->vel;

    func_L39_005FD3A8(&p->pos, &p->pos);
    if (q->state == 0) {
        p->color = func_003894A0(0x4FBF2323, 0x4F202020, p->timer * q->f10);
    } else if (q->state == 1) {
        if (p->pos.z > q->f14) {
            vec_add_ab(&p->pos, &p->pos, q);
            q->f8 -= q->fC;
        }
    } else if (q->state == 2) {
        p->color = func_003894A0(0x232323, 0x7F232323, p->timer * q->f10);
    }
    if (func_003883C8(&p->timer) && q->state == 0) {
        q->state = 1;
        p->timer = 0x12C;
    } else if (func_003883C8(&p->timer) && q->state == 1) {
        q->state = 2;
        p->timer = 0x96;
        q->f10 = 0.00666666683f;
    } else if (func_003883C8(&p->timer) && q->state == 2) {
        func_003C7CE0(p);
    }
}
/* localdecomp:end func_L39_005D3438 */
