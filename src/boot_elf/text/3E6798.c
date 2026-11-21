#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
/* --- end of declarations from other files --- */

/* declarations of 3E5C60.c's earlier functions */
extern void *func_003E5D80(s32 idx);

typedef struct { u32 key; void *val; } HE_3E0E90;
typedef struct { s32 f0; s32 n; HE_3E0E90 e[0x400]; } HT_3E0E90;
typedef struct { s32 f0; s32 f4; struct { s32 pad[2]; void (*fn)(void *, s32); } *vt; } O_3E0E90;
typedef struct { struct { s32 pad[3]; void (*fn)(void *, void *); } *vt; } M_3E0E90;
typedef struct { s32 f0; s32 x4; } G_3E0E90;
extern s32 D_001DAA08[2];
extern G_3E0E90 D_001DA938[];
extern void *func_003E6BB0();
extern void *func_003E6FC0();
extern s32 func_003E7078();
/* localdecomp:start func_003E6798 */
static __inline__ u8 ht_dead_003E6798(void *v) {
    s32 d = v == (void *)D_001DAA08;
    if (v == 0) return 1;
    return d;
}
static __inline__ void *ht_val_003E6798(HT_3E0E90 *t, s32 i) {
    if (!ht_dead_003E6798(t->e[i].val) && i < 0x400) return t->e[i].val;
    return 0;
}
static __inline__ u32 ht_key_003E6798(HT_3E0E90 *t, s32 i) {
    if (!ht_dead_003E6798(t->e[i].val) && i < 0x400) return t->e[i].key;
    return 0;
}
static __inline__ G_3E0E90 *inst_003E6798(void) {
    G_3E0E90 *p = D_001DA938;
    G_3E0E90 *q;
    if (p->x4) q = p;
    else q = func_003E6FC0(p);
    return q;
}
s32 func_003E6798(s32 a, s32 i) {
    u8 *s = func_003E5D80(a);
    HT_3E0E90 *t = (HT_3E0E90 *)(s + 0x1C4);
    O_3E0E90 *o = ht_val_003E6798(t, i);
    M_3E0E90 *m;
    if (o == 0) return 0;
    if (o->f0 == 0) {
        u32 k = ht_key_003E6798((HT_3E0E90 *)(s + 0x1C4), i);
        func_003E6BB0((HT_3E0E90 *)(s + 0x1C4), k);
        o->vt->fn(o, 2);
        m = (M_3E0E90 *)func_003E7078(inst_003E6798(), 1);
        m->vt->fn(m, o);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E6798 */
