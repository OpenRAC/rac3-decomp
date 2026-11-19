/* functional: high. NTSC-draft body verified against PAL asm; only the order of two independent stores differs from retail (2 instructions swapped). */
typedef struct {
    u8 *p0;
    s32 i4;
    s32 i8;
    f32 fC;
} Q_0046B9E8;

typedef struct {
    u8 b0, b1, b2, b3;
    s32 c4;
    u8 b8, b9;
    s16 hA;
    s32 iC;
    vu0_q v10;
    vu0_q v20;
    Q_0046B9E8 q;
} T_0046B9E8;

extern u8 *D_L01_00221174[];
extern void func_003C2F58(u8 *, s32, void *);

T_0046B9E8 *func_L01_0046B9E8(u8 *a0, s32 a1, s32 a2, s32 a3, f32 f12, f32 f13) {
    T_0046B9E8 *m = ((T_0046B9E8 * (*)(s32))func_L01_004618E0)(0x37);
    Q_0046B9E8 *q;
    if (m != 0) {
        m->iC = a3;
        m->c4 = a2;
        m->b9 = 0x20;
        m->b3 = 0x48;
        m->b1 = 3;
        m->b2 = *D_L01_00221174[0];
        if (a1 > 0) {
            func_003C2F58(a0, a1, &m->v10);
        } else {
            m->v10 = *(vu0_q *)(a0 + 0x10);
        }
        m->v20 = m->v10;
        ((f32 *)m)[7] = f12;
        ((f32 *)m)[11] = f13;
        q = &m->q;
        q->p0 = a0;
        q->i8 = *(s16 *)(a0 + 0xAA);
        q->i4 = a1;
        q->fC = f12;
    }
    return m;
}
