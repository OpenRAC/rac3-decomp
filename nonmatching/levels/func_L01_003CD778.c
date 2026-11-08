/* func_L01_003CD778: NEAR 4 diff: lqc2 vf2 (bbit032 s0,2) retail-scheduled before the two arg moves; mine after. Non-volatile m-operand asm (j-form scheduling substitute). */
typedef int Q_3CD778 __attribute__((mode(TI)));
extern void func_L01_003CDDD8(void *, int, int, int, M_3CC220 *, int);
extern void func_L01_003CDB08(M_3CC220 *, void *);
extern void func_L01_003CE2E8(M_3CC220 *);
extern int func_0038CAD0(void *);
extern void func_L01_003CDCE8(void *);
extern void func_L01_00404A10(void *, void *);

void func_L01_003CD778(M_3CC220 *m) {
    V_3CC220 *v = m->vars;
    Q_3CD778 old;
    switch (m->b20) {
    case 0:
        m->b20 = 1;
    case 1: {
        u8 *pos = m->pos;
        old = *(Q_3CD778 *)pos;
        __asm__("lqc2 $vf2, %1\n lqc2 $vf1, %2\n vadd.xyz $vf1, $vf1, $vf2\n"
            : "=m"(*(Q_3CD778 *)pos) : "m"(*(Q_3CD778 *)pos), "m"(*(Q_3CD778 *)v->bB0) : "vf1", "vf2");
        __asm__("sqc2 $vf1, %0\n" : "=m"(*(Q_3CD778 *)pos) : "m"(*(Q_3CD778 *)pos) : "vf1");
        func_L01_003CDB08(m, &old);
        func_L01_003CE2E8(m);
        if (func_0038CAD0((u8 *)v + 0xD0)) {
            m->b20 = 2;
            func_L01_003CDDD8(pos, 20, 5, 0, m, v->tgt != 0);
        }
        break;
    }
    case 2:
        func_003C2880((s32)m);
        return;
    }
    func_L01_00404A10(func_L01_003CDCE8, m);
}
