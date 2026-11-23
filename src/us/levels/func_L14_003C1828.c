#include "common.h"

/* NTSC-U counterpart of func_L14_003C35B0. */
/* localdecomp:start func_L14_003C1828 */
#include "vu0.h"

typedef struct {
    f32 f0;         /* 0x00 */
    f32 f4;         /* 0x04 */
    f32 f8;         /* 0x08 */
    f32 fC;         /* 0x0C */
    s32 path;       /* 0x10 */
    s32 point;      /* 0x14 */
    f32 speed;      /* 0x18 */
} V_003C35B0;

typedef struct {
    s32 count;
    u8 pad4[0xC];
    vu0_v4 pts[1];
} P_003C35B0;

typedef struct {
    u8 pad0[0x10];
    vu0_v4 pos;     /* 0x10 */
    u8 state;       /* 0x20 */
    u8 pad21[3];
    u8 *parent;     /* 0x24 */
    u8 pad28[0xC];
    u16 flags;      /* 0x34 */
    u8 pad36[0x32];
    V_003C35B0 *vars; /* 0x68 */
    u8 pad6C[0xC];
    s32 color;      /* 0x78 */
    u8 pad7C[0x1C];
    s32 x98;        /* 0x98 */
    u8 pad9C[0x14];
    u8 xB0;         /* 0xB0 */
} M_003C35B0;

extern s32 D_001D545C;
extern s32 D_001D6694;
extern u8 D_001BBC40[];
extern s32 D_00142C48[];
extern s32 D_00142C4C[];
extern s32 D_00142C5C[];
__asm__(".extern D_L14_001DEC10, 4");
extern f32 D_L14_001DEC10;
extern f32 D_L14_001DEC14;
extern P_003C35B0 *D_L14_0021DF80[];
extern void func_L01_004450F0(void *, s32, s32);
extern void func_003C2880(void *);
extern void func_L01_004AA7E8(void *, s32);
extern void func_L01_0044EAE0(void *, void *, void *, f32, f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);
extern s32 func_0038DBD8(s32, s32, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_L01_004436F4(void *);

void func_L14_003C1828(M_003C35B0 *m) {
    V_003C35B0 *v = m->vars;
    P_003C35B0 *path;
    vu0_v4 tgt;
    vu0_v4 d;
    f32 s;

    if (m->state == 0 && D_001D545C == 0x10) {
        if (D_001BBC40[m->xB0 + 0x100] & 0x80) {
            func_003C2880(m);
            return;
        }
        v->f4 = m->pos.z;
        func_L01_004450F0(m, 1, -1);
    }
    if (D_001D6694 == 2 && D_001D545C == 0x16) {
        m->x98 = 0;
        m->flags = (m->flags | 0x41) & ~0x1000;
        func_L01_004AA7E8(m, 1);
    }
    if (D_001D545C == 0x16 && D_00142C5C[0] < 0) {
        func_003C2880(m);
        return;
    }
    if (D_001D545C == 0xE && (D_00142C48[0] & 0x800)) {
        func_003C2880(m);
        return;
    }
    if (D_001D545C == 0x10) {
        if (!(D_00142C4C[0] & 0x4000) || D_001D6694 == 2) {
            m->x98 = 0;
            m->flags = (m->flags | 0x41) & ~0x1000;
            func_L01_004AA7E8(m, 1);
        } else {
            m->flags &= ~0x41;
            m->flags |= *(u16 *)(m->parent + 0x44) & 0x1000;
            m->x98 = *(s32 *)(m->parent + 0x10);
        }
    }
    if (m->state != 2) {
        func_L01_0044EAE0(m, &v->f8, &v->fC, D_L14_001DEC10, D_L14_001DEC14 * 0.017453292f * 0.016666668f, v->f4);
    }
    v->f0 = func_0038DAB8(v->f0, 0.0290888231f);
    s = func_0038D0B0(v->f0);
    m->color = func_0038DBD8(0x8000A0A0, 0x80005050, (s + 1.0f) * 0.5f);
    if (D_001D545C == 0x10 && m->state == 1 && (D_00142C4C[0] & 0x4000) && D_001D6694 != 2) {
        v->speed = 0.200000018f;
        func_L01_004450F0(m, 2, -1);
    }
    if (D_001D545C == 0x10 && m->state == 2) {
        path = D_L14_0021DF80[v->path];
        if (v->point >= path->count) {
            func_L01_004450F0(m, 3, -1);
            return;
        }
        tgt = *(path->pts + v->point);
        vec_sub_ba(&d, &tgt, &m->pos);
        func_0038CF68(&d, &d, v->speed);
        vec_add_ab(&m->pos, &m->pos, &d);
        if (func_0038CF38(&m->pos, &tgt) < 0.5f) {
            v->point++;
        }
        if (v->point >= path->count - 6 && v->speed >= 0.0500000045f) {
            v->speed -= 0.00222222228f;
        }
        func_L01_004436F4(m);
    }
}
/* localdecomp:end func_L14_003C1828 */
