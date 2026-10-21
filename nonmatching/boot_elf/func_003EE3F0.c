/* Near miss of func_003EE3F0 with its file's own flags: tools/check.py reports 39 diff
   (the version it replaces: 71).
*/

/* US draft of func_003EE3F0 (rac3-uya-decomp func_003EE290, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003EE3F0 */
typedef struct { s32 *arr[16]; s32 x40; s32 x44; } O_3E8AD0;
typedef struct { u8 p0[8]; void *f8; u8 p1[0x2C - 0xC]; O_3E8AD0 *x2C; } T_3E8AD0;
typedef struct { u8 p0[4]; s32 f4; } S_3E8AD0;
typedef struct { s32 (*f0)(); s32 (*f4)(); s32 (*f8)(); s32 (*fC)(); } VT_3E8AD0;
/* retail reaches both of these through lui/addiu, so they must not be small data:
   an unsized array never is. */
extern u8 D_001D9708_003EE3F0[];
extern char D_001D9670[];
extern S_3E8AD0 D_001DA938_003EE3F0[];
extern s32 *func_003E6FC0();
extern s32 **func_003E7078_003EE3F0();
extern s32 func_003E74D0();
extern void func_003EE290();
void func_003EE3F0(T_3E8AD0 *p, s32 flags) {
    O_3E8AD0 *a, *b;
    S_3E8AD0 *d;
    s32 *q;
    s32 **t;
    s32 **w;
    p->f8 = D_001D9708_003EE3F0;
    func_003EE290(p);
    a = p->x2C;
    if (a->x44 != 0) func_003E74D0(a->x44);
    a->x44 = 0;
    b = p->x2C;
    if (b->x44 != 0) func_003E74D0(b->x44);
    b->x44 = 0;
    if (b != 0) {
        w = b->arr + 16;
        while (w != b->arr) {
            w--;
            if (*w) func_003E74D0(*w);
            *w = 0;
        }
    }
    d = D_001DA938_003EE3F0;
    if (d->f4 != 0) {
        q = (s32 *)d;
    } else {
        q = func_003E6FC0(d);
    }
    t = func_003E7078_003EE3F0(q, 1);
    if (t != 0) {
        ((VT_3E8AD0 *)*t)->fC(t, p->x2C);
        p->x2C = 0;
    }
    p->f8 = D_001D9670;
    if (flags & 1) func_003F2738(p);
}
/* localdecomp:end func_003EE3F0 */
