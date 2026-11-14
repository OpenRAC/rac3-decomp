#include "common.h"

/* declared by functions of L39_004F4E58.c, which this file was cut from */
typedef struct S_004F4FD8 { u8 pad[0x30]; s32 *a; struct S_004F4FD8 *b; } S_004F4FD8;

/* localdecomp:start func_L39_004F5DA0 */
extern s32 D_L39_0046EE90[];
extern s32 D_L39_0046EEE0[];
extern s32 D_L39_0046EF30[];
struct S_004F5DA0;
typedef struct V_004F5DA0 V_004F5DA0;
typedef struct {
    s32 (*f0)(V_004F5DA0 *, struct S_004F5DA0 *);
    s32 (*f4)(V_004F5DA0 *, struct S_004F5DA0 *);
} VT_004F5DA0;
struct V_004F5DA0 { VT_004F5DA0 *vt; };
typedef struct S_004F5DA0 { u8 pad0[0xC]; s32 c; u8 pad10[0x18]; s32 r; s32 flags; } S_004F5DA0;

s32 func_L39_004F5DA0(S_004F5DA0 *a0, V_004F5DA0 *a1) {
    s32 r;

    if (a0->c != 0
        && (!(a0->flags & 2) || a1 != (V_004F5DA0 *)D_L39_0046EE90)
        && (!(a0->flags & 4) || a1 != (V_004F5DA0 *)D_L39_0046EEE0)
        && (!(a0->flags & 8) || a1 != (V_004F5DA0 *)D_L39_0046EF30)) {
        return 0x200;
    }
    r = a1->vt->f0(a1, a0);
    if (r != 0) {
        return r;
    }
    if (a1->vt->f4 != 0) {
        r = a1->vt->f4(a1, a0);
        a0->r = r;
        if (r == 0) {
            return 0x206;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_004F5DA0 */

/* localdecomp:start func_L39_004F5E70 */
extern void func_L39_004F5F80(void *);
extern void func_L39_004F74E8(void *, s32, s32);

void func_L39_004F5E70(u8 *p) {
    func_L39_004F5F80(p);
    func_L39_004F74E8(p + 0xC, 0, 8);
}
/* localdecomp:end func_L39_004F5E70 */

INCLUDE_ASM("asm/levels", func_L39_004F5EA0);

/* localdecomp:start func_L39_004F5F38 */
typedef struct E_004F5F38 { s32 key; s32 value; } E_004F5F38;
typedef struct T_004F5F38 { u8 pad[0xC]; u32 count; E_004F5F38 *entries; } T_004F5F38;

s32 func_L39_004F5F38(T_004F5F38 *t, s32 *out, s32 key) {
    u32 i;

    for (i = 0; i < t->count; i++) {
        if (t->entries[i].key == key) {
            *out = t->entries[i].value;
            return 0;
        }
    }
    return 0x217;
}
/* localdecomp:end func_L39_004F5F38 */

/* localdecomp:start func_L39_004F5F80 */
extern void func_L39_004F74E8(void *, s32, s32);

void func_L39_004F5F80(void *p) {
    func_L39_004F74E8(p, 0, 0xC);
}
/* localdecomp:end func_L39_004F5F80 */

/* localdecomp:start func_L39_004F5FA0 */
extern void func_L39_004F5FC8(void *);
extern void func_L39_004F7620(void *);

void func_L39_004F5FA0(u8 *p) {
    func_L39_004F5FC8(p);
    func_L39_004F7620(*(void **)(p + 8));
}
/* localdecomp:end func_L39_004F5FA0 */

/* localdecomp:start func_L39_004F5FC8 */
typedef struct E_004F5FC8 { void *h; void *arg; void (*fn)(void *); } E_004F5FC8;
typedef struct S_004F5FC8 { s32 n; s32 pad; E_004F5FC8 *e; } S_004F5FC8;
extern void func_L39_004F7620(void *);

void func_L39_004F5FC8(void *arg) {
    S_004F5FC8 *p = arg;
    u32 n = p->n;
    E_004F5FC8 *e = p->e;

    while (n-- > 0) {
        if (e->h != 0) {
            if (e->fn != 0) {
                e->fn(e->h);
            } else {
                func_L39_004F74E8(e->h, 0, (s32)e->arg);
                func_L39_004F7620(e->h);
            }
            e->h = 0;
        }
        e++;
    }
    p->n = 0;
}
/* localdecomp:end func_L39_004F5FC8 */

/* localdecomp:start func_L39_004F6060 */
/* written here: allocate *a1 = alloc(a2); on failure 0x206, else the sibling call to 004F6130 */
extern void *func_L39_004F7590(void *n);
extern s32 func_L39_004F6130(void *a0, void **a1, void *a2);

s32 func_L39_004F6060(void *a0, void **a1, void *a2)
{
    void *p = func_L39_004F7590(a2);
    *a1 = p;
    if (p == 0) {
        return 0x206;
    }
    return func_L39_004F6130(a0, a1, a2);
}
/* localdecomp:end func_L39_004F6060 */

/* localdecomp:start func_L39_004F60D8 */
extern void func_L39_004F7510(void *dst, const void *src, u32 n);

s32 func_L39_004F60D8(void *a, s32 *b, void *c, void *d) {
    s32 r = func_L39_004F6060(a, (void **)b, d);
    if (r != 0) {
        return r;
    }
    func_L39_004F7510((void *)*b, c, (u32)d);
    return 0;
}
/* localdecomp:end func_L39_004F60D8 */

/* localdecomp:start func_L39_004F6130 */
extern s32 func_L39_004F6198(void *, void *, void *, s32);
extern void func_L39_004F7620(void *);

s32 func_L39_004F6130(void *a0, void **a1, void *a2)
{
    s32 r = func_L39_004F6198(a0, *a1, a2, 0);
    if (r == 0) {
        return r;
    }
    func_L39_004F74E8(*a1, 0, (s32)a2);
    func_L39_004F7620(*a1);
    *a1 = 0;
    return r;
}
/* localdecomp:end func_L39_004F6130 */

INCLUDE_ASM("asm/levels", func_L39_004F6198);

/* localdecomp:start func_L39_004F62B0 */
typedef struct S_004F62B0 { void *p; s32 n; } S_004F62B0;

S_004F62B0 *func_L39_004F6368(void *, void *);
extern void *func_L39_004F75B0(void *, s32);
extern s32 func_L39_004F6130(void *a0, void **a1, void *a2);

s32 func_L39_004F62B0(void *a0, void **a1, s32 a2) {
    S_004F62B0 *e;
    void *v;

    e = func_L39_004F6368(a0, *a1);
    v = func_L39_004F75B0(*a1, a2);
    *a1 = v;
    if (v == 0) {
        if (e != 0) {
            e->p = 0;
        }
        return 0x206;
    }
    if (e == 0) {
        return func_L39_004F6130(a0, a1, (void *)a2);
    }
    e->p = v;
    e->n = a2;
    return 0;
}
/* localdecomp:end func_L39_004F62B0 */

INCLUDE_ASM("asm/levels", func_L39_004F6368);

/* localdecomp:start func_L39_004F63B8 */
typedef struct { s32 a; s32 b; } S_004F63B8;
extern void func_L39_004F6420(void *);

void func_L39_004F63B8(S_004F63B8 *lo)
{
    S_004F63B8 *hi;
    s32 t;

    func_L39_004F6420(lo);
    for (hi = lo + 15; lo < hi; lo++, hi--) {
        t = lo->a; lo->a = hi->a; hi->a = t;
        t = lo->b; lo->b = hi->b; hi->b = t;
    }
}
/* localdecomp:end func_L39_004F63B8 */

INCLUDE_ASM("asm/levels", func_L39_004F6420);

INCLUDE_ASM("asm/levels", func_L39_004F66E8);

/* localdecomp:start func_L39_004F6A30 */
void func_L39_004F66E8(void *, void *, void *);

void func_L39_004F6A30(u8 *a, void *b, void *c)
{
    func_L39_004F66E8(a, b, c);
    func_L39_004F66E8(a + 0x80, b, b);
    func_L39_004F66E8(a + 0x100, b, b);
}
/* localdecomp:end func_L39_004F6A30 */

/* localdecomp:start func_L39_004F6A80 */
s32 func_L39_004F4FD8(S_004F4FD8 *);
s32 func_L39_004F7018(void *);
s32 func_L39_005076F8(void *, void *, void *, void *);

s32 func_L39_004F6A80(void *a, void *b, void *c, void *d) {
    s32 r;

    r = func_L39_004F4FD8(a);
    if (r != 0) {
        return r;
    }
    r = func_L39_004F7018(b);
    if (r != 0) {
        return r;
    }
    return func_L39_005076F8(a, b, c, d);
}
/* localdecomp:end func_L39_004F6A80 */

/* localdecomp:start func_L39_004F6B10 */
s32 func_L39_004F5010(void *);
s32 func_L39_00507878(void *, void *, void *, void *, void *, void *, void *, void *);

s32 func_L39_004F6B10(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7) {
    s32 r;

    r = func_L39_004F4FD8(a0);
    if (r != 0) {
        return r;
    }
    r = func_L39_004F5010(a6);
    if (r != 0) {
        return r;
    }
    return func_L39_00507878(a0, a1, a2, a3, a4, a5, a6, a7);
}
/* localdecomp:end func_L39_004F6B10 */

/* localdecomp:start func_L39_004F6BF0 */
s32 func_L39_004F5010(void *);
s32 func_L39_005079E8(void *, void *, void *, void *, void *, void *);

s32 func_L39_004F6BF0(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5) {
    s32 r;

    r = func_L39_004F4FD8(a0);
    if (r != 0) {
        return r;
    }
    r = func_L39_004F5010(a4);
    if (r != 0) {
        return r;
    }
    return func_L39_005079E8(a0, a1, a2, a3, a4, a5);
}
/* localdecomp:end func_L39_004F6BF0 */

/* localdecomp:start func_L39_004F6CA8 */
s32 func_L39_004F7018(void *);
s32 func_L39_005077B8(void *, void *, void *, void *);

s32 func_L39_004F6CA8(void *a0, void *a1, void *a2, void *a3) {
    s32 r;

    r = func_L39_004F4FD8(a0);
    if (r != 0) {
        return r;
    }
    r = func_L39_004F7018(a1);
    if (r != 0) {
        return r;
    }
    return func_L39_005077B8(a0, a1, a2, a3);
}
/* localdecomp:end func_L39_004F6CA8 */

/* localdecomp:start func_L39_004F6D38 */
s32 func_L39_004F5010(void *);
s32 func_L39_00507930(void *, void *, void *, void *, void *, void *, void *, void *);

s32 func_L39_004F6D38(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, void *a7) {
    s32 r;

    r = func_L39_004F4FD8(a0);
    if (r != 0) {
        return r;
    }
    r = func_L39_004F5010(a6);
    if (r != 0) {
        return r;
    }
    return func_L39_00507930(a0, a1, a2, a3, a4, a5, a6, a7);
}
/* localdecomp:end func_L39_004F6D38 */

/* localdecomp:start func_L39_004F6E18 */
s32 func_L39_004F5010(void *);
s32 func_L39_00507A80(void *, void *, void *, void *, void *, void *);

s32 func_L39_004F6E18(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5)
{
    s32 r;

    r = func_L39_004F4FD8(a0);
    if (r != 0) {
        return r;
    }
    r = func_L39_004F5010(a4);
    if (r != 0) {
        return r;
    }
    return func_L39_00507A80(a0, a1, a2, a3, a4, a5);
}
/* localdecomp:end func_L39_004F6E18 */

/* localdecomp:start func_L39_004F6ED0 */
typedef struct S_004F6ED0 {
    u8 pad0[0x14];
    u8 f14[0x14];
    void *f28;
    struct S_004F6ED0 *f2C;
} S_004F6ED0;
extern void func_L39_004F4EE8(void *);
extern u8 D_L39_0046E9A8[];

s32 func_L39_004F6ED0(S_004F6ED0 **out)
{
    S_004F6ED0 *p;

    p = *out = ((S_004F6ED0 *(*)(s32))func_L39_004F7590)(0x30);
    if (p) {
        func_L39_004F5E70((u8 *)p);
        func_L39_004F4EE8(p->f14);
        p->f28 = D_L39_0046E9A8;
        p->f2C = p;
        return 0;
    }
    return 0x206;
}
/* localdecomp:end func_L39_004F6ED0 */

/* localdecomp:start func_L39_004F6F38 */
extern s32 func_L39_004F7018(void *arg0);
extern void func_L39_004F4EB8(void *arg0);
extern void func_L39_004F7620(void *arg0);

void func_L39_004F6F38(s32 *arg0)
{
    s32 *obj = (s32 *)*arg0;
    if (obj != 0) {
        if (func_L39_004F7018(obj) == 0) {
            obj[11] = 0;
            func_L39_004F4EB8(obj + 5);
            func_L39_004F5FA0((u8 *)obj);
            func_L39_004F7620(obj);
        }
        *arg0 = 0;
    }
}
/* localdecomp:end func_L39_004F6F38 */

INCLUDE_ASM("asm/levels", func_L39_004F6FA0);

LINKER_REMNANT("asm/levels", func_L39_004F7010);

/* localdecomp:start func_L39_004F7018 */
s32 func_L39_004F7018(void *arg0)
{
    s32 r;

    if (arg0 == 0) {
        return 0;
    }
    if (((S_004F6ED0 *)arg0)->f2C != arg0 || ((S_004F6ED0 *)arg0)->f28 != D_L39_0046E9A8) {
        r = 0x212;
    } else {
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L39_004F7018 */

/* localdecomp:start func_L39_004F7050 */
extern u8 D_L39_0046E9B0[];

s32 func_L39_004F7050(void **arg0) {
    *arg0 = D_L39_0046E9B0;
    return 1;
}
/* localdecomp:end func_L39_004F7050 */

INCLUDE_ASM("asm/levels", func_L39_004F7068);

INCLUDE_ASM("asm/levels", func_L39_004F70C8);

LINKER_REMNANT("asm/levels", func_L39_004F7128);

INCLUDE_ASM("asm/levels", func_L39_004F7130);

INCLUDE_ASM("asm/levels", func_L39_004F7190);

/* localdecomp:start func_L39_004F71F0 */
extern s32 D_L39_0046E9C0[];
s32 func_L39_004F71F0(s32 **out) {
    *out = D_L39_0046E9C0;
    return 1;
}
/* localdecomp:end func_L39_004F71F0 */

INCLUDE_ASM("asm/levels", func_L39_004F7208);

INCLUDE_ASM("asm/levels", func_L39_004F7270);

LINKER_REMNANT("asm/levels", func_L39_004F72C0);

INCLUDE_ASM("asm/levels", func_L39_004F72C8);

/* localdecomp:start func_L39_004F7318 */
s32 func_L39_004F7318(void) {
    return 0x21E;
}
/* localdecomp:end func_L39_004F7318 */

INCLUDE_ASM("asm/levels", func_L39_004F7320);

/* localdecomp:start func_L39_004F73F0 */
void func_L39_004F73F0(void *p)
{
    ((s32 *)p)[2] = 0;
    func_L39_004F74E8(p, 0, 0xC);
}
/* localdecomp:end func_L39_004F73F0 */

INCLUDE_ASM("asm/levels", func_L39_004F7410);

/* localdecomp:start func_L39_004F7460 */
typedef struct S_004F7460 {
    void *f0;
    s32 f4;
    void (*f8)(void *);
} S_004F7460;
extern void func_L39_004F74E8(void *, s32, s32);
extern void *func_L39_004F75B0(void *, s32);

s32 func_L39_004F7460(S_004F7460 *p, s32 n)
{
    void *t;

    if (p->f8 != 0) {
        p->f8(p->f0);
    }
    if (p->f4 == n) {
        return 0;
    }
    func_L39_004F74E8(p->f0, 0, p->f4);
    t = func_L39_004F75B0(p->f0, n);
    p->f0 = t;
    if (t == 0) {
        p->f4 = 0;
        return 0x206;
    }
    p->f4 = n;
    return 0;
}
/* localdecomp:end func_L39_004F7460 */

/* localdecomp:start func_L39_004F74E8 */
extern void func_004F7738(void *, s32, s32);

void func_L39_004F74E8(void *p, s32 c, s32 n) {
    if (n != 0) {
        func_004F7738(p, c, n);
    }
}
/* localdecomp:end func_L39_004F74E8 */

/* localdecomp:start func_L39_004F7510 */
extern void func_004F7778(void *, const void *, u32);

void func_L39_004F7510(void *dst, const void *src, u32 n) {
    if (n != 0) {
        func_004F7778(dst, src, n);
    }
}
/* localdecomp:end func_L39_004F7510 */

/* localdecomp:start func_L39_004F7538 */
extern void func_004F77F0(void *, void *, s32);

void func_L39_004F7538(void *dst, void *src, s32 n) {
    if (n) {
        func_004F77F0(dst, src, n);
    }
}
/* localdecomp:end func_L39_004F7538 */

/* localdecomp:start func_L39_004F7560 */
extern s32 func_004F77B0(const void *, const void *, s32);

s32 func_L39_004F7560(const void *a, const void *b, s32 n) {
    if (n == 0) {
        return 0;
    }
    return func_004F77B0(a, b, n);
}
/* localdecomp:end func_L39_004F7560 */

/* localdecomp:start func_L39_004F7590 */
extern void *func_L39_004B7748(u32);

void *func_L39_004F7590(void *n) {
    u32 size = (u32)n;

    if (size == 0) {
        size = 1;
    }
    return func_L39_004B7748(size);
}
/* localdecomp:end func_L39_004F7590 */

/* localdecomp:start func_L39_004F75B0 */
extern void *func_L39_004F7590(void *n);
void *func_L39_004B7C20(void *, u32);
extern void func_L39_004B7A80(void *);

void *func_L39_004F75B0(void *p, s32 size) {
    void *r;

    if (p == 0) {
        return func_L39_004F7590((void *)size);
    }
    r = func_L39_004B7C20(p, size ? size : 1);
    if (r == 0) {
        func_L39_004B7A80(p);
    }
    return r;
}
/* localdecomp:end func_L39_004F75B0 */

/* localdecomp:start func_L39_004F7620 */
extern void func_L39_004B7A80(void *);

void func_L39_004F7620(void *p) {
    if (p) {
        func_L39_004B7A80(p);
    }
}
/* localdecomp:end func_L39_004F7620 */

/* localdecomp:start func_L39_004F7648 */
extern s32 func_004F76C0(const char *);

s32 func_L39_004F7648(const char *s) {
    return func_004F76C0(s);
}
/* localdecomp:end func_L39_004F7648 */

/* localdecomp:start func_L39_004F7660 */
extern char *func_004F7690(char *, const char *);

char *func_L39_004F7660(char *dst, const char *src) {
    return func_004F7690(dst, src);
}
/* localdecomp:end func_L39_004F7660 */

INCLUDE_ASM("asm/levels", func_L39_004F7678);

/* localdecomp:start func_L39_004F76C0 */
/* strlen */
u32 func_L39_004F76C0(const char *s) {
    const char *start = s;

    while (*s) {
        s++;
    }
    return s - start;
}
/* localdecomp:end func_L39_004F76C0 */

/* localdecomp:start func_L39_004F76F8 */
/* strcmp */
s32 func_L39_004F76F8(const char *a, const char *b) {
    while (*a && *a == *b) {
        a++;
        b++;
    }
    return *(const u8 *)a - *(const u8 *)b;
}
/* localdecomp:end func_L39_004F76F8 */

/* localdecomp:start func_L39_004F7738 */
/* memset */
void *func_L39_004F7738(void *dst, s32 c, u32 n) {
    u8 *d = dst;

    while (n--) {
        *d++ = c;
    }
    return dst;
}
/* localdecomp:end func_L39_004F7738 */

/* localdecomp:start func_L39_004F7778 */
/* memcpy */
void *func_L39_004F7778(u8 *dst, const u8 *src, u32 n) {
    u8 *ret = dst;

    while (n--) {
        *dst++ = *src++;
    }
    return ret;
}
/* localdecomp:end func_L39_004F7778 */

/* localdecomp:start func_L39_004F77B0 */
/* memcmp */
s32 func_L39_004F77B0(const void *a, const void *b, u32 n) {
    const u8 *p = a;
    const u8 *q = b;

    while (n--) {
        if (*p != *q) {
            return *p - *q;
        }
        p++;
        q++;
    }
    return 0;
}
/* localdecomp:end func_L39_004F77B0 */

INCLUDE_ASM("asm/levels", func_L39_004F77F0);

/* localdecomp:start func_L39_004F7890 */
extern void func_L39_004F7968(u32, s32 *, s32 *, s32 *);
extern s32 func_L39_004F8148(s32, s32, s32, s32, s32, s32);
extern s32 func_L39_004F7A20(s32, s32, s32, s32, s32, s32);
extern void func_001264E0(s32);

void func_L39_004F7890(s32 p, s32 x, s32 k, u32 flags) {
    s32 *h;
    s32 v0, v1, v2;
    s32 d = x ^ k;
    u32 f = flags >> 1;
    s32 odd = flags & 1;

    if (!odd) {
        h = (s32 *)(p - 0x14);
    } else {
        h = (s32 *)(p - d - 0x14);
    }
    if (!odd) {
        *h = (s32)h;
        func_L39_004F7968(f, &v0, &v1, &v2);
        func_L39_004F8148(p, p + d, p - v0, k, v1, v2);
    } else {
        *h = 0;
        func_L39_004F7968(f, &v0, &v1, &v2);
        func_L39_004F7A20(p - d, p, p - d - v0, k, v1, v2);
    }
    func_001264E0(0);
    func_001264E0(2);
}
/* localdecomp:end func_L39_004F7890 */

INCLUDE_ASM("asm/levels", func_L39_004F7968);

INCLUDE_ASM("asm/levels", func_L39_004F7A20);

INCLUDE_ASM("asm/levels", func_L39_004F7AF8);

INCLUDE_ASM("asm/levels", func_L39_004F7B98);

INCLUDE_ASM("asm/levels", func_L39_004F7C38);

INCLUDE_ASM("asm/levels", func_L39_004F7CE8);

INCLUDE_ASM("asm/levels", func_L39_004F7D98);

INCLUDE_ASM("asm/levels", func_L39_004F7E70);

INCLUDE_ASM("asm/levels", func_L39_004F7F30);

INCLUDE_ASM("asm/levels", func_L39_004F8030);

/* localdecomp:start func_L39_004F8148 */
extern u32 func_L39_00509E38(s32);
extern s32 (*D_L39_0046E9F0[])(s32, s32, s32, s32, s32);

s32 func_L39_004F8148(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    s32 i;
    u32 code = func_L39_00509E38(a3);
    s32 n = code >> 28;

    for (i = 0; i < n; i++) {
        D_L39_0046E9F0[((s32)code >> (i * 4)) & 0xF](a0, a1, a2, a4, a5);
    }
    return 0;
}
/* localdecomp:end func_L39_004F8148 */

/* localdecomp:start func_L39_004F8220 */
/* best 15 diff: only register allocation. Retail gives end $s1, key $s2 (ours swapped), so prologue moves differ. Signed int compare needed (slt). Tried pointer types with casts, key local, while/for, separate cursor: all 15-16. */
s32 func_L39_00509DF8(s32, s32, s32);

s32 func_L39_004F8220(s32 p, s32 end, s32 base, s32 a, s32 b) {
    for (; p < end; p += 4) {
        if (func_L39_00509DF8(p - base, a, b) > 0) {
            *(u32 *)p ^= 0x9F8ED17;
        }
    }
    return 0;
}
/* localdecomp:end func_L39_004F8220 */

/* localdecomp:start func_L39_004F82C0 */
s32 func_L39_00509DF8(s32, s32, s32);

s32 func_L39_004F82C0(s32 p, s32 end, s32 base, s32 a, s32 b) {
    while (p < end) {
        if (func_L39_00509DF8(p - base, a, b) > 0) {
            *(u32 *)p ^= 0xA95128C3;
        }
        p += 4;
    }
    return 0;
}
/* localdecomp:end func_L39_004F82C0 */

/* localdecomp:start func_L39_004F8360 */
/* best: 17 diff. Logic right; retail keeps end in $s1 and mask 0x7FFFF in $s2, ours swaps them (plus resulting prologue schedule, and-operand order). Tried int params, for loop with temp v, pointer params with (s32) compare: same. */
extern s32 func_L39_00509DF8(s32, s32, s32);

s32 func_L39_004F8360(s32 *p, s32 *end, s32 base, s32 a3, s32 a4) {
    while ((s32)p < (s32)end) {
        if (func_L39_00509DF8((s32)p - base, a3, a4) > 0) {
            *p = ((*p >> 13) & 0x7FFFF) | ((*p << 19) & 0xFFF80000);
        }
        p++;
    }
    return 0;
}
/* localdecomp:end func_L39_004F8360 */

INCLUDE_ASM("asm/levels", func_L39_004F8420);

INCLUDE_ASM("asm/levels", func_L39_004F84E0);

INCLUDE_ASM("asm/levels", func_L39_004F85B8);

INCLUDE_ASM("asm/levels", func_L39_004F8690);

INCLUDE_ASM("asm/levels", func_L39_004F87A0);

INCLUDE_ASM("asm/levels", func_L39_004F88C8);
