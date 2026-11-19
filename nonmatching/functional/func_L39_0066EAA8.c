/* functional: high. Compiles; PAL port of the NTSC-U draft (PAL timer limit 0xFB, callees func_L39_00590508/0066E378/0066DF98); bytes differ in regalloc/scheduling and vec_add_ab macro lowering. */
#include "common.h"
#include "vu0.h"

typedef struct N_0066EAA8 N_0066EAA8;
struct N_0066EAA8 {
    u8 pad0[0x20];
    N_0066EAA8 *p20;
    N_0066EAA8 *next;
    u8 *p28;
    u8 pad2C[0xA];
    s16 state;
    s32 timer;
    u8 pad3C[0x4];
    u8 *p40;
    u8 *p44;
    u8 *p48;
    u8 *p4C;
    u8 pad50[0x14];
    s32 w64;
};

extern N_0066EAA8 *D_L39_0024CF7C;
extern void func_L39_00590508(void *, void *, f32);
extern void func_L39_0066E378(void *, N_0066EAA8 *, s32);
extern N_0066EAA8 *func_L39_0066DF98(N_0066EAA8 *);

void func_L39_0066EAA8(void) {
    N_0066EAA8 *n;
    vu0_v4 pos;
    vu0_v4 tmp;
    u8 *p;
    s32 v;

    n = D_L39_0024CF7C;
    while (n != 0) {
        switch (n->state) {
        case 0:
            n->timer = n->timer - 1;
            if (n->timer <= 0) {
                n->state = 1;
            }
            n = n->next;
            break;
        case 1:
            p = n->p4C;
            if (p == 0) {
                n = n->next;
                break;
            }
            if (n->w64 == 0) {
                pos = *(vu0_v4 *)(p + 0xA0);
                func_L39_00590508(&tmp, n->p4C + 0x40, 0.5f);
                vec_add_ab(&pos, &pos, &tmp);
                func_L39_00590508(&tmp, n->p4C + 0x20, 0.5f);
                vec_add_ab(&pos, &pos, &tmp);
                v = 0;
                if (n->p40 != 0) v = *(s32 *)(n->p40 + 0x2524);
                if (n->p44 != 0) v = *(s32 *)(n->p44 + 0x2D0);
                if (n->p48 != 0) v = *(s32 *)(n->p48 + 0x1C);
                func_L39_0066E378(&pos, n, v);
            }
            n->state = 2;
            n = n->next;
            break;
        case 2:
            n->timer = n->timer + 1;
            if (n->timer < 0xFB) {
                p = n->p28;
                if (p == 0) {
                    n->state = 3;
                } else if (p[0x20] == 0xFE) {
                    n->state = 3;
                } else if (p[0x20] == 0xFD) {
                    n->state = 3;
                }
            } else {
                n->state = 3;
            }
            n = n->next;
            break;
        case 3:
            n = func_L39_0066DF98(n);
            break;
        }
    }
}
