/* NTSC-U draft (2026-11-14, Claude worker): C of func_L39_005D2FE8, the NTSC-U twin of func_L39_005D5558, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (src/levels/shared/L39_005D5558.c's line: "-O2 -G8 -fopt-stack -mno-check-zero-division").
 */
#include "common.h"

/* NTSC-U counterpart of func_L39_005D5558 (src/levels/shared/L39_005D5558.c) */
/* localdecomp:start func_L39_005D2FE8 */
#include "vu0.h"

typedef struct S_005D5558_Q {
    u8 pad0[0x8];
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    u8 pad18[0x1C - 0x18];
    u8 state;
} S_005D5558_Q;

typedef struct S_005D5558 {
    u8 pad0[0x4];
    s32 color;
    u8 pad8[0xA - 0x8];
    s16 timer;
    u8 padC[0x10 - 0xC];
    vu0_v4 pos;
    S_005D5558_Q vel;
} S_005D5558;

extern void func_L39_005FD3A8(void *, void *);
extern s32 func_003894A0(s32, s32, f32);
extern s32 func_003883C8(void *);
extern void func_003C7CE0(void *);

void func_L39_005D2FE8(S_005D5558 *p)
{
    S_005D5558_Q *q = &p->vel;

    func_L39_005FD3A8(&p->pos, &p->pos);
    if (q->state == 0) {
        p->color = func_003894A0(0x7F232323, 0x7F373737, p->timer * q->f10);
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
/* localdecomp:end func_L39_005D2FE8 */
