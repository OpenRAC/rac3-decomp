#include "common.h"

INCLUDE_ASM("asm/levels", func_L01_00518480);

/* localdecomp:start func_L01_00518590 */
extern s32 func_L01_00518590(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_003E6DE8(void *);
extern s32 func_003E6378();
extern void *func_003E6C08();
extern s32 func_003E6DE8();

typedef struct { s32 x0; s32 x4; s32 x8; s32 xC; } S_003E37F0;
extern S_003E37F0 D_L01_001E15E0[];
extern s32 D_L01_001DC150;
extern void func_003EE160(void *p, s32, s32);
s32 func_L01_00518590(s32 arg0, s32 arg1, s32 arg2) {
    S_003E37F0 *q;
    S_003E37F0 *p;
    void *t;
    void *v;
    s32 r = 0;
    p = D_L01_001E15E0;
    if (p->x4) q = p;
    else q = func_003E6C08(p);
    t = (void *)func_003E6378(func_003E6DE8(q), arg0);
    v = (t != 0 && (*(s32 (**)(void *, s32))((u8 *)(*(void **)((u8 *)t + 8)) + 0x10))(t, D_L01_001DC150) != 0) ? t : 0;
    if (v != 0) {
        r = 1;
        func_003EE160(v, arg1, arg2);
    }
    return r;
}
/* localdecomp:end func_L01_00518590 */

LINKER_REMNANT("asm/levels", func_L01_00518648);
