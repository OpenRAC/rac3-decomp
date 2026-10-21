#include "common.h"

/* localdecomp:start func_L01_00439CB8 */
typedef struct Slot_00436BD8 {
    s16 id;
    u16 count;
    u8 state;
    u8 pad5[7];
    u8 *data;
    s32 arg;
    s32 owner;
    u8 pad18[4];
    struct Slot_00436BD8 *next;
    u8 pad20[32];
} Slot_00436BD8;

extern Slot_00436BD8 D_L01_001F4740[];

Slot_00436BD8 *func_L01_00439CB8(u8 *self, s32 id, s32 arg) {
    s32 i;
    Slot_00436BD8 *e;
    u8 *d;

    for (i = 0; i < 16 && D_L01_001F4740[i].state != 0; i++) {
    }
    if (i == 16) {
        return 0;
    }
    e = &D_L01_001F4740[i];
    e->state = 2;
    e->arg = arg;
    e->id = id;
    e->owner = *(s32 *)(self + 36);
    d = (*(u8 ***)(*(u8 **)(self + 36) + 28))[(s16)id + 1];
    e->count = d[2];
    e->data = d + (d[0] + 4);
    e->next = *(Slot_00436BD8 **)(self + 80);
    *(Slot_00436BD8 **)(self + 80) = e;
    return e;
}
/* localdecomp:end func_L01_00439CB8 */

/* localdecomp:start func_L01_00439D70 */
typedef struct N436C90 {
    u8 pad[28];
    struct N436C90 *next;
} N436C90;

typedef struct {
    u8 pad[80];
    N436C90 *head;
} L436C90;

extern void func_0038CB78(void *, s32, s32);

void func_L01_00439D70(L436C90 *l, N436C90 **pp) {
    N436C90 *p;

    if (*pp == 0) {
        return;
    }
    if (l->head == *pp) {
        l->head = (*pp)->next;
    } else {
        p = l->head;
        while (p->next != 0 && p->next != *pp) {
            p = p->next;
        }
        if (p->next == *pp) {
            p->next = (*pp)->next;
        }
    }
    func_0038CB78(*pp, 0, 64);
    *pp = 0;
}
/* localdecomp:end func_L01_00439D70 */

INCLUDE_ASM("asm/levels", func_L01_00439E10);

INCLUDE_ASM("asm/levels", func_L01_0043A1E8);

INCLUDE_ASM("asm/levels", func_L01_0043A250);

/* localdecomp:start func_L01_0043A2E0 */
typedef struct {
    u8 pad0[6];
    s16 h6;
    s16 h8;
    s16 h10;
    s16 h12;
    s16 h14;
    unsigned long q[1];
} S_437200_B;

typedef struct {
    u8 pad0[28];
    S_437200_B *arr[1];
} S_437200_E;

typedef struct {
    u8 pad0[4];
    u8 idx[1];
} S_437200_I;

typedef struct {
    u8 pad0[8];
    u8 cnt;
    u8 pad9[19];
    S_437200_I *ix;
    u8 pad20[40];
    S_437200_E *arr[1];
} S_437200_H;

typedef struct {
    u8 pad0[8];
    u8 cnt;
} S_437200_C;

typedef struct {
    u8 pad0[20];
    S_437200_C *c;
    S_437200_H *h;
} S_437200_O;

extern void func_0038CBA0(void *, s32);
extern void func_0038CC88(void *, void *, s32);
extern void func_0011F0A0(s32);

void func_L01_0043A2E0(S_437200_O *obj, s32 i, s32 j, S_437200_B *dest) {
    S_437200_B *src;
    s32 n;
    s32 m;
    s32 k;
    s32 n8;
    s32 m8;
    u16 t;
    s32 size;
    u8 *idx;
    unsigned long *sp;
    unsigned long *q;

    m = obj->h->cnt;
    n = obj->c->cnt;
    src = obj->h->arr[i]->arr[j];
    func_0038CBA0(dest, ((n + 3) * 8) & 0xFF0);
    n8 = n * 8;
    m8 = m * 8;
    dest->h6 = (n + src->h10 + src->h14 + 1) >> 1;
    dest->h8 = n8;
    t = src->h10;
    dest->h10 = t;
    dest->h12 = (t + n) * 8;
    dest->h14 = src->h14;
    {
        u8 *from = (u8 *)src + (m8 + 16);
        size = src->h6 * 16 - m8;
        if (size != 0) {
            func_0038CC88((u8 *)dest + (n8 + 16), from, size);
        }
    }
    idx = obj->h->ix->idx;
    sp = src->q;
    for (k = 0; k < m; k++) {
        ((unsigned long *)dest)[*idx + 2] = *sp;
        idx++;
        sp++;
    }
    q = (unsigned long *)((u8 *)dest + dest->h6 * 16);
    if (*q == 0) {
        *q = 1;
    }
    func_0011F0A0(0);
}
/* localdecomp:end func_L01_0043A2E0 */

INCLUDE_ASM("asm/levels", func_L01_0043A430);
