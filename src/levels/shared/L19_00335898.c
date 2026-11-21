#include "common.h"

/* declared by functions of L19_003357A0.c, which this file was cut from */
typedef struct {
    u8 b[0x100];
} E_003357A0;
extern void func_L19_00335898(void *, E_003357A0 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32);

/* localdecomp:start func_L19_00335898 */
#include "vu0.h"

typedef struct {
    vu0_v4 v[4];
    s32 rgba[4];
    f32 uv[4][2];
    long w70;
    u8 pad78[0x18];
} Q_00335898;
typedef struct {
    vu0_v4 base;
    u8 pad10[8];
    s32 w18;
    s32 w1C;
    u8 pad20[4];
    s32 w24;
    u8 pad28[0x3C - 0x28];
    s32 w3C;
    u8 pad40[0x80 - 0x40];
    s32 w80;
    f32 f84;
    u8 pad88[0x9C - 0x88];
    s32 w9C;
    u8 padA0[0xAC - 0xA0];
    f32 fAC;
    f32 fB0;
    u8 padB4[0xCC - 0xB4];
    f32 fCC;
    f32 fD0;
} S_00335898;
extern vu0_v4 D_L19_001E2080;
extern vu0_v4 D_L19_00276E50;
extern void func_L19_00336088(u8 *, s32, s32, s32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern s32 func_0038DBD8(s32, s32, f32);
extern f32 func_003C4088(f32, f32, f32);
extern void func_003D2DA0(void *, s32, s32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_003A9440(s32, unsigned long);

void func_L19_00335898(void *arg0, E_003357A0 *arg1, s32 n, s32 c0a, s32 c0b, s32 c1a, s32 c1b, f32 w0a, f32 w0b,
                       f32 w1a, f32 w1b, f32 k) {
    vu0_v4 toCam;
    Q_00335898 qb;
    Q_00335898 qa;
    vu0_v4 dir;
    vu0_v4 w;
    vu0_v4 pos;
    vu0_v4 d;
    u8 *m = arg0;
    S_00335898 *p = *(S_00335898 **)(m + 0x68);
    vu0_v4 *pt = (vu0_v4 *)arg1;
    f32 t;
    f32 cc;
    f32 l;
    f32 a;
    f32 wa;
    f32 wb;
    f32 scale;
    f32 len;
    f32 wwa0;
    f32 wwa1;
    f32 wwb0;
    f32 wwb1;
    s32 ca0;
    s32 ca1;
    s32 cb0;
    s32 cb1;
    s32 i;
    s32 j;

    t = 0.0f;
    func_L19_00336088((u8 *)&qa, p->w9C, 1, c0a);
    qa.w70 = 0;
    for (j = 0; j < 4; j++) {
        qa.uv[j][0] += p->f84;
    }
    func_L19_00336088((u8 *)&qb, p->w80, 1, c1a);
    pos = *(vu0_v4 *)(m + 0x10);
    pos.z += 1.1f;
    qb.w70 = 0;
    if (m[0x20] == 3) {
        cc = p->fCC;
        t = (cc + cc + 1.0f) * (1.0f - (f32)p->w24 / (f32)p->w1C) - cc;
        if (1.0f - cc < t && (p->w3C & 2)) {
            func_0038CF68(&d, &D_L19_00276E50, p->fD0);
            vec_add_ab(m + 0x10, &p->base, &d);
        }
    }
    for (i = 0; i < n - 1; i++) {
        wb = 0.0f;
        wa = 0.0f;
        if (m[0x20] == 3) {
            vec_sub_ab(&d, &pos, &pt[i]);
            l = func_0038CEA8(&d) / 1.1f;
            a = fabs_asm(t - l);
            if (a < p->fCC) {
                wa = 1.0f - a / p->fCC;
            }
            vec_sub_ab(&d, &pos, &pt[i + 1]);
            l = func_0038CEA8(&d) / 1.1f;
            a = fabs_asm(t - l);
            if (a < p->fCC) {
                wb = 1.0f - a / p->fCC;
            }
        } else if (m[0x20] == 2) {
            vec_sub_ab(&d, &pos, &pt[i]);
            l = func_0038CEA8(&d) / 1.1f;
            if (l < p->fCC) {
                wa = (1.0f - l / p->fCC) * (1.0f - (f32)p->w24 / (f32)p->w18);
            }
            vec_sub_ab(&d, &pos, &pt[i + 1]);
            l = func_0038CEA8(&d) / 1.1f;
            if (l < p->fCC) {
                wb = 1.0f - l / p->fCC;
            }
        }
        scale = 1.0f;
        ca0 = func_0038DBD8(c0a, c0b, wa);
        ca1 = func_0038DBD8(c1a, c1b, wa);
        wwa0 = func_003C4088(w0a, w0b, wa);
        wwa1 = func_003C4088(w1a, w1b, wa);
        cb0 = func_0038DBD8(c0a, c0b, wb);
        cb1 = func_0038DBD8(c1a, c1b, wb);
        wwb0 = func_003C4088(w0a, w0b, wb);
        wwb1 = func_003C4088(w1a, w1b, wb);
        if (p->w3C & 4) {
            f32 dist;
            vec_sub_ba(&dir, &pt[i], &pos);
            dist = func_0038CEA8(&dir);
            if (dist < p->fB0) {
                scale = p->fAC * (1.0f - dist / p->fB0) + 1.0f;
            }
        }
        vec_sub_ab(&toCam, &pt[i], &D_L19_001E2080);
        vec_sub_ab(&dir, &pt[i + 1], &pt[i]);
        len = func_0038CEA8(&dir);
        func_0038CE90(&w, &dir, &toCam);
        qa.rgba[0] = qa.rgba[1] = qa.rgba[2] = qa.rgba[3] = ca0;
        func_0038CF68(&w, &w, scale * wwa0 * len);
        vec_add_ba(&qa.v[0], &pt[i], &w);
        vec_sub_ba(&qa.v[1], &pt[i], &w);
        qa.rgba[0] = qa.rgba[1] = qa.rgba[2] = qa.rgba[3] = cb0;
        func_0038CF68(&w, &w, scale * wwb0 * len);
        vec_add_ba(&qa.v[2], &pt[i + 1], &w);
        vec_sub_ab(&qa.v[3], &pt[i + 1], &w);
        func_003D2DA0(&qa, 0, 0);
        qb.rgba[0] = qb.rgba[1] = qb.rgba[2] = qb.rgba[3] = ca1;
        func_0038CF68(&w, &w, scale * wwa1 * len);
        vec_add_ba(&qb.v[0], &pt[i], &w);
        vec_sub_ba(&qb.v[1], &pt[i], &w);
        qb.rgba[0] = qb.rgba[1] = qb.rgba[2] = qb.rgba[3] = cb1;
        func_0038CF68(&w, &w, scale * wwb1 * len);
        vec_add_ba(&qb.v[2], &pt[i + 1], &w);
        vec_sub_ab(&qb.v[3], &pt[i + 1], &w);
        func_0038CE20(&dir, &dir, k);
        vec_sub_ab(&qb.v[0], &qb.v[0], &dir);
        vec_sub_ab(&qb.v[1], &qb.v[1], &dir);
        vec_add_ba(&qb.v[2], &qb.v[2], &dir);
        vec_add_ab(&qb.v[3], &qb.v[3], &dir);
        func_003D2DA0(&qb, 0, 0);
    }
    func_003A9440(0x47, 0x5360B);
}
/* localdecomp:end func_L19_00335898 */
