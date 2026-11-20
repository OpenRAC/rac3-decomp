#include "common.h"

/* localdecomp:start func_L39_0056CC48 */
#include "vu0.h"

typedef int u128_0056CC48 __attribute__((mode(TI)));

extern u8 D_L39_0024DE80[];
extern s32 D_L39_0024B868[2];
extern vu0_v4 D_L39_0025F760;
extern s32 D_L39_002412DC;
__asm__(".extern D_L39_002412DC, 16");
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_L01_003E4168(void *);
extern s32 func_L01_003FB640(void *, s32, u8 *, f32);
extern s32 func_L01_003E7F48(void *, s32, void *, f32);
extern s32 func_L01_003E7B80(void *, void *, s32, f32, f32);

s32 func_L39_0056CC48(u8 *a0) {
    vu0_v4 dir0;
    vu0_v4 pos;
    vu0_v4 dir;
    vu0_v4 step;
    vu0_v4 old;
    vu0_v4 d;
    u8 *m;
    u8 *cam;
    u8 *st;
    u8 *pl;
    u8 *pls;
    u8 *sub;
    s32 ret;
    s32 flag;
    s32 i;
    f32 sp;
    f32 dist;
    s32 *q;

    ret = 0;
    m = *(u8 **)(a0 + 0x70);
    sub = m + 0x60;
    cam = m + 0x180;
    *(u128_0056CC48 *)&dir0 = *(u128_0056CC48 *)(m + 0x180);
    st = m + 0x210;
    pl = D_L39_0024DE80 + *(s32 *)(a0 + 0x94) * 0x460;
    dist = 0.0f;
    *(u128_0056CC48 *)&pos = *(u128_0056CC48 *)(m + 0xB0);
    pls = pl + 0x150;
    func_0038CF68(&dir, &dir0, 1.0f);
    sp = 0.35f;
    flag = 0;
    if (D_L39_002412DC == 0x30 || D_L39_002412DC == 0x1C) {
        if (!(D_L39_0024B868[*(s32 *)(a0 + 0x94)] & 0x20)) {
            flag = 1;
            D_L39_0024B868[*(s32 *)(a0 + 0x94)] |= 0x20;
        }
    }
    for (i = 0; i < (s32)(*(f32 *)(st + 0x40) - 1.0f); i++) {
        if (i > 0 && func_L01_003E4168(&pos) == 0
            && func_L01_003FB640(&pos, D_L39_0024B868[*(s32 *)(a0 + 0x94)], *(u8 **)(pls + 0xF0), sp) != 0
            && func_L01_003E7F48(a0, i, &pos, sp) == 0) {
            *(u128_0056CC48 *)&step = *(u128_0056CC48 *)&D_L39_0025F760;
            *(u128_0056CC48 *)&old = *(u128_0056CC48 *)&pos;
            if (func_L01_003E7B80(a0, &pos, i, dist, sp) != 0) {
                ret = 1;
                if (fabs_asm(*(f32 *)(*(u8 **)(pls + 0x134) + 0x100)) > 0.05f) {
                    {
                        vu0_q qa, qb;
                        __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(step));
                        __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(old));
                        __asm__("vsub.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
                        __asm__("sqc2 %1, %0" : "=m"(d) : "j"(qa));
                    }
                    func_0038CF68(&d, &d, 1.0f);
                    if (fabs_asm(func_0038CE68(pl + 0x90, &d)) < 0.75f) {
                        *(s16 *)(st + 0x34) = 0x719;
                        *(f32 *)(st + 0x30) += 0.09f;
                        if (*(f32 *)(cam + 0x2C) - *(f32 *)(st + 0x30) < 0.2f) {
                            *(f32 *)(st + 0x30) = *(f32 *)(cam + 0x2C) - 0.2f;
                        }
                    }
                }
                {
                    vu0_q qa, qb;
                    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(pos));
                    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)(sub + 0x50)));
                    __asm__("vsub.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
                    __asm__("sqc2 %1, %0" : "=m"(d) : "j"(qa));
                }
                func_0038CF68(cam, &d, *(f32 *)(cam + 0x2C) - *(f32 *)(st + 0x30));
                func_0038CF68(&dir, cam, 1.0f);
            }
        }
        sp += *(f32 *)(st + 0x44) * *(f32 *)(st + 0x3C);
        dist += sp;
        func_0038CE20(&step, &dir, sp * ((*(f32 *)(cam + 0x2C) - *(f32 *)(st + 0x30)) / *(f32 *)(cam + 0x2C)));
        {
            vu0_q qa, qb;
            __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(pos));
            __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(step));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qa) : "j"(qa), "j"(qb));
            __asm__("sqc2 %1, %0" : "=m"(pos) : "j"(qa));
        }
    }
    if (D_L39_002412DC == 0x30 || D_L39_002412DC == 0x1C) {
        if (flag) {
            q = &D_L39_0024B868[*(s32 *)(a0 + 0x94)];
            *q &= ~0x20;
        }
    }
    return ret;
}
/* localdecomp:end func_L39_0056CC48 */

/* localdecomp:start func_L39_0056CFF8 */
#include "vu0.h"

typedef int q128_0056CFF8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_0056CFF8;

typedef struct {
    u8 pad0[0x10];
    V_0056CFF8 pos; /* 0x10 */
    u8 *p20;
    struct { u8 pad[0x10]; s32 w10; } *p24; /* 0x24 */
    u8 pad28[0x98 - 0x28];
    s32 w98; /* 0x98 */
    u8 pad9C[0xAA - 0x9C];
    s16 hAA; /* 0xAA */
} M_0056CFF8;

typedef struct {
    u8 pad0[0x50];
    V_0056CFF8 pos; /* 0x50 */
} C_0056CFF8;

typedef struct {
    V_0056CFF8 v; /* 0x00 */
    u8 pad10[0x2C - 0x10];
    f32 f2C; /* 0x2C */
} D_0056CFF8;

typedef struct {
    u8 pad0[0x30];
    f32 f30;
    s16 h34;
    s16 pad36;
    s16 pad38;
    s16 h3A;
    u8 pad3C[0x4C - 0x3C];
    s16 h4C;
    s16 h4E;
} E_0056CFF8;

typedef struct {
    u8 pad0[0x60];
    C_0056CFF8 c;  /* 0x60 */
    u8 padC0[0x180 - 0xC0];
    D_0056CFF8 d;  /* 0x180 */
    u8 pad1B0[0x210 - 0x1B0];
    E_0056CFF8 e;  /* 0x210 */
} B_0056CFF8;

typedef struct {
    u8 pad0[0x30];
    V_0056CFF8 pos; /* 0x30 */
    u8 pad40[0x70 - 0x40];
    B_0056CFF8 *base; /* 0x70 */
    u8 pad74[0x94 - 0x74];
    s32 idx; /* 0x94 */
} S_0056CFF8;

typedef struct {
    u8 pad0[0x80];
    V_0056CFF8 v80; /* 0x80 */
    u8 pad90[0xF0 - 0x90];
    void *pF0; /* 0xF0 */
    u8 padF4[0x100 - 0xF4];
    s32 w100; /* 0x100 */
    u8 pad104[0x11C - 0x104];
    s32 w11C; /* 0x11C */
    u8 pad120[0x134 - 0x120];
    struct { u8 pad[0x100]; f32 f100; f32 f104; } *p134; /* 0x134 */
} R_0056CFF8;

typedef struct {
    u8 pad0[0x20];
    V_0056CFF8 v20; /* 0x80 */
    V_0056CFF8 v30; /* 0x90 */
} T_0056CFF8;

typedef struct {
    u8 pad0[0x54];
    struct { u8 pad[0x86]; s16 h86; } *p54; /* 0x54 */
    u8 pad58[0x60 - 0x58];
    T_0056CFF8 t;   /* 0x60 */
    u8 padA0[0x150 - 0xA0];
    R_0056CFF8 r;   /* 0x150 */
    u8 pad290[0x454 - 0x290];
    s32 w454;       /* 0x454 */
    u8 pad458[0x460 - 0x458];
} P_0056CFF8;

extern u8 D_L39_0024DE80[];
extern s32 D_L39_0024B858[] __attribute__((section(".sdata")));
extern M_0056CFF8 *D_L39_002637C0[];
extern M_0056CFF8 *D_L39_003CE540[];
extern vu0_v4 D_L39_0025F760;
extern f32 D_L39_0024B6A8 __attribute__((section(".sdata")));
extern s32 D_001D7B50_sda;
__asm__(".extern D_L39_0024B6A8, 4");
__asm__(".extern D_001D7B50_sda, 4");

extern void func_0038CDF8(void *, void *, void *, f32);
extern s32 func_003D4D00(void *, s32, void *, void *, f32);
extern void func_L01_003E8F20(s32, f32, f32, f32);
extern s32 func_L01_00446720(char *);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038D0C8(f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038D890(void *, void *, void *, f32);
extern s32 func_L39_0056CC48(u8 *);
extern s32 func_L01_003E7AA0(void *);
extern s32 func_L01_003E77B0(void *);
extern s32 func_0038CB00(void *);
extern f32 func_003C3BE8(f32, f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern s32 func_L01_003E4168(void *);
extern void func_L39_0057B4C0(s32, s32);
extern f32 func_0038CEA8(void *);

void func_L39_0056CFF8(S_0056CFF8 *self) {
    V_0056CFF8 v0;
    V_0056CFF8 v10;
    V_0056CFF8 v20;
    V_0056CFF8 v30;
    V_0056CFF8 v40;
    P_0056CFF8 *p = &((P_0056CFF8 *)D_L39_0024DE80)[self->idx];
    B_0056CFF8 *base = self->base;
    R_0056CFF8 *r = &p->r;
    C_0056CFF8 *c = &base->c;
    E_0056CFF8 *e;
    D_0056CFF8 *d = &base->d;
    T_0056CFF8 *t;
    f32 len;
    s32 flag = 0;
    s32 nsaved = 0;
    s32 n;
    s32 i;
    s32 j;
    f32 x;
    s32 set;
    f32 dist;

    e = &base->e;
    t = &p->t;
    len = d->f2C - e->f30 + 1.5f;

    func_0038CDF8(&v0, &c->pos, p, 0.5f);
    n = func_003D4D00(&v0, 1, r->pF0, 0, len * 0.5f);
    if (n > 0) {
        for (i = 0; i < n; i++) {
            M_0056CFF8 *m = D_L39_002637C0[i];
            if (m->hAA == 0x191F || m->hAA == 0x1920) {
                func_L01_003E8F20(self->idx, -1.0f, -1.0f, D_L39_0024B6A8);
            }
            if (m->w98 != 0 && (!func_L01_00446720((char *)m) || m->hAA == 0xB6B)) {
                if (m->hAA != 0x477 && m->hAA != 0xB && m->hAA != 0x1AD6 && m->hAA != 0x1ADA &&
                    m->hAA != 0x1944 && m->hAA != 0x18DE && m->hAA != 0x1F89 && m->hAA != 0x1CAA &&
                    m->hAA != 0x109E && m->hAA != 0x109F) {
                    D_L39_003CE540[nsaved++] = m;
                    m->w98 = 0;
                } else {
                    vec_sub_ab(&v10, &m->pos, &c->pos);
                    func_0038CE20(&v20, &t->v30, func_0038CE68(&t->v30, &v10));
                    vec_sub_ab(&v30, &v10, &v20);
                    func_0038CF68(&v30, &v30, 1.0f);
                    if (fabs_asm(1.5707964f - func_0038D0C8(func_0038CE68(&v30, d) / (d->f2C - e->f30))) < 0.43633232f) {
                        func_0038CE90(&v40, d, &t->v30);
                        func_0038CF68(&v40, &v40, 1.0f);
                        if (func_0038CE68(&v40, &v10) > 0.0f) {
                            func_0038D890(d, d, &t->v20, -0.017453292f);
                        } else {
                            func_0038D890(d, d, &t->v20, 0.017453292f);
                        }
                    }
                }
            }
        }
    }

    if (e->h4E == 0) {
        if (func_L39_0056CC48((u8 *)self)) {
            flag = 1;
        }
        if (func_L01_003E7AA0(self)) {
            flag = 1;
        }
    }
    if (func_L01_003E77B0(self)) {
        flag = 1;
    }
    x = d->f2C;
    if (x - e->f30 < 1.5f) {
        e->h34 = 0x683;
        e->f30 = x - 1.5f;
    }
    if (p->p54 != 0 && (p->p54->h86 == 4 || p->p54->h86 == 0x51)) {
        if (p->w454 < 8) {
            e->h34 = 0x589;
        }
    }
    if (e->h3A != 0 || (!flag && ((e->h34 > 0 && e->h34 < 0x683) ||
                                 (r->p134->f100 < 0.3f && r->p134->f104 < 0.3f)))) {
        if (func_0038CB00(&e->h34)) {
            e->h3A = 0;
        }
        if (e->h3A != 0) {
            if (func_0038CB00(&e->h34)) {
                e->h3A = 0;
            }
        }
        e->f30 = func_003C3BE8(0.0f, e->f30, (f32)e->h34 / 1667.0f);
    } else {
        if (e->h34 >= 0x684) {
            func_0038CB00(&e->h34);
        } else {
            e->h34 = 0x683;
        }
    }
    func_0038CF68(d, d, d->f2C - e->f30);

    set = 0;
    vec_add_ab(&v10, d, &c->pos);
    if (!(D_L39_0024B858[self->idx] & 0x20)) {
        D_L39_0024B858[self->idx] |= 0x20;
        set = 1;
    }
    if (r->w100 != 0x31 && D_001D7B50_sda == -1 && e->h4E == 0 &&
        func_003D3CB0(&c->pos, &v10, D_L39_0024B858[self->idx], r->pF0, 0) &&
        !func_L01_003E4168(&D_L39_0025F760)) {
        if (++e->h4C >= 25) {
            func_L39_0057B4C0(self->idx, 1);
        }
    } else {
        e->h4C = 0;
    }

    vec_sub_ba(&v30, &self->pos, &v10);
    dist = func_0038CEA8(&v30);
    vec_sub_ab(&v20, &self->pos, &c->pos);
    func_0038CF68(&v20, &v20, 1.0f);
    if ((30.0f < dist && p->w454 >= 9) ||
        (r->w11C > 0 && func_0038CE68(&v20, &r->v80) > 0.0f && dist < 20.0f &&
         func_003D3CB0(&self->pos, &v10, D_L39_0024B858[self->idx], r->pF0, 0))) {
        func_L39_0057B4C0(self->idx, 0);
    }
    if (set) {
        D_L39_0024B858[self->idx] &= ~0x20;
    }
    for (j = 0; j < nsaved; j++) {
        D_L39_003CE540[j]->w98 = D_L39_003CE540[j]->p24->w10;
    }
}
/* localdecomp:end func_L39_0056CFF8 */
