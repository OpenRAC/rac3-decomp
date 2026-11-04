#include "common.h"

typedef struct R_003E3770 {
    f32 f0;
    f32 f4;
    f32 f8;
} R_003E3770;
typedef struct S_003E3770 {
    u8 pad0[0x18];
    f32 f18;
    u8 pad1[4];
    u8 b20;
    u8 pad2[0x47];
    R_003E3770 *p68;
} S_003E3770;

/* localdecomp:start func_L07_003E3770 */
extern f32 func_00382538(void);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D0B0(f32);

void func_L07_003E3770(S_003E3770 *a) {
    R_003E3770 *p;
    f32 v;

    p = a->p68;
    if (a->b20 == 0) {
        ((s32 *)p)[1] = 0;
        p->f0 = func_00382538();
        p->f8 = func_003824E0(0.04188790545f, 0.0837758109f);
        a->b20 = 1;
    }
    a->f18 = a->f18 - p->f4;
    v = func_0038DAB8(p->f0, p->f8);
    p->f0 = v;
    p->f4 = func_0038D0B0(v) * 0.2f;
    a->f18 = a->f18 + p->f4;
}
/* localdecomp:end func_L07_003E3770 */

INCLUDE_ASM("asm/levels", func_L07_003E3820);

INCLUDE_ASM("asm/levels", func_L07_003E3AB0);

INCLUDE_ASM("asm/levels", func_L07_003E3B30);
