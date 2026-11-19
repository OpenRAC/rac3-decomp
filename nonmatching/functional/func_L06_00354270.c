/* functional: medium. check.py at level_06: 275 diffs (stack layout, register allocation, branch-likely scheduling); every branch, call and argument re-derived from the assembly, including the retail oddities: the first 353CB8 call in the obj+0x390 path reads an uninitialised c/d pair (left uninitialised here), and the failure retry swaps which endpoint is replaced. Helper structs are inferred from stack offsets; k fields are vector pointers carried as s32 as the file's other prototypes do. */
#include "vu0.h"
#include "common.h"
typedef struct { u8 pad0[4]; u8 *y; vu0_v4 *to; s32 idx; vu0_v4 *from; f32 r; f32 d1; f32 d2; } N_00354270;
typedef struct { u8 *y; s32 i; vu0_v4 *pos; vu0_v4 *tgt; s32 k; f32 r; f32 d; } X_00354270;
typedef struct { vu0_v4 p; s32 idx; f32 f; } H_00354270;
typedef struct { N_00354270 *s; void *b; f32 f8; f32 c; f32 d; s32 k; H_00354270 *a; H_00354270 *e; } C_00354270;
extern f32 func_0038CEA8(void *);
extern f32 func_0038CF00(void *, void *);
extern f32 func_L01_0040E570(void *, void *);
extern f32 func_L06_0045B290(void *, f32, f32, s32, s32);
extern s32 func_L06_00352E20(u8 *, s32, s32, void *);
extern void func_L06_00353610(u8 *, void *, s32, void *, void *, void *);
extern s32 func_L06_003536C0(void *, void *, void *);
extern s32 func_L06_00353CB8(void *);
extern void func_0038CC88(void *, void *, s32);
extern void func_0038CD28(void *, void *, s32);

s32 func_L06_00354270(N_00354270 *n, void *b) {
    vu0_v4 d0;
    vu0_v4 q10;
    vu0_v4 q20;
    H_00354270 a;
    H_00354270 e;
    X_00354270 x;
    C_00354270 c;
    H_00354270 bk;
    H_00354270 bk2;
    u8 *p;
    f32 len;
    f32 dist;
    f32 f20;
    s32 flags;
    s32 m;
    s32 dir;

    p = *(u8 **)(n->y + 0x358);
    vec_sub_ab(&d0, n->from, (u8 *)p + n->idx * 16 + 0x10);
    len = func_0038CEA8(&d0);
    dist = func_0038CF00(n->to, n->from);
    f20 = func_L06_0045B290(p, len, *(f32 *)(n->y + 0x348), n->idx, *(s32 *)(n->y + 0x344));
    if (n->d1 + n->d2 < dist) {
        func_L06_00354118(n, (s32)b);
        return -1;
    }
    func_L06_00353610(n->y, p, n->idx, n->from, n->to, &q10);
    x.y = n->y;
    x.i = n->idx;
    x.pos = n->from;
    x.tgt = n->to;
    x.k = (s32)&q10;
    x.r = n->d1;
    x.d = n->d2;
    c.s = n;
    c.b = b;
    c.f8 = dist;
    c.k = (s32)&q10;
    c.a = &a;
    c.e = &e;
    if (*(s32 *)(n->y + 0x390) != 0) {
        a.idx = 0;
        a.f = 0.0f;
        e.f = 0.0f;
        e.idx = *(s32 *)p - 1;
        return func_L06_00353CB8(&c) != 0;
    }
    if (n->d2 < dist) {
        if (dist - n->d2 < n->r * 0.5f && 0.0f < dist - n->r) {
            flags = func_L06_003536C0(&x, &a, &e);
            if (func_L06_003541C8(flags, (S3534C8 *)n, (s32)b, (T3534C8 *)&a, (T3534C8 *)&e, len) == 0) {
                return 0;
            }
            if (f20 < 0.0f) {
                m = a.idx;
                m = m - (0 < m);
            } else {
                m = e.idx;
                m = m + (m < *(s32 *)p - 1);
            }
            dir = 0.0f < f20;
            if (func_L06_00352E20(n->y, dir, m, &q20)) {
                if (func_L01_0040E570(&q20, n->to) < n->r) {
                    f20 = -f20;
                }
            }
            if (f20 < 0.0f) {
                func_0038CC88(&bk, &e, 0x20);
                e.idx = n->idx;
                e.f = len;
            } else {
                func_0038CC88(&bk, &a, 0x20);
                a.idx = n->idx;
                a.f = len;
            }
            c.d = n->d2;
            c.c = dist - n->d1;
            if (func_L06_00353CB8(&c)) {
                return 1;
            }
            if (f20 < 0.0f) {
                func_0038CC88(&e, &bk, 0x20);
                a.idx = n->idx;
                a.f = len;
            } else {
                func_0038CC88(&a, &bk, 0x20);
                e.idx = n->idx;
                e.f = len;
            }
            if (func_L06_00353CB8(&c)) {
                return 1;
            }
        }
    }
    if (dist < n->r) {
        x.d = 0.0f;
        flags = func_L06_003536C0(&x, &a, &e);
        if (func_L06_003541C8(flags, (S3534C8 *)n, (s32)b, (T3534C8 *)&a, (T3534C8 *)&e, len) == 0) {
            return 0;
        }
        if (f20 < 0.0f) {
            m = a.idx;
            m = m - (0 < m);
        } else {
            m = e.idx;
            m = m + (m < *(s32 *)p - 1);
        }
        dir = 0.0f < f20;
        if (func_L06_00352E20(n->y, dir, m, &q20)) {
            if (func_L01_0040E570(&q20, n->to) < n->r) {
                f20 = -f20;
            }
        }
        if (f20 < 0.0f) {
            func_0038CD28(&bk2, &a, 0x20);
        } else {
            func_0038CD28(&bk2, &e, 0x20);
        }
        x.r = n->r;
        flags = func_L06_003536C0(&x, &a, &e);
        func_L06_003541C8(flags, (S3534C8 *)n, (s32)b, (T3534C8 *)&a, (T3534C8 *)&e, len);
        if (f20 < 0.0f) {
            func_0038CD28(&e, &a, 0x20);
            func_0038CD28(&a, &bk2, 0x20);
        } else {
            func_0038CD28(&a, &e, 0x20);
            func_0038CD28(&e, &bk2, 0x20);
        }
        c.d = n->d2;
        c.c = -n->d2;
        if (func_L06_00353CB8(&c)) {
            return 1;
        }
    }
    flags = func_L06_003536C0(&x, &a, &e);
    if (func_L06_003541C8(flags, (S3534C8 *)n, (s32)b, (T3534C8 *)&a, (T3534C8 *)&e, len) == 0) {
        return 0;
    }
    c.d = n->d2;
    c.c = dist - n->d1;
    return func_L06_00353CB8(&c) != 0;
}
