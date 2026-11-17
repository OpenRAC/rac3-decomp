/* PAL near miss (b8-s4): 2 differences: the same C as the matched twin func_L01_00516470 (PAL names for the callees); retail puts the lui/addiu of D_L01_001E1670 before the jal and the move of the result into its delay slot, this C moves the result first and fills the slot with the addiu. About 8 compiles (declaration forms of the table and of func_L01_00519700, nested call) did not change it.
 */
#include "common.h"
/* localdecomp:start func_L01_00516640 */
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_003E1E50; /* from the top of L01_00516438.c */
extern s32 func_L01_00515E00(void *);
extern s32 func_L01_00515340();
extern void *func_L01_00515BD0();
extern void *func_L01_00519700();
extern s32 D_L01_001DC0B8;
extern S_003E1E50 D_L01_001E15E0;
extern u8 D_L01_001E1670[];

s32 func_L01_00516640(s32 arg0, f32 fa, f32 fb) {
    s32 *base;
    s32 (*cb)(void *, f32, f32);
    s32 r;
    s32 t;
    void *p;
    S_003E1E50 *q;

    r = 0;
    q = &D_L01_001E15E0;
    if (q->f4 != 0) {
        base = (s32 *)q;
    } else {
        base = (s32 *)func_L01_00515BD0(q);
    }
    p = (void *)func_L01_00515340(func_L01_00515E00(base), arg0);
    if ((p == 0) || ((*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)p + 8)) + 0x10))(p, D_L01_001DC0B8) == 0)) {
        p = 0;
    }
    if (p != 0) {
        t = (*(s32 (**)(void *))((u8 *)(*(void **)((u8 *)p + 8)) + 0xC))(p);
        cb = (void *)((void *(*)(void *, s32))func_L01_00519700)(D_L01_001E1670, t);
        if (cb != 0) {
            r = cb(p, fa, fb);
        }
    }
    return r;
}
/* localdecomp:end func_L01_00516640 */
