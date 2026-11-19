/* functional: high. Near miss (register/ordering only after the callee return); needs -mvu0-use-vf0-vf2 for vu0.h helpers, which the file's flag line lacks. Dead sq to sp+0 omitted (local copy never read). */
typedef struct {
    u128_t q[2];
    s32 t[2];
    s32 idx;
    u8 pad2C[4];
    vu0_v4 v30;
    vu0_v4 v40;
    u8 pad50[0xA0];
    s32 pF0;
    s32 iF4;
    s32 iF8;
    s32 iFC;
    u8 pad100[0x48];
    s32 i148;
    u8 pad14C[0xC];
    s32 i158;
    s32 i15C;
    u128_t q160;
} K_0061FBC8;

extern f32 D_L39_0024118C;
__asm__(".extern D_L39_0024118C, 16");
extern f32 func_L39_0061FDF0(u128_t *, u128_t *, u128_t *);
extern void func_L39_0061FEA8(vu0_v4 *, vu0_v4 *, u128_t *, u128_t *, u128_t *, s32 *, s32 *, s32 *);
extern void func_0038CE20(void *, void *, f32);

void func_L39_0061FBC8(K_0061FBC8 *k, u128_t *vec, s32 now) {
    s32 tl;
    s32 idx, n;
    f32 d;
    u128_t *slotN, *slotI;
    s32 *timeI, *timeN;

    tl = now;
    if ((now >> 9) != (k->i158 >> 9) && k->i158 != -1 && (now & 0x1FF) < 0x100) {
        k->i15C = now + 0xF5;
        k->q160 = *vec;
    }
    idx = k->idx;
    k->i158 = tl;
    timeI = &k->t[idx];
    n = (idx + 1) % 2;
    slotN = &k->q[n];
    timeN = &k->t[n];
    slotI = &k->q[idx];
    if (tl < *timeI) {
        return;
    }
    if (tl < *timeN) {
        s32 old = *timeN;
        u128_t qn;
        *timeN = tl;
        tl = old;
        qn = *slotN;
        *slotN = *vec;
        *vec = qn;
    }
    d = func_L39_0061FDF0(slotI, slotN, vec);
    if ((k->i148 & 4) || d < *(f32 *)k->pF0) {
        vec_sub_ba(&k->v30, (vu0_v4 *)vec, (vu0_v4 *)slotN);
        func_0038CE20(&k->v30, &k->v30, 1.0f / ((f32)(tl - *timeN) / (D_L39_0024118C * 1000.0f)));
        qzero(&k->v40);
    } else {
        func_L39_0061FEA8(&k->v30, &k->v40, slotI, slotN, vec, timeI, timeN, &tl);
    }
    *slotI = *vec;
    *timeI = tl;
    k->idx = (k->idx + 1) % 2;
    k->iF4 = tl;
    ((u128_t *)((u8 *)k + 0x70))[0] = *vec;
    ((u128_t *)((u8 *)k + 0x90))[0] = *vec;
    k->iFC = tl;
}
