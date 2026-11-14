#include "common.h"

/* localdecomp:start func_L39_00695FC0 */
__asm__(".extern D_L39_0024D760, 16");
__asm__(".extern D_L39_00247914, 16");
typedef struct S_00695FC0_T { s32 f0; u8 pad[0x30]; u8 f34; } S_00695FC0_T;
typedef struct S_00695FC0_G { u8 pad[0x38]; S_00695FC0_T *f38; } S_00695FC0_G;
typedef struct S_00695FC0_O { u8 pad[0x288]; s32 f288; } S_00695FC0_O;
extern S_00695FC0_G *D_L39_0024D760;
extern S_00695FC0_O *D_L39_00247914;
extern S_00695FC0_O *D_001DC204_sda;
s32 func_L39_00695FC0(void)
{
    S_00695FC0_T *t = D_L39_0024D760->f38;
    if (t->f34 != 0) {
        D_L39_00247914->f288 = 9;
        return 1;
    }
    if (t->f0 >= 0) {
        D_001DC204_sda->f288 = 6;
        return 1;
    }
    return 0;
}
/* localdecomp:end func_L39_00695FC0 */

INCLUDE_ASM("asm/levels", func_L39_00696010);

LINKER_REMNANT("asm/levels", func_L39_006962F8);

INCLUDE_ASM("asm/levels", func_L39_00696308);

LINKER_REMNANT("asm/levels", func_L39_00696AC0);

/* localdecomp:start func_L39_00696AC8 */
extern u8 D_L39_0047CDB0[];
extern void func_L39_00688400(u8 *, s32);

/* from rac4-decomp's func_004EE7B0, renamed, constants adapted */
void func_L39_00696AC8(void *object, s32 flags)
{
    *(void **)((u8 *)object + 96) = D_L39_0047CDB0;
    func_L39_00688400(object, flags);
}
/* localdecomp:end func_L39_00696AC8 */
