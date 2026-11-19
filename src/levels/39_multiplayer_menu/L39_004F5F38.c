#include "common.h"

/* declared by functions of L39_004F4E58.c, which this file was cut from */
typedef struct S_004F4FD8 { u8 pad[0x30]; s32 *a; struct S_004F4FD8 *b; } S_004F4FD8;

/* declared by functions of L39_004F5DA0.c, which this file was cut from */
extern void func_L39_004F5F80(void *);
extern void func_L39_004F74E8(void *, s32, s32);

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
