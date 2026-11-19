/* functional: medium. Not byte-near (392 words differ: frame and registers); control flow and every store re-read block by block against PAL asm. Needs -mvu0-use-vf0-vf2. func_L39_006202E0 has no matched C: its 8-arg prototype (a4=k+0x80, a7=k+0xF8 left in registers by the preceding paths) is my reading of the asm. */
typedef struct {
    vu0_v4 q[2];
    s32 t[2];
    s32 idx;
    u8 pad2C[4];
    vu0_v4 v30;
    vu0_v4 v40;
    vu0_v4 v50;
    vu0_v4 v60;
    vu0_v4 v70;
    vu0_v4 v80;
    vu0_v4 v90;
    vu0_v4 vA0;
    vu0_v4 vB0;
    u8 padC0[0x30];
    f32 *pF0;
    s32 iF4;
    s32 iF8;
    s32 iFC;
    u8 pad100[0x10];
    vu0_v4 q110[2];
    s32 pend[2];
    s32 i138;
    u8 pad13C[4];
    s32 i140;
    u8 pad144[4];
    s32 i148;
} T_0061F5A0;

extern f32 D_L39_0024118C;
__asm__(".extern D_L39_0024118C, 16");
extern f32 func_L39_0061FDF0(vu0_v4 *, vu0_v4 *, vu0_v4 *);
extern void func_L39_0061FEA8(vu0_v4 *, vu0_v4 *, vu0_v4 *, vu0_v4 *, vu0_v4 *, s32 *, s32 *, s32 *);
extern void func_L39_00620168(vu0_v4 *, s32 *, s32, vu0_v4 *, vu0_v4 *, vu0_v4 *, s32, s32, f32);
extern void func_L39_00620240(vu0_v4 *, s32 *, s32, vu0_v4 *, vu0_v4 *, s32 *, s32 *, f32, f32);
extern void func_L39_006202E0(vu0_v4 *, vu0_v4 *, vu0_v4 *, vu0_v4 *, vu0_v4 *, s32 *, s32 *, s32 *);
extern void func_L39_006205B0(void *, void *, void *, s32 *, s32 *);
extern void func_0038CE20(void *, void *, f32);

void func_L39_0061F5A0(T_0061F5A0 *k, vu0_v4 *vec, s32 now, s32 force) {
    s32 tl = now;
    s32 idx = k->idx;
    s32 n = (idx + 1) % 2;
    s32 *timeI = &k->t[idx];
    s32 *timeN = &k->t[n];
    vu0_v4 *slotI = &k->q[idx];
    vu0_v4 *slotN = &k->q[n];
    vu0_v4 *out = &k->v80;
    s32 *outi = &k->iF8;
    f32 d;
    s32 near;

    if (tl < *timeI) {
        return;
    }
    if (tl < *timeN) {
        s32 old = *timeN;
        vu0_v4 qn;
        *timeN = tl;
        tl = old;
        qn = *slotN;
        *slotN = *vec;
        *vec = qn;
    }
    d = func_L39_0061FDF0(slotI, slotN, vec);
    near = (k->i148 & 4) || d < *k->pF0;
    if (force == 0) {
        if ((k->i148 & 0x40) || (near && k->iFC < *timeI)) {
            s32 m = k->i138;
            if (k->i148 & 0x40) {
                s32 m2 = (m + 1) % 2;
                k->q110[m2] = *vec;
                k->pend[(k->i138 + 1) % 2] = now;
                return;
            }
            k->q110[m] = *vec;
            k->pend[k->i138] = now;
            k->i148 |= 0x40;
            k->i140 = *timeI;
            return;
        }
    } else {
        s32 m = k->i138;
        s32 m2 = (m + 1) % 2;
        if (k->pend[m] < k->pend[m2]) {
            f32 d2 = func_L39_0061FDF0(slotN, vec, &k->q110[m2]);
            if (!(k->i148 & 4) && k->pF0[0] <= d2) {
                s32 v;
                d = d2;
                *slotI = *slotN;
                near = 0;
                *slotN = *vec;
                *vec = k->q110[(k->i138 + 1) % 2];
                *timeI = *timeN;
                *timeN = tl;
                v = k->pend[(k->i138 + 1) % 2];
                k->pend[(k->i138 + 1) % 2] = 0;
                tl = v;
                k->i148 &= ~0x40;
            } else {
                k->i140 = tl;
                k->i138 = (k->i138 + 1) % 2;
            }
        } else {
            k->i148 &= ~0x40;
        }
    }
    k->v70 = k->v90;
    k->iF4 = k->iFC;
    if (near) {
        func_L39_00620240(out, outi, k->iFC, slotN, vec, timeN, &tl, k->pF0[2], k->pF0[3]);
        vec_sub_ba(&k->v30, vec, slotN);
        func_0038CE20(&k->v30, &k->v30, 1.0f / ((f32)(tl - *timeN) / (D_L39_0024118C * 1000.0f)));
        qzero(&k->v40);
    } else {
        vu0_v4 acc;
        func_L39_0061FEA8(&k->v30, &k->v40, slotI, slotN, vec, timeI, timeN, &tl);
        acc = k->v40;
        func_L39_00620168(out, outi, k->iFC, &k->v30, &acc, vec, *timeN, tl, k->pF0[4]);
    }
    if ((k->i148 & 2) || k->pF0[1] < d) {
        k->i148 = (k->i148 & ~1) | 0x10;
        func_L39_006205B0(&k->v50, &k->v90, out, &k->iFC, outi);
        qzero(&k->v60);
    } else {
        vu0_v4 *a2, *a3;
        s32 *a5, *a6;
        if ((k->i148 & 1) && k->iFC < tl) {
            k->i148 |= 0x20;
        }
        if (tl < k->iFC) {
            a2 = slotN; a3 = &k->v90; a5 = timeN; a6 = &k->iFC;
        } else if (*timeI < k->iFC) {
            a2 = slotI; a3 = &k->v90; a5 = timeI; a6 = &k->iFC;
        } else {
            a2 = &k->v90; a3 = slotI; a5 = &k->iFC; a6 = timeI;
        }
        k->i148 = k->i148 & ~1 & ~0x10;
        func_L39_006202E0(&k->v50, &k->v60, a2, a3, out, a5, a6, outi);
        if (!(*timeI < k->iFC)) {
            vu0_v4 tmp;
            func_0038CE20(&tmp, &k->v60, (f32)(*timeI - k->iFC) / (D_L39_0024118C * 1000.0f));
            vec_sub_ba(&k->v50, &k->v50, &tmp);
        }
    }
    *slotI = *vec;
    *timeI = now;
    k->idx = (k->idx + 1) % 2;
}
