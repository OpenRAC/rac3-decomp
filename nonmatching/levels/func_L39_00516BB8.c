// near miss func_L39_00516BB8: 40 diff, only register allocation: retail has result in t2 and ctx copy in t3 (flag t6, neg t4, gt t5), mine ctx t2/result t3; retail also does 'move t2,t1' then 'or t2,t2,t4' in the branch delay slot (cases 2,3) where mine merges into one 'or'. Logic and structure match (switch of 8, jump table at 0x479A20).
typedef struct {
    u8 _p0[0x20];
    s32 f20;
    u8 _p24[4];
    s32 f28;
    u8 _p2C[0x40 - 0x2C];
    s32 *f40;
    long regs[16];
} T_00516BB8;

s32 func_L39_00516BB8(T_00516BB8 *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    long x;
    s32 gt, eq, neg;
    s32 r;

    a3 = a3 | (a4 << 8);
    x = (a2 & 0x80) ? *(a0->regs + (a2 & 0xF)) : a2;
    gt = x > 0;
    eq = x == 0;
    neg = (u64)x >> 63;
    r = 0;
    switch (a1) {
    case 0:
        r = eq;
        break;
    case 1:
        r = !eq;
        break;
    case 2:
        r = eq;
        r |= neg;
        break;
    case 3:
        r = eq;
        r |= gt;
        break;
    case 4:
        r = 1;
        if (a2 & 0x80) {
            *(a0->regs + (a2 & 0xF)) = a0->f20;
        }
        break;
    case 5:
        a0->f20 = x;
        r = 0;
        break;
    case 6:
    case 7:
        break;
    }
    if (r != 0) {
        if (a3 >= a0->f28) {
            return 2;
        }
        a0->f20 = a0->f40[a3];
    }
    return 0;
}
