/* NTSC-U draft (Claude wave K): C of func_L39_0066C158, the NTSC-U twin of func_L39_0066EAA8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 78 words differ on NTSC-U with "-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as" (the file's line: "-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as") (NTSC-U twin "func_L39_0066C158", whose code is not the PAL one).
 * Worker's note: Best 78 diff (88 of 107 words equal, 23 structural; medium draft was 101/43) with -mvu0-use-vf0-vf2 + @ps2as. New: (1) the 0xFE/0xFD test must be two separate else-ifs (else if (p[0x20] == 0xFE) state = 3; else if (p[0x20] == 0xFD) state = 3;) so fold-const ...
 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L39_0066C158 */
/* Needs -mvu0-use-vf0-vf2 (vec_* helpers) and @ps2as (float immediates) beyond the PAL file's flags. */
typedef struct N_0066C158 N_0066C158;
struct N_0066C158 {
    u8 pad0[0x20];
    N_0066C158 *p20;
    N_0066C158 *next;
    N_0066C158 *p28;
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

extern N_0066C158 *D_L39_0024D07C;
extern void func_003886E8(void *, f32, void *);
extern void func_L39_0066BA58(void *, N_0066C158 *, s32);
extern N_0066C158 *func_L39_0066B690(N_0066C158 *);

void func_L39_0066C158(void) {
    N_0066C158 *n;
    vu0_v4 pos;
    vu0_v4 tmp;
    u8 *p;
    s32 v;

    n = D_L39_0024D07C;
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
                func_003886E8(&tmp, 0.5f, n->p4C + 0x40);
                vec_add_ab(&pos, &pos, &tmp);
                func_003886E8(&tmp, 0.5f, n->p4C + 0x20);
                vec_add_ab(&pos, &pos, &tmp);
                v = 0;
                if (n->p40 != 0) v = *(s32 *)(n->p40 + 0x2524);
                if (n->p44 != 0) v = *(s32 *)(n->p44 + 0x2D0);
                if (n->p48 != 0) v = *(s32 *)(n->p48 + 0x1C);
                func_L39_0066BA58(&pos, n, v);
            }
            n->state = n->state + 1;
            n = n->next;
            break;
        case 2:
            n->timer = n->timer + 1;
            if (n->timer < 0x12D) {
                p = (u8 *)n->p28;
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
            n = func_L39_0066B690(n);
            break;
        }
    }
}
/* localdecomp:end func_L39_0066C158 */
