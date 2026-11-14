#include "vu0.h"
#include "common.h"

typedef struct {
    s32 key;
    f32 val;
} E_00353160;
typedef struct {
    u8 pad0[0x274];
    s32 n;
    u8 pad1[0x280 - 0x278];
    E_00353160 e[1];
} O_00353160;

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L06_00351930 */
extern void func_003C3A10(u8 *, s32, s32, s32);
void func_L06_00351930(u8 *a0, u8 *a1, s32 a2, s32 a3, s32 a4) {
    if (a0[67] != a2) {
        func_003C3A10(a0, a2, a3, a4);
        func_003C3A10(*(u8 **)(a1 + 608), a2, a3, a4);
    }
}
/* localdecomp:end func_L06_00351930 */

/* localdecomp:start func_L06_003519A0 */
extern void func_003C3A10(u8 *, s32, s32, s32);
void func_L06_003519A0(u8 *a0, s32 a1, s32 a2, s32 a3, s32 a4) {
    if (a0[67] != a2) {
        func_003C3A10(a0, a2, a3, a4);
    }
}
/* localdecomp:end func_L06_003519A0 */

/* localdecomp:start func_L06_003519D0 */
extern void func_003C3A10(u8 *o, s32 a, s32 b, s32 c);

void func_L06_003519D0(s32 unused, u8 *b, s32 x, s32 y, s32 z) {
    u8 *o = *(u8 **)(b + 608);
    if (o[67] != x) {
        func_003C3A10(o, x, y, z);
    }
}
/* localdecomp:end func_L06_003519D0 */

/* localdecomp:start func_L06_00351A08 */
extern void func_003C3A10(u8 *o, s32 a, s32 b, s32 c);
typedef struct { u8 pad[0x10]; u8 x10; } M_350D10;
typedef struct { u8 pad[0x48]; M_350D10 *x48[1]; } L_350D10;
typedef struct { u8 pad[0x24]; L_350D10 *x24; u8 pad28[0x41 - 0x28]; u8 x41; u8 x42; u8 x43; } A_350D10;
typedef struct { u8 pad[0x260]; A_350D10 *x260; } B_350D10;
void func_L06_00351A08(A_350D10 *a, B_350D10 *b, s32 c) {
    A_350D10 *t = b->x260;
    s32 idx = t->x43;
    if (a->x43 != idx) {
        ((void (*)(A_350D10 *, s32, s32, s32))func_003C3A10)(a, idx, (t->x41 + c / 10) % a->x24->x48[idx]->x10, c);
    }
}
/* localdecomp:end func_L06_00351A08 */

INCLUDE_ASM("asm/levels", func_L06_00351A68);

/* localdecomp:start func_L06_00351BB8 */
extern s32 D_L06_001E8458[];
extern void func_003C2F58(u8 *a, s32 b, f32 *out);
extern s32 func_003D3CB0(void *a, void *b, s32 c, u8 *d, s32 e);

s32 func_L06_00351BB8(u8 *a0, u8 *obj) {
    f32 v[4];
    s32 d;
    if (*(s16 *)(obj + 0x23C) != 0) {
        func_003C2F58(*(u8 **)(obj + 0x260), 4, v);
        if (func_003D3CB0(v, obj + 0x220, 0, a0, 0) == 0) {
            return 1;
        }
        d = D_L06_001E8458[0];
        if (d == 0) {
            return 0;
        }
        return d == *(s32 *)(obj + 0x230);
    }
    return 0;
}
/* localdecomp:end func_L06_00351BB8 */

INCLUDE_ASM("asm/levels", func_L06_00351C48);

INCLUDE_ASM("asm/levels", func_L06_00352110);

/* localdecomp:start func_L06_00352370 */
extern s32 func_00382498(s32, s32);

void func_L06_00352370(void *self, u8 *obj) {
    s32 v;
    *(s32 *)(obj + 896) = -1;
    v = func_00382498(4, 6) * 2;
    *(s32 *)(obj + 860) = v;
    *(s32 *)(obj + 908) = v;
}
/* localdecomp:end func_L06_00352370 */

/* localdecomp:start func_L06_003523B0 */
extern s32 func_00382498(s32, s32);
void func_L06_003523B0(s32 a0, char *a1) {
    *(s32 *)(a1 + 904) = func_00382498(90, 120);
}
/* localdecomp:end func_L06_003523B0 */

/* localdecomp:start func_L06_003523E0 */
void func_L06_003523E0(s32 arg0, void *arg1) {
    *(s32 *)((u8 *)arg1 + 0x388) = 0x14;
}
/* localdecomp:end func_L06_003523E0 */

/* localdecomp:start func_L06_003523F0 */
s32 func_L06_003523F0(s32 a0, u8 *a1) {
    s32 r = 0;
    if (*(s32 *)(a1 + 904) <= 0) {
        r = *(s32 *)(a1 + 860) < 1;
    }
    return r;
}
/* localdecomp:end func_L06_003523F0 */

INCLUDE_ASM("asm/levels", func_L06_00352410);

INCLUDE_ASM("asm/levels", func_L06_00352500);

/* localdecomp:start func_L06_003525E0 */
extern s32 func_00382498(s32, s32);
void func_L06_003525E0(u8 *a0, u8 *a1) {
    *(s32 *)(a1 + 0x380) = -1;
    if (a0[0x94] == 0x18) {
        *(s32 *)(a1 + 0x35C) = func_00382498(8, 10) * 2;
    } else {
        *(s32 *)(a1 + 0x35C) = func_00382498(4, 4) * 2;
    }
    *(s32 *)(a1 + 0x330) = 0x14;
    *(s32 *)(a1 + 0x38C) = *(s32 *)(a1 + 0x35C);
}
/* localdecomp:end func_L06_003525E0 */

INCLUDE_ASM("asm/levels", func_L06_00352648);

/* localdecomp:start func_L06_00352810 */
typedef struct {
    u8 pad0[148];
    u8 unk94;
} P351B10;

typedef struct {
    u8 pad0[816];
    s32 unk330;
    u8 pad334[860 - 820];
    s32 unk35C;
    u8 pad360[896 - 864];
    s32 unk380;
} O351B10;

extern s32 func_0038CAD0(s32 *);
extern void func_L06_00352648(P351B10 *, O351B10 *, s32);

s32 func_L06_00352810(P351B10 *p, O351B10 *o) {
    if (o->unk35C != 0) {
        if (func_0038CAD0(&o->unk330) == 0) {
            return 0;
        }
        if (o->unk380 == 0) {
            func_L06_00352648(p, o, 1);
            o->unk380 = 1;
        } else {
            func_L06_00352648(p, o, 0);
            o->unk380 = 0;
        }
        if (p->unk94 == 24) {
            o->unk330 = 12;
        } else {
            o->unk330 = 20;
        }
        o->unk35C--;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_00352810 */

INCLUDE_ASM("asm/levels", func_L06_003528B8);

INCLUDE_ASM("asm/levels", func_L06_00352AA0);

/* localdecomp:start func_L06_00352CA0 */
extern void func_0038CDF8(void *, void *, void *, f32);
extern s32 func_L01_003FB640(void *, f32, s32, u8 *);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern s32 func_003D4D00(void *, f32, s32, void *, void *);
extern void func_0038CF68(void *, void *, f32);
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00352CA0;
typedef struct {
    V_00352CA0 dir;
    u8 pad10[8];
    u8 b18;
    u8 pad19;
    u16 h1A;
    u8 pad1C[4];
    s32 flags;
    u8 pad24[0x30 - 0x24];
} D_00352CA0;
typedef struct { u8 pad[0x18]; u8 *target; } G_00352CA0;
extern G_00352CA0 D_L06_001E8440;
void func_L06_00352CA0(u8 *a0, u8 *a1) {
    V_00352CA0 l;
    V_00352CA0 r;
    V_00352CA0 mid;
    V_00352CA0 p;
    D_00352CA0 d;
    G_00352CA0 *g;
    func_L06_00351628((s32)a0, a1, &l, &r);
    func_0038CDF8(&mid, &l, &r, 0.5f);
    p = mid;
    p.z = *(f32 *)(a0 + 0x18) + 0.3f;
    if (func_L01_003FB640(&p, 3.0f, 1, a0)) {
        g = &D_L06_001E8440;
        if (g->target != 0 && g->target != a0) {
            func_L01_00446760(&d, a0, 0x10001, a1 + 0x110, 1.0f);
            d.b18 = 2;
            d.h1A = *(u16 *)(a0 + 0xAA);
            vec_sub_ba(&d.dir, g->target + 0x10, a0 + 0x10);
            d.dir.z = 0.0f;
            func_0038CF68(&d.dir, &d.dir, 4.0000005f);
            d.dir.w = 5627.925f;
            d.flags |= 1;
            func_003D4D00(&p, 3.0f, 0, a0, &d);
        }
    }
}
/* localdecomp:end func_L06_00352CA0 */

/* localdecomp:start func_L06_00352E08 */
void func_L06_00352E08(s32 a0, u8 *a1) {
    *(s32 *)(a1 + 0x380) = -1;
    *(s32 *)(a1 + 0x35C) = -1;
    *(s32 *)(a1 + 0x38C) = -1;
}
/* localdecomp:end func_L06_00352E08 */

INCLUDE_ASM("asm/levels", func_L06_00352E20);

INCLUDE_ASM("asm/levels", func_L06_00352FB0);

/* localdecomp:start func_L06_00353160 */
f32 func_L06_00353160(u8 *a0, s32 a1) {
    O_00353160 *o = (O_00353160 *)a0;
    s32 n = o->n;
    s32 k;
    s32 i;
    if (n == 0) {
        return 0.0f;
    }
    if (a1 < o->e[0].key) {
        return 0.0f;
    }
    for (k = a1; k >= 0; k--) {
        for (i = n - 1; i >= 0; i--) {
            if (o->e[i].key == k) {
                break;
            }
        }
        if (i >= 0) {
            return o->e[i].val;
        }
    }
    return 0.0f;
}
/* localdecomp:end func_L06_00353160 */

/* localdecomp:start func_L06_00353208 */
void func_L06_00353208(s32 a0, u8 *obj, f32 v) {
    *(f32 *)(obj + 844) = v;
}
/* localdecomp:end func_L06_00353208 */

/* localdecomp:start func_L06_00353210 */
extern void func_0038CF68(void *, void *, f32);
void func_L06_00353210(u8 *d, s32 *p, s32 i) {
    if (i < p[0] - 1) {
        vec_sub_ab(d, (u8 *)p + i * 16 + 0x20, (u8 *)p + i * 16 + 0x10);
    } else {
        vec_sub_ab(d, (u8 *)p + i * 16 + 0x10, (u8 *)p + i * 16);
    }
    ((void (*)(void *, void *))func_0038CF68)(d, d);
    vec_add_ab(d, d, (u8 *)p + i * 16 + 0x10);
}
/* localdecomp:end func_L06_00353210 */

/* localdecomp:start func_L06_003532B8 */
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CDF8(void *, void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
typedef struct { s32 n; u8 pad[0xC]; vu0_v4 e[1]; } P_003532B8;
void func_L06_003532B8(void *py, void *pp, s32 i, s32 k, f32 d, void *out) {
    u8 *y = py;
    P_003532B8 *p = pp;
    vu0_v4 a;
    vu0_v4 b;
    vu0_v4 m;
    vu0_v4 r;
    if (i == 0 && *(s32 *)(y + 0x340) == 0) {
        vec_sub_ab(&m, &p->e[1], &p->e[0]);
        m.z = 0.0f;
    } else if (i == p->n - 1 && *(s32 *)(y + 0x340) == 0) {
        vec_sub_ab(&m, &p->e[i], &p->e[i - 1]);
        m.z = 0.0f;
    } else {
        vec_sub_ab(&a, &p->e[i], &p->e[(i + p->n - 1) % p->n]);
        a.z = 0.0f;
        func_0038CF68(&a, &a, 1.0f);
        vec_sub_ba(&b, &p->e[(i + 1) % p->n], &p->e[i]);
        b.z = 0.0f;
        func_0038CF68(&b, &b, 1.0f);
        func_0038CDF8(&m, &a, &b, 0.5f);
    }
    func_0038CE90(&r, (void *)k, &m);
    func_0038CF68(out, &r, d);
    vec_add_ab(out, out, &p->e[i]);
}
/* localdecomp:end func_L06_003532B8 */

/* localdecomp:start func_L06_00353480 */
extern void func_L06_003532B8(void *, void *, s32, s32, f32, void *);
extern void func_0038CDF8(void *, void *, void *, f32);
typedef struct { u8 pad[0xC]; f32 f; } __attribute__((aligned(16))) E_00353480;
typedef struct { s32 n; u8 pad[0xC]; E_00353480 e[1]; } P_00353480;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00353480;
void func_L06_00353480(u8 *y, P_00353480 *p, s32 i, f32 t, f32 d, s32 k, void *out) {
    V_00353480 a;
    V_00353480 b;
    s32 lo;
    s32 hi;
    if (i == p->n - 1) {
        if (*(s32 *)(y + 0x340) != 0) {
            lo = i;
            hi = (i + 1) % p->n;
        } else if (0.0001f < t) {
            lo = p->n - 2;
            hi = i;
            t += p->e[lo].f;
        } else {
            lo = i;
            t = 0.0f;
            hi = lo;
        }
    } else {
        lo = i;
        hi = lo + 1;
    }
    if (0.0001f < t) {
        func_L06_003532B8(y, p, lo, k, d, &a);
        func_L06_003532B8(y, p, hi, k, d, &b);
        func_0038CDF8(out, &a, &b, t / p->e[lo].f);
    } else {
        func_L06_003532B8(y, p, lo, k, d, out);
    }
}
/* localdecomp:end func_L06_00353480 */

INCLUDE_ASM("asm/levels", func_L06_00353610);

INCLUDE_ASM("asm/levels", func_L06_003536C0);

/* localdecomp:start func_L06_00353AC8 */
extern f32 func_0038CEA8(void *);
s32 func_L06_00353AC8(void *a0, void *a1, f32 lo, f32 hi) {
    vu0_v4 t;
    f32 len;
    vec_sub_ab(&t, a0, a1);
    len = func_0038CEA8(&t);
    if (len < lo + 0.01f) {
        func_0038CF68(&t, &t, lo + 0.01f);
    } else if (hi - 0.01f < len) {
        func_0038CF68(&t, &t, hi - 0.01f);
    } else {
        return 0;
    }
    vec_add_ab(a0, a1, &t);
    return 1;
}
/* localdecomp:end func_L06_00353AC8 */

/* localdecomp:start func_L06_00353B90 */
extern void func_L06_00353210(u8 *, s32 *, s32);
extern f32 func_0038CF38(void *, void *);
extern void func_L06_00353480(void *, void *, s32, f32, f32, s32, void *);
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00353B90;
s32 func_L06_00353B90(u8 **a0, void *a1, s32 *a2, f32 *a3) {
    V_00353B90 tmp;
    s32 *p = *(s32 **)(*(u8 **)(*a0 + 4) + 0x358);
    f32 d;
    f32 lim;
    s32 r;
    ((void (*)(void *, void *, s32, f32))func_L06_00353210)(&tmp, p, *a2, *a3);
    d = func_0038CF38(a1, &tmp);
    lim = *(f32 *)(*(u8 **)(*a0 + 4) + 0x304);
    r = 0;
    if (lim < d) {
        d = lim;
        r = 1;
    }
    if (*a2 == p[0] - 1 && 0.0f < *a3) {
        *a3 = 0.0f;
        r = 1;
    } else if (*a2 == 0 && *a3 < 0.0f) {
        *a3 = 0.0f;
        r = 1;
    }
    if (r) {
        func_L06_00353480(*(void **)(*a0 + 4), p, *a2, *a3, d, *(s32 *)(a0 + 5), a1);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_00353B90 */

INCLUDE_ASM("asm/levels", func_L06_00353CB8);

/* localdecomp:start func_L06_00354118 */
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CF00(void *, void *);
typedef struct { u8 pad[0x358]; u8 *pts; } M_00354118;
typedef struct { u8 pad[4]; M_00354118 *m; vu0_v4 *to; s32 idx; vu0_v4 *from; u8 pad2[8]; f32 len; } A_00354118;
typedef struct { vu0_v4 *pos; s32 *idx; f32 *out; } B_00354118;
void func_L06_00354118(void *pa, s32 pb) {
    A_00354118 *a = pa;
    B_00354118 *b = (B_00354118 *)pb;
    vu0_v4 t;
    vu0_v4 *base = (vu0_v4 *)a->m->pts;
    vec_sub_ab(&t, a->to, a->from);
    func_0038CF68(b->pos, &t, a->len);
    vec_add_ab(b->pos, b->pos, a->from);
    *b->idx = a->idx;
    *b->out = func_0038CF00(&base[a->idx + 1], b->pos);
}
/* localdecomp:end func_L06_00354118 */

/* localdecomp:start func_L06_003541C8 */
typedef struct {
    u8 pad0[832];
    s32 unk340;
    u8 pad344[856 - 836];
    s32 *unk358;
} O3534C8;

typedef struct {
    s32 unk0;
    O3534C8 *unk4;
    s32 unk8;
    s32 unkC;
} S3534C8;

typedef struct {
    u8 pad0[16];
    s32 unk10;
    f32 unk14;
} T3534C8;

extern void func_L06_00354118(void *, s32);

s32 func_L06_003541C8(s32 flags, S3534C8 *s, s32 arg, T3534C8 *a, T3534C8 *b, f32 f) {
    if (flags == 0) {
        func_L06_00354118(s, arg);
        return 0;
    }
    if (s->unk4->unk340 != 0) {
        if ((flags ^ 1) & 1) {
            a->unk10 = s->unkC;
            a->unk14 = f;
        }
        if (!(flags & 2)) {
            b->unk10 = s->unkC;
            b->unk14 = f;
        }
    } else {
        if ((flags ^ 1) & 1) {
            a->unk10 = 0;
            a->unk14 = 0.0f;
        }
        if (!(flags & 2)) {
            b->unk10 = s->unk4->unk358[0] - 1;
            b->unk14 = 0.0f;
        }
    }
    return 1;
}
/* localdecomp:end func_L06_003541C8 */

INCLUDE_ASM("asm/levels", func_L06_00354270);

INCLUDE_ASM("asm/levels", func_L06_00354828);

/* localdecomp:start func_L06_00354A40 */
extern void func_L06_00351628(s32, u8 *, void *, void *);
extern void func_L01_0046E078(s32, void *, void *, void *, s32);
extern void func_L06_00354828(u8 *, u8 *, void *, s32);
__asm__(".extern D_L06_001DD2F8, 4");
extern u8 D_L06_001DD2F8;

void func_L06_00354A40(u8 *a0, u8 *a1) {
    u128_t t[3];
    t[2] = *(u128_t *)(a1 + 0x110);
    ((float *)&t[2])[2] += -0.36f;
    func_L06_00351628((s32)a0, a1, &t[0], &t[1]);
    func_L01_0046E078(0, &t[0], &t[2], &D_L06_001DD2F8, 1);
    func_L01_0046E078(0, &t[1], &t[2], &D_L06_001DD2F8, 1);
    func_L06_00354828(a0, a1, &t[0], 1);
    func_L06_00354828(a0, a1, &t[1], 1);
}
/* localdecomp:end func_L06_00354A40 */

/* localdecomp:start func_L06_00354B08 */
extern void func_L06_00352CA0(u8 *, u8 *);
extern s32 D_L06_001DD308;
__asm__(".extern D_L06_001DD308, 4");
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00354B08;
void func_L06_00354B08(u8 *a0, u8 *a1) {
    V_00354B08 l;
    V_00354B08 r;
    V_00354B08 t;
    func_L06_00352CA0(a0, a1);
    func_L06_00351628((s32)a0, a1, &l, &r);
    t = *(V_00354B08 *)(a1 + 0x110);
    t.z += -0.36f;
    func_L01_0046E078(0, &l, &t, &D_L06_001DD308, 1);
    func_L01_0046E078(0, &r, &t, &D_L06_001DD308, 1);
    t.z += -0.09f;
    func_L01_0046E078(0, &l, &t, &D_L06_001DD308, 1);
    func_L01_0046E078(0, &r, &t, &D_L06_001DD308, 1);
    func_L06_00354828(a0, a1, &l, 20);
    func_L06_00354828(a0, a1, &r, 20);
}
/* localdecomp:end func_L06_00354B08 */

/* localdecomp:start func_L06_00354C28 */
extern s32 D_L06_001DD308;
__asm__(".extern D_L06_001DD308, 4");
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00354C28;
void func_L06_00354C28(u8 *a0, u8 *a1) {
    V_00354C28 l;
    V_00354C28 r;
    V_00354C28 t;
    func_L06_00352CA0(a0, a1);
    func_L06_00351628((s32)a0, a1, &l, &r);
    t = *(V_00354C28 *)(a1 + 0x110);
    t.z += -0.36f;
    func_L01_0046E078(0, &l, &t, &D_L06_001DD308, 1);
    func_L01_0046E078(0, &r, &t, &D_L06_001DD308, 1);
    t.z += -0.09f;
    func_L01_0046E078(0, &l, &t, &D_L06_001DD308, 1);
    func_L01_0046E078(0, &r, &t, &D_L06_001DD308, 1);
    func_L06_00354828(a0, a1, &l, 20);
    func_L06_00354828(a0, a1, &r, 20);
}
/* localdecomp:end func_L06_00354C28 */

/* localdecomp:start func_L06_00354D48 */
extern void func_L06_00354A40(u8 *a0, u8 *a1);
extern void func_L06_00354C28(u8 *a0, u8 *a1);
extern void func_L06_00354B08(u8 *a0, u8 *a1);

void func_L06_00354D48(u8 *a0, u8 *a1) {
    if (*(s32 *)(a1 + 864) != 0) {
        if (a0[67] == 7) {
            func_L06_00354A40(a0, a1);
        } else {
            func_L06_00354C28(a0, a1);
            *(s32 *)(a1 + 864) = 0;
        }
    } else if (a0[67] == 7) {
        func_L06_00354B08(a0, a1);
        *(s32 *)(a1 + 864) = 1;
    }
}
/* localdecomp:end func_L06_00354D48 */

/* localdecomp:start func_L06_00354DC0 */
extern void func_L06_00351930(u8 *a0, u8 *a1, s32 a2, s32 a3, s32 a4);
extern s32 func_L06_00351390(u8 *a0, s32 a1);
extern void func_L01_004450F0(u8 *a0, s32 a1, s32 a2);
s32 func_L06_00354DC0(u8 *a0) {
    s32 s1 = *(s32 *)(a0 + 104);
    if (func_L06_00351390(a0, s1) != 0 || a0[32] == 2) {
        func_L01_004450F0(a0, 1, 1);
        ((void (*)(u8 *a0, s32 a1, s32 a2, s32 a3, s32 t0))func_L06_00351930)(a0, s1, 1, 0, 10);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L06_00354DC0 */

/* localdecomp:start func_L06_00354E38 */
s32 func_L06_00354E38(u8 *a0) {
    u8 *v = *(u8 **)(a0 + 0x68);
    if (a0[0x60] & 2) {
        if (*(s32 *)(v + 0x33C) != 0) {
            func_L06_00351930(a0, v, 0x11, 0, 10);
            *(s32 *)(v + 0x33C) = 0;
        } else {
            if (0.0f < *(f32 *)(v + 0x338)) {
                func_L01_004450F0(a0, 1, 3);
                func_L06_00351930(a0, v, 2, 0, 10);
            } else {
                func_L01_004450F0(a0, 1, 5);
                func_L06_00351930(a0, v, 2, 0, 10);
            }
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_L06_00354E38 */
