#include "common.h"

typedef struct {
    unsigned long *f0;
    s32 f4;
} BitSet_004FCA98;

/* declared by functions of L39_004FB668.c, which this file was cut from */
extern void *func_L39_004BEED8(s32);

/* localdecomp:start func_L39_004FC3C8 */
extern void *func_L39_004BEED8(s32);
extern void func_L39_004FC410(void *);

typedef struct S_004FC3C8 {
    char _p0[0x108];
    s32 f108;
    char _p10C[4];
} S_004FC3C8;

void *func_L39_004FC3C8(void) {
    S_004FC3C8 *obj = func_L39_004BEED8(sizeof(S_004FC3C8));

    if (obj == 0) {
        return 0;
    }
    func_L39_004FC410(obj);
    obj->f108 = 1;
    return obj;
}
/* localdecomp:end func_L39_004FC3C8 */

/* localdecomp:start func_L39_004FC410 */
extern void func_0011D534(void *, s32, s32);

void func_L39_004FC410(void *p) {
    s32 *arg0 = (s32 *)p;
    func_0011D534(arg0, 0, 0x110);
    arg0[0] = 0;
    arg0[0x108 / 4] = 0;
}
/* localdecomp:end func_L39_004FC410 */

INCLUDE_ASM("asm/levels", func_L39_004FC448);

/* localdecomp:start func_L39_004FC4B8 */
typedef struct {
    void *data;
    s32 count;
    s32 capacity;
    s32 unkC;
    u32 flags;
} Vec_004FC4B8;

extern s32 D_L39_0046EA50 __attribute__((section(".data")));
extern char D_L39_00478F08[];
extern void *func_0011D380(void *, const void *, unsigned int);
extern void *func_L39_004BEED8(s32);
extern void func_L39_004BEF28(void *);
extern s32 func_L39_00505980(u32, s32, s32, s32);

void *func_L39_004FC4B8(void *arg0, s32 newCap) {
    Vec_004FC4B8 *vec = arg0;
    char buf[16];
    void *mem;

    buf[0] = 0;
    func_L39_00505980((u32)buf, (s32)D_L39_00478F08, 340, ++D_L39_0046EA50);
    if (vec->capacity < newCap) {
        if (vec->flags & 2) {
            return 0;
        }
        mem = func_L39_004BEED8((newCap + 1) * 8);
        if (mem == 0) {
            return 0;
        }
        if (vec->data != 0) {
            func_0011D380(mem, vec->data, vec->count * 8);
            func_L39_004BEF28(vec->data);
        }
        vec->data = mem;
        vec->capacity = newCap;
    }
    return vec;
}
/* localdecomp:end func_L39_004FC4B8 */

/* localdecomp:start func_L39_004FC580 */
/* from rac4-decomp's func_L00_00538390 */
s32 func_L39_004FC380();
s32 func_L39_004FC5C0(s32, s32);

s32 func_L39_004FC580(s32 arg0) {
    s32 v = func_L39_004FC380();
    if (v == 0) return 0;
    return func_L39_004FC5C0(v, arg0);
}
/* localdecomp:end func_L39_004FC580 */

/* localdecomp:start func_L39_004FC5C0 */
typedef struct {
    unsigned long *f0;
    s32 f4;
    s32 f8;
    s32 fC;
} S_004FC5C0;

extern void *func_L39_004FC4B8(void *, s32);
extern void *func_0011D380(void *, const void *, unsigned int);

s32 func_L39_004FC5C0(s32 arg0, s32 arg1) {
    S_004FC5C0 *a = (S_004FC5C0 *)arg0;
    S_004FC5C0 *b = (S_004FC5C0 *)arg1;
    if (a == b) {
        return (s32)a;
    }
    if (b->f4 > a->f8) {
        if (func_L39_004FC4B8(a, b->f4) == 0) {
            return 0;
        }
    } else if (a == 0) {
        return 0;
    }
    func_0011D380(a->f0, b->f0, b->f4 * 8);
    if ((a->f4 = b->f4) == 0) {
        if (a->f0 != 0) {
            *a->f0 = 0;
        }
    }
    a->fC = b->fC;
    return (s32)a;
}
/* localdecomp:end func_L39_004FC5C0 */

/* localdecomp:start func_L39_004FC668 */
extern s32 func_L39_004FC158(BitSet_004FCA98 *);
unsigned long func_L39_004FC668(BitSet_004FCA98 *a) {
    unsigned long r = 0;
    s32 i;
    if ((func_L39_004FC158(a) + 7) / 8 > 8) return -1;
    for (i = a->f4 - 1; i >= 0; i--) r = a->f0[i];
    return r;
}
/* localdecomp:end func_L39_004FC668 */

/* localdecomp:start func_L39_004FC6F8 */
typedef struct {
    unsigned long *d;
    s32 top;
    s32 dmax;
    s32 neg;
} BN_004FC6F8;
extern void *func_L39_004FC4B8(void *, s32);

s32 func_L39_004FC6F8(BN_004FC6F8 *a, unsigned long w) {
    s32 i;
    s32 n;

    if (((a->dmax > 0) ? a : func_L39_004FC4B8(a, 2)) == 0) {
        return 0;
    }
    n = sizeof(unsigned long) / 8;
    a->neg = 0;
    a->top = 0;
    a->d[0] = w;
    if (a->d[0] != 0) {
        a->top = 1;
    }
    for (i = 1; i < n; i++) {
        a->d[i] = w >> 32;
        if (a->d[i] != 0) {
            a->top = i + 1;
        }
    }
    return 1;
}
/* localdecomp:end func_L39_004FC6F8 */

/* localdecomp:start func_L39_004FC780 */
typedef struct {
    unsigned long *d;
    s32 top;
    s32 dmax;
    s32 neg;
    s32 flags;
} BigNum_004FC780;

extern void *func_L39_004FC4B8(void *, s32);

void *func_L39_004FC780(const u8 *s, s32 len, BigNum_004FC780 *ret) {
    u32 i;
    u32 m;
    u32 n;
    unsigned long l;

    if (ret == 0) {
        ret = (BigNum_004FC780 *) func_L39_004FC380();
    }
    if (ret == 0) {
        return 0;
    }
    l = 0;
    n = len;
    if (n == 0) {
        ret->top = 0;
        return ret;
    }
    if (((((s32) (n + 2) * 8 + 63) / 64 <= ret->dmax) ? ret : func_L39_004FC4B8(ret, (s32) (n + 2) * 8 / 64 + 1)) == 0) {
        return 0;
    }
    i = ((n - 1) / 8) + 1;
    m = (n - 1) % 8;
    ret->top = i;
    while (n-- > 0) {
        l = (l << 8) | *(s++);
        if (m-- == 0) {
            unsigned long *d = ret->d;

            d[--i] = l;
            l = 0;
            m = 7;
        }
    }
    func_L39_004FC318(ret);
    return ret;
}
/* localdecomp:end func_L39_004FC780 */

/* localdecomp:start func_L39_004FC8C0 */
extern s32 func_L39_004FC158(BitSet_004FCA98 *);
s32 func_L39_004FC8C0(BitSet_004FCA98 *p, u8 *out) {
    s32 n = (func_L39_004FC158(p) + 7) / 8;
    s32 i = n;
    while (i-- > 0) *out++ = p->f0[i / 8] >> ((i % 8) * 8);
    return n;
}
/* localdecomp:end func_L39_004FC8C0 */

/* localdecomp:start func_L39_004FC960 */
s32 func_L39_004FC960(BitSet_004FCA98 *a0, BitSet_004FCA98 *a1) {
    s32 i;
    unsigned long *pa;
    unsigned long *pb;
    i = a0->f4 - a1->f4;
    if (i != 0) {
        return i;
    }
    pa = a0->f0;
    pb = a1->f0;
    for (i = a0->f4 - 1; i >= 0; i--) {
        if (pa[i] != pb[i]) {
            return (pa[i] > pb[i]) ? 1 : -1;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_004FC960 */

/* localdecomp:start func_L39_004FC9D0 */
typedef struct {
    unsigned long *f0;
    s32 f4;
    s32 f8;
    s32 fC;
} S_004FC9D0;

s32 func_L39_004FC9D0(S_004FC9D0 *a, S_004FC9D0 *b) {
    s32 gt, lt;
    s32 i;
    if (a == 0 || b == 0) {
        if (a != 0) return -1;
        else if (b != 0) return 1;
        else return 0;
    }
    if (a->fC != b->fC) {
        return a->fC == 0 ? 1 : -1;
    }
    if (a->fC == 0) {
        gt = 1;
        lt = -1;
    } else {
        gt = -1;
        lt = 1;
    }
    if (a->f4 > b->f4) return gt;
    if (a->f4 < b->f4) return lt;
    for (i = a->f4 - 1; i >= 0; i--) {
        if (a->f0[i] > b->f0[i]) return gt;
        if (b->f0[i] > a->f0[i]) return lt;
    }
    return 0;
}
/* localdecomp:end func_L39_004FC9D0 */
