#include "common.h"

/* NTSC-U counterpart of func_L39_006D7138 (src/levels/39_multiplayer_menu/L39_006D5208.c) */
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;
extern void *D_L39_0024D860;

/* localdecomp:start func_L39_006D49A8 */
/* NTSC-U has one default entry (0x63), replacing PAL's five fixed entries. */
void *memcpy(void *, const void *, unsigned int);
__asm__(".extern D_L39_0024D860, 16");
extern void *D_L39_0024D860;
typedef struct {
    u8 pad0[0x18];
    s32 f18;
    char name[0x5C - 0x1C];
    s32 f5C;
    u8 f60;
    u8 pad61[3];
} Item_006D7138;
typedef struct {
    u8 pad0[0xC];
    s32 fC;
    u8 pad10[8];
    s32 f18;
    Item_006D7138 *f1C;
} Pool_006D7138;
typedef struct {
    s32 (*cmp)(Item_006D7138 *, Item_006D7138 *);
    s32 count;
    Item_006D7138 **arr;
} Heap_006D7138;
typedef struct {
    u8 f0;
    u8 pad1[3];
    s32 f4;
    s32 f8;
    u8 padC;
    u8 fD;
    u8 padE[2];
    s32 f10;
    Heap_006D7138 heap;
    Pool_006D7138 *pool;
} Q_006D7138;
typedef struct {
    u8 pad0[0x1D];
    u8 f1D;
    u8 pad1E[0x78 - 0x1E];
    Q_006D7138 *f78;
} G_006D7138;
extern char D_L39_00249F48[6] __attribute__((aligned(4), section(".data")));

void func_L39_006D49A8(Item_006D7138 *arg0) {
    G_006D7138 *g = D_L39_0024D860;
    Q_006D7138 *q = g->f78;
    Item_006D7138 *item;
    Heap_006D7138 *h;

    if (g->f1D != 0) {
        return;
    }
    if (arg0->f5C == 0 && (u32)(arg0->f18 - 0x28) < 0x3C) {
        Heap_006D7138 *h1 = &q->heap;
        if (h1->count < q->f10) {
            {
                Pool_006D7138 *pl = q->pool;
                Item_006D7138 *aa = pl->f1C;
                Item_006D7138 *it1;
                if (aa != 0) {
                    Item_006D7138 *nx = *(Item_006D7138 **)((u8 *)aa + pl->fC);
                    pl->f18--;
                    pl->f1C = nx;
                }
                it1 = aa;
                if (it1 != 0) {
                    *it1 = *arg0;
                    {
                        Heap_006D7138 *ph = &q->heap;
                        s32 i = ph->count++;
                        s32 p;
                        ph->arr[i] = it1;
                        if (ph->cmp != 0) {
                            p = i / 2;
                            while (i > 0 && (u8)ph->cmp(ph->arr[p], ph->arr[i])) {
                                Item_006D7138 *t = ph->arr[p];
                                ph->arr[p] = ph->arr[i];
                                ph->arr[i] = t;
                                i = p;
                            }
                        }
                    }
                }
            }
        }
    }
    if (arg0->f60 != 0) {
        h = &q->heap;
        if (h->count == 0 && q->f10 > 0) {
            {
                Pool_006D7138 *pl = q->pool;
                Item_006D7138 *aa = pl->f1C;
                if (aa != 0) {
                    Item_006D7138 *nx = *(Item_006D7138 **)((u8 *)aa + pl->fC);
                    pl->f18--;
                    pl->f1C = nx;
                }
                item = aa;
                if (item != 0) {
                    item->f18 = 0x63;
                    memcpy(item->name, D_L39_00249F48, 6);
                    {
                        Heap_006D7138 *ph = &q->heap;
                        s32 i = ph->count++;
                        s32 p;
                        ph->arr[i] = item;
                        if (ph->cmp != 0) {
                            p = i / 2;
                            while (i > 0 && (u8)ph->cmp(ph->arr[p], ph->arr[i])) {
                                Item_006D7138 *t = ph->arr[p];
                                ph->arr[p] = ph->arr[i];
                                ph->arr[i] = t;
                                i = p;
                            }
                        }
                    }
                }
            }
        }
        q->fD = 1;
        q->f8 = q->f4;
        q->f0 = 0;
    }
}
/* localdecomp:end func_L39_006D49A8 */
