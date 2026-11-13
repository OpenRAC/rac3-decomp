#include "common.h"

typedef struct Obj_00559980 {
    u8 pad0[0x10];
    u8 *ptr[5];
    u8 pad1[0xE0 - 0x24];
    u8 item[5][0x10];
} Obj_00559980;

/* declared by functions of L39_00557E48.c, which this file was cut from */
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CE68();
typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L39_005591C8 */
#include "vu0.h"

typedef struct { u8 p0[0xF8]; f32 fF8; } H_005591C8;
typedef struct { u8 p0[0x2524]; H_005591C8 *h; } G_005591C8;
typedef struct { u8 p0[0x8]; G_005591C8 *g; } B_005591C8;
typedef struct { u8 p0[0x330]; vu0_v4 v330; u8 p340[0x10]; vu0_v4 v350; } A_005591C8;
typedef struct { u8 p0[0x68]; void *vars; } M_005591C8;

extern f32 D_L39_0024B374;
__asm__(".extern D_L39_0024B374, 4");
extern f32 *D_L39_0024B2F4;
__asm__(".extern D_L39_0024B2F4, 4");
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);

void func_L39_005591C8(M_005591C8 *a0, M_005591C8 *a1)
{
    B_005591C8 *b = a1->vars;
    A_005591C8 *a = a0->vars;
    vu0_v4 v;

    v.x = func_0038D098(b->g->h->fF8) * D_L39_0024B374;
    v.y = func_0038D0B0(b->g->h->fF8) * D_L39_0024B374;
    v.z = 0.0f;
    v.x = -v.x;
    v.y = -v.y;
    func_0038CF68(&v, &v, *D_L39_0024B2F4);
    vec_add_ba(&a->v350, &v, &a->v330);
}
/* localdecomp:end func_L39_005591C8 */

/* localdecomp:start func_L39_00559268 */
#include "vu0.h"

typedef struct S_00559268_A {
    u8 pad0[0xF8];
    f32 angle;
} S_00559268_A;

typedef struct S_00559268_T {
    u8 pad0[0x2D0];
    S_00559268_A *a2D0;
    u8 pad2D4[0x2FC - 0x2D4];
    s16 kind;
} S_00559268_T;

typedef struct S_00559268_E {
    u8 pad0[0x140];
    u8 v140[0x2524 - 0x140];
    S_00559268_A *a2524;
    S_00559268_T *t2528;
} S_00559268_E;

typedef struct S_00559268_S {
    u8 pad0[0x8];
    S_00559268_E *e;
    u8 padC[0x70 - 0xC];
    s32 mode;
    u8 pad74[0x80 - 0x74];
    u8 v80[0x144 - 0x80];
    void *f144;
} S_00559268_S;

typedef struct S_00559268_O {
    u8 pad0[0x340];
    vu0_v4 v340;
    u8 pad350[0x3A0 - 0x350];
    vu0_v4 v3A0;
} S_00559268_O;

typedef struct S_00559268_M {
    u8 pad0[0x68];
    void *p68;
} S_00559268_M;

extern f32 *D_L39_0024B2F4;
__asm__(".extern D_L39_0024B2F4, 4");
extern u8 D_L39_0024B2C8[];
extern u8 D_L39_0024B2E0[];
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038CF68(void *, void *, f32);

void func_L39_00559268(S_00559268_M *a, S_00559268_M *b)
{
    S_00559268_S *s = b->p68;
    S_00559268_O *o = a->p68;
    S_00559268_T *t;
    vu0_v4 v;
    f32 d;

    d = func_0038CF38(s->v80, &o->v3A0);
    if (s->mode == 1 && d < 15.0f) {
        S_00559268_T *t0 = s->e->t2528;
        if (t0 == 0 || t0->kind != 2) {
            return;
        }
    }
    t = s->e->t2528;
    if (t == 0 || t->kind != 2) {
        v.x = func_0038D098(s->e->a2524->angle) * *D_L39_0024B2F4;
        v.y = func_0038D0B0(s->e->a2524->angle) * *D_L39_0024B2F4;
        v.z = 0.0f;
    } else {
        v.x = func_0038D098(t->a2D0->angle) * *D_L39_0024B2F4;
        v.y = func_0038D0B0(s->e->t2528->a2D0->angle) * *D_L39_0024B2F4;
        v.z = 0.0f;
    }
    if (func_0038CE68(&v, s->e->v140) >= 0.0f) {
        s->f144 = D_L39_0024B2C8;
    } else {
        s->f144 = D_L39_0024B2E0;
    }
    v.x = -v.x;
    v.y = -v.y;
    func_0038CF68(&v, &v, *D_L39_0024B2F4);
    vec_add_ab(&o->v3A0, &v, &o->v340);
}
/* localdecomp:end func_L39_00559268 */

/* localdecomp:start func_L39_005593F8 */
typedef struct { u8 p0[0x10]; f32 f10; f32 f14; } T_005593F8;
typedef struct { u8 p0[0x2524]; T_005593F8 *t; } G_005593F8;
typedef struct { u8 p0[8]; G_005593F8 *g; u8 p1[0x68]; f32 f74; u8 p2[8]; f32 f80; f32 f84; } V_005593F8;
typedef struct { u8 p0[0x68]; V_005593F8 *v; } M_005593F8;
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern void func_L39_005594C8(M_005593F8 *);
/* defined later in this file with its own (anonymous) struct pointer type: declared without a prototype */
extern void func_L39_005596F0();
__asm__(".extern D_L39_0024B2F8, 4");
__asm__(".extern D_L39_0024B36C, 4");
__asm__(".extern D_L39_0024B370, 4");
extern f32 D_L39_0024B2F8;
extern f32 D_L39_0024B36C;
extern f32 D_L39_0024B370;

void func_L39_005593F8(M_005593F8 *m) {
    V_005593F8 *v = m->v;
    f32 a;
    f32 deg;

    a = func_0038D160(v->g->t->f10 - v->f80, v->g->t->f14 - v->f84);
    deg = func_0038DBA0(a, v->f74) * 180.0f / 3.14159274f;
    func_L39_005594C8(m);
    func_L39_005596F0(m);
    if (deg > 1.0471976f) {
        D_L39_0024B2F8 = D_L39_0024B370 * D_L39_0024B36C;
    } else {
        D_L39_0024B2F8 = D_L39_0024B370;
    }
    *(u128_t *)&v->f80 = *(u128_t *)((u8 *)v->g->t + 0x10);
}
/* localdecomp:end func_L39_005593F8 */

/* localdecomp:start func_L39_005594C8 */
#include "vu0.h"
typedef struct { u8 p0[0xAA]; s16 id; } O_005594C8;
typedef struct { s32 n; u8 p0[0xC]; O_005594C8 *list[26]; s32 w78; u8 p1[0x14]; vu0_v4 q90; vu0_v4 qA0; } V_005594C8;
typedef struct { u8 p0[0x68]; V_005594C8 *v; } M_005594C8;
extern void func_0038CF68(void *, void *, f32);
extern void func_L39_00557FD0(void *, void *, void *, s32);
void func_L39_005594C8(M_005593F8 *mp) {
    M_005594C8 *m = (M_005594C8 *)mp;
    V_005594C8 *v = m->v;
    s32 n = v->n;
    s32 i;
    vu0_v4 d;
    vu0_v4 tmp;

    if (n < 2) return;
    for (i = 0; i < n; i++) {
        if (v->list[i]->id != 0x109F) return;
    }
    if (v->w78 == 0) return;
    vec_sub_ab(&tmp, &v->q90, &v->qA0);
    d = tmp;
    d.z = 0.0f;
    func_0038CF68(&d, &d, 1.0f);
    func_L39_00557FD0(&d, &v->qA0, v->list, 2);
}
/* localdecomp:end func_L39_005594C8 */

INCLUDE_ASM("asm/levels", func_L39_00559588);
