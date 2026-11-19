#include "common.h"

/* localdecomp:start func_L39_00516838 */
typedef struct {
    long count;
    s32 depth;
} C_00516838;

typedef struct {
    u8 _p0[0x10];
    u8 *f10;
    u8 _p14[0x48 - 0x14];
    long regs[16];
    s32 fC8;
    s32 fCC;
    s32 fD0;
    s32 fD4;
    C_00516838 *fD8;
} T_00516838;

typedef s32 (*F_00516838)(void *, s32, long *, long, long, long);

s32 func_L39_00516838(T_00516838 *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    C_00516838 *c = 0;
    long x, y, z;
    s32 sync;
    s32 r;

    if (a0->fC8 == 0) {
        return 2;
    }
    x = (a2 & 0x80) ? *(a0->regs + (a2 & 0xF)) : a2;
    y = (a3 & 0x80) ? *(a0->regs + (a3 & 0xF)) : a3;
    z = (a4 & 0x80) ? *(a0->regs + (a4 & 0xF)) : a4;
    if (a0->fD0 < 0) {
        a0->fD8 = 0;
    } else {
        a0->fD8 = (C_00516838 *)(a0->f10 + a0->fD0 * 0x28);
    }
    sync = a1 == 1;
    if (sync) {
        c = a0->fD8;
        if (c->count == 0) {
            return 3;
        }
        c->count--;
        c->depth++;
    }
    r = ((F_00516838)a0->fC8)(a0, a0->fCC, a0->regs, x, y, z);
    if (sync) {
        c->count++;
        c->depth--;
    }
    return r;
}
/* localdecomp:end func_L39_00516838 */

/* localdecomp:start func_L39_00516960 */
typedef struct {
    long f0;
    long f8;
    u32 f10;
    u8 f14;
    u8 _p15[3];
} E_00516960;

typedef struct {
    u8 _p0[0x10];
    u8 *f10;
    u8 _p14[0x48 - 0x14];
    long regs[16];
    s32 fC8;
    s32 fCC;
    s32 fD0;
} T_00516960;

extern s32 func_L39_005175B0(void *, long *);

s32 func_L39_00516960(T_00516960 *a0, s32 op, s32 a2, s32 a3, s32 a4) {
    E_00516960 *e;
    E_00516960 tmp;
    E_00516960 *p;

    if (a0->fD0 < 0) {
        return 2;
    }
    e = (E_00516960 *)(a0->f10 + a0->fD0 * 0x28);
    if (op == 0) {
        if (a2 & 0x80) {
            *(a0->regs + (a2 & 0xF)) = e->f14 & 0xC0;
        }
        if (a3 & 0x80) {
            *(a0->regs + (a3 & 0xF)) = e->f10;
        }
        if (a4 & 0x80) {
            *(a0->regs + (a4 & 0xF)) = e->f14 & 0x2F;
        }
        return 0;
    }
    if (op != 1) {
        return 2;
    }
    if (a2 & 0x80) {
        if (a3 & 0x80) {
            a3 = *(a0->regs + (a3 & 0xF));
        }
        if (a3 != 0) {
            tmp = *e;
            e->f10 = 2;
            p = &tmp;
        } else {
            p = e;
        }
        return func_L39_005175B0(p, a0->regs + (a2 & 0xF));
    }
    return 2;
}
/* localdecomp:end func_L39_00516960 */

/* localdecomp:start func_L39_00516A88 */
typedef struct {
    long f0;
    long f8;
    u32 f10;
    u8 f14;
    u8 _p15[3];
} E_00516A88;

/* the low six bits of an entry's flags byte */
static __inline__ s32 lo_00516A88(u8 b) { return b & 0x3F; }

s32 func_L39_00516A88(T_00516838 *a0, s32 op, s32 a2, s32 a3, s32 a4) {
    E_00516A88 *e;
    long x, y, z;
    s32 r;

    if (a0->fD0 < 0) {
        return 2;
    }
    e = (E_00516A88 *)(a0->f10 + a0->fD0 * 0x28);
    x = (a2 & 0x80) ? *(a0->regs + (a2 & 0xF)) : a2;
    y = (a3 & 0x80) ? *(a0->regs + (a3 & 0xF)) : a3;
    z = (a4 & 0x80) ? *(a0->regs + (a4 & 0xF)) : a4;
    if (!(op & 4)) {
        r = 0;
        if (((op & 3) << 6) != (e->f14 & 0xC0)) {
            r = 1;
        }
        if (x != e->f10) {
            r |= 2;
        }
        if ((lo_00516A88(e->f14) & z) != y) {
            r |= 4;
        }
    } else {
        z = 1 << e->f10;
        r = x != (e->f14 & 0xC0);
        if ((z & y) != z) {
            r |= 2;
        }
    }
    if (op & 8) {
        a0->regs[0] = r;
        return 0;
    }
    return r ? 3 : 0;
}
/* localdecomp:end func_L39_00516A88 */

INCLUDE_ASM("asm/levels", func_L39_00516BB8);

/* localdecomp:start func_L39_00516CB8 */
s32 func_L39_00516CB8(T_00516838 *a0, s32 op, s32 a2, s32 a3, s32 a4) {
    long *dst;
    long x, y;

    if (!(a2 & 0x80)) {
        return 2;
    }
    dst = a0->regs + (a2 & 0xF);
    x = (a3 & 0x80) ? *(a0->regs + (a3 & 0xF)) : a3;
    y = (a4 & 0x80) ? *(a0->regs + (a4 & 0xF)) : a4;
    switch (op) {
    case 0:
        *dst = x + y;
        break;
    case 1:
        *dst = x - y;
        break;
    case 2:
        *dst = x * y;
        break;
    case 3:
        if (y == 0) {
            return 5;
        }
        *dst = x / y;
        break;
    case 4:
        if (y == 0) {
            return 5;
        }
        *dst = x % y;
        break;
    case 5:
        *dst = x | y;
        break;
    case 6:
        *dst = x & y;
        break;
    case 7:
        *dst = x ^ y;
        break;
    default:
        return 2;
    }
    return 0;
}
/* localdecomp:end func_L39_00516CB8 */

/* localdecomp:start func_L39_00516DC8 */
typedef struct {
    u8 _p0[0x1C];
    long *f1C;
    s32 f20;
    u8 _p24[0x48 - 0x24];
    long regs[16];
} T_00516DC8;

s32 func_L39_00516DC8(T_00516DC8 *a0, s32 op, s32 a2, s32 a3, s32 a4) {
    long *dst;

    if (!(a2 & 0x80)) {
        return 2;
    }
    dst = a0->regs + (a2 & 0xF);
    switch (op) {
    case 0:
        *dst = a3 | (a4 << 8);
        break;
    case 1:
        *dst = *(u16 *)dst | ((long)(a3 | (a4 << 8)) << 16);
        break;
    case 2:
        *dst = a0->f1C[a0->f20++];
        break;
    default:
        return 2;
    }
    return 0;
}
/* localdecomp:end func_L39_00516DC8 */

/* localdecomp:start func_L39_00516E70 */
s32 func_L39_00516E70(void) {
    return 2;
}
/* localdecomp:end func_L39_00516E70 */

/* localdecomp:start func_L39_00516E78 */
typedef s32 (*H_00516E78)(void *, u32, s32, s32, s32);
typedef s32 (*F_00516E78)(void *, s32, long *, u32, u32, u32);

typedef struct {
    H_00516E78 *f0;
    u8 _p4[0x18 - 0x4];
    s32 f18;
    unsigned long *f1C;
    s32 f20;
    u8 _p24[0x48 - 0x24];
    long regs[16];
    s32 fC8;
    s32 fCC;
    u8 _pD0[0xE0 - 0xD0];
    long fE0;
} T_00516E78;

s32 func_L39_00516E78(T_00516E78 *a0, s32 a1) {
    s32 r = 0;
    s32 trace;
    unsigned long *code;
    unsigned long ins;
    u32 op;

    a0->f20 = 0;
    trace = a0->fE0 & 2;
    code = a0->f1C;
    if (trace && a0->fC8 == 0) {
        trace = 0;
    }
    a0->fCC = a1;
    for (;;) {
        if (a0->f18 < a0->f20) {
            return 9;
        }
        if (trace && (r = ((F_00516E78)a0->fC8)(a0, a0->fCC, a0->regs, 0xFFFFFFFF, 0, 0)) != 0) {
            break;
        }
        ins = code[a0->f20++];
        if (ins == 0) {
            return r;
        }
        op = ins & 0xFF;
        r = a0->f0[op >> 4](a0, op & 0xF, (ins >> 8) & 0xFF, (ins >> 16) & 0xFF, (ins >> 24) & 0xFF);
        if (r != 0) {
            break;
        }
        if (op == 1) {
            break;
        }
    }
    return r;
}
/* localdecomp:end func_L39_00516E78 */

LINKER_REMNANT("asm/levels", func_L39_00516FC8);
