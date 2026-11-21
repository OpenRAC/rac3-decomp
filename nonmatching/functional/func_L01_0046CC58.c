/* functional: high. PAL near miss draft, re-read against the PAL asm: 8 instructions differ (register choice), behaviour identical. */
typedef struct {
    vu0_q v0;
    f32 f10;
    f32 f14;
    s32 i18;
} Q_0046CC58;

typedef struct {
    u8 b0, b1, b2, b3;
    s32 c4;
    u8 b8, b9;
    s16 hA;
    f32 fC;
    vu0_q v10;
    Q_0046CC58 q;
} T_0046CC58;

extern u8 *D_L01_00221198[];
extern f32 func_0038CF38(void *, void *);

T_0046CC58 *func_L01_0046CC58(vu0_q *pos, vu0_q *posB, s32 life, s32 color, s32 a4, s32 flag, f32 size, f32 f13, f32 f14) {
    T_0046CC58 *m = ((T_0046CC58 * (*)(s32))func_L01_004618E0)(0x40);
    Q_0046CC58 *q;
    if (m != 0) {
        m->v10 = *pos;
        q = &m->q;
        if (func_0038CF38(&D_001A4C60, pos) < 80.0f) {
            m->b9 = 0x31;
        } else {
            m->b9 = 0x21;
        }
        if (flag != 0) {
            m->b3 = 0x48;
        } else {
            m->b3 = 0x44;
        }
        m->b1 = 0;
        m->b2 = D_L01_00221198[0][1];
        m->c4 = color;
        m->fC = size * 210000.0f;
        m->b8 = (s32)func_003824E0(0.0f, 255.0f);
        m->hA = life;
        q->v0 = *posB;
        q->i18 = a4;
        q->f10 = f13;
        q->f14 = f14;
    }
    return m;
}
