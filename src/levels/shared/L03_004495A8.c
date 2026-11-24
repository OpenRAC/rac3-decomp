#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L03_004495A8 */
extern int D_L03_0021D8C0[];
extern void func_L03_004495E8(int, int);

void func_L03_004495A8(int a0, int a1) {
    int p;
    if (a1 != -1) {
        p = D_L03_0021D8C0[a1];
        if (p != 0)
            func_L03_004495E8(a0, p);
    }
}
/* localdecomp:end func_L03_004495A8 */

/* localdecomp:start func_L03_004495E8 */
typedef struct { s32 count; s32 pad[3]; vu0_v4 pts[1]; } P_004495E8;
typedef struct { u8 pad[0x34]; f32 f34; s32 w38; u8 pad3C[0xC4 - 0x3C]; P_004495E8 *wC4; s16 hC8; s16 hCA; } S_004495E8;
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CEA8(void *);
extern f32 func_0038CE68(void *, void *);
extern void *func_L01_0045B958(void *);
extern s32 func_L01_0045A748(void *, void *);
extern void func_L03_00449838(s32, s32, s16, s16);
void func_L03_004495E8(int a0, int a1) {
    u8 *o = (u8 *)a0;
    P_004495E8 *t = (P_004495E8 *)a1;
    S_004495E8 *m;
    f32 v[4];
    f32 d[4];
    f32 e[4];
    s16 i;
    f32 len;
    f32 s;
    m = func_L01_0045B958(o);
    if (m == 0) {
        return;
    }
    if (t != m->wC4) {
        func_L03_00449838(a0, a1, 1, -1);
    }
    s = m->f34 * 10.0f + 1.0f;
    vec_sub_ba(v, &t->pts[m->hC8], o + 0x10);
    if (!(m->w38 & 0x400)) {
        v[2] = 0.0f;
    }
    func_0038CF68(v, v, s);
    vec_add_ab(v, v, o + 0x10);
    func_L01_0045A748(o, v);
    i = m->hC8 - m->hCA;
    if (i < 0) {
        i += t->count;
    } else if (i >= t->count) {
        i -= t->count;
    }
    vec_sub_ba(d, &t->pts[m->hC8], &t->pts[i]);
    if (!(m->w38 & 0x400)) {
        d[2] = 0.0f;
    }
    len = func_0038CEA8(d) - m->f34;
    func_0038CF68(d, d, 1.0f);
    vec_sub_ab(e, o + 0x10, &t->pts[i]);
    if (len < func_0038CE68(e, d)) {
        m->hC8 += m->hCA;
        if (m->hC8 < 0) {
            m->hC8 += t->count;
        } else if (m->hC8 >= t->count) {
            m->hC8 -= t->count;
        }
    }
}
/* localdecomp:end func_L03_004495E8 */

/* localdecomp:start func_L03_004497E8 */
extern s32 D_L03_0021D8C0[];
extern void func_L03_00449838(s32 a0, s32 a1, s16 a2, s16 a3);
void func_L03_004497E8(s32 a0, s32 a1, s16 a2, s16 a3) {
    if (a1 != -1) {
        s32 x = D_L03_0021D8C0[a1];
        if (x) {
            func_L03_00449838(a0, x, a2, a3);
        }
    }
}
/* localdecomp:end func_L03_004497E8 */

/* localdecomp:start func_L03_00449838 */
extern void *func_L01_0045B958(void *);
extern s32 func_L03_004640A8(void *, void *, f32);
typedef struct { u8 pad[0x9C]; s32 w9C; u8 padA0[0x24]; s32 wC4; s16 hC8; s16 hCA; } S_449838;

void func_L03_00449838(s32 a0, s32 a1, s16 a2, s16 a3) {
    S_449838 *m = func_L01_0045B958((void *)a0);
    m->w9C |= 4;
    m->wC4 = a1;
    m->hCA = a2;
    if (a3 == -1) {
        m->hC8 = func_L03_004640A8((u8 *)a0 + 0x10, (void *)a1, 0.0f);
    } else {
        m->hC8 = a3;
    }
}
/* localdecomp:end func_L03_00449838 */
