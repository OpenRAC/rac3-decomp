/* Near miss of func_003EE038 with its file's own flags: tools/check.py reports 38 diff
   (the version it replaces: 71).
*/

/* US draft of func_003EE038 (rac3-uya-decomp func_003E8AD0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003EE038 */
typedef struct { s32 *arr[16]; s32 x40; s32 x44; } O_3E8AD0;
typedef struct { u8 p0[8]; void *f8; u8 p1[0x2C - 0xC]; O_3E8AD0 *x2C; } T_3E8AD0;
typedef struct { u8 p0[4]; s32 f4; } S_3E8AD0;
typedef struct { s32 (*f0)(); s32 (*f4)(); s32 (*f8)(); s32 (*fC)(); } VT_3E8AD0;
/* Retail reaches D_001D9708 and D_001D9670 with lui, so they must not be small data:
   declare them without a size (the per-function alias for the sized D_001D9708). */
extern u8 D_001D9708_003EE038[];
extern char D_001D9670[];
extern S_3E8AD0 D_001DA938_003EE038[];
extern s32 *func_003E6C08();
extern s32 **func_003E6CC0_003EE038();
extern s32 func_003E7118();
extern void func_003EDED8();
void func_003EE038(T_3E8AD0 *p, s32 flags) {
    O_3E8AD0 *a, *b;
    s32 *q;
    s32 **t;
    s32 **w;
    p->f8 = D_001D9708_003EE038;
    func_003EDED8(p);
    a = p->x2C;
    if (a->x44 != 0) func_003E7118(a->x44);
    a->x44 = 0;
    b = p->x2C;
    if (b->x44 != 0) func_003E7118(b->x44);
    b->x44 = 0;
    if (b->arr != 0) {
        w = b->arr + 16;
        if (b->arr != w) {
            do {
                w--;
                if (*w) func_003E7118(*w);
                *w = 0;
            } while (b->arr != w);
        }
    }
    {
        S_3E8AD0 *d = D_001DA938_003EE038;
        if (d->f4 != 0) {
            q = (s32 *)d;
        } else {
            q = func_003E6C08(d);
        }
    }
    t = func_003E6CC0_003EE038(q, 1);
    if (t != 0) {
        ((VT_3E8AD0 *)*t)->fC(t, p->x2C);
        p->x2C = 0;
    }
    p->f8 = D_001D9670;
    if (flags & 1) func_003F2380(p);
}
/* localdecomp:end func_003EE038 */
