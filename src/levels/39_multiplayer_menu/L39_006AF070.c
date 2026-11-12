#include "common.h"

typedef struct {
    u8 pad0[0x20];
    void (*f20)(void *, s32, s32);
    u8 pad24[0x4C - 0x24];
    void (*f4C)(void *, s32, s32);
} VT_006AEF20;
typedef struct {
    u8 pad0[0x60];
    VT_006AEF20 *vt;
} OBJ_006AEF20;

/* localdecomp:start func_L39_006AF070 */
extern u8 D_1A5CD0[];
extern s32 *D_00241120;
__asm__(".extern D_00241120, 16");
extern s32 D_002404C0;
__asm__(".extern D_002404C0, 16");
typedef struct S_006AF070 {
    u8 pad0[0xF0];
    s16 fF0;
    u8 pad1[0x174 - 0xF2];
    s32 f174;
    s32 f178;
    s16 f17C;
} S_006AF070;
extern S_006AF070 *D_00241640;
__asm__(".extern D_00241640, 16");
typedef struct Vt_006AF070 {
    u8 pad0[0xF0];
    void (*fF0)(void *);
} Vt_006AF070;
typedef struct Obj_006AF070 {
    u8 pad0[0x60];
    Vt_006AF070 *f60;
} Obj_006AF070;
extern s32 func_L39_006CC238(s32, s32);
extern void func_L39_006CC2A8(s32, void *, s32);
extern void func_199A20(void);
extern void func_L39_00689A70(void);
extern void func_L39_0059A578(s32, s32);
extern int func_19D510(void);

void func_L39_006AF070(Obj_006AF070 *self)
{
    u8 *g = D_1A5CD0;
    s32 r;
    s32 v;

    r = func_L39_006CC238(3, *(s32 *)(g + 0x5F4));
    if (r < 8) {
        func_L39_006CC2A8(3, g + 0x5F4, r + 8);
    }
    D_00241640->fF0 = 7;
    D_00241640->f174 = *(s32 *)(g + 0x128) + 600;
    func_199A20();
    self->f60->fF0(self);
    func_L39_00689A70();
    *(s32 *)(g + 0x130) = *D_00241120;
    D_00241640->f178 = *D_00241120;
    v = D_00241640->f17C;
    if (*D_00241120 >= 2 && v <= 45) {
        v += 10;
    }
    func_L39_0059A578(v, 0);
    D_002404C0 = func_19D510();
}
/* localdecomp:end func_L39_006AF070 */

LINKER_REMNANT("asm/levels", func_L39_006AF160);

INCLUDE_ASM("asm/levels", func_L39_006AF168);

LINKER_REMNANT("asm/levels", func_L39_006AF2E8);

/* localdecomp:start func_L39_006AF2F0 */
extern u8 D_L39_0047DEA0[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_006AF2F0(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047DEA0;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_006AF2F0 */
