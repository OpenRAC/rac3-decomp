/* Near miss of func_003E74A8 with its file's own flags: tools/check.py reports 2 diff
   (the version it replaces: 19).
   What differs: The table address at 0x1DA9C8 is now formed with lui/addiu (declaring
   D_001DA9C8 as the 0x20-byte HT object via a per-function alias keeps it out of small data,
   so the $gp-relative `addiu $a0, $gp, -0x1ee8` of the draft is gone), but gcc splits that
   address into a hi/lo pair and the scheduler sinks the low half into the `jal func_003E9DF8`
   delay slot: ours emits `lui $a0,0x1e; move $a1,$v0; jal 0x3e9df8; addiu $a0,$a0,-0x5638`,
   retail emits `lui $a0,0x1e; addiu $a0,$a0,-0x5638; jal 0x3e9df8; move $a1,$v0` (2 word
   diffs, same length). Retail's adjacent lui/addiu is gcc's atomic `la` macro...
*/

/* Candidate for func_003E74A8 (PAL frontbin).
   The hash table at 0x001DA9C8 is a 0x20-byte object (the HT_003E4890 type of
   func_003E9DF8), not the 8 bytes the shared declaration in src/frontbin/3E73A0.c
   guesses, so it is declared here with its real size and a per-function alias
   (D_001DA9C8_003E74A8).  That keeps it out of small data, so gcc forms its
   address with lui/addiu instead of a $gp-relative addiu.
   Still open: gcc splits that address into a hi/lo pair and the scheduler
   sinks the low half into the call's delay slot, while retail keeps the two
   together (see work/RESULTS.md). */

/* localdecomp:start func_003E74A8 */
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern u8 func_003E9DF8_003E74A8[];
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E1F40;
extern S_003E1F40 D_001DA938_003E74A8;
typedef struct { u32 key; void *val; } HE_003E74A8;
typedef struct { s32 f0; s32 n; HE_003E74A8 e[3]; } HT_003E74A8;
extern HT_003E74A8 D_001DA9C8_003E74A8;
s32 func_003E74A8(s32 arg0, f32 fa, f32 fb) {
    s32 *base;
    s32 (*cb)(void *, f32, f32);
    s32 r;
    s32 t;
    void *p;
    S_003E1F40 *q;

    r = 0;
    q = &D_001DA938_003E74A8;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6C08(q);
    }
    p = (void *)func_003E6378(func_003E6DE8(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9668) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_003E9DF8_003E74A8)((void *)&D_001DA9C8_003E74A8, t);
        if (cb != 0) {
            r = cb(p, fa, fb);
        }
    }
    return r;
}
/* localdecomp:end func_003E74A8 */
