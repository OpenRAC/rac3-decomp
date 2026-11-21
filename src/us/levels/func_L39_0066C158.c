#include "common.h"

/* NTSC-U counterpart of func_L39_0066EAA8 (src/levels/shared/L39_0066E378.c): timeout 0x12D frames instead of 0xFB */
/* localdecomp:start func_L39_0066C158 */
#include "vu0.h"

typedef struct { u8 pad[0x20]; u8 b20; } Src_0066C158;
typedef struct { u8 pad[0x2524]; u8 *target; } OwnA_0066C158;
typedef struct { u8 pad[0x2D0]; u8 *target; } OwnB_0066C158;
typedef struct { u8 pad[0x1C]; u8 *target; } OwnC_0066C158;
typedef struct Node_0066C158 {
    u8 pad0[0x24];
    struct Node_0066C158 *next;
    Src_0066C158 *src;
    u8 pad2C[0x36 - 0x2C];
    s16 state;
    s32 timer;
    u8 pad3C[4];
    OwnA_0066C158 *ownA;
    OwnB_0066C158 *ownB;
    OwnC_0066C158 *ownC;
    u8 *moby;
    u8 pad50[0x64 - 0x50];
    s32 spawned;
} Node_0066C158;

extern Node_0066C158 *D_L39_0024D07C;
extern void func_003886E8(void *, void *, f32);
extern void func_L39_0066BA58(void *, u8 *, u8 *);
extern Node_0066C158 *func_L39_0066B690(Node_0066C158 *);

void func_L39_0066C158(void)
{
    Node_0066C158 *n;
    vu0_v4 pos;
    vu0_v4 tmp;
    u8 *target;
    s32 v;
    long done = 3;

    n = D_L39_0024D07C;
    while (n != 0) {
        switch (n->state) {
        case 0:
            if (--n->timer <= 0) {
                n->state = 1;
            }
            n = n->next;
            break;
        case 1:
            if (n->moby != 0) {
                v = n->spawned;
                if (v == 0) {
                    pos = *(vu0_v4 *)(n->moby + 0xA0);
                    func_003886E8(&tmp, n->moby + 0x40, 0.5f);
                    vec_add_ab(&pos, &pos, &tmp);
                    func_003886E8(&tmp, n->moby + 0x20, 0.5f);
                    vec_add_ab(&pos, &pos, &tmp);
                    target = 0;
                    if (n->ownA != 0) {
                        target = n->ownA->target;
                    }
                    if (n->ownB != 0) {
                        target = n->ownB->target;
                    }
                    if (n->ownC != 0) {
                        target = n->ownC->target;
                    }
                    func_L39_0066BA58(&pos, (u8 *)n, target);
                }
                v = 2;
                n->state = v;
            }
            n = n->next;
            break;
        case 2:
            if (++n->timer >= 0x12D || n->src == 0) {
                n->state = done;
            } else if (n->src->b20 == 0xFE) {
                n->state = done;
            } else if (n->src->b20 == 0xFD) {
                n->state = done;
            }
            n = n->next;
            break;
        case 3:
            n = func_L39_0066B690(n);
            break;
        }
    }
}
/* localdecomp:end func_L39_0066C158 */
