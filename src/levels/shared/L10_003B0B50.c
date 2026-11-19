#include "common.h"

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V4_003B10C8;
typedef struct { u8 pad0[0x12]; s16 count; u8 pad14[0xC]; s32 *ids; u8 pad24[0xC]; } Path_003B10C8;
typedef struct { s32 count; u8 pad4[0x1C]; Path_003B10C8 paths[1]; } Paths_003B10C8;
typedef struct { u8 pad0[0x30]; V4_003B10C8 pos; u8 pad40[0x40]; } Node_003B10C8;

/* localdecomp:start func_L10_003B0B50 */
#include "vu0.h"

typedef struct M_003B0B50 {
    u8 pad0[0x10];
    V4_003B10C8 pos;
    u8 state;
    u8 pad21[0x47];
    struct P_003B0B50 *pv;
} M_003B0B50;
typedef struct Q_003B0B50 {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 wC;
    s32 w10;
} Q_003B0B50;
typedef struct P_003B0B50 {
    u8 pad0[0x3B4];
    s32 w3B4;
    s16 h3B8;
    s16 h3BA;
    M_003B0B50 *m3BC;
    u8 pad3C0[0x10];
    s32 w3D0;
    s32 w3D4;
    M_003B0B50 *m3D8;
    f32 f3DC;
    u8 pad3E0[0x104];
    s32 w4E4;
    u8 pad4E8[0x10];
    f32 f4F8;
    u8 pad4FC[8];
    s32 w504;
    u8 pad508[0x48];
    V4_003B10C8 v550;
} P_003B0B50;
typedef struct { s32 n; u8 pad4[0xC]; V4_003B10C8 pt[1]; } Path_003B0B50;

extern u8 D_001A4BE0[];
extern s32 D_L10_001DEE40;
__asm__(".extern D_L10_001DEE40, 16");
extern s32 D_L10_001DF2D8;
__asm__(".extern D_L10_001DF2D8, 4");
extern u8 *D_L10_001DF29C;
__asm__(".extern D_L10_001DF29C, 16");
extern Node_003B10C8 *D_L10_001DF380;
__asm__(".extern D_L10_001DF380, 16");
extern s16 *D_L10_0021BF20[];
extern Path_003B0B50 *D_L10_0021D1C0[];

extern s32 func_00382380(void *, s32, s32);
extern f32 func_0038CF38(void *, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L10_003A7160(void *);

void func_L10_003B0B50(M_003B0B50 *m)
{
    P_003B0B50 *p = m->pv;
    u8 *g;
    s16 *q;

    if (p->w3D4 > 0)
        return;
    if (m->state == 2) {
        if (D_L10_001DEE40 % 200 == 0)
            p->f4F8 = func_0038D160(p->m3BC->pos.x - m->pos.x, p->m3BC->pos.y - m->pos.y);
        p->v550 = m->pos;
    }
    if (m->state == 9) {
        Path_003B0B50 *pth = D_L10_0021D1C0[p->w504];
        p->v550 = ((V4_003B10C8 *)pth)[p->w4E4 + 1];
        if (func_0038CF38(&p->v550, &m->pos) < 1.0f) {
            if (++p->w4E4 >= pth->n)
                p->w4E4 = 0;
        }
        return;
    }
    g = D_001A4BE0;
    if (*(M_003B0B50 **)(g + 0x1A50) != 0 && (*(M_003B0B50 **)(g + 0x1A50))->state != 0) {
        if (*(M_003B0B50 **)(g + 0x1A50) != p->m3D8) {
            p->f3DC = func_0038CF38(&(*(M_003B0B50 **)(g + 0x1A50))->pos, &m->pos);
            p->w3B4 = 0;
            p->m3D8 = *(M_003B0B50 **)(g + 0x1A50);
        }
        if (fabs_asm(m->pos.z - (*(M_003B0B50 **)(g + 0x1A50))->pos.z) > 10.0f) {
            func_L10_003A7160(*(M_003B0B50 **)(g + 0x1A50));
            *(M_003B0B50 **)(g + 0x1A50) = 0;
            p->m3D8 = 0;
            p->h3BA = 0;
        } else {
            p->h3B8 = 0;
            p->h3BA = 1;
            p->v550.x = func_0038D098(func_0038D160(m->pos.x - (*(M_003B0B50 **)(g + 0x1A50))->pos.x,
                                                    m->pos.y - (*(M_003B0B50 **)(g + 0x1A50))->pos.y)) * 0.5f;
            p->v550.y = func_0038D0B0(func_0038D160(m->pos.x - (*(M_003B0B50 **)(g + 0x1A50))->pos.x,
                                                    m->pos.y - (*(M_003B0B50 **)(g + 0x1A50))->pos.y)) * 0.5f;
            p->v550.z = 0.0f;
            vec_add_ab(&p->v550, &p->v550, &(*(M_003B0B50 **)(g + 0x1A50))->pos);
        }
    } else {
        p->h3BA = 0;
    }
    if (p->h3BA == 0 && func_L01_0040E570(&p->v550, &p->m3BC->pos) > 4.0f) {
        V4_003B10C8 t;
        f32 a = func_0038D160(p->m3BC->pos.x - m->pos.x, p->m3BC->pos.y - m->pos.y);
        t.x = -func_0038D098(a);
        t.y = -func_0038D0B0(a);
        t.z = 0.0f;
        t.w = 1.0f;
        p->h3B8 = 1;
        p->h3BA = 0;
        vec_add_ba(&p->v550, &p->m3BC->pos, &t);
    }
    for (q = D_L10_0021BF20[p->w3D0];
         (p->w3D0 & 0xFF) != 0xFF && p->w3D0 <= D_L10_001DF2D8 && q != 0
         && (q[-1] >= 0 || q == D_L10_0021BF20[p->w3D0]);
         q++) {
        M_003B0B50 *o = (M_003B0B50 *)(D_L10_001DF29C + ((*q & 0x7FFF) << 8));
        Q_003B0B50 *r;
        Node_003B10C8 *e;
        if (o == 0)
            break;
        r = (Q_003B0B50 *)o->pv;
        if (func_00382380(&p->v550, r->w0, 0) == 0)
            continue;
        if (r->w10 > 0 && func_00382380(&m->pos, r->w8, 0) == 0)
            continue;
        if (r->w10 < 0 && func_00382380(&m->pos, r->w8, 0) != 0)
            continue;
        e = (Node_003B10C8 *)((r->w4 << 7) + (s32)D_L10_001DF380);
        if (fabs_asm(e->pos.z - m->pos.z) < 2.5f) {
            p->v550 = e->pos;
            break;
        }
    }
}
/* localdecomp:end func_L10_003B0B50 */

/* localdecomp:start func_L10_003B0F78 */
#include "vu0.h"

extern f32 func_L01_004395E0(void *);
extern void func_003C2F58(void *, s32, void *);
extern f32 func_0038CE68(void *, void *);
extern s32 D_L10_002B97D0[];
extern f32 D_L10_001DE588;
__asm__(".extern D_L10_001DE588, 4");

void func_L10_003B0F78(u8 *m)
{
    u8 *v = *(u8 **)(m + 0x68);
    s32 r = 0;
    s32 n;
    vu0_v4 pos;
    vu0_v4 d;

    n = func_L01_004395E0(m);
    if (m[0x43] == m[0x42]) {
        switch (m[0x42]) {
        case 1:
        case 3:
        case 7:
        case 9:
        case 10:
        case 13:
        case 14:
            r = 2;
            break;
        case 12:
            r = D_L10_002B97D0[n];
            break;
        case 15:
            r = (u32)(n - 5) < 17 ? 0 : 2;
            break;
        }
    }
    if (r == 0) {
        *(s32 *)(v + 0x51C) = 0;
        return;
    }
    func_003C2F58(m, r == 1 ? 1 : 2, &pos);
    vec_sub_ab(&pos, &pos, m + 0x10);
    pos.z += D_L10_001DE588;
    if (*(s32 *)(v + 0x51C) != 0) {
        vec_sub_ab(&d, &pos, v + 0x520);
        *(f32 *)(v + 0x514) = -func_0038CE68(&d, m + 0xC0);
        *(f32 *)(v + 0x518) = pos.z;
        *(vu0_v4 *)(v + 0x520) = pos;
    } else {
        *(f32 *)(v + 0x518) = pos.z;
        *(vu0_v4 *)(v + 0x520) = pos;
        *(s32 *)(v + 0x51C) = 1;
    }
    *(f32 *)(v + 0x518) = 1.23337996f;
}
/* localdecomp:end func_L10_003B0F78 */

/* localdecomp:start func_L10_003B10C8 */
#include "vu0.h"

extern Paths_003B10C8 *D_L10_001DEF4C;
__asm__(".extern D_L10_001DEF4C, 16");
extern Node_003B10C8 *D_L10_001DF380;
__asm__(".extern D_L10_001DF380, 16");
extern f32 func_L01_0040E570(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, void *);
extern int func_00382380(void *, int, int);

s32 func_L10_003B10C8(u8 *m, s32 idx, f32 *out, void *a3, void *a4, s32 flag)
{
    V4_003B10C8 *home = a3;
    s32 *cur = a4;
    Path_003B10C8 *path;
    V4_003B10C8 pos;
    V4_003B10C8 tgt;
    V4_003B10C8 dir;
    f32 d;
    f32 nd;
    f32 lim;
    s32 best;
    s32 i;
    s32 id;
    Node_003B10C8 *e;

    if (idx >= 0 && idx < D_L10_001DEF4C->count) {
    path = &D_L10_001DEF4C->paths[idx];
    pos = *(V4_003B10C8 *)(m + 0x10);
    tgt = *(V4_003B10C8 *)out;
    pos.z += 1.0f;
    tgt.z += 1.0f;
    d = func_L01_0040E570(&pos, &tgt);
    vec_sub_ab(&dir, &tgt, &pos);
    func_0038CE20(&dir, &dir, sqrt_asm(d));
    if (flag == 0 && func_003D3CB0(&pos, &tgt, 0, m, 0) == 0) {
        *cur = -1;
        *home = *(V4_003B10C8 *)out;
        return 1;
    }
    lim = d * 4.0f;
    best = -1;
    for (i = 0; i < path->count; i++) {
        id = path->ids[i];
        e = &D_L10_001DF380[id];
        if (id == *cur)
            continue;
        if (func_00382380(&pos, id, 0) != 0) {
            *cur = path->ids[i];
            continue;
        }
        nd = func_L01_0040E570(&tgt, &e->pos);
        if (lim < nd)
            continue;
        if (func_003D3CB0(&pos, &e->pos, 0, m, 0) != 0)
            continue;
        lim = nd;
        best = i;
    }
    if (best < 0) {
        if (func_L01_0040E570(m + 0x10, home) > 0.040000003f)
            *(V4_003B10C8 *)out = *home;
        else
            return 0;
    } else {
        *(V4_003B10C8 *)out = D_L10_001DF380[path->ids[best]].pos;
    }
    }
    return 1;
}
/* localdecomp:end func_L10_003B10C8 */

LINKER_REMNANT("asm/levels", func_L10_003B1350);
