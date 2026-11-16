/* func_003C4A40 (PAL frontbin, src/frontbin/3C2FE0.c, @ps2as), PAL code with no US twin, written
   from the assembly 2026-11-16. Near miss: 4 diff in its file's context. Everything but the last
   block is retail's; there the three bytes from func_003C6FB0 load into $v1/$v0 where retail uses
   $v0/$v1 for `a` and `c`. Tried: all six store orders (4 or 6), all six declaration orders (4),
   an s32[3] array (4), u8 temporaries (5, 6), reusing `n`/`q` (6, 18), do { } while (0) around
   the stores (11 to 14). tools/permuter_engine.py reached 1 only with
   `do { n = b; b = n; p->f4 = a; p->f5 = b; p->f6 = c; } while (0);`, which is not source. */
/* localdecomp:start func_003C4A40 */
typedef struct { s16 f0; s16 f2; u8 f4; u8 f5; u8 f6; u8 f7; s16 f8; s16 fA; s16 fC; s16 fE; } S_3C4A40;
void func_003C4A40(s32 id, S_3C4A40 *p) {
    s32 n = p->f0;
    s32 q;
    if (n != 0 && p->f2 == 0) {
        return;
    }
    p->f2 = 0;
    q = (p->fC * 5 + 2) / 6;
    p->f0 = q;
    if (n != 0) {
        p->f0 = (f32)q * ((f32)n / (f32)((p->fE * 5 + 2) / 6));
        if (p->f0 <= 0) {
            p->f0 = 1;
        }
    } else {
        s32 a;
        s32 b;
        s32 c;
        func_003C6FB0(id, &a, &b, &c);
        p->f4 = a;
        p->f5 = b;
        p->f6 = c;
    }
}
/* localdecomp:end func_003C4A40 */
