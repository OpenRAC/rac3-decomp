/* functional: medium. Not byte-near (about 369 words differ in registers/ordering); control flow, constants (0.2, 0.02, 1.44, 0.01) and offsets read from PAL asm. Needs -mvu0-use-vf0-vf2. D_L39_0024118C is gp-relative in the tail of retail (declared plain there); here one extern is used. */
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
    u8 padC0[0x28];
    s32 iE8;
    f32 fEC;
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
    s32 i144;
    s32 i148;
    u8 pad14C[0xC];
    s32 i158;
    s32 i15C;
    vu0_v4 q160;
    vu0_v4 q170;
    vu0_v4 q180;
} U_0061ED80;

extern s32 D_001A5DF8[];
extern f32 D_L39_0024118C;
__asm__(".extern D_L39_0024118C, 16");
extern void func_L39_0061F5A0(U_0061ED80 *, vu0_v4 *, s32, s32);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CED8(void *);
extern void func_0038CFB8(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE20(void *, void *, f32);
extern void func_003C4360(f32 *, f32, f32, f32, f32);

void func_L39_0061ED80(U_0061ED80 *k, vu0_v4 *vec, s32 *tp) {
    s32 now;
    vu0_v4 old90, oldA0, p20, p30, p40, p50, p60;
    f32 d, f20, lim, len, cap, step;
    f32 z, lim0, lim1;
    f32 fa, fb;

    fa = k->pF0[8];
    fb = k->pF0[9];
    if (k->i15C >= 0 && !(D_001A5DF8[0] < k->i15C)) {
        k->q180 = k->q170;
        k->q170 = k->q160;
        k->i15C = -1;
    }
    if (vec != 0) {
        s32 t = *tp;
        if ((t >> 9) != (k->i158 >> 9) && k->i158 != -1 && (t & 0x1FF) < 0x100) {
            k->q160 = *vec;
            k->i15C = *tp + 0xF5;
        }
        k->i148 &= ~0x80;
        k->iE8 = 0;
        k->i158 = *tp;
        func_L39_0061F5A0(k, vec, *tp, 0);
    }
    now = D_001A5DF8[0] - k->i144;
    if (k->i148 & 0x40) {
        if (!(now < k->i140)) {
            s32 m;
            k->iE8 = 0;
            k->i148 &= ~0x40;
            m = k->i138;
            func_L39_0061F5A0(k, &k->q110[m], k->pend[m], 1);
        }
    }
    old90 = k->v90;
    oldA0 = k->vA0;
    d = func_0038CF00(&k->v80, &k->v90);
    if (now < k->iF8) {
        k->fEC = d;
    } else if (k->i148 & 1) {
        k->fEC = d;
    } else if (d < 0.2f) {
        k->fEC = 0.0f;
        k->i148 |= 1;
    } else if (!(0.0f < k->fEC) || !(k->fEC < d) || !(k->fEC < func_0038CEA8(&k->vA0))) {
        k->fEC = d;
    } else {
        k->fEC = 0.0f;
        k->i148 |= 1;
    }
    if (k->iE8 != 0 && !(now < k->iE8)) {
        k->iE8 = 0;
        k->i148 |= 0x80;
    }
    if (k->i148 & 0x80) {
        f32 sp70;
        len = func_0038CED8(&k->vA0);
        cap = k->pF0[6] * 0.02f;
        sp70 = len;
        if (cap < len) {
            sp70 = cap;
        }
        func_003C4360(&sp70, 0.0f, 0.0f, k->pF0[9] * 1.44f, cap);
        if (sp70 < 0.0f) {
            sp70 = 0.0f;
        }
        func_0038CFB8(&k->vA0, &k->vA0, sp70);
        vec_add_ba(&k->v90, &k->v90, &k->vA0);
    } else {
        f32 sp74;
        if (k->i148 & 1) {
            s32 n = (k->idx + 1) % 2;
            f32 tt = (f32)(now - k->t[n]) / (D_L39_0024118C * 1000.0f);
            cap = k->pF0[6];
            func_0038CE20(&p20, &k->v30, tt);
            func_0038CE20(&p30, &k->v40, tt * 0.5f * tt);
            vec_add_ba(&p40, &p20, &p30);
            k->v90.z = 0.0f;
            vec_add_ba(&p50, &k->q[(k->idx + 1) % 2], &p40);
        } else {
            f32 tt = (f32)(now - k->iF4) / (D_L39_0024118C * 1000.0f);
            cap = k->pF0[7];
            func_0038CE20(&p20, &k->v50, tt);
            func_0038CE20(&p30, &k->v60, tt * 0.5f * tt);
            vec_add_ba(&p40, &p20, &p30);
            k->v90.z = 0.0f;
            vec_add_ba(&p50, &k->v70, &p40);
        }
        z = p50.z;
        p50.z = 0.0f;
        len = func_0038CED8(&k->vA0);
        cap = cap * 0.02f;
        sp74 = len;
        if (cap < len) {
            sp74 = cap;
        }
        vec_sub_ba(&p60, &p50, &k->v90);
        f20 = func_0038CEA8(&p60);
        func_003C4360(&sp74, f20, fa * 1.44f, fb * 1.44f, cap);
        func_0038CF68(&p60, &p60, sp74);
        vec_add_ba(&k->v90, &k->v90, &p60);
        f20 = f20 - sp74;
        if (f20 < 0.0f) {
            f20 = -f20;
        }
        if (f20 < cap * 0.01f) {
            k->v90 = p50;
        }
        k->v90.z = z;
    }
    if (now != k->iFC) {
        f32 inv;
        vec_sub_ba(&k->vA0, &old90, &k->v90);
        inv = 1.0f / ((f32)(now - k->iFC) / (D_L39_0024118C * 1000.0f));
        func_0038CE20(&k->vA0, &k->vA0, inv);
        vec_sub_ba(&k->vB0, &oldA0, &k->vA0);
        func_0038CE20(&k->vB0, &k->vB0, inv);
        k->iFC = now;
    }
}
