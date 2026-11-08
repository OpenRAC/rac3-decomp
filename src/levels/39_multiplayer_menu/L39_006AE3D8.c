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

INCLUDE_ASM("asm/levels", func_L39_006AE3D8);

INCLUDE_ASM("asm/levels", func_L39_006AE8F8);

INCLUDE_ASM("asm/levels", func_L39_006AED18);

/* localdecomp:start func_L39_006AEF20 */
void func_L39_006AEF20(u8 *a0) {
    OBJ_006AEF20 *obj = *(OBJ_006AEF20 **)(a0 + 0x11C);
    obj->vt->f20(obj, 3, 0);
    obj = *(OBJ_006AEF20 **)(a0 + 0x11C);
    obj->vt->f4C(obj, 0x40, 1);
}
/* localdecomp:end func_L39_006AEF20 */

INCLUDE_ASM("asm/levels", func_L39_006AEF70);

INCLUDE_ASM("asm/levels", func_L39_006AF070);

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

INCLUDE_ASM("asm/levels", func_L39_006AF318);

INCLUDE_ASM("asm/levels", func_L39_006AF570);

INCLUDE_ASM("asm/levels", func_L39_006AF5D8);
