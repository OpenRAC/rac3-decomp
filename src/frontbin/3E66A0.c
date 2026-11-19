#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern s32 func_003E69B0();
extern void func_003E69F8(void *);
extern void func_003E6A60();
extern void func_003E6A98();
extern void func_003E6B28(void *);
extern void func_003E6BB8();
extern s32 func_003E6720();
extern void *func_003E66A0();
extern void *func_003E67F8();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003E66A0 */
typedef struct { u32 key; void *val; } HE_400;
typedef struct { s32 f0; s32 n; HE_400 e[0x400]; } HT_400;
extern u8 D_001DAA08_003E66A0[];
void *func_003E66A0(HT_400 *t, u32 key) {
    s32 i;
    for (i = 0; i < 0x400; i++) {
        s32 h = ((key & 0x3FF) + ((key % 0x3FF) * i + i)) & 0x3FF;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != D_001DAA08_003E66A0) return v;
    }
    return 0;
}
/* localdecomp:end func_003E66A0 */

/* localdecomp:start func_003E6720 */
extern void *func_003E66A0();
typedef struct { u32 key; void *val; } HE_3E11D0;
typedef struct { s32 f0; s32 n; HE_3E11D0 e[0x400]; } HT_3E11D0;
extern u8 D_001DAA08_003E6720[];
s32 func_003E6720(HT_3E11D0 *t, u32 key, void *val) {
    s32 i;
    s32 h;
    if (t->n >= 0x400) return 0;
    if (((void *(*)(void))func_003E66A0)()) return 0;
    for (i = 0; i < 0x400; i++) {
        h = ((key & 0x3FF) + ((key % 0x3FF) * i + i)) & 0x3FF;
        if (t->e[h].val == 0 || t->e[h].val == D_001DAA08_003E6720) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003E6720 */

/* localdecomp:start func_003E67F8 */
extern u8 D_001DAA08;
void *func_003E67F8(HT_400 *t, u32 key) {
    s32 i;
    for (i = 0; i < 0x400; i++) {
        s32 h = ((key & 0x3FF) + ((key % 0x3FF) * i + i)) & 0x3FF;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (v != &D_001DAA08 && t->e[h].key == key) {
            t->e[h].val = &D_001DAA08;
            t->n--;
            return v;
        }
    }
    return 0;
}
/* localdecomp:end func_003E67F8 */

LINKER_REMNANT("asm/remnants", func_003E6888);

/* localdecomp:start func_003E68C0 */
typedef struct O { struct VT *vt; u8 pad[0x18]; } O;
struct VT { u8 pad[0x10]; void (*fn)(O *, s32); };
extern u8 D_001DA8F8;
extern u8 D_001DA930[];
void func_003E68C0(void) {
    O *first = (O *)&D_001DA8F8;
    O *p;
    if (first != 0) {
        p = (O *)D_001DA930;
        if (p != first) {
            do {
                p--;
                p->vt->fn(p, 0);
            } while (p != first);
        }
    }
}
/* localdecomp:end func_003E68C0 */

/* localdecomp:start func_003E6920 */
extern s32 D_001DA8F8_003E6920;
extern s32 D_001DA930_003E6920;
typedef struct { u8 p[0x1C]; } E_3E13D0;
extern void **func_003F2208(void **);
extern void func_116FD0();
extern void func_003E6888();
s32 func_003E6920(s32 idx) {
    s32 i;
    E_3E13D0 *p;
    if (D_001DA930_003E6920 == 0) {
        p = (E_3E13D0 *)&D_001DA8F8_003E6920;
        i = 1;
        do {
            func_003F2208((void **)p);
            i--;
            __asm__ volatile("nop");
            p++;
        } while (i != -1);
        D_001DA930_003E6920 = 1;
        func_116FD0((u8 *)func_003E6888 + 0x38);
    }
    return (s32)&((E_3E13D0 *)&D_001DA8F8_003E6920)[idx];
}
/* localdecomp:end func_003E6920 */

/* localdecomp:start func_003E69B0 */
typedef struct { u8 pad0[0x20]; s32 *slots[12]; } S_003E1460_inner;
typedef struct { u8 pad0[4]; S_003E1460_inner *f4; } S_003E1460_outer;

s32 func_003E69B0(S_003E1460_outer *arg0, u32 arg1, s32 *arg2) {
    s32 **slot;

    if (arg1 < 12) {
        { s32 **b = arg0->f4->slots; slot = &b[arg1]; }
        if (*slot == 0 || (**slot ^ 4) != 0) {
            *slot = arg2;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003E69B0 */

typedef struct CallbackVtable_003E14A8 {
    unsigned char padding[0x10];
    void (*callback)(void *);
} CallbackVtable_003E14A8;
typedef struct Entry_003E14A8 {
    unsigned char padding[4];
    CallbackVtable_003E14A8 *vtable;
} Entry_003E14A8;
typedef struct Container_003E14A8 {
    unsigned char padding[0x20];
    Entry_003E14A8 *slots[12];
} Container_003E14A8;
typedef struct Root_003E14A8 {
    unsigned char padding[4];
    Container_003E14A8 *container;
} Root_003E14A8;
/* localdecomp:start func_003E69F8 */
void func_003E69F8(void *argument) {
    int index;
    Root_003E14A8 *root = argument;
    Entry_003E14A8 *entry;
    register CallbackVtable_003E14A8 *vtable __asm__("$3");
    register void (*callback)(void *) __asm__("$2");

    for (index = 0; index < 12; index++) {
        entry = root->container->slots[index];
        if (entry != 0) {
            vtable = entry->vtable;
            callback = vtable->callback;
            callback(entry);
        }
    }
}
/* localdecomp:end func_003E69F8 */

/* localdecomp:start func_003E6A60 */
extern void func_003E5F28(void *);
 
typedef struct { void *arr[5]; s32 idx; } S_3E1510;
 
void func_003E6A60(void *p) {
    S_3E1510 *q = *(S_3E1510 **)((u8 *)p + 0x4);
    void *x = q->arr[q->idx];
    if (x != 0) {
        func_003E5F28(x);
    }
}
/* localdecomp:end func_003E6A60 */

/* localdecomp:start func_003E6A98 */
typedef struct { u8 pad[0x64]; void (*fn[4])(void); s32 count; } Q_3E1548;
typedef struct { s32 pad; Q_3E1548 *q; } S_3E1548;
void func_003E6A98(S_3E1548 *p) {
    s32 i;
    for (i = 0; i < p->q->count; i++) {
        if (p->q->fn[i]) {
            p->q->fn[i]();
            p->q->fn[i] = 0;
        }
    }
    p->q->count = 0;
}
/* localdecomp:end func_003E6A98 */

/* localdecomp:start func_003E6B28 */
typedef struct { u8 pad[0x50]; void (*fn[4])(void); s32 count; } Q_3E15D8;
typedef struct { s32 pad; Q_3E15D8 *q; } S_3E15D8;
void func_003E6B28(void *arg0) {
    S_3E15D8 *p = (S_3E15D8 *)arg0;
    s32 i;
    for (i = 0; i < p->q->count; i++) {
        if (p->q->fn[i]) {
            p->q->fn[i]();
            p->q->fn[i] = 0;
        }
    }
    p->q->count = 0;
}
/* localdecomp:end func_003E6B28 */

/* localdecomp:start func_003E6BB8 */
extern void func_003E7188();
extern void func_003E60C8(s32);
extern void func_003E71E0(void);
typedef struct { s32 a[5]; s32 idx; } Q_3E1668;
typedef struct { s32 pad; Q_3E1668 *q; } S_3E1668;
void func_003E6BB8(S_3E1668 *p) {
    s32 v; func_003E7188(p); v = p->q->a[p->q->idx]; if (v) func_003E60C8(v); func_003E71E0();
}
/* localdecomp:end func_003E6BB8 */
