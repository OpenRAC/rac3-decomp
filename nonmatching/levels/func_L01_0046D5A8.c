/* PAL port of the NTSC-U draft (round 8): PAL port of the NTSC-U draft (round 8): 3 differences with the file's line (already -mvu0-use-vf0-vf2 and @ps2as; callees func_L01_00445EA8, func_0038D098 / D0B0 / D328 / D028 / D000 / DAB8, the file's func_L01_0046D440 with (tgt, pos, 8, 0, color, vel, 0, 0), life < 8, steps 0.019198622f / 0.0872664675f). Left: in the first func_L01_0046D440 call (h1C == 1, no vel) retail puts `mov.s $f13,$f12` before `move $a3,$zero` and fills the jal delay slot with `move $t1,$zero`; gcc fills it with the mov.s and schedules the two moves after the a2 load. Assigning the result, a (f32 *)0 argument, int/float zero spellings and a float zero local used for both f12 and f13 give the same 3 */
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0046D5A8 */
typedef struct {
    f32 f0, f4, f8;
    u8 *tgt;
    f32 f10, f14;
    s16 h18, h1A, h1C;
} St_46D5A8;
extern s32 func_L01_00445EA8(u8 *, s32);
extern void func_0038D328(void *, void *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038D000(void *, void *, void *);
extern f32 func_0038DAB8(f32, f32);

void func_L01_0046D5A8(u8 *obj)
{
    St_46D5A8 *st;
    S_469D90 *r;
    vu0_v4 A;
    vu0_v4 B;
    vu0_v4 C;
    f32 M[16] __attribute__((aligned(16)));

    st = (St_46D5A8 *)(obj + 0x20);
    if (st->h1C == 0) {
        if (func_L01_00445EA8(obj + 4, st->h1A) != 0) {
            func_003CD250((Obj *)obj);
            return;
        }
        if (st->tgt == 0) {
            return;
        }
        A.x = st->f0;
        A.y = st->f4;
        A.z = st->f8;
        func_0038CE20(&A, &A, (f32)st->h18);
        vec_add_ba(obj + 0x10, st->tgt + 0x10, &A);
        return;
    }
    if (func_0038CB00((s16 *)(obj + 0xA)) != 0 || (*(s16 *)(obj + 0xA) < 8 && func_L01_00445EA8(obj + 4, 0x10) != 0)) {
        func_003CD250((Obj *)obj);
        return;
    }
    if (st->h1C == 1) {
        func_L01_0046D440(0, obj + 0x10, 8, 0, *(s8 *)(obj + 7), 0, 0.0f, 0.0f);
    } else {
        A.x = st->f0;
        A.y = st->f4;
        A.z = st->f8;
        r = func_L01_0046D440((s32)st->tgt, obj + 0x10, 8, 0, *(s8 *)(obj + 7), &A.x, 0.0f, 0.0f);
        if (r != 0) {
            *(u16 *)((u8 *)r + 0x38) = st->h18;
        }
    }
    if (st->h1C == 1) {
        *(u128_t *)(obj + 0x10) = *(u128_t *)(st->tgt + 0x10);
        A.x = func_0038D098(st->f10) * 2.25f;
        A.y = func_0038D0B0(st->f10) * 2.25f;
        A.z = A.x;
        A.x = 0.0f;
        B.x = func_0038D098(st->f14) * 0.28f;
        B.y = func_0038D0B0(st->f14) * 0.28f;
        B.z = B.x;
        B.x = 0.0f;
        qzero(&C);
        C.y = st->f10;
        func_0038D328(M, &C);
        func_0038D028(&B, &B, M);
        vec_add_ba(&A, &A, &B);
        func_0038D000(&A, &A, st->tgt + 0xC0);
        vec_add_ba(obj + 0x10, obj + 0x10, &A);
        st->f10 = func_0038DAB8(st->f10, 0.019198622f);
        st->f14 = func_0038DAB8(st->f14, 0.0872664675f);
    }
}
/* localdecomp:end func_L01_0046D5A8 */
