#include "common.h"

typedef struct S_006CD768 {
    u8 f0;
    u8 pad1[7];
    u8 f8;
    u8 pad9[3];
    s32 fC;
} S_006CD768;

/* declared by functions of L39_006CCE90.c, which this file was cut from */
extern void *D_L39_0024D760;
extern u8 D_001A5CD0[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);
void func_00120D28(s32, s32, s32);
void *func_001206F4(void *, void *);
long func_0012DCB0(void);
long func_00130760(long, long);
void func_001961E8(s32);
s32 func_001961F8(void);
void func_00195410(void);
s32 func_L39_006D8AD8(u8 *);
void func_L39_006D2EF0(void *, s32, s32);
extern u16 D_L39_00249C18[];
extern void *func_001206F4(void *, void *);

/* localdecomp:start func_L39_006D08E8 */
typedef struct S_006D08E8 {
    u16 f0;
    u8 pad2[0x16];
    s32 f18;
    s32 f1C;
    s32 f20;
    u8 pad24[0xC];
    u8 f30[16];
} S_006D08E8;
extern u16 D_L39_00249C18[];
extern u8 D_001978D0[];
void func_0014B008(void *);
s32 func_0017D990(void *, void *, s32);
void func_001961E8(s32);
s32 func_001961F8(void);

s32 func_L39_006D08E8(u8 *arg0) {
    S_006D08E8 buf;
    s32 r = 1;

    if (arg0[0x3B4] != 0) {
        buf.f0 = D_L39_00249C18[0];
        buf.f18 = *(s32 *)arg0;
        arg0[0x3BC] = 1;
        buf.f1C = 0;
        buf.f20 = 0;
        *(s32 *)(arg0 + 0x3C0) = (s32) func_00130760(func_0012DCB0(), 0x24000);
        func_0014B008(buf.f30);
        func_001961E8(func_0017D990(&buf, D_001978D0, 0));
        if (func_001961F8() != 0) {
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006D08E8 */

/* localdecomp:start func_L39_006D0990 */
/* log: adapted from the matched twin func_L39_006D2AC0 (same file), offsets for this one. */
__asm__(".extern D_L39_0024D760, 16");
typedef s32 (*Cmp_006D0990)(void *, void *);
typedef struct Heap_006D0990 {
    Cmp_006D0990 cmp;
    s32 count;
    void **items;
} Heap_006D0990;
typedef struct Pool_006D0990 {
    u8 pad0[0xC];
    s32 link;
    u8 pad10[8];
    s32 free;
    u8 *head;
} Pool_006D0990;
typedef struct Mgr_006D0990 {
    u8 pad0[0x3B4];
    u8 active;
    u8 pad3B5[3];
    s32 cur;
    u8 f3BC;
    u8 pad3BD[3];
    s32 f3C0;
    s32 f3C4;
    s32 max;
    Heap_006D0990 heaps[2];
    Pool_006D0990 *pool;
} Mgr_006D0990;
typedef struct Part_006D0990 {
    u8 b[0x1D8];
} __attribute__((packed)) Part_006D0990;
typedef struct Blk_006D0990 {
    Part_006D0990 a;
    s32 b;
} Blk_006D0990;
typedef struct Msg_006D0990 {
    u8 pad0[0x18];
    s32 type;
    u8 pad1C[0x1D8 - 0x1C];
    u8 f1D8;
} Msg_006D0990;
extern void func_0011D534(void *, s32, s32);

void func_L39_006D0990(Msg_006D0990 *arg0) {
    u8 *g = D_L39_0024D760;
    Mgr_006D0990 *m = *(Mgr_006D0990 **)(g + 0x38);
    Heap_006D0990 *q;
    Heap_006D0990 *h;
    s32 idx;
    s32 one;
    s32 zero;

    if (!m->active) {
        return;
    }
    if (g[0x1D] != 0) {
        return;
    }
    one = 1;
    zero = 0;
    idx = m->cur == 0 ? one : zero;
    q = &m->heaps[idx];
    if (arg0->type == 0) {
        if (q->count < m->max) {
            Pool_006D0990 *pool = m->pool;
            u8 *h = pool->head;
            u8 *p;
            if (h != 0) {
                pool->head = *(u8 **)(h + pool->link);
                pool->free--;
            }
            p = h;
            if (p != 0) {
                s32 i;
                *(Blk_006D0990 *)p = *(Blk_006D0990 *)arg0;
                i = q->count++;
                q->items[i] = p;
                if (q->cmp != 0) {
                    s32 parent = i / 2;
                    while (i > 0 && (u8)q->cmp(q->items[parent], q->items[i])) {
                        void *t = q->items[parent];
                        q->items[parent] = q->items[i];
                        q->items[i] = t;
                        i = parent;
                    }
                }
            }
        }
    } else if (arg0->type != 1) {
        if (arg0->f1D8 != 0) {
            func_0011D534(arg0, 0, 0x1DC);
            arg0->f1D8 = 1;
        } else {
            func_0011D534(arg0, 0, 0x1DC);
        }
    } else {
        arg0->f1D8 = 1;
    }
    if (arg0->f1D8 == 0) {
        return;
    }
    if (q->cmp != 0 && q->count >= 2) {
        s32 k;
        for (k = q->count - 1; k > 0; k--) {
            void *t = q->items[k];
            q->items[k] = q->items[0];
            q->items[0] = t;
            if (q->cmp != 0) {
                s32 pos = k;
                void *val = q->items[k];
                s32 child = pos * 2 + 1;
                if (child < 0) {
                    do {
                        s32 right = child + 1;
                        if (right < 0) {
                            if ((u8)q->cmp(q->items[child], q->items[right])) {
                                child = right;
                            }
                            if (q->cmp(val, q->items[child]) == 0) {
                                break;
                            }
                            q->items[pos] = q->items[child];
                            pos = child;
                            child = pos * 2 + 1;
                        }
                    } while (child < 0);
                }
                q->items[pos] = val;
            }
        }
    }
    h = 0;
    if (m->active && m->cur >= 0) {
        h = &m->heaps[m->cur];
    }
    if (h != 0) {
        s32 i;
        for (i = 0; i < h->count; i++) {
            Pool_006D0990 *pool = m->pool;
            u8 *p = h->items[i];
            *(u8 **)(p + pool->link) = pool->head;
            pool->head = p;
            pool->free++;
        }
        h->count = 0;
    }
    m->cur = idx;
    m->f3C4 = m->f3C0;
    m->f3BC = 0;
}
/* localdecomp:end func_L39_006D0990 */

INCLUDE_ASM("asm/levels", func_L39_006D0DD0);

INCLUDE_ASM("asm/levels", func_L39_006D0F08);

INCLUDE_ASM("asm/levels", func_L39_006D12C8);

/* localdecomp:start func_L39_006D1658 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x13];
    s32 f28;
    s32 f2C;
    u8 f30[0x10];
} S_006D1658;
typedef struct {
    u8 pad0[0x424];
    u8 f424;
    u8 pad425[7];
    u8 f42C;
    u8 pad42D[3];
    s32 f430;
    u8 pad434[4];
    s32 f438;
} T_006D1658;
extern u16 D_L39_00249C18[];
extern u8 D_00197920[];
extern void *func_001206F4(void *, void *);
extern void func_0014B008(void *);
extern s32 func_0017D178(void *, u8 *, s32);

s32 func_L39_006D1658(u8 *arg0) {
    T_006D1658 *p = (T_006D1658 *)arg0;
    s32 r = 1;
    S_006D1658 x;

    if (p->f424 != 0) {
        void *n = *(void **)((u8 *)D_L39_0024D760 + 0x50);
        x.f0 = D_L39_00249C18[0];
        func_001206F4(x.f15, n);
        p->f42C = 1;
        x.f28 = 1;
        x.f2C = p->f438;
        p->f430 = (s32) func_00130760(func_0012DCB0(), 0x24000);
        func_0014B008(x.f30);
        func_001961E8(func_0017D178(&x, D_00197920, 0));
        if (func_001961F8() != 0) {
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006D1658 */

/* localdecomp:start func_L39_006D1710 */
typedef struct E_006D1710 {
    s32 pad0[6];
    s32 f18;
    u8 pad1C[0x110 - 0x1C];
    u8 f110;
    u8 pad111[3];
} E_006D1710;

typedef s32 (*Cmp_006D1710)(E_006D1710 *, E_006D1710 *);

typedef struct Q_006D1710 {
    Cmp_006D1710 cmp;
    s32 count;
    E_006D1710 **arr;
} Q_006D1710;

typedef struct P_006D1710 {
    u8 pad0[0xC];
    s32 fC;
    u8 pad10[8];
    s32 f18;
    u8 *f1C;
} P_006D1710;

typedef struct M_006D1710 {
    u8 pad0[0x424];
    u8 f0;
    u8 pad1[3];
    s32 f4;
    u8 f8;
    u8 pad9[3];
    s32 fC;
    s32 f10;
    s32 f24;
    Q_006D1710 q[2];
    P_006D1710 *f40;
} M_006D1710;

typedef struct G_006D1710 {
    u8 pad0[0x1D];
    u8 f1D;
    u8 pad1E[0x1A];
    M_006D1710 *f38;
} G_006D1710;

__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
void func_0011D534(void *, s32, s32);

void func_L39_006D1710(E_006D1710 *arg0) {
    G_006D1710 *g = (G_006D1710 *)D_L39_0024D760;
    M_006D1710 *m = g->f38;
    Q_006D1710 *q;
    Q_006D1710 *p;
    P_006D1710 *pool;
    E_006D1710 *node;
    E_006D1710 *n;
    P_006D1710 *pool2;
    E_006D1710 *node2;
    E_006D1710 *e;
    E_006D1710 *t;
    s32 which;
    s32 i;
    s32 k;
    s32 j;
    s32 child;

    if (m->f0 == 0 || g->f1D != 0) {
        return;
    }
    if (m->f4 == 0) {
        which = 1;
    } else {
        which = 0;
    }
    q = &m->q[which];
    if (arg0->f18 == 0) {
        if (q->count < m->f24) {
            pool = m->f40;
            n = (E_006D1710 *)pool->f1C;
            if (n != 0) {
                pool->f1C = *(u8 **)((u8 *)n + pool->fC);
                pool->f18--;
            }
            node = n;
            if (node != 0) {
                *node = *arg0;
                j = q->count++;
                q->arr[j] = node;
                if (q->cmp != 0) {
                    i = j / 2;
                    while (j > 0 && (u8)q->cmp(q->arr[i], q->arr[j])) {
                        t = q->arr[i];
                        q->arr[i] = q->arr[j];
                        q->arr[j] = t;
                        j = i;
                    }
                }
            }
        }
    } else if (arg0->f18 != 1) {
        if (arg0->f110 != 0) {
            func_0011D534(arg0, 0, 0x114);
            arg0->f110 = 1;
        } else {
            func_0011D534(arg0, 0, 0x114);
        }
    } else {
        arg0->f110 = 1;
    }
    if (arg0->f110 == 0) {
        return;
    }
    if (q->cmp != 0 && q->count >= 2) {
        for (k = q->count - 1; k > 0; k--) {
            t = q->arr[k];
            q->arr[k] = q->arr[0];
            q->arr[0] = t;
            if (q->cmp != 0) {
                i = k;
                e = q->arr[i];
                child = i * 2 + 1;
                while (child < 0) {
                    s32 r = child + 1;
                    if (r < 0) {
                        if ((u8)q->cmp(q->arr[child], q->arr[r])) {
                            child = r;
                        }
                        if (q->cmp(e, q->arr[child])) {
                            q->arr[i] = q->arr[child];
                            i = child;
                            child = i * 2 + 1;
                        } else {
                            break;
                        }
                    }
                }
                q->arr[i] = e;
            }
        }
    }
    p = 0;
    if (m->f0 != 0 && m->f4 >= 0) {
        p = &m->q[m->f4];
    }
    if (p != 0) {
        for (k = 0; k < p->count; k++) {
            pool2 = m->f40;
            node2 = p->arr[k];
            *(u8 **)((u8 *)node2 + pool2->fC) = pool2->f1C;
            pool2->f1C = (u8 *)node2;
            pool2->f18++;
        }
        p->count = 0;
    }
    m->f4 = which;
    m->f10 = m->fC;
    m->f8 = 0;
}
/* localdecomp:end func_L39_006D1710 */

/* localdecomp:start func_L39_006D1B40 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x13];
    s32 f28;
    s32 f2C;
    u8 f30[0x10];
} S_006D1B40;
typedef struct {
    u8 pad0[0x45C];
    u8 f45C;
    u8 pad45D[7];
    u8 f464;
    u8 pad465[3];
    s32 f468;
    u8 pad46C[4];
    s32 f470;
} T_006D1B40;
extern u16 D_L39_00249C18[];
extern u8 D_001978A8[];
extern void *func_001206F4(void *, void *);
extern void func_0014B008(void *);
extern s32 func_0017D0F8(void *, u8 *, s32);

s32 func_L39_006D1B40(u8 *arg0) {
    T_006D1B40 *p = (T_006D1B40 *)arg0;
    s32 r = 1;
    S_006D1B40 x;

    if (p->f45C != 0) {
        void *n = *(void **)((u8 *)D_L39_0024D760 + 0x50);
        x.f0 = D_L39_00249C18[0];
        func_001206F4(x.f15, n);
        p->f464 = 1;
        x.f28 = 1;
        x.f2C = p->f470;
        p->f468 = (s32) func_00130760(func_0012DCB0(), 0x24000);
        func_0014B008(x.f30);
        func_001961E8(func_0017D0F8(&x, D_001978A8, 0));
        if (func_001961F8() != 0) {
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006D1B40 */

/* localdecomp:start func_L39_006D1BF8 */
__asm__(".extern D_L39_0024D760, 16");
typedef s32 (*Cmp_006D1BF8)(void *, void *);
typedef struct Heap_006D1BF8 {
    Cmp_006D1BF8 cmp;
    s32 count;
    void **items;
} Heap_006D1BF8;
typedef struct Pool_006D1BF8 {
    u8 pad0[0xC];
    s32 link;
    u8 pad10[8];
    s32 free;
    u8 *head;
} Pool_006D1BF8;
typedef struct Mgr_006D1BF8 {
    u8 pad0[0x45C];
    u8 active;
    u8 pad45D[3];
    s32 cur;
    u8 f464;
    u8 pad465[3];
    s32 f468;
    s32 f46C;
    s32 max;
    Heap_006D1BF8 heaps[2];
    Pool_006D1BF8 *pool;
} Mgr_006D1BF8;
typedef struct Blk_006D1BF8 {
    u8 b[0x118];
} __attribute__((packed)) Blk_006D1BF8;
typedef struct Msg_006D1BF8 {
    u8 pad0[0x18];
    s32 type;
    u8 pad1C[0x114 - 0x1C];
    u8 f114;
} Msg_006D1BF8;
extern void func_0011D534(void *, s32, s32);

void func_L39_006D1BF8(Msg_006D1BF8 *arg0) {
    u8 *g = D_L39_0024D760;
    Mgr_006D1BF8 *m = *(Mgr_006D1BF8 **)(g + 0x38);
    Heap_006D1BF8 *q;
    Heap_006D1BF8 *h;
    s32 idx;
    s32 one;
    s32 zero;

    if (!m->active) {
        return;
    }
    if (g[0x1D] != 0) {
        return;
    }
    one = 1;
    zero = 0;
    idx = m->cur == 0 ? one : zero;
    q = &m->heaps[idx];
    if (arg0->type == 0) {
        if (q->count < m->max) {
            Pool_006D1BF8 *pool = m->pool;
            u8 *h = pool->head;
            u8 *p;
            if (h != 0) {
                pool->head = *(u8 **)(h + pool->link);
                pool->free--;
            }
            p = h;
            if (p != 0) {
                s32 i;
                *(Blk_006D1BF8 *)p = *(Blk_006D1BF8 *)arg0;
                i = q->count++;
                q->items[i] = p;
                if (q->cmp != 0) {
                    s32 parent = i / 2;
                    while (i > 0 && (u8)q->cmp(q->items[parent], q->items[i])) {
                        void *t = q->items[parent];
                        q->items[parent] = q->items[i];
                        q->items[i] = t;
                        i = parent;
                    }
                }
            }
        }
    } else if (arg0->type != 1) {
        if (arg0->f114 != 0) {
            func_0011D534(arg0, 0, 0x118);
            arg0->f114 = 1;
        } else {
            func_0011D534(arg0, 0, 0x118);
        }
    } else {
        arg0->f114 = 1;
    }
    if (arg0->f114 == 0) {
        return;
    }
    if (q->cmp != 0 && q->count >= 2) {
        s32 k;
        for (k = q->count - 1; k > 0; k--) {
            void *t = q->items[k];
            q->items[k] = q->items[0];
            q->items[0] = t;
            if (q->cmp != 0) {
                s32 pos = k;
                void *val = q->items[k];
                s32 child = pos * 2 + 1;
                if (child < 0) {
                    do {
                        s32 right = child + 1;
                        if (right < 0) {
                            if ((u8)q->cmp(q->items[child], q->items[right])) {
                                child = right;
                            }
                            if (q->cmp(val, q->items[child]) == 0) {
                                break;
                            }
                            q->items[pos] = q->items[child];
                            pos = child;
                            child = pos * 2 + 1;
                        }
                    } while (child < 0);
                }
                q->items[pos] = val;
            }
        }
    }
    h = 0;
    if (m->active && m->cur >= 0) {
        h = &m->heaps[m->cur];
    }
    if (h != 0) {
        s32 i;
        for (i = 0; i < h->count; i++) {
            Pool_006D1BF8 *pool = m->pool;
            u8 *p = h->items[i];
            *(u8 **)(p + pool->link) = pool->head;
            pool->head = p;
            pool->free++;
        }
        h->count = 0;
    }
    m->cur = idx;
    m->f46C = m->f468;
    m->f464 = 0;
}
/* localdecomp:end func_L39_006D1BF8 */

/* localdecomp:start func_L39_006D2030 */
typedef struct {
    u16 f00;
    u8 pad02[0x16];
    s32 f18;
    s32 f1C;
    s32 f20;
    s32 f24;
} Loc_006D2030;
typedef struct {
    u8 pad0[0x494];
    s32 f494;
    s32 f498;
    u8 f49C;
    u8 pad49D[7];
    u8 f4A4;
    u8 pad4A5[3];
    s32 f4A8;
    u8 pad4AC[4];
    s32 f4B0;
} S_006D2030;
extern u16 D_L39_00249C18[];
extern u8 D_00197948[];
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_0014B008(void *);
extern s32 func_0017D908(void *, u8 *, s32);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);

s32 func_L39_006D2030(S_006D2030 *p, s32 a, s32 b, s32 c) {
    s32 r = 1;
    Loc_006D2030 loc;
    u8 buf[0x10];

    if (p->f49C != 0) {
        p->f498 = b;
        p->f494 = a;
        loc.f00 = D_L39_00249C18[0];
        loc.f18 = a;
        loc.f1C = b;
        loc.f20 = c;
        loc.f24 = p->f4B0;
        p->f4A4 = 1;
        p->f4A8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
        func_0014B008(buf);
        func_001961E8(func_0017D908(&loc, D_00197948, 0));
        if (func_001961F8() != 0) {
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006D2030 */

/* localdecomp:start func_L39_006D20E8 */
/* from func_L39_006D25E0 / func_L39_006D2AC0 (same file), offsets changed. */
__asm__(".extern D_L39_0024D760, 16");
typedef struct Heap_006D20E8 {
    s32 (*cmp)(void *, void *);
    s32 count;
    void **items;
} Heap_006D20E8;
typedef struct Pool_006D20E8 {
    u8 pad0[0xC];
    s32 link;
    u8 pad10[8];
    s32 free;
    u8 *head;
} Pool_006D20E8;
typedef struct Mgr_006D20E8 {
    u8 pad0[0x49C];
    u8 active;
    u8 pad49D[3];
    s32 cur;
    u8 f4A4;
    u8 pad4A5[3];
    s32 f4A8;
    s32 f4AC;
    s32 max;
    Heap_006D20E8 heaps[1];
    u8 pad4C0[0x4CC - 0x4C0];
    Pool_006D20E8 *pool;
} Mgr_006D20E8;
typedef struct Blk_006D20E8 {
    s32 b[0x12];
} Blk_006D20E8;
typedef struct Msg_006D20E8 {
    u8 pad0[0x40];
    s32 type;
    u8 f44;
} Msg_006D20E8;
extern void func_0011D534(void *, s32, s32);

void func_L39_006D20E8(Msg_006D20E8 *arg0) {
    u8 *g = D_L39_0024D760;
    Mgr_006D20E8 *m = *(Mgr_006D20E8 **)(g + 0x38);
    Heap_006D20E8 *q;
    Heap_006D20E8 *h;
    s32 idx;
    s32 one;
    s32 zero;

    if (!m->active) {
        return;
    }
    if (g[0x1D] != 0) {
        return;
    }
    one = 1;
    zero = 0;
    idx = m->cur == 0 ? one : zero;
    q = &m->heaps[idx];
    if (arg0->type == 0) {
        if (q->count < m->max) {
            Pool_006D20E8 *pool = m->pool;
            u8 *h = pool->head;
            u8 *p;
            if (h != 0) {
                pool->head = *(u8 **)(h + pool->link);
                pool->free--;
            }
            p = h;
            if (p != 0) {
                s32 i;
                *(Blk_006D20E8 *)p = *(Blk_006D20E8 *)arg0;
                i = q->count++;
                q->items[i] = p;
                if (q->cmp != 0) {
                    s32 parent = i / 2;
                    while (i > 0 && (u8)q->cmp(q->items[parent], q->items[i])) {
                        void *t = q->items[parent];
                        q->items[parent] = q->items[i];
                        q->items[i] = t;
                        i = parent;
                    }
                }
            }
        }
    } else if (arg0->type != 1) {
        if (arg0->f44 != 0) {
            func_0011D534(arg0, 0, 0x48);
            arg0->f44 = 1;
        } else {
            func_0011D534(arg0, 0, 0x48);
        }
    } else {
        arg0->f44 = 1;
    }
    if (arg0->f44 == 0) {
        return;
    }
    if (q->cmp != 0 && q->count >= 2) {
        s32 k;
        for (k = q->count - 1; k > 0; k--) {
            void *t = q->items[k];
            q->items[k] = q->items[0];
            q->items[0] = t;
            if (q->cmp != 0) {
                s32 pos = k;
                void *val = q->items[k];
                s32 child = pos * 2 + 1;
                if (child < 0) {
                    do {
                        s32 right = child + 1;
                        if (right < 0) {
                            if ((u8)q->cmp(q->items[child], q->items[right])) {
                                child = right;
                            }
                            if (q->cmp(val, q->items[child]) == 0) {
                                break;
                            }
                            q->items[pos] = q->items[child];
                            pos = child;
                            child = pos * 2 + 1;
                        }
                    } while (child < 0);
                }
                q->items[pos] = val;
            }
        }
    }
    h = 0;
    if (m->active && m->cur >= 0) {
        h = &m->heaps[m->cur];
    }
    if (h != 0) {
        s32 i;
        for (i = 0; i < h->count; i++) {
            Pool_006D20E8 *pool = m->pool;
            u8 *p = h->items[i];
            *(u8 **)(p + pool->link) = pool->head;
            pool->head = p;
            pool->free++;
        }
        h->count = 0;
    }
    m->cur = idx;
    m->f4AC = m->f4A8;
    m->f4A4 = 0;
}
/* localdecomp:end func_L39_006D20E8 */

/* localdecomp:start func_L39_006D2500 */
typedef struct {
    u8 pad0[0x4D4];
    u8 f4D4;
    u8 pad1[3];
    s32 f4D8;
    u8 f4DC;
    u8 pad2[7];
    u8 f4E4;
    u8 pad3[3];
    s32 f4E8;
    s32 f4EC_unused;
    s32 f4F0;
} S_006D2500;
typedef struct {
    u8 pad0[0x50];
    s32 f50;
} G_006D2500;
typedef struct {
    s32 f00;
    u8 pad[0x24];
} Pad_006D2500;
typedef struct {
    u16 f00;
    u8 pad02[0x13];
    u8 name[0x10];
    s32 f28;
    s32 f2C;
    s32 f30;
    s32 f34;
    s32 f38;
} Loc_006D2500;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_0014B008(void *);
extern void *func_0017D678(void *, void *, s32);
extern s32 func_001961F8(void);
extern u16 D_L39_00249C18[];
extern u8 D_00197858[];
__asm__(".extern D_L39_0024D760, 16");

s32 func_L39_006D2500(S_006D2500 *arg0, s32 arg1, s32 arg2) {
    s32 r = 1;
    Loc_006D2500 loc;
    u8 buf[0x10];
    s32 x;

    if (arg0->f4DC != 0) {
        x = ((G_006D2500 *)D_L39_0024D760)->f50;
        arg0->f4D8 = arg2;
        arg0->f4D4 = arg1;
        loc.f00 = D_L39_00249C18[0];
        func_001206F4((u8 *)&loc + 0x15, (void *)x);
        loc.f28 = *(s32 *)arg0;
        loc.f30 = arg0->f4F0;
        loc.f34 = arg0->f4D8;
        arg0->f4E4 = 1;
        loc.f2C = 1;
        loc.f38 = arg1;
        arg0->f4E8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
        func_0014B008(buf);
        func_001961E8((s32)func_0017D678(&loc, D_00197858, 0));
        if (func_001961F8() != 0) {
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006D2500 */

/* localdecomp:start func_L39_006D25E0 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct Heap_006D25E0 {
    s32 (*cmp)(void *, void *);
    s32 count;
    void **items;
} Heap_006D25E0;
typedef struct Pool_006D25E0 {
    u8 pad0[0xC];
    s32 link;
    u8 pad10[8];
    s32 free;
    u8 *head;
} Pool_006D25E0;
typedef struct Mgr_006D25E0 {
    u8 pad0[0x4DC];
    u8 active;
    u8 pad4DD[3];
    s32 cur;
    u8 f4E4;
    u8 pad4E5[3];
    s32 f4E8;
    s32 f4EC;
    s32 max;
    Heap_006D25E0 heaps[1];
    u8 pad500[0x50C - 0x500];
    Pool_006D25E0 *pool;
} Mgr_006D25E0;
typedef struct Blk_006D25E0 {
    s32 b[0x71];
} Blk_006D25E0;
typedef struct Msg_006D25E0 {
    u8 pad0[0x18];
    s32 type;
    u8 pad1C[0x1BC - 0x1C];
    u8 f1BC;
} Msg_006D25E0;
extern void func_0011D534(void *, s32, s32);

void func_L39_006D25E0(Msg_006D25E0 *arg0) {
    u8 *g = D_L39_0024D760;
    Mgr_006D25E0 *m = *(Mgr_006D25E0 **)(g + 0x38);
    Heap_006D25E0 *q;
    Heap_006D25E0 *h;
    s32 idx;
    s32 one;
    s32 zero;

    if (!m->active) {
        return;
    }
    if (g[0x1D] != 0) {
        return;
    }
    one = 1;
    zero = 0;
    idx = m->cur == 0 ? one : zero;
    q = &m->heaps[idx];
    if (arg0->type == 0) {
        if (q->count < m->max) {
            Pool_006D25E0 *pool = m->pool;
            u8 *h = pool->head;
            u8 *p;
            if (h != 0) {
                pool->head = *(u8 **)(h + pool->link);
                pool->free--;
            }
            p = h;
            if (p != 0) {
                s32 i;
                *(Blk_006D25E0 *)p = *(Blk_006D25E0 *)arg0;
                i = q->count++;
                q->items[i] = p;
                if (q->cmp != 0) {
                    s32 parent = i / 2;
                    while (i > 0 && (u8)q->cmp(q->items[parent], q->items[i])) {
                        void *t = q->items[parent];
                        q->items[parent] = q->items[i];
                        q->items[i] = t;
                        i = parent;
                    }
                }
            }
        }
    } else if (arg0->type != 1) {
        if (arg0->f1BC != 0) {
            func_0011D534(arg0, 0, 0x1C4);
            arg0->f1BC = 1;
        } else {
            func_0011D534(arg0, 0, 0x1C4);
        }
    } else {
        arg0->f1BC = 1;
    }
    if (arg0->f1BC == 0) {
        return;
    }
    if (q->cmp != 0 && q->count >= 2) {
        s32 k;
        for (k = q->count - 1; k > 0; k--) {
            void *t = q->items[k];
            q->items[k] = q->items[0];
            q->items[0] = t;
            if (q->cmp != 0) {
                s32 pos = k;
                void *val = q->items[k];
                s32 child = pos * 2 + 1;
                if (child < 0) {
                    do {
                        s32 right = child + 1;
                        if (right < 0) {
                            if ((u8)q->cmp(q->items[child], q->items[right])) {
                                child = right;
                            }
                            if (q->cmp(val, q->items[child]) == 0) {
                                break;
                            }
                            q->items[pos] = q->items[child];
                            pos = child;
                            child = pos * 2 + 1;
                        }
                    } while (child < 0);
                }
                q->items[pos] = val;
            }
        }
    }
    h = 0;
    if (m->active && m->cur >= 0) {
        h = &m->heaps[m->cur];
    }
    if (h != 0) {
        s32 i;
        for (i = 0; i < h->count; i++) {
            Pool_006D25E0 *pool = m->pool;
            u8 *p = h->items[i];
            *(u8 **)(p + pool->link) = pool->head;
            pool->head = p;
            pool->free++;
        }
        h->count = 0;
    }
    m->cur = idx;
    m->f4EC = m->f4E8;
    m->f4E4 = 0;
}
/* localdecomp:end func_L39_006D25E0 */

/* localdecomp:start func_L39_006D29F0 */
typedef struct S_6D29F0 {
    s32 f0;
    u8 pad4[0x510];
    u8 f514;
    u8 f515;
    u8 pad516[6];
    u8 f51C;
    u8 pad51D[3];
    s32 f520;
    u8 pad524[4];
    s32 f528;
} S_6D29F0;
typedef struct S_6D29F0_G {
    u8 pad0[0x50];
    void *f50;
} S_6D29F0_G;
extern u16 D_L39_00249C18[];
extern u8 D_00197880[];
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern void func_0014B008(void *);
extern s32 func_0017D800(void *, u8 *, s32);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);

s32 func_L39_006D29F0(S_6D29F0 *arg0, s32 arg1) {
    s32 r = 1;
    struct { u16 x[1]; u8 pad2[0x13]; u8 buf[0x13]; s32 a; s32 b; s32 c; s32 d; u8 pad3[8]; u8 e[0x10]; } l;

    if (arg0->f515 != 0) {
        void *name = ((S_6D29F0_G *)D_L39_0024D760)->f50;
        arg0->f514 = arg1;
        l.x[0] = D_L39_00249C18[0];
        func_001206F4(l.buf, name);
        arg0->f51C = 1;
        l.a = arg0->f0;
        l.b = arg0->f514;
        l.c = 1;
        l.d = arg0->f528;
        arg0->f520 = (s32) func_00130760(func_0012DCB0(), 0x24000);
        func_0014B008(l.e);
        func_001961E8(func_0017D800(&l, D_00197880, 0));
        if (func_001961F8() != 0) {
            r = 0;
        }
    }
    return r;
}
/* localdecomp:end func_L39_006D29F0 */

/* localdecomp:start func_L39_006D2AC0 */
__asm__(".extern D_L39_0024D760, 16");
typedef s32 (*Cmp_006D2AC0)(void *, void *);
typedef struct Heap_006D2AC0 {
    Cmp_006D2AC0 cmp;
    s32 count;
    void **items;
} Heap_006D2AC0;
typedef struct Pool_006D2AC0 {
    u8 pad0[0xC];
    s32 link;
    u8 pad10[8];
    s32 free;
    u8 *head;
} Pool_006D2AC0;
typedef struct Mgr_006D2AC0 {
    u8 pad0[0x515];
    u8 active;
    u8 pad516[2];
    s32 cur;
    u8 f51C;
    u8 pad51D[3];
    s32 f520;
    s32 f524;
    s32 max;
    Heap_006D2AC0 heaps[1];
    u8 pad538[0x544 - 0x538];
    Pool_006D2AC0 *pool;
} Mgr_006D2AC0;
typedef struct Blk_006D2AC0 {
    u8 b[0x28];
} __attribute__((packed)) Blk_006D2AC0;
typedef struct Msg_006D2AC0 {
    u8 pad0[0x18];
    s32 type;
    u8 pad1C[0x24 - 0x1C];
    u8 f24;
} Msg_006D2AC0;
extern void func_0011D534(void *, s32, s32);

void func_L39_006D2AC0(Msg_006D2AC0 *arg0) {
    u8 *g = D_L39_0024D760;
    Mgr_006D2AC0 *m = *(Mgr_006D2AC0 **)(g + 0x38);
    Heap_006D2AC0 *q;
    Heap_006D2AC0 *h;
    s32 idx;
    s32 one;
    s32 zero;

    if (!m->active) {
        return;
    }
    if (g[0x1D] != 0) {
        return;
    }
    one = 1;
    zero = 0;
    idx = m->cur == 0 ? one : zero;
    q = &m->heaps[idx];
    if (arg0->type == 0) {
        if (q->count < m->max) {
            Pool_006D2AC0 *pool = m->pool;
            u8 *h = pool->head;
            u8 *p;
            if (h != 0) {
                pool->head = *(u8 **)(h + pool->link);
                pool->free--;
            }
            p = h;
            if (p != 0) {
                s32 i;
                *(Blk_006D2AC0 *)p = *(Blk_006D2AC0 *)arg0;
                i = q->count++;
                q->items[i] = p;
                if (q->cmp != 0) {
                    s32 parent = i / 2;
                    while (i > 0 && (u8)q->cmp(q->items[parent], q->items[i])) {
                        void *t = q->items[parent];
                        q->items[parent] = q->items[i];
                        q->items[i] = t;
                        i = parent;
                    }
                }
            }
        }
    } else if (arg0->type != 1) {
        if (arg0->f24 != 0) {
            func_0011D534(arg0, 0, 0x28);
            arg0->f24 = 1;
        } else {
            func_0011D534(arg0, 0, 0x28);
        }
    } else {
        arg0->f24 = 1;
    }
    if (arg0->f24 == 0) {
        return;
    }
    if (q->cmp != 0 && q->count >= 2) {
        s32 k;
        for (k = q->count - 1; k > 0; k--) {
            void *t = q->items[k];
            q->items[k] = q->items[0];
            q->items[0] = t;
            if (q->cmp != 0) {
                s32 pos = k;
                void *val = q->items[k];
                s32 child = pos * 2 + 1;
                if (child < 0) {
                    do {
                        s32 right = child + 1;
                        if (right < 0) {
                            if ((u8)q->cmp(q->items[child], q->items[right])) {
                                child = right;
                            }
                            if (q->cmp(val, q->items[child]) == 0) {
                                break;
                            }
                            q->items[pos] = q->items[child];
                            pos = child;
                            child = pos * 2 + 1;
                        }
                    } while (child < 0);
                }
                q->items[pos] = val;
            }
        }
    }
    h = 0;
    if (m->active && m->cur >= 0) {
        h = &m->heaps[m->cur];
    }
    if (h != 0) {
        s32 i;
        for (i = 0; i < h->count; i++) {
            Pool_006D2AC0 *pool = m->pool;
            u8 *p = h->items[i];
            *(u8 **)(p + pool->link) = pool->head;
            pool->head = p;
            pool->free++;
        }
        h->count = 0;
    }
    m->cur = idx;
    m->f524 = m->f520;
    m->f51C = 0;
}
/* localdecomp:end func_L39_006D2AC0 */

/* localdecomp:start func_L39_006D2E80 */
extern void func_00196F18(s32, u8 *);

void func_L39_006D2E80(s32 arg0, s32 arg1) {
    u8 buf[0x100];

    func_L39_006CECA0(buf, (s32 *)arg1);
    func_00196F18(*(s32 *)arg0, buf);
}
/* localdecomp:end func_L39_006D2E80 */

/* localdecomp:start func_L39_006D2EB8 */
void func_00120D28(s32, s32, s32);
void func_L39_006D2E80(s32, s32);

void func_L39_006D2EB8(s32 arg0, s32 arg1) {
    func_00120D28(arg0 + 0x30, arg1, 4);
    func_L39_006D2E80(arg0, arg0 + 0x28);
}
/* localdecomp:end func_L39_006D2EB8 */

/* localdecomp:start func_L39_006D2EF0 */
void func_L39_006D2E80(s32, s32);
void func_L39_006D2EF0(void *arg0, s32 arg1, s32 arg2) {
    *(s32 *)((u8 *)arg0 + 0x28) = arg1;
    *(s32 *)((u8 *)arg0 + 0x2C) = arg2;
    func_L39_006D2E80((s32) arg0, (s32) (arg0 + 0x28));
}
/* localdecomp:end func_L39_006D2EF0 */

INCLUDE_ASM("asm/levels", func_L39_006D2F18);

/* localdecomp:start func_L39_006D2FA0 */
typedef struct {
    u16 f00;
    char _p02[0x15 - 0x02];
    u8 f15[0x28 - 0x15];
    s32 f28;
    u8 f2C[0x20];
    char _p4C[0x50 - 0x4C];
} Loc_006D2FA0;
typedef struct {
    char _p0[0x1];
    u8 f1;
    char _p2[0x8 - 0x2];
    s32 f8;
    char _pC[0x10 - 0xC];
    s32 f10;
    s32 f14;
    char _p18[0x1C - 0x18];
    u8 f1C;
    char _p1D[0x50 - 0x1D];
    void *f50;
} G_006D2FA0;
typedef struct {
    char _p0[0xD4];
    u8 fD4;
    char _pD5[0xD8 - 0xD5];
    u8 fD8[0xF0 - 0xD8];
    s32 fF0;
} S_006D2FA0;
typedef struct {
    char _p0[0x2DC];
    s32 f2DC;
} P_006D2FA0;

__asm__(".extern D_L39_0024D760, 16");
extern s32 func_00183BDC(void);
extern void func_L39_005958A0(s32, s32, s32);
extern s32 func_0017CE78(void *, void *, s32);
extern void func_00197740(void);
extern void func_00195410(void);
extern u8 D_001A5CD0[];

void *func_L39_006D2FA0(S_006D2FA0 *arg0, void *arg1) {
    Loc_006D2FA0 loc;
    G_006D2FA0 *g;
    P_006D2FA0 *p;
    s32 r;
    void *t;

    g = D_L39_0024D760;
    t = g->f50;
    loc.f00 = D_L39_00249C18[0];
    func_001206F4(loc.f15, t);
    loc.f28 = func_00183BDC();
    func_L39_005958A0((s32)loc.f2C, (s32)arg1, 0x20);
    arg0->fD4 = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017CE78(&loc, func_00197740, 0));
    p = (P_006D2FA0 *)D_001A5CD0;
    while (arg0->fD4 != 0) {
        if (func_001961F8() != 0 || p->f2DC != 0) {
            g->f10 = 0x26;
            if (g->f14 == 0) {
                g->f14 = 0x26;
            }
            r = 0;
            break;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if (func_L39_006D8AD8((u8 *)g) == 0) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    arg0->fD4 = 0;
    if (r != 0) {
        if (arg0->fF0 != 0) {
            r = 0;
        }
    }
    return r ? arg0->fD8 : 0;
}
/* localdecomp:end func_L39_006D2FA0 */

/* localdecomp:start func_L39_006D30F8 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct { u8 bytes[0x148]; } __attribute__((packed)) Block_006D30F8;
typedef struct { u8 pad[0xD4]; u8 fD4; u8 pad2[3]; Block_006D30F8 fD8; } Target_006D30F8;
typedef struct { u8 pad[0x38]; Target_006D30F8 *p; } Global_006D30F8;

void func_L39_006D30F8(Block_006D30F8 *arg0) {
    Target_006D30F8 *t = ((Global_006D30F8 *)D_L39_0024D760)->p;
    t->fD4 = 0;
    t->fD8 = *arg0;
}
/* localdecomp:end func_L39_006D30F8 */

/* localdecomp:start func_L39_006D31B8 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x13];
    s32 f28;
    s32 f2C;
} Loc_006D31B8;
typedef struct {
    u8 pad0[0x220];
    u8 f220;
    u8 pad221[3];
    u8 f224[0x18];
    s32 f23C;
} S_006D31B8;
typedef struct {
    u8 f0;
    u8 f1;
    u8 pad2[6];
    s32 f8;
    u8 padC[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
    u8 pad1D[0x33];
    void *f50;
} G_006D31B8;
typedef struct {
    u8 pad[0x2DC];
    s32 f2DC;
} P_006D31B8;
extern u8 D_00197768[];
extern u8 D_001A5CD0[];
extern s32 func_0017CEF8(void *, u8 *, s32);
extern void func_00195410(void);
extern s32 func_L39_006D8AD8(u8 *);

/* follows func_L39_006DCAD0 */
void *func_L39_006D31B8(S_006D31B8 *arg0, s32 arg1, s32 arg2) {
    G_006D31B8 *g = D_L39_0024D760;
    P_006D31B8 *p;
    s32 r;
    Loc_006D31B8 loc;
    void *t;
    s32 one;

    t = g->f50;
    loc.f0 = D_L39_00249C18[0];
    func_001206F4(loc.f15, t);
    loc.f28 = arg1;
    loc.f2C = arg2;
    arg0->f220 = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017CEF8(&loc, D_00197768, 0));
    p = (P_006D31B8 *)D_001A5CD0;
    while (arg0->f220 != 0) {
        if (func_001961F8() != 0 || p->f2DC != 0) {
            g->f10 = 0x27;
            if (g->f14 == 0) {
                g->f14 = 0x27;
            }
            r = 0;
            break;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if (func_L39_006D8AD8((u8 *)g) == 0) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    arg0->f220 = 0;
    if (r != 0) {
        if (arg0->f23C != 0) {
            g->f10 = 0x27;
            if (g->f14 == 0) {
                g->f14 = 0x27;
            }
            r = 0;
        }
    }
    return r != 0 ? arg0->f224 : 0;
}
/* localdecomp:end func_L39_006D31B8 */

/* localdecomp:start func_L39_006D3318 */
typedef struct { u8 bytes[0x168]; } __attribute__((packed)) Block_6D3318;
typedef struct { u8 pad[0x220]; u8 f220; u8 pad221[3]; Block_6D3318 f224; } Target_6D3318;
typedef struct { u8 pad[0x38]; Target_6D3318 *f38; } Global_6D3318;
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;

void func_L39_006D3318(Block_6D3318 *arg) {
    Target_6D3318 *t = ((Global_6D3318 *)D_L39_0024D760)->f38;
    t->f220 = 0;
    t->f224 = *arg;
}
/* localdecomp:end func_L39_006D3318 */

INCLUDE_ASM("asm/levels", func_L39_006D33D8);

/* localdecomp:start func_L39_006D3440 */
void *func_L39_006D3440(void *arg0) {
    (*(s8 *)arg0) = 0;
    *(s8 *)((u8 *)arg0 + 1) = 0;
    *(s8 *)((u8 *)arg0 + 2) = 0;
    *(s8 *)((u8 *)arg0 + 3) = 0;
    *(s8 *)((u8 *)arg0 + 4) = 0;
    *(s32 *)((u8 *)arg0 + 8) = 0;
    *(s32 *)((u8 *)arg0 + 0xC) = 0;
    *(s8 *)((u8 *)arg0 + 0x10) = 0;
    *(s8 *)((u8 *)arg0 + 0x11) = 0;
    *(s8 *)((u8 *)arg0 + 0x12) = 0;
    *(s8 *)((u8 *)arg0 + 0x13) = 0;
    *(s32 *)((u8 *)arg0 + 0x14) = 0;
    *(s32 *)((u8 *)arg0 + 0x18) = 0;
    *(s8 *)((u8 *)arg0 + 0x20) = 0;
    *(s32 *)((u8 *)arg0 + 0x3FC) = 0;
    *(s32 *)((u8 *)arg0 + 0xD20) = 0;
    *(s32 *)((u8 *)arg0 + 0x1644) = 0;
    return arg0;
}
/* localdecomp:end func_L39_006D3440 */

/* localdecomp:start func_L39_006D3490 */
typedef struct S_006D3490 {
    u8 f0, f1, f2, f3, f4;
    s32 f8, fC;
    u8 f10, f11, f12, f13;
    s32 f14, f18;
    u8 f1C[4];
    u8 f20;
    u8 pad21[0x3DB];
    s32 f3FC;
    u8 pad400[0x920];
    s32 fD20;
    u8 padD24[0x920];
    s32 f1644;
} S_006D3490;

void func_L39_006D3490(S_006D3490 *o) {
    o->f0 = 0;
    o->f1 = 0;
    o->f2 = 0;
    o->f3 = 0;
    o->f4 = 0;
    o->f8 = 0;
    o->fC = 0;
    o->f10 = 0;
    o->f11 = 0;
    o->f12 = 0;
    o->f13 = 0;
    o->f14 = 0;
    o->f18 = 0;
    o->f20 = 0;
    o->f3FC = 0;
    o->fD20 = 0;
    o->f1644 = 0;
}
/* localdecomp:end func_L39_006D3490 */

INCLUDE_ASM("asm/levels", func_L39_006D34D8);

/* localdecomp:start func_L39_006D3950 */
typedef struct { s32 w[0x2F]; } Block_6D3950;
typedef struct { u8 flag; u8 pad[0x27]; Block_6D3950 block; } Target_6D3950;
typedef struct { u8 pad[0x3C]; Target_6D3950 *target; } Context_6D3950;
__asm__(".extern D_L39_0024D760, 16");

void func_L39_006D3950(Block_6D3950 *source) {
    Target_6D3950 *target = ((Context_6D3950 *)D_L39_0024D760)->target;
    target->block = *source;
    target->flag = 0;
}
/* localdecomp:end func_L39_006D3950 */

INCLUDE_ASM("asm/levels", func_L39_006D3A30);

/* localdecomp:start func_L39_006D4018 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct {
    char _p0[0x3C];
    s8 *f3C;
} S_6D4018;

/* from rac4-decomp's func_L00_0076F1E0 */
void func_L39_006D4018(void) {
    ((S_6D4018 *)D_L39_0024D760)->f3C[1] = 0;
}
/* localdecomp:end func_L39_006D4018 */

/* localdecomp:start func_L39_006D4030 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct {
    char _p0[0x10];
    s32 f10;
    s32 f14;
    char _p18[0x24];
    s8 *f3C;
} S_006D4030;
typedef struct {
    char _p0[0x18];
    s32 f18;
    s32 f1C;
} A_006D4030;
void func_0019B5B8(s32);
void func_0019B798(s32);

void func_L39_006D4030(A_006D4030 *arg) {
    S_006D4030 *g = (S_006D4030 *)D_L39_0024D760;
    s8 *p = g->f3C;
    s32 k = arg->f18;

    if (k != 0) {
        switch (k) {
        case -0x3CF:
            g->f10 = 0x2B;
            if (g->f14 == 0) {
                g->f14 = 0x2B;
            }
            break;
        case -0x3C7:
            g->f10 = 3;
            if (g->f14 == 0) {
                g->f14 = 3;
            }
            break;
        default:
            g->f10 = 0x2A;
            if (g->f14 == 0) {
                g->f14 = 0x2A;
            }
            break;
        }
    } else {
        func_0019B5B8(arg->f1C);
        func_0019B798(1);
    }
    p[1] = 0;
}
/* localdecomp:end func_L39_006D4030 */

/* localdecomp:start func_L39_006D40B0 */
typedef struct S_6D40B0_G {
    u8 pad0[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0x38];
    void *f50;
} S_6D40B0_G;
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern void *func_001206F4(void *, void *);
extern void func_00196038(void);
extern void func_0019B798(s32);
extern void func_0019B5B8(s32);
extern s32 func_0017E310(void *);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);

s32 func_L39_006D40B0(void) {
    S_6D40B0_G *g = (S_6D40B0_G *)D_L39_0024D760;
    void *name = g->f50;
    s32 r = 1;
    struct { u8 pad[0x14]; s32 mode; } l;

    func_00196038();
    func_0019B798(0);
    func_0019B5B8(-1);
    func_001206F4(&l, name);
    l.mode = 2;
    func_001961E8(func_0017E310(&l));
    if (func_001961F8() != 0) {
        g->f10 = 4;
        if (g->f14 == 0) {
            g->f14 = 4;
        }
        r = 0;
    }
    l.mode = 1;
    func_001961E8(func_0017E310(&l));
    if (func_001961F8() != 0) {
        g->f10 = 4;
        if (g->f14 == 0) {
            g->f14 = 4;
        }
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L39_006D40B0 */

/* localdecomp:start func_L39_006D4188 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x13];
    s32 f28;
    u8 pad2C[4];
} S_006D4188;
typedef struct {
    u8 pad0;
    u8 f1;
    u8 pad2[6];
    s32 f8;
    u8 padC[4];
    s32 f10;
    s32 f14;
    u8 pad18[0x38];
    void *f50;
} G_006D4188;
extern u16 D_L39_00249C78[];
extern u8 D_00197BF0[];
extern void *func_001206F4(void *, void *);
s32 func_0019B5C8(void);
extern s32 func_0017EAB8(void *, u8 *, s32);

s32 func_L39_006D4188(u8 *arg0) {
    G_006D4188 *g;
    s32 r = 1;
    S_006D4188 x;

    x.f0 = D_L39_00249C78[0];
    g = (G_006D4188 *)D_L39_0024D760;
    func_001206F4(x.f15, g->f50);
    x.f28 = func_0019B5C8();
    arg0[3] = 1;
    *(s32 *)(arg0 + 0xC) = (s32) func_00130760(func_0012DCB0(), 0x24000);
    g->f1 = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017EAB8(&x, D_00197BF0, 0));
    if (func_001961F8() != 0) {
        g->f10 = 0x2E;
        if (g->f14 == 0) {
            g->f14 = 0x2E;
        }
        r = 0;
    }
    g->f1 = 0;
    return r;
}
/* localdecomp:end func_L39_006D4188 */

/* localdecomp:start func_L39_006D4278 */
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
typedef struct { s32 w[0x18C / 4]; } S_006D4278_blk;
typedef struct {
    u8 pad0[2];
    u8 b2;
    u8 b3;
    u8 pad4[8];
    s32 wC;
    u8 pad10[0xE4 - 0x10];
    S_006D4278_blk blk;
} S_006D4278_t;
typedef struct { u8 pad[0x3C]; S_006D4278_t *f3C; } S_006D4278_g;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);

void func_L39_006D4278(S_006D4278_blk *arg)
{
    S_006D4278_t *t = ((S_006D4278_g *)D_L39_0024D760)->f3C;
    t->b3 = 0;
    t->blk = *arg;
    t->wC = (s32)func_00130760(func_0012DCB0(), 0x24000);
    t->b2 = 1;
}
/* localdecomp:end func_L39_006D4278 */

/* localdecomp:start func_L39_006D4380 */
typedef struct {
    u8 pad0[2];
    u8 f2;
    u8 pad3[0xD];
    u8 f10;
    u8 pad11[0x25F];
    u8 f270[0x18];
    s32 f288;
} S_006D4380;
typedef struct {
    u8 f0;
    u8 f1;
    u8 pad2[6];
    s32 f8;
    u8 padC[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
    u8 pad1D[0x33];
    void *f50;
} S_006D4380_G;
extern u16 D_L39_00249C78[];
extern u8 D_00197B00[];
typedef struct { u8 pad[0x2DC]; s32 f2DC; } S_006D4380_D;
extern u8 D_001A5CD0[];
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void *func_001206F4(void *, void *);
extern s32 func_0017EAB8(void *, u8 *, s32);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);
extern void func_00195410(void);

u8 *func_L39_006D4380(S_006D4380 *arg0, s32 arg1) {
    S_006D4380_G *g = (S_006D4380_G *)D_L39_0024D760;
    s32 r;
    struct { u16 x[1]; u8 pad2[0x13]; u8 buf[0x13]; s32 a; u8 pad3[0x4]; } l;

    arg0->f2 = 0;
    l.x[0] = D_L39_00249C78[0];
    func_001206F4(l.buf, g->f50);
    l.a = arg1;
    g->f1 = arg0->f10 = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017EAB8(&l, D_00197B00, 0));
    r = 1;
    while (arg0->f10 != 0) {
        if (func_001961F8() != 0 || ((S_006D4380_D *)D_001A5CD0)->f2DC != 0) {
            g->f10 = 0x2E;
            if (g->f14 == 0) {
                g->f14 = 0x2E;
            }
            r = 0;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if (func_L39_006D8AD8((u8 *)g) == 0) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    arg0->f10 = 0;
    if (r != 0) {
        s32 e = arg0->f288;
        s32 c;

        if (e == -0x3DF || e == -0x3D1) {
            c = 0x35;
            goto set;
        }
        if (e != 0) {
            c = 0x2E;
        set:
            g->f10 = c;
            if (g->f14 == 0) {
                g->f14 = c;
            }
            r = 0;
        }
    }
    return r ? arg0->f270 : 0;
}
/* localdecomp:end func_L39_006D4380 */

/* localdecomp:start func_L39_006D44F0 */
typedef struct { u8 bytes[0x188]; } __attribute__((packed)) Part_6D44F0;
typedef struct { Part_6D44F0 a; s32 b; } Block_6D44F0;
typedef struct { u8 pad[2]; u8 f2; u8 pad3[0xD]; u8 f10; u8 pad11[0x25F]; Block_6D44F0 f270; } Target_6D44F0;
typedef struct { u8 pad[0x3C]; Target_6D44F0 *f3C; } Global_6D44F0;
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;

void func_L39_006D44F0(Block_6D44F0 *arg) {
    Target_6D44F0 *t = ((Global_6D44F0 *)D_L39_0024D760)->f3C;
    t->f270 = *arg;
    t->f2 = 1;
    t->f10 = 0;
}
/* localdecomp:end func_L39_006D44F0 */

/* localdecomp:start func_L39_006D45B8 */
typedef struct S_6D45B8 {
    u8 pad0[0x12];
    u8 f12;
    u8 pad13[5];
    s32 f18;
} S_6D45B8;
typedef struct S_6D45B8_G {
    u8 pad0[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0x38];
    s32 f50;
} S_6D45B8_G;
extern u16 D_L39_00249C78[];
extern u8 D_00197C18[];
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_0019B5C8(void);
extern s32 func_0017E9B8(u16 *, u8 *, s32);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);

s32 func_L39_006D45B8(u8 *arg0) {
    S_6D45B8 *p = (S_6D45B8 *)arg0;
    S_6D45B8_G *g = (S_6D45B8_G *)D_L39_0024D760;
    s32 r = 1;
    struct { u16 x[1]; u8 pad2[0x13]; u8 buf[0x13]; s32 v; } l;

    *(s32 *)(arg0 + 0xD20) = 0;
    l.x[0] = D_L39_00249C78[0];
    func_001206F4(l.buf, (void *)g->f50);
    l.v = func_0019B5C8();
    p->f12 = 1;
    p->f18 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017E9B8(l.x, D_00197C18, 0));
    if (func_001961F8() != 0) {
        g->f10 = 0x2F;
        if (g->f14 == 0) {
            g->f14 = 0x2F;
        }
        r = 0;
    }
    return r;
}
/* localdecomp:end func_L39_006D45B8 */

/* localdecomp:start func_L39_006D4688 */
typedef struct { u8 b[0x100]; } Blk_006D4688;
typedef struct {
    char name[0x20];
    s32 f20;
    Blk_006D4688 data;
} Rec_006D4688;
typedef struct { Rec_006D4688 r[8]; } Recs_006D4688;
typedef struct {
    u8 _p0[0x11];
    u8 f11;
    u8 f12;
    u8 _p13[0x18 - 0x13];
    s32 f18;
    s32 f1C;
    u8 _p20[0x3FC - 0x20];
    s32 f3FC;
    Recs_006D4688 saved;
    u8 _pD20[0xD20 - 0xD20];
    s32 fD20;
    Recs_006D4688 recs;
} T_006D4688;
typedef struct {
    u8 _p0[0x10];
    s32 f10;
    s32 f14;
    u8 _p18[0x3C - 0x18];
    T_006D4688 *f3C;
} G_006D4688;
typedef struct {
    u8 _p0[0x18];
    s32 f18;
    s32 f1C;
    char name[0x20];
    Blk_006D4688 data;
    u8 _p140[0x144 - 0x140];
    u8 f144;
} A_006D4688;

__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;
extern void func_L39_005958A0(s32, s32, s32);

void func_L39_006D4688(A_006D4688 *a) {
    G_006D4688 *g = (G_006D4688 *)D_L39_0024D760;
    T_006D4688 *t = g->f3C;
    s32 c;

    if (a->f18 == 0) {
        Rec_006D4688 *rec = &t->recs.r[t->fD20++];
        rec->f20 = a->f1C;
        func_L39_005958A0((s32)rec->name, (s32)a->name, 0x20);
        rec->data = a->data;
        if (a->f144 == 1) {
            t->saved = t->recs;
            t->f11 = 1;
            t->f3FC = t->fD20;
            t->f18 = t->f1C;
            t->f12 = 0;
        }
    } else if (a->f18 == 1) {
        t->f11 = 1;
        t->f18 = t->f1C;
        t->f12 = 0;
        t->f3FC = 0;
    } else {
        if (a->f18 == -0x3DF || a->f18 == -0x3D1) {
            t->f11 = 0;
            c = 0x35;
        } else if (a->f18 < 0) {
            t->f11 = 0;
            c = 0x2F;
        } else {
            return;
        }
        t->f12 = 0;
        t->f3FC = 0;
        g->f10 = c;
        if (g->f14 == 0) {
            g->f14 = c;
        }
    }
}
/* localdecomp:end func_L39_006D4688 */

/* localdecomp:start func_L39_006D48C8 */
__asm__(".extern D_L39_0024D760, 16");
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x13];
    s32 f28;
} Loc_006D48C8;
typedef struct {
    u8 pad0;
    u8 f1;
    u8 pad2[6];
    s32 f8;
    u8 padC[4];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
    u8 pad1D[0x33];
    void *f50;
} G_006D48C8;
typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad21[3];
    s32 f24;
    u8 pad28[0x1644 - 0x28];
    s32 f1644;
    u8 f1648[1];
} S_006D48C8;
typedef struct {
    u8 pad0[0x2DC];
    s32 f2DC;
} D_006D48C8;
extern u16 D_L39_00249C78[];
extern u8 D_00197B28[];
extern void *func_001206F4(void *, void *);
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern void func_001961E8(s32);
extern s32 func_001961F8(void);
extern void func_00195410(void);

u8 *func_L39_006D48C8(S_006D48C8 *p, s32 a, s32 *out) {
    G_006D48C8 *g;
    Loc_006D48C8 x;
    D_006D48C8 *d;
    s32 r;
    s32 code;
    u8 *ret;

    g = D_L39_0024D760;
    p->f1644 = 0;
    x.f0 = D_L39_00249C78[0];
    func_001206F4(x.f15, g->f50);
    x.f28 = a;
    p->f20 = 1;
    g->f1 = 1;
    r = 1;
    g->f8 = (s32) func_00130760(func_0012DCB0(), 0x24000);
    func_001961E8(func_0017E9B8((u16 *)&x, D_00197B28, 0));
    d = (D_006D48C8 *)D_001A5CD0;
    while (p->f20) {
        if (func_001961F8() != 0 || d->f2DC != 0) {
            g->f10 = 0x2F;
            if (g->f14 == 0) {
                g->f14 = 0x2F;
            }
            r = 0;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if (!func_L39_006D8AD8((u8 *)g)) {
            r = 0;
            break;
        }
    }
    g->f1 = 0;
    p->f20 = 0;
    code = p->f24;
    if (code == 1) {
        p->f1644 = 0;
    } else if (code == -0x3DF || code == -0x3D1) {
        g->f10 = 0x35;
        if (g->f14 == 0) {
            g->f14 = 0x35;
        }
        r = 0;
    } else if (code < 0) {
        g->f10 = 0x2F;
        if (g->f14 == 0) {
            g->f14 = 0x2F;
        }
        r = 0;
    }
    ret = 0;
    *out = 0;
    if (r) {
        *out = p->f1644;
        ret = p->f1648;
    }
    return ret;
}
/* localdecomp:end func_L39_006D48C8 */

/* localdecomp:start func_L39_006D4A68 */
typedef struct {
    u8 data[0x100];
} Blk_006D4A68;
typedef struct {
    u8 name[0x20];
    s32 f20;
    Blk_006D4A68 blk;
} Ent_006D4A68;
typedef struct {
    u8 pad0[0x20];
    u8 f20;
    u8 pad21[3];
    s32 f24;
    u8 pad28[0x161C];
    s32 count;
    Ent_006D4A68 ents[1];
} Tab_006D4A68;
typedef struct {
    u8 pad0[0x3C];
    Tab_006D4A68 *f3C;
} G_006D4A68;
typedef struct {
    u8 pad0[0x18];
    s32 f18;
    s32 f1C;
    u8 name[0x20];
    Blk_006D4A68 blk;
    u8 pad140[4];
    u8 f144;
} Arg_006D4A68;
extern void func_L39_005958A0(s32, s32, s32);
__asm__(".extern D_L39_0024D760, 16");
extern void *D_L39_0024D760;

void func_L39_006D4A68(Arg_006D4A68 *a) {
    Tab_006D4A68 *t = ((G_006D4A68 *)D_L39_0024D760)->f3C;

    if (a->f18 == 0) {
        Ent_006D4A68 *e = &t->ents[t->count++];
        e->f20 = a->f1C;
        func_L39_005958A0((s32)e, (s32)a->name, 0x20);
        e->blk = a->blk;
        if (a->f144 != 1) {
            return;
        }
    }
    t->f20 = 0;
    t->f24 = a->f18;
}
/* localdecomp:end func_L39_006D4A68 */

/* localdecomp:start func_L39_006D4B98 */
typedef struct S_006D4B98 {
    u8 pad0[3];
    u8 f3;
    u8 f4;
    u8 pad5[3];
    s32 f8;
    s32 fC;
    u8 pad10[2];
    u8 f12;
    u8 f13;
    s32 f14;
    s32 f18;
} S_006D4B98;
typedef struct { u8 pad[0x10]; s32 f10; s32 f14; } G_006D4B98;
extern G_006D4B98 *D_001E2050_sda;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_L39_006D45B8(u8 *);
extern s32 func_L39_006D4188(u8 *);

s32 func_L39_006D4B98(S_006D4B98 *arg0) {
    G_006D4B98 *g = D_001E2050_sda;
    s32 r = 1;

    if (arg0->f12 != 0) {
        if (((s32) func_00130760(func_0012DCB0(), 0x24000) - arg0->f18) >= 0x3A99) {
            g->f10 = 2;
            if (g->f14 == 0) {
                g->f14 = 2;
            }
            arg0->f12 = 0;
            func_L39_006D45B8((u8 *)arg0);
            r = 0;
        }
    } else if (arg0->f13 != 0) {
        if (arg0->f14 < ((s32) func_00130760(func_0012DCB0(), 0x24000) - arg0->f18)) {
            r = func_L39_006D45B8((u8 *)arg0);
        }
    }
    if (arg0->f3 != 0) {
        if (((s32) func_00130760(func_0012DCB0(), 0x24000) - arg0->fC) >= 0x3A99) {
            g->f10 = 2;
            if (g->f14 == 0) {
                g->f14 = 2;
            }
            arg0->f3 = 0;
            func_L39_006D4188((u8 *)arg0);
            r = 0;
        }
    } else if (arg0->f4 != 0) {
        if (arg0->f8 < ((s32) func_00130760(func_0012DCB0(), 0x24000) - arg0->fC)) {
            r = func_L39_006D4188((u8 *)arg0);
        }
    }
    return r;
}
/* localdecomp:end func_L39_006D4B98 */

/* localdecomp:start func_L39_006D4D48 */
typedef struct {
    u8 pad0[3];
    u8 f3;
    u8 pad4[8];
    s32 fC;
    u8 pad10[2];
    u8 f12;
    u8 pad13[5];
    s32 f18;
} T_006D4D48;
typedef struct {
    u8 pad0[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[4];
    u8 f1C;
} G_006D4D48;
typedef struct {
    u8 pad0[0x2DC];
    s32 f2DC;
} P_006D4D48;
extern long func_0012DCB0(void);
extern long func_00130760(long, long);
extern s32 func_001961F8(void);
extern void func_00195410(void);

s32 func_L39_006D4D48(T_006D4D48 *a0) {
    s32 r1 = 1;
    s32 r2;
    G_006D4D48 *g = (G_006D4D48 *)D_001E2050_sda;

    if (a0->f3) {
        P_006D4D48 *p = (P_006D4D48 *)D_001A5CD0;

        do {
        if (func_001961F8() != 0 || p->f2DC != 0) {
            g->f10 = 0x2E;
            if (g->f14 == 0) {
                g->f14 = 0x2E;
            }
            r1 = 0;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if ((s32) func_00130760(func_0012DCB0(), 0x24000) - a0->fC >= 0x3A99) {
            r1 = 0;
            break;
        }
        } while (a0->f3);
    }
    a0->f3 = 0;
    r2 = 1;
    if (a0->f12) {
        P_006D4D48 *p = (P_006D4D48 *)D_001A5CD0;

        do {
        if (func_001961F8() != 0 || p->f2DC != 0) {
            g->f10 = 0x2E;
            if (g->f14 == 0) {
                g->f14 = 0x2E;
            }
            r2 = 0;
        }
        g->f1C = 1;
        func_00195410();
        g->f1C = 0;
        if ((s32) func_00130760(func_0012DCB0(), 0x24000) - a0->f18 >= 0x3A99) {
            r2 = 0;
            break;
        }
        } while (a0->f12);
    }
    a0->f12 = 0;
    return r1 || r2;
}
/* localdecomp:end func_L39_006D4D48 */
