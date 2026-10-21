/* US draft of func_003EDDA0 (rac3-uya-decomp func_003E8838, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003EDDA0 */
typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E8838;
typedef struct { s32 *e[16]; s32 pad[2]; s32 n; } O_003E8838;
typedef struct { u8 p0[0x2C]; O_003E8838 *x2C; } T_003E8838;
extern S_003E8838 D_001DA938_003EDDA0[];
extern s32 *func_003E6C08();
extern s32 func_003E6DE8();
extern s32 func_003E6378();
extern s32 D_001D96D0;
extern s32 func_003E7118();
extern void func_003E7108();
s32 func_003EDDA0(S_3E7EC8 *a, s32 key) {
    T_003E8838 *self = (T_003E8838 *)a;
    S_003E8838 *q;
    S_003E8838 *p;
    void *t;
    s32 v;
    s32 i, cnt;
    s32 *slot;
    p = D_001DA938_003EDDA0;
    if (p->x4) q = p;
    else q = (S_003E8838 *)func_003E6C08(p);
    t = (void *)func_003E6378(func_003E6DE8(q), key);
    if (t == 0 || (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_001D96D0) == 0) t = 0;
    v = (s32)t;
    if (v == 0) return 0;
    cnt = 0;
    for (i = 0; i < self->x2C->n; i++) {
        if (*(s32 *)((i << 2) + (s32)self->x2C) == v) cnt++;
    }
    if (cnt != 0) return 0;
    if (self->x2C->n < 16) {
        slot = (s32 *)((self->x2C->n << 2) + (s32)self->x2C);
        if (*slot != 0) func_003E7118(*slot);
        *slot = v;
        if (v != 0) func_003E7108(v);
        self->x2C->n = self->x2C->n + 1;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_003EDDA0 */
