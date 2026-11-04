#include "common.h"

typedef struct SubA_L31_00344F00 {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 pad[0x2D];
} SubA_L31_00344F00;
typedef struct Blk_L31_00344F00 {
    SubA_L31_00344F00 a[8];
    s16 b[8];
    s32 f190;
    s32 f194;
    s32 f198;
    s32 f19C;
    s32 f1A0;
    u8 f1A4;
    u8 f1A5;
} Blk_L31_00344F00;
typedef struct Outer_L31_00344F00 {
    u8 pad[0x68];
    Blk_L31_00344F00 *f68;
} Outer_L31_00344F00;

/* localdecomp:start func_L31_00344F00 */
void func_L31_00344F00(Outer_L31_00344F00 *o) {
    Blk_L31_00344F00 *p = o->f68;
    SubA_L31_00344F00 *q = p->a;
    s32 i;

    p->f1A4 = 8;
    p->f194 = 0;
    i = 0;
    do {
        if (q[i].f2 == 0xFF) {
            p->f1A4 = i;
        } else {
            p->f194 += q[i].f2;
        }
        i++;
    } while (i < 8 && p->f1A4 == 8);
    p->f190 = 0;
    p->f1A5 = 8;
    i = 0;
    p->f1A0 = 0;
    p->f198 = 0;
    do {
        if (p->b[i] <= 0) {
            p->f1A5 = i;
        } else {
            p->f1A0 += p->b[i];
        }
        i++;
    } while (i < 8 && p->f1A5 == 8);
}
/* localdecomp:end func_L31_00344F00 */
