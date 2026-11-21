#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003F2380();
extern s32 func_003EDF58();
extern void func_003EE160(void *p, s32, s32);
typedef struct S_3E7EC8 S_3E7EC8;
typedef struct { u8 pad[0x10]; s32 (*f10)(S_3E7EC8 *, s32); } V_3E7EC8;
struct S_3E7EC8 { u8 pad[8]; V_3E7EC8 *vt; };
extern s32 func_003EDDA0(S_3E7EC8 *a, s32 b);
extern void func_003EDED8();
typedef struct { u8 p0[8]; void *f8; u8 pC[4]; s32 f10, f14, f18, f1C; f32 f20, f24; s32 f28; } O_3E8420;
/* --- end of declarations from other files --- */

typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E8838;
typedef struct { s32 *e[16]; s32 pad[2]; s32 n; } O_003E8838;
typedef struct { u8 p0[0x2C]; O_003E8838 *x2C; } T_003E8838;
extern S_003E8838 D_001DA938_003EDDA0[];
extern s32 *func_003E6C08();
extern s32 func_003E6DE8();
extern s32 func_003E6378();
extern s32 D_001D96D0;
extern s32 func_003E7118();
extern void func_003E7108();
/* localdecomp:start func_003EDDA0 */
s32 func_003EDDA0(S_3E7EC8 *a, s32 key) {
    T_003E8838 *self = (T_003E8838 *)a;
    S_003E8838 *q;
    S_003E8838 *p;
    void *t;
    s32 v;
    s32 i, cnt;
    s32 *slot;
    p = D_001DA938_003EDDA0;
    if (p->x4) q = p;
    else q = (S_003E8838 *)func_003E6C08(p);
    t = (void *)func_003E6378(func_003E6DE8(q), key);
    if (t == 0 || (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D96D0) == 0) t = 0;
    v = (s32)t;
    if (v == 0) return 0;
    cnt = 0;
    for (i = 0; i < self->x2C->n; i++) {
        if (*(s32 *)((i << 2) + (s32)self->x2C) == v) cnt++;
    }
    if (cnt != 0) return 0;
    if (self->x2C->n < 16) {
        slot = (s32 *)((self->x2C->n << 2) + (s32)self->x2C);
        if (*slot != 0) func_003E7118(*slot);
        *slot = v;
        if (v != 0) func_003E7108(v);
        self->x2C->n = self->x2C->n + 1;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EDDA0 */

/* localdecomp:start func_003EDED8 */
extern s32 func_003E7118();
typedef struct { s32 a[0x12]; s32 x48; } S_E8;
typedef struct { u8 p[0x2C]; S_E8 *x2C; } T_E8;
void func_003EDED8(T_E8 *a0) {
    s32 i;
    for (i = 0; i < a0->x2C->x48; i++) {
        s32 *p = (s32 *)((u8 *)(i << 2) + (s32)a0->x2C);
        if (*p != 0) {
            func_003E7118(*p);
        }
        *p = 0;
    }
}
/* localdecomp:end func_003EDED8 */

typedef struct { s32 *arr[16]; s32 x40, x44, x48, x4C, x50, x54; f32 x58, x5C; } O_3E89F0;
typedef struct { u8 p0[8]; void *f8; u8 p1[0x2C - 0xC]; O_3E89F0 *x2C; } T_3E89F0;
typedef struct { s32 (*f0)(); s32 (*f4)(); s32 (*f8)(); } VT_3E89F0;
extern u8 D_001D9708[8];
void **func_003E6CC0(s32 *, s32);
/* localdecomp:start func_003EDF58 */
/* func_003F2388 is operator new (size, heap): under the name malloc gcc knows its result aliases nothing */
extern void *malloc(s32, s32) __asm__("func_003F2388");
s32 func_003EDF58(T_3E89F0 *p) {
    S_003E8838 *q;
    void **t;
    O_3E89F0 *o;
    s32 i;
    s32 **w;
    func_003ED988((O_3E8420 *)p);
    p->f8 = &D_001D9708;
    if (D_001DA938_003EDDA0->x4 != 0) q = D_001DA938_003EDDA0;
    else q = (S_003E8838 *)func_003E6C08(D_001DA938_003EDDA0);
    t = func_003E6CC0((s32 *)q, 1);
    if (t != 0) {
        o = (O_3E89F0 *)malloc(0x60, ((VT_3E89F0 *)*t)->f8(t, 0x60));
        w = o->arr;
        i = 15;
        do { *w++ = 0; } while (--i != -1);
        p->x2C = o;
        o->x40 = 0;
        o->x54 = 0;
        o->x5C = 1.0f;
        o->x50 = 0;
        o->x44 = 0;
        o->x58 = 1.0f;
        o->x48 = 0;
        func_003EE160(p, 1, 0);
    }
    return (s32)p;
}
/* localdecomp:end func_003EDF58 */

typedef struct { s32 *arr[16]; s32 x40; s32 x44; } O_3E8AD0;
typedef struct { u8 p0[8]; void *f8; u8 p1[0x2C - 0xC]; O_3E8AD0 *x2C; } T_3E8AD0;
typedef struct { u8 p0[4]; s32 f4; } S_3E8AD0;
typedef struct { s32 (*f0)(); s32 (*f4)(); s32 (*f8)(); s32 (*fC)(); } VT_3E8AD0;
extern u8 D_001D9708[8];
extern u8 D_001D9670_003EE038[8];
extern S_3E8AD0 D_001DA938_003EE038[];
extern s32 *func_003E6C08();
extern s32 **func_003E6CC0_003EE038();
extern s32 func_003E7118();
/* localdecomp:start func_003EE038 */
void func_003EE038(T_3E8AD0 *p, s32 flags) {
    O_3E8AD0 *a, *b;
    s32 *q;
    s32 **t;
    s32 **w;
    p->f8 = D_001D9708;
    func_003EDED8(p);
    a = p->x2C;
    if (a->x44 != 0) func_003E7118(a->x44);
    a->x44 = 0;
    b = p->x2C;
    if (b->x44 != 0) func_003E7118(b->x44);
    b->x44 = 0;
    if (b->arr != 0) {
        w = b->arr + 16;
        if (b->arr != w) {
            do {
                w--;
                if (*w) func_003E7118(*w);
                *w = 0;
            } while (b->arr != w);
        }
    }
    {
        S_3E8AD0 *d = D_001DA938_003EE038;
        if (d->f4 != 0) {
            q = (s32 *)d;
        } else {
            q = func_003E6C08(d);
        }
    }
    t = func_003E6CC0_003EE038(q, 1);
    if (t != 0) {
        ((VT_3E8AD0 *)*t)->fC(t, p->x2C);
        p->x2C = 0;
    }
    p->f8 = D_001D9670_003EE038;
    if (flags & 1) func_003F2380(p);
}
/* localdecomp:end func_003EE038 */
