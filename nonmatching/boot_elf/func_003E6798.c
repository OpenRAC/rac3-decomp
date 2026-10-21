/* Near miss of func_003E6798 with its file's own flags: tools/check.py reports 56 diff
   (the version it replaces: 71).
   What differs: Only the tombstone address (D_1DAA08) is wrong: retail materializes it once as
   `lui $3,%hi` + `addiu $3,$3,%lo` in one register and copies that full address (`daddu
   $8,$3,$0`) for the second comparison, while this C makes GCC split it into hi/lo (one `lui
   $v1`, a copy of the hi half `move $a3,$v1`, and the low half re-applied later as `addiu
   $v1,$a3,-0x55f8`), so the second comparison re-derives the address instead of reusing the
   copy and the branch offsets shift (0xc8/0xbc/0xb0 vs retail 0xbc/0xb0). Everything else
   (prologue, both dead-checks, the value/key loads, the calls, the epilogue)...
*/

/* US draft of func_003E6798 (rac3-uya-decomp func_003E6650, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` (a single-function override). */


/* localdecomp:start func_003E6798 */
typedef struct { u32 key; void *val; } HE_3E0E90;
typedef struct { s32 f0; s32 n; HE_3E0E90 e[0x400]; } HT_3E0E90;
typedef struct { s32 f0; s32 f4; struct { s32 pad[2]; void (*fn)(void *, s32); } *vt; } O_3E0E90;
typedef struct { struct { s32 pad[3]; void (*fn)(void *, void *); } *vt; } M_3E0E90;
typedef struct { s32 f0; s32 x4; } G_3E0E90;
/* The tombstone pointer. Declared as an incomplete array on purpose: a sized
   object of <= 8 bytes would land in .sdata and be addressed through $gp
   (the draft's `extern s32 D_001DAA08[2]` did exactly that), while retail
   materializes the address with lui/addiu -- see the matched func_003E6A58,
   which declares the very same address (D_001DAA08_003E6A58) the same way. */
extern u8 D_1DAA08[];
extern G_3E0E90 D_001DA938[];
extern void *func_003E6BB0();
extern void *func_003E6FC0();
extern s32 func_003E7078();
static inline u8 ht_dead_3E0E90(void *v) {
    s32 d = v == D_1DAA08;
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
    else q = func_003E6FC0(p);
    return q;
}
s32 func_003E6798(s32 a, s32 i) {
    u8 *s = func_003E5D80(a);
    HT_3E0E90 *t = (HT_3E0E90 *)(s + 0x1C4);
    O_3E0E90 *o = ht_val_3E0E90(t, i);
    M_3E0E90 *m;
    if (o == 0) return 0;
    if (o->f0 == 0) {
        /* re-derived rather than reusing t: reusing t does not match */
        u32 k = ht_key_3E0E90((HT_3E0E90 *)(s + 0x1C4), i);
        func_003E6BB0((HT_3E0E90 *)(s + 0x1C4), k);
        o->vt->fn(o, 2);
        m = (M_3E0E90 *)func_003E7078(inst_3E0E90(), 1);
        m->vt->fn(m, o);
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003E6798 */
