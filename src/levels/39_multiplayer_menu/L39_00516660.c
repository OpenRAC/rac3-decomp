#include "common.h"

/* localdecomp:start func_L39_00516660 */
typedef struct N_00516660 {
    long count;
    s32 depth;
    u8 _pC[0x18 - 0xC];
    struct N_00516660 *f18;
    struct N_00516660 *f1C;
    struct N_00516660 *f20;
    u8 _p24[0x28 - 0x24];
} N_00516660;

typedef struct {
    u8 _p0[0x10];
    N_00516660 *f10;
    u8 _p14[0x3C - 0x14];
    s32 *f3C;
    u8 _p40[0x48 - 0x40];
    long regs[16];
    s32 fC8;
    s32 fCC;
    s32 fD0;
    s32 fD4;
} T_00516660;

s32 func_L39_00516660(T_00516660 *a0, s32 op, s32 a2, s32 a3, s32 a4) {
    long count = 0;
    long start = 0;
    N_00516660 *n = 0;

    if (op & 8) {
        count = (a3 & 0x80) ? *(a0->regs + (a3 & 0xF)) : a3;
        start = count;
        if (a0->fD0 < 0) {
            return 2;
        }
        n = a0->f10 + a0->fD0;
    }
    switch (op) {
    case 0:
        a0->f3C[a3 | (a4 << 8)] = a0->fD0;
        return 0;
    case 1:
        a0->fD4 = 1;
        goto jump;
    case 2:
        a0->fD4 = 0;
        goto jump;
    case 3:
        goto jump;
    case 8:
        while (count > 0 && n->f20 != 0) {
            count--;
            n = n->f20;
        }
        break;
    case 9:
        while (count > 0 && n->f18 != 0) {
            count--;
            n = n->f18;
        }
        break;
    case 10:
        while (count > 0 && n->f1C != 0) {
            count--;
            n = n->f1C;
        }
        break;
    default:
        return 3;
    }
    if (a2 & 0x80) {
        *(a0->regs + (a2 & 0xF)) = start - count;
    } else if (count != 0) {
        return 2;
    }
    a0->fD0 = n - a0->f10;
    return 0;

jump:
    if (a2 != 0) {
        a0->fD0 = a0->f3C[a2];
    }
    return 0;
}
/* localdecomp:end func_L39_00516660 */

/* localdecomp:start func_L39_00516830 */
s32 func_L39_00516830(void) {
    return 0;
}
/* localdecomp:end func_L39_00516830 */

