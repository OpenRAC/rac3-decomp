/* Near miss of func_003E7860 with its file's own flags: tools/check.py reports 2 diff
   (the version it replaces: 19).
   What differs: The table address is now built with %hi/%lo (lui+addiu) like PAL retail
   instead of $gp-relative (the US draft's `extern s32 D_001DA9C8[2]` is 8 bytes, so -G8 made
   the compiler use `addiu $a0,$gp,-0x1ee8`); declaring the object with an incomplete type
   fixes that. 2 diffs remain, both at the func_003EA1B0 call: mine emits `move $a1,$v0` before
   the jal and leaves the %lo `addiu $a0,$a0,-0x5638` in the jal's delay slot, retail has the
   `addiu` right after the `lui` and `move $a1,$v0` in the delay slot (the same order as the
   matched siblings func_003E7A38/func_003E82D8, which get it from a `do {...
*/

/* Candidate for func_003E7860 (PAL retail), modelled on the matched sibling
   functions of the same file (func_003E7A38, func_003E82D8):
   - the hash table object is bigger than the -G8 small data limit, so it is
     declared with an incomplete type and addressed with %hi/%lo (lui+addiu),
     not through $gp;
   - the lookup helper is called without a prototype, like in those siblings,
     which is what puts the table address before the call instead of in the
     call's delay slot. */

/* localdecomp:start func_003E7860 */
extern s32 func_003E71A0(void *);
extern s32 func_003E6730();
extern void *func_003E6FC0();
extern void *func_003EA1B0();
extern s32 D_001D9668;
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E1F40;
extern S_003E1F40 D_001DA938_003E7860;
extern u8 D_1DA9C8[];
s32 func_003E7860(s32 arg0, f32 fa, f32 fb) {
    s32 *base;
    s32 (*cb)(void *, f32, f32);
    s32 r;
    s32 t;
    void *p;
    S_003E1F40 *q;

    r = 0;
    q = &D_001DA938_003E7860;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_003E6FC0(q);
    }
    p = (void *)func_003E6730(func_003E71A0(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_001D9668) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)func_003EA1B0(D_1DA9C8, t);
        if (cb != 0) {
            r = cb(p, fa, fb);
        }
    }
    return r;
}
/* localdecomp:end func_003E7860 */
