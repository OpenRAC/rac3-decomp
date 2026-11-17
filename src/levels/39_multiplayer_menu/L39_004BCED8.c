#include "common.h"

/* declared by functions of L39_004BCDE0.c, which this file was cut from */
typedef struct S_004BCDE0 {
    u8 _00[0x88];
    long f88;
    long f90;
    u8 _98[8];
    s32 fA0;
} S_004BCDE0;
extern s32 **func_L39_004BD178(S_004BCDE0 *, s32, s32 *);

/* localdecomp:start func_L39_004BCED8 */
extern void *func_L39_004BEF00(void *, s32, s32);
extern unsigned long func_130D30(unsigned long, unsigned long);

typedef struct N_004BCED8 {
    s32 pad0;
    struct N_004BCED8 *next;
    unsigned long key;
} N_004BCED8;

typedef struct T_004BCED8 {
    N_004BCED8 **buckets;
    s32 pad4;
    s32 pad8;
    s32 count;
    u32 size;
    u32 p;
    u32 maxp;
    u8 pad1C[0x38 - 0x1C];
    unsigned long added;
    unsigned long grows;
    unsigned long removed;
    unsigned long shrinks;
    u8 pad58[0xA0 - 0x58];
    s32 fails;
} T_004BCED8;

void func_L39_004BCED8(T_004BCED8 *t) {
    u32 old;
    N_004BCED8 **newb;
    N_004BCED8 **pp;
    N_004BCED8 *n;
    N_004BCED8 **nb;
    u32 newsize;
    u32 i;
    unsigned long size;

    old = t->p;
    newb = &t->buckets[old + t->maxp];
    t->count++;
    t->added++;
    t->p = old + 1;
    pp = &t->buckets[old];
    *newb = 0;
    size = t->size;
    while ((n = *pp) != 0) {
        if (func_130D30(n->key, size) != old) {
            *pp = n->next;
            n->next = *newb;
            *newb = n;
        } else {
            pp = &n->next;
        }
    }
    if (t->p >= t->maxp) {
        newsize = t->size * 2;
        nb = func_L39_004BEF00(t->buckets, t->size * 8, t->size * 4);
        if (nb == 0) {
            t->p = 0;
            t->fails++;
            return;
        }
        for (i = t->size; i < newsize; i++) {
            nb[i] = 0;
        }
        t->buckets = nb;
        t->maxp = t->size;
        t->size = newsize;
        t->grows++;
        t->p = 0;
    }
}
/* localdecomp:end func_L39_004BCED8 */

/* localdecomp:start func_L39_004BD050 */
extern void *func_L39_004BEF00(void *, s32, s32);
typedef struct N_004BD050 {
    s32 pad0;
    struct N_004BD050 *next;
    unsigned long key;
} N_004BD050;

typedef struct T_004BD050 {
    N_004BD050 **buckets;
    s32 pad4;
    s32 pad8;
    s32 count;
    u32 size;
    u32 p;
    u32 maxp;
    u8 pad1C[0x48 - 0x1C];
    unsigned long removed;
    unsigned long shrinks;
    u8 pad58[0xA0 - 0x58];
    s32 fails;
} T_004BD050;

void func_L39_004BD050(T_004BD050 *t) {
    N_004BD050 *last;
    N_004BD050 *n;
    N_004BD050 **nb;

    last = t->buckets[t->p + t->maxp - 1];
    t->buckets[t->p + t->maxp - 1] = 0;
    if (t->p == 0) {
        nb = func_L39_004BEF00(t->buckets, (t->size >> 1) * 4, t->size * 4);
        if (nb == 0) {
            t->fails++;
            return;
        }
        t->shrinks++;
        t->size >>= 1;
        t->maxp >>= 1;
        t->p = t->maxp - 1;
        t->buckets = nb;
    } else {
        t->p--;
    }
    t->count--;
    t->removed++;
    n = t->buckets[t->p];
    if (n == 0) {
        t->buckets[t->p] = last;
    } else {
        while (n->next != 0) {
            n = n->next;
        }
        n->next = last;
    }
}
/* localdecomp:end func_L39_004BD050 */

/* localdecomp:start func_L39_004BD178 */
typedef struct N_004BD178 {
    void *key;
    struct N_004BD178 *next;
    unsigned long hash;
} N_004BD178;
typedef struct {
    N_004BD178 **buckets;
    s32 (*cmp)(void *, void *);
    unsigned long (*hashfn)(void *);
    char _pC[4];
    u32 f10;
    u32 f14;
    u32 f18;
    char _p1C[0x58 - 0x1C];
    long f58;
    long f60;
    char _p68[0x98 - 0x68];
    long f98;
} H_004BD178;

extern unsigned long func_130D30(unsigned long, unsigned long);

s32 **func_L39_004BD178(S_004BCDE0 *self, s32 arg1, s32 *arg2) {
    H_004BD178 *h = (H_004BD178 *)self;
    void *key = (void *)arg1;
    unsigned long *hashp = (unsigned long *)arg2;
    unsigned long hash;
    unsigned long idx;
    s32 (*cmp)(void *, void *);
    N_004BD178 **slot;
    N_004BD178 *n;

    hash = h->hashfn(key);
    h->f58++;
    *hashp = hash;
    idx = func_130D30(hash, h->f18);
    if (idx < h->f14) {
        idx = func_130D30(hash, h->f10);
    }
    slot = &h->buckets[(s32)idx];
    cmp = h->cmp;
    for (n = *slot; n != 0; n = n->next) {
        h->f98++;
        if (n->hash == hash) {
            h->f60++;
            if (cmp(n->key, key) == 0) {
                break;
            }
        }
        slot = &n->next;
    }
    return (s32 **)slot;
}
/* localdecomp:end func_L39_004BD178 */
