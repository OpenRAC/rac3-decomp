/* functional: high. Ported from the NTSC-U draft (func_L05_00357F78) with every callee and $gp constant re-derived from the PAL asm. PAL differs from the draft: the four distance thresholds are ((g*5+2)/6)^2 (not g*g) and the final smoothing call uses 0.3693/0.6933 instead of 0.03/0.3. Verified: 54 calls identical in order, the multisets of arithmetic ops, constants, and non-stack loads/stores equal retail; only branch offsets (layout) and stack offsets differ. */

typedef struct {
    vu0_v4 v00, v10, v20, v30, v40, v50, v60, v70;
} C_00358FF8;

typedef struct {
    u8 p0[0x10];
    vu0_v4 pos;
    u8 flags;
    u8 p21[0x9F];
    vu0_v4 vC0;
    vu0_v4 vD0;
    vu0_v4 vE0;
    vu0_v4 vF0;
} Q_00358FF8;

typedef struct {
    u8 p0;
    u8 b1;
    u8 p2[0xE];
    vu0_v4 v10;
    u8 p20[0xC];
    f32 f2C;
    u8 p30[0xC];
    f32 f3C;
} R_00358FF8;

typedef struct {
    u8 p0[0x220];
    vu0_v4 v220;
    u8 p230[0x1BC];
    Q_00358FF8 *q;
    u8 p3F0[0x18];
    s16 h408;
    s16 h40A;
    u8 p40C[4];
    R_00358FF8 r;
} P_00358FF8;

typedef struct {
    u8 p0[0x10];
    vu0_v4 pos;
    u8 p20[0xC];
    f32 f2C;
    u8 p30[4];
    u16 h34;
    u8 p36[0x32];
    P_00358FF8 *p;
    u8 p6C[0x54];
    vu0_v4 vC0;
    vu0_v4 vD0;
    vu0_v4 vE0;
    vu0_v4 vF0;
} M_00358FF8;

extern f32 D_L05_001DD60C;
extern f32 D_L05_001DD610;
extern f32 D_L05_001DD614;
extern f32 D_L05_001DD618;
extern f32 D_L05_001DD61C;
extern f32 D_L05_001DD620;
extern f32 D_L05_001DD624;
__asm__(".extern D_L05_001DD60C, 4");
__asm__(".extern D_L05_001DD610, 4");
__asm__(".extern D_L05_001DD614, 4");
__asm__(".extern D_L05_001DD618, 4");
__asm__(".extern D_L05_001DD61C, 4");
__asm__(".extern D_L05_001DD620, 4");
__asm__(".extern D_L05_001DD624, 4");

extern void func_0038D308(void *, void *);
extern void func_003CA4A0(void *, s32, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D570(void *, void *);
extern void func_0038D640(void *, void *, void *);
extern f32 func_L01_0040E4C0(void *);
extern s32 func_L02_003E6F38(f32, f32, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern s32 func_L05_00355B80(void *);
extern s32 func_L05_00355AE8(void *);
extern void func_L01_0040EE50(void *, void *);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038D160(f32, f32);
extern void func_L01_0043A430(void *, s32, void *);
extern void func_L01_00448728(void *, f32, void *, f32, f32, f32, s32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D098(f32);

void func_L05_00358FF8(M_00358FF8 *m) {
    P_00358FF8 *p;
    Q_00358FF8 *q;
    R_00358FF8 *r;
    s16 *st;
    C_00358FF8 c;
    vu0_v4 v80, v90, vA0, vB0, vC0, vD0, vE0;
    s32 loc;
    f32 fa, fb;
    f32 f20, f21, f22, f23, len, dot, lenA, lenB;
    vu0_v4 *pc;

    p = m->p;
    q = p->q;
    st = &p->h40A;
    if (!(m->h34 & 0x100)) {
        func_0038D308(&m->vC0, &m->vF0);
    }
    if (q->flags & 8) {
        qzero(&q->vF0);
        q->flags &= 0xFC;
        p->h40A = 0;
        p->h408 = 0;
    }
    loc = 0;
    func_003CA4A0(m, 1, &loc, &c);
    func_0038CE20(&c.v30, &c.v30, m->f2C * 0.0009765625f);
    func_0038D570(&c.v40, &m->vC0);
    c.v70 = m->pos;
    func_0038D640(&c, &c.v40, &c);
    q->pos = c.v30;
    if (q->flags & 0x10) {
        return;
    }
    if (q->flags & 4) {
        v80 = c.v20;
        if (p->h408 != 1) {
            vA0 = q->vE0;
            vec_sub_ab(&vB0, &v80, &vA0);
            lenA = func_L01_0040E4C0(&vB0);
            f20 = (D_L05_001DD624 * 5.0f + 2.0f) / 6.0f;
            f20 = f20 * f20;
            if (func_L02_003E6F38(0.0f, lenA, f20)) {
                p->h408 = 1;
            } else {
                p->h408 = 0;
                func_0038CE20(&vB0, &vB0, sqrt_asm(f20 / lenA));
                vec_add_ab(&v80, &vB0, &vA0);
                func_0038CF68(&v80, &v80, 1.0f);
            }
        }
    } else {
        v80 = c.v60;
        if (p->h408 != 2) {
            vA0 = q->vE0;
            vec_sub_ab(&vB0, &v80, &vA0);
            lenB = func_L01_0040E4C0(&vB0);
            f20 = (D_L05_001DD624 * 5.0f + 2.0f) / 6.0f;
            f20 = f20 * f20;
            if (func_L02_003E6F38(0.0f, lenB, f20)) {
                p->h408 = 2;
            } else {
                p->h408 = 0;
                func_0038CE20(&vB0, &vB0, sqrt_asm(f20 / lenB));
                vec_add_ab(&v80, &vB0, &vA0);
                func_0038CF68(&v80, &v80, 1.0f);
            }
        }
    }
    *(vu0_q *)&q->vE0 = *(vu0_q *)&v80;
    f21 = (D_L05_001DD61C * 5.0f + 2.0f) / 6.0f;
    f21 = f21 * f21;
    if (func_L05_00355B80(q)) {
        f21 = f21 * 4.0f;
    }
    if (q->flags & 1) {
        vec_sub_ba(&v90, &p->v220, &q->pos);
        f23 = 0.0f;
        dot = func_0038CE68(&v80, &v90);
        func_0038CE20(&vA0, &v80, dot);
        vec_sub_ba(&v90, &v90, &vA0);
        vB0 = c.v40;
        dot = func_0038CE68(&v80, &vB0);
        func_0038CE20(&vA0, &v80, dot);
        vec_sub_ab(&vB0, &vB0, &vA0);
        f20 = func_0038CE68(&vB0, &v90);
        if (f20 < f23) {
            dot = func_L01_0040E4C0(&vB0);
            func_0038CE20(&vA0, &vB0, f20 / dot);
            vec_sub_ab(&v90, &v90, &vA0);
        }
        f22 = 1.0f;
        func_0038CF68(&v90, &v90, f22);
        vC0 = q->vC0;
        dot = func_0038CE68(&v90, &vC0);
        if (dot < 0.96f) {
            *st = 0;
        }
        if (*st != 2) {
            dot = func_0038CE68(&v80, &vC0);
            func_0038CE20(&vA0, &v80, dot);
            vec_sub_ba(&vC0, &vC0, &vA0);
            func_0038CF68(&vC0, &vC0, f22);
            vec_sub_ab(&vD0, &v90, &vC0);
            f20 = func_L01_0040E4C0(&vD0);
            if (func_L02_003E6F38(f23, f20, f21)) {
                *st = 2;
            } else {
                *st = 0;
                func_0038CE20(&vD0, &vD0, sqrt_asm(f21 / f20));
                vec_add_ab(&v90, &vD0, &vC0);
                func_0038CF68(&v90, &v90, f22);
            }
        }
    } else {
        if (q->flags & 4) {
            v90 = c.v00;
        } else {
            v90 = c.v40;
        }
        f22 = 1.0f;
        dot = func_0038CE68(&v80, &v90);
        func_0038CE20(&vA0, &v80, dot);
        vec_sub_ab(&v90, &v90, &vA0);
        func_0038CF68(&v90, &v90, f22);
        if (*st != 1) {
            vB0 = q->vC0;
            dot = func_0038CE68(&v80, &vB0);
            func_0038CE20(&vA0, &v80, dot);
            vec_sub_ba(&vB0, &vB0, &vA0);
            func_0038CF68(&vB0, &vB0, f22);
            vec_sub_ab(&vC0, &v90, &vB0);
            len = func_L01_0040E4C0(&vC0);
            f20 = (D_L05_001DD620 * 5.0f + 2.0f) / 6.0f;
            f20 = f20 * f20;
            if (func_L02_003E6F38(0.0f, len, f20)) {
                *st = 1;
            } else {
                *st = 0;
                func_0038CE20(&vC0, &vC0, sqrt_asm(f20 / len));
                vec_add_ab(&v90, &vC0, &vB0);
                func_0038CF68(&v90, &v90, f22);
            }
        }
    }
    q->vC0 = v90;
    pc = &q->vC0;
    func_0038CE90(&q->vD0, &v90, &v80);
    f21 = 0.0f;
    r = &p->r;
    if (q->flags & 2) {
        func_L01_0040EE50(&vA0, pc);
        f20 = D_L05_001DD60C;
        if (func_L05_00355AE8(m)) {
            f20 = D_L05_001DD610;
        }
        func_0038CE20(&vD0, &m->vE0, f20);
        vec_add_ba(&vE0, &vD0, &m->pos);
        vec_sub_ba(&vD0, &p->v220, &vE0);
        func_0038CF68(&vD0, &vD0, 1.0f);
        func_0038D000(&vD0, &vD0, &vA0);
        if (vD0.x < D_L05_001DD618) {
            if (vD0.z < 0.0f) {
                f21 = -D_L05_001DD614;
            } else {
                f21 = D_L05_001DD614;
            }
        } else {
            f21 = func_0038D160(vD0.x, vD0.z);
        }
        f21 = f21 * 0.5f;
    }
    if (r->b1 == 0) {
        func_L01_0043A430(q, 5, r);
    }
    fa = r->f2C;
    fb = r->f3C;
    func_L01_00448728(&fa, f21, &fb, 0.369333357f, 0.693333387f, 0.0f, 0);
    r->f2C = fa;
    r->f3C = fb;
    loc = 5;
    func_003CA4A0(q, 1, &loc, &c);
    func_L01_0040EE50(&vA0, &c);
    r->v10 = vB0;
    func_0038CE20(&r->v10, &r->v10, func_0038D0B0(fa));
    r->v10.w = func_0038D098(fa);
}

