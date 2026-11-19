/* functional: high. Per-tick update of a three-state fading effect (q = obj+0x20, state byte q[0x1C]): state 0 fades the colour word between 0x7F232323 and 0x7F373737 by timer*q[0x10], state 1 drifts the position by q while z is above q[0x14] (q[8] -= q[0xC]), state 2 fades 0x232323 to 0x7F232323; when the timer (s16 +0xA) expires it advances state 0 -> 1 (timer 250), 1 -> 2 (timer 125, q[0x10] = 0.008), and frees the object when state 2 expires. PAL values; VU0 vadd in plain C; same call order as retail. */
/* localdecomp:start func_L39_005D5558 */
typedef struct {
    u8 pad0[0x8];
    f32 f8;
    f32 fC;
    f32 f10;
    f32 f14;
    u8 pad18[4];
    u8 state;
} L39Q_5D5558;

typedef struct {
    u8 pad0[0x4];
    s32 color;
    u8 pad8[2];
    s16 timer;
    u8 padC[4];
    f32 pos[4] __attribute__((aligned(16)));
    L39Q_5D5558 vel;
} L39Obj_5D5558;

extern void func_L39_005FFB48(void *, void *);
extern s32 func_0038DBD8(s32, s32, f32);

void func_L39_005D5558(L39Obj_5D5558 *p) {
    L39Q_5D5558 *q = &p->vel;

    func_L39_005FFB48(p->pos, p->pos);
    if (q->state == 0) {
        p->color = func_0038DBD8(0x7F232323, 0x7F373737, p->timer * q->f10);
    } else if (q->state == 1) {
        if (p->pos[2] > q->f14) {
            p->pos[0] = p->pos[0] + *(f32 *)((u8 *)p + 0x20);
            p->pos[1] = p->pos[1] + *(f32 *)((u8 *)p + 0x24);
            p->pos[2] = p->pos[2] + *(f32 *)((u8 *)p + 0x28);
            q->f8 -= q->fC;
        }
    } else if (q->state == 2) {
        p->color = func_0038DBD8(0x232323, 0x7F232323, p->timer * q->f10);
    }
    if (func_0038CB00(&p->timer) && q->state == 0) {
        q->state = 1;
        p->timer = 0xFA;
    } else if (func_0038CB00(&p->timer) && q->state == 1) {
        q->state = 2;
        p->timer = 0x7D;
        q->f10 = 0.008f;
    } else if (func_0038CB00(&p->timer) && q->state == 2) {
        func_003CD250(p);
    }
}
/* localdecomp:end func_L39_005D5558 */
