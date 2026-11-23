/* func_L01_004593B8: 40 diff with the file's flags (L01_00457F00.c, @ps2as); was 53: `b = 0;` assigned before `a = 0;`
   gives retail's a = $s0 / b = $s1 (the a/b swap was 13 of the 53 diffs). Instructions and control flow are retail's
   (plain scalar D_L01_001E001C: lui/lw, then $gp in a delay slot). Still different (round 17, B28):
   (A) the count copies: ours n in $t0, n+1 in $a0, -1 in $t1; retail n $t1, n+1 $t0, -1 $a0 (regalloc.py: -1 has
   3 refs / live 24 = priority 0.125, n+1 0.188, n 0.143; retail needs -1 above both);
   (B) the first loop's entry test is `slt $v0,$s1,$a0; beqz` (cse swaps the constant 0 for b's zero register) where
   retail has `nop; blez $t0` (retail's second loop has the slt form too);
   (C) both list checks end `move $v0,$zero; movz $v0,x,$found` where retail has `move $v0,x; movn $v0,$zero,$found`
   (if / ternary / `x = 0` spellings of the inline helper's tail give identical code);
   (D) in the second float block `add.s $f20,$f0,$f20` sits in the bc1f delay slot in ours (sched2 puts it before the
   sub.s, reorg then moves it into the slot), retail keeps it before the sub.s and leaves a `nop` in the slot.
   No effect: counts as locals (79-111), a/b as ternaries (68), index locals (40-49), `*n += 1`, a/b test order
   (84-89), the return spellings (40), statement order of the first 7 statements (greedy, 40), `none = -1` local (40).
   The pointer local for &p (assigned first) gives retail's $s2 = $sp. */
typedef int Q_004593B8 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_004593B8;
extern u8 *D_L01_001E001C;
extern f32 func_L01_0040E518(void *, void *);

static __inline__ u8 *pick_004593B8(u8 *x, u8 **list, s32 n) {
    s32 i;
    s32 found = 0;
    for (i = 0; i < n; i++) {
        if (x == list[i]) {
            found = 1;
        }
    }
    if (found) {
        return 0;
    }
    return x;
}

u8 *func_L01_004593B8(s32 a0, u8 *obj, u8 **list, s32 *n, V_004593B8 *pos) {
    V_004593B8 p;
    V_004593B8 *pp;
    u8 *a;
    u8 *b;
    u8 *v;
    u8 *r;
    s32 i;
    s32 found;
    f32 da;
    f32 db;
    pp = &p;
    b = 0;
    a = 0;
    *(Q_004593B8 *)&p = *(Q_004593B8 *)pos;
    list[*n] = obj;
    (*n)++;
    v = *(u8 **)(obj + 0x68);
    if (*(s32 *)v != -1) {
        a = D_L01_001E001C + (*(s32 *)v << 8);
    }
    if (*(s32 *)(v + 4) != -1) {
        b = D_L01_001E001C + (*(s32 *)(v + 4) << 8);
    }
    if (a != 0 && b == 0) {
        return pick_004593B8(a, list, *n);
    }
    if (b != 0 && a == 0) {
        return pick_004593B8(b, list, *n);
    }
    db = 0.0f;
    db += func_L01_0040E518(b + 0x10, pp);
    if (3.0f < __builtin_fabsf(*(f32 *)(b + 0x18) - pp->z)) {
        db += 100.0f;
    }
    da = 0.0f;
    da += func_L01_0040E518(a + 0x10, pp);
    if (3.0f < __builtin_fabsf(*(f32 *)(a + 0x18) - pp->z)) {
        da += 100.0f;
    }
    r = b;
    if (da < db) {
        r = a;
    }
    return r;
}
