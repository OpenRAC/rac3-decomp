/* functional: high. US draft checked against PAL asm: argument registers and the two stack args (0xE0/0xE8), every field offset of the 0x60-byte object, the lq/sq vector copies, the COP2 add (lqc2/vadd.xyz/sqc2, allowed inline asm) and the b9 computation. Types come from the file context (3BFAC8.c). 30 words differ (scheduling/save slots). */
S_3BA5B8 *func_003BFAC8(Q_3BA5B8 *pos, B_3BA5B8 *b, s32 a2, f32 f0, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, f32 f1, f32 f2, u8 a8, s32 a9) {
    S_3BA5B8 *p = func_003CD108(0x59);
    Sub_3BA5B8 *s;
    Q_3BA5B8 t;
    s32 v;
    if (p) {
        p->w4 = a2;
        p->fC = f0;
        p->b1 = 0;
        p->b9 = 0x44;
        p->b3 = 0x48;
        p->b8 = func_00382468(0xFF);
        p->b2 = D_002FCFFC[0][a4];
        p->hA = a5;
        s = &p->s20;
        s->b = b;
        s->w4 = a3;
        s->f8 = f1;
        s->bC = a6;
        s->bD = a8;
        s->q10.q = *pos;
        s->q10.f[3] = f2;
        if (a4 == 0) s->bE = 1;
        s->bF = a9;
        if (b) {
            p->q10 = b->q10;
            func_0038D000(&t, &s->q10.q, (u8 *)b + 0xC0);
            __asm__ __volatile__(
                "lqc2 $vf1, %0\n"
                "lqc2 $vf2, %1\n"
                "vadd.xyz $vf1, $vf1, $vf2\n"
                "sqc2 $vf1, %0\n"
                : "+m"(p->q10) : "m"(t));
            if (a7 > 0) v = a7 >> 5;
            else v = b->h32 >> 5;
            p->b9 = v * 16 + 4;
        } else {
            p->q10 = *pos;
        }
    }
    return p;
}
