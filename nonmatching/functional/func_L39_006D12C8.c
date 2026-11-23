/* functional: medium. Same as func_L39_006D0F08 but flag byte at +0xE8, node byte +0xC8 = 0, no extra copies, no -0x3DE branch, clear size 0xEC. Dead sift-down dropped, see 0F08. */
typedef struct Q_006D12C8_Heap {
    u8 (*cmp)(void *, void *);
    s32 count;
    void **arr;
} Q_006D12C8_Heap;
typedef struct Q_006D12C8_Pool {
    u8 pad0[0xC];
    u8 *fC;
    u8 pad10[8];
    s32 f18;
    s32 f1C;
} Q_006D12C8_Pool;
typedef struct Q_006D12C8_Mgr {
    u8 pad0[0x3EC];
    u8 f3EC;
    u8 pad3ED[3];
    s32 f3F0;
    u8 f3F4;
    u8 pad3F5[3];
    s32 f3F8;
    s32 f3FC;
    s32 f400;
    Q_006D12C8_Heap heap[2];
    Q_006D12C8_Pool *pool;
} Q_006D12C8_Mgr;
typedef struct Q_006D12C8_G {
    u8 pad0[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[5];
    u8 f1D;
    u8 pad1E[0x1A];
    Q_006D12C8_Mgr *f38;
} Q_006D12C8_G;
typedef struct Q_006D12C8_Node {
    u8 body[0xC8];
    u8 fC8;
    u8 padC9[3];
    s32 fCC;
    s32 fD0;
} Q_006D12C8_Node;

extern s32 func_L01_00521C90(s32, s32);
extern void func_L39_005958F8(void *, void *, s32);
extern void func_0011D534(void *, s32, s32);

void func_L39_006D12C8(u8 *arg0) {
    Q_006D12C8_G *g = (Q_006D12C8_G *)D_L39_0024D760;
    Q_006D12C8_Mgr *m = g->f38;
    Q_006D12C8_Heap *h;
    Q_006D12C8_Heap *other;
    Q_006D12C8_Pool *pool;
    Q_006D12C8_Node *node;
    s32 which;
    s32 slot;
    s32 i;
    s32 j;
    s32 k;
    void *tmp;

    if (m->f3EC == 0) {
        return;
    }
    if (g->f1D != 0) {
        return;
    }
    which = (m->f3F0 == 0);
    h = &m->heap[which];
    if (*(s32 *)(arg0 + 0x18) == 0) {
        if (h->count < m->f400) {
            pool = m->pool;
            slot = pool->f1C;
            if (slot != 0) {
                pool->f1C = *(s32 *)(pool->fC + slot);
                pool->f18 = pool->f18 - 1;
                node = (Q_006D12C8_Node *)func_L01_00521C90(0xD4, slot);
                node->fC8 = 0;
                func_L39_005958F8(node, arg0 + 0x20, 0xC8);
                i = h->count;
                h->count = i + 1;
                h->arr[i] = node;
                if (h->cmp != 0) {
                    /* sift up; the parent index is computed once, as in retail */
                    j = i / 2;
                    while (i > 0) {
                        if ((h->cmp(h->arr[j], h->arr[i]) & 0xFF) == 0) {
                            break;
                        }
                        tmp = h->arr[i];
                        h->arr[i] = h->arr[j];
                        h->arr[j] = tmp;
                        i = j;
                    }
                }
            }
        }
    } else if (*(s32 *)(arg0 + 0x18) == 1) {
        arg0[0xE8] = 1;
    } else if (arg0[0xE8] != 0) {
        func_0011D534(arg0, 0, 0xEC);
        arg0[0xE8] = 1;
    } else {
        func_0011D534(arg0, 0, 0xEC);
    }
    if (arg0[0xE8] == 0) {
        return;
    }
    if (h->cmp != 0 && h->count >= 2) {
        /* rotate: swap element 0 with j for j = count-1 .. 1 (retail's sift-down
           loop is dead: its child index 2*j+1 is never < 0) */
        for (j = h->count - 1; j > 0; j--) {
            tmp = h->arr[0];
            h->arr[0] = h->arr[j];
            h->arr[j] = tmp;
        }
    }
    other = 0;
    if (m->f3EC != 0 && m->f3F0 >= 0) {
        other = &m->heap[m->f3F0];
    }
    if (other != 0) {
        if (other->count > 0) {
            k = 0;
            do {
                slot = (s32)other->arr[k];
                k++;
                pool = m->pool;
                *(s32 *)(pool->fC + slot) = pool->f1C;
                pool->f1C = slot;
                pool->f18 = pool->f18 + 1;
            } while (k < other->count);
        }
        other->count = 0;
    }
    m->f3F0 = which;
    m->f3FC = m->f3F8;
    m->f3F4 = 0;
}
