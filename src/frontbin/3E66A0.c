#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern s32 func_003E6FE8();
extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern void (*D_001D9A40[2])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void *func_003E6C08();
extern s32 func_003E69B0();
extern s32 func_003E6D10();
extern void func_003E69F8(void *);
extern void func_003E6A60();
extern s32 func_003E6F18();
extern void func_003E6A98();
extern void func_003E6B28(void *);
extern void func_003E6BB8();
extern void func_003E6FF8(void *p);
extern s32 func_003E6DE8();
extern s32 func_003E6CC0();
extern void func_003E6FF8(void *);
extern s32 func_003E6FA0(s32 *, s32, s32, s32, s32, s32);
extern s32 func_003E7118();
extern void func_003E7108();
extern s32 func_003E6EA0();
extern void func_003E7040();
extern void func_003E7018();
extern void func_003E6FF0();
extern void func_003E7068();
extern void func_003E7090();
extern void func_003E70B8();
extern s32 func_003E6720();
extern void *func_003E66A0();
extern void *func_003E67F8();
extern s32 *func_003E6E80();
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

void func_0038CB78(void *, s32, s32);
typedef struct { u8 pad0[0x4]; u8 *f4; } S_001DA9B8_003E16B8;
extern S_001DA9B8_003E16B8 D_001DA938[];
extern u8 D_0031B750[];
INCLUDE_ASM("asm/nonmatchings/text", func_003E6C08);

LINKER_REMNANT("asm/remnants", func_003E6CB0);

/* localdecomp:start func_003E6CC0 */
typedef struct { u8 pad[0x18]; s32 arr[1]; } S_3E1770;
 
s32 func_003E6CC0(void *p, s32 i) {
    return (*(S_3E1770 **)((u8 *)p + 0x4))->arr[i];
}
/* localdecomp:end func_003E6CC0 */

/* localdecomp:start func_003E6CD8 */
s32 func_003E6CD8(void *p, u32 i, s32 v) {
    if (i < 8) {
        s32 *q = *(s32 **)((u8 *)p + 0x4) + i;
        if (*q == 0) {
            *q = v;
            return 1;
        }
    }
    return 0;
}
/* localdecomp:end func_003E6CD8 */

/* localdecomp:start func_003E6D10 */
extern s32 func_003E6920(s32);
s32 func_003E6D10(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_17;

    if ((arg3 != 0) && (arg4 < 0x190)) {
        if (arg2 <= 0x31FFF) {
            temp_17 = arg1 * 4;
            if ((*(s32 *)((u8 *)((*(s32 *)((u8 *)arg0 + 4)) + temp_17) + 0x18)) == 0) {
                (*(s32 *)((u8 *)((*(s32 *)((u8 *)arg0 + 4)) + temp_17) + 0x18)) = func_003E6920(arg1);
                func_003F21E8(func_003E6920(arg1), arg4, arg3, arg2);
                return 1;
            }
            goto block_5;
        }
        /* Duplicate return node #6. Try simplifying control flow for better match */
        return 0;
    }
block_5:
    return 0;
}
/* localdecomp:end func_003E6D10 */

LINKER_REMNANT("asm/remnants", func_003E6DE0);

/* localdecomp:start func_003E6DE8 */
typedef struct 
{
  u8 pad[0x14];
  int index;
} SubStruct;
typedef struct 
{
  u8 pad;
  SubStruct *sub;
} MainStruct;
s32 func_003E6DE8(MainStruct *p)
{
  SubStruct *sub = p->sub;
  int *new_var;
  if (sub != 0)
  {
    int *base_ptr = (int *) sub;
    int element_offset = sub->index;
    new_var = &base_ptr[element_offset];
    return *new_var;
  }
  return 0;
}
/* localdecomp:end func_003E6DE8 */

/* localdecomp:start func_003E6E10 */
extern s32 func_003F23A8(s32 *);
s32 func_003E6E10(s32 *a0, s32 a1) {
    u8 *t;
    if (func_003F23A8(a0) != 0) {
        return 0;
    }
    t = (u8 *)a0[1];
    if (t != 0 && (u32)a1 < 8 && *(s32 *)(t + (a1 << 2)) != 0) {
        *(s32 *)(t + 0x14) = a1;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E6E10 */

LINKER_REMNANT("asm/remnants", func_003E6E78);

/* localdecomp:start func_003E6E80 */
s32 *func_003E6E80(s32 *p, s32 a, s32 b, s32 c, s32 d) {
    p[2] = a;
    p[1] = b;
    p[4] = d;
    p[3] = c;
    p[0] = 0;
    return p;
}
/* localdecomp:end func_003E6E80 */

/* localdecomp:start func_003E6EA0 */
typedef struct { s32 x0; u32 x4; u32 x8; s32 xC; s32 (*x10)(s32, u32); } S_3E1950;
s32 func_003E6EA0(S_3E1950 *p) {
    u32 i;
    s32 r = 0;
    for (i = p->x8; i <= p->x4; i++) {
        r |= p->x10(p->xC, i) != 0;
    }
    return r;
}
/* localdecomp:end func_003E6EA0 */

/* localdecomp:start func_003E6F18 */
typedef struct { u32 i, max, wrap; s32 c; s32 (*fn)(s32, u32); } S_E19C8;
s32 func_003E6F18(S_E19C8 *s, s32 n) {
    s32 r = 0;
    u32 x, v;
    while (n > 0) {
        n--;
        r |= (s->fn(s->c, s->i) != 0);
        x = s->i + 1;
        s->i = x;
        v = s->max < x ? s->wrap : x;
        s->i = v;
    }
    return r;
}
/* localdecomp:end func_003E6F18 */

/* localdecomp:start func_003E6FA0 */
extern void func_003E6FE0(void *);
s32 func_003E6FA0(s32 *p, s32 a, s32 b, s32 c, s32 d, s32 e) {
    p[1] = a;
    p[2] = b;
    p[3] = c;
    p[4] = d;
    p[5] = e;
    func_003E6FE0(p);
    return (s32)p;
}
/* localdecomp:end func_003E6FA0 */

/* localdecomp:start func_003E6FE0 */
void func_003E6FE0(void *p) {
    *(s32 *)p = 0;
}
/* localdecomp:end func_003E6FE0 */

/* localdecomp:start func_003E6FE8 */
s32 func_003E6FE8(void *p) {
    return *(s32 *)((u8 *)p + 0x0);
}
/* localdecomp:end func_003E6FE8 */

/* localdecomp:start func_003E6FF0 */
void func_003E6FF0(void *p, s32 value) {
    *(s32 *)((u8 *)p + 0x0) = value;
}
/* localdecomp:end func_003E6FF0 */

/* localdecomp:start func_003E6FF8 */
extern void func_003E6FF0(void *, s32);
 
void func_003E6FF8(void *p) {
    func_003E6FF0(p, 0);
}
/* localdecomp:end func_003E6FF8 */

/* localdecomp:start func_003E7018 */
void func_003E7018(void *p) {
    void (*fn)() = *(void (**)())((u8 *)p + 0x4);
    if (fn != 0) {
        fn();
    }
}
/* localdecomp:end func_003E7018 */

/* localdecomp:start func_003E7040 */
void func_003E7040(void *p) {
    void (*fn)() = *(void (**)())((u8 *)p + 0x8);
    if (fn != 0) {
        fn();
    }
}
/* localdecomp:end func_003E7040 */

/* localdecomp:start func_003E7068 */
void func_003E7068(void *p) {
    void (*fn)() = *(void (**)())((u8 *)p + 0xC);
    if (fn != 0) {
        fn();
    }
}
/* localdecomp:end func_003E7068 */

/* localdecomp:start func_003E7090 */
void func_003E7090(void *p) {
    void (*fn)() = *(void (**)())((u8 *)p + 0x10);
    if (fn != 0) {
        fn();
    }
}
/* localdecomp:end func_003E7090 */

/* localdecomp:start func_003E70B8 */
void func_003E70B8(void *p) {
    void (*fn)() = *(void (**)())((u8 *)p + 0x14);
    if (fn != 0) {
        fn();
    }
}
/* localdecomp:end func_003E70B8 */

LINKER_REMNANT("asm/remnants", func_003E70E0);

typedef struct {
    s32 field_0;        /* Offset 0x00 - Targeted by sw $zero, 0($a0) */
    s32 field_4;        /* Offset 0x04 - Padding */
    void* field_8;      /* Offset 0x08 - Targeted by sw $v0, 8($a0) */
} TargetStruct;

extern char D_001D9670[];
/* localdecomp:start func_003E70E8 */
extern char D_001D9670[];
void **func_003E70E8(void **p) { p[0] = 0; p[2] = D_001D9670; return p; }
/* localdecomp:end func_003E70E8 */

/* localdecomp:start func_003E7100 */
s32 func_003E7100(s32 arg0, s32 arg1) {
    return arg1 == 0;
}
/* localdecomp:end func_003E7100 */

/* localdecomp:start func_003E7108 */
void func_003E7108(s32 *p) {
    *p += 1;
}
/* localdecomp:end func_003E7108 */

/* localdecomp:start func_003E7118 */
// Define the context structure passing through $a0
typedef struct {
    s32 counter; /* Offset 0x00 - Targeted by lw/sw operations */
} CounterContext;

// Signature must take the context pointer ($a0) and return an s32 ($v0)
s32 func_003E7118(CounterContext* ctx) {
    // 0: lw $v0, 0($a0)
    s32 current_val = ctx->counter;

    // 4: beqz $v0
    if (current_val != 0) {
        // 8: addiu $v0, $v0, -1
        // c: sw $v0, 0($a0)
        ctx->counter = current_val - 1;
    }

    // 14: lw $v0, 0($a0) (Scheduled cleanly into the jr $ra delay slot)
    return ctx->counter;
}
/* localdecomp:end func_003E7118 */

/* localdecomp:start func_003E7130 */
extern u8 D_001D9670_g;
extern s32 func_003F2380();
void func_003E7130(u8 *p, s32 f) {
    *(u8 **)(p + 8) = &D_001D9670_g;
    if (f & 1) func_003F2380(p);
}
/* localdecomp:end func_003E7130 */

/* localdecomp:start func_003E7160 */
extern void func_003A9440(s32, unsigned long);
void func_003E7160(void) {
    func_003A9440(0x47, 0x33001);
}
/* localdecomp:end func_003E7160 */
