/* Near miss of func_003E63E0 with its file's own flags: tools/check.py reports 56 diff
   (the version it replaces: 71).
*/

/* US draft of func_003E63E0 (rac3-uya-decomp func_003E0E90, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003E63E0 */
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
/* localdecomp:end func_003E63E0 */
