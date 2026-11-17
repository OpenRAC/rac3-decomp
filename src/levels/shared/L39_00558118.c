#include "common.h"

typedef struct Obj_00559980 {
    u8 pad0[0x10];
    u8 *ptr[5];
    u8 pad1[0xE0 - 0x24];
    u8 item[5][0x10];
} Obj_00559980;

/* declared by functions of L39_00557E48.c, which this file was cut from */
extern f32 func_0038CF00(void *, void *);

/* localdecomp:start func_L39_00558118 */
typedef struct { u8 p0[0x2E4]; f32 w2E4; } S_00558118;
typedef struct { u8 p0[0x10]; f32 x; f32 y; u8 p1[0x50]; S_00558118 *sub; u8 p2[0x3E]; s16 id; } O_00558118;
typedef struct { s32 n; u8 p0[0xC]; O_00558118 *list[1]; } L_00558118;
typedef struct { u8 p0[0x68]; L_00558118 *l; } M_00558118;
extern f32 D_L39_0024B300;
__asm__(".extern D_L39_0024B300, 4");
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_0038CF00(void *, void *);
extern f32 func_0038DAB8(f32, f32);
void func_L39_00558118(M_00558118 *m) {
    L_00558118 *l = m->l;
    s32 n = l->n;
    s32 i;
    f32 d;
    f32 ang;
    f32 a1;
    f32 a2;
    S_00558118 *s;
    if (n < 2) return;
    for (i = 0; i < n; i++) {
        if (l->list[i]->id != 0x109F) return;
    }
    d = func_0038CF00(&l->list[0]->x, &l->list[1]->x);
    if (!(d < D_L39_0024B300)) return;

    ang = func_0038D160(l->list[1]->x - l->list[0]->x, l->list[1]->y - l->list[0]->y);
    s = l->list[0]->sub;
    if (func_0038DBA0(ang, s->w2E4) < 1.5707964f) {
        if (D_L39_0024B300 / 1.5f < d) {
            a1 = func_0038DAB8(ang, 1.5707964f);
            a2 = func_0038DAB8(ang, -1.5707964f);
            if (func_0038DBA0(a1, s->w2E4) > func_0038DBA0(a2, s->w2E4)) s->w2E4 = a2;
            else s->w2E4 = a1;
        } else {
            a1 = func_0038DAB8(ang, 2.0943952f);
            a2 = func_0038DAB8(ang, -2.0943952f);
            if (func_0038DBA0(a1, s->w2E4) > func_0038DBA0(a2, s->w2E4)) s->w2E4 = a2;
            else s->w2E4 = a1;
        }
    }

    ang = func_0038D160(l->list[0]->x - l->list[1]->x, l->list[0]->y - l->list[1]->y);
    s = l->list[1]->sub;
    if (func_0038DBA0(ang, s->w2E4) < 1.5707964f) {
        if (D_L39_0024B300 / 1.5f < d) {
            a1 = func_0038DAB8(ang, 1.5707964f);
            a2 = func_0038DAB8(ang, -1.5707964f);
            if (func_0038DBA0(a1, s->w2E4) > func_0038DBA0(a2, s->w2E4)) s->w2E4 = a2;
            else s->w2E4 = a1;
        } else {
            a1 = func_0038DAB8(ang, 2.0943952f);
            a2 = func_0038DAB8(ang, -2.0943952f);
            if (func_0038DBA0(a1, s->w2E4) > func_0038DBA0(a2, s->w2E4)) s->w2E4 = a2;
            else s->w2E4 = a1;
        }
    }
}
/* localdecomp:end func_L39_00558118 */

/* localdecomp:start func_L39_00558438 */
struct O_00558438;
typedef struct { u8 p0[0x270]; struct O_00558438 *owner; } S_00558438;
typedef struct O_00558438 { u8 p0[0x68]; S_00558438 *sub; u8 p1[0x3E]; s16 id; } O_00558438;
typedef struct { s32 n; u8 p0[0xC]; O_00558438 *list[1]; } L_00558438;
typedef struct { u8 p0[0x68]; L_00558438 *l; } M_00558438;
extern s32 func_L39_00557E18(s32);
s32 func_L39_00558438(M_00558438 *m, s32 a1, O_00558438 *o) {
    s32 id = o->id;
    L_00558438 *l = m->l;
    s32 i;
    if (!func_L39_00557E18(id)) return 0;
    if (id == 0x109D || id == 0x109F || id == 0x109E) {
        for (i = 0; i < l->n; i++) {
            O_00558438 *p = l->list[i];
            if (p == o) return 0;
            if (o->id == 0x109E && p->id == 0x109F && p->sub->owner == o) return 0;
        }
    }
    return 1;
}
/* localdecomp:end func_L39_00558438 */
