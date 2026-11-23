#include "common.h"

/* localdecomp:start func_L39_005128F8 */
extern void func_L39_004F74E8(void *, s32, s32);
extern void func_L39_004F7620(void *);
typedef struct S_005128F8 { s32 n; s32 cap; void *data; } S_005128F8;

void func_L39_005128F8(S_005128F8 *arg0) {
    if (arg0->data != 0) {
        func_L39_004F74E8(arg0->data, 0, arg0->n << 3);
        func_L39_004F7620(arg0->data);
        arg0->data = 0;
    }
    arg0->n = 0;
    arg0->cap = 0;
}
/* localdecomp:end func_L39_005128F8 */

/* localdecomp:start func_L39_00512948 */
typedef struct { s32 cap; s32 count; unsigned long *data; } S_00512948;
extern void *func_L39_004F7590(s32);
extern void func_L39_004F7510(void *, void *, s32);
extern void func_L39_004F74E8(void *, s32, s32);
extern void func_L39_004F7620(void *);
s32 func_L39_00512948(s32 n, S_00512948 *s) {
    unsigned long *p;
    s32 size = n * 8;

    if (s->cap >= n) {
        return 0;
    }
    if (s->data == 0) {
        s->cap = n;
        s->data = func_L39_004F7590(size);
        if (s->data == 0) {
            s->cap = 0;
            return 0x100;
        }
        return 0;
    }
    p = func_L39_004F7590(size);
    if (p != 0) {
        func_L39_004F7510(p, s->data, s->count * 8);
        func_L39_004F74E8(s->data, 0, s->cap * 8);
        func_L39_004F7620(s->data);
        s->cap = n;
        s->data = p;
        return 0;
    }
    func_L39_004F74E8(s->data, 0, s->cap * 8);
    func_L39_004F7620(s->data);
    s->cap = 0;
    s->count = 0;
    s->data = 0;
    return 0x100;
}
/* localdecomp:end func_L39_00512948 */

/* localdecomp:start func_L39_00512A40 */
typedef struct {
    s32 cap;
    s32 count;
    unsigned long *words;
} S_00512A40_Big;

extern void *func_L39_004F7590(s32);
extern void func_L39_004F74E8(void *, s32, s32);
extern void func_L39_004F7620(void *);

s32 func_L39_00512A40(s32 n, S_00512A40_Big *b) {
    unsigned long *p;
    s32 ret;
    s32 size = n * 8;

    if (b->cap >= n) {
        return 0;
    }
    if (b->words == 0) {
        b->cap = n;
        b->words = func_L39_004F7590(size);
        if (b->words == 0) {
            b->cap = 0;
            return 0x100;
        }
        return 0;
    }
    p = func_L39_004F7590(size);
    if (p != 0) {
        func_L39_004F74E8(b->words, 0, b->cap * 8);
        func_L39_004F7620(b->words);
        b->cap = n;
        b->words = p;
        ret = 0;
    } else {
        func_L39_004F74E8(b->words, 0, b->cap * 8);
        func_L39_004F7620(b->words);
        b->cap = 0;
        b->words = 0;
        ret = 0x100;
    }
    b->count = 0;
    return ret;
}
/* localdecomp:end func_L39_00512A40 */

/* localdecomp:start func_L39_00512B20 */
extern void func_L39_005128E8(s32 *);
extern s32 func_L39_00513350(void *, void *, void *);
extern s32 func_L39_00513808(void *, void *, void *);
s32 func_L39_00512B20(void *a, void *b, void *c, void *d) {
    s32 buf[4];
    s32 r;
    func_L39_005128E8(buf);
    r = func_L39_00513350(a, b, buf);
    if (r == 0) r = func_L39_00513808(buf, c, d);
    func_L39_005128F8((S_005128F8 *)buf);
    return r;
}
/* localdecomp:end func_L39_00512B20 */

/* localdecomp:start func_L39_00512BA8 */
typedef struct { s32 cap; s32 n; long *d; } S_00512BA8;
extern void func_L39_005128E8(s32 *);
extern s32 func_L39_00510F60(void *, void *);
extern s32 func_L39_005141B0(void *, void *, void *, void *, void *);

s32 func_L39_00512BA8(void *arg0, S_00512BA8 *arg1, void *arg2) {
    S_00512BA8 a;
    S_00512BA8 b;

    s32 ret;

    func_L39_005128E8((s32 *)&a);
    func_L39_005128E8((s32 *)&b);
    for (;;) {
        if (func_L39_00510F60(arg0, arg1) >= 0) {
            ret = arg1->d[arg1->n - 1] == 0 ? 0x107 : 0x108;
            break;
        }
        ret = func_L39_005141B0(arg0, arg1, arg2, &a, &b);
        if (ret != 0) break;
        if (b.n != 1 || b.d[0] != 1) ret = 0x10B;
        break;
    }
    func_L39_005128F8((S_005128F8 *)&a);
    func_L39_005128F8((S_005128F8 *)&b);
    return ret;
}
/* localdecomp:end func_L39_00512BA8 */
