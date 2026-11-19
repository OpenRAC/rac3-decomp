#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
void func_00389D60(void (*callback)(s32), s32 argument);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
void func_00389F18(void (*callback)(s32), s32 argument);
extern s32 func_003E6D68();
extern void func_003E6DB0(void *);
extern void func_003E6E18();
extern void func_003E6E50();
extern void func_003E6EE0(void *);
extern void func_003E6F70();
extern s32 func_003E6AD8();
extern void *func_003E6A58();
extern void *func_003E6BB0();
/* --- end of declarations from other files --- */

/* localdecomp:start func_003E6A58 */
typedef struct { u32 key; void *val; } HE_400;
typedef struct { s32 f0; s32 n; HE_400 e[0x400]; } HT_400;
extern u8 D_001DAA08_003E6A58[];
void *func_003E6A58(HT_400 *t, u32 key) {
    s32 i;
    for (i = 0; i < 0x400; i++) {
        s32 h = ((key & 0x3FF) + ((key % 0x3FF) * i + i)) & 0x3FF;
        void *v = t->e[h].val;
        if (v == 0) return 0;
        if (t->e[h].key == key && v != D_001DAA08_003E6A58) return v;
    }
    return 0;
}
/* localdecomp:end func_003E6A58 */

/* localdecomp:start func_003E6AD8 */
extern void *func_003E6A58();
typedef struct { u32 key; void *val; } HE_3E11D0;
typedef struct { s32 f0; s32 n; HE_3E11D0 e[0x400]; } HT_3E11D0;
extern u8 D_001DAA08_003E6AD8[];
s32 func_003E6AD8(HT_3E11D0 *t, u32 key, void *val) {
    s32 i;
    s32 h;
    if (t->n >= 0x400) return 0;
    if (((void *(*)(void))func_003E6A58)()) return 0;
    for (i = 0; i < 0x400; i++) {
        h = ((key & 0x3FF) + ((key % 0x3FF) * i + i)) & 0x3FF;
        if (t->e[h].val == 0 || t->e[h].val == D_001DAA08_003E6AD8) {
            t->e[h].val = val;
            t->e[h].key = key;
            t->n++;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003E6AD8 */

/* localdecomp:start func_003E6BB0 */
extern u8 D_001DAA08;
void *func_003E6BB0(HT_400 *t, u32 key) {
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
/* localdecomp:end func_003E6BB0 */

LINKER_REMNANT("asm/boot_elf/remnants", func_003E6C40);

/* localdecomp:start func_003E6C78 */
typedef struct O { struct VT *vt; u8 pad[0x18]; } O;
struct VT { u8 pad[0x10]; void (*fn)(O *, s32); };
extern u8 D_001DA8F8;
extern u8 D_001DA930[];
void func_003E6C78(void) {
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
/* localdecomp:end func_003E6C78 */

/* localdecomp:start func_003E6CD8 */
extern s32 D_001DA8F8_003E6CD8;
extern s32 D_001DA930_003E6CD8;
typedef struct { u8 p[0x1C]; } E_3E13D0;
extern void **func_003F25C0(void **);
extern void func_116FD0();
extern void func_003E6C40();
s32 func_003E6CD8(s32 idx) {
    s32 i;
    E_3E13D0 *p;
    if (D_001DA930_003E6CD8 == 0) {
        p = (E_3E13D0 *)&D_001DA8F8_003E6CD8;
        i = 1;
        do {
            func_003F25C0((void **)p);
            i--;
            p++;
        } while (i != -1);
        D_001DA930_003E6CD8 = 1;
        func_116FD0((u8 *)func_003E6C40 + 0x38);
    }
    return (s32)&((E_3E13D0 *)&D_001DA8F8_003E6CD8)[idx];
}
/* localdecomp:end func_003E6CD8 */

/* localdecomp:start func_003E6D68 */
typedef struct { u8 pad0[0x20]; s32 *slots[12]; } S_003E1460_inner;
typedef struct { u8 pad0[4]; S_003E1460_inner *f4; } S_003E1460_outer;

s32 func_003E6D68(S_003E1460_outer *arg0, u32 arg1, s32 *arg2) {
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
/* localdecomp:end func_003E6D68 */

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
/* localdecomp:start func_003E6DB0 */
void func_003E6DB0(void *argument) {
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
/* localdecomp:end func_003E6DB0 */

/* localdecomp:start func_003E6E18 */
extern void func_003E62E0(void *);
 
typedef struct { void *arr[5]; s32 idx; } S_3E1510;
 
void func_003E6E18(void *p) {
    S_3E1510 *q = *(S_3E1510 **)((u8 *)p + 0x4);
    void *x = q->arr[q->idx];
    if (x != 0) {
        func_003E62E0(x);
    }
}
/* localdecomp:end func_003E6E18 */

/* localdecomp:start func_003E6E50 */
typedef struct { u8 pad[0x64]; void (*fn[4])(void); s32 count; } Q_3E1548;
typedef struct { s32 pad; Q_3E1548 *q; } S_3E1548;
void func_003E6E50(S_3E1548 *p) {
    s32 i;
    for (i = 0; i < p->q->count; i++) {
        if (p->q->fn[i]) {
            p->q->fn[i]();
            p->q->fn[i] = 0;
        }
    }
    p->q->count = 0;
}
/* localdecomp:end func_003E6E50 */

/* localdecomp:start func_003E6EE0 */
typedef struct { u8 pad[0x50]; void (*fn[4])(void); s32 count; } Q_3E15D8;
typedef struct { s32 pad; Q_3E15D8 *q; } S_3E15D8;
void func_003E6EE0(void *arg0) {
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
/* localdecomp:end func_003E6EE0 */

/* localdecomp:start func_003E6F70 */
extern void func_003E7540();
extern void func_003E6480(s32);
extern void func_003E7598(void);
typedef struct { s32 a[5]; s32 idx; } Q_3E1668;
typedef struct { s32 pad; Q_3E1668 *q; } S_3E1668;
void func_003E6F70(S_3E1668 *p) {
    s32 v; func_003E7540(p); v = p->q->a[p->q->idx]; if (v) func_003E6480(v); func_003E7598();
}
/* localdecomp:end func_003E6F70 */
