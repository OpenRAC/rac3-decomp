#include "common.h"

/* localdecomp:start func_L39_00515BD8 */
extern void *func_L39_004F7590(s32);
extern void func_L39_004F74E8(void *, s32, s32);

s32 func_L39_00515BD8(void **arg0) {
    void *p;

    p = func_L39_004F7590(12);
    *arg0 = p;
    if (p == 0) {
        return 0x258;
    }
    func_L39_004F74E8(p, 0, 12);
    return 0;
}
/* localdecomp:end func_L39_00515BD8 */

/* localdecomp:start func_L39_00515C28 */
extern void func_L39_00515C70(void *, s32);
extern void func_L39_004F7620(void *);

typedef struct {
    s32 unk0;
    s32 unk4;
    void *unk8;
} S_00515C28;

typedef struct {
    S_00515C28 *p;
} H_00515C28;

s32 func_L39_00515C28(H_00515C28 *arg0) {
    func_L39_00515C70(arg0->p, 0);
    func_L39_004F7620(arg0->p->unk8);
    func_L39_004F7620(arg0->p);
    arg0->p = 0;
    return 0;
}
/* localdecomp:end func_L39_00515C28 */

/* localdecomp:start func_L39_00515C70 */
typedef struct { void *unk0; s32 unk4; void (*unk8)(void *); } S_00515C70_E;
typedef struct { s32 unk0; s32 unk4; S_00515C70_E *unk8; } S_00515C70;
extern void func_L39_004F74E8(void *, s32, s32);
extern void func_L39_004F7620(void *);
void func_L39_00515C70(void *p, s32 arg1) {
    S_00515C70 *arg0 = p;
    u32 n = arg0->unk0;
    S_00515C70_E *e = arg0->unk8;
    while (n-- > 0) {
        if (e->unk0 != 0) {
            if (e->unk8 != 0) {
                e->unk8(e->unk0);
            } else {
                if (arg1 != 0) {
                    func_L39_004F74E8(e->unk0, 0, e->unk4);
                }
                func_L39_004F7620(e->unk0);
            }
            e->unk0 = 0;
        }
        e++;
    }
    arg0->unk0 = 0;
}
/* localdecomp:end func_L39_00515C70 */

/* localdecomp:start func_L39_00515D28 */
extern void *func_L39_004F7590(s32);
extern s32 func_L39_00515E00(s32, s32, void *);
extern void func_L39_004F7620(void *);
s32 func_L39_00515D28(s32 a, s32 b, void **c) {
    void *v;
    s32 r;

    v = func_L39_004F7590(b);
    *c = v;
    if (v == 0) {
        return 0x258;
    }
    r = func_L39_00515E00(a, b, v);
    if (r != 0) {
        func_L39_004F7620(*c);
    }
    return r;
}
/* localdecomp:end func_L39_00515D28 */

/* localdecomp:start func_L39_00515DA8 */
extern void func_L39_004F7510(void *, void *, s32);
s32 func_L39_00515DA8(s32 a, s32 b, s32 c, s32 *d) {
    s32 r = func_L39_00515D28(a, b, (void **)d);
    if (r != 0) { return r; }
    func_L39_004F7510((void *)d[0], (void *)c, b);
    return 0;
}
/* localdecomp:end func_L39_00515DA8 */

/* localdecomp:start func_L39_00515E00 */
/* func_L39_00515E18 is defined later in this file with a struct type of its own block (S_00515E18 *), which
 * cannot be named here: an old-style declaration stays compatible with that definition, and the call casts
 * to the full prototype. */
extern s32 func_L39_00515E18();

s32 func_L39_00515E00(s32 arg0, s32 arg1, void *arg2)
{
    return ((s32 (*)(s32, s32, void *, s32))func_L39_00515E18)(arg0, arg1, arg2, 0);
}
/* localdecomp:end func_L39_00515E00 */

/* localdecomp:start func_L39_00515E18 */
extern void *func_L39_004F7590(s32);
extern void func_L39_004F7510(void *, void *, s32);
extern void func_L39_004F7620(void *);

typedef struct { s32 n; u32 cap; u32 d; } S_00515E18;

s32 func_L39_00515E18(S_00515E18 *s, s32 b, s32 a, s32 c) {
    s32 n = s->n;
    s32 cap = n + 10;
    s32 t = cap * 3;
    if (s->cap < n + 1) {
        u32 d = (u32)func_L39_004F7590(t << 2);
        if (d == 0) {
            return 600;
        }
        func_L39_004F7510((void *)d, (void *)s->d, (s->n * 3) << 2);
        func_L39_004F7620((void *)s->d);
        s->d = d;
        s->cap = cap;
        n = s->n;
    }
    *(s32 *)(((n * 3) << 2) + s->d) = a;
    *(s32 *)(((s->n * 3) << 2) + s->d + 4) = b;
    *(s32 *)(((s->n++ * 3) << 2) + s->d + 8) = c;
    return 0;
}
/* localdecomp:end func_L39_00515E18 */

LINKER_REMNANT("asm/levels", func_L39_00515F30);

/* localdecomp:start func_L39_00515F38 */
typedef struct {
    s32 key;
    s32 unk4;
    s32 unk8;
} E_00515F38;

typedef struct {
    u32 count;
    s32 unk4;
    E_00515F38 *items;
} S_00515F38;

E_00515F38 *func_L39_00515F38(S_00515F38 *arg0, s32 arg1) {
    u32 n;
    E_00515F38 *p;
    if (arg1 == 0) return 0;
    n = arg0->count;
    p = arg0->items;
    while (n-- > 0) {
        if (p->key == arg1) return p;
        p++;
    }
    return 0;
}
/* localdecomp:end func_L39_00515F38 */
