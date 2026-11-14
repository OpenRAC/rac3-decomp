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

INCLUDE_ASM("asm/levels", func_L39_004F5F38);

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

INCLUDE_ASM("asm/levels", func_L39_004F5FC8);

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

INCLUDE_ASM("asm/levels", func_L39_004F60D8);

INCLUDE_ASM("asm/levels", func_L39_004F6130);

INCLUDE_ASM("asm/levels", func_L39_004F6198);

INCLUDE_ASM("asm/levels", func_L39_004F62B0);

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

INCLUDE_ASM("asm/levels", func_L39_004F6A30);

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

INCLUDE_ASM("asm/levels", func_L39_004F6E18);

INCLUDE_ASM("asm/levels", func_L39_004F6ED0);

INCLUDE_ASM("asm/levels", func_L39_004F6F38);

INCLUDE_ASM("asm/levels", func_L39_004F6FA0);

INCLUDE_ASM("asm/levels", func_L39_004F7018);

INCLUDE_ASM("asm/levels", func_L39_004F7320);

INCLUDE_ASM("asm/levels", func_L39_004F73F0);

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

INCLUDE_ASM("asm/levels", func_L39_004F7590);

INCLUDE_ASM("asm/levels", func_L39_004F75B0);

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

INCLUDE_ASM("asm/levels", func_L39_004F841C);

INCLUDE_ASM("asm/levels", func_L39_004F84DC);

INCLUDE_ASM("asm/levels", func_L39_004F85B4);

INCLUDE_ASM("asm/levels", func_L39_004F868C);

INCLUDE_ASM("asm/levels", func_L39_004F879C);

INCLUDE_ASM("asm/levels", func_L39_004F88C8);
