/* functional: high. Verified vs asm: hash-table at s+0x1C4 (header 8 bytes, entries key/val 8 bytes: key at 0x1CC+8i, val at 0x1D0+8i), entry live when val != 0 and val != D_001DAA08 and i<0x400; if the object's field f0 == 0: func_003E67F8(table,key); o->vt[2](o,2); m = func_003E6CC0(inst, 1) where inst = D_001DA938 if its +4 is set else func_003E6C08(D_001DA938) (a0 left holding D_001DA938: passed explicitly); m->vt[3](m,o); return 1; else 0. 56 words differ (inlined helpers scheduling). */
/* fcheck: the removal path no state ran (the states met only dead or busy entries) read against retail: offsets 0x1CC/0x1D0, sentinel D_001DAA08, vtable slots 8 and 0xC, the singleton passed to func_003E6C08: fcheck-read: 003E6434-003E643C,003E6440-003E6444,003E6450-003E6458,003E645C-003E647C,003E6480-003E6480,003E6484-003E648C,003E6490-003E6498,003E649C-003E649C,003E64A0-003E64CC,003E64D0-003E64D4,003E64D8-003E64DC,003E64E0-003E6500 */
extern u8 *func_003E59C8(s32);
typedef struct { u32 key; void *val; } HE_3E0E90;
typedef struct { s32 f0; s32 n; HE_3E0E90 e[0x400]; } HT_3E0E90;
typedef struct { s32 f0; s32 f4; struct { s32 pad[2]; void (*fn)(void *, s32); } *vt; } O_3E0E90;
typedef struct { struct { s32 pad[3]; void (*fn)(void *, void *); } *vt; } M_3E0E90;
typedef struct { s32 f0; s32 x4; } G_3E0E90;
extern u8 D_001DAA08_003E66A0[]; /* PAL: incomplete type, so the address is built with lui/addiu, not $gp-relative */
extern G_3E0E90 D_001DA938[];
extern void *func_003E67F8();
extern void *func_003E6C08();
extern s32 func_003E6CC0();
static inline u8 ht_dead_3E0E90(void *v) {
    s32 d = v == D_001DAA08_003E66A0;
    if (v == 0) return 1;
    return d;
}
static inline void *ht_val_3E0E90(HT_3E0E90 *t, s32 i) {
    if (!ht_dead_3E0E90(t->e[i].val) && i < 0x400) return t->e[i].val;
    return 0;
}
static inline u32 ht_key_3E0E90(HT_3E0E90 *t, s32 i) {
    if (!ht_dead_3E0E90(t->e[i].val) && i < 0x400) return t->e[i].key;
    return 0;
}
static inline G_3E0E90 *inst_3E0E90(void) {
    G_3E0E90 *p = D_001DA938;
    G_3E0E90 *q;
    if (p->x4) q = p;
    else q = func_003E6C08(p);
    return q;
}
s32 func_003E63E0(s32 a, s32 i) {
    u8 *s = func_003E59C8(a);
    HT_3E0E90 *t = (HT_3E0E90 *)(s + 0x1C4);
    O_3E0E90 *o = ht_val_3E0E90(t, i);
    M_3E0E90 *m;
    if (o == 0) return 0;
    if (o->f0 == 0) {
        /* re-derived rather than reusing t: reusing t does not match */
        u32 k = ht_key_3E0E90((HT_3E0E90 *)(s + 0x1C4), i);
        func_003E67F8((HT_3E0E90 *)(s + 0x1C4), k);
        o->vt->fn(o, 2);
        m = (M_3E0E90 *)func_003E6CC0(inst_3E0E90(), 1);
        m->vt->fn(m, o);
        return 1;
    }
    return 0;
}
