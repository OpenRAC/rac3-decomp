#include "common.h"

typedef struct Obj_00559980 {
    u8 pad0[0x10];
    u8 *ptr[5];
    u8 pad1[0xE0 - 0x24];
    u8 item[5][0x10];
} Obj_00559980;

/* localdecomp:start func_L39_00557E48 */
extern u8 *D_L39_0024BF68;
__asm__(".extern D_L39_0024BF68, 16");
extern f32 func_0038CF00(void *, void *);
void *func_L39_00557E48(u8 *pos) {
    u8 *best = 0;
    u8 *o;
    f32 min = 9999.0f;
    f32 d;
    for (o = D_L39_0024BF68; o != 0; o = *(u8 **)(o + 0x28)) {
        if (*(s16 *)(o + 0xAA) == 0x166F) {
            d = func_0038CF00(pos + 0x10, o + 0x10);
            if (d < min) {
                min = d;
                best = o;
            }
        }
    }
    return best;
}
/* localdecomp:end func_L39_00557E48 */

/* localdecomp:start func_L39_00557EF0 */
extern u8 *func_L39_0066B870(s32 a0);
extern u8 *func_L39_0066B8A8(u8 *a0, s32 *a1);
typedef struct { s32 w0; } W_00557EF0;
typedef struct { u8 p0[0x90]; W_00557EF0 *w90; } E_00557EF0;
typedef struct { u8 p0[0x68]; u8 *sub; } B_00557EF0;
typedef struct { u8 p0[0x70]; s32 w70[1]; } BS_00557EF0;
typedef struct { u8 p0[0x2AC]; s32 w2AC; u8 p1[0x4C]; s32 w2FC; u8 p2[0x10]; E_00557EF0 *w310[1]; } V_00557EF0;
typedef struct { u8 p0[0x68]; V_00557EF0 *v; } M_00557EF0;
typedef struct { u8 p0[0x68]; BS_00557EF0 *s; } Best_00557EF0;
void func_L39_00557EF0(M_00557EF0 *m, s32 a1) {
    V_00557EF0 *v = m->v;
    Best_00557EF0 *best;
    u8 *it;
    u8 *r;
    E_00557EF0 *e;
    s32 i;
    s32 k = 0;
    v->w2FC = 0;
    best = func_L39_00557E48((u8 *)m);
    it = func_L39_0066B870(v->w2AC);
    for (i = 0; (r = func_L39_0066B8A8(it, &i)) != 0 && (e = *(E_00557EF0 **)(r + 0x1C)) != 0; i++) {
        v->w310[v->w2FC] = e;
        if (best != 0 && a1 == 0) {
            best->s->w70[k++] = e->w90->w0;
        }
        v->w2FC++;
    }
}
/* localdecomp:end func_L39_00557EF0 */

INCLUDE_ASM("asm/levels", func_L39_00557FD0);

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

INCLUDE_ASM("asm/levels", func_L39_00558508);

INCLUDE_ASM("asm/levels", func_L39_005585B0);

INCLUDE_ASM("asm/levels", func_L39_005587D0);

/* localdecomp:start func_L39_005589F0 */
typedef struct { u8 pad[612]; s32 w612; } Sub_00557F78;
typedef struct { u8 pad0[104]; Sub_00557F78 *sub; u8 pad1[62]; s16 h170; } Obj_00557F78;
typedef struct { s32 n; s32 pad[3]; Obj_00557F78 *list[1]; } Tbl_00557F78;
typedef struct { u8 pad[104]; Tbl_00557F78 *tbl; } Moby_00557F78;
Obj_00557F78 *func_L39_005589F0(Moby_00557F78 *m, s32 a1) {
    Tbl_00557F78 *t = m->tbl;
    s32 i;
    for (i = 0; i < t->n; i++) {
        Obj_00557F78 *o = t->list[i];
        if (o->h170 == a1 && a1 == 4253 && o->sub->w612 == 1337) return o;
    }
    return 0;
}
/* localdecomp:end func_L39_005589F0 */

INCLUDE_ASM("asm/levels", func_L39_00558A58);

/* localdecomp:start func_L39_00558CA0 */
typedef struct { s32 n; u8 p0[0xC]; void *list[8]; } Out_00558CA0;
extern f32 D_L39_0024B308;
__asm__(".extern D_L39_0024B308, 4");
extern void *D_L39_002637C0[];
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
void func_L39_00558CA0(u8 *obj, Out_00558CA0 *out, void *m) {
    s32 n;
    s32 i;
    n = func_003D4D00(obj + 0x10, 0, obj, 0, D_L39_0024B308);
    out->n = 0;
    for (i = 0; i < n; i++) {
        if (func_L39_00558438(m, (s32)obj, D_L39_002637C0[i])) {
            out->list[out->n] = D_L39_002637C0[i];
            if (++out->n >= 8) break;
        }
    }
}
/* localdecomp:end func_L39_00558CA0 */

/* localdecomp:start func_L39_00558D80 */
extern f32 func_0038CE68();

s32 func_L39_00558D80(void) {
    if (func_0038CE68() < 0.0f) {
        return 1;
    }
    return -1;
}
/* localdecomp:end func_L39_00558D80 */

INCLUDE_ASM("asm/levels", func_L39_00558DB8);

/* localdecomp:start func_L39_00558E68 */
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_L39_004997E0[];
typedef struct { u8 p0[0x14B8]; f32 f14B8; u8 p1[0x19E4 - 0x14BC]; u8 b19E4; u8 p2[0x2524 - 0x19E5]; u8 *w2524; } G_00558E68;
typedef struct { u8 p0[8]; G_00558E68 *g; s32 wC; u8 p1[0x40]; u8 q50[8]; f32 f58; f32 f5C; u8 q60[8]; f32 f68; } S_00558E68;
typedef struct { u8 p0[0x68]; S_00558E68 *s; } M_00558E68;
typedef union { u8 b[8]; u32 w[2]; } Buf_00558E68;
s32 func_L39_00558E68(M_00558E68 *m) {
    S_00558E68 *s = m->s;
    Buf_00558E68 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 mm;
    s32 i;
    u8 *d;
    u8 *q;
    u32 r;
    u32 a2;
    u32 b2;
    s32 n2;
    s32 k2;
    s32 mm2;
    s32 i2;
    u8 *d2;
    u8 *q2;
    u32 r2;

    q = &s->g->b19E4;
    if (*q == 0) {
        r = 0;
    } else {
        n = *q;
        k = ((u32)q - n) & 7;
        mm = n + 1;
        d = buf.b;
        for (i = 0; i < 40; i += 5) {
            *d++ = D_L39_004997E0[mm + ((k + i) & 7) * 255];
        }
        a = buf.w[0] ^ (u32)q;
        b = buf.w[1] ^ a;
        buf.w[0] = a;
        buf.w[1] = b;
        r = b;
    }
    if ((r ^ 7) == 0 && s->g->f14B8 > 6.0f) {
        if (s->wC == 0) {
            *(u128_t *)s->q50 = *(u128_t *)(s->g->w2524 + 0x10);
            s->wC = 1;
        }
    }
    if (s->wC != 0) {
        q2 = &s->g->b19E4;
        if (*q2 == 0) {
            r2 = 0;
        } else {
            n2 = *q2;
            k2 = ((u32)q2 - n2) & 7;
            mm2 = n2 + 1;
            d2 = buf.b;
            for (i2 = 0; i2 < 40; i2 += 5) {
                *d2++ = D_L39_004997E0[mm2 + ((k2 + i2) & 7) * 255];
            }
            a2 = buf.w[0] ^ (u32)q2;
            b2 = buf.w[1] ^ a2;
            buf.w[0] = a2;
            buf.w[1] = b2;
            r2 = b2;
        }
        if ((r2 ^ 7) != 0) {
            s->wC = 0;
            *(u128_t *)s->q60 = *(u128_t *)(s->g->w2524 + 0x10);
            if (s->f68 - s->f58 > 6.0f) {
                return 1;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_L39_00558E68 */

/* localdecomp:start func_L39_00559018 */
extern u8 D_L39_004997E0[];
typedef struct { u8 p0[8]; u8 *g; u8 p1[0x70]; f32 f7C; } S_00559018;
typedef struct { u8 p0[0x68]; S_00559018 *s; } M_00559018;
typedef union { u8 b[8]; u32 w[2]; } Buf_00559018;
void func_L39_00559018(M_00559018 *m) {
    S_00559018 *s = m->s;
    Buf_00559018 buf;
    u32 a;
    u32 b;
    s32 n;
    s32 k;
    s32 mm;
    s32 i;
    u8 *d;
    u8 *q;
    u8 *q2;
    s32 n2;
    s32 k2;
    s32 mm2;
    s32 i2;
    u8 *d2;
    u32 a2;
    u32 b2;
    u32 r2;
    u32 r;
    f32 x;
    f32 c;
    u8 c1;

    q = s->g + 0x19E6;
    if (*q == 0) {
        r = 0;
    } else {
        n = *q;
        k = ((u32)q - n) & 7;
        mm = n + 1;
        d = buf.b;
        for (i = 0; i < 40; i += 5) {
            *d++ = D_L39_004997E0[mm + ((k + i) & 7) * 255];
        }
        a = buf.w[0] ^ (u32)q;
        b = buf.w[1] ^ a;
        buf.w[0] = a;
        buf.w[1] = b;
        r = b;
    }
    c1 = (r ^ 4) != 0;
    if (!c1) {
        q2 = s->g + 0x19E4;
        if (*q2 == 0) {
            r2 = 0;
        } else {
            n2 = *q2;
            k2 = ((u32)q2 - n2) & 7;
            mm2 = n2 + 1;
            d2 = buf.b;
            for (i2 = 0; i2 < 40; i2 += 5) {
                *d2++ = D_L39_004997E0[mm2 + ((k2 + i2) & 7) * 255];
            }
            a2 = buf.w[0] ^ (u32)q2;
            b2 = buf.w[1] ^ a2;
            buf.w[0] = a2;
            buf.w[1] = b2;
            r2 = b2;
        }
        c1 = (r2 ^ 0x83) == 0;
    }
    if (c1) {
        s->f7C = *(f32 *)(*(u8 **)(s->g + 0x2524) + 0x18);
    } else {
        if (*(f32 *)(s->g + 0x14B8) > 6.5f) {
            s->f7C = *(f32 *)(*(u8 **)(s->g + 0x2524) + 0x18);
        } else {
            x = *(f32 *)(s->g + 0x2A8);
            c = s->f7C;
            if (__builtin_fabsf(x - c) < 0.5f) {
            } else if (c - x > 10.0f) {
                s->f7C = *(f32 *)(*(u8 **)(s->g + 0x2524) + 0x18);
            } else {
                s->f7C = x;
            }
        }
    }
}
/* localdecomp:end func_L39_00559018 */

INCLUDE_ASM("asm/levels", func_L39_005591C8);

INCLUDE_ASM("asm/levels", func_L39_00559268);

INCLUDE_ASM("asm/levels", func_L39_005593F8);

INCLUDE_ASM("asm/levels", func_L39_005594C8);

INCLUDE_ASM("asm/levels", func_L39_00559588);

/* localdecomp:start func_L39_005596B0 */
typedef struct { u8 p0[0x14C]; u8 f14C; u8 p1; s16 f14E; } V_005596B0;
typedef struct { u8 p0[0x68]; V_005596B0 *v; } M_005596B0;
void func_L39_005596B0(M_005596B0 *m) {
    V_005596B0 *v = m->v;
    if (v->f14C == 1) {
        v->f14E++;
        if (v->f14E >= 0xFB) {
            v->f14C = 0;
            v->f14E = 0;
        }
    }
}
/* localdecomp:end func_L39_005596B0 */

/* localdecomp:start func_L39_005596F0 */
typedef struct { s32 w0; u8 p0[0x74]; s32 w78; u8 p1[0xC4]; s32 w140; } V_558C78;
typedef struct { u8 p0[0x68]; V_558C78 *v; } M_558C78;
extern void func_L39_00559588(M_558C78 *);
void func_L39_005596F0(M_558C78 *m) {
    V_558C78 *v = m->v;
    s32 s;
    if (v->w78 != 0) {
        s = v->w0;
        if (s == 5 || v->w140 == 1) {
            if (s != 0) {
                func_L39_00559588(m);
            }
        }
    }
}
/* localdecomp:end func_L39_005596F0 */

INCLUDE_ASM("asm/levels", func_L39_00559740);
