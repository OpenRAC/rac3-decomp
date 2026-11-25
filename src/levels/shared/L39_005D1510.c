#include "common.h"

/* localdecomp:start func_L39_005D1510 */
#include "vu0.h"
typedef struct {
    u8 *owner;
    s32 joint;
    s32 pad8;
    u8 kind;
    u8 grow;
    u8 dist;
    u8 keep;
    vu0_v4 off;
} Sub_L39_005D1510;

typedef struct {
    s32 pad0;
    s32 color;
    u8 size;
    u8 pad9;
    s16 life;
    f32 scale;
    vu0_v4 pos;
    Sub_L39_005D1510 sub;
} Fx_L39_005D1510;

extern s32 func_0038CB00(void *);
extern void func_003CD250(void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D000(void *, void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern vu0_v4 D_L39_0024DE00[];

void func_L39_005D1510(Fx_L39_005D1510 *p) {
    Sub_L39_005D1510 *q = &p->sub;
    u8 *owner;
    f32 f3, f0, one;
    s32 w;
    vu0_v4 m[4];

    if (p->life >= 0) {
        if (func_0038CB00(&p->life) != 0) {
            func_003CD250(p);
            return;
        }
    }
    owner = q->owner;
    if (owner != 0) {
        if ((s8)owner[0x20] < 0) {
            func_003CD250(p);
            return;
        }
        if (q->joint >= 0) {
            func_003C2EC0(owner, q->joint, m);
            func_0038D000(&p->pos, &q->off, m);
            vec_add_ab(&p->pos, &p->pos, &m[3]);
            *(s32 *)&p->pos.w = 0;
        } else {
            *(vu0_q *)&p->pos = *(vu0_q *)(owner + 0x10);
            func_0038D000(&m[0], &q->off, owner + 0xC0);
            vec_add_ab(&p->pos, &p->pos, &m[0]);
            if (q->dist != 0) {
                vec_sub_ab(&m[1], &p->pos, &D_L39_0024DE00[0]);
                p->size = (s32)(func_0038CE68(&m[1], &D_L39_0024DE00[2]) * 6.0f);
            }
            if (q->kind != 0) {
                switch (q->kind) {
                case 1:
                    vec_sub_ab(&m[2], &p->pos, owner + 0x10);
                    func_0038CF68(&m[2], &m[2], 1.0f);
                    break;
                case 2:
                    m[2] = *(vu0_v4 *)(owner + 0xC0);
                    break;
                case 3:
                    m[2] = *(vu0_v4 *)(owner + 0xC0);
                    vec_neg(&m[2], &m[2]);
                    break;
                case 4:
                    m[2] = *(vu0_v4 *)(owner + 0xD0);
                    break;
                case 5:
                    m[2] = *(vu0_v4 *)(owner + 0xD0);
                    vec_neg(&m[2], &m[2]);
                    break;
                case 6:
                    m[2] = *(vu0_v4 *)(owner + 0xE0);
                    break;
                case 7:
                    m[2] = *(vu0_v4 *)(owner + 0xE0);
                    vec_neg(&m[2], &m[2]);
                    break;
                }
                vec_sub_ab(&m[1], &p->pos, &D_L39_0024DE00[0]);
                one = 1.0f;
                func_0038CF68(&m[1], &m[1], one);
                f3 = -func_0038CE68(&m[1], &m[2]);
                f3 = f3 * 1.25f + 0.05f;
                if (f3 < 0.0f) {
                    p->color = p->color & 0x05FFFFFF;
                    goto tail;
                }
                if (one < f3) {
                    f3 = one;
                }
                if (q->keep != 0) {
                    f0 = (f32)((u32)(p->color & 0xFF000000) >> 24) * f3;
                    w = (s32)f0 << 24;
                    p->color = (p->color & 0xFFFFFF) | w;
                } else {
                    w = (s32)(f3 * 255.0f) << 24;
                    p->color = (p->color & 0xFFFFFF) | w;
                }
            }
        }
    } else {
        *(vu0_q *)&p->pos = *(vu0_q *)&q->off;
    }
tail:
    p->scale = p->scale * q->off.w;
    p->size = p->size + q->grow;
}
/* localdecomp:end func_L39_005D1510 */
